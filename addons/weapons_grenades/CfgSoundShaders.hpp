class CfgSoundShaders {
    class SUBCVAR(EMP_Detonation_SoundShader){
        samples[] = {
            {QPATHTOF(data\emp_detonation.wav),1}
        };
        volume = 1;
        range=70;
        rangeCurve[] = {{0,1},{50,0.75},{70,0}};
    }; 
};
