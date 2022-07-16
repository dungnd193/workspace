#include <stdio.h>


int main()
{
    int n,a,b;
    printf("\nNhap so nguyen duong n(co 2 chu so) : ");
    scanf("%d",&n);
    a=n/10;
    b=n%10;
    printf("\n- So dao nguoc cua so ban dau la : %d%d",b,a);
}