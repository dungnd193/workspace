#include <stdio.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    printf("CHUONG TRINH TINH DIEN TICH, THE TICH HINH CAU");
    printf("\n************************************************");

    float r;
    printf("\nMoi ban nhap ban kinh R : ");
    scanf("%f",&r);
    printf("\nDien tich hinh cau la: %f",4*PI*r*r);
    printf("\nThe tich hinh cau la: %f",(4/3)*PI*r*r*r);
}