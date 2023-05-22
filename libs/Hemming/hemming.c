//
// Created by Alexandr on 07.05.2023.
//

#include "hemming.h"

int findControlBites(struct message *mes) {
    if (mes->n <= 0)
        return 0;
    int k = 1;
    int k_num = 1;
    while (k < k_num + mes->n*8 + 1) {
        k *= 2;
        k_num++;
    }
    return k_num - 1;
}

void cpyMes(struct hemming* ptr, struct message *mes) {
    int sum = ptr->bites;
    int i = 0;
    int j = 0;
    int mod = 1;
    while (j < sum) {
        if (j + 1 == mod)
            mod *= 2;
        else {
            setBite(&ptr->mes, j, getBite(mes, i));
            i++;
        }
        j++;
    }
}

void setControlBite(struct hemming* ptr, int i) {
    int num = pow(2, i);
    int poz = num-1;
    int res = 0;
    while (poz < ptr->bites) {
        int circle = num;
        while (poz < ptr->bites && circle > 0) {
            res = res ^ getBite(&ptr->mes, poz);
            circle--;
            poz++;
        }
        poz += num;
    }
    setBite(&ptr->mes, num-1, res);
}

void setCheckBites(struct hemming* ptr, struct message *mes) {
    for (int i = 0; i < ptr->controls; i++) {
        setControlBite(ptr, i);
    }
}

struct hemming * initHemming(struct message *mes) {
    int k = findControlBites(mes);
    int n = mes->n*8;
    struct hemming *answ = calloc(1, sizeof(struct hemming));
    int sum = n + k;
    int num = sum / 8 + ((sum % 8) != 0);
    initMessage(&answ->mes, num);
    answ->bites = sum;
    answ->controls = k;
    cpyMes(answ, mes);
    setCheckBites(answ, mes);
    return answ;
}

void freeHemming(struct hemming *ptr) {
    freeMessage(&ptr->mes);
    free(ptr);
}

void writeHemming(struct hemming *ptr) {
    writeBites(&ptr->mes, ptr->bites);
}

int isDegOfTwo(int x) {
    if (x == 0)
        return 0;
    return (x & (x-1)) == 0;
}

struct message toMessage(struct hemming * hem) {
    struct message mes;
    int n = (hem->bites - hem->controls) / 8;
    initMessage(&mes, n);
    int j = 0;
    for (int i = 0; i < hem->bites; ++i) {
        if (!isDegOfTwo(i+1)) {
            setBite(&mes, j, getBite(&hem->mes, i));
            j++;
        }
    }
    return mes;
}

void fixError(struct hemming *hem) {
    int pozError = 0;
    for (int i = 0; i < hem->bites; ++i) {
        if (getBite(&hem->mes, i))
            pozError ^= i + 1;
    }
    invertBite(&hem->mes, pozError-1);
}

int findTroubles(struct hemming *hem) {
    int pozError = 0;
    for (int i = 0; i < hem->bites; ++i) {
        if (getBite(&hem->mes, i))
            pozError ^= i + 1;
    }
    return pozError != 0;
}

int doError(struct hemming *hem) {
    srand(time(NULL));
    int poz = rand() % hem->bites;
    invertBite(&hem->mes, poz);
    return poz;
}