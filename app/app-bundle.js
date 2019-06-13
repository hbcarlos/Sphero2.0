! function(e) {
    function t(t) {
        for (var o, s, r = t[0], c = t[1], d = t[2], u = 0, p = []; u < r.length; u++) s = r[u], a[s] && p.push(a[s][0]), a[s] = 0;
        for (o in c) Object.prototype.hasOwnProperty.call(c, o) && (e[o] = c[o]);
        for (l && l(t); p.length;) p.shift()();
        return i.push.apply(i, d || []), n()
    }

    function n() {
        for (var e, t = 0; t < i.length; t++) {
            for (var n = i[t], o = !0, r = 1; r < n.length; r++) {
                var c = n[r];
                0 !== a[c] && (o = !1)
            }
            o && (i.splice(t--, 1), e = s(s.s = n[0]))
        }
        return e
    }
    var o = {},
        a = {
            1: 0
        },
        i = [];

    function s(t) {
        if (o[t]) return o[t].exports;
        var n = o[t] = {
            i: t,
            l: !1,
            exports: {}
        };
        return e[t].call(n.exports, n, n.exports, s), n.l = !0, n.exports
    }
    s.m = e, s.c = o, s.d = function(e, t, n) {
        s.o(e, t) || Object.defineProperty(e, t, {
            configurable: !1,
            enumerable: !0,
            get: n
        })
    }, s.r = function(e) {
        Object.defineProperty(e, "__esModule", {
            value: !0
        })
    }, s.n = function(e) {
        var t = e && e.__esModule ? function() {
            return e.default
        } : function() {
            return e
        };
        return s.d(t, "a", t), t
    }, s.o = function(e, t) {
        return Object.prototype.hasOwnProperty.call(e, t)
    }, s.p = "";
    var r = window.webpackJsonp = window.webpackJsonp || [],
        c = r.push.bind(r);
    r.push = t, r = r.slice();
    for (var d = 0; d < r.length; d++) t(r[d]);
    var l = c;
    i.push([217, 0]), n()
}([function(e, t, n) {
    "use strict";
    const o = {
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
        a = {
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
    var i = n(13);
    let s;
    const r = e => {
            l({
                payload: e,
                action: "register"
            })
        },
        c = (e, t) => {
            s(t)
        },
        d = e => {
            i.ipcRenderer.send("message", e)
        },
        l = e => {
            e.topic = o.SERVICE, e.target = "service", d(e)
        };
    n.d(t, "c", function() {
        return m
    }), n.d(t, "e", function() {
        return f
    }), n.d(t, "d", function() {
        return v
    }), n.d(t, "f", function() {
        return O
    }), n.d(t, "b", function() {
        return o
    }), n.d(t, "a", function() {
        return a
    });
    let u, p = !1,
        b = {};
    const m = (e, t, n) => {
            "service" !== e.toLowerCase() ? p || (((e, t, n, o) => {
                s = o, r({
                    name: e,
                    isWebView: t,
                    disabled: n
                }), i.ipcRenderer.on("message", c)
            })(e, t, n, h), u = e, p = !0) : console.error("Messaging client name can't be 'service'. Try a different client name")
        },
        f = (e, t, n) => {
            n && (e === o.WILDCARD && (t = a.WILDCARD), b[e] || (b[e] = {}), b[e][t] || (b[e][t] = []), b[e][t].push(n))
        },
        v = (e, t, n) => {
            e === o.WILDCARD && (t = a.WILDCARD);
            const i = b[e][t] || [];
            if (n) {
                const e = i.indexOf(n); - 1 !== e && i.splice(e, 1)
            } else
                for (; i.length > 0;) i.pop()
        },
        O = (e, t, n, o) => {
            d({
                topic: e,
                action: t,
                payload: n,
                target: o,
                sender: u
            })
        },
        h = e => {
            const {
                topic: t,
                action: n,
                payload: i,
                target: s,
                sender: r
            } = e;
            let c = [];
            b[t] && (b[t][n] && (c = c.concat(b[t][n])), b[t][a.WILDCARD] && (c = c.concat(b[t][a.WILDCARD]))), b[o.WILDCARD] && b[o.WILDCARD][a.WILDCARD] && (c = c.concat(b[o.WILDCARD][a.WILDCARD])), g(c, t, n, i, s, r)
        },
        g = (e, t, n, o, a, i) => {
            const s = {
                topic: t,
                action: n,
                payload: o,
                target: a,
                sender: i
            };
            e.forEach(e => {
                e(s)
            })
        }
}, function(e, t, n) {
    "use strict";
    const o = n(33),
        a = n(208),
        i = ["ar", "arc", "dv", "fa", "ha", "he", "khw", "ks", "ku", "ps", "ur", "yi"];
    let s, r = !1;
    const c = (e, t) => {
            const n = e.getAppPath();
            return a.resolve(n, "_locales", t, "messages.json")
        },
        d = e => {
            let t = e.getLocale().replace("-", "_");
            o.existsSync(c(e, t)) || (t = t.split("_")[0], o.existsSync(c(e, t)) || (t = "en")), r = i.indexOf(t) > -1, s = JSON.parse(o.readFileSync(c(e, t)))
        };
    (() => {
        let e = n(13).app;
        e ? e.on("ready", () => d(e)) : (e = n(13).remote.app, d(e))
    })();
    const l = (e, t = []) => {
            const n = s ? s[e] : null;
            if (n) {
                let e = n.message;
                if ("string" == typeof t && (t = [t]), n.placeholders) {
                    Object.keys(n.placeholders).forEach(t => {
                        const o = n.placeholders[t].content,
                            a = new RegExp(`\\$${t}\\$`, "i");
                        e = e.replace(a, o)
                    })
                }
                for (let n = 0; n < t.length; n++) {
                    const o = "$" + (n + 1);
                    e = e.split(o).join(t[n])
                }
                return e
            }
            return e
        },
        u = () => r;
    n.d(t, "a", function() {
        return l
    }), n.d(t, "b", function() {
        return u
    })
}, , function(e, t, n) {
    "use strict";
    n.r(t);
    var o = n(7),
        a = n(13);
    var i = n(11),
        s = n(0);
    n.d(t, "getPairedClassicRobots", function() {
        return c
    }), n.d(t, "isRobotSupported", function() {
        return d
    }), n.d(t, "usePairedClassicList", function() {
        return l
    }), n.d(t, "supportsClassic", function() {
        return u
    }), n.d(t, "getSignalStrengthThresholds", function() {
        return p
    }), n.d(t, "startDiscovery", function() {
        return b
    }), n.d(t, "stopDiscovery", function() {
        return m
    }), n.d(t, "connect", function() {
        return f
    }), n.d(t, "disconnect", function() {
        return v
    }), n.d(t, "isRobotConnected", function() {
        return O
    }), n.d(t, "getRobotType", function() {
        return h
    }), n.d(t, "getRobotName", function() {
        return g
    }), n.d(t, "getRobotVersions", function() {
        return y
    }), n.d(t, "setRobotColor", function() {
        return E
    }), n.d(t, "getUserRobotColor", function() {
        return T
    }), n.d(t, "setUserRobotColor", function() {
        return R
    }), n.d(t, "getUserRobotVolume", function() {
        return S
    }), n.d(t, "setUserRobotVolume", function() {
        return D
    }), n.d(t, "getUserSensorSetting", function() {
        return C
    }), n.d(t, "setUserSensorSetting", function() {
        return A
    }), n.d(t, "getUserJoytickSetting", function() {
        return N
    }), n.d(t, "setUserJoytickSetting", function() {
        return j
    }), n.d(t, "getUserRobotSpeed", function() {
        return M
    }), n.d(t, "setUserRobotSpeed", function() {
        return w
    }), n.d(t, "setUserPreviousRobotType", function() {
        return I
    }), n.d(t, "getUserPreviousRobotType", function() {
        return k
    }), n.d(t, "setRobotMovement", function() {
        return x
    }), n.d(t, "startRobotCalibration", function() {
        return L
    }), n.d(t, "updateRobotCalibration", function() {
        return _
    }), n.d(t, "endRobotCalibration", function() {
        return P
    }), n.d(t, "forceFirmwareUpdate", function() {
        return B
    }), n.d(t, "runProgram", function() {
        return $
    }), n.d(t, "stopProgram", function() {
        return U
    }), n.d(t, "setFrontLED", function() {
        return V
    }), n.d(t, "setBackLED", function() {
        return W
    }), n.d(t, "setBackLEDBrightness", function() {
        return F
    }), n.d(t, "setHoloProjector", function() {
        return Y
    }), n.d(t, "setLogicDisplay", function() {
        return H
    }), n.d(t, "playSound", function() {
        return G
    }), n.d(t, "stopSound", function() {
        return q
    }), n.d(t, "playAnimation", function() {
        return z
    }), n.d(t, "cancelAnimation", function() {
        return K
    }), n.d(t, "stopAnimation", function() {
        return X
    }), n.d(t, "setHeadLED", function() {
        return J
    }), n.d(t, "applyUserRobotSettings", function() {
        return Q
    }), n.d(t, "turnOnLights", function() {
        return Z
    }), n.d(t, "turnOffLights", function() {
        return ee
    }), n.d(t, "deepSleep", function() {
        return te
    }), n.d(t, "RobotType", function() {
        return o.d
    }), n.d(t, "RobotErrorCode", function() {
        return o.c
    });
    let r = a.remote.getGlobal("robotData");
    s.e(s.b.ROBOT, s.a.Robot.STATE.ROBOT_DATA, e => {
        r = e.payload
    });
    const c = () => {
            s.f(s.b.ROBOT, s.a.Robot.DISCOVERY.GET_PAIRED_CLASSIC_ROBOTS)
        },
        d = () => r.supportsRobot,
        l = () => r.usePairedClassicList,
        u = () => r.supportsClassic,
        p = e => r.signalStrengthThresholds[e.type],
        b = e => {
            s.f(s.b.ROBOT, s.a.Robot.DISCOVERY.START, {
                type: e
            })
        },
        m = () => {
            s.f(s.b.ROBOT, s.a.Robot.DISCOVERY.STOP)
        },
        f = (e, t) => {
            s.f(s.b.ROBOT, s.a.Robot.STATE.CONNECT, {
                type: e,
                name: t
            })
        },
        v = () => {
            s.f(s.b.ROBOT, s.a.Robot.STATE.DISCONNECT)
        },
        O = () => r.robotConnected,
        h = () => r.robotType,
        g = () => r.robotName,
        y = () => r.currentVersion,
        E = (e, t, n) => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_COLOR, [e, t, n])
        },
        T = () => r.userRobotColor,
        R = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_USER_COLOR, e), Object(i.i)({
                color: e
            })
        },
        S = () => r.userRobotVolume,
        D = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_USER_VOLUME, e)
        },
        C = () => r.sensorEnabled,
        A = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_SENSORS_ENABLED, e), Object(i.i)({
                sensorData: e
            })
        },
        N = () => r.joystickEnabled,
        j = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_JOYSTICK_ENABLED, e), Object(i.i)({
                joystick: e
            })
        },
        M = () => r.robotSpeed,
        w = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_SPEED, e), Object(i.i)({
                speed: e
            })
        },
        I = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_PREVIOUS_ROBOT_TYPE, e), Object(i.i)({
                previousRobotType: e
            })
        },
        k = () => r.previousRobotType,
        x = (e, t) => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_MOVEMENT, [e, t])
        },
        L = () => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.START_CALIBRATION)
        },
        _ = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.UPDATE_CALIBRATION, e)
        },
        P = () => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.END_CALIBRATION)
        },
        B = () => {
            s.f(s.b.ROBOT, s.a.Robot.FIRMWARE_UPDATE.FORCE_UPDATE)
        },
        $ = (e, t) => {
            s.f(s.b.ROBOT, s.a.Robot.PROGRAM.RUN, [e, t])
        },
        U = e => {
            s.f(s.b.ROBOT, s.a.Robot.PROGRAM.STOP, e)
        },
        V = (e, t, n) => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_FRONT_LED, [e, t, n])
        },
        W = (e, t, n) => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_BACK_LED, [e, t, n])
        },
        F = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_BACK_LED_BRIGHTNESS, e)
        },
        Y = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_HOLOPROJECTOR, e)
        },
        H = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_LOGIC_DISPLAY, e)
        },
        G = (e, t) => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.PLAY_SOUND, [e, t])
        },
        q = () => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.STOP_SOUND)
        },
        z = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.PLAY_ANIMATION, e)
        },
        K = () => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.CANCEL_ANIMATION)
        },
        X = () => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.STOP_ANIMATION)
        },
        J = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.SET_HEAD_LED, e)
        },
        Q = e => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.APPLY_USER_SETTINGS, e)
        },
        Z = () => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.TURN_ON_LIGHTS)
        },
        ee = () => {
            s.f(s.b.ROBOT, s.a.Robot.COMMAND.TURN_OFF_LIGHTS)
        },
        te = () => {
            s.f(s.b.ROBOT, s.a.Robot.STATE.DEEP_SLEEP)
        }
}, function(e, t, n) {
    "use strict";
    const o = "create",
        a = "send",
        i = "set",
        s = "event",
        r = "exception",
        c = "timing",
        d = "screenview";
    var l = n(6);
    const u = {
        ACCOUNT: "User Account",
        APP: "Application",
        CANVAS: "Canvas",
        ERROR: "Error",
        SITE: "Site",
        TIMER: {
            TIME_TO_SITE_LOADED: "Time To Site Ready",
            TIME_IN_CANVAS: "Time In canvas"
        },
        ROBOT: "Robot",
        PROGRAM: "Program"
    };
    n.d(t, "a", function() {
        return g
    });
    const p = {},
        b = (e, t, n, o) => {
            ((e, t, n, o) => {
                ga(a, s, e, t, n, o)
            })(e, t, n, o)
        },
        m = (e, t, n) => ((e, t, n) => {
            ga(a, c, e, t, n)
        })(e, t, n),
        f = (e, t, n) => b(u.APP, e, t, n),
        v = e => {
            (e => {
                ga(a, d, {
                    screenName: e
                })
            })(e)
        },
        O = {
            "Sign Up": /^account\/signup$/,
            Dashboard: /^dashboard$/,
            "My Programs": /^remixes\/me$/,
            "Program Details": /^remixes\/.*$/,
            "My Workbook": /^dashboard\/workbook$/,
            "My Activities": /^cwists\/category\/me$/,
            Programs: /^remixes$/,
            Activities: /^cwists\/category$/,
            "Activity Details": /^cwists\/preview\/.*$/,
            "Activity Steps": /^cwists\/cwistings\/.*$/,
            "My Classes": /^family$/,
            Assignments: /^family\/assignments$/
        },
        h = e => {
            const t = Date.now() - p[e];
            return delete p[e], t
        },
        g = {
            start: () => {
                ((e, t, n) => {
                    ga(o, e, {
                        cookieDomain: "none",
                        legacyHistoryImport: !1,
                        storage: "none"
                    }), ga(i, "checkProtocolTask", () => {}), ga(i, "appName", "sprk-electron"), ga(i, "appVersion", t), ga(n)
                })("UA-18158757-15", Object(l.e)(), () => {
                    f("Launch")
                })
            },
            sendAccountEvent: (e, t, n) => b(u.ACCOUNT, e, t, n),
            sendAppEvent: f,
            sendAppLoadTiming: () => m(u.TIMER.TIME_TO_SITE_LOADED, "Total Time", Math.round(performance.now())),
            sendCanvasEvent: (e, t, n) => b(u.CANVAS, e, t, n),
            sendErrorEvent: (e, t, n) => b(u.ERROR, e, t, n),
            sendSiteEvent: (e, t, n) => b(u.SITE, e, t, n),
            sendRobotEvent: (e, t, n) => b(u.ROBOT, e, t, n),
            sendScreenView: e => {
                const t = new URL(e).pathname.slice(1);
                if ("" !== t) {
                    for (const e in O)
                        if (O[e].test(t)) return void v(e);
                    v(t)
                } else v("Home")
            },
            sendProgramEvent: (e, t, n) => b(u.PROGRAM, e, t, n),
            sendException: (e, t) => ((e, t) => {
                ga(a, r, {
                    exDescription: e,
                    exFatal: !0 === t
                })
            })(e, t),
            timers: u.TIMER,
            timer: {
                setTimer: e => {
                    p[e] = Date.now()
                },
                completeTimer: (e, t) => {
                    m(e, t, (e => p[e] ? h(e) : new Error("Timer does not exist"))(e))
                }
            }
        }
}, function(e, t, n) {
    "use strict";
    (function(e, o) {
        n.d(t, "a", function() {
            return E
        });
        var a = n(4),
            i = n(1),
            s = n(6),
            r = n(17);
        const c = [];
        let d = !1;
        const l = () => {
                if (!u() && !d) {
                    d = !0, c.shift()()
                }
            },
            u = () => 0 === c.length,
            p = ({
                container: t,
                template: n,
                target: o,
                modalDetails: a
            }) => {
                e(t).html(n);
                const i = e(o);
                a.content ? (i.html(a.content), a.title && i.find(".modal-title").text(a.title)) : (i.find(".modal-title").text(a.title), ((e, t) => {
                    if (t) {
                        const n = e.find(".modal-body");
                        if (Array.isArray(t))
                            for (let e = 0; e < t.length; ++e) n.append(`<p>${t[e]}</p>`);
                        else n.append(`<p>${t}</p>`)
                    }
                })(i, a.body), a.footer && i.find(".modal-footer").html(a.footer))
            },
            b = ({
                cancelButtonTitle: e = Object(i.a)("cancelButtonText"),
                onCancel: t
            }, n, o) => {
                const a = n.find(".cancel");
                t ? (a.text(e), a.on("click", () => {
                    t(o)
                })) : a.remove()
            },
            m = ({
                confirmButtonTitle: e = Object(i.a)("saveButtonText"),
                onConfirm: t,
                isDestructive: n
            }, o, a) => {
                const s = o.find(".submit");
                t ? (s.text(e), s.on("click", () => {
                    t(a)
                }), n && 1 === n && s.addClass("sprk-red")) : s.remove()
            },
            f = t => g({
                $target: e("#error-modal"),
                callback: t
            }),
            v = ({
                numberOfLines: t = 1,
                defaultValue: n,
                isDismissible: o = !0,
                onConfirm: a,
                onCancel: i
            }) => {
                const s = e("#custom-modal");
                t && t > 1 ? s.find(".modal-body").append(`<textarea id="text-input-field" class="sprk-input" rows=${t}></textarea>`) : s.find(".modal-body").append('<input type="text" id="text-input-field" class="sprk-input" />');
                const r = e("#text-input-field");
                return r.attr("placeholder", n), r.on("focus", e => {
                    "" !== r.attr("placeholder") && (e.currentTarget.value = n), r.attr("placeholder", ""), O()
                }), o && r.on("keydown", e => {
                    13 === e.keyCode ? a(r) : 27 === e.keyCode && i()
                }), r
            },
            O = () => {
                e("#text-input-field").removeClass("error"), e("#custom-modal").find(".input-error").text("")
            },
            h = ({
                $target: e,
                isDismissible: t = !1,
                callback: n,
                onReady: o
            }) => {
                r.b(e, {
                    dismissible: t,
                    opacity: .7,
                    ready: o,
                    complete: () => {
                        y(), "function" == typeof n && n()
                    }
                })
            },
            g = ({
                $target: e,
                callback: t
            }) => {
                r.a(e, {
                    complete: () => {
                        e.remove(), y(), t && t()
                    }
                })
            },
            y = () => {
                u() || (d = !1, l()), d = !1
            },
            E = {
                openCustomModal: (t, {
                    callback: a,
                    applyBeforeOpen: i = (() => {}),
                    onReady: s
                }) => {
                    const c = o.assign({
                        isDismissible: !1
                    }, t);
                    p({
                        modalDetails: c,
                        target: "#custom-modal",
                        container: "#custom-modal-container",
                        template: n(200)
                    });
                    const d = e("#custom-modal");
                    b(c, d), m(c, d), ((e, {
                        onCancel: t,
                        isDismissible: n
                    }) => {
                        n ? n && t ? e.find(".close-button").on("click", () => t()) : e.find(".close-button").on("click", () => r.a(e, {
                            complete: () => {}
                        })) : e.find(".close-button").remove()
                    })(d, c), i(), h({
                        $target: d,
                        isDismissible: c.isDismissible,
                        callback: a,
                        onReady: s
                    })
                },
                closeCustomModal: t => g({
                    $target: e("#custom-modal"),
                    callback: t
                }),
                openConfirmationModal: (t, o) => {
                    const a = "#confirmation-modal";
                    p({
                        modalDetails: t,
                        target: a,
                        container: "#confirmation-modal-container",
                        template: n(165)
                    });
                    const i = e(a);
                    b(t, i), m(t, i), h({
                        $target: i,
                        isDismissible: t.isDismissible,
                        callback: o
                    })
                },
                closeConfirmationModal: t => g({
                    $target: e("#confirmation-modal"),
                    callback: t
                }),
                openCommentDialog: (t, a) => {
                    const i = o.assign({
                        confirmButtonTitle: "",
                        cancelButtonTitle: "",
                        isDismissible: !1
                    }, t);
                    p({
                        modalDetails: i,
                        target: "#comment-modal",
                        container: "#custom-modal-container",
                        template: n(201)
                    });
                    const s = e("#comment-modal"),
                        r = v(i);
                    b(i, s), m(i, s, r), h({
                        $target: s,
                        isDismissible: i.isDismissible,
                        callback: () => {
                            r.focus(), a && a()
                        }
                    })
                },
                closeCommentDialog: t => g({
                    $target: e("#comment-modal"),
                    callback: t
                }),
                openTextDialog: (t, {
                    callback: o,
                    applyBeforeOpen: a = (() => {}),
                    onReady: i
                }) => {
                    p({
                        modalDetails: t,
                        target: "#custom-modal",
                        container: "#custom-modal-container",
                        template: n(202)
                    });
                    const s = e("#custom-modal"),
                        r = v(t);
                    b(t, s, r), m(t, s, r), a(r), h({
                        $target: s,
                        isDismissible: t.isDismissible,
                        callback: () => {
                            r.focus(), o && o()
                        },
                        onReady: i
                    })
                },
                closeTextDialog: t => g({
                    $target: e("#custom-modal", t)
                }),
                addInputErrors: t => {
                    O(), e("#custom-modal").find(".input-error").append(t.payload), e("#text-input-field").addClass("error")
                },
                openErrorModal: (t, o) => {
                    p({
                        modalDetails: t,
                        target: "#error-modal",
                        container: "#error-modal-container",
                        template: n(203)
                    });
                    const r = e("#error-modal");
                    (({
                        isCritical: e,
                        confirmButtonTitle: t = Object(i.a)("acknowledgeButton"),
                        onConfirm: n = f
                    }, o) => {
                        const a = o.find(".submit");
                        a.text(t), e && !0 === e ? a.on("click", () => {
                            Object(s.j)()
                        }) : a.on("click", () => {
                            n(), f()
                        })
                    })(t, r), c.push(() => {
                        h({
                            $target: r,
                            isDismissible: t.isDismissible,
                            callback: o
                        })
                    }), a.a.sendErrorEvent(t.title, t.body), l()
                },
                closeErrorModal: f
            }
    }).call(this, n(8), n(16))
}, function(e, t, n) {
    "use strict";
    var o = n(21);
    n.d(t, "a", function() {
        return o.a
    });
    var a = n(167);
    n.d(t, "b", function() {
        return a.a
    }), n.d(t, "c", function() {
        return a.b
    }), n.d(t, "d", function() {
        return a.c
    }), n.d(t, "e", function() {
        return a.d
    }), n.d(t, "f", function() {
        return a.e
    }), n.d(t, "g", function() {
        return a.f
    }), n.d(t, "h", function() {
        return a.g
    }), n.d(t, "i", function() {
        return a.h
    }), n.d(t, "j", function() {
        return a.i
    }), n.d(t, "k", function() {
        return a.j
    }), n.d(t, "l", function() {
        return a.k
    })
}, function(e, t, n) {
    "use strict";
    n.d(t, "d", function() {
        return o
    }), n.d(t, "c", function() {
        return a
    }), n.d(t, "b", function() {
        return i
    }), n.d(t, "a", function() {
        return c
    }), n.d(t, "e", function() {
        return d
    });
    const o = {
            SPHERO: {
                type: "SPHERO",
                name: "spheroName",
                prefix: "Sphero-",
                displayName: "Sphero",
                id: 2
            },
            SPRK2: {
                type: "SPRK+",
                name: "sprkPlusName",
                prefix: "SK-",
                displayName: "Sprk+",
                id: 2
            },
            MINI: {
                type: "MINI",
                name: "miniName",
                prefix: "SM-",
                displayName: "Sphero Mini",
                id: 7
            },
            OLLIE: {
                type: "OLLIE",
                name: "ollieName",
                prefix: "2B-",
                displayName: "Ollie",
                id: 3
            },
            BB8: {
                type: "BB-8",
                name: "bb8Name",
                prefix: "BB-",
                displayName: "BB-8",
                id: 4
            },
            BB9E: {
                type: "BB-9E",
                name: "bb9eName",
                prefix: "GB-",
                displayName: "BB-9E",
                id: 5
            },
            R2D2: {
                type: "R2-D2",
                name: "r2d2Name",
                prefix: "D2-",
                displayName: "R2-D2",
                id: 6
            },
            R2Q5: {
                type: "R2-Q5",
                name: "r2q5Name",
                prefix: "Q5-",
                displayName: "R2-Q5",
                id: 8
            },
            BOLT: {
                type: "BOLT",
                name: "boltName",
                prefix: "SB-",
                displayName: "Sphero BOLT",
                id: 9
            },
            NONE: {
                type: "NONE",
                name: "robotName",
                prefix: "",
                displayName: "",
                id: 0
            },
            UNSUPPORTED: {
                type: "UNSUPPORTED",
                name: "robotName",
                prefix: "",
                displayName: "",
                id: 0
            }
        },
        a = {
            DEFAULT: 3e4,
            NO_ROBOT: 30001,
            CANCELLED: 30002,
            NO_BLUETOOTH: 30003,
            NOT_SUPPORTED: 30004,
            NO_INTERNET: 30005,
            UNSUPPORTED_FIRMWARE: 30006,
            NO_BLE: 30007,
            BLUETOOTH_DISABLED: 30008,
            V2_FIRMWARE_OUTDATED: 30009
        },
        i = {
            color: {
                r: 0,
                g: 133,
                b: 202,
                a: 1
            },
            speed: 166,
            sensorData: !0,
            joystick: !1,
            previousRobotType: o.NONE,
            volume: 255
        },
        s = "Inductive",
        r = "Usb",
        c = {
            [o.SPHERO.type]: s,
            [o.OLLIE.type]: r,
            [o.BB8.type]: s,
            [o.SPRK2.type]: s,
            [o.R2D2.type]: r,
            [o.R2Q5.type]: r,
            [o.BB9E.type]: s,
            [o.MINI.type]: r,
            [o.BOLT.type]: s
        },
        d = (o.SPHERO.type, o.OLLIE.type, o.BB8.type, o.SPRK2.type, [o.R2D2.type, o.BB9E.type, o.R2Q5.type])
}, , function(e, t, n) {
    "use strict";
    (function(e, o) {
        n.d(t, "c", function() {
            return a
        }), n.d(t, "b", function() {
            return i
        }), n.d(t, "f", function() {
            return s
        }), n.d(t, "g", function() {
            return r
        }), n.d(t, "e", function() {
            return d
        }), n.d(t, "d", function() {
            return l
        }), n.d(t, "a", function() {
            return u
        });
        n(7);
        const a = (e, t) => Math.floor(Math.random() * (t - e)) + e,
            i = e => {
                const t = e.split("//")[1].match(/\/(.+)/)[1].split("/");
                return {
                    appDesignation: t[0],
                    action: t[1],
                    id: t[2],
                    subresource: t[3],
                    subresourceId: t[4]
                }
            },
            s = (e, t, n, o) => {
                return `<button id=${e} class="sprk-button ${n=n.join(" ")}" ${c(o)}>${t}</button>`
            },
            r = (e, t, n, o = "Off", a = "On") => `<span>${t}</span>\n            <div></div>\n            <div class="switch">\n                <label>${o}\n                    <input type="checkbox" id="${e}" ${n?"checked":""} /><span class="lever"></span>\n                ${a}</label>\n            </div>`,
            c = t => e.reduce(t, (e, t, n) => e.concat(`data-${n}="${t}"`), ""),
            d = (e, t, n = [], o = {}, a = !1) => {
                n = n.join(" ");
                const i = c(o);
                return a && (t = t.toUpperCase()), `<button id="${e}" class="sprk-button ${n}" ${i}>${t}</button>`
            },
            l = (e, t) => Number(`${Math.round(e+"e"+t)}e-${t}`),
            u = e => {
                0
            }
    }).call(this, n(16), n(8))
}, function(e, t, n) {
    "use strict";
    var o = n(166);
    n.d(t, "a", function() {
        return o.a
    }), n.d(t, "b", function() {
        return o.b
    }), n.d(t, "c", function() {
        return o.c
    }), n.d(t, "d", function() {
        return o.d
    }), n.d(t, "e", function() {
        return o.e
    }), n.d(t, "f", function() {
        return o.f
    }), n.d(t, "g", function() {
        return o.g
    }), n.d(t, "h", function() {
        return o.h
    }), n.d(t, "i", function() {
        return o.i
    }), n.d(t, "j", function() {
        return o.j
    }), n.d(t, "k", function() {
        return o.k
    }), n.d(t, "l", function() {
        return o.l
    }), n.d(t, "m", function() {
        return o.m
    }), n.d(t, "n", function() {
        return o.n
    }), n.d(t, "o", function() {
        return o.o
    }), n.d(t, "p", function() {
        return o.p
    })
}, function(e, t, n) {
    "use strict";
    n.d(t, "d", function() {
        return d
    }), n.d(t, "h", function() {
        return l
    }), n.d(t, "b", function() {
        return u
    }), n.d(t, "g", function() {
        return p
    }), n.d(t, "i", function() {
        return b
    }), n.d(t, "f", function() {
        return m
    }), n.d(t, "c", function() {
        return f
    }), n.d(t, "a", function() {
        return v
    }), n.d(t, "e", function() {
        return g
    });
    var o = n(175),
        a = n.n(o),
        i = n(14),
        s = n(7),
        r = n(6);
    const c = new a.a("sphero-app");
    c.version(2).stores({
        users: "&id, launchCount, firstDrive, showSensorDataHint",
        app: "settings"
    }).upgrade(() => {
        c.app.toCollection().modify(e => {
            delete e.robotSettings.sleepInCharger
        })
    }), c.version(1).stores({
        users: "&id, launchCount, firstDrive, showSensorDataHint",
        app: "settings"
    });
    const d = () => Object(i.c)().then(e => c.users.get(e, e => {
            if (e) return e;
            Object(i.c)().then(e => {
                c.users.add({
                    id: e,
                    launchCount: 0,
                    firstDrive: !0,
                    firstText: !0,
                    showSensorDataHint: !0
                })
            })
        })),
        l = e => {
            Object(i.c)().then(t => {
                c.users.update(t, e)
            })
        },
        u = e => {
            c.app.get("application").then(t => {
                e(t)
            })
        },
        p = (e, t) => {
            c.app.update("application", e).then(() => {
                t && t()
            })
        },
        b = e => {
            c.app.get("application").then(t => {
                const n = Object.assign({}, t.robotSettings, e);
                c.app.update("application", Object.assign(t, {
                    robotSettings: n
                }))
            })
        },
        m = e => c.app.put(Object.assign({
            settings: "chart states"
        }, e)),
        f = () => c.app.get("chart states"),
        v = () => {
            c.app.delete("chart states")
        },
        O = (e, t) => {
            c.users.add(Object.assign({
                id: e,
                launchCount: 0,
                firstDrive: !0,
                firstText: !0,
                showSensorDataHint: !0
            }, t))
        },
        h = e => {
            e.settings = "application", p(e)
        },
        g = () => {
            c.app.get("application").then(e => {
                e || c.app.add({
                    settings: "application",
                    firstText: !0,
                    canvasAnimations: !1,
                    canvasSounds: !1,
                    robotSettings: s.b
                })
            }), Object(r.g)(O, h)
        };
    g()
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "f", function() {
            return p
        }), n.d(t, "d", function() {
            return m
        }), n.d(t, "c", function() {
            return f
        }), n.d(t, "e", function() {
            return v
        }), n.d(t, "b", function() {
            return O
        }), n.d(t, "a", function() {
            return y
        });
        var o = n(0),
            a = n(1),
            i = n(22),
            s = n(4),
            r = n(3),
            c = n(17),
            d = n(15),
            l = n(24);
        let u = !1;
        const p = () => {
                const t = e("#robot-status-container");
                t.html(n(191)), e("#robot-disconnected").find("p").html(Object(a.a)("connectComponentText")), t.on("click", () => {
                    t.hasClass("disconnecting") || (r.isRobotConnected() ? h() : o.f(o.b.ROBOT, o.a.Robot.DISCOVERY.TOGGLE_CONNECTION))
                }), b()
            },
            b = t => {
                t || v(), e("#robot-status").hide(), e("#robot-status-container").removeClass("disconnecting"), e("#robot-disconnected").show(), e("#robot-status").empty()
            },
            m = b,
            f = () => {
                v(), e("#robot-status").html(`<div id="connected-robot-icon" class="robot-icon ${r.getRobotType().type}"></div><div id="connected-robot-name">${r.getRobotName()}</div>`), e("#robot-disconnected").hide(), e("#robot-status").show()
            },
            v = t => {
                u && !t || (u = !1, e("#robot-status-container").removeClass("closed"))
            },
            O = t => {
                e("#robot-status-container").addClass("closed"), t && (u = !0)
            },
            h = () => {
                const e = Object(l.b)(E);
                o.e(o.b.WINDOW, o.a.Window.DRAWER_CLOSED, g), i.c(e)
            },
            g = () => {
                o.d(o.b.WINDOW, o.a.Window.DRAWER_CLOSED, g)
            },
            y = v,
            E = {
                [l.a.UPDATE]: () => {
                    (t => {
                        const o = e("#confirmation-modal-container");
                        o.html(n(165));
                        const i = o.find(".confirmation-dialog");
                        i.find(".modal-title").text(Object(a.a)("fwUpdateConfirmTitle")), i.find(".modal-body").text(Object(a.a)("fwUpdateConfirmBody")), i.find(".cancel").on("click", () => {
                            c.a(i, {
                                complete: () => {
                                    o.empty(), t && t(!1)
                                }
                            })
                        }).text(Object(a.a)("cancelButtonText")), i.find(".submit").on("click", () => {
                            c.a(i, {
                                complete: () => {
                                    o.empty(), t && t(!0)
                                }
                            })
                        }).text(Object(a.a)("fwUpdateConfirmText")), c.b(i, {
                            dismissible: !1
                        })
                    })(e => {
                        e && r.forceFirmwareUpdate()
                    }), i.a()
                },
                [l.a.SLEEP]: () => {
                    s.a.sendRobotEvent(o.a.Robot.STATE.DEEP_SLEEP, "state", "deep sleep"), o.f(o.b.ROBOT, o.a.Robot.STATE.DEEP_SLEEP), i.a()
                },
                [l.a.DISCONNECT]: () => {
                    r.disconnect(), e("#robot-status-container").addClass("disconnecting"), e("#robot-status").html('<div id="disconnect-wrapper"></div>'), Object(d.a)("#disconnect-wrapper", "yellow", "small"), Object(d.d)("#disconnect-wrapper"), e("#disconnect-wrapper").append(`<span>${Object(a.a)("disconnecting")}</span>`), i.a()
                },
                [l.a.VOLUME]: () => {
                    const t = e("#robot-volume-range")[0];
                    if (!t.noUiSlider) return;
                    const n = parseInt(t.noUiSlider.get());
                    isNaN(n) || r.setUserRobotVolume(t.noUiSlider.get())
                }
            }
    }).call(this, n(8))
}, function(e, t) {
    e.exports = require("electron")
}, function(e, t, n) {
    "use strict";
    (function(e, o) {
        n.d(t, "a", function() {
            return u
        }), n.d(t, "c", function() {
            return p
        }), n.d(t, "e", function() {
            return b
        }), n.d(t, "f", function() {
            return m
        }), n.d(t, "d", function() {
            return f
        }), n.d(t, "g", function() {
            return v
        }), n.d(t, "b", function() {
            return O
        });
        var a = n(10),
            i = n(179),
            s = n.n(i),
            r = n(178),
            c = n.n(r),
            d = n(40),
            l = n.n(d);
        n(177);
        const u = () => {
                const t = 'var BASE_URL = "https://edu.sphero.com/";' + s.a + c.a,
                    n = e("#site-webview").getDOMObject();
                Object(a.b)(n, t, !1, e => {
                    o.isError(e) && Object(a.b)(n, t, !1, e => {
                        o.isError(e) && n.reload()
                    })
                })
            },
            p = () => new Promise((t, n) => {
                Object(a.b)(e("#site-webview").getDOMObject(), l.a, !1, e => {
                    !e || o.isError(e) ? n("Error executing code getting cookies - User id") : t(e.userId)
                })
            }),
            b = t => {
                Object(a.b)(e("#site-webview").getDOMObject(), `window.nativeAppManager.setConnectedRobot(${JSON.stringify(t)});`, !0)
            },
            m = t => {
                Object(a.b)(e("#site-webview").getDOMObject(), `window.nativeAppManager.setProgramRunningState(${JSON.stringify(t)});`, !0)
            },
            f = t => {
                Object(a.b)(e("#site-webview").getDOMObject(), `window.nativeAppManager.setAnimationFramesLoaded(${JSON.stringify(t)});`, !0)
            },
            v = t => {
                Object(a.b)(e("#site-webview").getDOMObject(), `window.nativeAppManager.setProgramRuntimeError(${JSON.stringify(t)});`, !0)
            },
            O = () => {
                Object(a.b)(e("#site-webview").getDOMObject(), 'document.addEventListener("dragover", e => e.preventDefault()); document.addEventListener("drop", e => e.preventDefault());', !0)
            }
    }).call(this, n(8), n(16))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return o
        }), n.d(t, "c", function() {
            return a
        }), n.d(t, "b", function() {
            return i
        }), n.d(t, "d", function() {
            return s
        });
        const o = (t = ".preloader-wrapper", n = "blue", o = "") => {
                e(t).html(((e, t) => `<div class="preloader-wrapper ${e} active"><div class="spinner-layer spinner-${t}-only"><div class="circle-clipper left"><div class="circle"></div></div><div class="gap-patch"><div class="circle"></div> </div><div class="circle-clipper right"><div class="circle"></div></div></div></div>`)(o, n))
            },
            a = t => {
                e(t).addClass("failed"), e(`${t} > .preloader-wrapper`).toggle(), e(t).append('<div id="load-failed"></div>')
            },
            i = (t = ".preloader-wrapper") => {
                e(t).hide()
            },
            s = (t = ".preloader-wrapper") => {
                e(t).show()
            }
    }).call(this, n(8))
}, , function(e, t, n) {
    "use strict";
    n.d(t, "b", function() {
        return a
    }), n.d(t, "a", function() {
        return i
    });
    var o = n(0);
    const a = (e, t) => {
            e && (s(t), r(t), c(o.a.Window.MODAL_WILL_OPEN), e.openModal(t))
        },
        i = (e, t) => {
            e && (r(t), c(o.a.Window.MODAL_WILL_CLOSE), e.closeModal(t))
        },
        s = e => {
            const t = e.ready;
            e.ready = (() => {
                c(o.a.Window.MODAL_OPENED), t && t()
            })
        },
        r = e => {
            const t = e.complete;
            e.complete = (() => {
                c(o.a.Window.MODAL_CLOSED), t && t()
            })
        },
        c = e => {
            o.f(o.b.WINDOW, e)
        }
}, , function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "d", function() {
            return k
        }), n.d(t, "b", function() {
            return U
        }), n.d(t, "c", function() {
            return V
        }), n.d(t, "a", function() {
            return W
        });
        var o = n(3),
            a = n(6);
        const i = {
                87: [0, 1],
                65: [-1, 0],
                83: [0, -1],
                68: [1, 0]
            },
            s = {
                37: -1,
                39: 1
            },
            r = {
                38: 5,
                40: -5
            };
        let c, d, l, u, p, b = null,
            m = null,
            f = null,
            v = null,
            O = !1,
            h = null;
        const g = () => {
                y() && E()
            },
            y = () => u.currentHeading >= 0 || null !== u.timer,
            E = () => {
                const e = y();
                A(), u.currentHeading = e ? -1 : 0, y() ? o.startRobotCalibration() : o.endRobotCalibration(), F(`toggled aiming: ${y()}`), S()
            },
            T = () => {
                R(), u.timer = setTimeout(g, 1e3)
            },
            R = () => {
                u && u.timer && (clearTimeout(u.timer), u.timer = null)
            },
            S = () => {
                m && m(c, y(), u.increment, p)
            },
            D = () => {
                if (!p.enabled) {
                    const e = d.targetVector;
                    let t = d.currentVector;
                    if (Math.pow(e[0] - t[0], 2) + Math.pow(e[1] - t[1], 2) > 1e-5) {
                        const n = d.smoothing;
                        t[0] = (1 - n) * e[0] + n * t[0], t[1] = (1 - n) * e[1] + n * t[1]
                    } else t = [e[0], e[1]];
                    d.currentVector = t
                }
                if (Math.abs(u.increment) > .001) {
                    let e = u.currentHeading + u.increment;
                    for (; e >= 360;) e -= 360;
                    for (; e < 0;) e += 360;
                    u.currentHeading = Math.round(e)
                }
                if (Math.abs(l.increment) > .001) {
                    const e = l.currentValue + l.increment;
                    W(Math.max(0, Math.min(e, 255))), S()
                }
                C()
            },
            C = () => {
                if (y()) u.lastHeading !== u.currentHeading && (F(`aiming = ${u.currentHeading}`), u.lastHeading = u.currentHeading, o.updateRobotCalibration(u.currentHeading));
                else if (!p.enabled) {
                    const e = d.currentVector;
                    let t = 180 * Math.atan2(e[0], e[1]) / Math.PI;
                    for (; t < 0;) t += 360;
                    t = Math.round(t);
                    let n = Math.sqrt(Math.pow(e[0], 2) + Math.pow(e[1], 2));
                    n *= l.currentValue, n = Math.round(n), d.lastHeading === t && 0 === t && d.lastMagnitude === n && 0 === n || (F(`[Driving] heading = ${t}; magnitude = ${n}`), d.lastHeading = t, d.lastMagnitude = n, o.setRobotMovement(t, n))
                }
            },
            A = () => {
                R(), c = {}, d = {
                    targetVector: [0, 0],
                    currentVector: [0, 0],
                    lastHeading: -999,
                    lastMagnitude: -999,
                    smoothing: 0
                }, u = {
                    currentHeading: -1,
                    lastHeading: -999,
                    increment: 0,
                    timer: null
                }, l = {
                    currentValue: o.getUserRobotSpeed(),
                    increment: 0
                }, p = {
                    timer: null,
                    target: null,
                    location: {},
                    mouseDown: !1,
                    touchDown: !1,
                    enabled: !!p && p.enabled
                }
            },
            N = e => {
                const t = (e => {
                    const t = Math.pow(e[0], 2) + Math.pow(e[1], 2);
                    return Math.sqrt(t)
                })(e);
                return t > 0 && (e[0] /= t, e[1] /= t), e
            },
            j = (e, t) => {
                i[e] && !O ? (g(), ((e, t) => {
                    c[e] = t, d.targetVector = [0, 0];
                    for (const e in i) c[e] && (d.targetVector[0] += i[e][0], d.targetVector[1] += i[e][1]);
                    N(d.targetVector), S()
                })(e, t)) : s[e] ? ((e, t) => {
                    if (t && !y() && E(), c[e] = t, y()) {
                        let e = 0,
                            t = !1;
                        for (const n in s) c[n] && (t = !0, e += s[n]);
                        u.increment = 5 * Math.max(-1, Math.min(e, 1)), t ? R() : T()
                    }
                    S()
                })(e, t) : r[e] && !O && (g(), ((e, t) => {
                    c[e] = t, l.increment = 0;
                    for (const e in r) c[e] && (l.increment += r[e]);
                    S()
                })(e, t))
            },
            M = e => {
                const t = e.keyCode;
                27 !== t && (e.originalEvent.stopPropagation(), e.originalEvent.preventDefault(), j(t, !0))
            },
            w = e => {
                e.originalEvent.stopPropagation(), e.originalEvent.preventDefault();
                const t = e.keyCode;
                j(t, !1)
            },
            I = () => {
                g(), A(), S(), C()
            },
            k = () => {
                y() && E(), p.enabled = !p.enabled, o.setUserJoytickSetting(p.enabled), A(), S()
            },
            x = (e, t) => {
                if (!p.enabled || y()) return;
                const n = {
                    x: e,
                    y: t
                };
                let o = v.width / 2;
                const a = v.left + o,
                    i = v.top + o;
                o -= 18;
                const s = {
                    x: n.x - a,
                    y: i - n.y
                };
                let r = Math.atan2(o, 0) - Math.atan2(s.y, s.x);
                (r = 180 * r / Math.PI) < 0 && (r += 360);
                let c = Math.sqrt(Math.pow(s.x, 2) + Math.pow(s.y, 2)) / o;
                c > 1 && (n.x -= s.x - s.x / c, n.y += s.y - s.y / c), c = Math.abs(c) > .8 ? 1 : c * Math.abs(c), c = Math.min(Math.max(c, -1), 1), c = Math.round(c * l.currentValue), p.target = {
                    magnitude: c,
                    heading: r
                }, p.timer || (L(), p.timer = setInterval(L, 33)), p.location = {
                    y: `${n.y-v.top}px`,
                    x: `${n.x-v.left}px`
                }, S()
            },
            L = () => {
                let e, t;
                p.target ? (e = p.target.heading, t = p.target.magnitude) : (e = t = 0, clearInterval(p.timer), p.timer = null), F(`[Driving] heading = ${e}; magnitude = ${t}`), o.setRobotMovement(e, t)
            },
            _ = () => {
                p.enabled && (p.touchDown || p.mouseDown) && (p.location = {
                    x: "",
                    y: ""
                }, p.target = null, p.mouseDown = !1, p.touchDown = !1, S())
            },
            P = e => {
                e && p.enabled && (p.mouseDown = !0, x(e.clientX, e.clientY))
            },
            B = e => {
                e && p.mouseDown && x(e.clientX, e.clientY)
            },
            $ = e => {
                !e || !e.touches || e.touches.length < 1 || (p.touchDown = !0, x(e.touches[0].clientX, e.touches[0].clientY))
            },
            U = (t, n, i, s, r) => {
                if (m = n, O = t, v = s, f = r, h = i, p.enabled = o.getUserJoytickSetting(), !b) {
                    A();
                    const t = e("body");
                    t.on("keydown", M), t.on("keyup", w), Object(a.b)("blur", I), Y(), b = setInterval(D, 33)
                }
                t ? E() : S()
            },
            V = () => {
                if (m = null, O = !1, v = null, f = null, b) {
                    y() ? E() : o.setRobotMovement(0, 0), A();
                    const t = e("body");
                    t.off("keydown"), t.off("keyup"), Object(a.k)("blur", I), H(), clearInterval(b), b = null
                }
            },
            W = e => {
                l.currentValue = e, o.setUserRobotSpeed(e)
            },
            F = e => {
                0
            },
            Y = () => {
                f && Object.keys(f).forEach(t => {
                    const n = e(t);
                    n.on("touchstart mousedown", e => {
                        e.preventDefault(), e.stopPropagation(), j(f[t], !0)
                    }), n.on("touchend mouseup mouseleave", e => {
                        e.preventDefault(), e.stopPropagation(), j(f[t], !1)
                    })
                }), !O && h && (h.on("touchstart touchmove", $), h.on("mousedown", P), e("body").on("mousemove", B), e("body").on("touchend mouseup", _))
            },
            H = () => {
                f && Object.keys(f).forEach(t => {
                    const n = e(t);
                    n.off("touchstart mousedown"), n.off("touchend mouseup mouseleave")
                }), h && (h.off("touchstart touchmove mousedown mousemove"), h = null, e("body").off("touchend mouseup"))
            };
        A()
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "e", function() {
            return y
        }), n.d(t, "c", function() {
            return T
        }), n.d(t, "b", function() {
            return R
        }), n.d(t, "d", function() {
            return D
        }), n.d(t, "a", function() {
            return C
        });
        var o = n(1),
            a = n(15),
            i = n(29),
            s = n(3),
            r = n(12),
            c = n(5),
            d = n(7);
        const l = Object(o.a)("cantConnect"),
            u = Object(o.a)("retryButtonText");
        let p, b, m, f, v, O, h, g;
        const y = (t, n, o) => {
                h = !1, E(t, n, o);
                const i = {
                    title: f,
                    body: p,
                    isDismissible: !1
                };
                c.a.openCustomModal(i, {
                    callback: r.a,
                    applyBeforeOpen: () => {
                        const n = e("#custom-modal");
                        n.addClass("robot-connection-modal robot-connection"), n.find(".modal-footer").append('<div class="flex row center"><div class="loading-graphic-wrapper"><div id="loading-status"></div></div></div>'), t.type === s.RobotType.SPHERO.type && n.find(".loading-graphic-wrapper").before(`<div class="${t.type}Hand help-icon" id="extra-image" ></div>`), n.find(".loading-graphic-wrapper").append(`<div class="${t.type} help-icon" class="loading-graphic"/>`), a.a("#loading-status", "blue")
                    }
                }), s.connect(t, n)
            },
            E = (e, t, n) => {
                O = e, v = t, g = n;
                const a = Object(o.a)(O.name);
                O.type === s.RobotType.SPHERO.type ? (p = Object(o.a)("connectionBodyClassic"), b = Object(o.a)("connectionFailureClassic")) : (p = Object(o.a)("connectionBody", a), b = Object(o.a)("connectionFailureBody", a)), f = Object(o.a)("connectionTitle", a), m = Object(o.a)(`help${d.a[O.type]}`, a)
            },
            T = e => c.a.closeCustomModal(e),
            R = () => {
                if (h) return;
                h = !0;
                const t = () => {
                        C()
                    },
                    n = () => {
                        const n = e("#custom-modal");
                        n.addClass("robot-connection-modal robot-connection connect-failed"), n.find(".modal-footer").append('<div class="flex row center"><div class="loading-graphic-wrapper"><div id="loading-status"></div></div></div>'), O.type === s.RobotType.SPHERO.type && n.find(".loading-graphic-wrapper").before(`<div class="${O.type}Hand help-icon" id="extra-image" ></div>`), n.find(".loading-graphic-wrapper").append(`<div class="${O.type} help-icon" class="loading-graphic"/>`), a.a("#loading-status", "blue"), a.c("#loading-status"), e("#extra-image").hide(), n.find(".modal-title").before('<div class="close-button"></div>'), n.find(".modal-footer").append(`<div class="retry-connection"><button id="retry-connection" class="sprk-button empty retry-connection-btn">${u}</button></div>`), n.find(".modal-footer").append(`<div class="cant-connect"><a href="#" id="cant-connect">${Object(o.a)("cantConnect")}</a></div>`), e("#cant-connect").on("click", () => {
                            c.a.closeCustomModal(() => {
                                i.a(l, m, O, y.bind(null, O, v, g), g)
                            })
                        }), n.find(".close-button").on("click", t), e("#retry-connection").on("click", S)
                    },
                    d = {
                        title: Object(o.a)("connectionTimeoutTitle", Object(o.a)(O.name)),
                        body: b,
                        isDismissible: !0,
                        onCancel: t
                    };
                c.a.closeCustomModal(() => {
                    c.a.openCustomModal(d, {
                        callback: () => {
                            Object(r.a)()
                        },
                        applyBeforeOpen: n
                    })
                })
            },
            S = () => {
                c.a.closeCustomModal(() => {
                    y(O, v, g)
                })
            },
            D = () => e("#custom-modal").hasClass("robot-connection"),
            C = () => {
                c.a.closeCustomModal(r.a)
            }
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    t.a = {
        PLATFORM: {
            MAC_OS: "MAC_OS",
            WINDOWS: "WINDOWS",
            CHROME_OS: "CHROME_OS",
            UNKNOWN: "UNKNOWN"
        },
        PACKAGER: {
            ELECTRON: "ELECTRON",
            CHROME: "CHROME"
        }
    }
}, function(e, t, n) {
    "use strict";
    (function(e, o) {
        n.d(t, "c", function() {
            return c
        }), n.d(t, "a", function() {
            return l
        });
        var a = n(0),
            i = n(3),
            s = n(23),
            r = n(164);
        n.d(t, "b", function() {
            return r.a
        });
        n(11);
        const c = o.debounce(t => {
                const n = [];
                e.each(t, (e, o) => {
                    const a = o.body ? `<div class="option-body">${o.body||""}</div>` : "";
                    n.push(`\n            <div class="option" id=${o.id}>\n                <div class="option-title">${o.title}</div>\n                ${a}\n            </div>`), e !== t.length - 1 && n.push('<div class="separator" />')
                });
                const o = {
                    title: "",
                    help: "Robot Connection Status",
                    content: `<div id="connection-container">\n                    ${n.join("")}\n                </div>`
                };
                d("", [o], "robot-connection content-tabs", () => {
                    t.forEach(t => {
                        if (t.callback)
                            if ("robot-volume" !== t.id) e(`#${t.id}.option`).on("click", () => {
                                t.callback()
                            });
                            else {
                                const n = e("#robot-volume-range")[0];
                                n.noUiSlider || (s.create(n, {
                                    start: Object(i.getUserRobotVolume)(),
                                    connect: "lower",
                                    step: 1,
                                    tooltips: !1,
                                    range: {
                                        min: 0,
                                        max: 255
                                    }
                                }), n.noUiSlider.on("change", t.callback))
                            }
                    })
                })
            }, 500, {
                leading: !0
            }),
            d = (t, o, i, s) => {
                const r = n(197);
                e("#right-drawer-container").html(r);
                const c = e("#right-drawer"),
                    d = c.find(".content-tabs"),
                    p = c.find(".tabs");
                o.length > 1 ? (e(".info-title").html(`<h3>${t}</h3>`), e.each(o, (t, n) => {
                    p.append(`<li id="item-list-${t}" class="tab col s3"><a id="tab-link-${t}" href="#content-tab-${t}"/></li>`), d.append(`<div id="content-tab-${t}" </div>`), e(`#content-tab-${t}`).html(n.content);
                    const o = e(`#tab-link-${t}`);
                    o.html(n.title), n.help && (e(o).attr("data-tooltip", n.help), e(o).attr("data-position", "bottom"), e(o).attr("data-delay", "50"), e(o).tooltip({
                        delay: 50
                    }))
                }), p.tabs()) : (p.remove(), e(".info-title").html(`<h3>${o[0].title}</h3>`), d.append('<div id="content-tab"></div>'), d.html(o[0].content)), i && (d.removeClass(), d.addClass(i)), c.css("background-color", d.css("background-color")), s && "function" == typeof s && (u.ready = s), c.openRightDrawer(u), a.f(a.b.WINDOW, a.a.Window.DRAWER_OPENED), e(".close-drawer").click(l), 1 === o.length ? e(".canvas-help-show").css("padding-top", "50px") : e("#tab-link-0").click()
            },
            l = () => {
                e("#right-drawer").closeRightDrawer(u), u.ready = null
            },
            u = {
                dismissible: !0,
                opacity: .7,
                in_duration: 400,
                out_duration: 400,
                complete: () => {
                    a.f(a.b.WINDOW, a.a.Window.DRAWER_CLOSED), e("#right-drawer-container").empty()
                }
            }
    }).call(this, n(8), n(16))
}, , function(e, t, n) {
    "use strict";
    n.d(t, "a", function() {
        return s
    }), n.d(t, "b", function() {
        return d
    });
    var o = n(1),
        a = n(3),
        i = n(7);
    const s = {
            UPDATE: "update-robot",
            SLEEP: "sleep-robot",
            DISCONNECT: "disconnect-robot",
            VOLUME: "robot-volume"
        },
        r = {
            [i.d.SPHERO.type]: [s.UPDATE, s.SLEEP, s.DISCONNECT],
            [i.d.OLLIE.type]: [s.UPDATE, s.SLEEP, s.DISCONNECT],
            [i.d.BB8.type]: [s.UPDATE, s.SLEEP, s.DISCONNECT],
            [i.d.SPRK2.type]: [s.UPDATE, s.SLEEP, s.DISCONNECT],
            [i.d.R2D2.type]: [s.VOLUME, s.UPDATE, s.SLEEP, s.DISCONNECT],
            [i.d.R2Q5.type]: [s.VOLUME, s.UPDATE, s.SLEEP, s.DISCONNECT],
            [i.d.BB9E.type]: [s.UPDATE, s.SLEEP, s.DISCONNECT],
            [i.d.MINI.type]: [s.UPDATE, s.SLEEP, s.DISCONNECT],
            [i.d.BOLT.type]: [s.UPDATE, s.SLEEP, s.DISCONNECT]
        },
        c = {
            [s.UPDATE]: e => (() => {
                let e = "";
                const t = a.getRobotVersions();
                return e = t.secondary ? Object(o.a)("forceFirmwareUpdateButtonHelp", [t.primary, t.secondary]) : Object(o.a)("forceFirmwareUpdateButtonHelpSingleVersion", t.primary), {
                    id: s.UPDATE,
                    title: Object(o.a)("forceFirmwareUpdateButtonText"),
                    body: e
                }
            })(),
            [s.SLEEP]: e => ({
                id: s.SLEEP,
                title: Object(o.a)("deepSleepRobotButtonText"),
                body: Object(o.a)("deepSleepRobotButtonHelp")
            }),
            [s.DISCONNECT]: e => ({
                id: s.DISCONNECT,
                title: Object(o.a)("disconnectRobotButtonText"),
                body: Object(o.a)("disconnectRobotButtonHelp")
            }),
            [s.VOLUME]: () => (() => {
                const e = a.getRobotType();
                return {
                    id: s.VOLUME,
                    title: Object(o.a)("r2VolumeSliderText", e.displayName),
                    body: '<div id="low" class="volume"/><div id="robot-volume-range" /><div id="high" class="volume"/>'
                }
            })()
        },
        d = e => {
            const t = a.getRobotType().type,
                n = [];
            return r[t].forEach(t => {
                const o = c[t](e[t]);
                o.callback = e[t], n.push(o)
            }), n
        }
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return d
        }), n.d(t, "b", function() {
            return l
        });
        var o = n(1),
            a = n(4),
            i = n(6),
            s = n(5),
            r = n(3);
        const c = {
                ANDROID: {
                    id: "ANDROID",
                    url: "https://play.google.com/store/apps/details?id=com.sphero.sprk&hl=en",
                    img: n(186)
                },
                IOS: {
                    id: "IOS",
                    url: "https://itunes.apple.com/us/app/sphero-sprk/id1017847674?mt=8",
                    img: n(185)
                },
                KINDLE: {
                    id: "KINDLE",
                    url: "https://www.amazon.com/gp/product/B018WUVNUK",
                    img: n(184)
                },
                MAC: {
                    id: "MAC",
                    url: "https://itunes.apple.com/app/id1349872101",
                    img: n(183)
                },
                WINDOWS: {
                    id: "WINDOWS",
                    url: "https://www.microsoft.com/store/apps/9N2796R62XLZ",
                    img: n(182)
                }
            },
            d = () => {
                Object(r.isRobotSupported)() || !p() && !b() || l(!0)
            },
            l = t => {
                let n, r, d, l, m;
                p() ? (n = Object(o.a)("newAppAvailableTitle"), r = Object(o.a)("newAppAvailableBodyMac"), d = u(c.MAC), l = "new-app-available", m = "New App Available (Mac)") : b() ? (n = Object(o.a)("newAppAvailableTitle"), r = Object(o.a)("newAppAvailableBodyWin"), d = u(c.WINDOWS), l = "new-app-available", m = "New App Available (Windows)") : (n = Object(o.a)("deviceNotSupportedTitle"), r = Object(o.a)("deviceNotSupportedBody"), d = `<p>${u(c.MAC)}${u(c.WINDOWS)}</p>\n            <p>${u(c.ANDROID)}${u(c.IOS)}${u(c.KINDLE)}</p>`, l = "unsupported-os", m = "Unsupported OS");
                const f = {
                    title: n,
                    body: r,
                    isDismissible: !0,
                    onCancel: s.a.closeCustomModal
                };
                s.a.openCustomModal(f, {
                    applyBeforeOpen: () => {
                        const t = e("#custom-modal");
                        t.addClass(l), t.find(".modal-title").before('<div class="close-button"></div>'), t.find(".modal-footer").html(d), t.find(".close-button").on("click", () => s.a.closeCustomModal()), t.find(".app-link").on("click", e => Object(i.i)(c[e.currentTarget.id].url))
                    }
                }), t || a.a.sendSiteEvent(m)
            },
            u = e => e === c.WINDOWS ? "" : `<a href="#" class="app-link" id="${e.id}"><img src="${e.img}" /></a>`,
            p = () => Object(i.f)().platform === i.a.PLATFORM.MAC_OS && Object(i.f)().packager === i.a.PACKAGER.CHROME,
            b = () => !1
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "c", function() {
            return T
        }), n.d(t, "b", function() {
            return k
        }), n.d(t, "a", function() {
            return x
        });
        var o = n(0),
            a = n(1),
            i = n(7),
            s = n(3),
            r = n(39),
            c = n(12),
            d = n(171),
            l = n(28),
            u = n(20),
            p = n(29),
            b = n(27),
            m = n(170),
            f = n(5),
            v = n(4),
            O = n(25);
        let h = !1,
            g = !1,
            y = !1,
            E = null;
        const T = () => {
                c.f();
                const e = (e, t) => o.e(o.b.ROBOT, e, t);
                e(o.a.Robot.STATE.CONNECTED, R), e(o.a.Robot.STATE.DISCONNECTED, S), e(o.a.Robot.STATE.CONNECT_FAILED, e => D(e.payload)), e(o.a.Robot.FIRMWARE_UPDATE.STARTED, C), e(o.a.Robot.FIRMWARE_UPDATE.PROGRESS, e => b.d(e.payload)), e(o.a.Robot.FIRMWARE_UPDATE.FAILED, e => A(e.payload)), e(o.a.Robot.FIRMWARE_UPDATE.SUCCEEDED, b.b), e(o.a.Robot.COMMAND.DRIVE, e => N(e)), e(o.a.Robot.COMMAND.AIM, e => N(e)), e(o.a.Robot.DISCOVERY.TOGGLE_CONNECTION, M), e(o.a.Robot.COMMAND.STOP_ANIMATION, w), e(o.a.Robot.DISCOVERY.DISCOVERED, e => U(e.payload)), e(o.a.Robot.DISCOVERY.PAIRED_CLASSIC_ROBOTS_LIST, e => V(e.payload)), e(o.a.Robot.MATRIX.SAVING_STARTED, e => W(e.payload)), e(o.a.WILDCARD, I), o.e(o.b.WINDOW, o.a.Window.DRIVE_CLOSED, j)
            },
            R = () => {
                u.d() ? u.c(L) : L(), v.a.sendRobotEvent("Connection", "Success")
            },
            S = () => {
                c.d(!0), h && r.a(), E = "toastRobotDisconnected", v.a.sendRobotEvent("Disconnect")
            },
            D = e => {
                let t, n;
                switch ((e = e || {}).code) {
                    case s.RobotErrorCode.NO_BLUETOOTH:
                        n = Object(a.a)("connectionFailureNoBluetoothTitle"), t = "No Bluetooth";
                        break;
                    case s.RobotErrorCode.NO_BLE:
                        n = Object(a.a)("connectionFailureNoBluetoothTitle"), t = "No BLE";
                        break;
                    case s.RobotErrorCode.BLUETOOTH_DISABLED:
                        n = Object(a.a)("connectionFailureBluetoothDisabledTitle"), t = "Bluetooth Disabled";
                        break;
                    case s.RobotErrorCode.V2_FIRMWARE_OUTDATED:
                        n = Object(a.a)("v2RobotFirmwareUpdateRequiredTitle"), t = "V2 Firmware Outdated";
                        break;
                    default:
                        u.b(e), t = e.message ? e.message : "Other"
                }
                n && (s.setUserPreviousRobotType(i.d.NONE), u.a(), f.a.openErrorModal({
                    title: n,
                    body: e.message
                }), c.e()), v.a.sendRobotEvent("Connection", "Failed", t)
            },
            C = () => {
                u.c(), b.c()
            },
            A = e => {
                e.code === s.RobotErrorCode.V2_FIRMWARE_OUTDATED ? (f.a.openErrorModal({
                    title: Object(a.a)("v2RobotFirmwareUpdateForcedTitle"),
                    body: e.message
                }), c.e()) : (b.a(e), c.d())
            },
            N = e => {
                h = !0, s.isRobotSupported() ? (g = e.payload, y = "aim" === e.action, P(g, y)) : Object(O.b)()
            },
            j = () => {
                h = !1, y = !1, s.isRobotConnected() ? c.c() : c.d()
            },
            M = () => {
                s.isRobotSupported() ? B() : Object(O.b)()
            },
            w = () => {
                s.turnOnLights()
            },
            I = () => {
                if (E) {
                    const e = Object(a.a)(s.getRobotType().name);
                    Materialize.toast(Object(a.a)(E, [e]), 2e3), E = null
                }
            },
            k = () => {
                c.e(!0)
            },
            x = () => {
                c.b(!0)
            },
            L = () => {
                h ? P(g, y) : c.c()
            },
            _ = (e = s.RobotType.NONE) => {
                e !== s.RobotType.SPHERO || s.usePairedClassicList() ? e !== s.RobotType.NONE ? (l.d(e, t => ((e, t) => {
                    null !== t ? u.e(e, t.name, _.bind(null, e)) : (h = !1, c.e())
                })(e, t), (e => {
                    const t = Object(a.a)(`help${i.a[e.type]}`, Object(a.a)(e.name));
                    p.a(Object(a.a)("cantConnect"), t, e, _.bind(null, e), $)
                }).bind(null, e), $), s.setUserPreviousRobotType(e)) : (h = !1, c.e()) : (u.e(e, null, $), s.setUserPreviousRobotType(e))
            },
            P = (t, n) => {
                s.isRobotConnected() ? (s.stopProgram(), r.b(t, n), e("#robot-status-container").addClass("closed")) : B()
            },
            B = () => {
                const e = s.getUserPreviousRobotType();
                e && e.type !== s.RobotType.NONE.type ? (c.b(), _(e)) : $()
            },
            $ = () => {
                c.b(), d.a(_)
            },
            U = e => {
                l.a(e)
            },
            V = e => {
                (e = Array.isArray(e) ? e : []).length ? l.b(e.map(e => ({
                    name: e
                }))) : l.c()
            },
            W = e => {
                m.a(e)
            }
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "c", function() {
            return c
        }), n.d(t, "d", function() {
            return l
        }), n.d(t, "a", function() {
            return u
        }), n.d(t, "b", function() {
            return p
        });
        var o = n(1),
            a = n(4),
            i = n(34),
            s = n(5);
        let r = null;
        const c = () => {
                const t = {
                    title: Object(o.a)("firmwareUpdateScreenTitle"),
                    body: n(190),
                    isDismissible: !1
                };
                s.a.openCustomModal(t, {
                    callback: b,
                    applyBeforeOpen: () => {
                        const t = e("#custom-modal");
                        t.addClass("firmware-update"), t.find(".modal-footer").html('<div class="firmware-warning"></div><div class="firmware-info-header"></div><div class="firmware-info-text"></div>'), t.find(".firmware-info-header").html(Object(o.a)("robotUpdateScreenTipsHeader")), t.find(".firmware-warning").html(Object(o.a)("firmwareUpdateWarning")), d(i.a(!0)), r = setInterval(() => {
                            d(i.a())
                        }, 1e4), l(0)
                    }
                })
            },
            d = t => {
                e("#custom-modal").find(".firmware-info-text").html(t)
            },
            l = (t = 0) => {
                const n = e("#loading-progress-meter"),
                    o = n.find(".background-img").height();
                n.find(".progress-img").height(o * (100 - t) / 100), n.find(".progress-info-text").html(`${t}%`)
            },
            u = e => {
                a.a.sendRobotEvent("Firmware", "Failure"), b(e)
            },
            p = () => {
                a.a.sendRobotEvent("Firmware", "Success"), b()
            },
            b = e => {
                r && (clearInterval(r), r = null), s.a.closeCustomModal(() => m(e))
            },
            m = e => {
                e && s.a.openErrorModal({
                    title: Object(o.a)("defaultErrorTitle"),
                    body: e.message
                })
            }
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    (function(e, o) {
        n.d(t, "d", function() {
            return y
        }), n.d(t, "a", function() {
            return N
        }), n.d(t, "b", function() {
            return j
        }), n.d(t, "c", function() {
            return M
        });
        var a = n(1),
            i = n(7),
            s = n(4),
            r = n(5),
            c = n(3),
            d = n(9),
            l = n(15);
        let u = {},
            p = [],
            b = i.d.NONE,
            m = null,
            f = null,
            v = !1,
            O = [0, 0, 0, 0];
        const h = ["full", "strong", "medium", "weak"],
            g = () => {
                if (p.length) return p.reduce((e, t) => {
                    const n = u[t];
                    return e.concat(`<div class="robot-selection-button" data-name="${n.name}">\n                <div id="${b.type}" class="robot-icon ${b.type}"></div>\n                <div class="robot-label">${n.name}</div>\n                <div class="signal-strength ${(e=>{if(!e&&0!=e)return"hidden";const t=O.findIndex(t=>Number(e)>Number(t));return t>-1?h[t]:"none"})(n.rssi)}"></div>\n            </div>`)
                }, "");
                if (v && b.type === i.d.SPHERO.type) {
                    const e = [];
                    return e.push(`<div>${Object(a.a)("noPairedRobots")}</div>`), e.push(`<div>${Object(a.a)("connectionFailureClassic")}</div>`), `<div id="no-robots">${e.join("<br>")}</div>`
                }
                return `<div id="no-robots"><div id="searching-spinner"></div><div>${Object(a.a)("lookingForRobots")}</div></div>`
            },
            y = (t, n, o, i) => {
                const l = {
                    title: Object(a.a)("chooseYourRobot"),
                    body: '<div id="robot-buttons"></div>',
                    isDismissible: !0,
                    onCancel: () => {
                        r.a.closeCustomModal(() => E(n))
                    }
                };
                u = {}, p = [], b = t, v = !1, O = c.getSignalStrengthThresholds(b), m = n, f = t.type === c.RobotType.SPHERO.type ? null : setTimeout(T, 1e3), r.a.openCustomModal(l, {
                    callback: () => E(n),
                    applyBeforeOpen: () => {
                        const t = e("#custom-modal");
                        t.addClass("robot-name-selection");
                        const n = t.find(".modal-footer");
                        n.html(`<div class="cant-connect">\n                ${d.f("help-button",Object(a.a)("cantConnect"),["modal-action","submit","filled"])}\n            </div>`), n.find("#help-button").on("click", () => {
                            r.a.closeCustomModal(() => E(o))
                        }), t.find(".modal-content").append('<div class="back-button" />'), t.find(".back-button").on("click", () => {
                            r.a.closeCustomModal(() => E(i))
                        }), R(), s.a.sendSiteEvent("Robot Select Name")
                    }
                }), t.type === c.RobotType.SPHERO.type && c.usePairedClassicList() ? c.getPairedClassicRobots() : c.startDiscovery(t)
            },
            E = (t, n = null) => {
                n || c.stopDiscovery(), A();
                const o = e("#custom-modal");
                o.find(".robot-selection-button").off("click"), o.find(".close-modal").off("click"), s.a.sendRobotEvent("Selected", n ? n.name : "none"), t && t(n)
            },
            T = () => {
                A(), (p = Object.keys(u)).sort((e, t) => u[t].rssi - u[e].rssi), R()
            },
            R = () => {
                const t = e("#robot-buttons");
                let n = t.find(".robot-selection-button");
                n.off(), l.b("#searching-spinner"), t.empty(), t.html(g()), p.length ? (e(".modal-body").removeClass("no-robots"), (n = t.find(".robot-selection-button")).on("click", e => {
                    const t = e.currentTarget.dataset.name;
                    r.a.closeCustomModal(() => E(m, u[t]))
                })) : (e(".modal-body").addClass("no-robots"), l.a("#searching-spinner", "black"))
            },
            S = o.throttle(R, 500, {
                leading: !0
            }),
            D = (e, t) => Math.round(.7 * e.rssi + (1 - .7) * t.rssi),
            C = e => !!(e => {
                if (!u[e.name]) return !0;
                const t = u[e.name];
                return D(t, e) !== t.rssi
            })(e) && (u[e.name] ? u[e.name].rssi = D(u[e.name], e) : (f || p.push(e.name), u[e.name] = e), !0),
            A = () => {
                f && (clearTimeout(f), f = null)
            },
            N = e => {
                C(e) && S()
            },
            j = e => {
                e.forEach(e => C(e)), R()
            },
            M = () => {
                v = !0, S()
            }
    }).call(this, n(8), n(16))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return r
        });
        var o = n(1),
            a = n(5),
            i = n(12),
            s = n(6);
        const r = (t, n, r, d, l) => {
                const u = {
                    title: t,
                    body: n,
                    isDismissible: !0,
                    onCancel: c
                };
                a.a.openCustomModal(u, {
                    callback: i.a,
                    applyBeforeOpen: () => {
                        const t = e("#custom-modal");
                        t.addClass("robot-connection robot-help-modal"), t.find(".modal-footer").html(`<div class="${r.type} connection-help-icon"/>`), t.find(".modal-footer").append(`<div class="button-container">\n            <div class="retry-connection"><button href="#" class="sprk-button empty" id="retry-connection">${Object(o.a)("retryButtonText")}</button></div>\n            <div class="retry-connection"><button href="#" class="sprk-button empty" id="other-robot">${Object(o.a)("chooseOtherRobot")}</button></div>\n        </div>`), t.find(".modal-footer").append(`<div class="learn-more"><a href="#" id="learn-more">${Object(o.a)("learnMore")}</a></div>`), t.find("#retry-connection").on("click", () => a.a.closeCustomModal(d)), t.find("#other-robot").on("click", () => a.a.closeCustomModal(l)), t.find("#learn-more").on("click", () => Object(s.i)("https://support.sphero.com"))
                    }
                })
            },
            c = () => {
                a.a.closeCustomModal(i.a)
            }
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "b", function() {
            return h
        }), n.d(t, "a", function() {
            return g
        });
        var o = n(10),
            a = n(14),
            i = n(4),
            s = n(9),
            r = n(176),
            c = n(11),
            d = n(0),
            l = n(3),
            u = n(174),
            p = n(26),
            b = n(7),
            m = n(22),
            f = n(6);
        const v = {};
        let O = "";
        const h = () => {
                const t = e("#site-webview"),
                    n = e("#site-container"),
                    u = t.getDOMObject();
                R(), Object(o.k)(u, () => {
                    Object(a.c)().then(e => {
                        v.userId = e, Object(c.e)(), C()
                    }).catch(() => {}), t.trigger("launch"), Object(a.b)(), Object(a.a)(), D(), _(l.getRobotType())
                }), t.on("launch", S), t.getDOMObject().src || Object(r.a)(), t.on("dialog", e => {
                    e.originalMessage.preventDefault()
                }), Object(o.g)(u, () => {
                    i.a.sendSiteEvent("Fullscreen"), n.addClass("fullscreen")
                }), Object(o.j)(u, () => {
                    n.removeClass("fullscreen")
                }), Object(o.n)(u, (e, t) => {
                    "clever.com" === t.host && "https://clever.com" === t.origin && "/in/redirector" === t.pathname ? u.src = t : Object(f.i)(t)
                }), Object(o.o)(u, {
                    urls: ["<all_urls>"]
                }, () => {
                    const e = t.attr("src");
                    O !== e && (O = e, i.a.sendScreenView(e))
                }, ["requestHeaders"]), Object(o.d)(u, {
                    urls: ["*://www.sphero.com/education", "*://store.sphero.com/", "*://sphero.com/", "*://twitter.com/*"]
                }, e => {
                    const t = new RegExp(/^https?:\/\/twitter.com\//);
                    if (!e.url.match(t)) {
                        const t = new URL(e.url);
                        return i.a.sendSiteEvent("Internal Link", t.hostname), Object(f.i)(e.url), {
                            cancel: !0
                        }
                    } {
                        const t = new RegExp(/^https?:\/\/twitter.com\/i\//);
                        if (!e.url.match(t)) {
                            const t = new URL(e.url);
                            return i.a.sendSiteEvent("External Link", t.hostname), Object(f.i)(e.url), {
                                cancel: !0
                            }
                        }
                    }
                    return {
                        cancel: !1
                    }
                }, ["blocking"]), Object(o.h)(u, () => !0), Object(f.c)(() => {
                    d.f(d.b.WINDOW, d.a.Window.RESIZE)
                }), Object(o.f)(u), Object(o.m)(u), Object(o.e)(u, {
                    urls: ["https://edu.sphero.com/chrome-app/*"]
                }, e => {
                    const t = new URL(e.url),
                        n = t.pathname.split("/").slice(2);
                    switch (n[0]) {
                        case "aim":
                            d.f(d.b.ROBOT, d.a.Robot.COMMAND.AIM);
                            break;
                        case "drive":
                            d.f(d.b.ROBOT, d.a.Robot.COMMAND.DRIVE);
                            break;
                        case "editor":
                            A(n);
                            break;
                        case "program":
                            N(n, t.searchParams);
                            break;
                        case "led":
                            I(n, t.searchParams);
                            break;
                        case "sound":
                            k(n, t.searchParams);
                            break;
                        case "robot_sound":
                            x(n, t.searchParams);
                            break;
                        case "robot_animation":
                            L(n, t.searchParams);
                            break;
                        case "analytics":
                            P(n, t.searchParams);
                            break;
                        case "home":
                            u.src = "https://edu.sphero.com/";
                            break;
                        case "login-failed":
                            i.a.sendAccountEvent("Login", "Failed"), v.userId = "-1";
                            break;
                        case "login":
                            i.a.sendAccountEvent("Login", "Success"), v.userId = n[1], d.f(d.b.APP, d.a.App.LOGIN, v);
                            break;
                        case "logout":
                            i.a.sendAccountEvent("Log Out"), v.userId = "-1", d.f(d.b.APP, d.a.App.LOGOUT), Object(o.a)(u);
                            break;
                        case "forgot-password":
                            i.a.sendAccountEvent("Forgot Password");
                            break;
                        case "signup":
                            i.a.sendAccountEvent("Sign Up", "Navigate");
                            break;
                        case "registered":
                            i.a.sendAccountEvent("Sign Up", "Successful");
                            break;
                        default:
                            console.warn("Unhandled request to ", n[0])
                    }
                    return {
                        cancel: !0
                    }
                }, ["blocking"]), d.e("debug", "debug", e => {
                    Object(s.a)(e)
                });
                const p = (e, t) => d.e(d.b.APP, e, t),
                    b = (e, t) => d.e(d.b.ROBOT, e, t);
                p(d.a.App.USER_AGENT_OVERRIDE_FAILED, () => R()), p(d.a.App.OPEN_URL, e => Object(f.i)(e.payload)), p(d.a.App.SITE_RELOAD, () => y()), p(d.a.App.SITE_GO_BACK, () => E()), p(d.a.App.SHOW_PREFERENCES, () => T()), b(d.a.Robot.STATE.DISCONNECTED, () => _()), b(d.a.Robot.STATE.CONNECTED, e => _(e.payload)), b(d.a.Robot.PROGRAM.SEND_FAILED, e => M(e)), b(d.a.Robot.PROGRAM.ERROR, e => w(e.payload)), b(d.a.Robot.PROGRAM.STARTING, () => Object(a.f)("starting")), b(d.a.Robot.PROGRAM.STARTED, () => j()), b(d.a.Robot.PROGRAM.STOPPED, () => Object(a.f)("stopped")), b(d.a.Robot.MATRIX.SAVING_COMPLETE, e => Object(a.d)(e.payload))
            },
            g = (t, n) => {
                const a = e("#site-webview").getDOMObject();
                Object(o.i)(a, t, () => {
                    Object(o.k)(a, n), Object(o.l)(a, n)
                })
            },
            y = () => {
                i.a.sendSiteEvent("Refresh"), e("#site-webview").getDOMObject().reload()
            },
            E = () => {
                i.a.sendSiteEvent("Back"), Object(o.c)(e("#site-webview").getDOMObject())
            },
            T = () => {
                e(".modal-overlay").getDOMObject() || (i.a.sendSiteEvent("Open Preferences"), l.stopProgram(), u.a())
            },
            R = () => {
                Object(o.p)(e("#site-webview").getDOMObject(), "SPRKApp/5.0")
            },
            S = () => {
                Object(c.d)().then(e => {
                    e.launchCount = e.launchCount + 1, Object(c.h)(e)
                }).then(() => {
                    e("#site-webview").off("launch", S)
                }).catch(e => {
                    Object(s.a)(e)
                })
            },
            D = () => {
                Object(c.b)(e => {
                    !e || e.storageMigrated || e.firstText || Object(c.d)().then(t => {
                        e.firstText = t.firstText, e.storageMigrated = !0, Object(c.g)(e)
                    }).catch(() => {})
                })
            },
            C = () => {
                Object(c.b)(e => {
                    e && Object(l.applyUserRobotSettings)(e.robotSettings)
                })
            },
            A = e => {
                switch (e[1]) {
                    case "enter":
                        i.a.sendCanvasEvent("Load Program"), i.a.timer.setTimer(i.a.timers.TIME_IN_CANVAS), d.f(d.b.APP, d.a.App.NAVIGATION_STATE, !1), Object(p.a)();
                        break;
                    case "exit":
                        i.a.timer.completeTimer(i.a.timers.TIME_IN_CANVAS, "Total Time"), d.f(d.b.APP, d.a.App.NAVIGATION_STATE, !0), Object(p.b)();
                        break;
                    default:
                        Object(s.a)(`Unexpected canvas request: ${e[1]}`)
                }
            },
            N = (e, t) => {
                const n = e[1];
                switch (e[2]) {
                    case "sensordata":
                        i.a.sendCanvasEvent("Sensor Data"), Object(m.b)(n);
                        break;
                    case "start":
                        i.a.sendProgramEvent("Run"), l.runProgram(t.get("code"), n);
                        break;
                    case "stop":
                        l.stopProgram();
                        break;
                    default:
                        Object(s.a)(`Unexpected program request: ${e[2]}`)
                }
            },
            j = () => {
                i.a.sendProgramEvent("Send", "Success"), Object(a.f)("started")
            },
            M = e => {
                Object(a.f)("stopped"), i.a.sendProgramEvent("Send", "Failed"), e.payload.code === b.c.NO_ROBOT ? d.f(d.b.ROBOT, d.a.Robot.DISCOVERY.TOGGLE_CONNECTION) : Object(a.g)(e.payload)
            },
            w = e => {
                i.a.sendProgramEvent("Runtime", "Failed"), Object(a.g)(e)
            },
            I = (e, t) => {
                switch (e[1]) {
                    case "on":
                        l.turnOnLights();
                        break;
                    case "off":
                        l.turnOffLights();
                        break;
                    case "set":
                        try {
                            const e = t.get("led"),
                                n = JSON.parse(t.get("value"));
                            switch (e) {
                                case "MAIN":
                                    l.setRobotColor(n.r, n.g, n.b);
                                    break;
                                case "FRONT":
                                    l.setFrontLED(n.r, n.g, n.b);
                                    break;
                                case "BACK":
                                    "number" == typeof n ? l.setBackLEDBrightness(n) : l.setBackLED(n.r, n.g, n.b);
                                    break;
                                case "DOME":
                                    l.setHeadLED(n);
                                    break;
                                case "HOLO_PROJECTOR":
                                    l.setHoloProjector(n);
                                    break;
                                case "LOGIC_DISPLAY":
                                    l.setLogicDisplay(n)
                            }
                        } catch (e) {
                            Object(s.a)(`Failed to parse LED request: ${t.toString()}`)
                        }
                        break;
                    default:
                        Object(s.a)(`Unexpected LED request: ${e[1]}`)
                }
            },
            k = (e, t) => {
                switch (e[1]) {
                    case "play":
                        d.f(d.b.SOUND, d.a.Sound.PLAY_EFFECT, {
                            asset: t.get("asset"),
                            interrupt: !0
                        });
                        break;
                    case "stop":
                        d.f(d.b.SOUND, d.a.Sound.STOP);
                        break;
                    default:
                        Object(s.a)(`Unexpected robot sound request: ${e[1]}`)
                }
            },
            x = (e, t) => {
                switch (e[1]) {
                    case "play":
                        l.playSound(t.get("asset"), !0);
                        break;
                    case "stop":
                        l.stopSound();
                        break;
                    default:
                        Object(s.a)(`Unexpected robot sound request: ${e[1]}`)
                }
            },
            L = (e, t) => {
                switch (e[1]) {
                    case "play":
                        l.playAnimation(t.get("asset"));
                        break;
                    case "stop":
                        l.stopAnimation();
                        break;
                    default:
                        Object(s.a)(`Unexpected robot animation request: ${e[1]}`)
                }
            },
            _ = e => {
                Object(a.e)({
                    id: e ? e.id : l.RobotType.NONE.id
                })
            },
            P = (e, t) => {
                try {
                    const e = t.get("event");
                    let n = t.get("properties");
                    n && "undefined" !== n && (n = JSON.parse(n), n = Object.keys(n).map(e => `${e}: ${n[e]}`).join(", ")), i.a.sendCanvasEvent(e, n)
                } catch (e) {
                    Object(s.a)(`Failed to parse analytics request: ${t}`)
                }
            }
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return c
        }), n.d(t, "b", function() {
            return d
        });
        var o = n(1);
        let a = !1,
            i = 0,
            s = -1,
            r = null;
        const c = (t, n, s) => {
                if (i = t ? n : 0, a !== t) {
                    a = t;
                    const n = e("#aiming-circle"),
                        i = e("#custom-modal.driving-modal");
                    e(`#color-picker-div, #aiming-help-wrapper, #aiming-help-wrapper, ${s?"#joystick-pip":".key-container"}, #speed-slider-wrapper`).toggleClass("hidden"), e("#color-wheel-wrapper, #robot-display-wrapper").toggle(), i.find(".component-wrapper").toggleClass("hidden"), i.find("span.sprk-title").text(Object(o.a)(t ? "aim" : "drive")), t ? (n.css("visibility", "visible"), p(), u(), l()) : (n.css("visibility", "hidden"), u(), e(".key-container, #speed-slider-wrapper").removeClass("grayscaled"))
                }
            },
            d = () => {
                u(), a = !1
            },
            l = () => {
                r = setInterval(() => {
                    if (Math.abs(i) > .001) {
                        for (s += i; s < 0;) s += 360;
                        for (; s >= 360;) s -= 360;
                        p()
                    }
                }, 1e3 / 30)
            },
            u = () => {
                r && (clearInterval(r), r = null)
            },
            p = () => {
                const t = `rotate(${s}deg)`;
                e("#aiming-circle").css({
                    "-webkit-transform": t,
                    "-moz-transform": t,
                    "-o-transform": t,
                    "-ms-transform": t,
                    transform: t
                })
            }
    }).call(this, n(8))
}, , function(e, t) {
    e.exports = require("fs")
}, function(e, t, n) {
    "use strict";
    n.d(t, "a", function() {
        return i
    });
    n(9);
    var o = n(1);
    let a = 0;
    const i = e => {
        e && (a = 0);
        return ++a > 6 && (a = 1), Object(o.a)(`updateTip${a}`)
    }
}, , function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return l
        });
        var o = n(18),
            a = n.n(o),
            i = n(35),
            s = n.n(i),
            r = n(9),
            c = n(1);
        class d {
            constructor() {
                this.defaultExtents = {
                    gyro: {
                        yMin: 0,
                        yMax: 100
                    },
                    accel: {
                        yMin: 0,
                        yMax: 5
                    },
                    vel: {
                        yMin: 0,
                        yMax: 20
                    },
                    dist: {
                        yMin: 0,
                        yMax: 200
                    },
                    att: {
                        yMin: 0,
                        yMax: 0
                    },
                    loc: {
                        yMin: -5,
                        yMax: 5,
                        xMin: -5,
                        xMax: 5
                    },
                    padding: .05
                }
            }
        }
        class l extends d {
            constructor(e, t = (() => {})) {
                super(), s.a.addGraph(() => (this.chart = s.a.models.lineChart(), this.chart.dispatch.on("renderEnd", t), this.chart), e)
            }
            generateChart(t, n, o, i, s, r, d, l) {
                let u;
                o && n[0].values[n[0].values.length - 1].x > 10 ? this.chart.brushExtent([0, 10]) : this.chart.brushExtent([0, 0]), this.chart.xAxis.tickFormat(a.a.format(r)).axisLabel(s), this.chart.yAxis.tickFormat(a.a.format(l)).axisLabel(d), this.chart.x2Axis.tickFormat(a.a.format(r)), this.chart.y2Axis.tickFormat(a.a.format(l)), this.chart.rightAlignYAxis(Object(c.b)()), i ? (u = this.calculateLocCorners(n, i()), n = this.generateFakeLocData(n, u)) : u = this.calculateCorners(n, t), this.chart.forceY([u.yMin, u.yMax]), this.chart.focus.forceY([u.yMin, u.yMax]), this.chart.useInteractiveGuideline(o), this.chart.showLegend(!1), this.chart.interactive(!1), this.chart.margin({
                    bottom: o ? 30 : 40
                }), this.chart.focusEnable(o), a.a.select(`#${t} svg`).datum(n).transition().duration(500).call(this.chart), this.seriesKeys = e.map(n, e => e.key)
            }
            redraw() {
                this.chart.update()
            }
            getHtml(e) {
                return `<div id=${e} class="data-vis-chart"><svg></svg></div>`
            }
            getButtonHtml(t) {
                return `<div class="chart-buttons">${e.map(["total","x","y","z","pitch","roll","yaw"],n=>{const o=e.findIndex(t,{key:n});if(-1!==o){const e=t[o],a=this.chart.state.disabled[this.seriesKeys.indexOf(n)];return r.e(e.key,e.key,[`
                $ {
                    e.key
                }
                Data `,`
                $ {
                    a ? "off" : ""
                }
                `,"filled","data","data-button"],{dataSeries:e.key},!0)}}).join("")}</div>`
            }
            toggleSeries(t) {
                const n = e.cloneDeep(this.chart.state),
                    o = this.seriesKeys.indexOf(t);
                return n.disabled[o] = !n.disabled[o], -1 !== n.disabled.indexOf(!1) && (this.chart.dispatch.changeState(n), this.chart.update(), this.getDisabledState())
            }
            updateState(t) {
                const n = e.cloneDeep(this.chart.state);
                for (const e in t) {
                    const o = this.seriesKeys.indexOf(e);
                    n.disabled[o] = t[e]
                }
                return -1 !== n.disabled.indexOf(!1) && (this.chart.dispatch.changeState(n), this.chart.update(), this.getDisabledState())
            }
            getDisabledState() {
                const t = e.cloneDeep(this.chart.state);
                return this.seriesKeys.reduce((e, n, o) => "fakeData" === n ? e : (e[n] = t.disabled[o], e), {})
            }
            clear() {
                a.a.select("svg").selectAll("*").remove()
            }
            generateFakeLocData(e, t) {
                for (let t = 0; t < e.length; t++) {
                    if ("fakeData" === e[t].key) return e
                }
                const n = {
                    color: "000000",
                    key: "fakeData",
                    values: [{
                        series: e.length,
                        x: t.xMin,
                        y: t.yMin
                    }, {
                        series: e.length,
                        x: t.xMax,
                        y: t.yMin
                    }, {
                        series: e.length,
                        x: t.xMax,
                        y: t.yMax
                    }, {
                        series: e.length,
                        x: t.xMin,
                        y: t.yMax
                    }]
                };
                return e.push(n), e
            }
            calculateLocCorners(e, t) {
                const n = {
                        x: e[0].maxXValue,
                        y: e[0].maxYValue
                    },
                    o = {
                        x: e[0].minXValue,
                        y: e[0].minYValue
                    },
                    a = this.defaultExtents.padding,
                    i = n.x - o.x,
                    s = n.y - o.y;
                n.y = Math.ceil(n.y + (s * (1 + a) - s) / 2), o.y = Math.floor(o.y - (s * (1 + a) - s) / 2), n.x = Math.ceil(n.x + (i * (1 + a) - i) / 2), o.x = Math.floor(o.x - (i * (1 + a) - i) / 2);
                const r = this.defaultExtents.loc;
                o.x > r.xMin && o.y > r.yMin && n.x < r.xMax && n.y < r.yMax && (o.x = r.xMin, o.y = r.yMin, n.x = r.xMax, n.y = r.yMax);
                const c = n.x - o.x,
                    d = n.y - o.y,
                    l = (o.x, o.y + .5 * d),
                    u = c / t;
                if (c > d && u > d) return {
                    xMin: o.x,
                    yMin: l - u / 2,
                    xMax: n.x,
                    yMax: l + u / 2
                }; {
                    const e = d * t;
                    return {
                        xMin: o.x - e / 2,
                        yMin: o.y,
                        xMax: n.x + e / 2,
                        yMax: n.y
                    }
                }
            }
            calculateCorners(e, t) {
                const n = {
                        x: e[0].values[e[0].values.length - 1].x,
                        y: Number.NEGATIVE_INFINITY
                    },
                    o = {
                        x: 0,
                        y: Number.POSITIVE_INFINITY
                    };
                e.forEach(e => {
                    e.minYValue < o.y && (o.y = e.minYValue), e.maxYValue > n.y && (n.y = e.maxYValue)
                });
                const a = this.defaultExtents.padding;
                n.y = Math.ceil(n.y * (n.y > 0 ? 1 + a : 1 - a)), o.y = Math.floor(o.y * (o.y > 0 ? 1 - a : 1 + a));
                const i = this.defaultExtents[t],
                    s = i.yMax - i.yMin,
                    r = n.y - o.y;
                return r < s && o.y < 0 ? (o.y -= (s - r) / 2, n.y += (s - r) / 2) : n.y < i.yMax && 0 === o.y && (n.y = i.yMax), o.y > i.yMin && (o.y = i.yMin), n.y = Math.ceil(n.y), o.y = Math.floor(o.y), {
                    xMin: o.x,
                    yMin: o.y,
                    xMax: n.x,
                    yMax: n.y
                }
            }
            static hideTooltips() {
                a.a.selectAll(".nvtooltip").style("opacity", 0)
            }
        }
    }).call(this, n(16))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return u
        }), n.d(t, "b", function() {
            return p
        });
        var o = n(3),
            a = n(23),
            i = n(1);
        let s, r, c, d, l = !1;
        const u = t => {
                const n = e("#driving-colour-wheel"),
                    o = e("#picked-color-display"),
                    s = e("#selection-ring"),
                    r = t.a;
                d = document.getElementById("brightness-slider"), a.create(d, {
                    start: r,
                    connect: "lower",
                    step: 1,
                    tooltips: !1,
                    direction: Object(i.b)() ? "rtl" : "ltr",
                    range: {
                        min: 0,
                        max: 255
                    }
                }), d.noUiSlider.on("slide", e => {
                    D(e[0] / 255)
                }), n.mousemove(e => {
                    s.toggleClass("opaque", !0);
                    const t = {
                        X: e.pageX,
                        Y: e.pageY
                    };
                    m(e.currentTarget, t, !l)
                }), n.mouseleave(() => {
                    o.css("background-color", v(c)), s.toggleClass("opaque", !1)
                }), n.on("click", e => {
                    const t = {
                        X: e.pageX,
                        Y: e.pageY
                    };
                    m(e.currentTarget, t)
                }), n.on("mousedown", () => {
                    l = !0
                }), e(document).on("mouseup", b), n.on("touchmove", e => {
                    if (!e.touches && !e.touches.length) return;
                    const t = {
                        X: e.touches[0].pageX,
                        Y: e.touches[0].pageY
                    };
                    m(e.currentTarget, t)
                }), E(t)
            },
            p = () => {
                e(document).off("mouseup", b)
            },
            b = () => {
                l = !1
            },
            m = (t, n, o) => {
                if (s = O(t), r = t.clientWidth / 2, o) {
                    const t = y(s, n, r);
                    e("#picked-color-display").css("background-color", v(t))
                } else T(n, s, r) || (g(s, n, r), h(n))
            },
            f = (t, n = !0) => {
                c = t, n && d.noUiSlider.set(255 * t.a), e("#picked-color-display").css("background-color", v(t)), e("#driving-colour-wheel").css("opacity", t.a)
            },
            v = e => `${e?"rgb("+Math.floor(e.r*e.a)+","+Math.floor(e.g*e.a)+","+Math.floor(e.b*e.a)+")":"rgb(255,255,255)"}`,
            O = t => {
                let n = 0,
                    o = 0;
                if (t.offsetParent)
                    do {
                        n += t.offsetLeft, o += t.offsetTop, t = t.offsetParent
                    } while (t);
                return {
                    X: n,
                    Y: o - e("#custom-modal.driving-modal").height() / 2
                }
            },
            h = t => {
                const n = e("#selection-ring"),
                    o = e("#color-wheel-wrapper").offset(),
                    a = t.X - o.left - 20,
                    i = t.Y - o.top - 20;
                n.css({
                    top: i,
                    left: a,
                    height: "40px",
                    width: "40px"
                }), n.toggleClass("opaque", !1), n.show()
            },
            g = (e, t, n) => {
                c = y(e, t, n), f(c), o.setUserRobotColor(c)
            },
            y = (e, t, n) => {
                const o = t.X - e.X - n,
                    a = e.Y - t.Y + n,
                    i = Math.min(Math.hypot(o, a) / n, 1);
                let s = (Math.atan2(o, a) - Math.PI / 2) / (2 * Math.PI);
                s < 0 ? s *= -1 : s > 0 && (s = 1 - s);
                const r = R(s, i, 1);
                return r.a = d.noUiSlider.get() / 255, r
            },
            E = t => {
                f(t);
                const n = e("#driving-colour-wheel")[0];
                r = n.offsetWidth / 2, s = O(n);
                const o = S(t),
                    a = 2 * o.h * Math.PI + Math.PI / 2,
                    i = Math.round(o.s * r * Math.sin(a)),
                    c = Math.round(o.s * r * Math.cos(a)),
                    d = i + s.X + r,
                    l = c + s.Y + r;
                h({
                    X: d,
                    Y: l
                })
            },
            T = (e, t, n) => {
                const o = e.X - t.X - n,
                    a = t.Y - e.Y + n;
                return Math.sqrt(Math.pow(0 - o, 2) + Math.pow(0 - a, 2)) > n
            },
            R = (e, t, n) => {
                let o, a, i;
                const s = Math.floor(6 * e),
                    r = 6 * e - s,
                    c = n * (1 - t),
                    d = n * (1 - r * t),
                    l = n * (1 - (1 - r) * t);
                switch (s % 6) {
                    case 0:
                        o = n, a = l, i = c;
                        break;
                    case 1:
                        o = d, a = n, i = c;
                        break;
                    case 2:
                        o = c, a = n, i = l;
                        break;
                    case 3:
                        o = c, a = d, i = n;
                        break;
                    case 4:
                        o = l, a = c, i = n;
                        break;
                    case 5:
                        o = n, a = c, i = d
                }
                return {
                    r: Math.round(255 * o),
                    g: Math.round(255 * a),
                    b: Math.round(255 * i)
                }
            },
            S = e => {
                let t, n;
                const o = e.r,
                    a = e.g,
                    i = e.b,
                    s = Math.min(o, a, i),
                    r = Math.max(o, a, i),
                    c = r / 255,
                    d = r - s;
                return 0 === r ? {
                    h: -1,
                    s: 0,
                    v: c
                } : (t = o === r ? (a - i) / d : a === r ? 2 + (i - o) / d : 4 + (o - a) / d, (t *= 60) < 0 && (t += 360), {
                    h: t / 360,
                    s: n = d / r,
                    v: c
                })
            },
            D = e => {
                const t = {
                    r: c.r,
                    g: c.g,
                    b: c.b,
                    a: e
                };
                f(t, !1), o.setUserRobotColor(t)
            }
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return s
        }), n.d(t, "b", function() {
            return r
        });
        var o = n(19),
            a = n(23);
        let i = -1;
        const s = t => {
                const n = document.getElementById("speed-slider");
                a.create(n, {
                    start: t,
                    connect: "lower",
                    step: 1,
                    tooltips: !1,
                    orientation: "vertical",
                    direction: "rtl",
                    range: {
                        min: 0,
                        max: 255
                    }
                }), n.noUiSlider.on("change", () => {
                    const e = parseInt(n.noUiSlider.get());
                    o.a(e)
                }), e("#icon-slow").on("click", () => {
                    n.noUiSlider.set(0), o.a(0)
                }), e("#icon-fast").on("click", () => {
                    n.noUiSlider.set(255), o.a(255)
                })
            },
            r = e => {
                if (e === i) return;
                document.getElementById("speed-slider").noUiSlider.set(e), i = e
            }
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    (function(e, o) {
        n.d(t, "b", function() {
            return g
        }), n.d(t, "a", function() {
            return y
        });
        var a = n(0),
            i = n(1),
            s = n(4),
            r = n(3),
            c = n(7),
            d = n(11),
            l = n(5),
            u = n(19),
            p = n(38),
            b = n(31),
            m = n(37),
            f = n(9);
        let v = !1,
            O = !1;
        const h = {
                "#drive-forward": 87,
                "#drive-backward": 83,
                "#drive-left": 65,
                "#drive-right": 68,
                "#aim-left": 37,
                "#aim-right": 39,
                "#speed-up": 38,
                "#speed-down": 40
            },
            g = o.debounce((t, o) => {
                const a = c.e.includes(r.getRobotType().type);
                if (v = o, O = r.getUserJoytickSetting(), s.a.sendSiteEvent("Drive"), e(".modal-overlay").getDOMObject()) return;
                const d = {
                    content: n(199),
                    isDismissible: !0,
                    onCancel: () => y
                };
                l.a.openCustomModal(d, {
                    callback: T,
                    applyBeforeOpen: () => {
                        const t = r.getRobotType();
                        a ? (e("#color-wheel-wrapper, .component-wrapper").empty(), e("#robot-display-wrapper").html(`<div class="drive-icon ${t.type}"></div>`)) : e("#robot-display-wrapper").empty(), e("#custom-modal").addClass("driving-modal").attr("tabindex", "-1"), e("#drive-forward").find(".key-label").html("w"), e("#drive-left").find(".key-label").html("a"), e("#drive-backward").find(".key-label").html("s"), e("#drive-right").find(".key-label").html("d"), e("#aim-help-1 > p").html(Object(i.a)("robotAimingInstructionsStep1", [Object(i.a)(t.name)])), e("#aim-help-1 .aim-help-icon").addClass(t.type), t.type === c.d.R2D2.type || t.type === c.d.R2Q5.type ? e("#aim-help-2 > p").html(Object(i.a)("r2d2AimingInstructionsStep2", [Object(i.a)(t.name)])) : e("#aim-help-2 > p").html(Object(i.a)("robotAimingInstructionsStep2", [Object(i.a)(t.name)])), e("#aim-help-2 .aim-help-icon").addClass(t.type);
                        const n = Object(i.a)("enableKeyboard"),
                            s = Object(i.a)("enableJoystick");
                        e(".toggle-wrapper").append(f.g("toggle-drive-type", "", O, n, s)), e("#toggle-drive-type").on("click", u.d), p.a(r.getUserRobotSpeed()), b.a(o, 0), A(O);
                        const d = e("#custom-modal.driving-modal");
                        d.find("span.sprk-title").text(Object(i.a)(o ? "aim" : "drive")), d.find(".close-button").on("click", y)
                    },
                    onReady: () => {
                        E(t), a || m.a(r.getUserRobotColor()), e("#custom-modal").focus()
                    }
                })
            }, 500, {
                leading: !0
            }),
            y = () => {
                v = !1, l.a.closeCustomModal(T)
            },
            E = t => {
                const n = e("#driving-control-wrapper"),
                    o = n[0].getBoundingClientRect();
                u.b(v, D, n, o, h), v || j(t), R()
            },
            T = () => {
                a.f(a.b.WINDOW, a.a.Window.DRIVE_CLOSED), e(".toggle-option").off("click"), b.b(), m.b(), u.c(), S()
            },
            R = () => {
                e("#custom-modal.driving-modal").focus()
            },
            S = () => {
                e("body").focus()
            },
            D = (e, t, n, o) => {
                !v || t ? (p.b(r.getUserRobotSpeed()), C(e), N(o), b.a(t, n, o.enabled)) : y()
            },
            C = t => {
                e.each({
                    37: "aim-left",
                    39: "aim-right",
                    38: "speed-up",
                    40: "speed-down",
                    65: "drive-left",
                    68: "drive-right",
                    83: "drive-backward",
                    87: "drive-forward"
                }, (n, o) => {
                    const a = !0 === t[n];
                    e(`#${o}, #${o} .imageCaret`).toggleClass("pressed", a), e(`#${o} .key-label`).css("color", a ? "#FFFFFF" : "#0085CA", a)
                })
            },
            A = t => {
                O = t, v ? (e(".key-container").addClass("hidden"), e("#joystick-pip").addClass("hidden"), e(".toggle-wrapper").addClass("hidden")) : O ? (e(".key-container").addClass("hidden"), e("#joystick-pip").removeClass("hidden"), e(".toggle-option").addClass("on"), e(".toggle-label").addClass("highlighted")) : (e(".key-container").removeClass("hidden"), e("#joystick-pip").addClass("hidden"), e(".toggle-option").removeClass("on"), e(".toggle-label").removeClass("highlighted"))
            },
            N = t => {
                if (t.enabled !== O && A(t.enabled), O) {
                    const n = e("#joystick-pip");
                    n[0].style.top = t.location.y, n[0].style.left = t.location.x
                }
            },
            j = e => {
                Object(d.d)().then(t => {
                    (t.firstDrive || e) && M()
                }).catch(e => {
                    console.warn(e)
                })
            },
            M = () => {
                e(".modal-content").append(n(198)), e(".hint-bubble").text(Object(i.a)("aimHelp"));
                const t = I();
                e(".hint-bubble-container").css({
                    top: t.top,
                    left: t.left
                }), e("#custom-modal.driving-modal").on("keydown", w), Object(d.h)({
                    firstDrive: !1
                })
            },
            w = () => {
                e("#custom-modal.driving-modal").off("keydown", w), e(".hint-bubble-container").remove()
            },
            I = () => {
                const t = {},
                    n = e(".modal-content").offset(),
                    o = e("#aiming-img-div").offset(),
                    a = e(".hint-bubble-container").height();
                return t.top = o.top - n.top - a - 20, t.left = o.left - n.left - 45, t
            }
    }).call(this, n(8), n(16))
}, function(e, t) {
    e.exports = "{\n    const getCookieInfo = () => {\n        const cookies = {};\n        const cookiesArray = document.cookie.split(';');\n        const cookieRegex = /(.+)=(.+)/;\n        cookiesArray.forEach(cookie => {\n            const splitCookie = cookieRegex.exec(cookie.trim());\n            cookies[splitCookie[1]] = splitCookie[2];\n        });\n        if (cookies !== 'undefined') {\n            return cookies;\n        }\n    };\n    getCookieInfo();\n}"
}, , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , function(e, t, n) {
    "use strict";
    (function(e, o) {
        n.d(t, "a", function() {
            return y
        });
        var a = n(0),
            i = n(2),
            s = n.n(i),
            r = n(1),
            c = n(36),
            d = n(173),
            l = n(172),
            u = n(9),
            p = n(5),
            b = n(11),
            m = n(15),
            f = n(6);
        n(195);
        const v = ["loc", "att", "gyro", "accel", "vel", "dist"],
            O = {
                loc: ",f",
                att: ",f",
                gyro: ",.2f",
                accel: ",.2f",
                vel: ",.2f",
                dist: ",f"
            };
        let h, g;
        ((e, t) => a.e(a.b.WINDOW, e, t))(a.a.Window.RESIZE, () => {
            h && h.redraw()
        }), Object(b.a)();
        const y = e => {
                g = {}, V(e).then(t => {
                    if (t && t.runs && 0 !== t.runs.length) return t.runs;
                    E(e, "no data")
                }).then(t => {
                    t && E(e, t[0], t)
                }).catch(e => {
                    console.log(`Error displaying charts! ${e}`)
                })
            },
            E = (t, n, o) => {
                if ("no data" === n) return void P();
                const a = k(n);
                R(), j(t, n).then(e => {
                    S(t, e)
                }).catch(e => {
                    console.log(`Failed to get chart data! ${e}`)
                });
                const i = e("#right-drawer"),
                    s = e("#data-vis-session-info");
                i.find(".info-title").text(Object(r.a)("sensorData")), s.find(".session-text").text(Object(r.a)("session", a)), s.append(L(o)), T(), e("#data-vis-session-info > .session-text, #data-vis-session-dropdown").on("click", () => {
                    B()
                }), s.find(".sprk-list").on("mousedown", "li", n => {
                    const o = e(n.currentTarget).data("id");
                    e("#charts").empty(), s.find(".session-text").text(Object(r.a)("session", k(o))), B(), j(t, o).then(e => {
                        S(t, e)
                    }).catch(e => {
                        console.log(`Failed to get chart data! ${e}`)
                    })
                }), e("#charts").on("click", ".share", () => {
                    const e = p.a.closeConfirmationModal,
                        t = {
                            title: Object(r.a)("screenshotTitle"),
                            body: Y(),
                            confirmButtonTitle: Object(r.a)("acknowledgeButton"),
                            onConfirm: e
                        };
                    p.a.openConfirmationModal(t)
                })
            },
            T = () => {
                const t = e("#right-drawer"),
                    n = {
                        dismissible: !0,
                        opacity: .7,
                        in_duration: 400,
                        out_duration: 400,
                        ready: (e => {
                            e.find(".close-drawer").on("click", () => {
                                a.f(a.b.WINDOW, a.a.Window.DRAWER_CLOSED), e.closeRightDrawer()
                            })
                        }).bind(null, t),
                        complete: () => {
                            c.a.hideTooltips()
                        }
                    };
                a.f(a.b.WINDOW, a.a.Window.DRAWER_OPENED), t.openRightDrawer(n)
            },
            R = () => e("#right-drawer-container").html(n(193)),
            S = (t, n) => {
                const a = e("#charts"),
                    i = x(n.id, n.runTime),
                    s = o.intersection(v, Object.keys(n.data));
                Object(m.a)("#spinner-container"), Object(b.c)().then(e => {
                    e ? g = e : (s.forEach(e => {
                        g[e] = g[e] || {}
                    }), Object(b.f)(g))
                }), a.append(i), a.append(`<div class="center available-charts">${N(s)}</div>`), C(s[0], n.data[s[0]]), window.dispatchEvent(new Event("resize"));
                const r = a.find(".chart-change");
                r.first().addClass("filled"), r.on("click", t => {
                    Object(m.d)("#spinner-container");
                    const o = parseInt(t.currentTarget.dataset.chartindex);
                    h.clear(), setTimeout(() => {
                        e("#charts").find(".drawer-content-block").remove(), r.removeClass("filled"), e(t.currentTarget).addClass("filled"), C(s[o], n.data[s[o]])
                    }, 1)
                });
                const c = e("#download-csv");
                return c.on("click", n => {
                    const o = e(n.currentTarget).data("chartid");
                    U(t, o).then(e => {
                        Object(l.a)(e.sensorData, o, v)
                    }).catch(e => {
                        console.log(`Generating CSV failed! ${e}`)
                    })
                }), c.on("hover", t => {
                    e(t.currentTarget).toggleClass("hover")
                }), n.id
            },
            D = () => .8 * e("#charts").width() / 480,
            C = (t, n) => {
                const o = () => {
                    const o = h.getHtml(t);
                    let a;
                    e("#charts").append(M(o));
                    const i = e(`#${t}`);
                    i.append(w()), "loc" === t ? (h.generateChart(t, n, !1, D, Object(r.a)("axisLocationLabel", "X"), ",f", Object(r.a)("axisLocationLabel", "Y"), O[t]), A(h, t), a = "") : (h.generateChart(t, n, !0, null, Object(r.a)("xAxisTime"), ",.1f", null, O[t]), A(h, t), a = h.getButtonHtml(n)), i.find(".nv-single-point").removeClass(".nv-single-point"), i.before(I(t)), i.after(a), i.parent().on("click", "button", n => {
                        const o = e(n.currentTarget),
                            a = o.data("dataseries"),
                            i = h.toggleSeries(a);
                        i && (o.toggleClass("off"), g[t] = i, Object(b.f)(g))
                    })
                };
                h ? o() : h = new c.a(o, () => Object(m.b)(e("#spinner-container")))
            },
            A = (e, t) => {
                o.isEmpty(g[t]) ? g[t] = h.getDisabledState(t) : h.updateState(g[t])
            },
            N = e => o.map(e, (e, t) => {
                return `<button class="sprk-button empty chart-change" data-chartindex=${t} >${Object(r.a)(`${e}SelectButton`)}</button>`
            }).join(""),
            j = (e, t) => U(e, t).then(e => {
                if (e) return {
                    id: t,
                    runTime: $(e.sensorData),
                    data: Object(d.a)(e.sensorData)
                };
                throw new Error("Failed to load data run!")
            }).catch(e => {
                console.log("Get chart data for run failed!", e)
            }),
            M = e => `<div class="drawer-content-block">${e}</div>`,
            w = () => '<div id="spinner-container" class="chart-spinner"></div>',
            I = e => {
                const t = Object(f.f)().platform.toLowerCase();
                return `<div class="chart-header"><div class="spacer"></div>${(e=>`<div class="chart-title">${e=Object(r.a)(`${e}ChartTitle`)}</div>`)(e)}<div class="share icon ${t}"></div></div>`
            },
            k = e => s()(e).format("MMM DD, YYYY, hh:mm a"),
            x = (e, t) => {
                const n = s.a.duration(t);
                let o = n.minutes(),
                    a = n.milliseconds() >= 500 ? n.seconds() + 1 : n.seconds();
                return 60 === a && (o += 1, a = 0), `<div class="run-time">${o?Object(r.a)("runTimeMinutes",[o,a]):Object(r.a)("runTimeSeconds",[a])}  ${Object(u.e)("download-csv",Object(r.a)("downloadCsvData"),["empty","data-button"],{chartId:e})}</div>`
            },
            L = e => {
                return `<ul class="sprk-list">${o.reduce(e,(e,t)=>e+_(t),"")}</ul>`
            },
            _ = e => `<li class="sprk-list-item" data-id="${e}">${k(e)}</li>`,
            P = () => {
                e("#right-drawer-container").html(n(192)), e("#no-data-title").text(Object(r.a)("noDataTitle")), T()
            },
            B = () => {
                e("#data-vis-session-info, #data-vis-session-dropdown").toggleClass("open"), e("#data-vis-session-info .sprk-list").toggleClass("show")
            },
            $ = e => e[e.length - 1].time - e[0].time,
            U = (e, t) => new Promise(n => {
                W("program run data", [e, t], e => {
                    n(e)
                })
            }),
            V = e => new Promise(t => {
                W("program run list", [e], e => {
                    t(e)
                })
            }),
            W = (e, t, n) => {
                a.e(a.b.CANVAS, a.a.Canvas.DATABASE_RESULT, F.bind(null, n, e)), a.f(a.b.CANVAS, a.a.Canvas.DATABASE_REQUEST, {
                    name: e,
                    params: t
                })
            },
            F = (e, t, n) => {
                a.d(a.b.CANVAS, a.a.Canvas.DATABASE_RESULT, F), t === n.payload.name && e(n.payload.result)
            },
            Y = () => {
                let e, t;
                const n = H({
                    keyType: "function bold",
                    keyText: "&#8679;"
                });
                switch (Object(f.f)().platform) {
                    case f.a.PLATFORM.MAC_OS:
                        e = H({
                            keyType: "function bold",
                            keyText: "&#8984;"
                        }), t = H({
                            keyType: "function bold",
                            keyText: "4"
                        });
                        break;
                    case f.a.PLATFORM.WINDOWS:
                        e = H({
                            keyType: "function bold",
                            keySymbol: "windows-key"
                        }), t = H({
                            keyType: "function bold",
                            keyText: "S"
                        });
                        break;
                    default:
                        e = H({
                            keyType: "function bold",
                            keyText: "Ctrl"
                        }), t = H({
                            keyType: "function bold",
                            keySymbol: "switch-window"
                        })
                }
                return [`<div class="flex center row bold blue-text screen-shot-keys">${e} + ${n} + ${t}</div>`, Object(r.a)("screenshotText")]
            },
            H = ({
                keyType: e = "standard",
                keyText: t = "",
                keySymbol: n = ""
            }) => `<div class="keyboard-key ${e}"><div>${t}</div><div class=${n}></div></div>`
    }).call(this, n(8), n(16))
}, function(e, t) {
    e.exports = '\x3c!-- This modal is to be used when users are presented with a Y/n option and no other actions--\x3e\n<div id="confirmation-modal" class="modal custom-modal confirmation-dialog">\n    <div class="modal-content">\n        <div class="input-field">\n            <div class="modal-title"></div>\n            <div class="modal-body"></div>\n            <div class="row error">\n                <div class="input-error" class="error col s12"></div>\n            </div>\n            <div class="modal-footer">\n                <button id="cancel-button" class="modal-action cancel sprk-button empty cancel-button cancel"></button>\n                <button id="confirm-button" class="modal-action submit sprk-button filled confirm-button submit"></button>\n            </div>\n        </div>\n    </div>\n</div>\n'
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "p", function() {
            return o
        }), n.d(t, "d", function() {
            return a
        }), n.d(t, "e", function() {
            return i
        }), n.d(t, "o", function() {
            return s
        }), n.d(t, "k", function() {
            return r
        }), n.d(t, "l", function() {
            return c
        }), n.d(t, "b", function() {
            return d
        }), n.d(t, "c", function() {
            return l
        }), n.d(t, "i", function() {
            return u
        }), n.d(t, "a", function() {
            return p
        }), n.d(t, "n", function() {
            return b
        }), n.d(t, "h", function() {
            return m
        }), n.d(t, "f", function() {
            return f
        }), n.d(t, "m", function() {
            return v
        }), n.d(t, "g", function() {
            return O
        }), n.d(t, "j", function() {
            return h
        });
        const o = (e, t) => {
                g(e, () => {
                    e.setUserAgent(`${e.getUserAgent()} ${t}`)
                })
            },
            a = (e, t, n) => {
                g(e, () => {
                    e.getWebContents().session.webRequest.onBeforeRequest(t, (e, t) => {
                        t(n(e))
                    })
                })
            },
            i = (e, t, n) => {
                g(e, () => {
                    e.getWebContents().session.webRequest.onBeforeSendHeaders(t, (e, t) => {
                        t(n(e))
                    })
                })
            },
            s = (e, t, n) => {
                g(e, () => {
                    e.getWebContents().session.webRequest.onSendHeaders(t, n)
                })
            },
            r = (e, t) => {
                y("did-finish-load", e, () => t())
            },
            c = (e, t) => {
                t && y("did-fail-load", e, e => t(e))
            },
            d = (t, n, o, a) => {
                t.isLoadingMainFrame() ? setTimeout(() => {
                    d(t, n, a)
                }, 10) : t.executeJavaScript(`try { ${n} } catch (e) { const error = { type: "error", message: e.message }; error; } `, !1, t => {
                    if (a) {
                        const n = e.get(t, "type", null);
                        a("error" === n ? new Error(t.message) : t)
                    }
                })
            },
            l = e => {
                const t = e.getWebContents();
                t && t.currentIndex > 1 && (e.stop(), e.goBack())
            },
            u = (e, t, n) => {
                e.src = "about:blank", g(e, () => {
                    g(e, n), e.src = t
                })
            },
            p = e => {
                const t = e.getWebContents();
                if (t) {
                    t.session.clearStorageData({
                        storages: ["cookies"]
                    })
                }
            },
            b = (e, t) => {
                g(e, () => {
                    y("new-window", e, e => {
                        e.preventDefault();
                        const n = new URL(e.url);
                        t(e, n)
                    })
                })
            },
            m = (e, t) => {
                g(e, () => {
                    e.getWebContents().session.setPermissionRequestHandler((e, n, o) => {
                        let a = !0;
                        "fullscreen" === n && (a = t()), o(a)
                    })
                })
            },
            f = () => {},
            v = () => {},
            O = (e, t) => {
                y("enter-html-full-screen", e, t)
            },
            h = (e, t) => {
                y("leave-html-full-screen", e, t)
            },
            g = (e, t) => {
                y("dom-ready", e, t, {
                    once: !0
                })
            },
            y = (e, t, n, o = {}) => {
                e && t && n && t.addEventListener(e, (...e) => {
                    n(...e)
                }, o)
            }
    }).call(this, n(16))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "b", function() {
            return r
        }), n.d(t, "a", function() {
            return c
        }), n.d(t, "j", function() {
            return d
        }), n.d(t, "k", function() {
            return l
        }), n.d(t, "g", function() {
            return u
        }), n.d(t, "i", function() {
            return p
        }), n.d(t, "d", function() {
            return b
        }), n.d(t, "e", function() {
            return m
        }), n.d(t, "h", function() {
            return f
        }), n.d(t, "c", function() {
            return v
        }), n.d(t, "f", function() {
            return O
        });
        var o = n(13),
            a = n(33),
            i = n(180),
            s = n(21);
        o.webFrame && o.webFrame.setVisualZoomLevelLimits(1, 1);
        const r = e => {
                o.remote.getCurrentWindow().on("resize", e)
            },
            c = (e, t) => {
                o.remote.getCurrentWindow().addListener(e, t)
            },
            d = (e, t) => {
                o.remote.getCurrentWindow().removeListener(e, t)
            },
            l = (e, t, n) => {
                o.remote.dialog.showSaveDialog({
                    defaultPath: e,
                    filters: [{
                        extensions: ["csv"]
                    }]
                }, e => {
                    e ? a.writeFile(e, t, e => {
                        e && (console.log(`Writing CSV failed! ${e}`), n && n(e))
                    }) : console.log("File not saved")
                })
            },
            u = () => {
                o.remote.getCurrentWindow().minimize()
            },
            p = () => {
                o.remote.app.relaunch()
            },
            b = () => o.remote.app.getVersion(),
            m = () => {
                let e;
                switch (i.platform()) {
                    case "darwin":
                        e = s.a.PLATFORM.MAC_OS;
                        break;
                    case "win32":
                        e = s.a.PLATFORM.WINDOWS;
                        break;
                    default:
                        e = s.a.PLATFORM.UNKNOWN
                }
                return {
                    platform: e,
                    packager: s.a.PACKAGER.ELECTRON
                }
            },
            f = t => {
                const n = e.isString(t) ? t : t.toString();
                o.shell.openExternal(n)
            },
            v = () => !1,
            O = () => {}
    }).call(this, n(16))
}, function(e, t, n) {
    "use strict";
    var o = n(0),
        a = n(1);
    const i = () => {
        window.speechSynthesis.cancel()
    };
    n.d(t, "a", function() {
        return d
    });
    let s = null,
        r = !1,
        c = null;
    const d = () => {
            const e = (e, t) => o.e(o.b.SOUND, e, t);
            e(o.a.Sound.PLAY_EFFECT, e => l(e.payload.asset, e.payload.interrupt)), e(o.a.Sound.STOP, p), e(o.a.Sound.SPEAK, e => u(e.payload.text, e.payload.interrupt)), e(o.a.Sound.PLAY_ROBOT, e => m(e.payload)), e(o.a.Sound.STOP_ROBOT, f), u(" ", !1), i()
        },
        l = (e, t) => {
            e ? t || !b() ? (p(), (s = new Audio(`sounds/${e}.mp3`)).addEventListener("ended", () => {
                o.f(o.b.SOUND, o.a.Sound.COMPLETED)
            }), s.play()) : o.f(o.b.SOUND, o.a.Sound.CANCELLED) : o.f(o.b.SOUND, o.a.Sound.ERROR, {
                message: Object(a.a)("soundNameError", e)
            })
        },
        u = (e, t) => {
            !t && b() || !e ? o.f(o.b.SOUND, o.a.Sound.CANCELLED) : (((e, t) => {
                const n = new SpeechSynthesisUtterance(e);
                n.lang = window.navigator.language, n.onend = n.onerror = (() => {
                    t && t()
                }), window.speechSynthesis.speak(n)
            })(e, () => {
                r = !1, o.f(o.b.SOUND, o.a.Sound.COMPLETED)
            }), r = !0)
        },
        p = () => {
            s && (s.pause(), s.currentTime = 0), i()
        },
        b = () => !(!s || s.paused || s.ended || !(0 <= s.currentTime)) || r,
        m = e => {
            f(), (c = new Audio(`sounds/robot/${e}.mp3`)).play()
        },
        f = () => {
            c && (c.pause(), c.currentTime = 0)
        }
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return r
        });
        var o = n(4),
            a = n(0),
            i = n(6);
        let s;
        const r = () => {
                (s = e("#titleBar")).html(n(181)), d(), a.e(a.b.WINDOW, a.a.Window.MODAL_WILL_OPEN, () => c("modalOpen", !0)), a.e(a.b.WINDOW, a.a.Window.MODAL_CLOSED, () => c("modalOpen", !1)), a.e(a.b.WINDOW, a.a.Window.DRAWER_OPENED, () => c("drawerOpen", !0)), a.e(a.b.WINDOW, a.a.Window.DRAWER_CLOSED, () => c("drawerOpen", !1)), a.e(a.b.APP, a.a.App.NAVIGATION_STATE, e => c("canvasOpen", !e.payload))
            },
            c = (t, n) => {
                n ? e("#titleBar").find(".left-buttons").addClass(t) : e("#titleBar").find(".left-buttons").removeClass(t)
            },
            d = () => {
                s.find(".close-button").parent().on("click", () => {
                    o.a.sendSiteEvent("Close Window"), window.close()
                }), s.find(".minimize-button").parent().on("click", () => {
                    o.a.sendSiteEvent("Minimize Window"), Object(i.h)()
                }), s.find(".preferences-button").parent().on("click", () => {
                    a.f(a.b.APP, a.a.App.SHOW_PREFERENCES)
                }), s.find(".refresh-button").parent().on("click", () => {
                    a.f(a.b.APP, a.a.App.SITE_RELOAD)
                }), s.find(".back-button").parent().on("click", () => {
                    a.f(a.b.APP, a.a.App.SITE_GO_BACK)
                }), e(".title-bar-button-wrapper").hover(t => {
                    e(t.currentTarget).children().addClass("highlight")
                }, t => {
                    e(t.currentTarget).children().removeClass("highlight")
                })
            }
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return l
        });
        var o = n(1),
            a = n(5),
            i = n(4),
            s = n(3),
            r = n(0),
            c = n(9);
        let d = 1;
        window.RobotManager = s;
        const l = t => {
                d = t || 1;
                O(r.a.Robot.MATRIX.FRAME_SAVED, p), O(r.a.Robot.MATRIX.SAVING_COMPLETE, b), O(r.a.Robot.STATE.DISCONNECTED, m);
                const i = {
                    title: Object(o.a)("loadingMatrixAnimationTitle"),
                    body: n(187),
                    isDismissible: !1
                };
                a.a.openCustomModal(i, {
                    callback: g,
                    applyBeforeOpen: () => {
                        const t = e("#custom-modal");
                        t.addClass("load-matrix-animation"), t.find(".modal-footer").html(c.f("cancel-button", Object(o.a)("cancelButtonText"), ["modal-action", "cancel", "filled"]));
                        const n = t.find("#cancel-button");
                        n.on("click", () => {
                            s.cancelAnimation()
                        }), n.addClass("hidden"), u(0)
                    }
                })
            },
            u = (t = 0) => {
                const n = e("#loading-progress-meter"),
                    a = Math.min(100, Math.max((t - 1) / d * 100, 0));
                n.find(".progress-fill").height(`${a}%`), n.find(".progress-text").html(`${Math.round(a)}%`), n.find(".progress-info-text").html(Object(o.a)("loadingMatrixAnimationProgress", [t, d]))
            },
            p = e => {
                const t = e.payload;
                if (!t.success) {
                    let e = "";
                    return e = t.frameIndex > 1e3 ? Object(o.a)("matrixOverloadMaxFrames", [1e3]) : t.frameIndex > 600 ? Object(o.a)("matrixOverloadMaxFramesPerAnimation", [600]) : Object(o.a)("matrixOverloadErrorMessage", [600, 1e3]), void f(e)
                }
                u(t.frameIndex + 1)
            },
            b = e => {
                e.payload ? v() : f(Object(o.a)("matrixOverloadErrorMessage", [600, 1e3]))
            },
            m = () => {
                g()
            },
            f = e => {
                i.a.sendRobotEvent("Load Matrix Animation", "Failure"), g(e)
            },
            v = () => {
                i.a.sendRobotEvent("Load Matrix Animation", "Success"), g()
            },
            O = (e, t) => r.e(r.b.ROBOT, e, t),
            h = (e, t) => r.d(r.b.ROBOT, e, t),
            g = e => {
                h(r.a.Robot.MATRIX.FRAME_SAVED, p), h(r.a.Robot.MATRIX.SAVING_COMPLETE, b), h(r.a.Robot.STATE.DISCONNECTED, m), a.a.closeCustomModal(() => y(e))
            },
            y = e => {
                e && a.a.openErrorModal({
                    title: Object(o.a)("matrixOverloadErrorTitle"),
                    body: `${e}<br><br>${Object(o.a)("matrixOverloadSharedErrorMessage")}`
                })
            }
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    (function(e, o) {
        n.d(t, "a", function() {
            return d
        });
        var a = n(1),
            i = n(3),
            s = n(4),
            r = n(5);
        const c = [{
            id: i.RobotType.BOLT.type,
            name: Object(a.a)("boltNameLong")
        }, {
            id: i.RobotType.SPRK2.type,
            name: Object(a.a)("sprkPlusNameLong")
        }, {
            id: i.RobotType.SPHERO.type,
            name: Object(a.a)("spheroNameLong")
        }, {
            id: i.RobotType.MINI.type,
            name: Object(a.a)("miniNameLong")
        }, {
            id: i.RobotType.OLLIE.type,
            name: Object(a.a)("ollieNameLong")
        }, {
            id: i.RobotType.BB8.type,
            name: Object(a.a)("bb8NameLong")
        }, {
            id: i.RobotType.BB9E.type,
            name: Object(a.a)("bb9eNameLong")
        }, {
            id: i.RobotType.R2D2.type,
            name: Object(a.a)("r2d2NameLong")
        }, {
            id: i.RobotType.R2Q5.type,
            name: Object(a.a)("r2q5NameLong")
        }];
        if (!Object(i.supportsClassic)()) {
            let e = null;
            for (let t = 0; c[t]; t++)
                if (c[t].id === i.RobotType.SPHERO.type) {
                    e = c[t], c.splice(t, 1), c.push(e);
                    break
                }
        }
        const d = t => {
            const n = (n = i.RobotType.NONE) => {
                    const o = e("#custom-modal");
                    o.find(".connection-robot-icons").off("click"), o.find(".close-modal").off("click"), s.a.sendRobotEvent("Selected", n.type), t && t(n)
                },
                d = {
                    title: Object(a.a)("chooseYourRobot"),
                    body: '<div id="robot-icons"></div>',
                    isDismissible: !0,
                    onCancel: () => {
                        r.a.closeCustomModal(n)
                    }
                };
            r.a.openCustomModal(d, {
                callback: n,
                applyBeforeOpen: () => {
                    const t = e("#custom-modal");
                    t.addClass("robot-selection"), e("#robot-icons").html((e => e.reduce((e, t) => e.concat(`<div class="robot-selection-button" data-type=${t.id}>\n            <div id="${t.id}" class="robot-icon ${t.id}"></div><div class="robot-text">${t.name}</div>\n        </div>`), ""))(c));
                    const d = t.find(".robot-selection-button");
                    s.a.sendSiteEvent("Robot Select"), d.on("click", e => {
                        const t = e.currentTarget.dataset.type;
                        Object(i.supportsClassic)() || t !== i.RobotType.SPHERO.type ? r.a.closeCustomModal(n.bind(null, o.find(i.RobotType, {
                            type: e.currentTarget.dataset.type
                        }))) : r.a.openErrorModal({
                            title: Object(a.a)("robotNotSupportedTitle"),
                            body: Object(a.a)("robotNotSupportedMessage", [Object(a.a)("spheroNameLong")])
                        })
                    })
                }
            })
        }
    }).call(this, n(8), n(16))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return d
        });
        var o = n(9),
            a = n(1),
            i = n(6),
            s = n(2),
            r = n.n(s);
        const c = {
                loc: 2,
                att: 2,
                gyro: 1,
                accel: 2,
                vel: 2,
                dist: 2
            },
            d = (t, n, o) => {
                const a = l(t, o),
                    s = e.reduce(a, (e, t) => e.concat(`${t.join(",")}\n`), ""),
                    c = r()(n).format("MMMDD-YYYY-[at]-hh-mmA") + ".csv";
                return Object(i.l)(c, s), !0
            },
            l = (t, n) => {
                const o = [p(t, n)],
                    a = t[0].time;
                return t.forEach(t => {
                    const i = [];
                    e.forEach(n, n => {
                        t[n] && i.push(e.flatten(e.reduce(t[n], (e, t) => e.concat(u(t, c[n])), [])))
                    }), i.unshift(u((t.time - a) / 1e3, 2)), o.push(e.flatten(i))
                }), o
            },
            u = (e, t) => Object(o.d)(e, t).toFixed(t),
            p = (t, n) => {
                const o = [];
                return e.forEach(n, n => {
                    t[0][n] && o.push(e.map(t[0][n], (e, t) => `${n}${t}`))
                }), o.unshift("timeHeader"), e.map(e.flatten(o), a.a)
            }
    }).call(this, n(16))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return a
        });
        const o = t => {
                const n = {};
                return e.forEach(Object.keys(t), e => {
                    switch (e) {
                        case "gyro":
                        case "att":
                            n[e] = [{
                                values: [],
                                key: "pitch",
                                color: "#8FC41A",
                                minYValue: Number.POSITIVE_INFINITY,
                                maxYValue: Number.NEGATIVE_INFINITY
                            }, {
                                values: [],
                                key: "roll",
                                color: "#6645A8",
                                minYValue: Number.POSITIVE_INFINITY,
                                maxYValue: Number.NEGATIVE_INFINITY
                            }, {
                                values: [],
                                key: "yaw",
                                color: "#F3C21A",
                                minYValue: Number.POSITIVE_INFINITY,
                                maxYValue: Number.NEGATIVE_INFINITY
                            }];
                            break;
                        case "loc":
                            n[e] = [{
                                values: [],
                                key: "loc",
                                color: "#8FC41A",
                                minXValue: Number.POSITIVE_INFINITY,
                                maxXValue: Number.NEGATIVE_INFINITY,
                                minYValue: Number.POSITIVE_INFINITY,
                                maxYValue: Number.NEGATIVE_INFINITY
                            }];
                            break;
                        case "vel":
                        case "dist":
                            n[e] = [{
                                values: [],
                                key: "x",
                                color: "#8FC41A",
                                minYValue: Number.POSITIVE_INFINITY,
                                maxYValue: Number.NEGATIVE_INFINITY
                            }, {
                                values: [],
                                key: "y",
                                color: "#6645A8",
                                minYValue: Number.POSITIVE_INFINITY,
                                maxYValue: Number.NEGATIVE_INFINITY
                            }, {
                                values: [],
                                key: "total",
                                color: "#0085CA",
                                minYValue: Number.POSITIVE_INFINITY,
                                maxYValue: Number.NEGATIVE_INFINITY
                            }];
                            break;
                        case "accel":
                            n[e] = [{
                                values: [],
                                key: "x",
                                color: "#8FC41A",
                                minYValue: Number.POSITIVE_INFINITY,
                                maxYValue: Number.NEGATIVE_INFINITY
                            }, {
                                values: [],
                                key: "y",
                                color: "#6645A8",
                                minYValue: Number.POSITIVE_INFINITY,
                                maxYValue: Number.NEGATIVE_INFINITY
                            }, {
                                values: [],
                                key: "z",
                                color: "#F3C21A",
                                minYValue: Number.POSITIVE_INFINITY,
                                maxYValue: Number.NEGATIVE_INFINITY
                            }, {
                                values: [],
                                key: "total",
                                color: "#0085CA",
                                minYValue: Number.POSITIVE_INFINITY,
                                maxYValue: Number.NEGATIVE_INFINITY
                            }]
                    }
                }), n
            },
            a = e => {
                const t = o(e[0]),
                    n = 0,
                    a = 0,
                    i = 1,
                    s = 2,
                    r = 0,
                    c = 1,
                    d = 2,
                    l = 3,
                    u = 2,
                    p = e[0].time,
                    b = (e, t) => {
                        t < e.minXValue && (e.minXValue = t), t > e.maxXValue && (e.maxXValue = t)
                    },
                    m = (e, t) => {
                        t < e.minYValue && (e.minYValue = t), t > e.maxYValue && (e.maxYValue = t)
                    };
                return e.forEach(e => {
                    const o = (e.time - p) / 1e3;
                    for (const p in e) {
                        const f = e[p],
                            v = t[p];
                        switch (p) {
                            case "loc":
                                b(v[n], f.x), m(v[n], f.y), v[n].values.push(f);
                                break;
                            case "gyro":
                                m(v[a], f.x), m(v[i], f.y), m(v[s], f.z), v[a].values.push({
                                    x: o,
                                    y: f.x
                                }), v[i].values.push({
                                    x: o,
                                    y: f.y
                                }), v[s].values.push({
                                    x: o,
                                    y: f.z
                                });
                                break;
                            case "att":
                                m(v[a], f.pitch), m(v[i], f.roll), m(v[s], f.yaw), v[a].values.push({
                                    x: o,
                                    y: f.pitch
                                }), v[i].values.push({
                                    x: o,
                                    y: f.roll
                                }), v[s].values.push({
                                    x: o,
                                    y: f.yaw
                                });
                                break;
                            case "vel":
                            case "dist":
                                m(v[r], f.x), m(v[c], f.y), m(v[u], f.total), v[r].values.push({
                                    x: o,
                                    y: f.x
                                }), v[c].values.push({
                                    x: o,
                                    y: f.y
                                }), v[u].values.push({
                                    x: o,
                                    y: f.total
                                });
                                break;
                            case "accel":
                                m(v[r], f.x), m(v[c], f.y), m(v[d], f.z), m(v[l], f.total), v[r].values.push({
                                    x: o,
                                    y: f.x
                                }), v[c].values.push({
                                    x: o,
                                    y: f.y
                                }), v[d].values.push({
                                    x: o,
                                    y: f.z
                                }), v[l].values.push({
                                    x: o,
                                    y: f.total
                                })
                        }
                    }
                }), t
            }
    }).call(this, n(16))
}, function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return c
        });
        var o = n(1),
            a = n(3),
            i = n(9),
            s = n(17),
            r = n(6);
        const c = () => {
                const t = e("#custom-modal-container");
                t.addClass("preferences"), t.append(n(204));
                const c = Object(o.a)("appVersion", [Object(r.e)(), ""]),
                    p = Object(r.f)().platform === r.a.PLATFORM.MAC_OS ? "prefsTitle" : "settingsTitle",
                    b = e("#preferences-modal");
                b.find(".modal-title").html(Object(o.a)(p)), b.find(".modal-footer").append(i.f("cancel-button", Object(o.a)("cancelButtonText"), ["modal-action", "cancel", "empty"])).append(i.f("save-button", Object(o.a)("saveButtonText"), ["modal-action", "submit", "filled"])).after(`<div class="app-version">${c}</div>`), d("sensor-data", "optionSensorData", a.getUserSensorSetting()), e("#save-button").on("click", () => {
                    const t = "on" === e("#sensor-data:checked").val();
                    a.setUserSensorSetting(t), l()
                }), e("#cancel-button").on("click", () => {
                    l()
                }), s.b(b, {
                    dismissible: !1,
                    complete: u
                })
            },
            d = (t, n, a) => {
                n = Object(o.a)(n);
                const s = Object(o.a)("optionOff"),
                    r = Object(o.a)("optionOn");
                e("#preferences-modal").find(".modal-body").append(i.g(t, n, a, s, r))
            },
            l = () => {
                s.a(e("#preferences-modal"), {
                    complete: u
                })
            },
            u = () => {
                const t = e("#custom-modal-container");
                t.removeClass("preferences"), t.empty()
            }
    }).call(this, n(8))
}, , function(e, t, n) {
    "use strict";
    (function(e) {
        n.d(t, "a", function() {
            return c
        });
        var o = n(1),
            a = n(4),
            i = n(30),
            s = n(0),
            r = n(9);
        const c = (t, o) => {
                const a = e("#load-screen-container"),
                    i = n(205);
                o = o || 0, a.append(i), a.fadeIn(o), t || (a.find(".sprk-button").click(() => {
                    a.find(".splash-info").removeClass("show"), s.f(s.b.APP, s.a.App.SITE_RELOAD), d()
                }), d())
            },
            d = () => {
                if (navigator.onLine) {
                    let t, n = "";
                    if (window.cleverLogin) {
                        t = `https://edu.sphero.com/signin/${n=`?user_token=${r.b(window.cleverLogin).id}`}`
                    } else t = "https://edu.sphero.com/";
                    Object(i.a)(t, t => {
                        e("#app-splash-screen").length && (t && -3 !== t ? l(Object(o.a)("retryConnectionButtonText"), Object(o.a)("connectionErrorHeaderMessage"), Object(o.a)("couldNotConnectWebSiteErrorDescriptionMessage")) : (a.a.sendAppLoadTiming(), u()))
                    })
                } else setTimeout(() => {
                    l(Object(o.a)("retryConnectionButtonText"), Object(o.a)("connectionErrorHeaderMessage"), Object(o.a)("connectionErrorDescriptionMessage"))
                }, 1e3)
            },
            l = (t, n, o) => {
                const a = e("#app-splash-screen"),
                    i = a.find(".splash-info");
                a.find(".info-header").html(n), a.find(".info-msg").html(o), a.find(".sprk-button").html(t), i.addClass("show")
            },
            u = t => {
                e("#app-splash-screen").remove(), e("#load-screen-container").fadeOut(t || 500)
            }
    }).call(this, n(8))
}, function(e, t) {
    e.exports = '{\n    const pauseVideos = () => {\n        //pause youtube videos\n        const iframes = document.querySelectorAll(\'iframe.youtube\');\n        for (let i = 0; i < iframes.length; i++) {\n            const iframe = iframes[i];\n            iframe.contentWindow.postMessage(\'{"event":"command","func":"pauseVideo","args":""}\', \'*\');\n        }\n\n        //pause native html 5 videos\n        const videoElements = document.querySelectorAll(\'video\');\n        videoElements.forEach(videoElement => {\n            videoElement.pause();\n        });\n    };\n    pauseVideos();\n}'
}, function(e, t) {
    e.exports = "/* eslint-disable no-unused-vars */\n/* global sendMessageToApp */\n\nif (!navigator.userAgent.match(/sprkapp/i)) {\n    sendMessageToApp('APP', 'user agent override failed');\n}"
}, function(e, t) {
    e.exports = "/* eslint-disable no-unused-vars */\n/* eslint-disable no-undef */\n\n/* const */sendMessageToApp = window.sendMessageToApp;"
}, function(e, t) {
    e.exports = require("os")
}, function(e, t) {
    e.exports = '<div class="left-buttons">\n    <div class="title-bar-button-wrapper">\n        <div class="title-bar-button back-button"></div>\n    </div>\n    <div class="title-bar-button-wrapper">\n        <div class="title-bar-button refresh-button"></div>\n    </div>\n    <div class="title-bar-button-wrapper">\n        <div class="title-bar-button preferences-button"></div>\n    </div>\n</div>\n<div class="draggable-area"></div>\n<div class="right-buttons">\n    <div class="title-bar-button-wrapper">\n        <div class="title-bar-button minimize-button"></div>\n    </div>\n    <div class="title-bar-button-wrapper">\n        <div class="title-bar-button close-button"></div>\n    </div>\n</div>\n'
}, function(e, t, n) {
    e.exports = n.p + "ac2ad0fe947e502aa6a42a42766243a3.svg"
}, function(e, t, n) {
    e.exports = n.p + "b7f3ff7269724e3c9b1077c808c42f13.svg"
}, function(e, t, n) {
    e.exports = n.p + "16309c8a1237cc9f787fb623d4f5141b.svg"
}, function(e, t, n) {
    e.exports = n.p + "d3b562828ee1b926ad9cc7ab6958f9ff.svg"
}, function(e, t, n) {
    e.exports = n.p + "e2650e4cca22fcabd2856a9754f5b349.svg"
}, function(e, t) {
    e.exports = '<div id="loading-progress-meter">\n        <div class="progress-meter">\n            <div class="progress-fill" />\n            <div class="progress-text" />\n            <div class="mask" />\n        </div>\n    <div class="progress-info-text"></div>\n</div>\n'
}, function(e, t, n) {
    e.exports = n.p + "0b33d0c942f019b38aab0688476a9131.png"
}, function(e, t, n) {
    e.exports = n.p + "62abc0ad60814b5d964df5c05a08cfde.png"
}, function(e, t, n) {
    e.exports = '<div id="loading-progress-meter">\n    <div class="background-img progress-meter">\n        <img src="' + n(189) + '"/>\n    </div>\n    <div class="progress-img progress-meter">\n        <img src="' + n(188) + '"/>\n    </div>\n    <p class="progress-info-text"></p>\n</div>\n'
}, function(e, t) {
    e.exports = '<div id="robot-status">\n</div>\n<div id="robot-disconnected">\n    <p></p>\n</div>\n'
}, function(e, t) {
    e.exports = '<div id="right-drawer" class="modal data-vis">\n    <div class="drawer-content">\n        <div class="fixed">\n            <div class="close-drawer"></div>\n            <div class="info-title"></div>\n        </div>\n        <div class="drawer-content-container no-data">\n            <div class="drawer-background centered no-data">\n                <div id="no-data-title"></div>\n                <div id="no-data-image"></div>\n        </div>\n    </div>\n</div>\n</div>\n'
}, function(e, t) {
    e.exports = '<div id="right-drawer" class="modal data-vis">\n    <div class="drawer-content">\n        <div class="fixed">\n            <div class="close-drawer"></div>\n            <div class="info-title"></div>\n        </div>\n        <div class="drawer-content-container">\n            <div id="data-vis-session-info"><span class="session-text"></span><span id="data-vis-session-dropdown"\n                                                                                    class="dropdown-caret"></span></div>\n            <div class="drawer-background">\n                <div id="charts">\n                    <div id="spinner-container"></div>\n                </div>\n            </div>\n        </div>\n    </div>\n</div>\n'
}, , , function(e, t, n) {
    var o = {
        "./af": 163,
        "./af.js": 163,
        "./ar": 162,
        "./ar-dz": 161,
        "./ar-dz.js": 161,
        "./ar-kw": 160,
        "./ar-kw.js": 160,
        "./ar-ly": 159,
        "./ar-ly.js": 159,
        "./ar-ma": 158,
        "./ar-ma.js": 158,
        "./ar-sa": 157,
        "./ar-sa.js": 157,
        "./ar-tn": 156,
        "./ar-tn.js": 156,
        "./ar.js": 162,
        "./az": 155,
        "./az.js": 155,
        "./be": 154,
        "./be.js": 154,
        "./bg": 153,
        "./bg.js": 153,
        "./bm": 152,
        "./bm.js": 152,
        "./bn": 151,
        "./bn.js": 151,
        "./bo": 150,
        "./bo.js": 150,
        "./br": 149,
        "./br.js": 149,
        "./bs": 148,
        "./bs.js": 148,
        "./ca": 147,
        "./ca.js": 147,
        "./cs": 146,
        "./cs.js": 146,
        "./cv": 145,
        "./cv.js": 145,
        "./cy": 144,
        "./cy.js": 144,
        "./da": 143,
        "./da.js": 143,
        "./de": 142,
        "./de-at": 141,
        "./de-at.js": 141,
        "./de-ch": 140,
        "./de-ch.js": 140,
        "./de.js": 142,
        "./dv": 139,
        "./dv.js": 139,
        "./el": 138,
        "./el.js": 138,
        "./en-au": 137,
        "./en-au.js": 137,
        "./en-ca": 136,
        "./en-ca.js": 136,
        "./en-gb": 135,
        "./en-gb.js": 135,
        "./en-ie": 134,
        "./en-ie.js": 134,
        "./en-il": 133,
        "./en-il.js": 133,
        "./en-nz": 132,
        "./en-nz.js": 132,
        "./eo": 131,
        "./eo.js": 131,
        "./es": 130,
        "./es-do": 129,
        "./es-do.js": 129,
        "./es-us": 128,
        "./es-us.js": 128,
        "./es.js": 130,
        "./et": 127,
        "./et.js": 127,
        "./eu": 126,
        "./eu.js": 126,
        "./fa": 125,
        "./fa.js": 125,
        "./fi": 124,
        "./fi.js": 124,
        "./fo": 123,
        "./fo.js": 123,
        "./fr": 122,
        "./fr-ca": 121,
        "./fr-ca.js": 121,
        "./fr-ch": 120,
        "./fr-ch.js": 120,
        "./fr.js": 122,
        "./fy": 119,
        "./fy.js": 119,
        "./gd": 118,
        "./gd.js": 118,
        "./gl": 117,
        "./gl.js": 117,
        "./gom-latn": 116,
        "./gom-latn.js": 116,
        "./gu": 115,
        "./gu.js": 115,
        "./he": 114,
        "./he.js": 114,
        "./hi": 113,
        "./hi.js": 113,
        "./hr": 112,
        "./hr.js": 112,
        "./hu": 111,
        "./hu.js": 111,
        "./hy-am": 110,
        "./hy-am.js": 110,
        "./id": 109,
        "./id.js": 109,
        "./is": 108,
        "./is.js": 108,
        "./it": 107,
        "./it.js": 107,
        "./ja": 106,
        "./ja.js": 106,
        "./jv": 105,
        "./jv.js": 105,
        "./ka": 104,
        "./ka.js": 104,
        "./kk": 103,
        "./kk.js": 103,
        "./km": 102,
        "./km.js": 102,
        "./kn": 101,
        "./kn.js": 101,
        "./ko": 100,
        "./ko.js": 100,
        "./ky": 99,
        "./ky.js": 99,
        "./lb": 98,
        "./lb.js": 98,
        "./lo": 97,
        "./lo.js": 97,
        "./lt": 96,
        "./lt.js": 96,
        "./lv": 95,
        "./lv.js": 95,
        "./me": 94,
        "./me.js": 94,
        "./mi": 93,
        "./mi.js": 93,
        "./mk": 92,
        "./mk.js": 92,
        "./ml": 91,
        "./ml.js": 91,
        "./mn": 90,
        "./mn.js": 90,
        "./mr": 89,
        "./mr.js": 89,
        "./ms": 88,
        "./ms-my": 87,
        "./ms-my.js": 87,
        "./ms.js": 88,
        "./mt": 86,
        "./mt.js": 86,
        "./my": 85,
        "./my.js": 85,
        "./nb": 84,
        "./nb.js": 84,
        "./ne": 83,
        "./ne.js": 83,
        "./nl": 82,
        "./nl-be": 81,
        "./nl-be.js": 81,
        "./nl.js": 82,
        "./nn": 80,
        "./nn.js": 80,
        "./pa-in": 79,
        "./pa-in.js": 79,
        "./pl": 78,
        "./pl.js": 78,
        "./pt": 77,
        "./pt-br": 76,
        "./pt-br.js": 76,
        "./pt.js": 77,
        "./ro": 75,
        "./ro.js": 75,
        "./ru": 74,
        "./ru.js": 74,
        "./sd": 73,
        "./sd.js": 73,
        "./se": 72,
        "./se.js": 72,
        "./si": 71,
        "./si.js": 71,
        "./sk": 70,
        "./sk.js": 70,
        "./sl": 69,
        "./sl.js": 69,
        "./sq": 68,
        "./sq.js": 68,
        "./sr": 67,
        "./sr-cyrl": 66,
        "./sr-cyrl.js": 66,
        "./sr.js": 67,
        "./ss": 65,
        "./ss.js": 65,
        "./sv": 64,
        "./sv.js": 64,
        "./sw": 63,
        "./sw.js": 63,
        "./ta": 62,
        "./ta.js": 62,
        "./te": 61,
        "./te.js": 61,
        "./tet": 60,
        "./tet.js": 60,
        "./tg": 59,
        "./tg.js": 59,
        "./th": 58,
        "./th.js": 58,
        "./tl-ph": 57,
        "./tl-ph.js": 57,
        "./tlh": 56,
        "./tlh.js": 56,
        "./tr": 55,
        "./tr.js": 55,
        "./tzl": 54,
        "./tzl.js": 54,
        "./tzm": 53,
        "./tzm-latn": 52,
        "./tzm-latn.js": 52,
        "./tzm.js": 53,
        "./ug-cn": 51,
        "./ug-cn.js": 51,
        "./uk": 50,
        "./uk.js": 50,
        "./ur": 49,
        "./ur.js": 49,
        "./uz": 48,
        "./uz-latn": 47,
        "./uz-latn.js": 47,
        "./uz.js": 48,
        "./vi": 46,
        "./vi.js": 46,
        "./x-pseudo": 45,
        "./x-pseudo.js": 45,
        "./yo": 44,
        "./yo.js": 44,
        "./zh-cn": 43,
        "./zh-cn.js": 43,
        "./zh-hk": 42,
        "./zh-hk.js": 42,
        "./zh-tw": 41,
        "./zh-tw.js": 41
    };

    function a(e) {
        var t = i(e);
        return n(t)
    }

    function i(e) {
        var t = o[e];
        if (!(t + 1)) {
            var n = new Error('Cannot find module "' + e + '".');
            throw n.code = "MODULE_NOT_FOUND", n
        }
        return t
    }
    a.keys = function() {
        return Object.keys(o)
    }, a.resolve = i, e.exports = a, a.id = 196
}, function(e, t) {
    e.exports = '<div id="right-drawer" class="modal">\n    <div class="drawer-content">\n        <div class="fixed">\n            <div class="close-drawer"></div>\n            <div class="info-title"></div>\n            <ul class="tabs"></ul>\n        </div>\n    </div>\n    <div class="content-tabs"></div>\n</div>\n'
}, function(e, t) {
    e.exports = '<div class="hint-bubble-container">\n    <div class="hint-bubble"></div>\n</div>\n'
}, function(e, t) {
    e.exports = '<div class="modal-content">\n    <div class="close-button"></div>\n    <div class="modal-title"><span class="sprk-title"></span></div>\n    <div class="modal-body">\n        \x3c!-- the images for these  directional components change dynamically, so they are declared on the CSS file --\x3e\n        <div id="driving-control-wrapper">\n            <div id="aiming-circle"></div>\n            <div class="key-container">\n                <div id="top-key-row">\n                    <div id="drive-forward" class="key">\n                        <span class="key-label"></span>\n                        <div class="direction-arrow top-side" data-direction="0" ></div>\n                    </div>\n                </div>\n                <div id="bottom-key-row">\n                    <div id="drive-left" class="key">\n                        <span class="key-label"></span>\n                        <div class="direction-arrow left-side" data-direction="270"></div>\n                    </div>\n                    <div id="drive-backward" class="key">\n                        <span class="key-label"></span>\n                        <div class="direction-arrow bottom-side" data-direction="180"></div>\n                    </div>\n                    <div id="drive-right" class="key">\n                        <span class="key-label"></span>\n                        <div class="direction-arrow right-side" data-direction="90"></div>\n                    </div>\n                </div>\n            </div>\n            <div id="joystick-pip" class="hidden"></div>\n            \x3c!--  <canvas id="visualizer"></canvas>--\x3e\n        </div>\n        <div id="speed-slider-wrapper">\n            <div id="speed-slider-middle-div">\n                <div id="icon-fast"></div>\n                <div id="speed-slider"></div>\n                <div id="icon-slow"></div>\n            </div>\n            <div id="speed-up" class="rectangular-key throttle"> \x3c!-- keyboard directional UP  --\x3e\n                <div class="imageCaret"></div>\n            </div>\n            <div id="speed-down" class="rectangular-key throttle">\n                <div class="imageCaret"></div>\x3c!-- keyboard directional DOWN  --\x3e\n            </div>\n        </div>\n        \x3c!--  <canvas id="visualizer"></canvas>--\x3e\n    </div>\n    <div id="color-wheel-wrapper">\n        <div id="picked-color-display"></div>\n        <div id="selection-ring"></div>\n        <div id="driving-colour-wheel"></div>\n    </div>\n    <div id="robot-display-wrapper">\n    </div>\n    <div id="aiming-help-wrapper" class="hidden">\n        <div id="aim-help-1">\n            <p></p>\n            <div class="aim-help-icon"></div>\n        </div>\n        <div id="aim-help-2">\n            <p></p>\n            <div class="aim-help-icon"></div>\n        </div>\n    </div>\n    <div id="aiming-wrapper">\n        <div id="aim-left" class="rectangular-key small aim">\n            <div class="imageCaret"></div>\n        </div>\n        <div id="aiming-img-div">\n            <div class="aim-icon"></div>\n        </div>\n        <div id="aim-right" class="rectangular-key small aim">\n            <div class="imageCaret"></div>\n        </div>\n    </div>\n    <div class="toggle-wrapper">\n        \n    </div>\n</div>\n<div class="component-wrapper">\n    <div class=\'dim brightness-icon\'></div>\n    <div id="brightness-slider"></div>\n    <div class=\'bright brightness-icon\'></div>\n</div>\n\n'
}, function(e, t) {
    e.exports = '\x3c!-- Modal is to be used for anything requiring the users to do something that isn\'t a straight Y/n answer --\x3e\n<div id="custom-modal" class="modal custom-modal">\n    <div class="modal-content">\n        <div class="close-button"></div>\n        <div class="modal-title"></div>\n        <div class="modal-body"></div>\n        <div class="row error"></div>\n        <div class="modal-footer"></div>\n    </div>\n</div>\n'
}, function(e, t) {
    e.exports = '<div id="comment-modal" class="modal custom-modal text-input" tabindex=-1 >\n    <div class="modal-content">\n        <div class="top-bar">\n            <div id="confirm-button" class="modal-accept submit"></div>\n            <div class="modal-title"></div>\n            <div id="cancel-button" class="modal-cancel cancel"></div>\n        </div>\n        <textarea type="text" id="text-input-field" class="sprk-input" rows="10"/>\n    </div>\n</div>'
}, function(e, t) {
    e.exports = '\x3c!-- Modal is to be used for anything requiring the users to do something that isn\'t a straight Y/n answer --\x3e\n<div id="custom-modal" class="modal custom-modal confirmation-dialog">\n    <div class="modal-content">\n        <div class="input-field">\n            <div class="modal-header">\n                <div class="modal-title"></div>\n                <div id="action-buttons"></div>\n            </div>\n            <div class="modal-body"></div>\n            <div class="row error">\n                <div class="input-error" class="error col s12"></div>\n            </div>\n            <div class="modal-footer">\n                <button id="cancel-button" class="modal-action cancel sprk-button empty cancel-button cancel"></button>\n                <button id="confirm-button" class="modal-action submit sprk-button filled confirm-button submit"></button>\n            </div>\n        </div>\n    </div>\n</div>\n'
}, function(e, t) {
    e.exports = '<div id="error-modal" class="modal custom-modal error-dialog">\n    <div class="modal-content">\n        <div class="input-field">\n            <div class="modal-title"></div>\n            <div class="modal-body"></div>\n            <div class="row error">\n                <div class="input-error" class="error col s12"></div>\n            </div>\n            <div class="modal-footer">\n                <button id="confirm-button" class="modal-action submit sprk-button filled confirm-butto submit"></button>\n            </div>\n        </div>\n    </div>\n</div>'
}, function(e, t) {
    e.exports = '<div id="preferences-modal" class="modal custom-modal">\n    <div class="modal-content">\n        <div class="modal-title"></div>\n        <div class="modal-body">\n        </div>\n        <div class="modal-footer"></div>\n    </div>\n</div>\n'
}, function(e, t) {
    e.exports = '<div id="app-splash-screen" class="splash-screen-main">\n    <div class="content-container">\n        <div class="sprk-logo large"></div>\n        <div class="splash-info">\n            <p class="info-header"></p>\n            <p class="info-msg"></p>\n            <button class="sprk-button sprk-white empty"></button>\n        </div>\n    </div>\n</div>\n'
}, , function(e, t, n) {}, function(e, t) {
    e.exports = require("path")
}, , , , , , , , function(e, t, n) {
    "use strict";
    (function(e) {
        n(215), n(213), n(211);
        var t = n(1);
        window.jQuery = window.$ = e, e.fn.extend({
            velocity: Materialize.Vel,
            openRightDrawer: function(n) {
                const o = e(this).modal(n).getDOMObject().M_Modal;
                o.animateIn = function() {
                    e.extend(this.$el[0].style, {
                        display: "block",
                        opacity: 0
                    }), e.extend(this.$overlay[0].style, {
                        display: "block",
                        opacity: 0
                    }), this.$overlay.velocity({
                        opacity: this.options.opacity
                    }, {
                        duration: this.options.inDuration,
                        queue: !1,
                        ease: "easeOutCubic"
                    });
                    const n = {
                        duration: this.options.inDuration,
                        queue: !1,
                        ease: "easeOutCubic",
                        complete: () => {
                            "function" == typeof this.options.ready && this.options.ready.call(this, this.$el, this.openingTrigger)
                        }
                    };
                    this.$el.css({
                        display: "block",
                        opacity: 1
                    });
                    const o = Object(t.b)() ? {
                        left: "0"
                    } : {
                        right: "0"
                    };
                    this.$el.velocity(o, n)
                }, o.animateOut = function() {
                    this.$overlay.velocity({
                        opacity: 0
                    }, {
                        duration: this.options.outDuration,
                        queue: !1,
                        ease: "easeOutQuart"
                    });
                    const e = {
                            duration: this.options.outDuration,
                            queue: !1,
                            ease: "easeOutCubic",
                            complete: () => {
                                this.$el[0].style.display = "none", this.$overlay[0].parentNode.removeChild(this.$overlay[0]), "function" == typeof this.options.complete && this.options.complete.call(this, this.$el)
                            }
                        },
                        n = Object(t.b)() ? {
                            left: "-100%"
                        } : {
                            right: "-100%"
                        };
                    this.$el.velocity(n, e)
                }, o.open()
            },
            closeRightDrawer: function(t) {
                const n = e(this).getDOMObject() ? e(this).getDOMObject().M_Modal : null;
                n && (n.options = e.extend({}, n.options, t), n.close())
            },
            openModal: function(t) {
                const n = e(this).modal(t).getDOMObject().M_Modal;
                n.animateIn = function() {
                    e.extend(this.$el[0].style, {
                        display: "block",
                        opacity: 0
                    }), e.extend(this.$overlay[0].style, {
                        display: "block",
                        opacity: 0
                    }), this.$overlay.velocity({
                        opacity: this.options.opacity
                    }, {
                        duration: this.options.inDuration,
                        queue: !1,
                        ease: "easeOutCubic"
                    });
                    const t = {
                        duration: this.options.inDuration,
                        queue: !1,
                        ease: "easeOutCubic",
                        complete: () => {
                            "function" == typeof this.options.ready && this.options.ready.call(this, this.$el, this.openingTrigger)
                        }
                    };
                    this.$el.css({
                        display: "block",
                        opacity: 0,
                        transformOrigin: "top"
                    }), this.$el.velocity({
                        scale: [1, 0],
                        translateY: ["-50%", "-50%"],
                        opacity: [1, 0]
                    }, t)
                }, n.animateOut = function() {
                    this.$overlay.velocity({
                        opacity: 0
                    }, {
                        duration: this.options.outDuration,
                        queue: !1,
                        ease: "easeOutQuart"
                    });
                    const e = {
                        duration: this.options.outDuration,
                        queue: !1,
                        ease: "easeOutCubic",
                        complete: () => {
                            this.$el[0].style.display = "none", this.$overlay[0].parentNode.removeChild(this.$overlay[0]), "function" == typeof this.options.complete && this.options.complete.call(this, this.$el)
                        }
                    };
                    this.$el.velocity({
                        scale: [0, 1],
                        translateY: ["-50%", "-50%"],
                        opacity: [0, 1]
                    }, e)
                }, n.open()
            },
            closeModal: function(t) {
                const n = e(this).getDOMObject() ? e(this).getDOMObject().M_Modal : null;
                n && (n.options = e.extend({}, n.options, t), n.close())
            }
        })
    }).call(this, n(8))
}, function(e, t, n) {
    "use strict";
    n.r(t),
        function(e) {
            n(216), n(207);
            var t = n(4),
                o = n(30),
                a = n(169),
                i = n(26),
                s = n(168),
                r = n(0),
                c = n(25),
                d = n(6),
                l = n(1);
            r.c("app", !1, !1), document.addEventListener("dragover", e => e.preventDefault()), document.addEventListener("drop", e => e.preventDefault()), window.onload = (() => {
                window.kiosk ? Object(d.d)() && e("body").addClass("kiosk") : Object(c.a)(), Object(l.b)() && e("body").addClass("rtl"), t.a.start(), o.b(), i.c(), s.a(), a.a()
            }), e.fn.extend({
                getDOMObject: function() {
                    return this.get(0)
                }
            })
        }.call(this, n(8))
}]);