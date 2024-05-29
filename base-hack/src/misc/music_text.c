/**
 * @file music_text.c
 * @author Ballaam
 * @brief Display the name of a song on the bottom of the screen when played
 * @version 0.1
 * @date 2024-03-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../../include/common.h"

static char* displayed_text_music = (char*)0;
static unsigned char display_timer = 0;
static short displayed_text_offset = -1;

void resetDisplayedMusic(void) {
    displayed_text_music = 0;
}

void initSongDisplay(int song) {
    if (song == 0) {
        return;
    }
    if (song == 34) {
        // Block it from occurring in the pause menu, cause text overload
        return;
    }
    if (music_types[song] != SONGTYPE_BGM) {
        return;
    }
    int channel = getTrackChannel(song);
    if ((MusicTrackChannels[channel] == song) && ((songData[song] & 0x200) == 0)) {
        return;
    }
    if (displayed_text_music) {
        complex_free(displayed_text_music);
    }
    displayed_text_music = getTextPointer(46, song, 0);
    displayed_text_offset = -1;
    int text_length = cstring_strlen(displayed_text_music);
    display_timer = 60;
    if (ObjectModel2Timer < 31) {
        display_timer = 91;
    }
    for (int i = 0; i < text_length; i++) {
        if (displayed_text_music[i] == 0xA) {
            displayed_text_music[i] = 0;
            displayed_text_offset = i + 1;
        }
    }
}

Gfx* displaySongNameHandler(Gfx* dl) {
    if ((!Rando.show_music_name) || (display_timer == 0)) {
        return dl;
    }
    if (display_timer > 0) {
        display_timer -= 1;
    }
    if (!displayed_text_music) {
        return dl;
    }
    if (displayed_text_offset == -1) {
        return dl;
    }
    for (int i = 0; i < 2; i++) {
        mtx_item mtx0;
        mtx_item mtx1;
        _guScaleF(&mtx0, 0x3F19999A, 0x3F19999A, 0x3F800000);
        _guTranslateF(&mtx1, 50.0f, 800.0f + (i * 30.0f), 0.0f);
        _guMtxCatF(&mtx0, &mtx1, &mtx0);
        _guTranslateF(&mtx1, 0.0f, 48.0f, 0.0f);
        _guMtxCatF(&mtx0, &mtx1, &mtx0);
        _guMtxF2L(&mtx0, &static_mtx[20 + i]);

        gSPDisplayList(dl++, 0x01000118);
        gSPMatrix(dl++, 0x02000180, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPPipeSync(dl++);
        gDPSetCombineLERP(dl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        gSPMatrix(dl++, (int)&static_mtx[20 + i], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        dl = displayText(dl,6,0,0,displayed_text_music + (displayed_text_offset * i),0);
        gSPPopMatrix(dl++, G_MTX_MODELVIEW);
    }
    return dl;
}