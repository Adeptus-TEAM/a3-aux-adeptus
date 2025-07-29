["", [worldName, (getPosATL cam_pos), (getDir cam_pos), 0.75, [-1.17921, 0], 0, 0, 265.831, 1, 0, 1, 0, 1]] call BIS_fnc_camera;

showChat false;
enableEnvironment false;
showCinemaBorder false;
showHUD false;
setAperture -1;
setViewDistance 200;

"colorCorrections" ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 0.24], [1, 1, 1, 0], [0.7, 0.7, 0, 0, -0.1, 0.4, 0.8]];
"colorCorrections" ppEffectEnable true;
"colorCorrections" ppEffectCommit 0;

_musiclist = ["AMP_ATMO_Music_23", "AMP_EPIC_Music_32"];

0 fadeMusic 1;
playMusic (selectRandom _musiclist);
addMusicEventHandler ["MusicStop", {
	0 fadeMusic 1;
	playMusic (selectRandom _musiclist);
}];
