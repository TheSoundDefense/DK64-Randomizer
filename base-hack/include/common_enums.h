typedef enum console {
    NONE,
    N64,
    WIIU,
    EMULATOR,
} console;

typedef enum data_indexes {
	TABLE_MUSIC_MIDI,
	TABLE_MAP_GEOMETRY,
	TABLE_MAP_WALLS,
	TABLE_MAP_FLOORS,
	TABLE_MODELTWO_GEOMETRY,
	TABLE_ACTOR_GEOMETRY,
	TABLE_UNK06,
	TABLE_TEXTURES_UNCOMPRESSED,
	TABLE_CUTSCENES,
	TABLE_MAP_SETUPS,
	TABLE_MAP_OBJECT_SCRIPTS,
	TABLE_ANIMATIONS,
	TABLE_TEXT,
	TABLE_UNK0D,
	TABLE_TEXTURES,
	TABLE_MAP_PATHS,
	TABLE_MAP_CHARACTER_SPAWNERS,
	TABLE_UNK11,
	TABLE_MAP_LOADING_ZONES,
	TABLE_UNK13,
	TABLE_UNK14,
	TABLE_MAP_AUTOWALKS,
	TABLE_UNK16,
	TABLE_MAP_EXITS,
	TABLE_MAP_RACE_CHECKPOINTS,
	TABLE_TEXTURES_2,
	TABLE_UNCOMPRESSED_FILE_SIZES,
	TABLE_UNK1B,
	TABLE_UNK1C,
	TABLE_UNK1D,
	TABLE_UNK1E,
	TABLE_UNK1F,
	TABLE_UNK20,
} data_indexes;

typedef enum load_modes {
	SAVESTATE,
	MAPWARP,
} load_modes;

typedef enum codecs {
    IA4,
    IA8,
    RGBA16,
    RGBA32,
} codecs;

typedef enum collision_types {
	/* 0x000 */ COLLISION_BBLAST,
	/* 0x001 */ COLLISION_UNKNOWN_1,
	/* 0x002 */ COLLISION_SIMIAN_SPRING,
	/* 0x003 */ COLLISION_MONKEYPORT_WARP,
	/* 0x004 */ COLLISION_GORILLA_GONE,
	/* 0x005 */ COLLISION_BANANAPORT,
	/* 0x006 */ COLLISION_BABOON_BALLOON,
	/* 0x007 */ COLLISION_BATTLE_CROWN,
	/* 0x008 */ COLLISION_GRAB,
	/* 0x009 */ COLLISION_MULTI_BANANAPORT,
	/* 0x00A */ COLLISION_MAPWARP,
} collision_types;

typedef enum location_list {
	/* 0x000 */ LOCATION_DIVE,
	/* 0x001 */ LOCATION_ORANGE,
	/* 0x002 */ LOCATION_BARREL,
	/* 0x003 */ LOCATION_VINE,
	/* 0x004 */ LOCATION_BFI,
	/* 0x005 */ LOCATION_FIRSTMOVE,
} location_list;

typedef enum helm_hurry_items {
	/* 0x000 */ HHITEM_NOTHING,
	/* 0x001 */ HHITEM_GB,
	/* 0x002 */ HHITEM_BLUEPRINT,
	/* 0x003 */ HHITEM_COMPANYCOIN,
	/* 0x004 */ HHITEM_MOVE,
	/* 0x005 */ HHITEM_MEDAL,
	/* 0x006 */ HHITEM_RAINBOWCOIN,
	/* 0x007 */ HHITEM_KEY,
	/* 0x008 */ HHITEM_CROWN,
	/* 0x009 */ HHITEM_BEAN,
	/* 0x00A */ HHITEM_PEARL,
	/* 0x00B */ HHITEM_KONG,
	/* 0x00C */ HHITEM_FAIRY,
	/* 0x00D */ HHITEM_CB,
	/* 0x00E */ HHITEM_FAKEITEM,
} helm_hurry_items;

typedef enum purchase_classification {
	/* 0x000 */ PCLASS_NOTHING,
	/* 0x001 */ PCLASS_MOVE,
	/* 0x002 */ PCLASS_INSTRUMENT,
	/* 0x003 */ PCLASS_GUN,
	/* 0x004 */ PCLASS_CAMERA,
	/* 0x005 */ PCLASS_SHOCKWAVE,
	/* 0x006 */ PCLASS_CAMSHOCK,
	/* 0x007 */ PCLASS_GB,
	/* 0x008 */ PCLASS_BLUEPRINT,
	/* 0x009 */ PCLASS_COMPANYCOIN,
	/* 0x00A */ PCLASS_MEDAL,
	/* 0x00B */ PCLASS_RAINBOWCOIN,
	/* 0x00C */ PCLASS_KEY,
	/* 0x00D */ PCLASS_CROWN,
	/* 0x00E */ PCLASS_BEAN,
	/* 0x00F */ PCLASS_PEARL,
	/* 0x010 */ PCLASS_KONG,
	/* 0x011 */ PCLASS_FAIRY,
	/* 0x012 */ PCLASS_FAKEITEM,
} purchase_classification;

typedef enum pad_refresh_signals {
    /* 0x000 */ ITEMREFRESH_BLAST,
    /* 0x001 */ ITEMREFRESH_SPRING,
    /* 0x002 */ ITEMREFRESH_BALLOON,
    /* 0x003 */ ITEMREFRESH_MONKEYPORT,
    /* 0x004 */ ITEMREFRESH_GONE,
	/* 0x005 */ ITEMREFRESH_VINE,
} pad_refresh_signals;

typedef enum moverando_hinttext {
	/* 0x000 */ MRT_CANBUY_BBLAST,
	/* 0x001 */ MRT_CANBUY_SKONG,
	/* 0x002 */ MRT_CANBUY_GGRAB,
	/* 0x003 */ MRT_CANBUY_CCHARGE,
	/* 0x004 */ MRT_CANBUY_RBARREL,
	/* 0x005 */ MRT_CANBUY_SSPRING,
	/* 0x006 */ MRT_CANBUY_OSTAND,
	/* 0x007 */ MRT_CANBUY_BBALLOON,
	/* 0x008 */ MRT_CANBUY_OSPRINT,
	/* 0x009 */ MRT_CANBUY_MMONKEY,
	/* 0x00A */ MRT_CANBUY_PTT,
	/* 0x00B */ MRT_CANBUY_MPORT,
	/* 0x00C */ MRT_CANBUY_HCHUNKY,
	/* 0x00D */ MRT_CANBUY_PPUNCH,
	/* 0x00E */ MRT_CANBUY_GGONE,
	/* 0x00F */ MRT_CANBUY_SLAM,
	/* 0x010 */ MRT_CANBUY_COCONUT,
	/* 0x011 */ MRT_CANBUY_PEANUT,
	/* 0x012 */ MRT_CANBUY_GRAPE,
	/* 0x013 */ MRT_CANBUY_FEATHER,
	/* 0x014 */ MRT_CANBUY_PINEAPPLE,
	/* 0x015 */ MRT_CANBUY_HOMING,
	/* 0x016 */ MRT_CANBUY_SNIPER,
	/* 0x017 */ MRT_CANBUY_AMMOBELT,
	/* 0x018 */ MRT_CANBUY_BONGOS,
	/* 0x019 */ MRT_CANBUY_GUITAR,
	/* 0x01A */ MRT_CANBUY_TROMBONE,
	/* 0x01B */ MRT_CANBUY_SAX,
	/* 0x01C */ MRT_CANBUY_TRIANGLE,
	/* 0x01D */ MRT_CANBUY_INSTRUMENTUPGRADE,
	/* 0x01E */ MRT_CANBUY_DIVE,
	/* 0x01F */ MRT_CANBUY_ORANGE,
	/* 0x020 */ MRT_CANBUY_BARREL,
	/* 0x021 */ MRT_CANBUY_VINE,
	/* 0x022 */ MRT_CANBUY_CAMERA,
	/* 0x023 */ MRT_CANBUY_SHOCKWAVE,
	/* 0x024 */ MRT_CANBUY_CAMERACOMBO,
	/* 0x025 */ MRT_CANBUY_BANANA,
	/* 0x026 */ MRT_CANBUY_CROWN,
	/* 0x027 */ MRT_CANBUY_MEDAL,
	/* 0x028 */ MRT_CANBUY_KEY,
	/* 0x029 */ MRT_CANBUY_BLUEPRINT,
	/* 0x02A */ MRT_CANBUY_NINTENDO,
	/* 0x02B */ MRT_CANBUY_RAREWARE,
	/* 0x02C */ MRT_CANBUY_BEAN,
	/* 0x02D */ MRT_CANBUY_PEARL,
	/* 0x02E */ MRT_CANBUY_KONG,
	/* 0x02F */ MRT_CANBUY_FAIRY,
	/* 0x030 */ MRT_CANBUY_FAKEITEM,
	/* 0x031 */ MRT_NOBUY_SPECIALMOVE,
	/* 0x032 */ MRT_NOBUY_SLAM,
	/* 0x033 */ MRT_NOBUY_GUN,
	/* 0x034 */ MRT_NOBUY_GUNUPGRADE,
	/* 0x035 */ MRT_NOBUY_AMMOBELT,
	/* 0x036 */ MRT_NOBUY_INSTRUMENT,
	/* 0x037 */ MRT_NOBUY_TRAINING,
	/* 0x038 */ MRT_NOBUY_FAIRYMOVE,
	/* 0x039 */ MRT_NOBUY_ITEM,
	/* 0x03A */ MRT_NOBUY_BANANA,
	/* 0x03B */ MRT_NOBUY_BLUEPRINT,
	/* 0x03C */ MRT_NOBUY_MEDAL,
	/* 0x03D */ MRT_NOBUY_KONG,
} moverando_hinttext;

typedef enum item_purchase_text {
	/* 0x000 */ ITEMTEXT_SLAM1,
	/* 0x001 */ ITEMTEXT_SLAM1_LATIN,
	/* 0x002 */ ITEMTEXT_SLAM2,
	/* 0x003 */ ITEMTEXT_SLAM2_LATIN,
	/* 0x004 */ ITEMTEXT_SLAM3,
	/* 0x005 */ ITEMTEXT_SLAM3_LATIN,
	/* 0x006 */ ITEMTEXT_BBLAST,
	/* 0x007 */ ITEMTEXT_BBLAST_LATIN,
	/* 0x008 */ ITEMTEXT_SKONG,
	/* 0x009 */ ITEMTEXT_SKONG_LATIN,
	/* 0x00A */ ITEMTEXT_GGRAB,
	/* 0x00B */ ITEMTEXT_GGRAB_LATIN,
	/* 0x00C */ ITEMTEXT_CCHARGE,
	/* 0x00D */ ITEMTEXT_CCHARGE_LATIN,
	/* 0x00E */ ITEMTEXT_RBARREL,
	/* 0x00F */ ITEMTEXT_RBARREL_LATIN,
	/* 0x010 */ ITEMTEXT_SSPRING,
	/* 0x011 */ ITEMTEXT_SSPRING_LATIN,
	/* 0x012 */ ITEMTEXT_OSTAND,
	/* 0x013 */ ITEMTEXT_OSTAND_LATIN,
	/* 0x014 */ ITEMTEXT_BBALLOON,
	/* 0x015 */ ITEMTEXT_BBALLOON_LATIN,
	/* 0x016 */ ITEMTEXT_OSPRINT,
	/* 0x017 */ ITEMTEXT_OSPRINT_LATIN,
	/* 0x018 */ ITEMTEXT_MMONKEY,
	/* 0x019 */ ITEMTEXT_MMONKEY_LATIN,
	/* 0x01A */ ITEMTEXT_PTT,
	/* 0x01B */ ITEMTEXT_PTT_LATIN,
	/* 0x01C */ ITEMTEXT_MPORT,
	/* 0x01D */ ITEMTEXT_MPORT_LATIN,
	/* 0x01E */ ITEMTEXT_HCHUNKY,
	/* 0x01F */ ITEMTEXT_HCHUNKY_LATIN,
	/* 0x020 */ ITEMTEXT_PPUNCH,
	/* 0x021 */ ITEMTEXT_PPUNCH_LATIN,
	/* 0x022 */ ITEMTEXT_GGONE,
	/* 0x023 */ ITEMTEXT_GGONE_LATIN,
	/* 0x024 */ ITEMTEXT_COCONUT,
	/* 0x025 */ ITEMTEXT_PEANUT,
	/* 0x026 */ ITEMTEXT_GRAPE,
	/* 0x027 */ ITEMTEXT_FEATHER,
	/* 0x028 */ ITEMTEXT_PINEAPPLE,
	/* 0x029 */ ITEMTEXT_BONGOS,
	/* 0x02A */ ITEMTEXT_GUITAR,
	/* 0x02B */ ITEMTEXT_TROMBONE,
	/* 0x02C */ ITEMTEXT_SAX,
	/* 0x02D */ ITEMTEXT_TRIANGLE,
	/* 0x02E */ ITEMTEXT_HOMING,
	/* 0x02F */ ITEMTEXT_SNIPER,
	/* 0x030 */ ITEMTEXT_BELT1,
	/* 0x031 */ ITEMTEXT_BELT2,
	/* 0x032 */ ITEMTEXT_THIRDMELON,
	/* 0x033 */ ITEMTEXT_INSUPGRADE1,
	/* 0x034 */ ITEMTEXT_INSUPGRADE2,
	/* 0x035 */ ITEMTEXT_DIVE,
	/* 0x036 */ ITEMTEXT_ORANGE,
	/* 0x037 */ ITEMTEXT_BARREL,
	/* 0x038 */ ITEMTEXT_VINE,
	/* 0x039 */ ITEMTEXT_CAMERA,
	/* 0x03A */ ITEMTEXT_SHOCKWAVE,
	/* 0x03B */ ITEMTEXT_CAMERACOMBO,
	/* 0x03C */ ITEMTEXT_BANANA,
	/* 0x03D */ ITEMTEXT_MEDAL,
	/* 0x03E */ ITEMTEXT_BLUEPRINT_DK,
	/* 0x03F */ ITEMTEXT_BLUEPRINT_DIDDY,
	/* 0x040 */ ITEMTEXT_BLUEPRINT_LANKY,
	/* 0x041 */ ITEMTEXT_BLUEPRINT_TINY,
	/* 0x042 */ ITEMTEXT_BLUEPRINT_CHUNKY,
	/* 0x043 */ ITEMTEXT_NINTENDO,
	/* 0x044 */ ITEMTEXT_RAREWARE,
	/* 0x045 */ ITEMTEXT_KEYGENERIC,
	/* 0x046 */ ITEMTEXT_CROWN,
	/* 0x047 */ ITEMTEXT_BEAN,
	/* 0x048 */ ITEMTEXT_KEY1,
	/* 0x049 */ ITEMTEXT_KEY2,
	/* 0x04A */ ITEMTEXT_KEY3,
	/* 0x04B */ ITEMTEXT_KEY4,
	/* 0x04C */ ITEMTEXT_KEY5,
	/* 0x04D */ ITEMTEXT_KEY6,
	/* 0x04E */ ITEMTEXT_KEY7,
	/* 0x04F */ ITEMTEXT_KEY8,
	/* 0x050 */ ITEMTEXT_PEARL,
	/* 0x051 */ ITEMTEXT_KONG_DK,
	/* 0x052 */ ITEMTEXT_KONG_DIDDY,
	/* 0x053 */ ITEMTEXT_KONG_LANKY,
	/* 0x054 */ ITEMTEXT_KONG_TINY,
	/* 0x055 */ ITEMTEXT_KONG_CHUNKY,
	/* 0x056 */ ITEMTEXT_FAIRY,
	/* 0x057 */ ITEMTEXT_RAINBOWCOIN,
	/* 0x058 */ ITEMTEXT_FAKEITEM,
	/* 0x059 */ ITEMTEXT_CRANKYITEM,
	/* 0x05A */ ITEMTEXT_FUNKYITEM,
	/* 0x05B */ ITEMTEXT_CANDYITEM,
	/* 0x05C */ ITEMTEXT_SNIDEITEM,
} item_purchase_text;

typedef enum pausescreenlist {
	/* 0x000 */ PAUSESCREEN_MAIN,
	/* 0x001 */ PAUSESCREEN_LEVEL_KONGS,
	/* 0x002 */ PAUSESCREEN_LEVEL_ALL,
	/* 0x003 */ PAUSESCREEN_TOTALS,
	/* 0x004 */ PAUSESCREEN_CHECKS,
	/* 0x007 */ PAUSESCREEN_MOVES,
	/* 0x005 */ PAUSESCREEN_ITEMLOCATIONS,
	/* 0x006 */ PAUSESCREEN_HINTS,
	/* ----- */ PAUSESCREEN_TERMINATOR,
} pausescreenlist;

typedef enum colorblind_modes {
	/* 0x000 */ COLORBLIND_OFF,
	/* 0x001 */ COLORBLIND_PROT,
	/* 0x002 */ COLORBLIND_DEUT,
	/* 0x003 */ COLORBLIND_TRIT,
} colorblind_modes;

typedef enum seasons {
	/* 0x000 */ SEASON_NONE,
	/* 0x001 */ SEASON_HALLOWEEN,
	/* 0x002 */ SEASON_CHRISTMAS,
} seasons;

typedef enum kongs {
	/* 0x000 */ KONG_DK,
	/* 0x001 */ KONG_DIDDY,
	/* 0x002 */ KONG_LANKY,
	/* 0x003 */ KONG_TINY,
	/* 0x004 */ KONG_CHUNKY,
} kongs;

typedef enum win_conditions {
	/* 0x000 */ GOAL_KROOL,
	/* 0x001 */ GOAL_KEY8,
	/* 0x002 */ GOAL_POKESNAP,
	/* 0x003 */ GOAL_CUSTOMITEM,
} win_conditions;

typedef enum master_types_list {
	/* 0x000 */ ACTORMASTER_UNUSED,
	/* 0x001 */ ACTORMASTER_LOWLEVEL,
	/* 0x002 */ ACTORMASTER_3D,
	/* 0x003 */ ACTORMASTER_CONTROLLER,
	/* 0x004 */ ACTORMASTER_SPRITE,
} master_types_list;

typedef enum vendors {
	/* 0x000 */ SHOP_CRANKY,
	/* 0x001 */ SHOP_FUNKY,
	/* 0x002 */ SHOP_CANDY,
	/* 0x003 */ SHOP_SNIDE,
} vendors;

typedef enum flagtypes {
	/* 0x000 */ FLAGTYPE_PERMANENT,
	/* 0x001 */ FLAGTYPE_GLOBAL,
	/* 0x002 */ FLAGTYPE_TEMPORARY,
} flagtypes;

typedef enum maps {
	/* 0x000 */ MAP_TESTMAP,
    /* 0x001 */ MAP_FUNKY,
    /* 0x002 */ MAP_DKARCADE,
    /* 0x003 */ MAP_HELMBARREL_LANKYMAZE,
    /* 0x004 */ MAP_JAPESMOUNTAIN,
    /* 0x005 */ MAP_CRANKY,
    /* 0x006 */ MAP_JAPESMINECART,
    /* 0x007 */ MAP_JAPES,
    /* 0x008 */ MAP_JAPESDILLO,
    /* 0x009 */ MAP_JETPAC,
    /* 0x00A */ MAP_KOSH_VEASY,
    /* 0x00B */ MAP_SNOOP_NORMALNOLOGO,
    /* 0x00C */ MAP_JAPESSHELL,
    /* 0x00D */ MAP_JAPESPAINTING,
    /* 0x00E */ MAP_AZTECBEETLE,
    /* 0x00F */ MAP_SNIDE,
    /* 0x010 */ MAP_AZTECTINYTEMPLE,
    /* 0x011 */ MAP_HELM,
    /* 0x012 */ MAP_TURTLES_VEASY,
    /* 0x013 */ MAP_AZTEC5DTDK,
    /* 0x014 */ MAP_AZTECLLAMATEMPLE,
    /* 0x015 */ MAP_AZTEC5DTDIDDY,
    /* 0x016 */ MAP_AZTEC5DTTINY,
    /* 0x017 */ MAP_AZTEC5DTLANKY,
    /* 0x018 */ MAP_AZTEC5DTCHUNKY,
    /* 0x019 */ MAP_CANDY,
    /* 0x01A */ MAP_FACTORY,
    /* 0x01B */ MAP_FACTORYCARRACE,
    /* 0x01C */ MAP_HELM_INTROSGAMEOVER,
    /* 0x01D */ MAP_FACTORYPOWERSHED,
    /* 0x01E */ MAP_GALLEON,
    /* 0x01F */ MAP_GALLEONSEASICKSHIP,
    /* 0x020 */ MAP_BATTYBARREL_VEASY,
    /* 0x021 */ MAP_JAPESUNDERGROUND,
    /* 0x022 */ MAP_ISLES,
    /* 0x023 */ MAP_HELMBARREL_TARGET,
    /* 0x024 */ MAP_FACTORYCRUSHER,
    /* 0x025 */ MAP_JAPESBBLAST,
    /* 0x026 */ MAP_AZTEC,
    /* 0x027 */ MAP_GALLEONSEALRACE,
    /* 0x028 */ MAP_NINTENDOLOGO,
    /* 0x029 */ MAP_AZTECBBLAST,
    /* 0x02A */ MAP_TROFFNSCOFF,
    /* 0x02B */ MAP_GALLEON5DSDIDDYLANKYCHUNKY,
    /* 0x02C */ MAP_GALLEONTREASURECHEST,
    /* 0x02D */ MAP_GALLEONMERMAID,
    /* 0x02E */ MAP_GALLEON5DSDKTINY,
    /* 0x02F */ MAP_GALLEON2DS,
    /* 0x030 */ MAP_FUNGI,
    /* 0x031 */ MAP_GALLEONLIGHTHOUSE,
    /* 0x032 */ MAP_HELMBARREL_MUSHROOMBOUNCE,
    /* 0x033 */ MAP_GALLEONMECHFISH,
    /* 0x034 */ MAP_FUNGIANTHILL,
    /* 0x035 */ MAP_BATTLEARENA_BEAVERBRAWL,
    /* 0x036 */ MAP_GALLEONBBLAST,
    /* 0x037 */ MAP_FUNGIMINECART,
    /* 0x038 */ MAP_FUNGIDIDDYBARN,
    /* 0x039 */ MAP_FUNGIDIDDYATTIC,
    /* 0x03A */ MAP_FUNGILANKYATTIC,
    /* 0x03B */ MAP_FUNGIDKBARN,
    /* 0x03C */ MAP_FUNGISPIDER,
    /* 0x03D */ MAP_FUNGIMILLFRONT,
    /* 0x03E */ MAP_FUNGIMILLREAR,
    /* 0x03F */ MAP_FUNGIMUSHROOMSLAM,
    /* 0x040 */ MAP_FUNGIGIANTMUSHROOM,
    /* 0x041 */ MAP_SNOOP_NORMAL,
    /* 0x042 */ MAP_MAUL_HARD,
    /* 0x043 */ MAP_SNATCH_NORMAL,
    /* 0x044 */ MAP_MAUL_EASY,
    /* 0x045 */ MAP_MAUL_NORMAL,
    /* 0x046 */ MAP_FUNGIMUSHROOMLEAP,
    /* 0x047 */ MAP_FUNGISHOOTINGGAME,
    /* 0x048 */ MAP_CAVES,
    /* 0x049 */ MAP_BATTLEARENA_KRITTERKARNAGE,
    /* 0x04A */ MAP_SNATCH_EASY,
    /* 0x04B */ MAP_SNATCH_HARD,
    /* 0x04C */ MAP_DKRAP,
    /* 0x04D */ MAP_MMAYHEM_EASY,
    /* 0x04E */ MAP_BARRAGE_EASY,
    /* 0x04F */ MAP_BARRAGE_NORMAL,
    /* 0x050 */ MAP_MAINMENU,
    /* 0x051 */ MAP_NFRTITLESCREEN,
    /* 0x052 */ MAP_CAVESBEETLERACE,
    /* 0x053 */ MAP_FUNGIDOGADON,
    /* 0x054 */ MAP_CAVES5DITINY,
    /* 0x055 */ MAP_CAVES5DILANKY,
    /* 0x056 */ MAP_CAVES5DIDK,
    /* 0x057 */ MAP_CASTLE,
    /* 0x058 */ MAP_CASTLEBALLROOM,
    /* 0x059 */ MAP_CAVESROTATINGROOM,
    /* 0x05A */ MAP_CAVES5DCCHUNKY,
    /* 0x05B */ MAP_CAVES5DCDK,
    /* 0x05C */ MAP_CAVES5DCDIDDYLOW,
    /* 0x05D */ MAP_CAVES5DCTINY,
    /* 0x05E */ MAP_CAVES1DC,
    /* 0x05F */ MAP_CAVES5DICHUNKY,
    /* 0x060 */ MAP_SALVAGE_NORMAL,
    /* 0x061 */ MAP_KLUMSY,
    /* 0x062 */ MAP_CAVESTILEFLIP,
    /* 0x063 */ MAP_SORTIE_EASY,
    /* 0x064 */ MAP_CAVES5DIDIDDY,
    /* 0x065 */ MAP_KLAMOUR_EASY,
    /* 0x066 */ MAP_BASH_VEASY,
    /* 0x067 */ MAP_SEARCHLIGHT_VEASY,
    /* 0x068 */ MAP_BBOTHER_EASY,
    /* 0x069 */ MAP_CASTLETOWER,
    /* 0x06A */ MAP_CASTLEMINECART,
    /* 0x06B */ MAP_MULTIPLAYERBATTLEARENA,
    /* 0x06C */ MAP_CASTLECRYPTLANKYTINY,
    /* 0x06D */ MAP_MULTIPLAYERARENA1,
    /* 0x06E */ MAP_FACTORYBBLAST,
    /* 0x06F */ MAP_GALLEONPUFFTOSS,
    /* 0x070 */ MAP_CASTLECRYPTDKDIDDYCHUNKY,
    /* 0x071 */ MAP_CASTLEMUSEUM,
    /* 0x072 */ MAP_CASTLELIBRARY,
    /* 0x073 */ MAP_KOSH_EASY,
    /* 0x074 */ MAP_KOSH_NORMAL,
    /* 0x075 */ MAP_KOSH_HARD,
    /* 0x076 */ MAP_TURTLES_EASY,
    /* 0x077 */ MAP_TURTLES_NORMAL,
    /* 0x078 */ MAP_TURTLES_HARD,
    /* 0x079 */ MAP_BATTYBARREL_EASY,
    /* 0x07A */ MAP_BATTYBARREL_NORMAL,
    /* 0x07B */ MAP_BATTYBARREL_HARD,
    /* 0x07C */ MAP_MAUL_INSANE,
    /* 0x07D */ MAP_SNATCH_INSANE,
    /* 0x07E */ MAP_SNOOP_VEASY,
    /* 0x07F */ MAP_SNOOP_EASY,
    /* 0x080 */ MAP_SNOOP_HARD,
    /* 0x081 */ MAP_MMAYHEM_NORMAL,
    /* 0x082 */ MAP_MMAYHEM_HARD,
    /* 0x083 */ MAP_BARRAGE_HARD,
    /* 0x084 */ MAP_SALVAGE_HARD,
    /* 0x085 */ MAP_SALVAGE_EASY,
    /* 0x086 */ MAP_SORTIE_NORMAL,
    /* 0x087 */ MAP_SORTIE_HARD,
    /* 0x088 */ MAP_BBOTHER_NORMAL,
    /* 0x089 */ MAP_BBOTHER_HARD,
    /* 0x08A */ MAP_SEARCHLIGHT_EASY,
    /* 0x08B */ MAP_SEARCHLIGHT_NORMAL,
    /* 0x08C */ MAP_SEARCHLIGHT_HARD,
    /* 0x08D */ MAP_KLAMOUR_NORMAL,
    /* 0x08E */ MAP_KLAMOUR_HARD,
    /* 0x08F */ MAP_KLAMOUR_INSANE,
    /* 0x090 */ MAP_PPPANIC_VEASY,
    /* 0x091 */ MAP_PPPANIC_EASY,
    /* 0x092 */ MAP_PPPANIC_NORMAL,
    /* 0x093 */ MAP_PPPANIC_HARD,
    /* 0x094 */ MAP_BASH_EASY,
    /* 0x095 */ MAP_BASH_NORMAL,
    /* 0x096 */ MAP_BASH_HARD,
    /* 0x097 */ MAP_CASTLEDUNGEON,
    /* 0x098 */ MAP_HELM_INTROSTORY,
    /* 0x099 */ MAP_ISLES_DKTHEATRE,
    /* 0x09A */ MAP_FACTORYJACK,
    /* 0x09B */ MAP_BATTLEARENA_ARENAAMBUSH,
    /* 0x09C */ MAP_BATTLEARENA_MOREKRITTERKARNAGE,
    /* 0x09D */ MAP_BATTLEARENA_FORESTFRACAS,
    /* 0x09E */ MAP_BATTLEARENA_BISHBASHBRAWL,
    /* 0x09F */ MAP_BATTLEARENA_KAMIKAZEKREMLINGS,
    /* 0x0A0 */ MAP_BATTLEARENA_PLINTHPANIC,
    /* 0x0A1 */ MAP_BATTLEARENA_PINNACLEPALAVER,
    /* 0x0A2 */ MAP_BATTLEARENA_SHOCKWAVESHOWDOWN,
    /* 0x0A3 */ MAP_CASTLEBASEMENT,
    /* 0x0A4 */ MAP_CASTLETREE,
    /* 0x0A5 */ MAP_HELMBARREL_RANDOMKREMLING,
    /* 0x0A6 */ MAP_CASTLESHED,
    /* 0x0A7 */ MAP_CASTLETRASH,
    /* 0x0A8 */ MAP_CASTLEGREENHOUSE,
    /* 0x0A9 */ MAP_JAPESLOBBY,
    /* 0x0AA */ MAP_HELMLOBBY,
    /* 0x0AB */ MAP_TREEHOUSE,
    /* 0x0AC */ MAP_ISLES_INTROSTORYROCK,
    /* 0x0AD */ MAP_AZTECLOBBY,
    /* 0x0AE */ MAP_GALLEONLOBBY,
    /* 0x0AF */ MAP_FACTORYLOBBY,
    /* 0x0B0 */ MAP_TRAININGGROUNDS,
    /* 0x0B1 */ MAP_TBARREL_DIVE,
    /* 0x0B2 */ MAP_FUNGILOBBY,
    /* 0x0B3 */ MAP_GALLEONSUBMARINE,
    /* 0x0B4 */ MAP_TBARREL_ORANGE,
    /* 0x0B5 */ MAP_TBARREL_BARREL,
    /* 0x0B6 */ MAP_TBARREL_VINE,
    /* 0x0B7 */ MAP_CASTLECRYPT,
    /* 0x0B8 */ MAP_ENGUARDEARENA,
    /* 0x0B9 */ MAP_CASTLECARRACE,
    /* 0x0BA */ MAP_CAVESBBLAST,
    /* 0x0BB */ MAP_CASTLEBBLAST,
    /* 0x0BC */ MAP_FUNGIBBLAST,
    /* 0x0BD */ MAP_FAIRYISLAND,
    /* 0x0BE */ MAP_MULTIPLAYERARENA2,
    /* 0x0BF */ MAP_RAMBIARENA,
    /* 0x0C0 */ MAP_MULTIPLAYERARENA3,
    /* 0x0C1 */ MAP_CASTLELOBBY,
    /* 0x0C2 */ MAP_CAVESLOBBY,
    /* 0x0C3 */ MAP_ISLES_SNIDEROOM,
    /* 0x0C4 */ MAP_CAVESDILLO,
    /* 0x0C5 */ MAP_AZTECDOGADON,
    /* 0x0C6 */ MAP_TRAININGGROUNDS_ENDSEQUENCE,
    /* 0x0C7 */ MAP_CASTLEKUTOUT,
    /* 0x0C8 */ MAP_CAVESSHACKDIDDYHIGH,
    /* 0x0C9 */ MAP_HELMBARREL_ROCKETBARREL,
    /* 0x0CA */ MAP_HELMBARREL_LANKYSHOOTING,
    /* 0x0CB */ MAP_KROOLDK,
    /* 0x0CC */ MAP_KROOLDIDDY,
    /* 0x0CD */ MAP_KROOLLANKY,
    /* 0x0CE */ MAP_KROOLTINY,
    /* 0x0CF */ MAP_KROOLCHUNKY,
    /* 0x0D0 */ MAP_BLOOPERSENDING,
    /* 0x0D1 */ MAP_HELMBARREL_HIDDENKREMLING,
    /* 0x0D2 */ MAP_HELMBARREL_FLOORISLAVA,
    /* 0x0D3 */ MAP_HELMBARREL_CHUNKYSHOOTING,
    /* 0x0D4 */ MAP_HELMBARREL_RAMBI,
    /* 0x0D5 */ MAP_KLUMSYENDING,
    /* 0x0D6 */ MAP_KROOLSHOE,
    /* 0x0D7 */ MAP_KROOLARENA,
} maps;

typedef enum file_data_indexes {
    DATA_JETPACHISCORE = 0x11,
    DATA_ARCADEHISCORE_CHAR0 = 0x12,
    DATA_ARCADEHISCORE_CHAR1 = 0x13,
    DATA_ARCADEHISCORE_CHAR2 = 0x14,
    DATA_ARCADEHISCORE_NUM = 0x15,
    DATA_RAMBIHISCORE_CHAR0 = 0x16,
    DATA_RAMBIHISCORE_CHAR1 = 0x17,
    DATA_RAMBIHISCORE_CHAR2 = 0x18,
    DATA_RAMBIHISCORE_NUM = 0x19,
    DATA_ENGUARDEHISCORE_CHAR0 = 0x1A,
    DATA_ENGUARDEHISCORE_CHAR1 = 0x1B,
    DATA_ENGUARDEHISCORE_CHAR2 = 0x1C,
    DATA_ENGUARDEHISCORE_NUM = 0x1D,
    DATA_SOUNDTYPE = 0x1E,
    DATA_LANGUAGE = 0x1F,
    DATA_CAMERATYPE = 0x20,
    DATA_LEVELIGT = 0x21,
	DATA_HELMHURRYIGT = 0x22,
	DATA_HELMHURRYOFF = 0x23,
	DATA_BONUSSTAT = 0x24,
	DATA_KONGIGT = 0x25,
	DATA_FILENAME = 0x26,
} file_data_indexes;

typedef enum extra_global_data {
	EGD_LEVELIGT,
	EGD_HELMHURRYIGT,
	EGD_HELMHURRYDISABLE,
	EGD_BONUSSTAT,
	EGD_KONGIGT,
	EGD_FILENAME,
	EGD_TERMINATOR,
} extra_global_data;

typedef enum bonus_stat {
    /* 0x000 */ STAT_TAGCOUNT,
    /* ----- */ STAT_TERMINATOR,
} bonus_stat;

typedef enum gamemodes {
	/* 0x000 */ GAMEMODE_NINTENDOLOGO,
	/* 0x001 */ GAMEMODE_OPENINGCUTSCENE,
	/* 0x002 */ GAMEMODE_RAP,
	/* 0x003 */ GAMEMODE_DKTV,
	/* 0x004 */ GAMEMODE_UNK4,
	/* 0x005 */ GAMEMODE_MAINMENU,
	/* 0x006 */ GAMEMODE_ADVENTURE,
	/* 0x007 */ GAMEMODE_LOADGAMEOVER,
	/* 0x008 */ GAMEMODE_UNK8,
	/* 0x009 */ GAMEMODE_GAMEOVER,
	/* 0x00A */ GAMEMODE_ENDSEQADV,
	/* 0x00B */ GAMEMODE_DKTHEATRE,
	/* 0x00C */ GAMEMODE_DKBONUS,
	/* 0x00D */ GAMEMODE_SNIDEGAMES,
	/* 0x00E */ GAMEMODE_ENDSEQTHEATRE,
} gamemodes;

typedef enum microhint_types {
	/* 0x000 */ MICROHINTS_NONE,
	/* 0x001 */ MICROHINTS_SOME,
	/* 0x002 */ MICROHINTS_ALL,
} microhint_types;

typedef enum tracker_types {
	/* 0 */ TRACKER_TYPE_COCONUT,
	/* 1 */ TRACKER_TYPE_BONGOS,
	/* 2 */ TRACKER_TYPE_GRAB,
	/* 3 */ TRACKER_TYPE_STRONG,
	/* 4 */ TRACKER_TYPE_BLAST,
	/* 5 */ TRACKER_TYPE_PEANUT,
	/* 6 */ TRACKER_TYPE_GUITAR,
	/* 7 */ TRACKER_TYPE_CHARGE,
	/* 8 */ TRACKER_TYPE_ROCKET,
	/* 9 */ TRACKER_TYPE_SPRING,
	/* 10 */ TRACKER_TYPE_GRAPE,
	/* 11 */ TRACKER_TYPE_TROMBONE,
	/* 12 */ TRACKER_TYPE_OSTAND,
	/* 13 */ TRACKER_TYPE_OSPRINT,
	/* 14 */ TRACKER_TYPE_BALLOON,
	/* 15 */ TRACKER_TYPE_FEATHER,
	/* 16 */ TRACKER_TYPE_SAX,
	/* 17 */ TRACKER_TYPE_PTT,
	/* 18 */ TRACKER_TYPE_MINI,
	/* 19 */ TRACKER_TYPE_MONKEYPORT,
	/* 20 */ TRACKER_TYPE_PINEAPPLE,
	/* 21 */ TRACKER_TYPE_TRIANGLE,
	/* 22 */ TRACKER_TYPE_PUNCH,
	/* 23 */ TRACKER_TYPE_HUNKY,
	/* 24 */ TRACKER_TYPE_GONE,
	/* 25 */ TRACKER_TYPE_SLAM,
	/* 26 */ TRACKER_TYPE_SLAM_HAS,
	/* 27 */ TRACKER_TYPE_HOMING,
	/* 28 */ TRACKER_TYPE_SNIPER,
	/* 29 */ TRACKER_TYPE_AMMOBELT,
	/* 30 */ TRACKER_TYPE_INSTRUMENT_UPG,
	/* 31 */ TRACKER_TYPE_DIVE,
	/* 32 */ TRACKER_TYPE_ORANGE,
	/* 33 */ TRACKER_TYPE_BARREL,
	/* 34 */ TRACKER_TYPE_VINE,
	/* 35 */ TRACKER_TYPE_CAMERA,
	/* 36 */ TRACKER_TYPE_SHOCKWAVE,
	/* 37 */ TRACKER_TYPE_KEY1,
	/* 38 */ TRACKER_TYPE_KEY2,
	/* 39 */ TRACKER_TYPE_KEY3,
	/* 40 */ TRACKER_TYPE_KEY4,
	/* 41 */ TRACKER_TYPE_KEY5,
	/* 42 */ TRACKER_TYPE_KEY6,
	/* 43 */ TRACKER_TYPE_KEY7,
	/* 44 */ TRACKER_TYPE_KEY8,
	/* 45 */ TRACKER_TYPE_MELON_2,
	/* 46 */ TRACKER_TYPE_MELON_3,
	/* 47 */ TRACKER_TYPE_INSUPG_1,
	/* 48 */ TRACKER_TYPE_INSUPG_2,
	/* 49 */ TRACKER_TYPE_BELT_1,
	/* 50 */ TRACKER_TYPE_BELT_2,
} tracker_types;

typedef enum overlays {
	/* 0x000 */ OVERLAY_BOOT,
	/* 0x001 */ OVERLAY_STATIC,
	/* 0x002 */ OVERLAY_MENU,
	/* 0x003 */ OVERLAY_MULTI,
	/* 0x004 */ OVERLAY_MINECART,
	/* 0x005 */ OVERLAY_RACE,
	/* 0x006 */ OVERLAY_CRITTER,
	/* 0x007 */ OVERLAY_BOSS,
	/* 0x008 */ OVERLAY_BONUS,
	/* 0x009 */ OVERLAY_ARCADE,
	/* 0x00A */ OVERLAY_NONE,
	/* 0x00B */ OVERLAY_JETPAC,
} overlays;

typedef enum song_types {
	/* 0x000 */ SONGTYPE_BGM,
	/* 0x001 */ SONGTYPE_EVENT,
	/* 0x002 */ SONGTYPE_MAJORITEM,
	/* 0x003 */ SONGTYPE_MINORITEM,
} song_types;

typedef enum cs_skip_types {
	/* 0x000 */ CSSKIP_OFF,
	/* 0x001 */ CSSKIP_PRESS,
	/* 0x002 */ CSSKIP_AUTO,
} cs_skip_types;

typedef enum fungi_time {
	/* 0x000 */ TIME_DAY,
	/* 0x001 */ TIME_NIGHT,
	/* 0x002 */ TIME_DUSK,
	/* 0x003 */ TIME_PROGRESSIVE,
} fungi_time;

typedef enum time_of_day_calls {
	/* 0x000 */ TODCALL_INITFILE,
	/* 0x001 */ TODCALL_FUNGIACTIVE,
} time_of_day_calls;

typedef enum songs {
	/* 0x000 */ SONG_SILENCE,
	/* 0x001 */ SONG_JAPESSTART,
	/* 0x002 */ SONG_CRANKY,
	/* 0x003 */ SONG_JAPESCART,
	/* 0x004 */ SONG_JAPESDILLO,
	/* 0x005 */ SONG_JAPESCAVES,
	/* 0x006 */ SONG_FUNKY,
	/* 0x007 */ SONG_UNUSEDCOIN,
	/* 0x008 */ SONG_MINIGAMES,
	/* 0x009 */ SONG_TRIANGLE,
	/* 0x00A */ SONG_GUITAR,
	/* 0x00B */ SONG_BONGOS,
	/* 0x00C */ SONG_TROMBONE,
	/* 0x00D */ SONG_SAXOPHONE,
	/* 0x00E */ SONG_AZTECMAIN,
	/* 0x00F */ SONG_TRANSFORMATION,
	/* 0x010 */ SONG_MINIMONKEY,
	/* 0x011 */ SONG_HUNKYCHUNKY,
	/* 0x012 */ SONG_GBGET,
	/* 0x013 */ SONG_AZTECBEETLE,
	/* 0x014 */ SONG_OHBANANA,
	/* 0x015 */ SONG_AZTECTEMPLE,
	/* 0x016 */ SONG_COMPANYCOINGET,
	/* 0x017 */ SONG_BANANACOINGET,
	/* 0x018 */ SONG_VULTURERING,
	/* 0x019 */ SONG_AZTECDOGADON,
	/* 0x01A */ SONG_AZTEC5DT,
	/* 0x01B */ SONG_FACTORYCARRACE,
	/* 0x01C */ SONG_FACTORYMAIN,
	/* 0x01D */ SONG_SNIDE,
	/* 0x01E */ SONG_JAPESTUNNELS,
	/* 0x01F */ SONG_CANDY,
	/* 0x020 */ SONG_MINECARTCOINGET,
	/* 0x021 */ SONG_MELONSLICEGET,
	/* 0x022 */ SONG_PAUSEMENU,
	/* 0x023 */ SONG_CRYSTALCOCONUTGET,
	/* 0x024 */ SONG_RAMBI,
	/* 0x025 */ SONG_AZTECTUNNELS,
	/* 0x026 */ SONG_WATERDROPLETS,
	/* 0x027 */ SONG_FACTORYJACK,
	/* 0x028 */ SONG_SUCCESS,
	/* 0x029 */ SONG_STARTPAUSE,
	/* 0x02A */ SONG_FAILURE,
	/* 0x02B */ SONG_TRANSITIONOPEN,
	/* 0x02C */ SONG_TRANSITIONCLOSE,
	/* 0x02D */ SONG_JAPESHIGHPITCHED,
	/* 0x02E */ SONG_FAIRYTICK,
	/* 0x02F */ SONG_MELONSLICEDROP,
	/* 0x030 */ SONG_AZTECCHUNKYKLAPTRAPS,
	/* 0x031 */ SONG_FACTORYCRUSHER,
	/* 0x032 */ SONG_JAPESBLAST,
	/* 0x033 */ SONG_FACTORYRESEARCHANDDEVELOPMENT,
	/* 0x034 */ SONG_FACTORYPRODUCTION,
	/* 0x035 */ SONG_TROFFNSCOFF,
	/* 0x036 */ SONG_BOSSDEFEAT,
	/* 0x037 */ SONG_AZTECBLAST,
	/* 0x038 */ SONG_GALLEONOUTSIDE,
	/* 0x039 */ SONG_BOSSUNLOCK,
	/* 0x03A */ SONG_AWAITINGBOSSENTRY,
	/* 0x03B */ SONG_TWINKLYSOUNDS,
	/* 0x03C */ SONG_GALLEONPUFFTOSS,
	/* 0x03D */ SONG_GALLEONSEALRACE,
	/* 0x03E */ SONG_GALLEONTUNNELS,
	/* 0x03F */ SONG_GALLEONLIGHTHOUSE,
	/* 0x040 */ SONG_BATTLEARENA,
	/* 0x041 */ SONG_DROPCOINS,
	/* 0x042 */ SONG_FAIRYNEARBY,
	/* 0x043 */ SONG_CHECKPOINT,
	/* 0x044 */ SONG_FORESTDAY,
	/* 0x045 */ SONG_BLUEPRINTGET,
	/* 0x046 */ SONG_FORESTNIGHT,
	/* 0x047 */ SONG_STRONGKONG,
	/* 0x048 */ SONG_ROCKETBARREL,
	/* 0x049 */ SONG_SPRINT,
	/* 0x04A */ SONG_FORESTCART,
	/* 0x04B */ SONG_DKRAP,
	/* 0x04C */ SONG_BLUEPRINTDROP,
	/* 0x04D */ SONG_GALLEON2DS,
	/* 0x04E */ SONG_GALLEON5DS,
	/* 0x04F */ SONG_GALLEONCHEST,
	/* 0x050 */ SONG_GALLEONMERMAID,
	/* 0x051 */ SONG_FORESTDOGADON,
	/* 0x052 */ SONG_MADMAZEMAUL,
	/* 0x053 */ SONG_CAVES,
	/* 0x054 */ SONG_CAVESTANTRUM,
	/* 0x055 */ SONG_NINTENDOLOGOOLD,
	/* 0x056 */ SONG_SUCCESSRACES,
	/* 0x057 */ SONG_FAILURERACES,
	/* 0x058 */ SONG_BONUSBARRELINTRODUCTION,
	/* 0x059 */ SONG_STEALTHYSNOOP,
	/* 0x05A */ SONG_MINECARTMAYHEM,
	/* 0x05B */ SONG_GALLEONMECHFISH,
	/* 0x05C */ SONG_GALLEONBLAST,
	/* 0x05D */ SONG_FORESTANTHILL,
	/* 0x05E */ SONG_FORESTBARN,
	/* 0x05F */ SONG_FORESTMILL,
	/* 0x060 */ SONG_SEASIDESOUNDS,
	/* 0x061 */ SONG_FORESTSPIDER,
	/* 0x062 */ SONG_FORESTMUSHROOMROOMS,
	/* 0x063 */ SONG_FORESTMUSHROOM,
	/* 0x064 */ SONG_BOSSINTRODUCTION,
	/* 0x065 */ SONG_TAGBARREL,
	/* 0x066 */ SONG_CAVESBEETLERACE,
	/* 0x067 */ SONG_CAVESIGLOOS,
	/* 0x068 */ SONG_MINIBOSS,
	/* 0x069 */ SONG_CASTLE,
	/* 0x06A */ SONG_CASTLECART,
	/* 0x06B */ SONG_BABOONBALLOON,
	/* 0x06C */ SONG_GORILLAGONE,
	/* 0x06D */ SONG_ISLES,
	/* 0x06E */ SONG_ISLESKREMISLE,
	/* 0x06F */ SONG_ISLESBFI,
	/* 0x070 */ SONG_ISLESKLUMSY,
	/* 0x071 */ SONG_HELMBOMON,
	/* 0x072 */ SONG_MOVEGET,
	/* 0x073 */ SONG_GUNGET,
	/* 0x074 */ SONG_HELMBOMOFF,
	/* 0x075 */ SONG_HELMBONUS,
	/* 0x076 */ SONG_CAVESCABINS,
	/* 0x077 */ SONG_CAVESROTATINGROOM,
	/* 0x078 */ SONG_CAVESICECASTLE,
	/* 0x079 */ SONG_CASTLETUNNELS,
	/* 0x07A */ SONG_INTROSTORY,
	/* 0x07B */ SONG_TRAININGGROUNDS,
	/* 0x07C */ SONG_ENGUARDE,
	/* 0x07D */ SONG_KLUMSYCELEBRATION,
	/* 0x07E */ SONG_CASTLECRYPT,
	/* 0x07F */ SONG_HEADPHONESGET,
	/* 0x080 */ SONG_PEARLGET,
	/* 0x081 */ SONG_CASTLEDUNGEON_CHAINS,
	/* 0x082 */ SONG_AZTECLOBBY,
	/* 0x083 */ SONG_JAPESLOBBY,
	/* 0x084 */ SONG_FACTORYLOBBY,
	/* 0x085 */ SONG_GALLEONLOBBY,
	/* 0x086 */ SONG_MAINMENU,
	/* 0x087 */ SONG_CASTLEINNERCRYPTS,
	/* 0x088 */ SONG_CASTLEBALLROOM,
	/* 0x089 */ SONG_CASTLEGREENHOUSE,
	/* 0x08A */ SONG_KROOLTHEME,
	/* 0x08B */ SONG_FORESTWINCH,
	/* 0x08C */ SONG_CASTLETOWER,
	/* 0x08D */ SONG_CASTLETREE,
	/* 0x08E */ SONG_CASTLEMUSEUM,
	/* 0x08F */ SONG_BBLASTFINALSTAR,
	/* 0x090 */ SONG_DROPRAINBOWCOIN,
	/* 0x091 */ SONG_RAINBOWCOINGET,
	/* 0x092 */ SONG_NORMALSTAR,
	/* 0x093 */ SONG_BEANGET,
	/* 0x094 */ SONG_CAVESDILLO,
	/* 0x095 */ SONG_CASTLEKUTOUT,
	/* 0x096 */ SONG_CASTLEDUNGEON_NOCHAINS,
	/* 0x097 */ SONG_BANANAMEDALGET,
	/* 0x098 */ SONG_KROOLBATTLE,
	/* 0x099 */ SONG_FORESTLOBBY,
	/* 0x09A */ SONG_CAVESLOBBY,
	/* 0x09B */ SONG_CASTLELOBBY,
	/* 0x09C */ SONG_HELMLOBBY,
	/* 0x09D */ SONG_CASTLETRASH,
	/* 0x09E */ SONG_ENDSEQUENCE,
	/* 0x09F */ SONG_KLUMSYENDING,
	/* 0x0A0 */ SONG_JAPESMAIN,
	/* 0x0A1 */ SONG_JAPESSTORM,
	/* 0x0A2 */ SONG_KROOLTAKEOFF,
	/* 0x0A3 */ SONG_CAVESBLAST,
	/* 0x0A4 */ SONG_FORESTBLAST,
	/* 0x0A5 */ SONG_CASTLEBLAST,
	/* 0x0A6 */ SONG_ISLESSNIDEROOM,
	/* 0x0A7 */ SONG_KROOLENTRANCE,
	/* 0x0A8 */ SONG_MONKEYSMASH,
	/* 0x0A9 */ SONG_FORESTRABBITRACE,
	/* 0x0AA */ SONG_GAMEOVER,
	/* 0x0AB */ SONG_WRINKLYKONG,
	/* 0x0AC */ SONG_FINALCBGET,
	/* 0x0AD */ SONG_KROOLDEFEAT,
	/* 0x0AE */ SONG_NINTENDOLOGO,
} songs;

typedef enum level_indexes {
	/* 0x000 */ LEVEL_JAPES,
	/* 0x001 */ LEVEL_AZTEC,
	/* 0x002 */ LEVEL_FACTORY,
	/* 0x003 */ LEVEL_GALLEON,
	/* 0x004 */ LEVEL_FUNGI,
	/* 0x005 */ LEVEL_CAVES,
	/* 0x006 */ LEVEL_CASTLE,
	/* 0x007 */ LEVEL_ISLES,
	/* 0x008 */ LEVEL_HELM,
	/* 0x009 */ LEVEL_BONUS,
	/* 0x00A */ LEVEL_MULTIPLAYER,
	/* 0x00B */ LEVEL_STORY,
	/* 0x00C */ LEVEL_TEST,
	/* 0x00D */ LEVEL_SHARED,
} level_indexes;

typedef enum requirement_item {
	/* 0x000 */ REQITEM_NONE,
	/* 0x001 */ REQITEM_KONG,
	/* 0x002 */ REQITEM_MOVE,
	/* 0x003 */ REQITEM_GOLDENBANANA,
	/* 0x004 */ REQITEM_BLUEPRINT,
	/* 0x005 */ REQITEM_FAIRY,
	/* 0x006 */ REQITEM_KEY,
	/* 0x007 */ REQITEM_CROWN,
	/* 0x008 */ REQITEM_COMPANYCOIN,
	/* 0x009 */ REQITEM_MEDAL,
	/* 0x00A */ REQITEM_BEAN,
	/* 0x00B */ REQITEM_PEARL,
	/* 0x00C */ REQITEM_RAINBOWCOIN,
	/* 0x00D */ REQITEM_ICETRAP,
	/* 0x00E */ REQITEM_GAMEPERCENTAGE,
	/* 0x00F */ REQITEM_COLOREDBANANA,
} requirement_item;

typedef enum item_ids { 
	/* 0x000 */ ITEMID_CB,
	/* 0x001 */ ITEMID_COINS,
	/* 0x002 */ ITEMID_STANDARDAMMO,
	/* 0x003 */ ITEMID_HOMINGAMMO,
	/* 0x004 */ ITEMID_ORANGES,
	/* 0x005 */ ITEMID_CRYSTALS,
	/* 0x006 */ ITEMID_FILM,
	/* 0x007 */ ITEMID_INSTRUMENTENERGY,
	/* 0x008 */ ITEMID_GBKONG,
	/* 0x009 */ ITEMID_GBS,
	/* 0x00A */ ITEMID_MULTIBUNCH,
	/* 0x00B */ ITEMID_RACECOIN,
	/* 0x00C */ ITEMID_BPFAIRY,
	/* 0x00D */ ITEMID_CBS_0,
	/* 0x00E */ ITEMID_MOVECOST,
} item_ids;

typedef enum enum_bonus_skin {
    /* 0x000 */ SKIN_GB,
    /* 0x001 */ SKIN_KONG_DK,
    /* 0x002 */ SKIN_KONG_DIDDY,
    /* 0x003 */ SKIN_KONG_LANKY,
    /* 0x004 */ SKIN_KONG_TINY,
    /* 0x005 */ SKIN_KONG_CHUNKY,
    /* 0x006 */ SKIN_BLUEPRINT,
    /* 0x007 */ SKIN_NINTENDO_COIN,
    /* 0x008 */ SKIN_RAREWARE_COIN,
    /* 0x009 */ SKIN_KEY,
    /* 0x00A */ SKIN_CROWN,
    /* 0x00B */ SKIN_MEDAL,
    /* 0x00C */ SKIN_POTION,
    /* 0x00D */ SKIN_BEAN,
    /* 0x00E */ SKIN_PEARL,
    /* 0x00F */ SKIN_FAIRY,
    /* 0x010 */ SKIN_RAINBOW_COIN,
    /* 0x011 */ SKIN_FAKE_ITEM,
    /* 0x012 */ SKIN_JUNK_ITEM,
    /* 0x013 */ SKIN_CRANKY,
    /* 0x014 */ SKIN_FUNKY,
    /* 0x015 */ SKIN_CANDY,
    /* 0x016 */ SKIN_SNIDE,
    /* ----- */ SKIN_TERMINATOR,
} enum_bonus_skin;