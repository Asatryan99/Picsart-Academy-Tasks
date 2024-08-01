#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define DATABASE "database.txt"

typedef struct {
    int id;
    char FirstName[100];
    char LastName[100];
} person;

// secondary functions

char* itoa(ssize_t num);
void print_line_with_colored_keyword (const char* line, const char* keyword);
long line_counter(FILE* file);
person* load_data (size_t* size);
void save_data (person* persons, size_t data_size);
int compare_by_id(const void *a, const void *b);
int compare_by_name(const void *a, const void *b);

// main functions

void add_new_person ();
void search_person ();
void update_person ();
void delete_person ();
void sort_data ();

int main () {
    
    int create_database_file = open(DATABASE, O_CREAT | O_EXCL, 0644);
    close(create_database_file);

    system("clear");
    int choice;
    while (1) {

        printf("USEAGE: 1: [ADD A NEW PERSON]\n");
        printf("USEAGE: 2: [SEARCH FOR A PERSON (by ID or NAME)\n");
        printf("USEAGE: 3: [UPDATE A PERSON]\n");
        printf("USEAGE: 4: [DELETE A PERSON]\n");
        printf("USEAGE: 5: [SORT DATABASE] (by ID or NAME)\n");
        printf("USEAGE: 6: [EXIT]\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);            


        switch (choice) {
            case 1:
                add_new_person(); 
                printf("\n");    
                break;
            case 2:
                search_person();
                printf("\n");
                break;
            case 3:
                update_person();
                printf("\n");
                break;
            case 4:
                delete_person();
                printf("\n");
                break;
            case 5:
                sort_data ();
                printf("\n");
                break;
            case 6:
                return 0;
        }
    }
}

char* itoa(ssize_t num) {
    int size = 0;
    int tmp = num;
    while (num) {
        size++;
        num /= 10;
    }
    num = tmp;
    char* str = (char*)malloc((size + 1) * sizeof(char));
    str[size] = '\0';
    for (int i = size - 1; i >= 0; --i) {
        str[i] = (num % 10) + 48;
        num /= 10;
    }
    return str;
}

int compare_by_id(const void *a, const void *b) {
    const person *person_a = (const person *)a;
    const person *person_b = (const person *)b;
    return person_a->id - person_b->id;
}

int compare_by_name(const void *a, const void *b) {
    const person *person_a = (const person *)a;
    const person *person_b = (const person *)b;
    return strcmp(person_a->FirstName, person_b->FirstName);
}

void print_line_with_colored_keyword (const char* line, const char* keyword) {

    const char* start = line;
    const char* position = strstr(line, keyword);

    printf("%.*s", (int)(position - start), start);
    printf("\033[1;31m%s\033[0m", keyword);
    start = position + strlen(keyword);
    printf("%s\n", start);
}

long line_counter(FILE* file) {
    int count = 0; char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    return count;
}

person* load_data (size_t* data_size) {

    FILE* database = fopen(DATABASE, "r");
    if (!database) {
        perror("fopen is failed");
        exit(EXIT_FAILURE);
    }
    long line_count = line_counter(database);

    person* persons = (person*)calloc(line_count, sizeof(person));
        if (persons == NULL) {
        perror("Memory allocation failed");
        fclose(database);
        exit(EXIT_FAILURE);
    }

    size_t index = 0;
    person load_person;
    rewind(database);
    while ((fscanf(database, "%d, %99[^,], %99[^\n]", &load_person.id, load_person.FirstName, load_person.LastName)) == 3) {
        persons[index++] = load_person;
    }

    if (fclose(database) == -1) {
        perror("fclose if failed");
        exit(EXIT_FAILURE);
    }

    *data_size = index;
    return persons;
}

void save_data (person* persons, size_t data_size) {

    FILE* database = fopen(DATABASE, "w");
    if (!database) {
        perror("fopen is failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < data_size; ++i) {
        char* buffer = (char*)calloc(sizeof(char), sizeof(persons[i]));
        fprintf(database, "%d, %s, %s\n", persons[i].id, persons[i].FirstName, persons[i].LastName);
        strcat(buffer, "\0");
        
        size_t bytes_written = fwrite(buffer, sizeof(char), strlen(buffer), database);
        if (bytes_written == -1) {
            perror("write");
            fclose(database);
            exit(EXIT_FAILURE);
        }

        free(buffer);
    }

    if (fclose(database) == -1) {
        perror("fclose is failed");
        exit(EXIT_FAILURE);
    }
}

void add_new_person () {

    FILE* database = fopen (DATABASE, "a+");
    if (!database) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    int id_fd = open("IDCOUNTER.txt", O_CREAT | O_RDWR, 0644);
    if (id_fd == -1) {
        perror("open count id");
        exit(EXIT_FAILURE);
    }

    char tmp[10];
    lseek(id_fd, 0, SEEK_SET);
    size_t read_id = read(id_fd, tmp, sizeof(tmp));
    if (read_id == -1) {
        perror("error read id history");
        exit(EXIT_FAILURE);
    }
    int ID = atoi(tmp);

    person* new_person = (person*)malloc(sizeof(person));

    printf("Enter your first name: ");
    scanf("%s", new_person->FirstName);
    printf("Enter your last name: ");
    scanf("%s", new_person->LastName);
    new_person->id = ID++;

    strcpy(tmp, itoa(ID));
    strcat(tmp, "\0");
    lseek(id_fd, 0, SEEK_SET);
    size_t write_id = write(id_fd, tmp, strlen(tmp));
    if (write_id == -1) {
        perror("error write id history");
        exit(EXIT_FAILURE);
    }
   
    fprintf(database, "%d, %s, %s\n", new_person->id, new_person->FirstName, new_person->LastName);

    if (fclose(database) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    free(new_person);
}

void search_person () {

    char keyword[200];
    printf("Enter <Name> or <ID>\n");
    scanf("%s", keyword);
    printf("\n");

    int database = open(DATABASE, O_RDONLY);
    if (database == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct stat st;
    if (fstat(database, &st) < 0) {
        perror("Error getting data base");
        close(database);
        exit(EXIT_FAILURE);
    }
    long long int database_size = st.st_size;

    char buffer[database_size];
    if (read(database, buffer, database_size) == -1) {
        perror("error read data base");
        exit(EXIT_FAILURE);
    }
    
    char* line = strtok(buffer, "\n");
    while (line != NULL) {
        if (strstr(line, keyword)) {
            print_line_with_colored_keyword(line, keyword);
        }
        line = strtok(NULL, "\n");
    }

    if (close(database) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}


void update_person () {

    int id;
    printf("Enter person ID: ");
    scanf("%d", &id);

    bool success = true;

    size_t data_size;
    person* database = load_data(&data_size);

    for (size_t i = 0; i < data_size; i++) {
        if (database[i].id == id) {
            char* old_person_info = (char*)calloc(sizeof(char), sizeof(database[i]));
            sprintf(old_person_info, "ID: %d, FirstName: %s, LastName: %s",database[i].id, database[i].FirstName, database[i].LastName);

            printf("Enter update firstname: ");
            scanf("%s", database[i].FirstName);
            printf("Enter update lastname: ");
            scanf("%s", database[i].LastName);

            char* new_person_info = (char*)calloc(sizeof(char), sizeof(database[i]));
            sprintf(new_person_info, "ID: %d, FirstName: %s, LastName: %s",database[i].id, database[i].FirstName, database[i].LastName);

            printf("\n\033[1;31m%s\033[0m", old_person_info);
            printf("  -- Change to -->  ");
            printf("\033[1;32m%s\033[0m\n", new_person_info);
            free(old_person_info);
            free(new_person_info);
            
            success = false;
            save_data(database, data_size);
        }
    }

    if (success == true) {
        perror("Invalid ID");
        exit(EXIT_FAILURE);
    }
}

void delete_person () {

    int id;
    printf("Enter person ID: ");
    scanf("%d", &id);

    bool success = true;

    size_t data_size;
    person* database = load_data(&data_size);

    for (size_t i = 0; i < data_size; i++) {
        if (database[i].id == id) {
            person tmp;
            for (size_t j = i; j < data_size - 1; j++) {
                tmp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = tmp;
            }

            save_data(database, data_size - 1);
            success = false;
        }
    }

    if (success == true) {
        perror("Invalid ID");
        exit(EXIT_FAILURE);
    }
}

void sort_data () {

    int action;
    printf("USEAGE: 1: [SORT BY ID]\n");
    printf("USEAGE: 2: [SORT BY NAME]\n");
    scanf("%d", &action);

    size_t data_size;
    person* database = load_data(&data_size);

    switch (action) {
        case 1:
            qsort(database, data_size, sizeof(person), compare_by_id);
            break;
        case 2:
            qsort(database, data_size, sizeof(person), compare_by_name);
            break;
    }

    save_data(database, data_size);
}
