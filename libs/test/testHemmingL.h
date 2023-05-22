//
// Created by Alexandr on 21.05.2023.
//

#ifndef NETKURSOV_TESTHEMMINGL_H
#define NETKURSOV_TESTHEMMINGL_H

#include <stdio.h>
#include "../HemmingL/hemmingL.h"
#define ERROR(s) printf("Ошибка в функции %s\n%s\n", __FUNCTION__, s)
#define END printf("Завершение %s\n", __FUNCTION__)

void testHemL1();
void testHemL2();
void testHemL3();
void testHemL4();
void testHemL5();

void allHemLTest();


#endif //NETKURSOV_TESTHEMMINGL_H
