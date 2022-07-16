#include <stdio.h>
#include <conio.h>

int main()
{
    int ngay,thang,nam,tuoi;
    printf("\nNhap ngay sinh: ");
    scanf("%d",ngay);
    printf("\nNhap thang sinh: ");
    scanf("%d",thang);
    printf("\nNhap nam sinh: ");
    scanf("%d",nam);
    tuoi=2021-nam+1;
    printf("Toi sinh ngay: %d/%d/%d, nam nay toi %d tuoi",ngay,thang,nam,tuoi);
}