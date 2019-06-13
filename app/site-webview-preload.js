const send = require('electron').ipcRenderer.send;

window.sendMessageToApp = (messageTopic, messageAction, messagePayload) => {
    send('message', {
        topic: messageTopic,
        action: messageAction,
        payload: messagePayload
    });
};
