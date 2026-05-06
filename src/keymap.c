#include "keymap.h"
#include <string.h>

// uhhh, nasty looking if statements
KeyGroup get_group(int key) {
  // spacebar
  if (key == 57) {
    return GROUP_SPACE;
  }
  // enter
  if (key == 28 || key == 96) {
    return GROUP_ENTER;
  }
  // abcd's and 123's
  if ((key >= 16 && key <= 25) || (key >= 30 && key <= 38) ||
      (key >= 44 && key <= 50) || (key >= 2 && key <= 13)) {
    return GROUP_ALPHANUMERIC;
  }
  // shift(L+R) ctrl(L+R) alt(L+R)
  if (key == 42 || key == 54 || key == 29 || key == 97 || key == 56 ||
      key == 100) {
    return GROUP_MODIFIERS;
  }
  // tab and backspace
  if (key == 15 || key == 14) {
    return GROUP_BACKSPACE_TAB;
  }
  // arrow up down left right now fall through to default (ALPHANUMERIC)
  // caps,num,scroll lock
  if (key == 58 || key == 69 /* :) */ || key == 70) {
    return GROUP_LOCK;
  }

  // lazy to write for extra keys so, default is abcd's
  return GROUP_ALPHANUMERIC;
}

const char *group_to_string(KeyGroup g) {
  switch (g) {
  case GROUP_ALPHANUMERIC:
    return "ALPHANUMERIC";
  case GROUP_SPACE:
    return "SPACE";
  case GROUP_ENTER:
    return "ENTER";
  case GROUP_MODIFIERS:
    return "MODIFIERS";
  case GROUP_BACKSPACE_TAB:
    return "BACKSPACE_TAB";
  case GROUP_LOCK:
    return "LOCK";
  default:
    return "UNKNOWN";
  }
}

KeyGroup group_from_string(const char *name) {
  if (strcmp(name, "ALPHANUMERIC") == 0)
    return GROUP_ALPHANUMERIC;
  if (strcmp(name, "SPACE") == 0)
    return GROUP_SPACE;
  if (strcmp(name, "ENTER") == 0)
    return GROUP_ENTER;
  if (strcmp(name, "MODIFIERS") == 0)
    return GROUP_MODIFIERS;
  if (strcmp(name, "BACKSPACE_TAB") == 0)
    return GROUP_BACKSPACE_TAB;
  if (strcmp(name, "LOCK") == 0)
    return GROUP_LOCK;

  return GROUP_ALPHANUMERIC;
}