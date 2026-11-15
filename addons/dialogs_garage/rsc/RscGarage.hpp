class RscGarage
{
	idd = -1;
	onLoad = QUOTE(_this call SUBFUNC(onLoad));

	class ControlsBackground
	{
		class background : RscText
		{
			x = X_COORD(0.29375);
			y = Y_COORD(0.225);
			w = W_COORD(0.4125);
			h = H_COORD(0.55);
			colorBackground[] = GUI_CO_OVERLAY ;
			
		};
		class header : background
		{
			x = X_COORD(0.29375);
			y = Y_COORD(0.225);
			w = W_COORD(0.4125);
			h = H_COORD(0.02777778);
			colorText[] = GUI_CO_TEXT_WHITE;
			text = SUBCSTRING(header);
		};
		class TypeCategoryText: background
		{
			x = X_COORD(0.596875);
			y = Y_COORD(0.43148149);
			w = W_COORD(0.109375);
			h = H_COORD(0.02777778);
			sizeEx = H_COORD(0.015);
			style = ST_LEFT;
			text = "Types";
			colorText[] = GUI_CO_TEXT_LIGHT;
			colorBackground[] = GUI_CO_TRANSPARENT;
			
		};
		class backgroundFrame : background
		{
            style = ST_FRAME;
			x = X_COORD(0.29427084);
			y = Y_COORD(0.225);
			w = W_COORD(0.4125);
			h = H_COORD(0.55);
			colorText[] = GUI_CO_BORDER_ACTIVE;
		};
        class headerFrame : backgroundFrame
		{
			x = X_COORD(0.29375);
			y = Y_COORD(0.225);
			w = W_COORD(0.4125);
			h = H_COORD(0.02777778);
		};
		class displayColumnFrame : backgroundFrame
		{
			x = X_COORD(0.596875);
			y = Y_COORD(0.25277778);
			w = W_COORD(0.109375);
			h = H_COORD(0.11018519);
			
		};
		class buttonsColumnFrame : backgroundFrame
		{
			x = X_COORD(0.596875);
			y = Y_COORD(0.6925926);
			w = W_COORD(0.109375);
			h = H_COORD(0.08240741);
		};
		class InfoVehicleColumnFrame : backgroundFrame
		{
			x = X_COORD(0.596875);
			y = Y_COORD(0.36296297);
			w = W_COORD(0.109375);
			h = H_COORD(0.06944445);
		};
		class TypeVehicleColumnFrame : backgroundFrame
		{
			x = X_COORD(0.596875);
			y = Y_COORD(0.43148149);
			w = W_COORD(0.109375);
			h = H_COORD(0.26111112);
		};
	};
    
	class Controls
	{

		class DisplayVehicleImage : RscPicture {
			idc = 1000;
			x = X_COORD(0.59739584);
			y = Y_COORD(0.25370371);
			w = W_COORD(0.1078125);
			h = H_COORD(0.10925926);
			text = QPATHTOF(data\notFound_co.jpg);
		};
		class DisplayName : RscText
		{
			idc = 1001;
			x = X_COORD(0.603125);
			y = Y_COORD(0.37592593);
			w = W_COORD(0.096875);
			h = H_COORD(0.04444445);
			style = ST_CENTER;
            colorText[] = GUI_CO_TEXT_WHITE;
		};
        class VehicleList : RscListBox
		{
			type = 5;
			style = 0;
			idc = 1003;
			x = X_COORD(0.29791667);
			y = Y_COORD(0.26018519);
			w = W_COORD(0.29270834);
			h = H_COORD(0.50925926);
			font = "PuristaMedium";
            colorText[] = GUI_CO_TEXT_WHITE;
            colorBackground[] = GUI_CO_LISTBOX;
            colorSelect[] = GUI_CO_TEXT_WHITE;
            colorSelect2[] = GUI_CO_TEXT_WHITE;
            colorSelectBackground[] = GUI_CO_SELECTED;
            colorSelectBackground2[] = GUI_CO_SELECTED;
            colorActive[] = GUI_CO_TEXT_WHITE;
			soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1.0};
			rowHeight = H_COORD(0.05);
			colorScrollbar[] = { RGB_CO_BLUE, 0.30 };
			period = 0;
			shadow = 0;
			onMouseButtonClick = QUOTE(0 call SUBFUNC(updateDisplayVehicle););
		};
		class CloseButton : RscButton
		{
			x = X_COORD(0.6915);
			y = Y_COORD(0.23);
			w = W_COORD(0.0109375);
			h = H_COORD(0.02037038);
            sizeEx = H_COORD(0.02);
			text = "X";
            colorText[] = GUI_CO_TEXT_WHITE;
            colorBackground[] = GUI_CO_TRANSPARENT;
            colorBackgroundActive[] = GUI_CO_HOVER;
            colorFocused[] = GUI_CO_TRANSPARENT;
            onButtonClick = "closeDialog 0;";
		};
		class SpawnButton : RscButton
		{
			x = X_COORD(0.60104167);
			y = Y_COORD(0.70277778);
			w = W_COORD(0.04739584);
			h = H_COORD(0.02777778);
            text = SUBCSTRING(btnSpawn);
            font = "PuristaMedium";
            sizeEx = H_COORD(0.02);
            BTN_COLOR_SPAWN;
            BTN_OFFSET_PRESSED;
			onButtonClick = QUOTE(_this call SUBFUNC(spawnVehicle););
		};
        
		class DeleteButton : SpawnButton
		{
			x = X_COORD(0.6546875);
			y = Y_COORD(0.70277778);
			w = W_COORD(0.04739584);
			h = H_COORD(0.02777778);
            text = SUBCSTRING(btnDelete);
            BTN_COLOR_DELETE;
            BTN_OFFSET_PRESSED;
			onButtonClick=QUOTE(_this call SUBFUNC(deleteVehicle););
			
		};
		class RearmButton : SpawnButton
		{
			x = X_COORD(0.6546875);
			y = Y_COORD(0.74166667);
			w = W_COORD(0.04739584);
			h = H_COORD(0.02777778);
			text = SUBCSTRING(btnRearm);
            BTN_COLOR_REARM;
            BTN_OFFSET_PRESSED;
			onButtonClick=QUOTE(_this call SUBFUNC(rearmVehicle););
		};
		class PylonButton : SpawnButton
		{
			x = X_COORD(0.60104167);
			y = Y_COORD(0.74166667);
			w = W_COORD(0.04739584);
			h = H_COORD(0.02777778);
			text = SUBCSTRING(btnPylon);
            BTN_COLOR_PYLON;
            BTN_OFFSET_PRESSED;
			onButtonClick=QUOTE(_this call SUBFUNC(pylonsVehicle););
		};
		class TerrestrialVehicleTypeButton : RscButton
		{
            style = ST_LEFT;
			x = X_COORD(0.596875);
			y = Y_COORD(0.45833334);
			w = W_COORD(0.109375);
			h = H_COORD(0.04166667);
            sizeEx = H_COORD(0.02);
			text = SUBCSTRING(btnTerrestrial);
            BTN_COLOR_TYPE_DEFAULT;
			//font = "PuristaMedium";
            BTN_OFFSET_PRESSED;
			onButtonClick = QUOTE([0] call SUBFUNC(typeSelection););

		};
		class AerialVehicleTypeButton : TerrestrialVehicleTypeButton
		{
			x = X_COORD(0.596875);
			y = Y_COORD(0.5);
			w = W_COORD(0.109375);
			h = H_COORD(0.04166667);
			text = SUBCSTRING(btnAerial);
			onButtonClick = QUOTE([1] call SUBFUNC(typeSelection););
		};
		class SupplyVehicleTypeButton : TerrestrialVehicleTypeButton
		{

			x = X_COORD(0.596875);
			y = Y_COORD(0.54166667);
			w = W_COORD(0.109375);
			h = H_COORD(0.04166667);
			text = SUBCSTRING(btnSupply);
			onButtonClick = QUOTE([2] call SUBFUNC(typeSelection););
		};
	};
	
};
