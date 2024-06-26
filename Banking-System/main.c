#include "accountInfo.h"

int main () {

    int dataBase_size = 5;
    Account* dataBase = (Account*)malloc(sizeof(Account) * dataBase_size);
    int accountCount = 0;
    int input = 0;
    system("clear");
    while (input != '9') {
        if (dataBase_size == accountCount) {
            dataBase_size += 5;
            dataBase = (Account*)realloc(dataBase,sizeof(Account) * dataBase_size);
        }
        printf("\n\n");
        printf("Enter : 1 : for create new account\n");
        printf("Enter : 2 : for view accounts list\n");
        printf("Enter : 3 : for deposit\n");
        printf("Enter : 4 : for withdraw\n");
        printf("Enter : 5 : view account info\n");
        printf("Enter : 9 : for EXIT\n");
        scanf("%d", &input);
        int accountnumber = 0;
        switch (input) {

            case 1:
                system("clear");
                dataBase[accountCount++]  = createAccount();
                break;
            case 2:
                if (accountCount == 0) {
                    system("clear");
                    printf("No bank accounts yet !");
                    break;
                }
                system("clear");
                for (int i = 0; i < accountCount; i++) {
                    printf("%d: %s\n", i + 1, dataBase[i].holder);
                }
                break;
            case 3: 
                if (accountCount == 0) {
                    system("clear");
                    printf("No bank accounts yet !");
                    break;
                }
                system("clear");
                printf("Enter account number\n");
                scanf("%d", &accountnumber);
                deposit(&dataBase[accountnumber - 1]);
                break;
            case 4:
                if (accountCount == 0) {
                    system("clear");
                    printf("No bank accounts yet !");
                    break;
                }
                system("clear");
                printf("Enter account number\n");
                scanf("%d", &accountnumber);
                withdraw(&dataBase[accountnumber - 1]);
                break;
            case 5:
                if (accountCount == 0) {
                    system("clear");
                    printf("No bank accounts yet !");
                    break;
                }
                system("clear");
                printf("Enter account number\n");
                scanf("%d", &accountnumber);
                viewAccount(dataBase[accountnumber - 1]);
                break;
            case 9:
                return 0;
        }
    }
    free(dataBase);
}