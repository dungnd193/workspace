#include <stdio.h>

// long Y(int n);
// long X(int n)
// {
//     if (n <= 4)
//         return n;
//     else
//         return Y(n - 1) + X(n - 2) + Y(n - 3) + X(n - 4);
// }
// long Y(int n)
// {
//     if (n <= 4)
//         return 2 * n;
//     else
//         return X(n - 1) + Y(n - 2) + X(n - 3) + Y(n - 4);
// }

//Khong de quy
long Tong(int n)
{
    int x1=1, x2=2, x3=3, x4=4, x5;
    int y1=2, y2=4, y3=6, y4=8, y5;
    int tong = 30;
    if(n<5) return 3*n;
    else {
        
        for (int i = 5; i <= n; i++) 
        {
            x5=y4+x3+y2+x1;
            y5=x4+y3+x2+y1;
            tong=tong+x5+y5;
            x1=x2;x2=x3;x3=x4;x4=x5;
            y1=y2;y2=y3;y3=y4;y4=y5;
        }
    }
    return tong;
    
}

int main()
{
    int n;
    printf("\nNhap n: ");
    scanf("%d", &n);
    // printf("\n X = %ld", X(n));
    // printf("\n Y = %ld", Y(n));
    printf("\n Tong = : %d",tong);
}


