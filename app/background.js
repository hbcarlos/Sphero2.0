const ipcRenderer = require('electron').ipcRenderer;
const Utils = require('./libs/utils-bundle');

//TEMP: Get Windows working!
if (Utils.getPlatformInfo().platform === Utils.PlatformDefines.PLATFORM.MAC_OS) {
    const SegfaultHandler = require('segfault-handler');
    SegfaultHandler.registerHandler('crash-background.log');
}

ipcRenderer.on('start', () => {
    const messagingClient = require('./libs/messagingclient-bundle');
    window.MessagingClient = messagingClient;
    if (!messagingClient.isConnected) {
        messagingClient.connectToService('background', false, false);
    }

    //needs to be loaded after setting up Messaging service and Messaging client in the global space
    let robotService = require('./libs/robotservice-bundle');
    robotService = new robotService.default();
    window.RobotService = robotService;

    ipcRenderer.send('background-started', robotService.getRobotData());
});

ipcRenderer.on('destroy', () => {
    window.RobotService.destroy(() => {
        window.RobotService = null;
        ipcRenderer.send('background-destroyed');
    });
});