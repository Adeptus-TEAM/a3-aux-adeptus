class CfgSoundShaders {
    class SUBCVAR(EMP_closeDetonation_SoundShader){
        samples[] = {
            {QPATHTOF(data\emp_detonation.wss),1}
        };
        volume = 1;
        range=70;
        rangeCurve[] = {{0,1},{50,0.75},{70,0}};
    }; 
    class SUBCVAR(EMP_midDetonation_SoundShader){
        samples[] = {
            {QPATHTOF(data\emp_detonation.wss),1}
        };
        volume = 1;
        range = 2200;
        rangeCurve[] = {{0,1},{100,1},{500,0},{2200,0}};
    }; 
    class SUBCVAR(EMP_distDetonation_SoundShader){
        samples[] = {
            {QPATHTOF(data\emp_detonation.wss),1}
        };
        volume = 1.12202;
        range = 2200;
        rangeCurve[] = {{0,0},{100,0},{250,1},{2200,1}};
    }; 
};
