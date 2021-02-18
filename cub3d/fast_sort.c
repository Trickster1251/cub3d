#include <stdio.h>

//   int y = 250;
//     int z = 100;

//     int *a = &y;
//     int *b = &z;

void    swap(int *a, int *b)
{
    int     *tmp;

    *tmp = *a;
    *a = *b;
    *b = *tmp;
}

int main()
{
    int arr[10] = {1, 2, 44, 5, 12, 5, 6, 7, 100};
    int i = -1;
    int len_array = 0;

    while(arr[++i])
        len_array++;

    int srav = arr[len_array / 2];
    i  = -1;

    int *left = arr[0];
    int *right = arr[len_array];
    while(arr[++i])
    {
        if (*left > arr[i + 1] && *left < srav)
        {
            swap(left, arr[i + 1]);
            
        }
        printf("%d\n", arr[i]);
    }

}