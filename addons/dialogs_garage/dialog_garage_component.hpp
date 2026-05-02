// ============================================
// GARAGE DIALOG - Color Defines
// ============================================

// --- Background Colors ---
#define RGB_CO_OVERLAY 0, 0, 0
#define GUI_CO_OVERLAY { RGB_CO_OVERLAY, 0.72 }

#define RGB_CO_PANEL 0, 0, 0
#define GUI_CO_PANEL { RGB_CO_PANEL, 0.82 }

#define RGB_CO_INPUT 0, 0, 0
#define GUI_CO_INPUT { RGB_CO_INPUT, 0.40 }

#define RGB_CO_LISTBOX 0, 0, 0
#define GUI_CO_LISTBOX { RGB_CO_LISTBOX, 0.60 }

// --- Selection / Hover ---
#define RGB_CO_BLUE 0.45, 0.63, 0.76
#define GUI_CO_SELECTED { RGB_CO_BLUE, 0.35 }
#define GUI_CO_HOVER { RGB_CO_BLUE, 0.15 }

// --- Border Colors ---
#define GUI_CO_BORDER { RGB_CO_BLUE, 0.25 }
#define GUI_CO_BORDER_ACTIVE { RGB_CO_BLUE, 0.60 }

// --- Text Colors ---
#define GUI_CO_TEXT_WHITE { 1, 1, 1, 0.9 }
#define GUI_CO_TEXT_LIGHT { 1, 1, 1, 0.7 }
#define GUI_CO_TEXT_DIM { 1, 1, 1, 0.4 }
#define GUI_CO_TEXT_ACCENT { 0.55, 0.75, 0.86, 0.95 }

// --- Button: SPAWN (Green) ---
#define RGB_CO_SPAWN 0.27, 0.63, 0.31
#define GUI_CO_SPAWN { RGB_CO_SPAWN, 0.20 }
#define GUI_CO_SPAWN_HOVER { RGB_CO_SPAWN, 0.40 }
#define GUI_CO_SPAWN_TEXT { 0.47, 0.78, 0.51, 0.95 }

// --- Button: DELETE (Red) ---
#define RGB_CO_DELETE 0.71, 0.24, 0.24
#define GUI_CO_DELETE { RGB_CO_DELETE, 0.22 }
#define GUI_CO_DELETE_HOVER { RGB_CO_DELETE, 0.40 }
#define GUI_CO_DELETE_TEXT { 0.82, 0.35, 0.35, 0.95 }

// --- Button: PYLON (Yellow) ---
#define RGB_CO_PYLON 0.75, 0.63, 0.20
#define GUI_CO_PYLON { RGB_CO_PYLON, 0.20 }
#define GUI_CO_PYLON_HOVER { RGB_CO_PYLON, 0.38 }
#define GUI_CO_PYLON_TEXT { 0.82, 0.75, 0.35, 0.95 }

// --- Button: REARM (Blue / Standard) ---
#define RGB_CO_REARM RGB_CO_BLUE
#define GUI_CO_REARM { RGB_CO_BLUE, 0.18 }
#define GUI_CO_REARM_HOVER { RGB_CO_BLUE, 0.35 }
#define GUI_CO_REARM_TEXT GUI_CO_TEXT_ACCENT

// ============================================
// Button Macros (like your BTN_COLOR_GREEN)
// ============================================

#define BTN_COLOR_SPAWN                                \
    colorText[] = GUI_CO_SPAWN_TEXT;                    \
    colorBackground[] = GUI_CO_SPAWN;                  \
    colorBackgroundActive[] = GUI_CO_SPAWN_HOVER;      \
    colorBackgroundDisabled[] = GUI_CO_SPAWN;           \
    colorBorder[] = GUI_CO_BORDER;                       \
    colorFocused[] = GUI_CO_SPAWN

#define BTN_COLOR_DELETE                               \
    colorText[] = GUI_CO_DELETE_TEXT;                   \
    colorBackground[] = GUI_CO_DELETE;                 \
    colorBackgroundActive[] = GUI_CO_DELETE_HOVER;     \
    colorBackgroundDisabled[] = GUI_CO_DELETE;          \
    colorBorder[] = GUI_CO_BORDER;                       \
    colorFocused[] = GUI_CO_DELETE

#define BTN_COLOR_PYLON                                \
    colorText[] = GUI_CO_PYLON_TEXT;                    \
    colorBackground[] = GUI_CO_PYLON;                  \
    colorBackgroundActive[] = GUI_CO_PYLON_HOVER;      \
    colorBackgroundDisabled[] = GUI_CO_PYLON;           \
    colorBorder[] = GUI_CO_BORDER;                       \
    colorFocused[] = GUI_CO_PYLON

#define BTN_COLOR_REARM                                \
    colorText[] = GUI_CO_REARM_TEXT;                    \
    colorBackground[] = GUI_CO_REARM;                  \
    colorBackgroundActive[] = GUI_CO_REARM_HOVER;      \
    colorBackgroundDisabled[] = GUI_CO_REARM;           \
    colorBorder[] = GUI_CO_BORDER;                       \
    colorFocused[] = GUI_CO_REARM

#define BTN_COLOR_TYPE_DEFAULT                            \
    colorText[] = GUI_CO_TEXT_LIGHT;                    \
    colorBackground[] = GUI_CO_REARM;             \
    colorBackgroundActive[] = GUI_CO_REARM_HOVER;               \
    colorBackgroundDisabled[] = GUI_CO_REARM;     \
    colorBorder[] = GUI_CO_BORDER;                       \
    colorFocused[] = GUI_CO_REARM
