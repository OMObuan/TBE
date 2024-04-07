// Copyright 2024 OMObuan

module;

#if defined(_WIN32) or defined(_WIN64)

#include <conio.h>

#else

#include <termios.h>
#include <unistd.h>

#endif

module get_keyboard_info_mod;

import rename_mod;

namespace GET_KEYBOARD_INFO {

void initKeyboard() {
#if defined(_WIN32) or defined(_WIN64)

#elif defined(__linux)

    tcgetattr(0, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    // newSettings.c_lflag &= ~ICANON;
    newSettings.c_cc[VTIME] = 0;
    newSettings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &newSettings);

#endif
}

void closeKeyboard() {
#if defined(_WIN32) or defined(_WIN64)

#elif defined(__linux)

    tcsetattr(0, TCSANOW, &oldSettings);

#endif
}

i32 keyboardHit() {
#if defined(_WIN32) or defined(_WIN64)

    return _kbhit();

#else

    char nowReadChar{};
    if (peekChar != -1) return true;
    newSettings.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &newSettings);
    auto result = read(0, &nowReadChar, 1);
    newSettings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &newSettings);
    if (result == true) {
        peekChar = nowReadChar;
        return true;
    }
    return false;

#endif
}

i32 readChar() {
#if defined(_WIN32) or defined(_WIN64)

    return _getch();

#else

    char nowReadChar{};
    if (peekChar != -1) {
        nowReadChar = peekChar;
        peekChar = -1;
        return nowReadChar;
    }
    read(0, &nowReadChar, 1);
    return nowReadChar;

#endif
}

}  // namespace GET_KEYBOARD_INFO
