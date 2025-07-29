class RscLoadout {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = QUOTE(_this call SUBFUNC(onLoad););
    onUnload = QUOTE(_this call SUBFUNC(onUnload););
    class ControlsBackground {
        class titleClass : RscText {
            x = X_COORD(0.00520834);
            y = Y_COORD(0.00462963);
            w = W_COORD(0.20625);
            h = GUI_STD_HEIGHT;
            text = SUBCSTRING(titleClass);
            colorBackground[] = GUI_BCG_COLOR;
            colorText[] = GUI_TITLETEXT_COLOR;
        };
        class titleSubClass : titleClass {
            idc = 1007;
            x = X_COORD(0.22135417);
            text = SUBCSTRING(titleSubClass);
        };
        class titleEquipement : titleClass {
            idc = 1008;
            x = X_COORD(0.7890625);
            text = SUBCSTRING(titleEquipement);
        };
    };
    class Controls {
        class listClass : RscListBox {
            idc = 1001;
            x = X_COORD(0.00520834);
            y = Y_COORD(0.03240741);
            w = W_COORD(0.20625);
            h = H_COORD(0.96296297);
            onLBSelChanged = QUOTE(_this call SUBFUNC(updateInterface););
        };
        class listSubClass : listClass {
            idc = 1002;
            x = X_COORD(0.22135417);
            h = H_COORD(0.17870371);
            onLBSelChanged = QUOTE(_this call SUBFUNC(updateInterface););
        };
        class listEquipement : listClass {
            idc = 1003;
            x = X_COORD(0.7890625);
            h = H_COORD(0.7425926);
        };
        class infoIsEngineer : RscText {
            idc = 1004;
            x = X_COORD(0.7890625);
            y = Y_COORD(0.78888889);
            w = W_COORD(0.20625);
            h = GUI_STD_HEIGHT;
            colorText[] = GUI_CO_WHITE;
            colorBackground[] = GUI_CO_RED;
        };
        class infoIsEOD : infoIsEngineer {
            idc = 1005;
            y = Y_COORD(0.82962963);
        };
        class infoIsMedic : infoIsEngineer {
            idc = 1006;
            y = Y_COORD(0.8712963);
        };
        class btnCancel : RscButton {
            x = X_COORD(0.77864584);
            y = Y_COORD(0.9675926);
            w = GUI_STD_WIDTH;
            h = GUI_STD_HEIGHT;
            text = CSTRING(btnCancel);
            BTN_COLOR_RED;
            onButtonClick = QUOTE(closeDialog 2;);
        };
        class btnConfirm : btnCancel {
            x = X_COORD(0.89166667);
            y = Y_COORD(0.9675926);
            text = CSTRING(btnConfirm);
            BTN_COLOR_GREEN;
            onButtonClick = QUOTE(closeDialog 1;);
        };
    };
};
