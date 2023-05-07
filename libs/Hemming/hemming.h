//
// Created by Alexandr on 07.05.2023.
//

#ifndef NETKURSOV_HEMMING_H
#define NETKURSOV_HEMMING_H

#include "../message/message.h"
#include <math.h>
#include <time.h>

struct hemming {
    struct message mes;
    int bites;
    int controls;
};

struct hemming * initHemming(struct message *mes);
struct message toMessage(struct hemming * hem);
void fixError(struct hemming *hem);
int findTroubles(struct hemming *hem);
int doError(struct hemming * hem);
void freeHemming(struct hemming *ptr);
void writeHemming(struct hemming *ptr);
#endif //NETKURSOV_HEMMING_H
