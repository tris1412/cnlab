#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[200];
    int n, i, m = 1, fl;

    printf("Enter the string:\n");
    scanf("%s", a);

    n = strlen(a);
    int index = 0;
    b[0] = 's'; // start marker

    printf("Variable Length Framing:\n");

    while (index < n) {
        printf("Enter the current frame length: ");
        scanf("%d", &fl);

        for (i = 0; i < fl && index < n; i++) {
            b[m++] = a[index++];
        }

        // Append the frame length as a character
        b[m++] = fl + '0';
    }

    b[m++] = 'd'; // end marker
    b[m] = '\0';

    printf("%s\n", b);
    return 0;
}

