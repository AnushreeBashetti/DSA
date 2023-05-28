#include <stdio.h>
#define n 100
int sym(int a[n][n], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (a[i][j] != a[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    int a[n][n];
    int size, i, j;
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    if (sym(a, size))
    {
        printf("Symmetric\n");
    } else {
        printf("not symmetric\n");
    }
    return 0;
}
