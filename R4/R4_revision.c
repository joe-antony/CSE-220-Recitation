#include  <stdio.h>
#include <string.h>

    // Pass by value: string functions (safe)
    void greetByValue(char name_pass_by_value[]) {
        char temp[40];
        strcpy(temp, name_pass_by_value);                        // Copy original name
        strcat(temp, " (Guest)");                  // Concatenate
        printf("Hello (by value): %s\n", temp);    // Print greeting
        printf("Length of greeting: %lu\n", strlen(temp));
    }

    // Pass by reference: demonstrate string comparison (safe)
    void updateName(char *name_pass_by_reference) {
        if (strcmp(name_pass_by_reference, "John") == 0) {           // Compare strings
            strcpy(name_pass_by_reference, "Alice");                 // Update if match
        }
    }

    int segfault_null_pointer() {
        char *p = NULL; // Declaring a char pointer p and initializing it to NULL
        *p = 'A'; // *p dereferences the NULL pointer,
        return 0; // This line will not be reached
    }
    
    void segfault_out_of_bounds() {
    char small[4] = "abc";
    small[10] = 'Z'; // Segmentation fault or undefined behavior
    }

int main() {
    char name[40] = "John";      // Array and string
    printf("Original name: %s\n", name);



    greetByValue(name);                        // Pass by value, safe
    printf("After greetByValue: %s\n", name);

    updateName(name);                          // Pass by reference, safe
    printf("After updateName: %s\n", name);

    // Uncomment one line at a time to see the segmentation fault effect

    segfault_null_pointer();
    segfault_out_of_bounds();
    segfault_string_literal();
    return 0;
}