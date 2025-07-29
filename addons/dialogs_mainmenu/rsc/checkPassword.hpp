class RscCheckPassword {
    idd = 6100;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = QUOTE(_this execvm '\x\ar\addons\dialogs_mainmenu\scripts\onLoadCheckPassword.sqf');
    onUnload = QUOTE(_this execvm '\x\ar\addons\dialogs_mainmenu\scripts\onUnloadCheckPassword.sqf');
    class ControlsBackground {
        class fullscreenBackground : RscText {
            x = SAFEZONE_X;
            y = SAFEZONE_Y;
            w = SAFEZONE_W;
            h = SAFEZONE_H;
            colorBackground[] = CA_UI_background;
        };
        class background : RscText {
            x = X_COORD(0.33489584);
            y = Y_COORD(0.40370371);
            w = W_COORD(0.33020834);
            h = H_COORD(0.16481482);
            colorBackground[] = GUI_BCG_MENU;
        };
        class frame : background {
            style = ST_FRAME;
            colorText[] = GUI_BCG_COLOR;
        };
        class info : RscText {
            x = X_COORD(0.3453125);
            y = Y_COORD(0.44537038);
            w = W_COORD(0.309375);
            h = GUI_STD_HEIGHT;
            text = SUBCSTRING(info);
            colorBackground[] = CA_UI_transparent;
            colorText[] = GUI_TEXT_COLOR;
        };
    };
    class Controls {
        class header : RscText {
            idc = 1000;
            x = X_COORD(0.33489584);
            y = Y_COORD(0.40370371);
            w = W_COORD(0.33020834);
            h = GUI_STD_HEIGHT;
            text = SUBCSTRING(header);
            colorBackground[] = GUI_BCG_COLOR;
            colorText[] = GUI_TITLETEXT_COLOR;
        };
        class passwordInput : RscEdit {
            idc = 1234;
            x = X_COORD(0.3453125);
            y = Y_COORD(0.48611112);
            w = W_COORD(0.309375);
            h = GUI_STD_HEIGHT;
            text = "";
            onEditChanged = QUOTE(profileNamespace setVariable [ARR_2('ar_dialogs_PasswordSaved',ARG_1(_this,1))]);
        };
        class btnCancel : RscButtonMenuCancel {
            x = X_COORD(0.43802084);
            y = Y_COORD(0.52777778);
            w = GUI_STD_WIDTH;
            h = GUI_STD_HEIGHT;
            onButtonClick = QUOTE((findDisplay 6100) closeDisplay 2;);
        };
        class btnConfirm : RscButtonMenuOK {
            x = X_COORD(0.5515625);
            y = Y_COORD(0.52777778);
            w = GUI_STD_WIDTH;
            h = GUI_STD_HEIGHT;
            onButtonClick = QUOTE((findDisplay 6100) closeDisplay 1;);
        };
    };
};
