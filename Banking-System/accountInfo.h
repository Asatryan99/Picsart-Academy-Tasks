#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Account INFO

typedef struct {
    int number;
    int balance;
    char holder[50];
} Account;

// Fuction Prototypes 

Account createAccount ();
void allAccounts (Account* account, int count);
void viewAccount (Account account);
void withdraw (Account* account);
void deposit (Account* account);