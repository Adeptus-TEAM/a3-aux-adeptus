class RscDisplayOptionsAudio
{
	onLoad = "[""onLoad"",_this,""RscDisplayOptionsAudio"",'GUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); [_this select 0] call ar_dialogs_optionsaudio_fnc_onLoad;";
	class controls
	{
		class VolumeGroup: RscControlsGroup
		{
			class controls
			{
				class CA_SliderEnvVolume: RscXSliderH
				{
					idc = 115100;
					x = QUOTE(8 * GUI_GRID_W);
					y = QUOTE(17 * GUI_GRID_H);
					w = QUOTE(15 * GUI_GRID_W);
					h = QUOTE(1 * GUI_GRID_H);
					tooltip = SUBCSTRING(SliderEnvVolume);
					colorBackground[] = {0,0,0,0.5};
					onSliderPosChanged = QUOTE(_this call SUBFUNC(onEnvVolumeChanged));
				};
				class CA_TextEnvVolume: RscText
				{
					idc = 115101;
					style = 1;
					x = QUOTE(0 * GUI_GRID_W);
					y = QUOTE(17 * GUI_GRID_H);
					w = QUOTE(8 * GUI_GRID_W);
					h = QUOTE(1 * GUI_GRID_H);
					text = SUBCSTRING(TextEnvVolume);
				};
			};
		};
	};
};

