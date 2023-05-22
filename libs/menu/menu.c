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

void writeInvitationMain() {
    printf("Для выхода введите 0\n");
    printf("Для работы с программой кодирования букв кодами Хемминга введите 1\n");
    printf("Для работы с программой кодирования сообщения кодом Хемминга введите 2\n");
    printf("-> ");
}

void runMenu2() {
    int code = UNDEFINED;
    int flagThereIs = 0;
    char str[MAX_STR];
    struct message mes;
    struct hemmingL *hem;
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
                hem = initHemmingL(str);
                printf("Код Хемминга для введенного сообщения\n");
                writeHemmingL(hem);
                putchar('\n');
                code = UNDEFINED;
                break;
            }
            case INTERFERENCE: {
                if (flagThereIs)
                    printf("Сделана ошибка в разряде %d\n", doErrorL(hem));
                else
                    ERROR("Ошибка: попытка сделать ошибку для не введенной строки");
                code = UNDEFINED;
                break;
            }
            case RESULT: {
                if (flagThereIs) {
                    printf("Код Хемминга:\n");
                    writeHemmingL(hem);
                    printf("Закодированное сообщение:");
                    char tmp[256];
                    toMessageL(hem, tmp);
                    puts(tmp);
                }
                code = UNDEFINED;
                break;
            }
            case FIX: {
                code = INPUT_M;
                fixErrorL(hem);
                code = UNDEFINED;
                break;
            }
            case FIND_ERROR: {
                if (findTroublesL(hem))
                    printf("Обнаружены ошибки\n");
                else
                    printf("Ошибки не обнаружены\n");
                code = UNDEFINED;
            }
        }
    if (flagThereIs)
        freeHemmingL(hem);

    }
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
        if (flagThereIs)
            freeHemming(hem);

    }
}

void runMainMenu() {
    int code = UNDEFINED;
    while (code != END_M) {
        switch (code) {
            case UNDEFINED: {
                writeInvitationMain();
                scanf("%i", &code);
                break;
            }
            case 1: {
                runMenu2();
                code = UNDEFINED;
                break;
            }
            case 2: {
                runMenu();
                code = UNDEFINED;
                break;
            }
            default:
                code = UNDEFINED;
        }
    }
}