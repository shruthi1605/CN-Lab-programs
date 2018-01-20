#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
unsigned long p,q,e,d,n,z,i,m,c;
int len;
char data[100];
printf("enter the value of p & q such that p*q>255\n");
scanf("%lu%lu",&p,&q);
n=p*q;
z=(p-1)*(q-1);
for(i=1;i<z;i++)
{
if((z%i)==0)
continue;
else
break;
}
e=i;
printf("\nencryption key is=%lu",e);
for(i=1;i<z;i++)
if(((e*i-1)%z)==0)
break;
d=i;
printf("\ndecryption key is=%lu",d);
printf("\nenter the msg:");
scanf("%s",data);
len=strlen(data);

for(i=0;i<len;i++)
{
m=(unsigned long) data[i];
printf("The letter:%lu\t%c\n",m,m);
//c=modexp(m,e,n);
c=((unsigned long)pow(m,e)%n);
printf("\nencrypted key and its representation is %lu\n",c);
//m=modexp(c,d,n);
m=((unsigned long)pow(c,d)%n);
printf("\ndecrypted key and its representation is %lu\n",m);
}
printf("\n decrypted msg is %s\n",data);
}
