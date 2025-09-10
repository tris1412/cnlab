#include<stdio.h>
int onescompl(int num,int bits){
return (~num) & ((1<<bits)-1);
}
void main()
{
int n,bits;
int sum=0;
printf("enter no of values:");
scanf("%d",&n);
int data[n];
printf("enter your data:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&data[i]);
sum+=data[i];
}
printf("\n enter the no of bits to represent the dat");
scanf("%d",&bits);
int checksum=onescompl(sum,bits);
printf("the senders side data:\n");
for(int i=0;i<n;i++)
{
printf("%d",data[i]);
}
printf("the sum is %d\n",sum);
printf("the checksum is %d\n",checksum);
int recvsum=0;
for(int i=0;i<n;i++)recvsum+=data[i];
recvsum+=checksum;
int wrapped=(recvsum) & ((1<<bits)-1);
int final=onescompl(wrapped,bits);
printf("the receive side:\n");
for(int i=0;i<n;i++)printf("%d",data[i]);
printf("%d(checksum)\n",checksum);
printf("the sum of received+checksum:%d\n",recvsum);
printf("wrapped(%d)bits=%d\n",bits,wrapped);
printf("ones complement=%d",final);
printf(final?"error detected\n":"no error detected\n");
}
