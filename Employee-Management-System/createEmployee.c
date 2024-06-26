#include "header.h"

employee* createEmployee () {
    printf("\nEnter employee NAME\n");
    employee* newEmployee = (employee*)malloc(sizeof(employee));
    scanf("%s", newEmployee -> name);
    printf("\nEnter employee POSITION\n");
    printf(": 1 : JUNIOR\n: 2 : MIDDLE\n: 3 : SINIOR\n");
    int position = 0;
    scanf("%d", &position);
    switch (position) {
        case 1:
            newEmployee -> position = JUNIOR;
            newEmployee -> wage = 300;
            break;
        case 2:
            newEmployee -> position = MIDDLE;
            newEmployee -> wage = 1000;
            break;
        case 3:
            newEmployee -> position = SINIOR;
            newEmployee -> wage = 2000;
            break;
    }
    static int idCount = 1;
    newEmployee -> ID = idCount++;

    return newEmployee;
}