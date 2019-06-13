const electron = require('electron');
const path = require('path');
const url = require('url');

const {createMenu} = require('./menu-manager');
const MessagingService = require('./libs/messagingservice-bundle');
const Utils = require('./libs/utils-bundle');

const isMacOs = Utils.getPlatformInfo().platform === Utils.PlatformDefines.PLATFORM.MAC_OS;

//TEMP: Get Windows working!
if (isMacOs) {
    const SegfaultHandler = require('segfault-handler');
    SegfaultHandler.registerHandler('crash-main.log');
}

// Keep a global reference of the window object, if you don't, the window will
// be closed automatically when the JavaScript object is garbage collected.
let mainWindow;
let backgroundWindow;

let allowAppToQuit = false;

const devTools = Utils.shouldShowDevTools();

const DISABLE_EVAL = 'window.eval = global.eval = () => {throw new Error("eval is disabled!");};';

const createWindow = () => {
    // Create a new service if one does not exist
    MessagingService.start();

    // Create the browser window.
    mainWindow = new electron.BrowserWindow({
        minWidth: Utils.screenDimensions.min.width,
        minHeight: Utils.screenDimensions.min.height,
        width: Utils.screenDimensions.default.width,
        height: Utils.screenDimensions.default.height,
        frame: true,
        webPreferences: {
            devTools
        }
    });

    mainWindow.webContents.executeJavaScript(DISABLE_EVAL);

    // Disable the title bar
    mainWindow.webContents.executeJavaScript('document.body.classList.add("no-title-bar")');

    // Emitted when the window is closed.
    mainWindow.on('closed', () => {
        // Dereference the window object, usually you would store windows
        // in an array if your app supports multi windows, this is the time
        // when you should delete the corresponding element.
        mainWindow = null;

        destroy();
    });

    // Create the background window.
    backgroundWindow = new electron.BrowserWindow({
        show: false,
        allowServiceWorkers: true,
        webPreferences: {
            devTools
        }
    });

    backgroundWindow.webContents.executeJavaScript(DISABLE_EVAL);

    backgroundWindow.loadURL(url.format({
        pathname: path.join(__dirname, 'background.html'),
        protocol: 'file:',
        slashes: true
    }));

    backgroundWindow.webContents.on('did-finish-load', () => {
        backgroundWindow.webContents.send('start');
    });

    electron.ipcMain.on('background-started', (event, robotData) => {
        global.robotData = robotData;

        // and load the index.html of the app.
        mainWindow.loadURL(url.format({
            pathname: path.join(__dirname, 'app.html'),
            protocol: 'file:',
            slashes: true
        }));
    });

    createMenu(backgroundWindow, mainWindow);
};

const destroy = () => {
    if (backgroundWindow) {
        electron.ipcMain.on('background-destroyed', () => {
            allowAppToQuit = true;
            electron.app.quit();
            backgroundWindow.destroy();
            backgroundWindow = null;
        });
        backgroundWindow.webContents.send('destroy');
    }
    MessagingService.destroy();
};

/**
 * Starts the application.
 */
const start = () => {
    // Enforce a single instance.
    const shouldQuit = electron.app.makeSingleInstance(() => {
        if (mainWindow) {
            if (mainWindow.isMinimized()) mainWindow.restore();
            mainWindow.focus();
        }
    });
    // Disabled on MAS: https://github.com/electron/electron/issues/9985
    if (shouldQuit && !process.mas) {
        electron.app.quit();
        return;
    }

    // This method will be called when Electron has finished
    // initialization and is ready to create browser windows.
    // Some APIs can only be used after this event occurs.
    electron.app.on('ready', createWindow);

    electron.app.on('before-quit', event => {
        if (!allowAppToQuit) {
            event.preventDefault();
            if (mainWindow) {
                mainWindow.destroy();
            }
            return;
        }
    });

    electron.app.on('activate', () => {
        // On OS X it's common to re-create a window in the app when the
        // dock icon is clicked and there are no other windows open.
        if (mainWindow === null) {
            createWindow();
        }
    });
};
start();
