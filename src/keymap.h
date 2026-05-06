#pragma once

typedef enum {
	GROUP_ALPHANUMERIC,
	GROUP_SPACE,
	GROUP_ENTER,
	GROUP_MODIFIERS,
	GROUP_BACKSPACE_TAB,
	GROUP_LOCK,
	GROUP_COUNT
} KeyGroup;

KeyGroup get_group(int key);
const char *group_to_string(KeyGroup g);
KeyGroup group_from_string(const char *name);
