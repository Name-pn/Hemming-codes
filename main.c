#include <stdio.h>
#include "libs/test/testMessage.h"
#include "libs/test/testHemming.h"
#include "libs/menu/menu.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    allMesTest();
    allHemTest();
    runMenu();
    return 0;
}
