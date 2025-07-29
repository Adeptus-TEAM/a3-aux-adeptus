class ctrlMenuStrip;
class Display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class Tools {
                    items[] += {QCVAR(missionParameters)};
                };
                class CVAR(missionParameters) {
                    text = SUBCSTRING(missionParametersText);
                    picture = QPATHTOEF(main,data\logo_ca.paa);
                    action = QUOTE(call SUBFUNC(openInterface));
                };
            };
        };
    };
};
