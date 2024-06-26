#include "header.h"

int main () {

    int dataBase_size = 5;
    employee** dataBase = (employee**)malloc(sizeof(employee*) * dataBase_size);
    int employeeCount = 0;
    int input = 0;
    system("clear");
    while (input != 9) {
        if (dataBase_size == employeeCount) {
            dataBase_size += 5;
            dataBase = (employee**)realloc(dataBase, sizeof(employee*) * dataBase_size);
        }
        printf("\n");
        printf("Enter : 1 : create new Employee\n");
        printf("Enter : 2 : delete Employee\n");
        printf("Enter : 3 : change Employee info\n");
        printf("Enter : 4 : print Employee List\n");
        printf("Enter : 9 : EXIT\n");
        scanf("%d",&input);
        switch(input) {
            case 1:
                system("clear");
                dataBase[employeeCount++] = createEmployee();
                break;
            case 2:
                system("clear");
                int deleteID; 
                printf("Enter Employee ID: ");
                scanf("%d", &deleteID);
                deleteEmployee(dataBase, deleteID, &employeeCount);
                break;
            case 3:
                system("clear");
                int changeID;
                int changeAction;
                printf("Enter Employee ID: ");
                scanf("%d", &changeID);
                printf("Enter : 1 : change Employee Name\n");
                printf("Enter : 2 : change Employee Position\n");
                printf("Enter : 3 : change Employee Wage\n");
                scanf("%d", &changeAction);
                changeEmployeeInfo(dataBase, changeID, changeAction, employeeCount);
                break;
            case 4:
                system("clear");
                if (employeeCount == 0) {
                    printf("Empty\n");
                    break;
                }
                for (int i = 0; i < employeeCount; i++) {
                    printf("ID: %d | NAME: %s\n", dataBase[i] -> ID, dataBase[i] -> name);
                }
                break;
        }
    }
    system("clear");
    printf("\nGood Bye!\n");
    return 0;
}