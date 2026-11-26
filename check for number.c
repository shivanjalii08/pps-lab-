#include<stdio.h>
int main()
{
int n1;
printf("Enter a year: ");
scanf("%d", &n1);
if (n1>0)
{
printf("It is a positive number.\n");
}
else 
if (n1==0)
{
printf("It is a zero.\n");
}
else
printf("It is a negative number.\n");
return 0;
}
