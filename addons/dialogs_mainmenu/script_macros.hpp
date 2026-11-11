// Layout: positions are taken from the 1600x900 mockup and scaled to the safe zone
#define MX(px) X_COORD((px)/1600)
#define MY(py) Y_COORD((py)/900)
#define MW(px) W_COORD((px)/1600)
#define MH(py) H_COORD((py)/900)

// Functions compiled in preStart live in uiNamespace (the main menu has no mission namespace of its own)
#define UIFUNC(var1) (uiNamespace getVariable QSUBFUNC(var1))

// Colors from adeptus-team.eu (hex in comments).
// Note: screenshots taken with Windows HDR on look brighter than the game really is.
// #060709
#define CO_BG { 0.024, 0.027, 0.035, 1 }
#define CO_BG_HEADER { 0.024, 0.027, 0.035, 0.85 }
#define CO_BG_PANEL { 0.024, 0.027, 0.035, 0.82 }
// #101828
#define CO_ROW { 0.063, 0.094, 0.157, 0.6 }
#define CO_ROW_HOVER { 0.063, 0.094, 0.157, 0.85 }
// #1E2939
#define CO_BORDER { 0.118, 0.161, 0.224, 1 }
#define CO_LINE { 1, 1, 1, 0.05 }
#define CO_WHITE { 1, 1, 1, 1 }
// #D1D5DC
#define CO_TEXT { 0.82, 0.835, 0.863, 1 }
// #99A1AF
#define CO_MUTED { 0.6, 0.631, 0.686, 1 }
// #6A7282
#define CO_DIM { 0.416, 0.447, 0.51, 1 }
// #FAC800
#define CO_YELLOW { 0.98, 0.784, 0, 1 }
// #51A2FF
#define CO_BLUE { 0.318, 0.635, 1, 1 }
// #FF6900
#define CO_ORANGE { 1, 0.412, 0, 1 }
// #5865F2
#define CO_DISCORD { 0.345, 0.396, 0.949, 1 }
#define CO_OVERLAY { 0.024, 0.027, 0.035, 0.78 }
// #0B0F16
#define CO_PANEL { 0.043, 0.059, 0.086, 1 }
#define CO_NONE { 0, 0, 0, 0 }

// Same colors, for scripts
#define ARR_ROW [0.063, 0.094, 0.157, 0.6]
#define ARR_ROW_HOVER [0.063, 0.094, 0.157, 0.85]
#define ARR_MUTED [0.6, 0.631, 0.686, 1]
#define ARR_WHITE [1, 1, 1, 1]

// Button colors: the textures are white shapes tinted with colorText (ctrlSetTextColor on hover)
// #D08700
#define CO_BTN { 0.816, 0.529, 0, 1 }
// #EDB200
#define CO_BTN_HOVER { 0.929, 0.698, 0, 1 }
// #101828
#define CO_BTN2 { 0.063, 0.094, 0.157, 1 }
// #1E2939
#define CO_BTN2_HOVER { 0.118, 0.161, 0.224, 1 }
// #364153
#define CO_BTN2_BORDER { 0.212, 0.255, 0.325, 1 }
#define ARR_BTN [0.816, 0.529, 0, 1]
#define ARR_BTN_HOVER [0.929, 0.698, 0, 1]
#define ARR_BTN2 [0.063, 0.094, 0.157, 1]
#define ARR_BTN2_HOVER [0.118, 0.161, 0.224, 1]

#define FONT_BOLD "RobotoCondensedBold"
#define FONT_REG  "RobotoCondensed"

// Text-only button (transparent, no shadow, no press offset)
#define BTN_FLAT(textColor)                 \
    colorText[] = textColor;                \
    colorDisabled[] = CO_DIM;               \
    colorBackground[] = CO_NONE;            \
    colorBackgroundActive[] = CO_NONE;      \
    colorBackgroundDisabled[] = CO_NONE;    \
    colorFocused[] = CO_NONE;               \
    colorShadow[] = CO_NONE;                \
    colorBorder[] = CO_NONE;                \
    shadow = 0;                             \
    borderSize = 0;                         \
    offsetX = 0;                            \
    offsetY = 0;                            \
    offsetPressedX = 0;                     \
    offsetPressedY = 0

// Server rows (index from 1): row background, accent bar, texts, join button image, clickable overlay
#define IDC_ROW_BG(i)     (6110 + i)
#define IDC_ROW_JOIN(i)   (6120 + i)
#define IDC_ROW_BUTTON(i) (6100 + i)

#define IDC_PROFILE_NAME 6150
#define IDC_VERSION      6151
#define IDC_PROFILE_BUTTON 6153
#define IDC_TAGLINE      6154
#define IDC_NEWS         6155
#define IDC_NEWS_LABEL   6156
#define IDC_NEWS_FALLBACK 6157

// News page shown on the main menu (its address must be whitelisted in CfgCommands, see config.cpp)
#define NEWS_URL "https://adeptus-team.eu/arma/news"
#define IDC_INTRO_BLACK  6190
#define IDC_INTRO_LOGO   6191
#define IDC_INTRO_TITLE  6192
#define IDC_INTRO_LINE   6193
#define IDC_OPTIONS_BG   6170

// Password dialog
#define IDD_PASSWORD        6100
#define IDC_PWD_TITLE       1000
#define IDC_PWD_INPUT       1234
#define IDC_PWD_REMEMBER    1235
#define IDC_PWD_CANCEL_IMG  1240
#define IDC_PWD_CONFIRM_IMG 1241
#define IDC_PWD_CANCEL      1250
#define IDC_PWD_CONFIRM     1251

// Profile variables (the password key is kept from the previous menu so saved passwords still work)
#define PROFILE_PASSWORD "AR_Dialogs_PasswordSaved"
#define PROFILE_REMEMBER "AR_Dialogs_RememberPassword"
#define PROFILE_LOADOUT  "AR_Dialogs_MainMenu_Loadout"

#define TEX(name) QPATHTOF(data\name)

