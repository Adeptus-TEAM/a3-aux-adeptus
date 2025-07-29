class RscLaatAirDrop {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = QUOTE(_this call SUBFUNC(onLoad););
    onUnload = QUOTE(_this call SUBFUNC(onUnload););
    class ControlsBackground {
        class background : RscText {
            x = X_COORD(0.29375);
            y = Y_COORD(0.22592593);
            w = W_COORD(0.41197917);
            h = H_COORD(0.54907408);
            colorBackground[] = GUI_BCG_MENU;
        };
        class header : background {
            h = GUI_STD_HEIGHT;
            text = SUBCSTRING(header);
            colorBackground[] = GUI_BCG_COLOR;
            colorText[] = GUI_TITLETEXT_COLOR;
        };
        class frame : background {
            style = ST_FRAME;
            colorText[] = GUI_BCG_COLOR;
        };
        class listSeeSupplyFrame : RscFrame {
			x = X_COORD(0.47916667);
			y = Y_COORD(0.30740741);
			w = W_COORD(0.21666667);
			h = H_COORD(0.15092593);
            colorText[] = GUI_TEXT_COLOR;
        };
        class titleGestSupply : RscText {
			x = X_COORD(0.30416667);
			y = Y_COORD(0.26666667);
			w = W_COORD(0.39166667);
            h = GUI_STD_HEIGHT;
            text = SUBCSTRING(titleGestSupply);
            colorBackground[] = CA_UI_transparent;
            colorText[] = GUI_TEXT_COLOR;
        };
        class titleSetDir : titleGestSupply {
			y = Y_COORD(0.48611112);
            text = SUBCSTRING(titleSetDir);
        };
        class titleSetHeight : titleGestSupply {
			y = Y_COORD(0.61018519);
            text = SUBCSTRING(titleSetHeight);
        };
    };
    class Controls {
        class comboSupply : RscCombo {
            idc = 1001;
			x = X_COORD(0.30416667);
			y = Y_COORD(0.30740741);
			w = W_COORD(0.16510417);
            h = GUI_STD_HEIGHT;
        };
        class listSeeSupply : RscListBox {
            idc = 1002;
            x = X_COORD(0.47916667);
            y = Y_COORD(0.30740741);
            w = W_COORD(0.21666667);
            h = H_COORD(0.15092593);
        };
        class btnAddSupply : RscButton {
			x = X_COORD(0.36614584);
			y = Y_COORD(0.34907408);
            w = GUI_STD_WIDTH;
            h = GUI_STD_HEIGHT;
            text = SUBCSTRING(btnAddSupply);
            BTN_COLOR_GREEN;
            onButtonClick = QUOTE(_this call SUBFUNC(addSupply););
        };
        class btnDeleteSupply : btnAddSupply {
            y = Y_COORD(0.39907408);
            text = SUBCSTRING(btnDeleteSupply);
            BTN_COLOR_RED;
            onButtonClick = QUOTE(_this call SUBFUNC(deleteSupply););
        };
        class sliderSetDir : RscSlider {
            idc = 1003;
            x = X_COORD(0.30416667);
            y = Y_COORD(0.55462963);
            w = W_COORD(0.39166667);
            h = GUI_STD_HEIGHT;
            onSliderPosChanged = QUOTE(_this call SUBFUNC(onSliderSetDirChanged););
        };
        class infoSetDir : RscText {
            idc = 1004;
            x = X_COORD(0.30416667);
            y = Y_COORD(0.52777778);
            w = W_COORD(0.39166667);
            h = GUI_STD_HEIGHT;
            style = ST_CENTER;
            colorBackground[] = CA_UI_transparent;
            colorText[] = GUI_TEXT_COLOR;
        };
        class sliderSetHeight : sliderSetDir {
            idc = 1005;
            y = Y_COORD(0.67870371);
            onSliderPosChanged = QUOTE(_this call SUBFUNC(onSliderSetHeightChanged););
        };
        class infoSetHeight : infoSetDir {
            idc = 1006;
            y = Y_COORD(0.65092593);
        };
        class btnCancel : RscButton {
            x = X_COORD(0.47916667);
            y = Y_COORD(0.73333334);
            w = GUI_STD_WIDTH;
            h = GUI_STD_HEIGHT;
            text = ECSTRING(dialogs,btnCancel);
            BTN_COLOR_RED;
            onButtonClick = QUOTE(closeDialog 2;);
        };
        class btnConfirm : btnCancel {
            x = X_COORD(0.59270834);
            text = ECSTRING(dialogs,btnConfirm);
            BTN_COLOR_GREEN;
            onButtonClick = QUOTE(closeDialog 1;);
        };
    };
};
