#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[100];
    char start[] = "dlestx";   
    char end[]   = "dleetx";   
    int n = 0, m = 0;

    printf("Enter a string:\n");
    scanf("%s", a);   

    
    strcpy(b, start);
    m = strlen(start);

    
    while (a[n] != '\0') {
        if (a[n] == 'd' && a[n+1] == 'l' && a[n+2] == 'e') {
            
            b[m++] = 'd';
            b[m++] = 'l';
            b[m++] = 'e';
            b[m++] = 'd';
            b[m++] = 'l';
            b[m++] = 'e';
            n += 3;  
        } else {
            b[m++] = a[n++];
        }
    }

    
    strcpy(&b[m], end);
    m += strlen(end);

    
    b[m] = '\0';

    printf("Stuffed Frame: %s\n", b);
    return 0;
}
