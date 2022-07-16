#include <stdio.h>

int main()
{
    float toan,ly,hoa,dtb;
    printf("\nNhap diem Toan : ");
    scanf("%f",&toan);
    printf("\nNhap diem Ly : ");
    scanf("%f",&ly);
    printf("\nNhap diem Hoa : ");
    scanf("%f",&hoa);
    dtb = (toan+ly+hoa)/3;
    printf("\nTong diem : %f",toan+ly+hoa);
    printf("\nDiem Trung Binh : %.2f",dtb);

}