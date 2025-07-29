class CfgWeapons {
    class JLTS_Z6;
    class SUBCVAR(z6): JLTS_Z6 {
        baseWeapon = QSUBCVAR(z6);
        displayName = SUBCSTRING(z6);
        author = AUTHOR;
        scope = 2;
        scopeArsenal = 2;
        picture = QPATHTOF(data\z6_ca.paa);
        class EventHandlers {
            class SUBADDON {
                fired = QUOTE(_this call SUBFUNC(z6EasterEgg));
            };
        };
    };
};
