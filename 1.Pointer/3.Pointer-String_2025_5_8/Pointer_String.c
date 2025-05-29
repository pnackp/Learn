#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to find the length of a string using pointer (no strlen)
// +1 is added to reserve space for null terminator '\0'
int findindex(char *s){
    int l = 0;
    while (*(s+l)) {
        l++;
    }
    return l + 1; // reserve space for '\0'
}

// Function to print each character in the string using pointer
void charac(char *s){
    printf("Characters: ");
    while (*s){
        printf("%c ", *s);
        s++;
    }
    printf("\n");
} 

// Function to print the string in uppercase (no modification to original string)
void upper(char* s){
    printf("Uppercase: ");
    while (*s){
        printf("%c", toupper(*s)); // use toupper from ctype.h
        s++;
    }
    printf("\n");
}

// Function to check if the original and reversed strings are the same
void palindrome(char* s , char *cp){
    while (*s && *cp) {
        if (*s != *cp) {
            printf("Palindrome: NO\n");
            return;
        }
        s++;
        cp++;
    }
    printf("Palindrome: YES\n");
}

// Function to reverse the string and check for palindrome
void reverse(char* s){
    int x = findindex(s); // length including '\0'
    char cpy[x]; // temporary array to hold reversed string
    int o = 0;

    printf("Reversed: ");
    for(int i = x - 2; i >= 0 ; i--){ // -2 because last char is '\0' l e v e l \0
        cpy[o] = s[i];
        printf("%c", cpy[o]);
        o++;
    }
    cpy[o] = '\0'; // don't forget null terminator!
    printf("\n");
    palindrome(s, cpy);
}

int main(){
    char *stg;  
    char str[100];

    // Get user input
    printf("Enter string: ");
    scanf("%s", str);

    // Calculate string length to allocate exact memory for stg
    int x = findindex(str);
    stg = (char *)malloc(x * sizeof(char));  
    strcpy(stg, str); // copy input to dynamically allocated memory

    // Output results
    printf("Length: %d\n", x - 1); // subtract 1 to show only actual string length
    charac(stg);
    upper(stg);
    reverse(stg);

    free(stg); // Clean up heap memory
    return 0;
}
