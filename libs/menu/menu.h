//
// Created by Alexandr on 07.05.2023.
//

#ifndef NETKURSOV_MENU_H
#define NETKURSOV_MENU_H

#define UNDEFINED 100
#define CLEAN 2
#define INPUT_M 3
#define INTERFERENCE 4
#define RESULT 5
#define FIX 6
#define FIND_ERROR 7
#define END_M 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../message/message.h"
#include "../hemming/hemming.h"
#include "../HemmingL/hemmingL.h"
#define MAX_STR 256
#define ERROR(s) printf("Ошибка в функции %s\n%s\n", __FUNCTION__, s)

void runMainMenu();

#endif //NETKURSOV_MENU_H
