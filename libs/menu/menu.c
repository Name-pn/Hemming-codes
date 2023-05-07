#include "menu.h"

void writeInvitation() {
    printf("Введите %d для очистки экрана\n", CLEAN);
    printf("Для ввода сообщения %d\n", INPUT_M);
    printf("Для внесения ошибки %d\n", INTERFERENCE);
    printf("Для вывода сообщения %d\n", RESULT);
    printf("Для попытки устранения ошибки %d\n", FIX);
    printf("Для попытки обнаружения ошибки %d\n", FIND_ERROR);
    printf("-> ");
}

void runMenu() {
    int code = UNDEFINED;
    int flagThereIs = 0;
    char str[MAX_STR];
    struct message mes;
    struct hemming *hem;
    while (code != END_M) {
        switch (code) {
            case UNDEFINED: {
                writeInvitation();
                scanf("%d", &code);
                if (code < 0 || code > FIND_ERROR)
                    code = UNDEFINED;

                break;
            }
            case CLEAN: {
                system("cls");
                code = UNDEFINED;
                break;
            }
            case INPUT_M: {
                gets(str);
                gets(str);
                flagThereIs = 1;
                int n = strlen(str) + 1;
                initMessage(&mes, n);
                setMessage(&mes, str);
                hem = initHemming(&mes);
                printf("Код Хемминга для введенного сообщения\n");
                writeHemming(hem);
                putchar('\n');
                code = UNDEFINED;
                break;
            }
            case INTERFERENCE: {
                if (flagThereIs)
                    printf("Сделана ошибка в разряде %d\n", doError(hem));
                else
                    ERROR("Ошибка: попытка сделать ошибку для не введенной строки");
                code = UNDEFINED;
                break;
            }
            case RESULT: {
                if (flagThereIs) {
                    printf("Код Хемминга:\n");
                    writeHemming(hem);
                    printf("Закодированное сообщение:");
                    struct message tmp = toMessage(hem);
                    puts(tmp.bufPtr);
                    freeMessage(&tmp);
                }
                code = UNDEFINED;
                break;
            }
            case FIX: {
                code = INPUT_M;
                fixError(hem);
                code = UNDEFINED;
                break;
            }
            case FIND_ERROR: {
                if (findTroubles(hem))
                    printf("Обнаружены ошибки\n");
                else
                    printf("Ошибки не обнаружены\n");
                code = UNDEFINED;
            }
        }


    }
}