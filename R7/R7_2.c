#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main() {
    // Example 1: Usage of strstr and strchr
    char *text = "CSE 220 Demo substring";
    char *substring = "Demo";
    char *ptr;

    //strstr to find a substring
    ptr = strstr(text,substring);
    if(ptr!= NULL){
        printf("Found string \"%s\" at position %ld\n", substring, ptr-text);    
    }

    char c = 't';
    ptr = strchr(text, c);
    if (ptr != NULL) {
        printf("First occurrence of '%c' at position %ld\n", c, ptr - text);
    }

    // Example 2: fscanf, fgetc, and fgets
    FILE *fp = fopen("Sample.txt", "r");
    if (!fp) {
        perror("sample.txt");
        return 1;
    }

    int num;
    char word[100];
    if (fscanf(fp, "%d %99s", &num, word) == 2) {
        printf("Read using fscanf: num = %d, word = %s\n", num, word);
    } else {
        printf("Failed to read with fscanf (file may be empty)\n");
    }
    // Reset the file pointer 
    rewind(fp);
    // fgets: Read a line from a file
    char line[256];
    if (fgets(line, sizeof(line), fp)) {
        printf("Line read with fgets: %s\n", line);
    }

    // fgetc: Read character-by-character
    printf("Characters read using fgetc: ");
    int ch;
    rewind(fp);
    while ((ch = fgetc(fp)) != EOF && ch != '\n') {
        putchar(ch);
    }
    putchar('\n');
    fclose(fp);


    // Example 3: sscanf
    char input[] = "42 apples";
    int n_apples;
    char fruit[50];
    if (sscanf(input, "%d %49s", &n_apples, fruit) == 2) {
        printf("Parsed using sscanf: %d %s\n", n_apples, fruit);
    }

    char name[50];

    printf("Please Enter your name :");
    scanf("%s",name);

    printf("You entered %s \n", name);

    return 0;
} // EOF == -1 