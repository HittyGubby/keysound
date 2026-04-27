#pragma once

typedef enum {
    GROUP_LETTER,
    GROUP_NUMBER,
    GROUP_SPACE,
    GROUP_ENTER,
    GROUP_MODIFIER,
    GROUP_CONTROL,
    GROUP_NAV,
    GROUP_FUNCTION,
    GROUP_LOCK,
    GROUP_COUNT
}KeyGroup;

KeyGroup get_group(int key);
const char* group_to_string(KeyGroup g);
KeyGroup group_from_string(const char *name);
 