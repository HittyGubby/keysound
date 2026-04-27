#include "keymap.h"
#include <string.h>


//uhhh, nasty looking if statements
KeyGroup get_group(int key){
    //spacebar
    if(key == 57){
        return GROUP_SPACE;
    }
    //enter
    if(key == 28 || key == 96){
        return GROUP_ENTER;
    }
    //abcd's
    if((key >= 16 && key <= 25) || (key >= 30 && key <= 38) || (key >= 44 && key<= 50)){
        return GROUP_LETTER;
    }
    //123's
    if(key >= 2 && key <= 13){
        return GROUP_NUMBER;
    }
    //shift(L+R) ctrl(L+R) alt(L+R)
    if(key == 42 || key == 54 || key == 29 || key == 97 || key == 56 || key == 100){
        return GROUP_MODIFIER;
    }
    // tab and backspace
    if(key == 15 || key == 14){
        return GROUP_CONTROL;
    }
    //f1 f2 f3's
    if((key >= 59 && key <= 68) || key == 87 || key == 88){
        return GROUP_FUNCTION;
    }
    //arrow up down left right
    if(key >= 102 && key <= 111){
        return GROUP_NAV;
    }
    //caps,num,scroll lock
    if(key == 58 || key == 69 /* :) */ || key == 70){
        return GROUP_LOCK;
    }

    //lazy to write for extra keys so, default is abcd's
    return GROUP_LETTER;
}

const char* group_to_string(KeyGroup g){
    switch(g){
        case GROUP_LETTER: return "LETTER";
        case GROUP_NUMBER: return "NUMBER";
        case GROUP_SPACE: return "SPACE";
        case GROUP_ENTER: return "ENTER";
        case GROUP_MODIFIER: return "MODIFIER";
        case GROUP_CONTROL: return "CONTROL";
        case GROUP_FUNCTION: return "FUNCTION";
        case GROUP_NAV: return "NAV";
        case GROUP_LOCK: return "LOCK";
        default: return "UNKNOWN";
    }
}

KeyGroup group_from_string(const char *name) {
    if(strcmp(name, "LETTER") == 0) return GROUP_LETTER;
    if(strcmp(name, "NUMBER") == 0) return GROUP_NUMBER;
    if(strcmp(name, "SPACE") == 0) return GROUP_SPACE;
    if(strcmp(name, "ENTER") == 0) return GROUP_ENTER;
    if(strcmp(name, "MODIFIER") == 0) return GROUP_MODIFIER;
    if(strcmp(name, "CONTROL") == 0) return GROUP_CONTROL;
    if(strcmp(name, "FUNCTION") == 0) return GROUP_FUNCTION;
    if(strcmp(name, "NAV") == 0) return GROUP_NAV;
    if(strcmp(name, "LOCK") == 0) return GROUP_LOCK;

    return GROUP_LETTER;
}