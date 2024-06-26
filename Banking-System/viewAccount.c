#include "accountInfo.h"
void viewAccount (Account account) {
    printf("\n");
    printf("Account INFO\n");
    printf("Number: %d\n", account.number);
    printf("Balace: %d $\n", account.balance);
    printf("Holder: %s\n", account.holder);
    printf("\n");
}