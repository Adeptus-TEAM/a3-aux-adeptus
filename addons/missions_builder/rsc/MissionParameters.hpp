class rscMissionParameters {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = QUOTE(_this call SUBFUNC(onLoad););
    onUnload = QUOTE(_this call SUBFUNC(onUnload););
    class ControlsBackground {
        class fullscreenBackground : RscText {
            x = SAFEZONE_X;
            y = SAFEZONE_Y;
            w = SAFEZONE_W;
            h = SAFEZONE_H;
            colorBackground[] = CA_UI_background;
        };
        class background : RscText {
            x = X_COORD(0.29375);
            y = Y_COORD(0.38981482);
            w = W_COORD(0.41302084);
            h = H_COORD(0.28888889);
            colorBackground[] = GUI_BCG_MENU;
        };
        class header : background {
            h = GUI_STD_HEIGHT;
            text = SUBCSTRING(missionParametersText);
            colorBackground[] = GUI_BCG_COLOR;
            colorText[] = GUI_TITLETEXT_COLOR;
        };
        class frame : background {
            style = ST_FRAME;
            colorText[] = GUI_BCG_COLOR;
        };
        class titleMissionName : RscText {
            x = X_COORD(0.30416667);
            y = Y_COORD(0.43148149);
            w = W_COORD(0.27864584);
            h = GUI_STD_HEIGHT;
            text = SUBCSTRING(missionNameText);
            colorBackground[] = CA_UI_transparent;
            colorText[] = GUI_TEXT_COLOR;
        };
        class titleMissionDesc : titleMissionName {
            y = Y_COORD(0.5);
            w = W_COORD(0.39166667);
            text = SUBCSTRING(missionDescText);
        };
        class titlePhase : titleMissionName {
            x = X_COORD(0.59270834);
            w = GUI_STD_WIDTH;
            text = SUBCSTRING(missionPhaseText);
        };
        class titleUnderfireTime : titleMissionName {
            y = Y_COORD(0.56851852);
            w = W_COORD(0.12395834);
            text = SUBCSTRING(missionUnderfireTimeText);
        };
        class titleRespawnButtonTime : titleUnderfireTime {
            x = X_COORD(0.43802084);
            text = SUBCSTRING(missionRespawnButtonTimeText);
        };
        class titlerespawnDelay : titleUnderfireTime {
            x = X_COORD(0.57239584);
            text = SUBCSTRING(missionrespawnDelayText);
        };
    };
    class Controls {
        class textMissionName : RscEdit {
            idc = 1001;
            x = X_COORD(0.30416667);
            y = Y_COORD(0.45833334);
            w = W_COORD(0.27864584);
            h = GUI_STD_HEIGHT;
            autocomplete = "general";
        };
        class textMissionDesc : textMissionName {
            idc = 1002;
            y = Y_COORD(0.52777778);
            w = W_COORD(0.39166667);
        };
        class selectMissionPhase : RscCombo {
            idc = 1003;
            x = X_COORD(0.59270834);
            y = Y_COORD(0.45833334);
            w = GUI_STD_WIDTH;
            h = GUI_STD_HEIGHT;
        };
        class underfireTime : RscEdit {
            idc = 1004;
            x = X_COORD(0.30416667);
            y = Y_COORD(0.5962963);
            w = W_COORD(0.12395834);
            maxChars = 3;
            autocomplete = "";
        };
        class respawnButtonTime : underfireTime {
            idc = 1005;
            x = X_COORD(0.43802084);
        };
        class respawnDelay : underfireTime {
            idc = 1006;
            x = X_COORD(0.57239584);
        };
        class btnCancel : RscButton {
            x = X_COORD(0.47916667);
            y = Y_COORD(0.63703704);
            w = GUI_STD_WIDTH;
            h = GUI_STD_HEIGHT;
            text = ECSTRING(dialogs,btnCancel);
            BTN_COLOR_RED;
            onButtonClick = QUOTE((uiNamespace getVariable [ARR_2('ar_missions_RscMissionParameters',displayNull)]) closeDisplay 2;);
        };
        class btnConfirm : btnCancel {
            x = X_COORD(0.59270834);
            text = ECSTRING(dialogs,btnConfirm);
            BTN_COLOR_GREEN;
            onButtonClick = QUOTE((uiNamespace getVariable [ARR_2('ar_missions_RscMissionParameters',displayNull)]) closeDisplay 1;);
        };
    };
};
