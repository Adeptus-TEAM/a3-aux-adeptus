class RscControlsGroup{};
class RscControlsGroupNoScrollbars: RscControlsGroup {};

class RscDisplayDynamicGroups
{
    onLoad="[""onLoad"",_this,""RscDisplayDynamicGroups"",'GUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); [_this select 0] call ar_dialogs_dynamicgroups_fnc_onload;";
    class Controls
    {
        class SectionManage : RscControlsGroupNoScrollbars
        {
            class Controls
            { 
                class Left: RscButton
                {
                    idc = 11178;
                    x = QUOTE(12.3 * GUI_GRID_W);
                    y = QUOTE(4.15 * GUI_GRID_H);
                    w = QUOTE(0.6 * GUI_GRID_W);
                    h = QUOTE(0.7 * GUI_GRID_H);
                    text = "<";
                    onButtonClick=QUOTE(['left'] call SUBFUNC(onButtonPressed));
                    colorBackground[] = {0,0,0,0};
                    colorBackgroundActive[] = {0,0,0,0.5};
					colorFocused[] = {0,0,0,0};
                    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
                    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
                    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
                    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
                };
                class Right: RscButton
                {
                    idc = 11179;
                    x = QUOTE(18.6* GUI_GRID_W);
                    y = QUOTE(4.15 * GUI_GRID_H);
                    w = QUOTE(0.6 * GUI_GRID_W);
                    h = QUOTE(0.7 * GUI_GRID_H);
                    text = ">";
                    onButtonClick=QUOTE(['right'] call SUBFUNC(onButtonPressed));
                    colorBackground[] = {0,0,0,0};
                    colorBackgroundActive[] = {0,0,0,0.5};
					colorFocused[] = {0,0,0,0};
                    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
                    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
                    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
                    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
                };
            };
        };
    };
};
