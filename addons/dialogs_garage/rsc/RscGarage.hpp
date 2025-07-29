class RscGarage {
	idd = -1;
	onLoad = QUOTE(_this call SUBFUNC(onLoad));
	class ControlsBackground {
		class background : RscText {
			x = X_COORD(0.29375);
			y = Y_COORD(0.225);
			w = W_COORD(0.4125);
			h = H_COORD(0.55);
			colorBackground[] = GUI_BCG_MENU;
		};
        class frame : background {
            style = ST_FRAME;
            colorText[] = GUI_BCG_COLOR;
        };
		class header : background {
			h = GUI_STD_HEIGHT;
			text = SUBCSTRING(header);
			colorBackground[] = GUI_BCG_COLOR;
            colorText[] = GUI_TITLETEXT_COLOR;
		};
		class DisplayVehicleImage : RscPicture {
			idc = 1000;
			x = X_COORD(0.34583334);
			y = Y_COORD(0.3175926);
			w = W_COORD(0.309375);
			h = H_COORD(0.31666667);
			text = QPATHTOF(data\notFound_co.jpg);
		};
		class DisplayVehicleImageFrame : DisplayVehicleImage {
			style = ST_FRAME;
			colorText[] = GUI_BCG_COLOR;
		};
		class DisplayName : RscText {
			idc = 1001;
			style = 2;
			x = X_COORD(0.396875);
			y = Y_COORD(0.2712963);
			w = W_COORD(0.20625);
			h = H_COORD(0.02777778);
		};
	};
	class Controls {
		class ButtonSelectionRight : RscShortcutButton {
			x = X_COORD(0.66510417);
			y = Y_COORD(0.45833334);
			w = W_COORD(0.02083334);
			h = H_COORD(0.04166667);
			BTN_CA_ARROW_RIGHT;
			onButtonClick = QUOTE(_this call SUBFUNC(selectionRightButton););
		};
		class ButtonSelectionLeft : ButtonSelectionRight {
			x = X_COORD(0.3140625);
			y = Y_COORD(0.45833334);
			BTN_CA_ARROW_LEFT;
			onButtonClick = QUOTE(_this call SUBFUNC(selectionLeftButton););
		};
		class SpawnButton : RscButton {
			x = X_COORD(0.4484375);
			y = Y_COORD(0.66481482);
			w = GUI_STD_WIDTH;
			h = GUI_STD_HEIGHT;
			BTN_OFFSET_PRESSED;
			text = SUBCSTRING(btnSpawn);
			BTN_COLOR_DEFAULT;
			onButtonClick = QUOTE(_this call SUBFUNC(spawnVehicle););
		};
		class RearmButton : SpawnButton {
			x = X_COORD(0.56197917);
			y = Y_COORD(0.66481482);
			text = SUBCSTRING(btnRearm);
			BTN_COLOR_GREEN;
			onButtonClick=QUOTE(_this call SUBFUNC(rearmVehicle););
		};
		class PylonButton : SpawnButton {
			x = X_COORD(0.33489584);
			y = Y_COORD(0.66481482);
			text = SUBCSTRING(btnPylon);
			BTN_COLOR_PURPLE;
			onButtonClick=QUOTE(_this call SUBFUNC(pylonsVehicle););
		};
		class DeleteButton : SpawnButton {
			x = X_COORD(0.4484375);
			y = Y_COORD(0.70648149);
			text = SUBCSTRING(btnDelete);
			BTN_COLOR_RED;
			onButtonClick=QUOTE(_this call SUBFUNC(deleteVehicle););
		};
	};
};
