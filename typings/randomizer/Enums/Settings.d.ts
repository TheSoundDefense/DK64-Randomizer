export enum ActivateAllBananaports {
    off = 0,
    all = 1,
    isles = 2,
}

export enum BananaportRando {
    off = 0,
    in_level = 1,
    crossmap_coupled = 2,
    crossmap_decoupled = 3,
}

export enum BigHeadMode {
    off = 0,
    big = 1,
    small = 2,
    random = 3,
}

export enum CBRando {
    off = 0,
    on = 1,
    on_with_isles = 2,
}

export enum CharacterColors {
    vanilla = 0,
    randomized = 1,
    custom = 2,
}

export enum ColorblindMode {
    off = 0,
    prot = 1,
    deut = 2,
    trit = 3,
}

export enum CrownEnemyRando {
    off = 0,
    easy = 1,
    medium = 2,
    hard = 3,
}

export enum DamageAmount {
    default = 0,
    double = 1,
    quad = 2,
    ohko = 3,
}

export enum DPadDisplays {
    off = 0,
    on = 1,
    minimal = 2,
}

export enum ExcludedSongs {
    wrinkly = 1,
    transformation = 2,
    pause_music = 3,
    sub_areas = 4,
}

export enum ExtraCutsceneSkips {
    off = 0,
    press = 1,
    auto = 2,
}

export enum FasterChecksSelected {
    factory_toy_monster_fight = 1,
    factory_piano_game = 2,
    factory_diddy_rnd = 3,
    factory_arcade_round_1 = 4,
    factory_car_race = 5,
    galleon_seal_race = 6,
    galleon_mech_fish = 7,
    forest_mill_conveyor = 8,
    forest_owl_race = 9,
    forest_rabbit_race = 10,
    caves_ice_tomato_minigame = 11,
    castle_minecart = 12,
    castle_car_race = 13,
    jetpac = 14,
    arcade = 15,
}

export enum FillAlgorithm {
    forward = 0,
    assumed = 1,
    random = 2,
    careful_random = 3,
}

export enum FreeTradeSetting {
    none = 0,
    not_blueprints = 1,
    major_collectibles = 2,
}

export enum FungiTimeSetting {
    day = 0,
    night = 1,
    random = 2,
    dusk = 3,
    progressive = 4,
}

export enum GalleonWaterSetting {
    lowered = 0,
    raised = 1,
    random = 2,
}

export enum GlitchesSelected {
    advanced_platforming = 1,
    b_locker_skips = 2,
    boulder_clips = 3,
    general_clips = 4,
    ledge_clips = 5,
    moonkicks = 6,
    phase_swimming = 7,
    phase_walking = 8,
    skew = 9,
    spawn_snags = 10,
    swim_through_shores = 11,
    tag_barrel_storage = 12,
    troff_n_scoff_skips = 13,
    moontail = 14,
}

export enum HelmDoorItem {
    vanilla = 0,
    opened = 1,
    medium_random = 2,
    req_gb = 3,
    req_bp = 4,
    req_companycoins = 5,
    req_key = 6,
    req_medal = 7,
    req_crown = 8,
    req_fairy = 9,
    req_rainbowcoin = 10,
    req_bean = 11,
    req_pearl = 12,
    easy_random = 13,
    hard_random = 14,
}

export enum HelmSetting {
    default = 0,
    skip_start = 1,
    skip_all = 2,
}

export enum HelmBonuses {
    zero = 0,
    one = 1,
    two = 2,
}

export enum HardBossesSelected {
    fast_mad_jack = 1,
    alternative_mad_jack_kongs = 2,
    pufftoss_star_rando = 3,
    pufftoss_star_raised = 4,
    kut_out_phase_rando = 5,
}

export enum HardModeSelected {
    null_option_0 = 1,
    null_option_1 = 2,
    hard_enemies = 3,
    water_is_lava = 4,
    reduced_fall_damage_threshold = 5,
    shuffled_jetpac_enemies = 6,
    lower_max_refill_amounts = 7,
    strict_helm_timer = 8,
    donk_in_the_dark_world = 9,
    donk_in_the_sky = 10,
    angry_caves = 11,
}

export enum IceTrapFrequency {
    rare = 0,
    mild = 1,
    common = 2,
    frequent = 3,
    pain = 4,
}

export enum ItemRandoListSelected {
    shop = 1,
    banana = 2,
    toughbanana = 3,
    crown = 4,
    blueprint = 5,
    key = 6,
    medal = 7,
    nintendocoin = 8,
    kong = 9,
    fairy = 10,
    rainbowcoin = 11,
    beanpearl = 12,
    fakeitem = 13,
    junkitem = 14,
    crateitem = 15,
    rarewarecoin = 16,
    shopowners = 17,
    hint = 18,
}

export enum KasplatRandoSetting {
    off = 0,
    vanilla_locations = 1,
    location_shuffle = 2,
}

export enum RandomModels {
    off = 0,
    random = 1,
    extreme = 2,
}

export enum KrushaUi {
    no_slot = 0,
    dk = 1,
    diddy = 2,
    lanky = 3,
    tiny = 4,
    chunky = 5,
    random = 6,
}

export enum KongModels {
    default = 0,
    disco_chunky = 1,
    krusha = 2,
    krool_fight = 3,
    krool_cutscene = 4,
    cranky = 5,
    candy = 6,
    funky = 7,
}

export enum LevelRandomization {
    vanilla = 0,
    level_order = 1,
    loadingzone = 2,
    loadingzonesdecoupled = 3,
    level_order_complex = 4,
}

export enum LogicType {
    glitchless = 1,
    glitch = 2,
    nologic = 3,
}

export enum MicrohintsEnabled {
    off = 0,
    base = 1,
    all = 2,
}

export enum MinigameBarrels {
    normal = 0,
    skip = 1,
    random = 2,
    selected = 3,
}

export enum MinigamesListSelected {
    batty_barrel_bandit = 1,
    big_bug_bash = 2,
    busy_barrel_barrage = 3,
    mad_maze_maul = 4,
    minecart_mayhem = 5,
    beaver_bother = 6,
    teetering_turtle_trouble = 7,
    stealthy_snoop = 8,
    stash_snatch = 9,
    splish_splash_salvage = 10,
    speedy_swing_sortie = 11,
    krazy_kong_klamour = 12,
    searchlight_seek = 13,
    kremling_kosh = 14,
    peril_path_panic = 15,
    helm_minigames = 16,
    arenas = 17,
    training_minigames = 18,
}

export enum MiscChangesSelected {
    auto_dance_skip = 1,
    fast_boot = 2,
    calm_caves = 3,
    animal_buddies_grab_items = 4,
    reduced_lag = 5,
    remove_extraneous_cutscenes = 6,
    hint_textbox_hold = 7,
    remove_wrinkly_puzzles = 8,
    fast_picture_taking = 9,
    hud_hotkey = 10,
    ammo_swap = 11,
    homing_balloons = 12,
    fast_transform_animation = 13,
    troff_n_scoff_audio_indicator = 14,
    lowered_aztec_lobby_bonus = 15,
    quicker_galleon_star = 16,
    vanilla_bug_fixes = 17,
    save_k_rool_progress = 18,
    small_bananas_always_visible = 19,
    fast_hints = 20,
    brighten_mad_maze_maul_enemies = 21,
    raise_fungi_dirt_patch = 22,
    global_instrument = 23,
    fast_pause_transitions = 24,
    cannon_game_better_control = 25,
    better_fairy_camera = 26,
    remove_enemy_cabin_timer = 27,
    remove_galleon_ship_timers = 28,
    japes_bridge_permanently_extended = 29,
}

export enum MoveRando {
    off = 0,
    on = 1,
    cross_purchase = 2,
    start_with = 3,
    item_shuffle = 4,
}

export enum MusicFilters {
    length = 1,
    location = 2,
}

export enum PuzzleRando {
    off = 0,
    easy = 1,
    medium = 2,
    hard = 3,
    chaos = 4,
}

export enum RandomPrices {
    vanilla = 0,
    free = 1,
    low = 2,
    medium = 3,
    high = 4,
    extreme = 5,
}

export enum RemovedBarriersSelected {
    japes_coconut_gates = 1,
    japes_shellhive_gate = 2,
    aztec_tunnel_door = 3,
    aztec_5dtemple_switches = 4,
    aztec_llama_switches = 5,
    factory_production_room = 6,
    factory_testing_gate = 7,
    galleon_lighthouse_gate = 8,
    galleon_shipyard_area_gate = 9,
    castle_crypt_doors = 10,
    galleon_seasick_ship = 11,
    forest_green_tunnel = 12,
    forest_yellow_tunnel = 13,
    caves_igloo_pads = 14,
    caves_ice_walls = 15,
    galleon_treasure_room = 16,
    aztec_tiny_temple_ice = 17,
}

export enum ShockwaveStatus {
    vanilla = 0,
    shuffled = 1,
    shuffled_decoupled = 2,
    start_with = 3,
}

export enum ShuffleLoadingZones {
    none = 0,
    levels = 1,
    all = 2,
}

export enum ShufflePortLocations {
    off = 0,
    vanilla_only = 1,
    half_vanilla = 2,
    on = 3,
}

export enum SlamRequirement {
    green = 0,
    blue = 1,
    red = 2,
    random = 3,
}

export enum SoundType {
    stereo = 0,
    mono = 1,
    surround = 2,
}

export enum SwitchsanityLevel {
    off = 0,
    helm_access = 1,
    all = 2,
}

export enum TrainingBarrels {
    normal = 0,
    shuffled = 1,
}

export enum WinCondition {
    beat_krool = 0,
    get_key8 = 1,
    all_fairies = 2,
    all_blueprints = 3,
    all_medals = 4,
    poke_snap = 5,
    all_keys = 6,
}

export enum WinConditionComplex {
    beat_krool = 0,
    get_key8 = 1,
    krem_kapture = 2,
    req_gb = 3,
    req_bp = 4,
    req_companycoins = 5,
    req_key = 6,
    req_medal = 7,
    req_crown = 8,
    req_fairy = 9,
    req_rainbowcoin = 10,
    req_bean = 11,
    req_pearl = 12,
    easy_random = 13,
    medium_random = 14,
    hard_random = 15,
    dk_rap_items = 16,
}

export enum WrinklyHints {
    off = 0,
    standard = 1,
    cryptic = 2,
    fixed_racing = 3,
    item_hinting = 4,
    item_hinting_advanced = 5,
}

export enum SpoilerHints {
    off = 0,
    vial_colors = 1,
    points = 2,
}
