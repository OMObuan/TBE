// Copyright 2024
// OMObuan

#include <iostream>
import get_keyboard_info_mod;
import rename_mod;

i32 main(i32, char *[]) {
    GET_KEYBOARD_INFO::initKeyboard();
    while (true) {
        GET_KEYBOARD_INFO::keyboardHit();
        auto getResult = GET_KEYBOARD_INFO::readChar();
        std::cout << getResult << '\n';
        // if (getResult == 3) break;
    }
    GET_KEYBOARD_INFO::closeKeyboard();
}
