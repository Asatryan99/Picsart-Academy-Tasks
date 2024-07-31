# Person Management System

This project is a simple command-line program for managing a database of people, written in C. It allows you to add, search, update, delete, and sort person records stored in a text file.

## Features

- **Add a new person**: Add a new person with an ID, first name, and last name.
- **Search for a person**: Search for a person by ID or name.
- **Update a person's information**: Update the first name and/or last name of an existing person.
- **Delete a person**: Remove a person from the database.
- **Sort the database**: Sort the records by ID or name.

## Getting Started

### Prerequisites

- A C compiler (e.g., `gcc`)
- A Unix-like operating system

### Compilation

To compile the program, run:

```sh
gcc -o person_management main.c
```

### Usage

After compiling, run the program with:

```sh
./person_management
```

You will be presented with a menu to choose from the available operations:

1. **Add a new person**
2. **Search for a person**
3. **Update a person**
4. **Delete a person**
5. **Sort database**
6. **Exit**

### Data Storage

- The data is stored in a text file named `database.txt`.
- The file `IDCOUNTER.txt` is used to keep track of the next available ID for new records.

## Functions Overview

### Secondary Functions

- **`itoa`**: Converts an integer to a string.
- **`print_line_with_colored_keyword`**: Prints a line with a highlighted keyword.
- **`line_counter`**: Counts the number of lines in a file.
- **`load_data`**: Loads the data from the file into memory.
- **`save_data`**: Saves the data from memory to the file.
- **`compare_by_id`**: Comparison function for sorting by ID.
- **`compare_by_name`**: Comparison function for sorting by name.

### Main Functions

- **`add_new_person`**: Adds a new person to the database.
- **`search_person`**: Searches for a person by ID or name.
- **`update_person`**: Updates a person's information.
- **`delete_person`**: Deletes a person from the database.
- **`sort_data`**: Sorts the database by ID or name.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue.

---
