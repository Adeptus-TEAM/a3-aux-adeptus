class CfgSoundSets{
    class SUBCVAR(EMP_Detonation_SoundSet){
        soundShaders[] = {
            QSUBCVAR(EMP_Detonation_SoundShader)
        };
        spatial = 1;
        volumeCurve = "InverseSquare2Curve";
        volumeFactor = 1;
        loop = 0;
        doppler = 0;
        distanceFilter = "explosionDistanceFreqAttenuationFilter";
    };
};
