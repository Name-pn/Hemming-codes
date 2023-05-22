//
// Created by Alexandr on 21.05.2023.
//

#include "hemmingL.h"

int uniqueNum(struct hemmingL *code, char *str) {
    for (int j = 0; j < 256; ++j) {
        code->lArray[j] = 0;
    }
    int i = 0;
    while (str[i]) {
        code->lArray[str[i]]++;
        i++;
    }
    int res = 0;
    for (int j = 0; j < 256; ++j) {
        if (code->lArray[j])
            res++;
    }
    return res;
}

void getControlsAndInfo(struct hemmingL * hem, int num) {
    int info = 1;
    int info_k = 0;
    while (num > info) {
        info <<= 1;
        info_k++;
    }
    hem->info = info_k;
    int controls = 1;
    int posLastControl = 1;
    while (posLastControl < info + controls) {
        controls += 1;
        posLastControl *= 2;
    }
    controls--;
    hem->controls = controls;
}

static int isDegOfTwo(int x) {
    if (x == 0)
        return 0;
    return (x & (x-1)) == 0;
}

void setControl(struct message *mes, int index, int circle, int n) {
    for (int i = index; i < n;) {
        for (int j = 0; j < circle; ++j) {
            setBite(mes, index, getBite(mes, index) ^ getBite(mes, i+j));
        }
        i += 2*circle;
    }
}

void setControls(struct message *mes, int n) {
    int controlIndex = 0;
    int controlCircle = 1;
    for (int i = 0; i < n; ++i) {
        if (isDegOfTwo(i+1)) {
            setControl(mes, controlIndex, controlCircle, n);
        }
        controlIndex++;
        controlCircle *= 2;
    }
}

struct message codeL(int k, int n) {
    struct message res;
    initMessage(&res, n / 8 + ((n % 8) != 0));
    int i = 1;
    while (k != 0) {
        if (isDegOfTwo(i))
            ;
        else {
            setBite(&res, i-1, k%2);
            k >>= 1;
        }
        i++;
    }
    setControls(&res, n);
    return res;
}

void initTable(struct hemmingL *h) {
    int k = 0;
    int n = h->info + h->controls;
    h->bites = n;
    for (int i = 0; i < 256; ++i) {
        if (h->lArray[i]) {
            h->table[k].c = i;
            h->table[k].lenght = n;
            h->table[k].code = codeL(k, n);
            printf("Запись таблицы номер %d:\n%c с кодом - ", k, h->table[k].c);
            writeBites(&h->table[k].code, n);
            printf("\n");
            k++;
        }
    }
}

int findLetter(char c, struct hemmingL *h) {
    for (int i = 0; i < h->letters; ++i) {
        if (h->table[i].c == c)
            return i;
    }
    return -1;
}

void initMessageL(struct hemmingL * h) {
    int bites = h->bites*h->length;
    initMessage(&h->mes, bites/8 + (bites%8 != 0));
    for (int i = 0; i < h->length; ++i) {
        int j = findLetter(h->str[i], h);
        if (j != -1) {
            int k = i*h->bites;
            for (int l = 0; l < h->bites; ++l) {
                setBite(&h->mes, k+l, getBite(&h->table[j].code, l));
            }
        }
    }
}

struct hemmingL * initHemmingL(char *str) {
    struct hemmingL *res = calloc(1, sizeof(struct hemmingL));
    res->str = str;
    res->length = strlen(str);
    res->letters = uniqueNum(res, str);
    getControlsAndInfo(res, res->letters);
    initTable(res);
    initMessageL(res);
    return res;
}

int equal(struct hemmingL *hem, int index, int start) {
    for (int i = 0; i < hem->bites; ++i) {
        if (getBite(&hem->table[index].code, i) != getBite(&hem->mes, start+i))
            return 0;
    }
    return 1;
}

int findLetterReverse(struct hemmingL *hem, int start) {
    for (int i = 0; i < hem->letters; ++i) {
        if (equal(hem, i, start))
            return i;
    }
    return -1;
}

void toMessageL(struct hemmingL * hem, char* res) {
    int j = 0;
    for (int i = 0; i < hem->length; ++i) {
        int k = findLetterReverse(hem, i*hem->bites);
        if (k != -1)
            res[j++] = hem->table[k].c;
    }
}

int checkLetter(struct hemmingL *hem, int i) {
    int res = 0;
    for (int j = 1; j <= hem->bites; ++j) {
        if (getBite(&hem->mes, i*hem->bites + j - 1))
            res ^= j;
    }
    return res;
}

void fixErrorL(struct hemmingL *hem) {
    for (int i = 0; i < hem->length; ++i) {
        int res = checkLetter(hem, i);
        if (res)
            invertBite(&hem->mes, i*hem->bites+res-1);
    }
    return;
}

int findTroublesL(struct hemmingL *hem) {
    for (int i = 0; i < hem->length; ++i) {
        int res = checkLetter(hem, i);
        if (res)
            return 1;
    }
    return 0;
}

int doErrorL(struct hemmingL * hem) {
    srand(time(NULL));
    int i = rand() % (hem->length * hem->bites);
    invertBite(&hem->mes, i);
    return i;
}

void freeHemmingL(struct hemmingL *ptr) {
    freeMessage(&ptr->mes);
    for (int i = 0; i < ptr->letters; ++i) {
        freeMessage(&ptr->table[i].code);
    }
    free(ptr);
}
void writeHemmingL(struct hemmingL *ptr) {
    writeBites(&ptr->mes, ptr->bites*ptr->length);

    printf("\n");
}