#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define MAX_PASSWORD_LENGTH 20

void maskPassword(char* password) {
    int i = 0;
    char c;
    while ((c = getch()) != '\r') {
        if (c == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else if (i < MAX_PASSWORD_LENGTH - 1) {
            password[i] = c;
            printf("*");
            i++;
        }
    }
    password[i] = '\0';
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter your password: ");
    maskPassword(password);

    printf("\nYour password is: %s\n", password);
    
    return 0;
}
