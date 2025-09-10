#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    int frameLength, index = 0;

    printf("Enter the message:\n");
    scanf("%s", msg);

    printf("Enter frame lengths one by one (program stops when message ends):\n");

    while (msg[index] != '\0') {
        printf("Enter the current frame length: ");
        scanf("%d", &frameLength);

        for (int i = 0; i < frameLength && msg[index] != '\0'; i++) {
            printf("%c", msg[index++]);  // print character and move index
        }
        printf("%d\n", frameLength);       // print frame length as 
    }

    printf("\n");
    return 0;
}

