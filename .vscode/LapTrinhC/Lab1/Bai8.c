#include <stdio.h>


int main()
{
    int n;
    printf("\nNhap so nguyen duong n(co 3 chu so) : ");
    scanf("%d",&n);
    printf("\n- Chu so hang tram: %d",n/100);
    n=n%100;
    printf("\n- Chu so hang truc: %d",n/10);
    printf("\n- Chu so hang don vi: %d",n%10);
}