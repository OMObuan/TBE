module;

#include <termios.h>

export module get_keyboard_info_mod;

import rename_mod;

export namespace GET_KEYBOARD_INFO {

termios oldSettings{}, newSettings{};

char peekChar{};

void initKeyboard();

void closeKeyboard();

i32 keyboardHit();

i32 readChar();

}  // namespace GET_KEYBOARD_INFO
