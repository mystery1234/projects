#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_FILE "minidb.txt"
#define MAX 100

void set_key(const char *key, const char *value) {
    FILE *fp = fopen(DB_FILE, "r");
    FILE *temp = fopen("temp.txt", "w");
    char line[MAX], file_key[MAX], file_value[MAX];
    int updated = 0;

    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {
            sscanf(line, "%[^:]:%s", file_key, file_value);
            if (strcmp(file_key, key) == 0) {
                fprintf(temp, "%s:%s\n", key, value);
                updated = 1;
            } else {
                fprintf(temp, "%s", line);
            }
        }
        fclose(fp);
    }

    if (!updated) {
        fprintf(temp, "%s:%s\n", key, value);
    }

    fclose(temp);
    remove(DB_FILE);
    rename("temp.txt", DB_FILE);

    printf(updated ? "Key updated.\n" : "New key added.\n");
}

void get_key(const char *key) {
    FILE *fp = fopen(DB_FILE, "r");
    char line[MAX], file_key[MAX], file_value[MAX];

    if (!fp) {
        printf("Database not found.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^:]:%s", file_key, file_value);
        if (strcmp(file_key, key) == 0) {
            printf("Value: %s\n", file_value);
            fclose(fp);
            return;
        }
    }

    printf("Key not found.\n");
    fclose(fp);
}

void delete_key(const char *key) {
    FILE *fp = fopen(DB_FILE, "r");
    FILE *temp = fopen("temp.txt", "w");
    char line[MAX], file_key[MAX], file_value[MAX];
    int found = 0;

    if (!fp) {
        printf("Database not found.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^:]:%s", file_key, file_value);
        if (strcmp(file_key, key) != 0) {
            fprintf(temp, "%s", line);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove(DB_FILE);
    rename("temp.txt", DB_FILE);

    printf(found ? "Key deleted.\n" : "Key not found.\n");
}
