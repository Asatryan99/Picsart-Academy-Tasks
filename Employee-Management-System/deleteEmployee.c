#include "header.h"

void deleteEmployee (employee** dataBase, const int id, int* employeeCount) {
    for (int i = 0; i < *employeeCount; i++) {
        if ((dataBase[i] -> ID) == id) {
            free(dataBase[i]);
            for (int j = i; j < *employeeCount - 1; j++) {
                dataBase[j] = dataBase[j + 1];
            }
        }
    }
    (*employeeCount)--;
}