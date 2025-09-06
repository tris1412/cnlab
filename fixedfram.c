#include <stdio.h>
#include <string.h>

int main() {
    char a[100];
    int fl, i;

    printf("Enter the string:\n");
    scanf("%s", a);

    printf("Enter the frame length:\n");
    scanf("%d", &fl);

    for (i = 0; i < strlen(a); i++) {
        printf("%c", a[i]);
        if ((i + 1) % fl == 0) {
            printf(" ");  // separate frames by space
        }
    }
    printf("\n");
    return 0;
}
