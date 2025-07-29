class CfgWeapons {
    class JLTS_icecream;
    class JLTS_icecream_base : JLTS_icecream {
        scope = 0;
        scopeArsenal = 0;
        class ItemInfo;
    };

    class SUBCVAR(item) : JLTS_icecream_base {
        displayName = SUBCSTRING(item);
        icon = QPATHTOF(data\icons\respawnBeacon_item_ca.paa);
        descriptionShort = SUBCSTRING(item_desc);
        scope = 2;
        scopeArsenal = 2;
        author = AUTHOR;
        class ItemInfo : ItemInfo {
            mass = 100;
        };
    };
};
