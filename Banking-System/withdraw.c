#include "accountInfo.h"
void withdraw (Account* account) {

    printf("Enter withdraw sum \n");
    int withdraw;
    scanf("%d", &withdraw);
    account->balance -= withdraw;
}