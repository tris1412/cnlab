#include <stdio.h>
#include <string.h>

char xorBit(char a, char b){ return (a==b)?'0':'1'; }

int main(){
    char msg[50], key[20];
    printf("Enter Dataword: "); scanf("%s", msg);
    printf("Enter Key: "); scanf("%s", key);

    int dLen=strlen(msg), kLen=strlen(key);
    for(int i=0;i<kLen-1;i++) msg[dLen+i]='0';
    msg[dLen+kLen-1]='\0';

    char rem[50];
    strcpy(rem, msg);

    for(int i=0;i<=dLen-1;i++)
        if(rem[i]=='1')
            for(int j=0;j<kLen;j++)
                rem[i+j]=xorBit(rem[i+j], key[j]);

    printf("\nCRC Remainder: ");
    for(int i=dLen;i<dLen+kLen-1;i++) printf("%c", rem[i]);

    // Append CRC to original message
    for(int i=0;i<kLen-1;i++) msg[dLen+i]=rem[dLen+i];
    msg[dLen+kLen-1]='\0';

    printf("\nTransmitted Codeword: %s\n", msg);

    // Receiver check
    strcpy(rem, msg);
    for(int i=0;i<=dLen-1;i++)
        if(rem[i]=='1')
            for(int j=0;j<kLen;j++)
                rem[i+j]=xorBit(rem[i+j], key[j]);

    int error=0;
    for(int i=dLen;i<dLen+kLen-1;i++) if(rem[i]!='0'){error=1; break;}
    if(error) printf("Error detected.\n");
    else printf("No error detected.\n");

    return 0;
}
