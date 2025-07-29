class CfgMods {
    class Mod_Base;
    class AdeptusRepublica : Mod_Base {
        name = QUOTE(MOD_NAME);
        tooltip = QUOTE(MOD_NAME);
        tooltipOwned = QUOTE(MOD_NAME);
        author = AUTHOR;
        picture = QPATHTOF(data\logo_ca.paa);
        logo = QPATHTOF(data\logo_ca.paa);
        logoOver = QPATHTOF(data\logo_ca.paa);
        logoSmall = QPATHTOF(data\logo_ca.paa);
        actionName = CSTRING(actionName);
        action = CSTRING(url);
        overview = CSTRING(overview);
        hideName = FALSE;
        hidePicture = FALSE;
        dlcColor[] = ADEPTUS_COLOR;
        VERSION_CONFIG;
    };
};
