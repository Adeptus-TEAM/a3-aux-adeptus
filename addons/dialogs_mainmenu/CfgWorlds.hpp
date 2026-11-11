#define MENU_CUTSCENES cutscenes[] = { QCVAR(intro1_P2_VR) }
#define WORLD_CUTSCENE(map,terrain) \
    class map : terrain {           \
        MENU_CUTSCENES;            \
    }

class CfgWorlds {
    class CAWorld;
    initWorld = "VR";
    demoWorld = "VR";
    // Mod: @ace
    // requiredAddons: "A3_Map_Stratis", "A3_Map_Altis", "A3_Data_F_Exp"
        WORLD_CUTSCENE(VR,CAWorld);
        WORLD_CUTSCENE(Stratis,CAWorld);
        WORLD_CUTSCENE(Altis,CAWorld);
        WORLD_CUTSCENE(Tanoa,CAWorld);

    // Mod: @CUP Terrains - CWA
    // requiredAddons: "CUP_Worlds_Intros"
        WORLD_CUTSCENE(Noe,CAWorld);

    // Mod: @Gliese 581x (East)
    // requiredAddons: "egl_gliese581xeast"
        WORLD_CUTSCENE(egl_gliese581xeast,CAWorld);

    // Mod: @Gliese 581x [ALPHA]
    // requiredAddons: "egl_gliese"
        WORLD_CUTSCENE(egl_gliese,CAWorld);

    // Mod: @Miranda
    // requiredAddons: "egl_miranda"
        WORLD_CUTSCENE(egl_miranda,CAWorld);

    // Mod: @[61St] - Adeptus Maps Pack
    // requiredAddons: "bsoc_brasil", "juju_kalahari", "pja319", "A3_Map_Abramia", "A3_Map_IslaDuala3", "A3_Map_lingor3", "A3_Map_Winthera3", "pja310", "pja305", "pja308", "pja314", "ibr_panthera_c", "A3_Map_dingor", "eladeen_terrain"
        WORLD_CUTSCENE(bsoc_brasil,CAWorld);
        WORLD_CUTSCENE(juju_kalahari,Stratis);
        WORLD_CUTSCENE(pja319,CAWorld);
        WORLD_CUTSCENE(abramia,Stratis);
        WORLD_CUTSCENE(IslaDuala3,Stratis);
        WORLD_CUTSCENE(lingor3,Stratis);
        WORLD_CUTSCENE(winthera3,Stratis);
        WORLD_CUTSCENE(pja310,CAWorld);
        WORLD_CUTSCENE(pja305,CAWorld);
        WORLD_CUTSCENE(pja308,CAWorld);
        WORLD_CUTSCENE(pja314,CAWorld);
        WORLD_CUTSCENE(panthera3,Stratis);
        WORLD_CUTSCENE(dingor,Stratis);
        WORLD_CUTSCENE(eladeen_terrain,Stratis);

    // Mod: @Operation TREBUCHET
    // requiredAddons: "OPTRE_Gridlock", "OPTRE_Harvest", "OPTRE_Iberius", "OPTRE_Kholo", "OPTRE_Madrigal", "OPTRE_Roost", "OPTRE_Sandstorm", "OPTRE_Phobos", "OPTRE_Core", "OPTRE_EridanusSecundus"
        WORLD_CUTSCENE(OPTRE_Gridlock,Stratis);
        WORLD_CUTSCENE(OPTRE_Harvest,CAWorld);
        WORLD_CUTSCENE(OPTRE_iberius,Stratis);
        WORLD_CUTSCENE(OPTRE_Kholo,CAWorld);
        WORLD_CUTSCENE(OPTRE_Madrigal,CAWorld);
        WORLD_CUTSCENE(OPTRE_Roost,CAWorld);
        WORLD_CUTSCENE(OPTRE_Sandstorm,Stratis);
        WORLD_CUTSCENE(OPTRE_Phobos,Altis);
        WORLD_CUTSCENE(Blood_OPTRE,CAWorld);
        WORLD_CUTSCENE(OPTRE_EridanusSecundus,Stratis);

    // Mod: @Gliese 581x (North)
    // requiredAddons: "egl_gliese581xnorth"
        WORLD_CUTSCENE(egl_gliese581xnorth,CAWorld);

    // Mod: @Operation TREBUCHET First Contact
    // requiredAddons: "OPTRE_Arcadia", "OPTRE_Archipelago", "OPTRE_Installation04_config", "OPTRE_Snowlands", "OPTRE_Wetlands", "OPTRE_Glassed"
        WORLD_CUTSCENE(OPTRE_Arcadia,CAWorld);
        WORLD_CUTSCENE(OPTRE_Archipelago,CAWorld);
        WORLD_CUTSCENE(OPTRE_Installation04,CAWorld);
        WORLD_CUTSCENE(OPTRE_Snowlands,CAWorld);
        WORLD_CUTSCENE(OPTRE_Wetlands,CAWorld);
        WORLD_CUTSCENE(Glassed,CAWorld);

    // Mod: @RE- CUP Terrains
    // requiredAddons: "CUP_Desert_Config", "CUP_Hotfix_Config", "CUP_CA_QGClutterHotfix", "CUP_Saralite_Config", "CUP_Utes_Config", "CUP_Chernarus_Config", "CUP_Chernarus_Summer_Config", "CUP_Desert2_Config", "CUP_Takistan_Config", "CUP_Zargabad_Config", "CUP_Afghan_Config", "CUP_Bohemia_Config", "CUP_Bootcamp_acr_Config", "CUP_Desert_e_Config", "CUP_Provinggrounds_pmc_Config", "CUP_Shapur_baf_Config", "CUP_Worlds_Intros"
        WORLD_CUTSCENE(Intro,CAWorld);
        WORLD_CUTSCENE(Sara,CAWorld);
        WORLD_CUTSCENE(Sara_DBE1,CAWorld);
        WORLD_CUTSCENE(SaraLite,CAWorld);
        WORLD_CUTSCENE(Utes,CAWorld);
        WORLD_CUTSCENE(Chernarus,CAWorld);
        WORLD_CUTSCENE(Chernarus_Summer,CAWorld);
        WORLD_CUTSCENE(Porto,CAWorld);
        WORLD_CUTSCENE(Takistan,CAWorld);
        WORLD_CUTSCENE(Zargabad,CAWorld);
        WORLD_CUTSCENE(Mountains_ACR,CAWorld);
        WORLD_CUTSCENE(Woodland_ACR,CAWorld);
        WORLD_CUTSCENE(Bootcamp_ACR,CAWorld);
        WORLD_CUTSCENE(Desert_E,CAWorld);
        WORLD_CUTSCENE(ProvingGrounds_PMC,CAWorld);
        WORLD_CUTSCENE(Shapur_BAF,CAWorld);
        WORLD_CUTSCENE(Chernarus_Winter,CAWorld);

    // Mod: @Legion Studios - Star Wars Battlefields
    // requiredAddons: "lsb_terrain_geonosis2", "lsb_terrain_geonosis", "Jabiim"
        WORLD_CUTSCENE(lsb_terrain_geonosis2,CAWorld);
        WORLD_CUTSCENE(lsb_terrain_geonosis,CAWorld);
        WORLD_CUTSCENE(Jabiim,CAWorld);

    // Mod: @CUP Terrains - Maps 2.0
    // requiredAddons: "CUP_Chernarus_A3_Config", "CUP_Zargabad_A3_c"
        WORLD_CUTSCENE(CUP_Chernarus_A3,Stratis);
        WORLD_CUTSCENE(cup_Zargabad_a3,CAWorld);

    // Mod: @CUP Terrains - Core
    // requiredAddons: "CUP_Terrains_Abel", "CUP_Intro_Config", "CUP_Terrains_Cain", "CUP_Terrains_Eden", "CUP_Worlds_Ambient", "CUP_Worlds_Intros"
        WORLD_CUTSCENE(Abel,CAWorld);
        WORLD_CUTSCENE(Desert_Island,CAWorld);
        WORLD_CUTSCENE(Cain,CAWorld);
        WORLD_CUTSCENE(Eden,CAWorld);
        WORLD_CUTSCENE(daraisolas,Intro);
        WORLD_CUTSCENE(Drago,CAWorld);
        WORLD_CUTSCENE(ElephantIsland,Utes);
        WORLD_CUTSCENE(GIMAP,Intro);
        WORLD_CUTSCENE(GNT_Sands,CAWorld);
        WORLD_CUTSCENE(Brik2,CAWorld);
        WORLD_CUTSCENE(Pomegratskaya_w,CAWorld);
        WORLD_CUTSCENE(OPX_RE,Intro);
        WORLD_CUTSCENE(SampleMap,CAWorld);
        WORLD_CUTSCENE(watkins,CAWorld);
        WORLD_CUTSCENE(Zedka,Intro);
        WORLD_CUTSCENE(SALTBEACH,CAWorld);
        WORLD_CUTSCENE(Sarve,CAWorld);
        WORLD_CUTSCENE(tolafarush,CAWorld);
        WORLD_CUTSCENE(uhao,CAWorld);
        WORLD_CUTSCENE(cl_training,Intro);
        WORLD_CUTSCENE(cmr_cicada,CAWorld);
        WORLD_CUTSCENE(dbb_lampedusa,CAWorld);
        WORLD_CUTSCENE(DBO_afghan,CAWorld);
        WORLD_CUTSCENE(isla_del_jonas,CAWorld);
        WORLD_CUTSCENE(gott_islands,Intro);
        WORLD_CUTSCENE(Klurs_Land,CAWorld);
        WORLD_CUTSCENE(kulima,Chernarus);
        WORLD_CUTSCENE(LCCE_Island,CAWorld);
        WORLD_CUTSCENE(LDDK_Isle,CAWorld);
        WORLD_CUTSCENE(MAP_SSara,CAWorld);
        WORLD_CUTSCENE(McNSaraLiteDryite,CAWorld);
        WORLD_CUTSCENE(Pomegrat,CAWorld);
        WORLD_CUTSCENE(Thirsk,CAWorld);
        WORLD_CUTSCENE(SaraLiteDry2,CAWorld);
        WORLD_CUTSCENE(yanutha,CAWorld);
        WORLD_CUTSCENE(ACE_Everon,CAWorld);
        WORLD_CUTSCENE(Antarctica,Intro);
        WORLD_CUTSCENE(bet_hurtgen,CAWorld);
        WORLD_CUTSCENE(bet_hurtgensnow,CAWorld);
        WORLD_CUTSCENE(bet_nomeisland,CAWorld);
        WORLD_CUTSCENE(bet_snowisland,CAWorld);
        WORLD_CUTSCENE(border,CAWorld);
        WORLD_CUTSCENE(borderlite,CAWorld);
        WORLD_CUTSCENE(FDF_Isle1_a,CAWorld);
        WORLD_CUTSCENE(FDF_Isle1,CAWorld);
        WORLD_CUTSCENE(ic_barbuda,CAWorld);
        WORLD_CUTSCENE(Kolgujev2010,CAWorld);
        WORLD_CUTSCENE(plr_mana,Chernarus);
        WORLD_CUTSCENE(Nicosia,CAWorld);
        WORLD_CUTSCENE(Celle,CAWorld);
        WORLD_CUTSCENE(tropica,CAWorld);
        WORLD_CUTSCENE(MBG_Kellu,CAWorld);
        WORLD_CUTSCENE(usec_aoraki,Takistan);
        WORLD_CUTSCENE(cindercity,Chernarus);
        WORLD_CUTSCENE(Testfield,CAWorld);
        WORLD_CUTSCENE(MBG_Nam,Chernarus);
        WORLD_CUTSCENE(IsolaDiCapraia,Utes);
        WORLD_CUTSCENE(Vostok,CAWorld);
        WORLD_CUTSCENE(Vostok_w,CAWorld);
        WORLD_CUTSCENE(esbekistan,CAWorld);
        WORLD_CUTSCENE(PMC_desert_51km,Intro);
        WORLD_CUTSCENE(PMC_aec,Intro);
        WORLD_CUTSCENE(HDT_island,Intro);
        WORLD_CUTSCENE(namalsk,Utes);
        WORLD_CUTSCENE(tigeria,Utes);
        WORLD_CUTSCENE(Tigeria_se,Utes);
        WORLD_CUTSCENE(hotze_base,CAWorld);
        WORLD_CUTSCENE(everon2010,hotze_base);
        WORLD_CUTSCENE(malden2010,hotze_base);
        WORLD_CUTSCENE(nogova2010,hotze_base);
        WORLD_CUTSCENE(gsep_mosch,Utes);
        WORLD_CUTSCENE(mb_manaisland,Utes);
        WORLD_CUTSCENE(Sbrodj,Utes);
        WORLD_CUTSCENE(Yapal,Utes);
        WORLD_CUTSCENE(SHL_Heighland,Utes);
        WORLD_CUTSCENE(skarikiska,Utes);
        WORLD_CUTSCENE(tavi,Utes);
        WORLD_CUTSCENE(AfghanValley,Utes);
        WORLD_CUTSCENE(Chimalpopoca,Utes);
        WORLD_CUTSCENE(EtahPlateau,Utes);
        WORLD_CUTSCENE(Faffindale,Utes);
        WORLD_CUTSCENE(LoloNaia,Utes);
        WORLD_CUTSCENE(PMC_desert_204km,CAWorld);
        WORLD_CUTSCENE(PMC_oceanworld,PMC_desert_204km);
        WORLD_CUTSCENE(PMC_mog,PMC_desert_51km);
        WORLD_CUTSCENE(Japahto,Chernarus);
        WORLD_CUTSCENE(ThirskW,CAWorld);
        WORLD_CUTSCENE(ACE_DES_Everon,ACE_Everon);
        WORLD_CUTSCENE(ACE_ARMAWOOD_Everon,ACE_Everon);
        WORLD_CUTSCENE(cmr_ovaron,Chernarus);
        WORLD_CUTSCENE(queshkibrul,Chernarus);
        WORLD_CUTSCENE(Lingor,Chernarus);
        WORLD_CUTSCENE(belsebub03,Chernarus);
        WORLD_CUTSCENE(isladuala,Utes);
        WORLD_CUTSCENE(jadegroove,Utes);
        WORLD_CUTSCENE(Panthera2,Utes);
        WORLD_CUTSCENE(clafghan,CAWorld);
        WORLD_CUTSCENE(MCN_Aliabad,CAWorld);
        WORLD_CUTSCENE(hellskitchen,Takistan);
        WORLD_CUTSCENE(torabora,Takistan);
        WORLD_CUTSCENE(TUP_Qom,Takistan);
        WORLD_CUTSCENE(2km_Test,Takistan);
        WORLD_CUTSCENE(2kmx4m_Test,Takistan);
        WORLD_CUTSCENE(MCN_HazarKot,Takistan);

    // Mod: @Gliese581x (South)
    // requiredAddons: "egl_gliese581xsouth"
        WORLD_CUTSCENE(egl_gliese581xsouth,CAWorld);

    // Mod: @Scion Conflict Reborn
    // requiredAddons: "jns_Ritov_terrain"
        WORLD_CUTSCENE(jns_Ritov,CAWorld);

    // Mod: @3AS (Beta Test)
    // requiredAddons: "3as_Tatooine", "3AS_Sullust", "A3_Map_Malden", "A3_Sounds_F_Enoch", "Kamino", "3AS_Orto_Plut", "3as_map_space2"
        WORLD_CUTSCENE(3as_Tatooine,Stratis);
        WORLD_CUTSCENE(3AS_Sullust,Altis);
        WORLD_CUTSCENE(Malden,CAWorld);
        WORLD_CUTSCENE(Enoch,CAWorld);
        WORLD_CUTSCENE(Kamino,CAWorld);
        WORLD_CUTSCENE(3AS_Orto_Plut,CAWorld);
        WORLD_CUTSCENE(Space2,CAWorld);
};
