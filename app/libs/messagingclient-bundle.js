! function(e, t) {
    "object" == typeof exports && "object" == typeof module ? module.exports = t() : "function" == typeof define && define.amd ? define([], t) : "object" == typeof exports ? exports.MessagingClient = t() : e.MessagingClient = t()
}(global, function() {
    return function(e) {
        var t = {};

        function o(r) {
            if (t[r]) return t[r].exports;
            var n = t[r] = {
                i: r,
                l: !1,
                exports: {}
            };
            return e[r].call(n.exports, n, n.exports, o), n.l = !0, n.exports
        }
        return o.m = e, o.c = t, o.d = function(e, t, r) {
            o.o(e, t) || Object.defineProperty(e, t, {
                configurable: !1,
                enumerable: !0,
                get: r
            })
        }, o.r = function(e) {
            Object.defineProperty(e, "__esModule", {
                value: !0
            })
        }, o.n = function(e) {
            var t = e && e.__esModule ? function() {
                return e.default
            } : function() {
                return e
            };
            return o.d(t, "a", t), t
        }, o.o = function(e, t) {
            return Object.prototype.hasOwnProperty.call(e, t)
        }, o.p = "", o(o.s = 1)
    }([function(e, t) {
        e.exports = require("electron")
    }, function(e, t, o) {
        "use strict";
        o.r(t);
        const r = {
                APP: "APP",
                CANVAS: "CANVAS",
                ROBOT: "ROBOT",
                SAVE_LOAD: "SAVE_LOAD",
                DIALOG: "DIALOG",
                WINDOW: "WINDOW",
                ANALYTICS: "ANALYTICS",
                SOUND: "SOUND",
                SERVICE: "SERVICE",
                WILDCARD: "*"
            },
            n = {
                App: {
                    SHOW_PREFERENCES: "show preferences",
                    TOAST: "toast",
                    LOGIN: "login",
                    LOGOUT: "logout",
                    USER_AGENT_OVERRIDE_FAILED: "user agent override failed",
                    OPEN_URL: "open url",
                    SITE_RELOAD: "site reload",
                    SITE_GO_BACK: "set go back",
                    NAVIGATION_STATE: "navigation state"
                },
                Canvas: {
                    DATABASE_RESULT: "database result",
                    DATABASE_REQUEST: "database request"
                },
                Robot: {
                    STATE: {
                        DISCONNECTED: "disconnected",
                        CONNECT: "connect",
                        CONNECTING: "connecting",
                        CONNECT_FAILED: "connection failed",
                        CONNECTED: "connected",
                        ROBOT_DATA: "robot data",
                        DISCONNECT: "disconnect robot",
                        ROBOT_NAME_UPDATED: "robot name updated",
                        DEEP_SLEEP: "deep sleep"
                    },
                    DISCOVERY: {
                        TOGGLE_CONNECTION: "toggle connection",
                        PAIRED_CLASSIC_ROBOTS_LIST: "paired classic robots list",
                        GET_PAIRED_CLASSIC_ROBOTS: "get paired classic robots",
                        START: "begin discovery",
                        STOP: "stop discovery",
                        DISCOVERED: "robot discovered"
                    },
                    FIRMWARE_UPDATE: {
                        STARTED: "firmware update started",
                        PROGRESS: "firmware update progress",
                        SUCCEEDED: "firmware update succeeded",
                        FAILED: "firmware update failed",
                        FORCE_UPDATE: "force update firmware"
                    },
                    PROGRAM: {
                        SEND_FAILED: "send program failed",
                        SEND_SUCCEEDED: "send program succeeded",
                        STARTING: "program starting",
                        STARTED: "program executing",
                        ERROR: "program error",
                        STOPPED: "program stopped",
                        RUN: "run program",
                        STOP: "stop program"
                    },
                    COMMAND: {
                        DRIVE: "drive",
                        AIM: "aim",
                        SET_COLOR: "set color",
                        TURN_ON_LIGHTS: "turn on lights",
                        TURN_OFF_LIGHTS: "turn off lights",
                        SET_FRONT_LED: "set front led",
                        SET_BACK_LED: "set back led",
                        SET_BACK_LED_BRIGHTNESS: "set back led brightness",
                        PLAY_ANIMATION: "play animation",
                        CANCEL_ANIMATION: "cancel animation",
                        STOP_ANIMATION: "stop animation",
                        PLAY_SOUND: "play sound",
                        STOP_SOUND: "stop sound",
                        SET_HOLOPROJECTOR: "set holoprojector",
                        SET_LOGIC_DISPLAY: "set logic display",
                        SET_HEAD_LED: "set head led",
                        SET_USER_COLOR: "set user color",
                        SET_SENSORS_ENABLED: "set sensors enabled",
                        SET_SPEED: "set speed",
                        SET_JOYSTICK_ENABLED: "set joystick enabled",
                        SET_PREVIOUS_ROBOT_TYPE: "set previous robot type",
                        SET_MOVEMENT: "set movement",
                        SET_USER_VOLUME: "set user volume",
                        START_CALIBRATION: "start calibration",
                        UPDATE_CALIBRATION: "update calibration",
                        END_CALIBRATION: "end calibration",
                        APPLY_USER_SETTINGS: "apply user settings"
                    },
                    MATRIX: {
                        SAVING_STARTED: "matrix animation saving started",
                        FRAME_SAVED: "matrix animation frame saved",
                        SAVING_COMPLETE: "matrix animation saving complete"
                    }
                },
                Window: {
                    RESIZE: "resize",
                    MODAL_CLOSED: "modal closed",
                    DRAWER_CLOSED: "drawer closed",
                    DRAWER_OPENED: "drawer opened",
                    DRIVE_CLOSED: "drive closed",
                    MODAL_WILL_OPEN: "will open modal",
                    MODAL_OPENED: "modal opened",
                    MODAL_WILL_CLOSE: "will close modal"
                },
                Sound: {
                    SPEAK: "speak",
                    PLAY_EFFECT: "play effect",
                    STOP: "stop",
                    PLAY_ROBOT: "play robot",
                    STOP_ROBOT: "stop robot",
                    COMPLETED: "completed",
                    CANCELLED: "cancelled",
                    ERROR: "error"
                },
                Service: {
                    MESSAGE_DELIVERY_FAILED: "message delivery failed"
                },
                WILDCARD: "*",
                DEBUG: "debug"
            };
        var a = o(0);
        let E;
        const s = e => {
                d({
                    payload: e,
                    action: "register"
                })
            },
            i = (e, t) => {
                E(t)
            },
            c = e => {
                a.ipcRenderer.send("message", e)
            },
            d = e => {
                e.topic = r.SERVICE, e.target = "service", c(e)
            };
        o.d(t, "destroy", function() {
            return D
        }), o.d(t, "connectToService", function() {
            return T
        }), o.d(t, "on", function() {
            return _
        }), o.d(t, "once", function() {
            return l
        }), o.d(t, "off", function() {
            return R
        }), o.d(t, "send", function() {
            return p
        }), o.d(t, "sendMessageToService", function() {
            return L
        }), o.d(t, "Topic", function() {
            return r
        }), o.d(t, "Action", function() {
            return n
        });
        let A, O = !1,
            S = {};
        const D = () => {
                S = void 0, E = void 0, a.ipcRenderer.removeListener("message", i)
            },
            T = (e, t, o) => {
                "service" !== e.toLowerCase() ? O || (((e, t, o, r) => {
                    E = r, s({
                        name: e,
                        isWebView: t,
                        disabled: o
                    }), a.ipcRenderer.on("message", i)
                })(e, t, o, u), A = e, O = !0) : console.error("Messaging client name can't be 'service'. Try a different client name")
            },
            _ = (e, t, o) => {
                o && (e === r.WILDCARD && (t = n.WILDCARD), S[e] || (S[e] = {}), S[e][t] || (S[e][t] = []), S[e][t].push(o))
            },
            l = (e, t, o) => {
                if (!o) return;
                const r = (...n) => {
                    o(...n), R(e, t, r)
                };
                _(e, t, r)
            },
            R = (e, t, o) => {
                e === r.WILDCARD && (t = n.WILDCARD);
                const a = S[e][t] || [];
                if (o) {
                    const e = a.indexOf(o); - 1 !== e && a.splice(e, 1)
                } else
                    for (; a.length > 0;) a.pop()
            },
            p = (e, t, o, r) => {
                c({
                    topic: e,
                    action: t,
                    payload: o,
                    target: r,
                    sender: A
                })
            },
            u = e => {
                const {
                    topic: t,
                    action: o,
                    payload: a,
                    target: E,
                    sender: s
                } = e;
                let i = [];
                S[t] && (S[t][o] && (i = i.concat(S[t][o])), S[t][n.WILDCARD] && (i = i.concat(S[t][n.WILDCARD]))), S[r.WILDCARD] && S[r.WILDCARD][n.WILDCARD] && (i = i.concat(S[r.WILDCARD][n.WILDCARD])), I(i, t, o, a, E, s)
            },
            I = (e, t, o, r, n, a) => {
                const E = {
                    topic: t,
                    action: o,
                    payload: r,
                    target: n,
                    sender: a
                };
                e.forEach(e => {
                    e(E)
                })
            },
            L = (e, t) => d({
                action: e,
                payload: t
            })
    }])
});