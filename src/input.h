#pragma once
#include <signal.h>

extern volatile sig_atomic_t keep_running;

void input_start(void (*callback)(int));