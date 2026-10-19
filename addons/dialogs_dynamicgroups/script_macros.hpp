#ifndef GUI_GRID_WAbs
	#define GUI_GRID_WAbs ((safezoneW / safezoneH) min 1.2)
#endif
#ifndef GUI_GRID_HAbs
	#define GUI_GRID_HAbs (GUI_GRID_WAbs / 1.2)
#endif
#ifndef GUI_GRID_W
	#define GUI_GRID_W (GUI_GRID_WAbs / 40)
#endif
#ifndef GUI_GRID_H
	#define GUI_GRID_H (GUI_GRID_HAbs / 25)
#endif
#ifndef GUI_GRID_CENTER_X
	#define GUI_GRID_CENTER_X (safezoneX + (safezoneW - GUI_GRID_WAbs)/2)
#endif
#ifndef GUI_GRID_CENTER_Y
	#define GUI_GRID_CENTER_Y (safezoneY + (safezoneH - GUI_GRID_HAbs)/2)
#endif
