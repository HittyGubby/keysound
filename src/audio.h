#pragma once
#include "keymap.h"

void audio_init();
void audio_load();
void audio_play_group(KeyGroup group);
void audio_cleanup();
void audio_load_pack(const char *pack);