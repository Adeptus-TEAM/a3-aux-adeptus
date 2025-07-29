#include "\a3\ui_f\hpp\defineCommonColors.inc"

#include "\a3\ui_f\hpp\defineCommonGrids.inc"

#include "\a3\ui_f\hpp\defineResinclDesign.inc"

// Define common dialog dimensions
#define SAFEZONE_X "safezoneX"
#define SAFEZONE_Y "safezoneY"
#define SAFEZONE_W "safezoneW"
#define SAFEZONE_H "safezoneH"

#define X_COORD(x) QUOTE((safezoneX + (safezoneW * x)))
#define Y_COORD(y) QUOTE((safezoneY + (safezoneH * y)))
#define W_COORD(w) QUOTE((safezoneW * w))
#define H_COORD(h) QUOTE((safezoneH * h))

#define GUI_STD_WIDTH \
    W_COORD(0.103125)

#define GUI_STD_HEIGHT \
    H_COORD(0.02777778)

// Define dialog colors
#define GUI_CO_WHITE { 1, 1, 1, 1 }
#define GUI_CO_TRANSPARENT { 0, 0, 0, 0 }

#define RGB_CO_GREEN 0.137, 0.608, 0.337
#define GUI_CO_GREEN { RGB_CO_GREEN, 1 }
#define GUI_CO_GREEN_SELECTED { RGB_CO_GREEN, 0.5 }

#define RGB_CO_RED 0.796, 0.263, 0.208
#define GUI_CO_RED { RGB_CO_RED, 1 }
#define GUI_CO_RED_SELECTED { RGB_CO_RED, 0.5 }

#define RGB_CO_PURPLE 0.502, 0.302, 0.502
#define GUI_CO_PURPLE { RGB_CO_PURPLE, 1 }
#define GUI_CO_PURPLE_SELECTED { RGB_CO_PURPLE, 0.5 }


// Define dialog button colors
#define BTN_COLOR_DEFAULT                             \
    colorText[] = GUI_TITLETEXT_COLOR;                \
    colorBackground[] = GUI_BCG_COLOR;                \
    colorBackgroundActive[] = GUI_BCG_COLOR_SELECTED; \
    colorBackgroundDisabled[] = GUI_BCG_COLOR_SELECTED; \
    colorFocused[] = GUI_BCG_COLOR

#define BTN_COLOR_GREEN                              \
    colorText[] = GUI_CO_WHITE;                      \
    colorBackground[] = GUI_CO_GREEN;                \
    colorBackgroundActive[] = GUI_CO_GREEN_SELECTED; \
    colorBackgroundDisabled[] = GUI_CO_GREEN_SELECTED; \
    colorFocused[] = GUI_CO_GREEN

#define BTN_COLOR_RED                              \
    colorText[] = GUI_CO_WHITE;                    \
    colorBackground[] = GUI_CO_RED;                \
    colorBackgroundActive[] = GUI_CO_RED_SELECTED; \
    colorBackgroundDisabled[] = GUI_CO_RED_SELECTED; \
    colorFocused[] = GUI_CO_RED

#define BTN_COLOR_PURPLE                             \
    colorText[] = GUI_CO_WHITE;                    \
    colorBackground[] = GUI_CO_PURPLE;             \
    colorBackgroundActive[] = GUI_CO_PURPLE_SELECTED; \
    colorBackgroundDisabled[] = GUI_CO_PURPLE_SELECTED; \
    colorFocused[] = GUI_CO_PURPLE

#define BTN_CA_ARROW_LEFT \
    autoAdjustTexture = TRUE; \
	color[] = GUI_CO_WHITE; \
	colorBackground[] = GUI_CO_WHITE; \
	colorFocused[] = GUI_CO_WHITE; \
	colorBackgroundFocused[] = GUI_CO_WHITE; \
    animTextureDefault = QPATHTOEF(dialogs,data\arrowempty_left_ca.paa); \
    animTextureNormal = QPATHTOEF(dialogs,data\arrowempty_left_ca.paa); \
    animTextureDisabled = QPATHTOEF(dialogs,data\arrowempty_left_ca.paa); \
    animTextureOver = QPATHTOEF(dialogs,data\arrowempty_left_ca.paa); \
    animTextureFocused = QPATHTOEF(dialogs,data\arrowempty_left_ca.paa); \
    animTexturePressed = QPATHTOEF(dialogs,data\arrowfull_left_ca.paa)

#define BTN_CA_ARROW_RIGHT \
    autoAdjustTexture = TRUE; \
	color[] = GUI_CO_WHITE; \
	colorBackground[] = GUI_CO_WHITE; \
	colorFocused[] = GUI_CO_WHITE; \
	colorBackgroundFocused[] = GUI_CO_WHITE; \
    animTextureDefault = QPATHTOEF(dialogs,data\arrowempty_right_ca.paa); \
    animTextureNormal = QPATHTOEF(dialogs,data\arrowempty_right_ca.paa); \
    animTextureDisabled = QPATHTOEF(dialogs,data\arrowempty_right_ca.paa); \
    animTextureOver = QPATHTOEF(dialogs,data\arrowempty_right_ca.paa); \
    animTextureFocused = QPATHTOEF(dialogs,data\arrowempty_right_ca.paa); \
    animTexturePressed = QPATHTOEF(dialogs,data\arrowfull_right_ca.paa)

#define BTN_OFFSET_PRESSED \
    offsetPressedX = 0.003; \
    offsetPressedY = 0.003

// Define common dialog styles
#define ST_LEFT 0x00
#define ST_RIGHT 0x01
#define ST_CENTER 0x02
#define ST_DOWN 0x04
#define ST_UP 0x08
#define ST_VCENTER 0x0C
#define ST_SINGLE 0x00
#define ST_MULTI 0x10
#define ST_TITLE_BAR 0x20
#define ST_PICTURE 0x30
#define ST_FRAME 0x40
#define ST_BACKGROUND 0x50
#define ST_GROUP_BOX 0x60
#define ST_GROUP_BOX2 0x70
#define ST_HUD_BACKGROUND 0x80
#define ST_TILE_PICTURE 0x90
#define ST_WITH_RECT 0xA0
#define ST_LINE 0xB0
#define ST_UPPERCASE 0xC0
#define ST_LOWERCASE 0xD0
#define ST_ADDITIONAL_INFO 0x0F00
#define ST_SHADOW 0x0100
#define ST_NO_RECT 0x0200
#define ST_KEEP_ASPECT_RATIO 0x0800
#define ST_TITLE ST_TITLE_BAR + ST_CENTER
#define SL_VERT 0
#define SL_HORZ 0x400
#define SL_TEXTURES 0x10
#define ST_VERTICAL 0x01
#define ST_HORIZONTAL 0
#define LB_TEXTURES 0x10
#define LB_MULTI 0x20
#define TR_SHOWROOT 1
#define TR_AUTOCOLLAPSE 2
