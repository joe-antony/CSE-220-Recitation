#include <stdio.h>
#include <string.h>

// Pass by value: string functions (safe)
void greetByValue(char name[]) {
    char temp[40];
    strcpy(temp, name);                        // Copy original name
    strcat(temp, " (Guest)");                  // Concatenate
    printf("Hello (by value): %s\n", temp);    // Print greeting
    printf("Length of greeting: %lu\n", strlen(temp));
}

// Pass by reference: demonstrate string comparison (safe)
void updateName(char *name) {
    if (strcmp(name, "John") == 0) {           // Compare strings
        strcpy(name, "Alice");                 // Update if match
    }
}

// Deliberate segmentation fault scenarios

// 1. Dereferencing a NULL pointer
void segfault_null_pointer() {
    char *p = NULL;
    *p = 'A'; // Segmentation fault: writing to a NULL address
}

// 2. Writing past the bounds of a small array
void segfault_out_of_bounds() {
    char small[4] = "abc";
    small[10] = 'Z'; // Segmentation fault or undefined behavior
}

// 3. Modifying read-only memory (string literal)
// void segfault_string_literal() {
//     char *str = "immutable";
//     str[0] = 'X'; // Segmentation fault on most systems
// }

int main() {
    char name[40] = "John";                    // Array and string
    printf("Original name: %s\n", name);

    greetByValue(name);                        // Pass by value, safe
    printf("After greetByValue: %s\n", name);

    updateName(name);                          // Pass by reference, safe
    printf("After updateName: %s\n", name);

    // Uncomment one line at a time to see the segmentation fault effect

    // segfault_null_pointer();
    // segfault_out_of_bounds();
    // segfault_string_literal();

    return 0;
}
