#include <stdio.h>
int main()
{
    int a[8][2][6];
    int y = 0;
    int* a1 = &y;
    int** a2 = &a1;
    int*** a3 = &a2;

    // printf("%d %d %d %d\n", sizeof(a), sizeof(a1), sizeof(a2), sizeof(a3));
    printf("%d , New: %d, Size of (int*)(&a2): %d\n", (int*)(&a2), ((int*)(&a2 + 1)) , sizeof((int*)(&a2)));
    //printf("%d ", (char*)(&a2 + 1) - (char*)&a2);
    return 0;
}