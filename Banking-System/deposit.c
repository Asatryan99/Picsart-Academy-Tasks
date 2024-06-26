#include "accountInfo.h"
void deposit (Account* account) {

    printf("Enter deposit sum \n");
    int deposit;
    scanf("%d", &deposit);
    account->balance += deposit;
}