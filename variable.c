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
printf("S");
        for (int i = 0; i < frameLength && msg[index] != '\0'; i++) {
            printf("%c", msg[index++]);  // print character and move index
        }
        printf(" D %d\n", frameLength);       // print frame length as 
    }

    printf("\n");
    return 0;
}
 ##edited new ver

#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    int frameLength, index = 0;
    char framed[200] = "";  // to store framed message
    char temp[20];

    printf("Enter the message:\n");
    scanf("%s", msg);

    printf("Enter frame lengths one by one (program stops when message ends):\n");

    // Print original message first
    printf("%s\n", msg);

    while (msg[index] != '\0') {
        printf("Enter the current frame length: ");
        scanf("%d", &frameLength);

        int count = 0;
        while (count < frameLength && msg[index] != '\0') {
            strncat(framed, &msg[index], 1); // add character
            index++;
            count++;
        }

        // append frame length as number
        sprintf(temp, "%d", count);
        strcat(framed, temp);
    }

    // Print framed output
    printf(" s %s\n  d", framed);

    return 0;
}

