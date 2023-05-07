//
// Created by Alexandr on 07.05.2023.
//
#include "testHemming.h"
#include "../message/message.h"
#include "../Hemming/hemming.h"

void testHem1() {
    struct message mes;
    initMessage(&mes, 2);
    setMessage(&mes, "1");
    struct hemming *hem = initHemming(&mes);
    writeHemming(hem);
    printf("= 00100000 11000000 00000\n");
    freeHemming(hem);
    freeMessage(&mes);
    END;
}

void testHem2() {
    //9 = 57 = 00111001
    struct message mes;
    initMessage(&mes, 2);
    setMessage(&mes, "9");
    struct hemming *hem = initHemming(&mes);
    writeHemming(hem);
    printf("= 11110010 11000000 00000\n");
    freeHemming(hem);
    freeMessage(&mes);
    END;
}
void testHem3() {
    //9 = 57 = 00111001
    struct message mes;
    initMessage(&mes, 2);
    setMessage(&mes, "9");
    struct hemming *hem = initHemming(&mes);
    struct message from = toMessage(hem);
    if (memcmp(mes.bufPtr, from.bufPtr, 2))
        ERROR("Ошибка в toMessage");
    printf("%s = 9\n", from.bufPtr);
    freeHemming(hem);
    freeMessage(&mes);
    END;
}
void testHem4() {
    //9 = 57 = 00111001
    //2 = 50 = 00110010
    struct message mes;
    initMessage(&mes, 3);
    setMessage(&mes, "92");
    struct hemming *hem = initHemming(&mes);
    writeHemming(hem);
    putc( '\n', stdout);
    int poz = doError(hem);
    printf("Ошибка в %d разряде\n", poz);
    writeHemming(hem);
    putc('\n', stdout);
    fflush(stdout);
    fixError(hem);
    printf("Двоичный вид после исправления ошибки\n", poz);
    writeHemming(hem);
    putc('\n', stdout);
    struct message from = toMessage(hem);
    if (memcmp(mes.bufPtr, from.bufPtr, 3))
        ERROR("Ошибка в fixError или doError");
    printf("%s = 92\n", from.bufPtr);
    freeHemming(hem);
    freeMessage(&mes);
    END;
}
void testHem5() {

}

void allHemTest() {
    testHem1();
    testHem2();
    testHem3();
    testHem4();
    testHem5();
}