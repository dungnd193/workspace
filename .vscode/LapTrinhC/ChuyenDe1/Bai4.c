#include <stdio.h>
#include <conio.h>

int main()
{
    int ngay,thang,nam;
    printf("\nNhap ngay: ");
    scanf("%d",ngay);
    printf("\nNhap thang: ");
    scanf("%d",thang);
    printf("\nNhap nam: ");
    scanf("%d",nam);
    printf("\nNgay thang vua nhap la: %d/%d/%d", ngay,thang,nam);
}