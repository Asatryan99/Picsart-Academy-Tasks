#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef enum {
    JUNIOR,
    MIDDLE,
    SINIOR
} position;

typedef struct {
    int ID;
    char name[50];
    int position;
    int wage;
} employee;


employee* createEmployee ();
void deleteEmployee (employee** dataBase, const int id, int* employeeCount);
void changeEmployeeInfo (employee** dataBase, const int ID, const int action, const int employeeCount);
