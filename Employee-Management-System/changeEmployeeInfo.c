#include "header.h"

void changeEmployeeInfo (employee** dataBase, const int ID, const int action, const int employeeCount) {
    switch (action) {
        case 1:
            char tmpString[50];
            printf("Enter new name: ");
            scanf("%s", tmpString); 
            for (int i = 0; i < employeeCount; i++) {
                if ((dataBase[i] -> ID) == ID) {
                    strcpy(dataBase[i]->name, tmpString);
                }
            }
            break;
        case 2:
            int changePosition;
            printf("\nEnter new position: \nEnter : 1 : JUNIOR\nEnter : 2 : MIDDLE\nEnter : 3 : SINIOR\n");
            scanf("%d",&changePosition);
            for (int i = 0; i < employeeCount; i++) {
                if ((dataBase[i] -> ID) == ID) {
                    switch (changePosition)
                    {
                    case 1: 
                        dataBase[i]-> position = JUNIOR;
                        dataBase[i]-> wage = 300; 
                        break;
                    case 2: 
                        dataBase[i]-> position = MIDDLE; 
                        dataBase[i]-> wage = 1000; 
                        break;
                    case 3: 
                        dataBase[i]-> position = SINIOR;
                        dataBase[i]-> wage = 2000;  
                        break;
                    }
                }
            }
            break;
        case 3:
            int newWage;
            printf("\nEnter new Wage: ");
            scanf("%d",&newWage);
            for (int i = 0; i < employeeCount; i++) {
                if ((dataBase[i] -> ID) == ID) {
                    dataBase[i] -> wage = newWage;
                }
            }
            break;
    }
}    
