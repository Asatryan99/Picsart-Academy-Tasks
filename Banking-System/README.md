# Banking System

This is a simple command-line banking system implemented in C. The program allows you to create and manage bank accounts, including depositing and withdrawing money. It demonstrates basic concepts such as dynamic memory allocation, user input handling, and basic banking operations.

## Features

- Create new bank accounts
- View a list of existing accounts
- Deposit money into an account
- Withdraw money from an account
- View account information

## Getting Started

### Prerequisites

- C compiler (e.g., `gcc`)

### Files

- `main.c`: Contains the main function and user interface logic.
- `accountInfo.c`: Contains the implementation of account-related functions.
- `accountInfo.h`: Header file for account-related function prototypes and the `Account` struct.

### Compiling the Program

To compile the program, use the following command:

```bash
gcc -o bankingSystem main.c accountInfo.c
```

### Running the Program

After compiling, you can run the program using:

```bash
./bankingSystem
```

## Usage

The program provides a simple menu for interacting with the banking system. The available options are:

- `1`: Create a new account
- `2`: View a list of existing accounts
- `3`: Deposit money into an account
- `4`: Withdraw money from an account
- `5`: View account information
- `9`: Exit the program

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.