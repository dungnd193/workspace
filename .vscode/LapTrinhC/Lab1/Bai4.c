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
    dtb = (toan*3+ly*2+hoa)/6;
    printf("\nTong diem : %f",toan*3+ly*2+hoa);
    printf("\nDiem Trung Binh : %.2f",dtb);

}