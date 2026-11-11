// Server password dialog, opened from a server row of the main menu (fnc_selectServer)
class RscCheckPassword {
    idd = IDD_PASSWORD;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "_this call (uiNamespace getVariable 'AR_Dialogs_MainMenu_fnc_onLoadPassword')";
    onUnload = "_this call (uiNamespace getVariable 'AR_Dialogs_MainMenu_fnc_onUnloadPassword')";

    class ControlsBackground {
        class overlay : RscText {
            x = "safezoneX";
            y = "safezoneY";
            w = "safezoneW";
            h = "safezoneH";
            colorBackground[] = CO_OVERLAY;
        };
        class panel : RscText {
            x = MX(530);
            y = MY(300);
            w = MW(540);
            h = MH(300);
            colorBackground[] = CO_PANEL;
        };
        class panelFrame : panel {
            style = ST_FRAME;
            colorBackground[] = CO_NONE;
            colorText[] = CO_BORDER;
        };
        class topBar : RscText {
            x = MX(530);
            y = MY(300);
            w = MW(540);
            h = MH(3);
            colorBackground[] = CO_YELLOW;
        };
        class tag : RscText {
            x = MX(558);
            y = MY(322);
            w = MW(480);
            h = MH(22);
            font = FONT_BOLD;
            sizeEx = MH(13);
            shadow = 0;
            colorText[] = CO_YELLOW;
            text = SUBCSTRING(passwordTag);
        };
        class label : tag {
            y = MY(396);
            font = FONT_REG;
            sizeEx = MH(16);
            colorText[] = CO_MUTED;
            text = SUBCSTRING(passwordLabel);
        };
        class rememberLabel : label {
            x = MX(588);
            y = MY(480);
            w = MW(300);
            h = MH(26);
            text = SUBCSTRING(passwordRemember);
        };
        class cancelImage : RscPicture {
            idc = IDC_PWD_CANCEL_IMG;
            x = MX(722);
            y = MY(526);
            w = MW(150);
            h = MH(48);
            text = TEX(btn_fill_ca.paa);
            colorText[] = CO_BTN2;
        };
        class cancelOutline : cancelImage {
            idc = -1;
            text = TEX(btn_outline_ca.paa);
            colorText[] = CO_BTN2_BORDER;
        };
        class confirmImage : cancelImage {
            idc = IDC_PWD_CONFIRM_IMG;
            x = MX(890);
            colorText[] = CO_BTN;
        };
    };

    class Controls {
        class title : RscText {
            idc = IDC_PWD_TITLE;
            x = MX(558);
            y = MY(344);
            w = MW(484);
            h = MH(40);
            font = FONT_BOLD;
            sizeEx = MH(30);
            shadow = 0;
            colorText[] = CO_WHITE;
            text = "";
        };
        class passwordInput : RscEdit {
            idc = IDC_PWD_INPUT;
            x = MX(558);
            y = MY(424);
            w = MW(484);
            h = MH(44);
            font = FONT_REG;
            sizeEx = MH(18);
            shadow = 0;
            colorBackground[] = CO_BG;
            colorText[] = CO_WHITE;
            colorSelection[] = CO_YELLOW;
            text = "";
        };
        class rememberBox : RscCheckBox {
            idc = IDC_PWD_REMEMBER;
            x = MX(558);
            y = MY(482);
            w = MW(22);
            h = MH(22);
        };
        class btnCancel : RscButton {
            idc = IDC_PWD_CANCEL;
            x = MX(722);
            y = MY(526);
            w = MW(150);
            h = MH(48);
            style = ST_CENTER;
            font = FONT_BOLD;
            sizeEx = MH(16);
            text = SUBCSTRING(passwordCancel);
            BTN_FLAT(CO_TEXT);
            onButtonClick = "(ctrlParent (_this select 0)) closeDisplay 2";
        };
        class btnConfirm : btnCancel {
            idc = IDC_PWD_CONFIRM;
            x = MX(890);
            default = 1; // Enter in the password field connects
            text = SUBCSTRING(passwordConnect);
            colorText[] = CO_WHITE;
            onButtonClick = "(ctrlParent (_this select 0)) closeDisplay 1";
        };
    };
};
