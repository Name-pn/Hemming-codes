//
// Created by Alexandr on 21.05.2023.
//

#ifndef NETKURSOV_HEMMINGL_H
#define NETKURSOV_HEMMINGL_H

#include "../message/message.h"
#include <math.h>
#include <time.h>
#include <string.h>

struct letter {
    char c;
    struct message code;
    int lenght;
};

struct hemmingL {
    char* str;
    struct message mes;
    struct letter table[256];
    char lArray[256];
    int length;
    int letters;
    int info;
    int bites;
    int controls;
};

struct hemmingL * initHemmingL(char *str);
void toMessageL(struct hemmingL * hem, char* res);
void fixErrorL(struct hemmingL *hem);
int findTroublesL(struct hemmingL *hem);
int doErrorL(struct hemmingL * hem);
void freeHemmingL(struct hemmingL *ptr);
void writeHemmingL(struct hemmingL *ptr);

#endif //NETKURSOV_HEMMINGL_H
