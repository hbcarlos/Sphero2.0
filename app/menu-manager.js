
const {Menu} = require('electron');
const MessagingService = require('./libs/messagingservice-bundle');
const Utils = require('./libs/utils-bundle');

let allowNavigation = true;
let modalOpen = false;
let drawerOpen = false;

const isMacOs = Utils.getPlatformInfo().platform === Utils.PlatformDefines.PLATFORM.MAC_OS;

exports.createMenu = (backgroundWindow, mainWindow) => {
    const template = [
    getAppMenu(),
    {
        role: 'editMenu',
        submenu: [
            {role: 'undo'},
            {role: 'redo'},
            {type: 'separator'},
            {role: 'cut'},
            {role: 'copy'},
            {role: 'paste'},
            {role: 'selectall'},
            {type: 'separator'}
        ]
    },
    {
        label: Utils.getLocalizedString('viewMenuTitle'),
        submenu: [
            {
                id: 'nav-reload',
                label: Utils.getLocalizedString('navReload'),
                accelerator: isMacOs ? 'Cmd+R' : 'Ctrl+F5',
                click() {
                    MessagingService.send(MessagingService.Topic.APP, MessagingService.Action.App.SITE_RELOAD);
                }
            },
            {
                id: 'nav-go-back',
                label: Utils.getLocalizedString('navGoBack'),
                accelerator: isMacOs ? 'Cmd+Left' : 'Alt+Left',
                click() {
                    MessagingService.send(MessagingService.Topic.APP, MessagingService.Action.App.SITE_GO_BACK);
                }
            }
        ]
    },
    {
        role: 'windowMenu',
        submenu: [
            {role: 'minimize'},
            {type: 'separator'},
            {role: 'front'}
        ]
    }];

    if (Utils.shouldShowDevTools()) {
        template.push(getDebugMenu(backgroundWindow, mainWindow));
    }

    Menu.setApplicationMenu(Menu.buildFromTemplate(template));

    MessagingService.on(MessagingService.Topic.WINDOW, MessagingService.Action.Window.MODAL_WILL_OPEN, () => {
        modalOpen = true;
        toggleMenuItems();
    });
    MessagingService.on(MessagingService.Topic.WINDOW, MessagingService.Action.Window.MODAL_CLOSED, () => {
        modalOpen = false;
        toggleMenuItems(true);
    });
    MessagingService.on(MessagingService.Topic.WINDOW, MessagingService.Action.Window.DRAWER_OPENED, () => {
        drawerOpen = true;
        toggleMenuItems();
    });
    MessagingService.on(MessagingService.Topic.WINDOW, MessagingService.Action.Window.DRAWER_CLOSED, () => {
        drawerOpen = false;
        toggleMenuItems(true);
    });
    MessagingService.on(MessagingService.Topic.APP, MessagingService.Action.App.NAVIGATION_STATE, message => {
        allowNavigation = message.payload;
        toggleMenuItems();
    });
};

const toggleMenuItems = () => {
    const menu = Menu.getApplicationMenu();
    menu.getMenuItemById('show-prefs').enabled = !modalOpen && !drawerOpen;
    menu.getMenuItemById('nav-reload').enabled = !modalOpen && allowNavigation && !drawerOpen;;
    menu.getMenuItemById('nav-go-back').enabled = !modalOpen && allowNavigation && !drawerOpen;;
};

const getAppMenu = () => {
    if (isMacOs) {
        return {
            submenu: [ // App menu
                {role: 'about'},
                {type: 'separator'},
                {
                    id: 'show-prefs',
                    label: `${Utils.getLocalizedString('prefsTitle')}...`,
                    accelerator: 'CmdOrCtrl+,',
                    click() {
                        MessagingService.send(MessagingService.Topic.APP, MessagingService.Action.App.SHOW_PREFERENCES);
                    }
                },
                {type: 'separator'},
                {role: 'hide'},
                {role: 'hideothers'},
                {role: 'unhide'},
                {type: 'separator'},
                {role: 'quit'}
            ]
        }
    }
    return {
        label: Utils.getLocalizedString('fileMenuTitle'),
        submenu: [ // App menu
            {
                id: 'show-prefs',
                label: Utils.getLocalizedString('settingsTitle'),
                accelerator: 'CmdOrCtrl+,',
                click() {
                    MessagingService.send(MessagingService.Topic.APP, MessagingService.Action.App.SHOW_PREFERENCES);
                }
            },
            {type: 'separator'},
            {role: 'quit'}
        ]
    }
}

const getDebugMenu = (backgroundWindow, mainWindow) => {
    return {
        label: 'Debug',
        submenu: [
            {accelerator: 'CmdOrCtrl+Alt+A', role: 'toggledevtools'}, {
                label: 'Toggle Background Dev Tools',
                accelerator: 'CmdOrCtrl+Alt+B',
                click() {
                    if (backgroundWindow.isVisible()) {
                        backgroundWindow.hide();
                    } else {
                        backgroundWindow.show();
                        backgroundWindow.openDevTools();
                    }
                }
            }, {
                type: 'separator'
            }, {
                label: 'Show Site Dev Tools',
                accelerator: 'CmdOrCtrl+Alt+S',
                click() {
                    mainWindow.webContents.executeJavaScript('document.getElementById("site-webview").openDevTools()');
                }
            }]
    };
};
