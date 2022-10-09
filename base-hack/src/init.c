#include "../include/common.h"

static const char exittoisles[] = "EXIT TO ISLES";

typedef struct musicInfo {
	/* 0x000 */ short data[0xB0];
} musicInfo;

void fixMusicRando(void) {
	// Music
	if (Rando.music_rando_on) {
		int size = 0x160;
		musicInfo* write_space = dk_malloc(size);
		int* file_size;
		*(int*)(&file_size) = size;
		copyFromROM(0x1FFF000,write_space,&file_size,0,0,0,0);
		for (int i = 0; i < 0xB0; i++) {
			int subchannel = (write_space->data[i] & 6) >> 1;
			int channel = (write_space->data[i] & 0x78) >> 3;
			songData[i] &= 0xFF81;
			songData[i] |= (subchannel & 3) << 1;
			songData[i] |= (channel & 0xF) << 3;
		}
		complex_free(write_space);
	}
}

void writeEndSequence(void) {
	int size = 0x84;
	int* file_size;
	*(int*)(&file_size) = size;
	copyFromROM(0x1FFF800,(int*)0x807506D0,&file_size,0,0,0,0);
}

void expandSaveFile(int static_expansion, int actor_count) {
	/*
		File cannot be bigger than 0x200 bytes

		File Structure:
			0x000->0x320 = Flags
			0x320->c+0x320 = Model2
			c+0x320->c+0x645 = Kong Vars
			c+0x645->c+0x6B7 = File Global Vars

		Generalized:
			0 -> f = Flags
			f -> f+c = Model 2
			f+c -> f+c+5k = Kong Vars
			f+c+5k -> f+c+5k+0x72 = File Global Vars
	*/
	// int expansion = static_expansion;
	int expansion = static_expansion + actor_count;
	int flag_block_size = 0x320 + expansion;
	int kong_var_size = 0xA1;
	int file_info_location = flag_block_size + (5 * kong_var_size);
	int file_default_size = file_info_location + 0x72;
	// Flag Block Size
	*(short*)(0x8060E36A) = file_default_size;
	*(short*)(0x8060E31E) = file_default_size;
	*(short*)(0x8060E2C6) = file_default_size;
	*(short*)(0x8060D54A) = file_default_size;
	*(short*)(0x8060D4A2) = file_default_size;
	*(short*)(0x8060D45E) = file_default_size;
	*(short*)(0x8060D3C6) = file_default_size;
	*(short*)(0x8060D32E) = file_default_size;
	*(short*)(0x8060D23E) = file_default_size;
	*(short*)(0x8060CF62) = file_default_size;
	*(short*)(0x8060CC52) = file_default_size;
	*(short*)(0x8060C78A) = file_default_size;
	*(short*)(0x8060C352) = file_default_size;
	*(short*)(0x8060BF96) = file_default_size;
	*(short*)(0x8060BA7A) = file_default_size;

	*(short*)(0x8060BEC6) = file_info_location;
	// Model 2 Start
	*(short*)(0x8060C2F2) = flag_block_size;
	*(short*)(0x8060BCDE) = flag_block_size;
	// Reallocate Balloons + Patches
	*(short*)(0x80688BCE) = 0x320 + static_expansion; // Reallocated to just before model 2 block
}

static const short kong_flags[] = {385,6,70,66,117};
void initHack(int source) {
	if (LoadedHooks == 0) {
		if ((source == 1) || (CurrentMap == 0x28)) {
			DebugInfoOn = 1;
			*(int*)(0x80731F78) = 0; // Debug 1 Column
			*(int*)(0x8060E04C) = 0; // Prevent moves overwrite
			*(short*)(0x8060DDAA) = 0; // Writes readfile data to moves
			*(short*)(0x806C9CDE) = 7; // GiveEverything, write to bitfield. Seems to be unused but might as well
			// Strong Kong
			*(int*)(0x8067ECFC) = 0x30810002; // ANDI $at $a0 2
			*(int*)(0x8067ED00) = 0x50200003; // BEQL $at $r0 3
			// Rocketbarrel
			*(int*)(0x80682024) = 0x31810002; // ANDI $at $t4 2
			*(int*)(0x80682028) = 0x50200006; // BEQL $at $r0 0x6
			// OSprint
			*(int*)(0x8067ECE0) = 0x30810004; // ANDI $at $a0 4
			*(int*)(0x8067ECE4) = 0x10200002; // BEQZ $at, 2
			// Mini Monkey
			*(int*)(0x8067EC80) = 0x30830001; // ANDI $v1 $a0 1
			*(int*)(0x8067EC84) = 0x18600002; // BLEZ $v1 2
			// Hunky Chunky (Not Dogadon)
			*(int*)(0x8067ECA0) = 0x30810001; // ANDI $at $a0 1
			*(int*)(0x8067ECA4) = 0x18200002; // BLEZ $at 2
			// PTT
			*(int*)(0x806E20F0) = 0x31010002; // ANDI $at $t0 2
			*(int*)(0x806E20F4) = 0x5020000F; // BEQL $at $r0 0xF
			// PPUnch
			*(int*)(0x806E48F4) = 0x31810002; // ANDI $at $t4 2
			*(int*)(0x806E48F8) = 0x50200074; // BEQL $at $r0 0xF
			DamageMultiplier = Rando.damage_multiplier;
			WarpToIslesEnabled = Rando.warp_to_isles_enabled;
			permaLossMode = Rando.perma_lose_kongs;
			preventTagSpawn = Rando.prevent_tag_spawn;
			bonusAutocomplete = Rando.resolve_bonus;
			TextHoldOn = Rando.quality_of_life.textbox_hold;
			ToggleAmmoOn = Rando.quality_of_life.ammo_swap;
			LobbiesOpen = Rando.lobbies_open_bitfield;
			ShorterBosses = Rando.short_bosses;
			WinCondition = Rando.win_condition;
			if (Rando.krusha_slot == 4) {
				Rando.disco_chunky = 0;
			} else if (Rando.krusha_slot > 4) {
				Rando.krusha_slot = -1;
			}
			changeCharSpawnerFlag(0x14, 2, 93); // Tie llama spawn to lanky help me cutscene flag
			changeCharSpawnerFlag(0x7, 1, kong_flags[(int)Rando.free_target_japes]);
			changeCharSpawnerFlag(0x10, 0x13, kong_flags[(int)Rando.free_target_ttemple]);
			changeCharSpawnerFlag(0x14, 1, kong_flags[(int)Rando.free_target_llama]);
			changeCharSpawnerFlag(0x1A, 1, kong_flags[(int)Rando.free_target_factory]);
			alterGBKong(0x22, 0x4, Rando.starting_kong); // First GB
			alterGBKong(0x7, 0x69, Rando.free_source_japes); // Front of Diddy Cage GB
			alterGBKong(0x7, 0x48, Rando.free_source_japes); // In Diddy's Cage
			alterGBKong(0x10, 0x5B, Rando.free_source_ttemple); // In Tiny's Cage
			alterGBKong(0x14, 0x6C, Rando.free_source_llama); // Free Lanky GB
			alterGBKong(0x1A, 0x78, Rando.free_source_factory); // Free Chunky GB
			// Savefile Expansion		
			int balloon_patch_count = 300; // Normally 121
			expandSaveFile(0x100,balloon_patch_count);
			if (Rando.no_health_refill) {
				*(int*)(0x80683A34) = 0; // Cancel Tag Health Refill
				// *(int*)(0x8060DD10) = 0; // Load File
				// *(int*)(0x806C8010) = 0; // Load into map with < 1 health
				// *(int*)(0x806C94E4) = 0; // ?
				// *(int*)(0x806C9BC0) = 0; // Multiplayer
				*(int*)(0x806CB340) = 0; // Voiding
				*(int*)(0x806DEFE4) = 0; // Fairies
				// *(int*)(0x80708C9C) = 0; // Bonus Barrels (Taking Damge) & Watermelons
				// *(int*)(0x80708CA4) = 0; // Bonus Barrels (Full Health) & Watermelons
				*(int*)(0x806A6EA8) = 0; // Bonus Barrels
			} else {
				*(int*)(0x806A6EA8) = 0x0C1C2519; // Set Bonus Barrel to refill health

			}
			if (Rando.short_bosses) {
				*(short*)(0x8074D474) = 44; // Dogadon Health: 3 + (62 * (2 / 3))
				*(short*)(0x8074D3A8) = 3; // Dillo Health
			}
			if (Rando.resolve_bonus & 1) {
				*(short*)(0x806818DE) = 0x4248; // Make Aztec Lobby GB spawn above the trapdoor)
				*(int*)(0x80681690) = 0; // Make some barrels not play a cutscene
				*(int*)(0x8068188C) = 0; // Prevent disjoint mechanic for Caves/Fungi BBlast Bonus
				*(short*)(0x80681898) = 0x1000;
				*(int*)(0x8068191C) = 0; // Remove Oh Banana
			}
			replace_zones(1);
			randomize_bosses();
			loadExtraHooks();
			no_enemy_drops();
			// Moves & Prices
			fixTBarrelsAndBFI(1);
			replace_moves();
			price_rando();
			if (!Rando.move_rando_on) {
				moveTransplant();
				if (!Rando.price_rando_on) {
					priceTransplant();
				}
			}
			if (Rando.disable_boss_kong_check) {
				*(int*)(0x8064EC00) = 0x24020001;
			}
			*(int*)(0x8074C1B8) = (int)&newCounterCode;
			fixMusicRando();
			// Disable Sniper Scope Overlay
			int asm_code = 0x00801025; // OR $v0, $a0, $r0
			*(int*)(0x806FF80C) = asm_code;
			*(int*)(0x806FF85C) = asm_code;
			*(int*)(0x806FF8AC) = asm_code;
			*(int*)(0x806FF8FC) = asm_code;
			*(int*)(0x806FF940) = asm_code;
			*(int*)(0x806FF988) = asm_code;
			*(int*)(0x806FF9D0) = asm_code;
			*(int*)(0x806FFA18) = asm_code;
			// Change Sniper Crosshair color
			*(short*)(0x806FFA92) = 0xFFD7;
			*(short*)(0x806FFA96) = 0x00FF;
			// *(int*)(0x806FFA90) = 0x3C0D8080;
			// *(int*)(0x806FFA94) = 0x8DADFFFC;
			// Style 6 Mtx
			int base_mtx = 75;
			style6Mtx[0x0] = base_mtx;
			style6Mtx[0x5] = base_mtx;
			style6Mtx[0xF] = 100;
			style6Mtx[0x8] = 0xEA00;
			style6Mtx[0x9] = 0xFD00;
			base_mtx = 12;
			style2Mtx[0x0] = base_mtx;
			style2Mtx[0x5] = base_mtx;
			style2Mtx[0xF] = 10;
			base_mtx = 50;
			style128Mtx[0x0] = base_mtx;
			style128Mtx[0x5] = base_mtx;
			style128Mtx[0xF] = 100;
			writeCoinRequirements(0);
			writeEndSequence();
			*(int*)(0x806F6350) = 0x0C000000 | (((int)&getObjectCollectability & 0xFFFFFF) >> 2); // Modify Function Call
			if (Rando.warp_to_isles_enabled) {
				// Pause Menu Exit To Isles Slot
				*(short*)(0x806A85EE) = 4; // Yes/No Prompt
				*(short*)(0x806A8716) = 4; // Yes/No Prompt
				//*(short*)(0x806A87BE) = 3;
				*(short*)(0x806A880E) = 4; // Yes/No Prompt
				//*(short*)(0x806A8766) = 4;
				*(short*)(0x806A986A) = 4; // Yes/No Prompt
				*(int*)(0x806A9990) = 0x2A210270; // SLTI $at, $s1, 0x2A8
				PauseSlot3TextPointer = (char*)&exittoisles;
			}
			if (Rando.quality_of_life.reduce_lag) {
				*(int*)(0x80748010) = 0x8064F2F0; // Cancel Sandstorm
				// No Rain
				*(float*)(0x8075E3E0) = 0.0f; // Set Isles Rain Radius to 0
			}
			if (Rando.quality_of_life.remove_cutscenes) {
				// K. Lumsy
				*(short*)(0x80750680) = 0x22;
				*(short*)(0x80750682) = 0x1;
				*(int*)(0x806BDC24) = 0x0C17FCDE; // Change takeoff warp func
				*(short*)(0x806BDC8C) = 0x1000; // Apply no cutscene to all keys
				*(short*)(0x806BDC3C) = 0x1000; // Apply shorter timer to all keys
				// Fast Vulture
				*(int*)(0x806C50BC) = 0x0C000000 | (((int)&clearVultureCutscene & 0xFFFFFF) >> 2); // Modify Function Call
				// General
				// *(int*)(0x8061D920) = 0xA4205CEC; // Set cutscene state change to 0
				// *(int*)(0x8061D91C) = 0x0C000000 | (((int)&checkSkippableCutscene & 0xFFFFFF) >> 2); // Modify Function Call
			} else {
				for (int i = 0; i < 432; i++) {
					cs_skip_db[i] = 0;
				}
			}
			if (Rando.quality_of_life.fast_picture) {
				// Fast Camera Photo
				*(short*)(0x80699454) = 0x5000; // Fast tick/no mega-slowdown on Biz
				int picture_timer = 0x14;
				*(short*)(0x806992B6) = picture_timer; // No wait for camera film development
				*(short*)(0x8069932A) = picture_timer;
			}
			if (Rando.quality_of_life.aztec_lobby_bonus) {
				// Lower Aztec Lobby Bonus
				*(short*)(0x80680D56) = 0x7C; // 0x89 if this needs to be unreachable without PTT
			}
			if (Rando.quality_of_life.fast_boot) {
				// Remove DKTV - Game Over
				*(short*)(0x8071319E) = 0x50;
				*(short*)(0x807131AA) = 5;
				// Remove DKTV - End Seq
				*(short*)(0x8071401E) = 0x50;
				*(short*)(0x8071404E) = 5;
			}
			if (Rando.quality_of_life.fast_transform) {
				// Fast Barrel Animation
				*(short*)(0x8067EAB2) = 1; // OSprint
				*(short*)(0x8067EAC6) = 1; // HC Dogadon 2
				*(short*)(0x8067EACA) = 1; // Others
				*(short*)(0x8067EA92) = 1; // Others 2
			}
			if (Rando.quality_of_life.rambi_enguarde_pickup) {
				// Transformations can pick up other's collectables
				*(int*)(0x806F6330) = 0x96AC036E; // Collection
				// Collection
				*(int*)(0x806F68A0) = 0x95B8036E; // DK Collection
				*(int*)(0x806F68DC) = 0x952C036E; // Diddy Collection
				*(int*)(0x806F6914) = 0x95F9036E; // Tiny Collection
				*(int*)(0x806F694C) = 0x95AE036E; // Lanky Collection
				*(int*)(0x806F6984) = 0x952B036E; // Chunky Collection
				// Opacity
				*(int*)(0x80637998) = 0x95B9036E; // DK Opacity
				*(int*)(0x806379E8) = 0x95CF036E; // Diddy Opacity
				*(int*)(0x80637A28) = 0x9589036E; // Tiny Opacity
				*(int*)(0x80637A68) = 0x954B036E; // Chunky Opacity
				*(int*)(0x80637AA8) = 0x9708036E; // Lanky Opacity
				// CB/Coin rendering
				*(int*)(0x806394FC) = 0x958B036E; // Rendering
				*(int*)(0x80639540) = 0x9728036E; // Rendering
				*(int*)(0x80639584) = 0x95AE036E; // Rendering
				*(int*)(0x80639430) = 0x95CD036E; // Rendering
				*(int*)(0x806393EC) = 0x9519036E; // Rendering
				*(int*)(0x806395C8) = 0x952A036E; // Rendering
				*(int*)(0x8063960C) = 0x95F8036E; // Rendering
				*(int*)(0x80639474) = 0x9549036E; // Rendering
				*(int*)(0x806393A8) = 0x956C036E; // Rendering
				*(int*)(0x806394B8) = 0x970F036E; // Rendering
				*(int*)(0x80639650) = 0x956C036E; // Rendering
				*(int*)(0x80639710) = 0x9549036E; // Rendering
				*(int*)(0x80639750) = 0x970F036E; // Rendering
				*(int*)(0x806396D0) = 0x95CD036E; // Rendering
				*(int*)(0x80639690) = 0x9519036E; // Rendering
			}
			*(int*)(0x805FEBC0) = 0x0C000000 | (((int)&parseCutsceneData & 0xFFFFFF) >> 2); // modifyCutsceneHook
			*(int*)(0x807313A4) = 0x0C000000 | (((int)&checkVictory_flaghook & 0xFFFFFF) >> 2); // perm flag set hook
			if (Rando.helm_hurry_mode) {
				*(int*)(0x806F56F8) = 0x0C000000 | (((int)&blueprintCollect & 0xFFFFFF) >> 2); // Blueprint collection hook
				*(int*)(0x80713CCC) = 0; // Prevent Helm Timer Disable
				*(int*)(0x80713CD8) = 0; // Prevent Shutdown Song Playing
				*(short*)(0x8071256A) = 15; // Init Helm Timer = 15 minutes
			}
			if (Rando.always_show_coin_cbs) {
				*(int*)(0x806324D4) = 0x24020001; // ADDIU $v0, $r0, 1 // Disable kong flag check
			}
			if (Rando.fast_warp) {
				// Replace vanilla warp animation (0x52) with monkeyport animation (0x53)
				*(short*)(0x806EE692) = 0x54;
				*(int*)(0x806DC2AC) = 0x0C000000 | (((int)&fastWarp & 0xFFFFFF) >> 2); // Modify Function Call
			}
			if (Rando.version == 0) {
				// Disable Graphical Debugger
				*(int*)(0x8060EEE0) = 0x240E0000; // ADDIU $t6, $r0, 0
			}
			if (Rando.disco_chunky) {
				// Disco
				*(char*)(0x8075C45B) = 0xE; // General Model
				*(short*)(0x806F123A) = 0xED; // Instrument
				*(int*)(0x806CF37C) = 0; // Fix object holding
				*(short*)(0x8074E82C) = 0xE; // Tag Barrel Model
				*(short*)(0x8075EDAA) = 0xE; // Cutscene Chunky Model
				*(short*)(0x8075571E) = 0xE; // Generic Cutscene Model
				*(short*)(0x80755738) = 0xE; // Generic Cutscene Model
				*(int*)(0x806F1274) = 0; // Prevent model change for GGone
				*(int*)(0x806CBB84) = 0; // Enable opacity filter GGone
				*(short*)(0x8075BF3E) = 0x2F5C; // Make CS Model Behave normally
				*(short*)(0x8075013E) = 0xE; // Low Poly Model
			}
			if (Rando.krusha_slot != -1) {
				// Krusha
				int slot = Rando.krusha_slot;
				KongModelData[slot].model = 0xDB; // General Model
				TagModelData[slot].model = 0xDB; // Tag Barrel Model
				*(int*)(0x80677E94) = 0x0C000000 | (((int)&adjustAnimationTables & 0xFFFFFF) >> 2); // Give Krusha animations to slot
				*(int*)(0x806C32B8) = 0x0C000000 | (((int)&updateCutsceneModels & 0xFFFFFF) >> 2); // Fix cutscene models
				RollingSpeeds[slot] = 175; // Increase Krusha slide speed to 175
				KongTagNames[slot] = 6; // Change kong name in Tag Barrel
				KongTextNames[slot] = KongTextNames[5];
				switch (slot) {
					case 0:
						// DK
						// *(int*)(0x806F1154) = 0x02002025; // Instrument - Param1
						// *(int*)(0x806F1158) = 0x0C184C65; // Instrument - Func Call
						// *(short*)(0x806F115E) = 0xDB; // Instrument - Param2
						// *(int*)(0x806F1194) = 0; // Instrument - NOP Other stuff
						// *(int*)(0x806F11B0) = 0; // Instrument - NOP Other stuff
						// *(int*)(0x806F11BC) = 0; // Instrument - NOP Other stuff
						// *(int*)(0x806F11D0) = 0; // Instrument - NOP Other stuff
						*(short*)(0x8075ED4A) = 0xDB; // Cutscene DK Model
						*(short*)(0x8075573E) = 0xDB; // Generic Cutscene Model
						*(int*)(0x8074C0A8) = 0x806C9F44; // Replace DK Code w/ Krusha Code
						*(short*)(0x806F0AFE) = 0; // Remove gun from hands in Tag Barrel
						*(int*)(0x806F0AF0) = 0x24050001; // Fix Hand State
						break;
					case 1:
						// Diddy
						*(short*)(0x806F11E6) = 0xDB; // Instrument
						*(short*)(0x8075ED62) = 0xDB; // Cutscene Diddy Model
						*(short*)(0x80755736) = 0xDB; // Generic Cutscene Model
						*(int*)(0x8074C0AC) = 0x806C9F44; // Replace Diddy Code w/ Krusha Code
						*(int*)(0x806F0A6C) = 0x0C1A29D9; // Replace hand state call
						*(int*)(0x806F0A78) = 0; // Replace hand state call
						*(int*)(0x806E4938) = 0; // Always run adapt code
						*(int*)(0x806E4940) = 0; // NOP Animation calls
						*(int*)(0x806E4950) = 0; // NOP Animation calls
						*(int*)(0x806E4958) = 0; // NOP Animation calls
						*(int*)(0x806E495C) = 0x0C000000 | (((int)&adaptKrushaZBAnimation_Charge & 0xFFFFFF) >> 2); // Allow Krusha to use slide move if fast enough (Charge)
						*(int*)(0x806E499C) = 0; // NOP Animation calls
						*(int*)(0x806E49C8) = 0; // NOP Animation calls
						*(int*)(0x806E49F0) = 0; // NOP Animation calls
						*(short*)(0x806CF5F0) = 0x5000; // Prevent blink special cases
						*(int*)(0x806CF76C) = 0; // Prevent blink special cases
						*(unsigned char*)(0x8075D19F) = 0xA0; // Fix Gun Firing
						break;
					case 2:
						// Lanky
						/*
							Issues:
								Lanky Phase arm extension has a poly tri not correctly aligned
						*/
						*(short*)(0x806F1202) = 0xDB; // Instrument
						*(short*)(0x8075ED7A) = 0xDB; // Cutscene Lanky Model
						*(short*)(0x8075573A) = 0xDB; // Generic Cutscene Model
						*(int*)(0x8074C0B0) = 0x806C9F44; // Replace Lanky Code w/ Krusha Code
						*(short*)(0x806F0ABE) = 0; // Remove gun from hands in Tag Barrel
						*(int*)(0x806E48BC) = 0x0C000000 | (((int)&adaptKrushaZBAnimation_PunchOStand & 0xFFFFFF) >> 2); // Allow Krusha to use slide move if fast enough (OStand)
						*(int*)(0x806E48B4) = 0; // Always run `adaptKrushaZBAnimation`
						*(int*)(0x806F0AB0) = 0x24050001; // Fix Hand State
						break;
					case 3:
						// Tiny
						*(short*)(0x806F121E) = 0xDB; // Instrument
						*(short*)(0x8075ED92) = 0xDB; // Cutscene Tiny Model
						*(short*)(0x8075573C) = 0xDB; // Generic Cutscene Model
						*(int*)(0x8074C0B4) = 0x806C9F44; // Replace Tiny Code w/ Krusha Code
						*(short*)(0x806F0ADE) = 0; // Remove gun from hands in Tag Barrel
						*(int*)(0x806E47F8) = 0; // Prevent slide bounce
						*(short*)(0x806CF784) = 0x5000; // Prevent blink special cases
						*(int*)(0x806F0AD0) = 0x24050001; // Fix Hand State
						break;
					case 4:
						// Chunky
						*(short*)(0x806F123A) = 0xDB; // Instrument
						*(int*)(0x806CF37C) = 0; // Fix object holding
						*(short*)(0x8075EDAA) = 0xDB; // Cutscene Chunky Model
						*(short*)(0x8075571E) = 0xDB; // Generic Cutscene Model
						*(short*)(0x80755738) = 0xDB; // Generic Cutscene Model
						*(int*)(0x806F1274) = 0; // Prevent model change for GGone
						*(int*)(0x806CBB84) = 0; // Enable opacity filter GGone
						*(int*)(0x8074C0B8) = 0x806C9F44; // Replace Chunky Code w/ Krusha Code
						*(int*)(0x806E4900) = 0x0C000000 | (((int)&adaptKrushaZBAnimation_PunchOStand & 0xFFFFFF) >> 2); // Allow Krusha to use slide move if fast enough (PPunch)
						*(int*)(0x806E48F8) = 0; // Always run `adaptKrushaZBAnimation`
						*(short*)(0x806F0A9E) = 0; // Remove gun from hands in Tag Barrel
						*(int*)(0x806F0A90) = 0x24050001; // Fix Hand State
					break;
				}
			}
			if (Rando.fast_gbs) {
				*(short*)(0x806BBB22) = 0x0005; // Chunky toy box speedup

				*(short*)(0x806C58D6) = 0x0008; //Owl ring amount
				*(short*)(0x806C5B16) = 0x0008;

				*(int*)(0x806BEDFC) = 0; //Spawn banana coins on beating rabbit 2 (Beating round 2 branches to banana coin spawning label before continuing)
				
				// Arcade R1
				*(unsigned char*)(0x80755B68) = 0x6E; // Modify GB Map
				*(short*)(0x80755B6A) = 0; // Modify GB ID
			}
			// Change Beaver Bother Klaptrap Model
			if (Rando.klaptrap_color_bbother == 0) {
				Rando.klaptrap_color_bbother = 0x21; // Set to default model if no model assigned
			}
			int kko_phase_rando = 0;
			for (int i = 0; i < 3; i++) {
				KKOPhaseOrder[i] = Rando.kut_out_phases[i];
				if (Rando.kut_out_phases[i]) {
					kko_phase_rando = 1;
				}
			}
			KKOPhaseRandoOn = kko_phase_rando;
			*(short*)(0x806F0376) = Rando.klaptrap_color_bbother;
			*(short*)(0x806C8B42) = Rando.klaptrap_color_bbother;
			if (Rando.wrinkly_rando_on) {
				*(int*)(0x8064F170) = 0; // Prevent edge cases for Aztec Chunky/Fungi Wheel
				*(int*)(0x8069E154) = 0x0C000000 | (((int)&getWrinklyLevelIndex & 0xFFFFFF) >> 2); // Modify Function Call
			}
			*(short*)(0x8060D01A) = getHi(&InvertedControls); // Change language store to inverted controls store
			*(short*)(0x8060D01E) = getLo(&InvertedControls); // Change language store to inverted controls store
			*(short*)(0x8060D04C) = 0x1000; // Prevent inverted controls overwrite
			// Expand Display List
			*(short*)(0x805FE56A) = 8000;
			*(short*)(0x805FE592) = 0x4100; // SLL 4 (Doubles display list size)
			// Object Instance Scripts
			*(int*)(0x80748064) = (int)&change_object_scripts;
			*(int*)(0x806416BC) = 0; // Prevent parent map check in cross-map object change communications
			// Sniper Scope Check
			*(int*)(0x806D2988) = 0x93190002; // LBU $t9, 0x2 ($t8)
			*(int*)(0x806D2990) = 0x33210004; // ANDI $at, $t9, 0x4
			*(short*)(0x806D299C) = 0x1020; // BEQ $at, $r0
			// Speedy T&S Turn-Ins
			*(int*)(0x806BE3E0) = 0; // NOP
			// EEPROM Patch
			*(int*)(0x8060D588) = 0; // NOP
			// Cancel Tamper
			*(int*)(0x8060AEFC) = 0; // NOP
			*(int*)(0x80611788) = 0; // NOP
			// Fix HUD if DK not free
			*(int*)(0x806FA324) = 0; // NOP
			*(short*)(0x807505AE) = 385; // Set Flag to DK Flag
			// Fix CB Spawning
			*(short*)(0x806A7882) = 385; // DK Balloon
			// Fix Boss Doors if DK not free
			*(int*)(0x80649358) = 0; // NOP
			// Fix Pause Menu
			*(int*)(0x806ABFF8) = 0; // NOP (Write of first slot to 1)
			*(short*)(0x806AC002) = 0x530;
			*(short*)(0x806AC006) = 0x5B0;
			*(unsigned char*)(0x8075054D) = 0xD7; // Change DK Q Mark to #FFD700
			// Guard Animation Fix
			*(short*)(0x806AF8C6) = 0x2C1;
			// Fix Diddy/Chunky Helm Medal Flag Mapping
			*(short*)(0x80755D8C) = 0x024C;
			*(short*)(0x80755DA4) = 0x0249;
			// Remove flare effect from guards
			*(int*)(0x806AE440) = 0;
			// Boost Diddy/Tiny's Barrel Speed
			*(float*)(0x807533A0) = 240.0f; // Diddy Ground
			*(float*)(0x807533A8) = 240.0f; // Tiny Ground
			*(float*)(0x807533DC) = 260.0f; // Lanky Air
			*(float*)(0x807533E0) = 260.0f; // Tiny Air
			// Bump Model Two Allowance
			int allowance = 550;
			*(short*)(0x80632026) = allowance; // Japes
			*(short*)(0x80632006) = allowance; // Aztec
			*(short*)(0x80631FF6) = allowance; // Factory
			*(short*)(0x80632016) = allowance; // Galleon
			*(short*)(0x80631FE6) = allowance; // Fungi
			*(short*)(0x80632036) = allowance; // Others
			// New Helm Barrel Code
			*(int*)(0x8074C24C) = (int)&HelmBarrelCode;
			// Deathwarp Handle
			*(int*)(0x8071292C) = 0x0C000000 | (((int)&WarpHandle & 0xFFFFFF) >> 2); // Check if in Helm, in which case, apply transition
			// New Guard Code
			*(short*)(0x806AF75C) = 0x1000;
			// Gold Beaver Code
      		*(int*)(0x8074C3F0) = 0x806AD54C; // Set as Blue Beaver Code
			*(int*)(0x806AD750) = 0x0C000000 | (((int)&beaverExtraHitHandle & 0xFFFFFF) >> 2); // Remove buff until we think of something better
			// Move Text Code
			*(int*)(0x8074C5B0) = (int)&getNextMoveText;
			*(int*)(0x8074C5A0) = (int)&getNextMoveText;

			if (Rando.item_rando) {

			} else {
				for (int i = 0; i < 54; i++) {
					BonusBarrelData[i].spawn_actor = 45; // Spawn GB
				}
			}
			
			// Spider Projectile
			//*(int*)(0x806ADDC0) = 0x0C000000 | (((int)&handleSpiderTrapCode & 0xFFFFFF) >> 2); // Remove buff until we think of something better
			// Slow Turn Fix
			*(int*)(0x806D2FC0) = 0x0C000000 | (((int)&fixRBSlowTurn & 0xFFFFFF) >> 2);
			// Tag Anywhere collectable Fixes
			// CB Bunch
			int non_chunky_bunch_indexes[] = {10,11,13,14};
			for (int i = 0; i < sizeof(non_chunky_bunch_indexes) / 4; i++) {
				int index = non_chunky_bunch_indexes[i];
				ModelTwoCollisionArray[index].actor_equivalent = 0;
			}
			*(int*)(0x806A65B8) = 0x240A0006; // Always ensure chunky bunch sprite
			// Coins
			int non_lanky_coin_indexes[] = {5,7,8,9};
			for (int i = 0; i < sizeof(non_lanky_coin_indexes) / 4; i++) {
				int index = non_lanky_coin_indexes[i];
				ModelTwoCollisionArray[index].actor_equivalent = 0;
			}
			*(int*)(0x806A64B0) = 0x240A0004; // Always ensure lanky coin sprite
			// 1-File Fixes
			*(int*)(0x8060CF34) = 0x240E0001; // Slot 1
			*(int*)(0x8060CF38) = 0x240F0002; // Slot 2
			*(int*)(0x8060CF3C) = 0x24180003; // Slot 3
			*(int*)(0x8060CF40) = 0x240D0000; // Slot 0
			*(int*)(0x8060D3AC) = 0; // Prevent EEPROM Shuffle
			*(int*)(0x8060DCE8) = 0; // Prevent EEPROM Shuffle
			*(int*)(0x8060C760) = 0x24900000; // Always load file 0
			// s*(short*)(0x8060CC22) = 1; // File Loop Cancel 1
			*(short*)(0x8060CD1A) = 1; // File Loop Cancel 2
			*(short*)(0x8060CE7E) = 1; // File Loop Cancel 3
			*(short*)(0x8060CE5A) = 1; // File Loop Cancel 4
			*(short*)(0x8060CF0E) = 1; // File Loop Cancel 5
			*(short*)(0x8060CF26) = 1; // File Loop Cancel 6
			//*(short*)(0x8060D0DE) = 1; // File Loop Cancel 7
			*(short*)(0x8060D106) = 1; // File Loop Cancel 8
			*(short*)(0x8060D43E) = 1; // File Loop Cancel 8
			*(int*)(0x8060CD08) = 0x26670000; // Save to File - File Index
			*(int*)(0x8060CE48) = 0x26670000; // Save to File - File Index
			*(int*)(0x8060CF04) = 0x26270000; // Save to File - File Index
			*(int*)(0x8060BFA4) = 0x252A0000; // Global Block after 1 file entry
			*(int*)(0x8060E378) = 0x258D0000; // Global Block after 1 file entry
			*(int*)(0x8060D33C) = 0x254B0000; // Global Block after 1 file entry
			*(int*)(0x8060D470) = 0x256C0000; // Global Block after 1 file entry
			*(int*)(0x8060D4B0) = 0x252A0000; // Global Block after 1 file entry
			*(int*)(0x8060D558) = 0x258D0000; // Global Block after 1 file entry
			*(int*)(0x8060CF74) = 0x25090000; // Global Block after 1 file entry
			// *(int*)(0x8060CFCC) = 0x25AE0000; // Global Block after 1 file entry
			*(int*)(0x8060D24C) = 0x25AE0000; // Global Block after 1 file entry
			*(int*)(0x8060C84C) = 0xA02067C8; // Force file 0
			*(int*)(0x8060C654) = 0x24040000; // Force file 0 - Save
			*(int*)(0x8060C664) = 0xAFA00034; // Force file 0 - Save
			*(int*)(0x8060C6C4) = 0x24040000; // Force file 0 - Read
			*(int*)(0x8060C6D4) = 0xAFA00034; // Force file 0 - Read

			// for (int i = 0; i < 10; i++) {
			// 	*(int*)(0x8060D6A0 + (4 * i)) = 0;
			// }
			// *(short*)(0x8060D6C8) = 0x5000;
			// Decouple Camera from Shockwave
			*(short*)(0x806E9812) = FLAG_ABILITY_CAMERA; // Usage
			*(short*)(0x806AB0F6) = FLAG_ABILITY_CAMERA; // Isles Fairies Display
			*(short*)(0x806AAFB6) = FLAG_ABILITY_CAMERA; // Other Fairies Display
			*(short*)(0x806AA762) = FLAG_ABILITY_CAMERA; // Film Display
			*(short*)(0x8060D986) = FLAG_ABILITY_CAMERA; // Film Refill
			*(short*)(0x806F6F76) = FLAG_ABILITY_CAMERA; // Film Refill
			initItemDropTable();
			initCollectableCollision();
			// LZ Save
			*(int*)(0x80712EC4) = 0x0C000000 | (((int)&postKRoolSaveCheck & 0xFFFFFF) >> 2);
			// Reduce TA Cooldown
			if (Rando.tag_anywhere) {
				// *(int*)(0x806F6D88) = 0; // Makes collectables not produce a flying model which delays collection. Instant change
				*(int*)(0x806F6D94) = 0; // Prevent delayed collection
				// Standard Ammo
				*(short*)(0x806F5B68) = 0x1000;
				*(int*)(0x806F5BE8) = 0x0C000000 | (((int)&tagAnywhereAmmo & 0xFFFFFF) >> 2);
				// Bunch
				*(short*)(0x806F59A8) = 0x1000;
				*(int*)(0x806F5A08) = 0x0C000000 | (((int)&tagAnywhereBunch & 0xFFFFFF) >> 2);

				*(int*)(0x806F6CAC) = 0x9204001A; // LBU $a0, 0x1A ($s0)
				*(int*)(0x806F6CB0) = 0x86060002; // LH $a2, 0x2 ($s0)
				*(int*)(0x806F6CB4) = 0x0C000000 | (((int)&tagAnywhereInit & 0xFFFFFF) >> 2);
				*(int*)(0x806F53AC) = 0; // Prevent LZ case
			}
			// Fix Tag Barrel Background Kong memes
			*(int*)(0x806839F0) = 0x0C000000 | (((int)&tagBarrelBackgroundKong & 0xFFFFFF) >> 2);
			// DK Face Puzzle
			int dk_reg_vals[] = {0x80,0x95,0x83,0x82}; // 0 = r0, 1 = s5, 2 = v1, 3 = v0
			*(unsigned char*)(0x8064AD01) = dk_reg_vals[(int)Rando.dk_face_puzzle_init[2]];
			*(unsigned char*)(0x8064AD05) = dk_reg_vals[(int)Rando.dk_face_puzzle_init[5]];
			*(unsigned char*)(0x8064AD09) = dk_reg_vals[(int)Rando.dk_face_puzzle_init[7]];
			*(unsigned char*)(0x8064AD11) = dk_reg_vals[(int)Rando.dk_face_puzzle_init[0]];
			*(unsigned char*)(0x8064AD15) = dk_reg_vals[(int)Rando.dk_face_puzzle_init[1]];
			*(unsigned char*)(0x8064AD19) = dk_reg_vals[(int)Rando.dk_face_puzzle_init[3]];
			*(unsigned char*)(0x8064AD1D) = dk_reg_vals[(int)Rando.dk_face_puzzle_init[4]];
			*(unsigned char*)(0x8064AD21) = dk_reg_vals[(int)Rando.dk_face_puzzle_init[6]];
			*(unsigned char*)(0x8064AD29) = dk_reg_vals[(int)Rando.dk_face_puzzle_init[8]];
			// Chunky Face Puzzle
			int chunky_reg_vals[] = {0x40,0x54,0x48,0x44}; // 0 = r0, 1 = s4, 2 = t0, 3 = a0
			*(unsigned char*)(0x8064A2D5) = chunky_reg_vals[(int)Rando.chunky_face_puzzle_init[2]];
			*(unsigned char*)(0x8064A2DD) = chunky_reg_vals[(int)Rando.chunky_face_puzzle_init[6]];
			*(unsigned char*)(0x8064A2ED) = chunky_reg_vals[(int)Rando.chunky_face_puzzle_init[0]];
			*(unsigned char*)(0x8064A2F1) = chunky_reg_vals[(int)Rando.chunky_face_puzzle_init[1]];
			*(unsigned char*)(0x8064A2F5) = chunky_reg_vals[(int)Rando.chunky_face_puzzle_init[3]];
			*(unsigned char*)(0x8064A2F9) = chunky_reg_vals[(int)Rando.chunky_face_puzzle_init[4]];
			*(unsigned char*)(0x8064A2FD) = chunky_reg_vals[(int)Rando.chunky_face_puzzle_init[5]];
			*(unsigned char*)(0x8064A301) = chunky_reg_vals[(int)Rando.chunky_face_puzzle_init[7]];
			*(unsigned char*)(0x8064A305) = chunky_reg_vals[(int)Rando.chunky_face_puzzle_init[8]];
			// Realign HUD
			/*
				Item: CB | Coords: 0x1E, 0x26 | X: 0x806F84EE | Y: 0x806F84FE
				Item: Coins | Coords: 0x122, 0x26 | X: 0x806F88CA | Y: 0x806F88CE
				Item: Ammo | Coords: 0x122, 0x48 | X: 0x806F86C6 | Y: 0x806F86CA
				Item: Homing Ammo | Coords: 0x122, 0x48 | X: 0x806F873A | Y: 0x806F873E
				Item: Oranges | Coords: 0x122, 0x6A | X: 0x806F87A6 | Y: 0x806F87AA
				Item: Crystals | Coords: 0x122, 0x8C | X: 0x806F868E | Y: 0x806F8692
				Item: Film | Coords: 0x122, 0xD0 | X: 0x806F8812 | Y: 0x806F8816
				Item: Instrument | Coords: 0x122, 0xAE | X: 0x806F893A | Y: 0x806F893E
				Item: GB Character | Coords: 0x1E, 0x48 | X: 0x806F857E | Y: 0x806F858E
				Item: GB | Coords: 0x7A, 0xD0 | X: 0x806F8642 | Y: 0x806F8646
				Item: Medal (Multi CB) | Coords: 0x52, 0xD0 | X: 0x806F8606 | Y: 0x806F860A
				Item: Race Coin | Coords: 0x122, 0x26 | X: 0x806F8852 | Y: 0x806F8856
				Item: Blueprint | Coords: 0xC2, 0xD0 | X: 0x806F85CA | Y: 0x806F85CE
				Item: CB T&S | Coords: 0x122, 0x26 | X: 0x806F8536 | Y: 0x806F853A
				Item: Unk | Coords: 0x1E, 0x26 | X: 0x806F897A | Y: 0x806F897E
			*/
			int y_spacing = 22;
			int y_bottom = 0xD0;
			*(short*)(0x806F893E) = y_bottom - (1 * y_spacing); // Instrument
			*(short*)(0x806F8692) = y_bottom - (2 * y_spacing); // Crystals
			*(short*)(0x806F87AA) = y_bottom - (3 * y_spacing); // Oranges
			*(short*)(0x806F86CA) = y_bottom - (4 * y_spacing); // Ammo
			*(short*)(0x806F873E) = y_bottom - (4 * y_spacing); // Homing Ammo
			// Multibunch HUD
			if (Rando.quality_of_life.hud_bp_multibunch) {
				*(short*)(0x806F860A) = y_bottom - (5 * y_spacing); // Multi CB
				*(int*)(0x806F97D8) = 0x0C000000 | (((int)&getHUDSprite_HUD & 0xFFFFFF) >> 2); // Change Sprite
				*(int*)(0x806F6BF0) = 0x0C000000 | (((int)&preventMedalHUD & 0xFFFFFF) >> 2); // Prevent Model Two Medals showing HUD
				*(short*)(0x806F8606) = 0x122; // Position X
				*(int*)(0x806F862C) = 0x4600F306; // MOV.S $f12, $f30
				*(int*)(0x806F8634) = 0x4600A386; // MOV.S $f14, $f20
				*(int*)(0x806F98E4) = 0x0C000000 | (((int)&initHUDDirection & 0xFFFFFF) >> 2); // HUD Direction
				*(int*)(0x806F9A00) = 0x0C000000 | (((int)&initHUDDirection & 0xFFFFFF) >> 2); // HUD Direction
				*(int*)(0x806F9A78) = 0x0C000000 | (((int)&initHUDDirection & 0xFFFFFF) >> 2); // HUD Direction
				*(int*)(0x806F9BC0) = 0x0C000000 | (((int)&initHUDDirection & 0xFFFFFF) >> 2); // HUD Direction
				*(int*)(0x806F9D14) = 0x0C000000 | (((int)&initHUDDirection & 0xFFFFFF) >> 2); // HUD Direction
				*(int*)(0x806FA62C) = 0; // NOP: Enable Number Rendering
				*(int*)(0x806FA56C) = 0; // NOP: Prevent opacity check
			}
			// GetOut Timer
			*(unsigned short*)(0x806B7ECA) = 125; // 0x8078 for center-bottom ms timer
			LoadedHooks = 1;
		}
	}
}

void quickInit(void) {
	if (Rando.quality_of_life.fast_boot) {
		initHack(1);
		initiateTransitionFade(0x51, 0, 5);
		CutsceneWillPlay = 0;
		Gamemode = 5;
		Mode = 5;
		StorySkip = 1;
		*(char*)(0x80745D20) = 7;
	}
}