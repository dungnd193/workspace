#include <stdio.h>


int main()
{
    int n,a,b,c,d;
    printf("\nNhap so nguyen duong n(co 4 chu so) : ");
    scanf("%d",&n);
    a=n/1000;  
    b=(n%1000)/100; 
    c=(n%100)/10; 
    d=(n%10);
    printf("\nTong cac chu so la : %d",a+b+c+d);
}