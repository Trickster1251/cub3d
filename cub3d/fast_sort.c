#include <stdio.h>
# define len(arr) (int)(sizeof(arr) / sizeof(arr[0]))

void    swap(int *a, int *b)
{
    int     *tmp;

    *tmp = *a;
    *a = *b;
    *b = *tmp;
}

int     part(int *arr, int l, int r)
{
    int i = -1;
    int len = ((int)(sizeof(arr) / sizeof(arr[0])));
    int x = arr[r];
    int less = l;
     while(arr[++i])
    {
        if (arr[i] <= x)
        {
        swap(&arr[i], &arr[less]);
        ++less;
        }
    }
        swap(&arr[less], &arr[r]);
    return less;
}

void q_sort(int *arr, int l, int r)
{
    if (l < r)
    {
        int q = part(arr, l, r);
        q_sort(arr, l, q - 1);
        q_sort(arr, q + 1, r);
    }
}

void q_sort_eval(int *arr)
{
    q_sort(arr, 0, (int)(sizeof(arr) / sizeof(arr[0]) - 1));
}

int main()
{
    int arr[] = {1, 2, 44, 5, 12, 5, 6, 7, 100, 12};

    int i  = -1;

    q_sort_eval(&arr);

    while(arr[++i])
    {
        printf("%d\n", arr[i]);
    }

    // int *left = arr[0];
    // int *right = arr[len_array];
    // while(arr[++i])
    // {
    //     if (*left > arr[i + 1] && *left < srav)
    //     {
    //         swap(left, arr[i + 1]);
            
    //     }
    //     printf("%d\n", arr[i]);
    // }

}