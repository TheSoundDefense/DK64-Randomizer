"""File containing enums to represent all settings."""

from __future__ import annotations

from enum import IntEnum, auto, Enum
from typing import TYPE_CHECKING
import json

from randomizer.Enums.Kongs import Kongs
from randomizer.Enums.Items import Items
from randomizer.Lists.EnemyTypes import Enemies
from randomizer.Enums.Maps import Maps

if TYPE_CHECKING:
    from randomizer.Enums.Settings import (
        ActivateAllBananaports,
        ShufflePortLocations,
        BananaportRando,
        BigHeadMode,
        CBRando,
        CharacterColors,
        ColorblindMode,
        CrownEnemyRando,
        DamageAmount,
        DPadDisplays,
        ExcludedSongs,
        ExtraCutsceneSkips,
        FasterChecksSelected,
        FreeTradeSetting,
        FungiTimeSetting,
        GalleonWaterSetting,
        GlitchesSelected,
        HardBossesSelected,
        HardModeSelected,
        IceTrapFrequency,
        ItemRandoListSelected,
        KasplatRandoSetting,
        KrushaUi,
        LevelRandomization,
        LogicType,
        MicrohintsEnabled,
        MinigamesListSelected,
        MiscChangesSelected,
        MoveRando,
        MusicFilters,
        PuzzleRando,
        RandomModels,
        RandomPrices,
        RemovedBarriersSelected,
        ShockwaveStatus,
        ShuffleLoadingZones,
        SoundType,
        SwitchsanityLevel,
        TrainingBarrels,
        WinCondition,
        WinConditionComplex,
        WrinklyHints,
        SpoilerHints,
        SlamRequirement,
        KongModels,
        MinigameBarrels,
        HelmDoorItem,
        HelmSetting,
        HelmBonuses,
    )
# Each select-based setting should have its own associated enum class. The enum
# values should exactly match the input values in the HTML (not the IDs).
# Do not change the values of any enums in this file, or settings strings will
# break.


# Convert JSON string to a Python dictionary
with open("randomizer/Enums/Settings.json") as f:
    enums_data = json.load(f)


def create_enum_class(name, values):
    """
    Dynamically creates an Enum or IntEnum class based on the JSON data.
    :param name: Name of the enum class
    :param values: Dictionary of enum members
    :return: Enum class
    """
    # Prepare the enum members as a dictionary of key=value pairs
    enum_members = {key: auto() if value == "auto" else value for key, value in values.items()}

    # Check if any of the members use "auto". If so, use Enum, otherwise use IntEnum.
    return IntEnum(name, enum_members)


# Create enums dynamically and store them in the globals dictionary to make them importable
for enum_name, enum_values in enums_data.items():
    globals()[enum_name] = create_enum_class(enum_name, enum_values)


# ALL SELECT-BASED SETTINGS NEED AN ENTRY HERE!
# A dictionary that maps setting names to the associated enum for that specific setting.
# The key for each enum must exactly match the HTML name of the associated select.
SettingsMap = {
    "activate_all_bananaports": ActivateAllBananaports,
    "bananaport_placement_rando": ShufflePortLocations,
    "bananaport_rando": BananaportRando,
    "big_head_mode": BigHeadMode,
    "bonus_barrels": MinigameBarrels,
    "cb_rando": CBRando,
    "chunky_colors": CharacterColors,
    "coin_door_item": HelmDoorItem,
    "colorblind_mode": ColorblindMode,
    "crown_door_item": HelmDoorItem,
    "crown_enemy_rando": CrownEnemyRando,
    "damage_amount": DamageAmount,
    "diddy_colors": CharacterColors,
    "dk_colors": CharacterColors,
    "dpad_display": DPadDisplays,
    "enemies_selected": Enemies,
    "enguarde_colors": CharacterColors,
    "excluded_songs_selected": ExcludedSongs,
    "free_trade_setting": FreeTradeSetting,
    "fungi_time": FungiTimeSetting,
    "galleon_water": GalleonWaterSetting,
    "gb_colors": CharacterColors,
    "glitches_selected": GlitchesSelected,
    "hard_bosses_selected": HardBossesSelected,
    "hard_mode_selected": HardModeSelected,
    "helm_barrels": MinigameBarrels,
    "helm_room_bonus_count": HelmBonuses,
    "helm_setting": HelmSetting,
    "ice_trap_frequency": IceTrapFrequency,
    "item_rando_list_selected": ItemRandoListSelected,
    "kasplat_rando_setting": KasplatRandoSetting,
    "krusha_ui": KrushaUi,
    "lanky_colors": CharacterColors,
    "level_randomization": LevelRandomization,
    "logic_type": LogicType,
    "microhints_enabled": MicrohintsEnabled,
    "minigames_list_selected": MinigamesListSelected,
    "misc_changes_selected": MiscChangesSelected,
    "more_cutscene_skips": ExtraCutsceneSkips,
    "move_rando": MoveRando,
    "music_filtering_selected": MusicFilters,
    "rambi_colors": CharacterColors,
    "random_models": RandomModels,
    "random_prices": RandomPrices,
    "shockwave_status": ShockwaveStatus,
    "shuffle_loading_zones": ShuffleLoadingZones,
    "sound_type": SoundType,
    "starting_keys_list_selected": Items,
    "starting_move_list_selected": Items,
    "switchsanity": SwitchsanityLevel,
    "random_starting_move_list_selected": Items,
    "tiny_colors": CharacterColors,
    "training_barrels": TrainingBarrels,
    "warp_level_list_selected": Maps,
    "win_condition": WinCondition,
    "win_condition_item": WinConditionComplex,
    "wrinkly_hints": WrinklyHints,
    "spoiler_hints": SpoilerHints,
    "starting_kong": Kongs,
    "remove_barriers_selected": RemovedBarriersSelected,
    "faster_checks_selected": FasterChecksSelected,
    "kong_model_dk": KongModels,
    "kong_model_diddy": KongModels,
    "kong_model_lanky": KongModels,
    "kong_model_tiny": KongModels,
    "kong_model_chunky": KongModels,
    "chunky_phase_slam_req": SlamRequirement,
    "puzzle_rando_difficulty": PuzzleRando,
}


class SettingsStringEnum(IntEnum):
    """Maps setting names to key values, for use in the settings string.

    Changing any of the existing values will cause generated settings strings
        to break. Only add new values.

    Do not delete settings from this enum. Instead, add an entry to the
        DeprecatedSettings set below. This will be cleaned up with every major
        release.

    ALL SETTINGS NEED AN ENTRY HERE!
    """

    activate_all_bananaports = 1
    alter_switch_allocation = 2
    auto_keys = 3
    bananaport_rando = 4
    blocker_0 = 5
    blocker_1 = 6
    blocker_2 = 7
    blocker_3 = 8
    blocker_4 = 9
    blocker_5 = 10
    blocker_6 = 11
    blocker_7 = 12
    blocker_text = 13
    bonus_barrel_auto_complete = 14
    bonus_barrel_rando = 15
    boss_kong_rando = 16
    boss_location_rando = 17
    cb_rando = 18
    coin_door_item = 19
    coin_door_item_count = 20
    crown_door_item = 21
    crown_door_item_count = 22
    crown_enemy_rando = 23
    crown_placement_rando = 24
    damage_amount = 25
    disable_tag_barrels = 26
    enable_shop_hints = 27
    enable_tag_anywhere = 28
    enemies_selected = 29
    enemy_rando = 30
    enemy_speed_rando = 31
    faster_checks_enabled = 32
    fast_start_beginning_of_game = 33
    fast_warps = 34
    fps_display = 35
    free_trade_setting = 36
    generate_spoilerlog = 37
    glitches_selected = 38
    hard_blockers = 39
    hard_bosses = 40
    hard_enemies = 41
    hard_level_progression = 42
    hard_shooting = 43
    hard_troff_n_scoff = 44
    helm_hurry = 45
    helm_phase_count = 46
    helm_phase_order_rando = 47
    helm_random = 48
    helm_setting = 49
    helmhurry_list_banana_medal = 50
    helmhurry_list_battle_crown = 51
    helmhurry_list_bean = 52
    helmhurry_list_blueprint = 53
    helmhurry_list_boss_key = 54
    helmhurry_list_colored_bananas = 55
    helmhurry_list_company_coins = 56
    helmhurry_list_fairies = 57
    helmhurry_list_golden_banana = 58
    helmhurry_list_ice_traps = 59
    helmhurry_list_kongs = 60
    helmhurry_list_move = 61
    helmhurry_list_pearl = 62
    helmhurry_list_rainbow_coin = 63
    helmhurry_list_starting_time = 64
    high_req = 65
    item_rando_list_selected = 66
    item_reward_previews = 67
    kasplat_rando_setting = 68
    key_8_helm = 69
    keys_random = 70
    kong_rando = 71
    krool_access = 72
    krool_key_count = 73
    krool_phase_count = 74
    krool_phase_order_rando = 75
    krool_random = 76
    krusha_ui = 77
    level_randomization = 78
    logic_type = 79
    maximize_helm_blocker = 80
    medal_cb_req = 81
    medal_requirement = 82
    microhints_enabled = 83
    minigames_list_selected = 84
    misc_changes_selected = 85
    move_rando = 86
    no_healing = 87
    no_melons = 88
    open_levels = 89
    open_lobbies = 90
    perma_death = 91
    portal_numbers = 92
    puzzle_rando = 93
    quality_of_life = 94
    random_fairies = 95
    random_medal_requirement = 96
    random_patches = 97
    random_prices = 98
    random_starting_region = 99
    randomize_blocker_required_amounts = 100
    randomize_cb_required_amounts = 101
    randomize_pickups = 102
    rareware_gb_fairies = 103
    select_keys = 104
    shockwave_status = 105
    shop_indicator = 106
    shorten_boss = 107
    shuffle_items = 108
    shuffle_shops = 109
    smaller_shops = 110
    starting_keys_list_selected = 111
    starting_kongs_count = 112
    starting_random = 113
    tns_location_rando = 114
    training_barrels = 115
    troff_0 = 116
    troff_1 = 117
    troff_2 = 118
    troff_3 = 119
    troff_4 = 120
    troff_5 = 121
    troff_6 = 122
    troff_text = 123
    warp_level_list_selected = 124
    warp_to_isles = 125
    win_condition = 126
    wrinkly_available = 127
    wrinkly_hints = 128
    wrinkly_location_rando = 129
    coin_rando = 130
    vanilla_door_rando = 131
    starting_moves_count = 132
    enable_plandomizer = 133
    hard_mode_selected = 134
    hard_mode = 135
    more_cutscene_skips = 136
    spoiler_hints = 137
    spoiler_include_woth_count = 138
    points_list_kongs = 139
    points_list_keys = 140
    points_list_guns = 141
    points_list_instruments = 142
    points_list_training_moves = 143
    points_list_important_shared = 144
    points_list_pad_moves = 145
    points_list_barrel_moves = 146
    points_list_active_moves = 147
    points_list_bean = 148
    random_crates = 149
    choose_starting_moves = 150
    starting_move_list_selected = 151
    start_with_slam = 152
    spoiler_include_level_order = 153
    enable_progressive_hints = 154
    progressive_hint_text = 155
    random_starting_move_list_selected = 156
    enemy_drop_rando = 157
    dim_solved_hints = 158
    starting_kong = 159
    switchsanity = 160
    fungi_time = 161
    galleon_water = 162
    remove_barriers_enabled = 163
    remove_barriers_selected = 164
    faster_checks_selected = 165
    k_rool_vanilla_requirement = 166
    disable_hard_minigames = 167
    chaos_blockers = 168
    mermaid_gb_pearls = 169
    kong_model_dk = 170
    kong_model_diddy = 171
    kong_model_lanky = 172
    kong_model_tiny = 173
    kong_model_chunky = 174
    helm_room_bonus_count = 175
    dk_portal_location_rando = 176
    serious_hints = 177
    cannons_require_blast = 178
    chunky_phase_slam_req = 179
    shuffle_helm_location = 180
    points_list_fairy_moves = 181
    points_list_shopkeepers = 182
    chaos_ratio = 183
    krool_in_boss_pool = 184
    enemy_kill_crown_timer = 185
    hard_bosses_selected = 186
    ice_trap_frequency = 187
    ice_traps_damage = 188
    puzzle_rando_difficulty = 189
    win_condition_item = 190
    win_condition_count = 191
    bananaport_placement_rando = 192


# If a setting needs to be removed, add it to this set instead of removing it
# from the enum above.
DeprecatedSettings = {
    SettingsStringEnum.hard_enemies,
    SettingsStringEnum.choose_starting_moves,
    SettingsStringEnum.open_levels,
    SettingsStringEnum.high_req,
    SettingsStringEnum.krusha_ui,
    SettingsStringEnum.hard_level_progression,
    SettingsStringEnum.puzzle_rando,
    SettingsStringEnum.win_condition,
}


class SettingsStringDataType(IntEnum):
    """Enum for mapping settings to data types for encryption/decryption."""

    bool = auto()
    # Can represent up to 16 values (-8 to 7).
    int4 = auto()
    # Can represent up to 256 values (-128 to 127).
    int8 = auto()
    # Can represent up to 65,536 values (-32,768 to 32,767).
    int16 = auto()
    # Will be shrunk down to the smallest possible size.
    var_int = auto()
    str = auto()
    list = auto()
    # Can represent up to 65,536 values (0 to 65535)
    u16 = auto()


# ALL SETTINGS NEED AN ENTRY HERE!
# This maps settings to the data types that will be used to encode them in the
# settings string. Any enum-based settings should use that enum as their data
# type, to shrink the payload as much as possible.
#
# When adding an int setting, make sure to use the smallest int possible.
# This will reduce the characters added to the settings string. See the above
# enum for valid int values.
#
# If you are using the var_int type, you must use the addSettingIntRange()
# function below to specify the valid int range.
SettingsStringTypeMap = {
    SettingsStringEnum.activate_all_bananaports: ActivateAllBananaports,
    SettingsStringEnum.alter_switch_allocation: SettingsStringDataType.bool,
    SettingsStringEnum.auto_keys: SettingsStringDataType.bool,
    SettingsStringEnum.bananaport_placement_rando: ShufflePortLocations,
    SettingsStringEnum.bananaport_rando: BananaportRando,
    SettingsStringEnum.blocker_0: SettingsStringDataType.var_int,
    SettingsStringEnum.blocker_1: SettingsStringDataType.var_int,
    SettingsStringEnum.blocker_2: SettingsStringDataType.var_int,
    SettingsStringEnum.blocker_3: SettingsStringDataType.var_int,
    SettingsStringEnum.blocker_4: SettingsStringDataType.var_int,
    SettingsStringEnum.blocker_5: SettingsStringDataType.var_int,
    SettingsStringEnum.blocker_6: SettingsStringDataType.var_int,
    SettingsStringEnum.blocker_7: SettingsStringDataType.var_int,
    SettingsStringEnum.blocker_text: SettingsStringDataType.var_int,
    SettingsStringEnum.bonus_barrel_auto_complete: SettingsStringDataType.bool,
    SettingsStringEnum.bonus_barrel_rando: SettingsStringDataType.bool,
    SettingsStringEnum.boss_kong_rando: SettingsStringDataType.bool,
    SettingsStringEnum.boss_location_rando: SettingsStringDataType.bool,
    SettingsStringEnum.cb_rando: CBRando,
    SettingsStringEnum.coin_door_item: HelmDoorItem,
    SettingsStringEnum.coin_door_item_count: SettingsStringDataType.var_int,
    SettingsStringEnum.random_crates: SettingsStringDataType.bool,
    SettingsStringEnum.crown_placement_rando: SettingsStringDataType.bool,
    SettingsStringEnum.crown_door_item: HelmDoorItem,
    SettingsStringEnum.crown_door_item_count: SettingsStringDataType.var_int,
    SettingsStringEnum.crown_enemy_rando: CrownEnemyRando,
    SettingsStringEnum.coin_rando: SettingsStringDataType.bool,
    SettingsStringEnum.damage_amount: DamageAmount,
    SettingsStringEnum.disable_tag_barrels: SettingsStringDataType.bool,
    SettingsStringEnum.dk_portal_location_rando: SettingsStringDataType.bool,
    SettingsStringEnum.enable_plandomizer: SettingsStringDataType.bool,
    SettingsStringEnum.enable_shop_hints: SettingsStringDataType.bool,
    SettingsStringEnum.enable_tag_anywhere: SettingsStringDataType.bool,
    SettingsStringEnum.enemies_selected: SettingsStringDataType.list,
    SettingsStringEnum.enemy_rando: SettingsStringDataType.bool,
    SettingsStringEnum.enemy_speed_rando: SettingsStringDataType.bool,
    SettingsStringEnum.faster_checks_enabled: SettingsStringDataType.bool,
    SettingsStringEnum.fast_start_beginning_of_game: SettingsStringDataType.bool,
    SettingsStringEnum.fast_warps: SettingsStringDataType.bool,
    SettingsStringEnum.fps_display: SettingsStringDataType.bool,
    SettingsStringEnum.free_trade_setting: FreeTradeSetting,
    SettingsStringEnum.generate_spoilerlog: SettingsStringDataType.bool,
    SettingsStringEnum.glitches_selected: SettingsStringDataType.list,
    SettingsStringEnum.hard_mode: SettingsStringDataType.bool,
    SettingsStringEnum.hard_mode_selected: SettingsStringDataType.list,
    SettingsStringEnum.hard_blockers: SettingsStringDataType.bool,
    SettingsStringEnum.hard_bosses: SettingsStringDataType.bool,
    SettingsStringEnum.hard_bosses_selected: SettingsStringDataType.list,
    SettingsStringEnum.hard_enemies: SettingsStringDataType.bool,
    SettingsStringEnum.hard_level_progression: SettingsStringDataType.bool,
    SettingsStringEnum.hard_shooting: SettingsStringDataType.bool,
    SettingsStringEnum.hard_troff_n_scoff: SettingsStringDataType.bool,
    SettingsStringEnum.helm_hurry: SettingsStringDataType.bool,
    SettingsStringEnum.helm_phase_count: SettingsStringDataType.var_int,
    SettingsStringEnum.helm_phase_order_rando: SettingsStringDataType.bool,
    SettingsStringEnum.helm_random: SettingsStringDataType.bool,
    SettingsStringEnum.helm_room_bonus_count: HelmBonuses,
    SettingsStringEnum.helm_setting: HelmSetting,
    SettingsStringEnum.helmhurry_list_banana_medal: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_battle_crown: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_bean: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_blueprint: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_boss_key: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_colored_bananas: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_company_coins: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_fairies: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_golden_banana: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_ice_traps: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_kongs: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_move: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_pearl: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_rainbow_coin: SettingsStringDataType.int16,
    SettingsStringEnum.helmhurry_list_starting_time: SettingsStringDataType.u16,
    SettingsStringEnum.high_req: SettingsStringDataType.bool,
    SettingsStringEnum.item_rando_list_selected: SettingsStringDataType.list,
    SettingsStringEnum.item_reward_previews: SettingsStringDataType.bool,
    SettingsStringEnum.kasplat_rando_setting: KasplatRandoSetting,
    SettingsStringEnum.key_8_helm: SettingsStringDataType.bool,
    SettingsStringEnum.keys_random: SettingsStringDataType.bool,
    SettingsStringEnum.kong_model_dk: KongModels,
    SettingsStringEnum.kong_model_diddy: KongModels,
    SettingsStringEnum.kong_model_lanky: KongModels,
    SettingsStringEnum.kong_model_tiny: KongModels,
    SettingsStringEnum.kong_model_chunky: KongModels,
    SettingsStringEnum.kong_rando: SettingsStringDataType.bool,
    SettingsStringEnum.krool_access: SettingsStringDataType.bool,
    SettingsStringEnum.krool_key_count: SettingsStringDataType.var_int,
    SettingsStringEnum.krool_phase_count: SettingsStringDataType.var_int,
    SettingsStringEnum.krool_phase_order_rando: SettingsStringDataType.bool,
    SettingsStringEnum.krool_random: SettingsStringDataType.bool,
    SettingsStringEnum.krusha_ui: KrushaUi,
    SettingsStringEnum.level_randomization: LevelRandomization,
    SettingsStringEnum.logic_type: LogicType,
    SettingsStringEnum.maximize_helm_blocker: SettingsStringDataType.bool,
    SettingsStringEnum.medal_cb_req: SettingsStringDataType.var_int,
    SettingsStringEnum.medal_requirement: SettingsStringDataType.var_int,
    SettingsStringEnum.microhints_enabled: MicrohintsEnabled,
    SettingsStringEnum.minigames_list_selected: SettingsStringDataType.list,
    SettingsStringEnum.misc_changes_selected: SettingsStringDataType.list,
    SettingsStringEnum.more_cutscene_skips: ExtraCutsceneSkips,
    SettingsStringEnum.move_rando: MoveRando,
    SettingsStringEnum.no_healing: SettingsStringDataType.bool,
    SettingsStringEnum.no_melons: SettingsStringDataType.bool,
    SettingsStringEnum.open_levels: SettingsStringDataType.bool,
    SettingsStringEnum.open_lobbies: SettingsStringDataType.bool,
    SettingsStringEnum.perma_death: SettingsStringDataType.bool,
    SettingsStringEnum.portal_numbers: SettingsStringDataType.bool,
    SettingsStringEnum.puzzle_rando: SettingsStringDataType.bool,
    SettingsStringEnum.quality_of_life: SettingsStringDataType.bool,
    SettingsStringEnum.random_fairies: SettingsStringDataType.bool,
    SettingsStringEnum.random_medal_requirement: SettingsStringDataType.bool,
    SettingsStringEnum.random_patches: SettingsStringDataType.bool,
    SettingsStringEnum.random_prices: RandomPrices,
    SettingsStringEnum.random_starting_region: SettingsStringDataType.bool,
    SettingsStringEnum.randomize_blocker_required_amounts: SettingsStringDataType.bool,
    SettingsStringEnum.randomize_cb_required_amounts: SettingsStringDataType.bool,
    SettingsStringEnum.randomize_pickups: SettingsStringDataType.bool,
    SettingsStringEnum.rareware_gb_fairies: SettingsStringDataType.var_int,
    SettingsStringEnum.select_keys: SettingsStringDataType.bool,
    SettingsStringEnum.shockwave_status: ShockwaveStatus,
    SettingsStringEnum.shop_indicator: SettingsStringDataType.bool,
    SettingsStringEnum.shorten_boss: SettingsStringDataType.bool,
    SettingsStringEnum.shuffle_items: SettingsStringDataType.bool,
    SettingsStringEnum.shuffle_shops: SettingsStringDataType.bool,
    SettingsStringEnum.smaller_shops: SettingsStringDataType.bool,
    SettingsStringEnum.starting_keys_list_selected: SettingsStringDataType.list,
    SettingsStringEnum.starting_kongs_count: SettingsStringDataType.var_int,
    SettingsStringEnum.starting_moves_count: SettingsStringDataType.var_int,
    SettingsStringEnum.starting_random: SettingsStringDataType.bool,
    SettingsStringEnum.tns_location_rando: SettingsStringDataType.bool,
    SettingsStringEnum.training_barrels: TrainingBarrels,
    SettingsStringEnum.troff_0: SettingsStringDataType.var_int,
    SettingsStringEnum.troff_1: SettingsStringDataType.var_int,
    SettingsStringEnum.troff_2: SettingsStringDataType.var_int,
    SettingsStringEnum.troff_3: SettingsStringDataType.var_int,
    SettingsStringEnum.troff_4: SettingsStringDataType.var_int,
    SettingsStringEnum.troff_5: SettingsStringDataType.var_int,
    SettingsStringEnum.troff_6: SettingsStringDataType.var_int,
    SettingsStringEnum.troff_text: SettingsStringDataType.var_int,
    SettingsStringEnum.vanilla_door_rando: SettingsStringDataType.bool,
    SettingsStringEnum.warp_level_list_selected: SettingsStringDataType.list,
    SettingsStringEnum.warp_to_isles: SettingsStringDataType.bool,
    SettingsStringEnum.win_condition: WinCondition,
    SettingsStringEnum.win_condition_item: WinConditionComplex,
    SettingsStringEnum.win_condition_count: SettingsStringDataType.var_int,
    SettingsStringEnum.wrinkly_available: SettingsStringDataType.bool,
    SettingsStringEnum.wrinkly_hints: WrinklyHints,
    SettingsStringEnum.wrinkly_location_rando: SettingsStringDataType.bool,
    SettingsStringEnum.spoiler_hints: SpoilerHints,
    SettingsStringEnum.spoiler_include_woth_count: SettingsStringDataType.bool,
    SettingsStringEnum.points_list_kongs: SettingsStringDataType.int16,
    SettingsStringEnum.points_list_keys: SettingsStringDataType.int16,
    SettingsStringEnum.points_list_guns: SettingsStringDataType.int16,
    SettingsStringEnum.points_list_instruments: SettingsStringDataType.int16,
    SettingsStringEnum.points_list_training_moves: SettingsStringDataType.int16,
    SettingsStringEnum.points_list_important_shared: SettingsStringDataType.int16,
    SettingsStringEnum.points_list_pad_moves: SettingsStringDataType.int16,
    SettingsStringEnum.points_list_barrel_moves: SettingsStringDataType.int16,
    SettingsStringEnum.points_list_active_moves: SettingsStringDataType.int16,
    SettingsStringEnum.points_list_bean: SettingsStringDataType.int16,
    SettingsStringEnum.choose_starting_moves: SettingsStringDataType.bool,
    SettingsStringEnum.starting_move_list_selected: SettingsStringDataType.list,
    SettingsStringEnum.start_with_slam: SettingsStringDataType.bool,
    SettingsStringEnum.spoiler_include_level_order: SettingsStringDataType.bool,
    SettingsStringEnum.enable_progressive_hints: SettingsStringDataType.bool,
    SettingsStringEnum.progressive_hint_text: SettingsStringDataType.var_int,
    SettingsStringEnum.random_starting_move_list_selected: SettingsStringDataType.list,
    SettingsStringEnum.enemy_drop_rando: SettingsStringDataType.bool,
    SettingsStringEnum.dim_solved_hints: SettingsStringDataType.bool,
    SettingsStringEnum.starting_kong: Kongs,
    SettingsStringEnum.switchsanity: SwitchsanityLevel,
    SettingsStringEnum.fungi_time: FungiTimeSetting,
    SettingsStringEnum.galleon_water: GalleonWaterSetting,
    SettingsStringEnum.remove_barriers_enabled: SettingsStringDataType.bool,
    SettingsStringEnum.remove_barriers_selected: SettingsStringDataType.list,
    SettingsStringEnum.faster_checks_selected: SettingsStringDataType.list,
    SettingsStringEnum.k_rool_vanilla_requirement: SettingsStringDataType.bool,
    SettingsStringEnum.disable_hard_minigames: SettingsStringDataType.bool,
    SettingsStringEnum.serious_hints: SettingsStringDataType.bool,
    SettingsStringEnum.cannons_require_blast: SettingsStringDataType.bool,
    SettingsStringEnum.chaos_blockers: SettingsStringDataType.bool,
    SettingsStringEnum.mermaid_gb_pearls: SettingsStringDataType.var_int,
    SettingsStringEnum.chunky_phase_slam_req: SlamRequirement,
    SettingsStringEnum.shuffle_helm_location: SettingsStringDataType.bool,
    SettingsStringEnum.points_list_fairy_moves: SettingsStringDataType.int16,
    SettingsStringEnum.points_list_shopkeepers: SettingsStringDataType.int16,
    SettingsStringEnum.chaos_ratio: SettingsStringDataType.int16,
    SettingsStringEnum.krool_in_boss_pool: SettingsStringDataType.bool,
    SettingsStringEnum.enemy_kill_crown_timer: SettingsStringDataType.bool,
    SettingsStringEnum.ice_trap_frequency: IceTrapFrequency,
    SettingsStringEnum.ice_traps_damage: SettingsStringDataType.bool,
    SettingsStringEnum.puzzle_rando_difficulty: PuzzleRando,
}

# ALL LIST SETTINGS NEED AN ENTRY HERE!
# Another map for list settings, for the underlying data type of the list.
SettingsStringListTypeMap = {
    SettingsStringEnum.enemies_selected: Enemies,
    SettingsStringEnum.glitches_selected: GlitchesSelected,
    SettingsStringEnum.item_rando_list_selected: ItemRandoListSelected,
    SettingsStringEnum.minigames_list_selected: MinigamesListSelected,
    SettingsStringEnum.misc_changes_selected: MiscChangesSelected,
    SettingsStringEnum.starting_keys_list_selected: Items,
    SettingsStringEnum.warp_level_list_selected: Maps,
    SettingsStringEnum.hard_mode_selected: HardModeSelected,
    SettingsStringEnum.starting_move_list_selected: Items,
    SettingsStringEnum.random_starting_move_list_selected: Items,
    SettingsStringEnum.remove_barriers_selected: RemovedBarriersSelected,
    SettingsStringEnum.faster_checks_selected: FasterChecksSelected,
    SettingsStringEnum.hard_bosses_selected: HardBossesSelected,
}

# This map specifies the minimum and maximum values for numeric settings.
SettingsStringIntRangeMap = {}


def addSettingIntRange(settingEnum: SettingsStringEnum, maxVal: int, minVal: int = 0) -> None:
    """Add an entry to the SettingsStringIntRangeMap."""
    SettingsStringIntRangeMap[settingEnum] = {"max": maxVal, "min": minVal}


# ALL NUMERIC VAR_INT SETTINGS NEED AN ENTRY HERE!
# Minimum values only need to be supplied if they are negative.
addSettingIntRange(SettingsStringEnum.blocker_0, 201)
addSettingIntRange(SettingsStringEnum.blocker_1, 201)
addSettingIntRange(SettingsStringEnum.blocker_2, 201)
addSettingIntRange(SettingsStringEnum.blocker_3, 201)
addSettingIntRange(SettingsStringEnum.blocker_4, 201)
addSettingIntRange(SettingsStringEnum.blocker_5, 201)
addSettingIntRange(SettingsStringEnum.blocker_6, 201)
addSettingIntRange(SettingsStringEnum.blocker_7, 201)
addSettingIntRange(SettingsStringEnum.blocker_text, 201)
addSettingIntRange(SettingsStringEnum.coin_door_item_count, 201)
addSettingIntRange(SettingsStringEnum.crown_door_item_count, 201)
addSettingIntRange(SettingsStringEnum.helm_phase_count, 5)
addSettingIntRange(SettingsStringEnum.krool_key_count, 8)
addSettingIntRange(SettingsStringEnum.krool_phase_count, 5)
addSettingIntRange(SettingsStringEnum.medal_cb_req, 100)
addSettingIntRange(SettingsStringEnum.medal_requirement, 40)
addSettingIntRange(SettingsStringEnum.mermaid_gb_pearls, 5)
addSettingIntRange(SettingsStringEnum.rareware_gb_fairies, 20)
addSettingIntRange(SettingsStringEnum.starting_kongs_count, 5)
addSettingIntRange(SettingsStringEnum.starting_moves_count, 40)
addSettingIntRange(SettingsStringEnum.troff_0, 500)
addSettingIntRange(SettingsStringEnum.troff_1, 500)
addSettingIntRange(SettingsStringEnum.troff_2, 500)
addSettingIntRange(SettingsStringEnum.troff_3, 500)
addSettingIntRange(SettingsStringEnum.troff_4, 500)
addSettingIntRange(SettingsStringEnum.troff_5, 500)
addSettingIntRange(SettingsStringEnum.troff_6, 500)
addSettingIntRange(SettingsStringEnum.troff_text, 500)
addSettingIntRange(SettingsStringEnum.progressive_hint_text, 201)
addSettingIntRange(SettingsStringEnum.win_condition_count, 201)
