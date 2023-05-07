//
// Created by Alexandr on 07.05.2023.
//

#ifndef NETKURSOV_TESTHEMMING_H
#define NETKURSOV_TESTHEMMING_H

#include <stdio.h>
#define ERROR(s) printf("Ошибка в функции %s\n%s\n", __FUNCTION__, s)
#define END printf("Завершение %s\n", __FUNCTION__)

void testHem1();
void testHem2();
void testHem3();
void testHem4();
void testHem5();

void allHemTest();

#endif //NETKURSOV_TESTHEMMING_H
