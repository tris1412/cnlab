#include <stdio.h>
#include <string.h>

char a[50];    
char b[200];   
char flag[] = "01111110";

int main() {
    printf("Enter the message (bit string):\n");
    scanf("%s", a);   
    
    strcpy(b, flag);  
    int count = 0, j = strlen(flag);

    for (int i = 0; i < strlen(a); i++) {
        b[j++] = a[i];
        
        if (a[i] == '1') {
            count++;
            if (count == 5) {
                b[j++] = '0'; 
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    strcat(b, flag);  
    
    printf("Stuffed frame: %s\n", b);
    return 0;
}
