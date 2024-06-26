#include "accountInfo.h"
Account createAccount () {

    printf("Enter new account holder\n");
    char holder[50];
    scanf("%s", holder);
    Account new_account;
    strcpy(new_account.holder, holder);
    static int accountCount = 0;
    new_account.number = accountCount++;
    new_account.balance = 0;
    return new_account;
}