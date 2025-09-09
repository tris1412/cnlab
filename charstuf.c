#include<stdio.h>
#include<string.h>

void main()
{
char a[100];char b[100];
int i,j=0;
printf("enter a string:");
scanf("%s",a);
strcpy(b,"dlestx");
j=strlen(b);
for(i=0;a[i]!='\0';i++)
{
if(strncmp(&a[i],"dle",3)==0)
{
strcat(b+j,"dle");
j+=3;
}
b[j++]=a[i];
}
strcat(b+j,"dleetx");
printf("stuffed frame:%s",b);
}

