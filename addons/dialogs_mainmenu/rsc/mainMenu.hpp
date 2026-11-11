/*
 * Adeptus main menu, styled after adeptus-team.eu.
 * The vanilla controls are kept (the engine and RscDisplayMain.sqf need them) but hidden by fnc_onLoad,
 * which also wires hover effects and the Editor / Mods / Options / Profile / Quit buttons.
 * Positions come from the 1600x900 mockup (MX/MY/MW/MH in script_macros.hpp).
 */

class RscStandardDisplay;
class RscDisplayMain : RscStandardDisplay {
    delete Spotlight;
    onLoad = "[""onLoad"",_this,""RscDisplayMain"",'GUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this call (uiNamespace getVariable 'AR_Dialogs_MainMenu_fnc_onLoad')";
    onUnload = "[""onUnload"",_this,""RscDisplayMain"",'GUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); uiNamespace setVariable ['AR_Dialogs_MainMenu_sceneReadyAt', -1]";

    class ControlsBackground {
        // Opaque left side + soft fade over the 3D scene, like the site's hero image
        class SUBCVAR(leftSolid) : RscText {
            x = "safezoneX";
            y = MY(0);
            w = MW(640);
            h = MH(900);
            colorBackground[] = CO_BG;
        };
        class SUBCVAR(leftFade) : RscPicture {
            x = MX(640);
            y = MY(0);
            w = MW(240);
            h = MH(900);
            text = TEX(fade_left_ca.paa);
        };
        // Dark band behind the header, so the buttons stay readable over the scene
        class SUBCVAR(headerBg) : RscText {
            x = "safezoneX";
            y = MY(0);
            w = "safezoneW";
            h = MH(76);
            colorBackground[] = CO_BG_HEADER;
        };
        class SUBCVAR(headerLine) : RscText {
            x = "safezoneX";
            y = MY(76);
            w = "safezoneW";
            h = "pixelH";
            colorBackground[] = CO_LINE;
        };

        // Server rows: background, border, accent bar, texts and "join" picture
        #define SERVER_ROW(i,y0,color,tag,name,desc) \
            class SUBCVAR(DOUBLES(rowBg,i)) : RscText { \
                idc = IDC_ROW_BG(i); \
                x = MX(48); y = MY(y0); w = MW(544); h = MH(96); \
                colorBackground[] = CO_ROW; \
            }; \
            class SUBCVAR(DOUBLES(rowFrame,i)) : SUBCVAR(DOUBLES(rowBg,i)) { \
                idc = -1; \
                style = ST_FRAME; \
                colorBackground[] = CO_NONE; \
                colorText[] = CO_BORDER; \
            }; \
            class SUBCVAR(DOUBLES(rowAccent,i)) : RscText { \
                x = MX(68); y = MY(y0 + 18); w = MW(4); h = MH(60); \
                colorBackground[] = color; \
            }; \
            class SUBCVAR(DOUBLES(rowTag,i)) : RscText { \
                x = MX(88); y = MY(y0 + 14); w = MW(330); h = MH(20); \
                font = FONT_BOLD; sizeEx = MH(13); shadow = 0; \
                colorText[] = color; \
                text = SUBCSTRING(tag); \
            }; \
            class SUBCVAR(DOUBLES(rowName,i)) : SUBCVAR(DOUBLES(rowTag,i)) { \
                y = MY(y0 + 33); h = MH(30); \
                sizeEx = MH(24); \
                colorText[] = CO_WHITE; \
                text = SUBCSTRING(name); \
            }; \
            class SUBCVAR(DOUBLES(rowDesc,i)) : SUBCVAR(DOUBLES(rowTag,i)) { \
                y = MY(y0 + 62); h = MH(20); \
                font = FONT_REG; sizeEx = MH(15); \
                colorText[] = CO_MUTED; \
                text = SUBCSTRING(desc); \
            }; \
            class SUBCVAR(DOUBLES(rowJoin,i)) : RscPicture { \
                idc = IDC_ROW_JOIN(i); \
                x = MX(432); y = MY(y0 + 24); w = MW(140); h = MH(48); \
                text = TEX(btn_fill_ca.paa); \
                colorText[] = CO_BTN; \
            }; \
            class SUBCVAR(DOUBLES(rowJoinText,i)) : RscText { \
                x = MX(432); y = MY(y0 + 24); w = MW(140); h = MH(48); \
                style = ST_CENTER; font = FONT_BOLD; sizeEx = MH(16); shadow = 0; \
                colorText[] = CO_WHITE; \
                text = SUBCSTRING(join); \
            }

        SERVER_ROW(1,184,CO_YELLOW,tagMain,nameMain,descMain);
        SERVER_ROW(2,292,CO_BLUE,tagTraining,nameTraining,descTraining);
        SERVER_ROW(3,400,CO_ORANGE,tagOpex,nameOpex,descOpex);

        // Player name panel (bottom right)
        class SUBCVAR(profileBg) : RscText {
            x = MX(1212);
            y = MY(798);
            w = MW(340);
            h = MH(66);
            colorBackground[] = CO_BG_PANEL;
        };
        class SUBCVAR(profileFrame) : SUBCVAR(profileBg) {
            style = ST_FRAME;
            colorBackground[] = CO_NONE;
            colorText[] = CO_BORDER;
        };
    };

    class Controls {
        delete Spotlight1;
        delete Spotlight2;
        delete Spotlight3;
        delete BackgroundSpotlightRight;
        delete BackgroundSpotlightLeft;
        delete BackgroundSpotlight;
        delete SpotlightNext;
        delete SpotlightPrev;

        // --- Header ---
        class SUBCVAR(logo) : RscPicture {
            x = MX(28);
            y = MY(2);
            w = MW(72);
            h = MH(72);
            style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
            text = TEX(logo_ca.paa);
        };
        // "TEAM" in the Adeptus yellow of the buttons (#D08700, CO_BTN)
        class SUBCVAR(brand) : RscStructuredText {
            x = MX(96);
            y = MY(16);
            w = MW(700);
            h = MH(50);
            size = MH(42);
            text = "61ST ADEPTUS <t color='#D08700'>TEAM</t>";
            shadow = 0;
            colorBackground[] = CO_NONE;
            class Attributes {
                font = FONT_BOLD;
                color = "#FFFFFF";
                align = "left";
                shadow = 0;
            };
        };

        // Vanilla actions, wired in fnc_onLoad (idc 6161 editor, 6162 mods, 6163 options, 6165 quit).
        // The profile is opened from the player name, bottom right.
        #define NAV_BUTTON(i,xpos,label) \
            class SUBCVAR(DOUBLES(nav,i)) : RscButton { \
                idc = 6160 + i; \
                x = MX(xpos); y = MY(16); w = MW(100); h = MH(44); \
                style = ST_CENTER; font = FONT_BOLD; sizeEx = MH(15); \
                text = SUBCSTRING(label); \
                BTN_FLAT(CO_MUTED); \
            }

        NAV_BUTTON(1,1140,navEditor);
        NAV_BUTTON(2,1244,navMods);
        NAV_BUTTON(3,1348,navOptions);
        NAV_BUTTON(5,1452,navQuit);

        // --- Left column ---
        // News panel: a simple HTML page from the website (NEWS_URL), loaded by fnc_onLoad.
        // Arma only renders basic HTML (h1-h6, p, br, b, a): the look comes from here, not from the page.
        class SUBCVAR(newsLabel) : RscText {
            idc = IDC_NEWS_LABEL;
            x = MX(42);
            y = MY(530);
            w = MW(560);
            h = MH(20);
            font = FONT_BOLD;
            sizeEx = MH(13);
            shadow = 0;
            colorText[] = CO_YELLOW;
            text = SUBCSTRING(newsLabel);
        };
        class SUBCVAR(news) : RscHTML {
            idc = IDC_NEWS;
            type = 9;
            style = 0;
            x = MX(48);
            y = MY(554);
            w = MW(544);
            h = MH(260);
            shadow = 0;
            colorBackground[] = CO_NONE;
            colorText[] = CO_TEXT;
            colorBold[] = CO_YELLOW;
            colorLink[] = CO_YELLOW;
            colorLinkActive[] = CO_WHITE;
            sizeEx = MH(16);
            #define NEWS_TAG(tag,tagFont,tagSize,tagAlign) \
                class tag { \
                    font = tagFont; \
                    fontBold = FONT_BOLD; \
                    sizeEx = MH(tagSize); \
                    align = tagAlign; \
                }
            // Titles in bold, like the rest of the menu
            NEWS_TAG(H1,FONT_BOLD,26,"left");
            NEWS_TAG(H2,FONT_BOLD,20,"left");
            NEWS_TAG(H3,FONT_BOLD,18,"left");
            NEWS_TAG(H4,FONT_BOLD,16,"left");
            NEWS_TAG(H5,FONT_REG,16,"left");
            NEWS_TAG(H6,FONT_REG,16,"left");
            NEWS_TAG(P,FONT_REG,16,"left");
        };
        // Shown instead of the news when the page cannot be loaded (no internet, site down)
        class SUBCVAR(newsFallback) : RscText {
            idc = IDC_NEWS_FALLBACK;
            style = ST_MULTI;
            x = MX(42);
            y = MY(554);
            w = MW(560);
            h = MH(60);
            font = FONT_REG;
            sizeEx = MH(16);
            shadow = 0;
            colorText[] = CO_MUTED;
            text = SUBCSTRING(newsFallback);
        };

        // Tagline in the spirit of the site ("bacta" highlighted in blue), text set by fnc_onLoad from the stringtable
        class SUBCVAR(tagline) : RscStructuredText {
            idc = IDC_TAGLINE;
            x = MX(42);
            y = MY(92);
            w = MW(600);
            h = MH(38);
            size = MH(26);
            text = "";
            shadow = 0;
            colorBackground[] = CO_NONE;
            class Attributes {
                font = FONT_BOLD;
                color = "#FFFFFF";
                align = "left";
                shadow = 0;
            };
        };
        class SUBCVAR(deploy) : RscText {
            x = MX(42);
            y = MY(136);
            w = MW(190);
            h = MH(32);
            font = FONT_BOLD;
            sizeEx = MH(25);
            shadow = 0;
            colorText[] = CO_WHITE;
            text = SUBCSTRING(deploy);
        };
        class SUBCVAR(deploySub) : RscText {
            x = MX(292);
            y = MY(141);
            w = MW(300);
            h = MH(28);
            style = ST_RIGHT;
            font = FONT_REG;
            sizeEx = MH(16);
            shadow = 0;
            colorText[] = CO_MUTED;
            text = SUBCSTRING(deploySub);
        };

        // Clickable server rows: the whole row is the button (on top of the row background)
        #define ROW_BUTTON(i,y0) \
            class SUBCVAR(DOUBLES(rowButton,i)) : RscButton { \
                idc = IDC_ROW_BUTTON(i); \
                x = MX(48); y = MY(y0); w = MW(544); h = MH(96); \
                text = ""; \
                tooltip = ""; \
                BTN_FLAT(CO_NONE); \
            }

        ROW_BUTTON(1,184);
        ROW_BUTTON(2,292);
        ROW_BUTTON(3,400);

        // Footer links: buttons with "url", like the vanilla main menu ("Unit" button). fnc_onLoad also sets the url
        // by script (ctrlSetURL), adds the hover color and logs each click in the RPT.
        #define LINK_BUTTON(i,xpos,width,label,linkColor,linkUrl) \
            class SUBCVAR(DOUBLES(link,i)) : RscButton { \
                idc = 6180 + i; \
                x = MX(xpos); y = MY(846); w = MW(width); h = MH(26); \
                style = ST_LEFT; font = FONT_BOLD; sizeEx = MH(14); \
                text = SUBCSTRING(label); \
                url = linkUrl; \
                tooltip = linkUrl; \
                onButtonClick = ""; \
                BTN_FLAT(linkColor); \
            }

        LINK_BUTTON(1,43,80,linkDiscord,CO_DISCORD,"https://discord.com/invite/dPgxPgv");
        LINK_BUTTON(2,129,80,linkSite,CO_MUTED,"https://adeptus-team.eu");
        LINK_BUTTON(3,215,60,linkWiki,CO_MUTED,"https://wiki.adeptus-team.eu");
        LINK_BUTTON(4,281,100,linkTeamspeak,CO_MUTED,"ts3server://ts3.adeptus-team.eu");

        // Options menu (opened by the OPTIONS button): one entry per vanilla options screen, hidden by default
        class SUBCVAR(optionsBg) : RscText {
            idc = IDC_OPTIONS_BG;
            x = MX(1328);
            y = MY(76);
            w = MW(140);
            h = MH(176);
            colorBackground[] = CO_BG_HEADER;
        };
        #define OPTION_BUTTON(i,label) \
            class SUBCVAR(DOUBLES(option,i)) : RscButton { \
                idc = IDC_OPTIONS_BG + i; \
                x = MX(1328); y = MY(76 + 4 + (i - 1) * 42); w = MW(140); h = MH(42); \
                style = ST_CENTER; font = FONT_BOLD; sizeEx = MH(15); \
                text = SUBCSTRING(label); \
                BTN_FLAT(CO_MUTED); \
            }

        OPTION_BUTTON(1,optionsVideo);
        OPTION_BUTTON(2,optionsAudio);
        OPTION_BUTTON(3,optionsControls);
        OPTION_BUTTON(4,optionsGame);

        class SUBCVAR(version) : RscText {
            idc = IDC_VERSION;
            x = MX(392);
            y = MY(846);
            w = MW(200);
            h = MH(26);
            style = ST_RIGHT;
            font = FONT_REG;
            sizeEx = MH(14);
            shadow = 0;
            colorText[] = CO_DIM;
            text = "";
        };

        // --- Right: player name (the soldier itself is in the 3D scene, see fnc_spawnSoldier) ---
        class SUBCVAR(profileName) : RscText {
            idc = IDC_PROFILE_NAME;
            x = MX(1234);
            y = MY(810);
            w = MW(300);
            h = MH(42);
            font = FONT_BOLD;
            sizeEx = MH(26);
            shadow = 0;
            colorText[] = CO_WHITE;
            text = "";
        };
        class SUBCVAR(profileHint) : RscText {
            x = MX(1212);
            y = MY(804);
            w = MW(326);
            h = MH(18);
            style = ST_RIGHT;
            font = FONT_BOLD;
            sizeEx = MH(12);
            shadow = 0;
            colorText[] = CO_MUTED;
            text = SUBCSTRING(profileHint);
        };
        // The whole name panel opens the vanilla profile screen (fnc_onLoad)
        class SUBCVAR(profileButton) : RscButton {
            idc = IDC_PROFILE_BUTTON;
            x = MX(1212);
            y = MY(798);
            w = MW(340);
            h = MH(66);
            text = "";
            colorText[] = CO_NONE;
            colorDisabled[] = CO_NONE;
            colorBackground[] = CO_NONE;
            colorBackgroundActive[] = { 1, 1, 1, 0.05 };
            colorBackgroundDisabled[] = CO_NONE;
            colorFocused[] = { 1, 1, 1, 0.05 };
            colorShadow[] = CO_NONE;
            colorBorder[] = CO_NONE;
            shadow = 0;
            borderSize = 0;
            offsetX = 0;
            offsetY = 0;
            offsetPressedX = 0;
            offsetPressedY = 0;
        };

        // --- Opening sequence (fnc_introTick): black screen, logo + title, then the menu appears ---
        // Last in the list so they are drawn over everything
        class SUBCVAR(introBlack) : RscText {
            idc = IDC_INTRO_BLACK;
            x = "safezoneX";
            y = "safezoneY";
            w = "safezoneW";
            h = "safezoneH";
            colorBackground[] = { 0, 0, 0, 1 };
        };
        class SUBCVAR(introLogo) : RscPicture {
            idc = IDC_INTRO_LOGO;
            x = MX(760);
            y = MY(300);
            w = MW(80);
            h = MH(80);
            style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
            text = TEX(logo_ca.paa);
        };
        class SUBCVAR(introTitle) : RscStructuredText {
            idc = IDC_INTRO_TITLE;
            x = MX(300);
            y = MY(440);
            w = MW(1000);
            h = MH(80);
            size = MH(56);
            text = "61ST ADEPTUS <t color='#D08700'>TEAM</t>";
            shadow = 0;
            colorBackground[] = CO_NONE;
            class Attributes {
                font = FONT_BOLD;
                color = "#FFFFFF";
                align = "center";
                shadow = 0;
            };
        };
        class SUBCVAR(introLine) : RscText {
            idc = IDC_INTRO_LINE;
            x = MX(800);
            y = MY(526);
            w = MW(0);
            h = MH(3);
            colorBackground[] = CO_YELLOW;
        };
    };
};
