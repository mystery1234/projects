#include <stdio.h>
#include <string.h>
#include "db.h"

int main() {
    char command[100], key[100], value[100];

    printf("MiniDB - Tiny Flat File DB in C\n");
    printf("Commands: set <key> <value>, get <key>, delete <key>, exit\n");

    while (1) {
        printf("MiniDB> ");
        scanf("%s", command);

        if (strcmp(command, "set") == 0) {
            scanf("%s %s", key, value);
            set_key(key, value);
        } else if (strcmp(command, "get") == 0) {
            scanf("%s", key);
            get_key(key);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", key);
            delete_key(key);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting MiniDB...\n");
            break;
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
