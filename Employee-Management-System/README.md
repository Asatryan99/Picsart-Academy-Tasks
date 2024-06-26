# Employee Management System

## Overview

This project is a simple console-based Employee Management System written in C. The program allows users to create, delete, update, and view employee information. The employees are stored dynamically, and the system can handle an expanding list of employees.

## Features

- **Add New Employee**: Create and add a new employee to the database.
- **Delete Employee**: Remove an employee from the database using their ID.
- **Update Employee Information**: Change an employee's name, position, or wage.
- **View Employee List**: Display a list of all employees with their IDs and names.

## Structure

The project consists of the following main files:

1. `main.c` - The main program file that handles user interaction and manages the database operations.
2. `header.h` - The header file containing the necessary declarations and structure definitions.
3. `employee.c` - Contains the functions to create, delete, and modify employee information.

## Usage

1. **Clone the repository**:

    ```bash
    git clone https://github.com/yourusername/employee-management-system.git
    cd employee-management-system
    ```

2. **Compile the program**:

    ```bash
    gcc main.c employee.c -o employee_management
    ```

3. **Run the program**:

    ```bash
    ./employee_management
    ```

4. **Follow the on-screen instructions** to manage employees.

## Code Overview

### `main.c`

The main file initializes the employee database, handles user input, and calls the appropriate functions based on the user's choices.

### `employee.c`

This file contains the implementation of the following functions:

- `employee* createEmployee()`: Prompts the user for employee details and creates a new employee.
- `void deleteEmployee(employee** dataBase, const int id, int* employeeCount)`: Deletes an employee from the database based on the provided ID.
- `void changeEmployeeInfo(employee** dataBase, const int ID, const int action, const int employeeCount)`: Modifies the information of an existing employee.

### `header.h`

The header file includes necessary libraries, definitions of constants, and the `employee` structure.

```c
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ID;
    char name[50];
    int position;
    int wage;
} employee;

#define JUNIOR 1
#define MIDDLE 2
#define SINIOR 3

employee* createEmployee();
void deleteEmployee(employee** dataBase, const int id, int* employeeCount);
void changeEmployeeInfo(employee** dataBase, const int ID, const int action, const int employeeCount);

#endif
```

## Contributions

Contributions are welcome! Please fork this repository and submit pull requests to add new features, fix bugs, or improve documentation.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

Feel free to customize the content as per your project specifics. Add or remove sections to better fit the structure and scope of your project.
