#include <stdio.h>

int swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    int a,b;
    printf("\nMoi ban nhap so thu nhat : ");
    scanf("%d",&a);
    printf("\nMoi ban nhap so thu hai : ");
    scanf("%d",&b);
    swap(a,b);
    printf("\nSo thu nhat la : %d",a);
    printf("\nSo thu hai la : %d",b);