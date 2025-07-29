class RscStandardDisplay;
class RscDisplayMain : RscStandardDisplay {
    delete Spotlight;
    idd = 0;
    idc = 1;
    enableDisplay = 1;
    class ControlsBackground {
        class SUBCVAR(background) : RscText {
            x = X_COORD(0.29375);
            y = Y_COORD(0.54166667);
            w = W_COORD(0.4125);
            h = H_COORD(0.23333334);
            colorBackground[] = GUI_BCG_MENU;
        };
        class SUBCVAR(Img1): RscPicture {
            x = X_COORD(0.30416667);
            y = Y_COORD(0.55462963);
            w = GUI_MAINMENU_WIDTH;
            h = H_COORD(0.20648149);
            text = QPATHTOF(data\img1_co.paa);
        };
        class SUBCVAR(Img2): SUBCVAR(Img1) {
            x = X_COORD(0.43802084);
            text = QPATHTOF(data\img2_co.paa);
        };
        class SUBCVAR(Img3): SUBCVAR(Img1) {
            x = X_COORD(0.57239584);
            text = QPATHTOF(data\img3_co.paa);
        };
        class SUBCVAR(name1): RscText {
            x = X_COORD(0.30416667);
            y = Y_COORD(0.55462963);
            w = GUI_MAINMENU_WIDTH;
            h = GUI_STD_HEIGHT;
            text = SUBCSTRING(name1);
            colorText[] = GUI_TEXT_COLOR;
            colorBackground[] = GUI_BCG_MENU;
        };
        class SUBCVAR(name2): SUBCVAR(name1) {
            x = X_COORD(0.43802084);
            text = SUBCSTRING(name2);
        };
        class SUBCVAR(name3): SUBCVAR(name1) {
            x = X_COORD(0.57239584);
            text = SUBCSTRING(name3);
        };
        class SUBCVAR(connect1): SUBCVAR(name1) {
            y = Y_COORD(0.73333334);
            text = SUBCSTRING(connect);
            style = ST_CENTER;
            BTN_COLOR_DEFAULT;
        };
        class SUBCVAR(connect2): SUBCVAR(connect1) {
            x = X_COORD(0.43802084);
        };
        class SUBCVAR(connect3): SUBCVAR(connect1) {
            x = X_COORD(0.57239584);
        };
    };
    class controls {
        class Logo : RscShortcutButton {
            access = 0;
            color[] = { 1, 1, 1, 1 };
            colorActive[] = { 1, 1, 1, 1 };
            colorDisabled[] = { 1, 1, 1, 0.25 };
            default = 0;
            deletable = 0;
            fade = 0;
            font = "RobotoCondensed";
            h = "1 * 5 * (pixelH * pixelGrid * 2)";
            shadow = 0;
            sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
            soundClick[] = { "", 0.1, 1 };
            soundEnter[] = { "", 0.1, 1 };
            soundEscape[] = { "", 0.1, 1 };
            soundPush[] = { "", 0.1, 1 };
            style = 48;
            text = QPATHTOF(data\logo_ca.paa);
            tooltipColorBox[] = { 1, 1, 1, 1 };
            tooltipColorShade[] = { 0, 0, 0, 0.65 };
            tooltipColorText[] = { 1, 1, 1, 1 };
            type = 11;
            url = "";
            w = "2 * 	5 * 	(pixelW * pixelGrid * 2)";
            x = "0.5 - 	5 * 	(pixelW * pixelGrid * 2)";
            y = "safezoneY + (3 - 0.5 * 	5) * 	(pixelH * pixelGrid * 2)";
        };
        class LogoApex : Logo {
        };

        delete Spotlight1;
        delete Spotlight2;
        delete Spotlight3;
        delete BackgroundSpotlightRight;
        delete BackgroundSpotlightLeft;
        delete BackgroundSpotlight;
        delete SpotlightNext;
        delete SpotlightPrev;

        class SUBCVAR(connect1): RscButton {
            idc = 6101;
            x = X_COORD(0.30416667);
            y = Y_COORD(0.55462963);
            w = GUI_MAINMENU_WIDTH;
            h = H_COORD(0.20648149);
            onButtonClick = QUOTE(_this execvm '\x\ar\addons\dialogs_mainmenu\scripts\connectToServer.sqf';);
            colorBackground[] = CA_UI_transparent;
            colorBackgroundActive[] = GUI_BCG_COLOR_SELECTED;
            colorBackgroundDisabled[] = GUI_BCG_MENU;
        };
        class SUBCVAR(connect2): SUBCVAR(connect1) {
            idc = 6102;
            x = X_COORD(0.43802084);
        };
        class SUBCVAR(connect3): SUBCVAR(connect1) {
            idc = 6103;
            x = X_COORD(0.57239584);
        };
    };
};
