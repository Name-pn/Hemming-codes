//
// Created by Alexandr on 21.05.2023.
//

#include "testHemmingL.h"

void testHemL1() {
    struct hemmingL *hem = initHemmingL("test");
    writeHemmingL(hem);
    freeHemmingL(hem);
}

void testHemL2() {
    struct hemmingL *hem = initHemmingL("Road");
    writeHemmingL(hem);
    doErrorL(hem);
    writeHemmingL(hem);
    fixErrorL(hem);
    writeHemmingL(hem);
    freeHemmingL(hem);
}

void testHemL3() {

}

void testHemL4() {

}

void testHemL5() {

}

void allHemLTest() {
    testHemL1();
    testHemL2();
    testHemL3();
    testHemL4();
    testHemL5();
}
