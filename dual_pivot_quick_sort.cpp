#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int arr[], int start, int end, int *lp, int *rp)
{
    if (arr[start] > arr[end])
    {
        swap(&arr[start], &arr[end]);
    }
    int i = start + 1;
    int j = end - 1;
    int k = start + 1;

    while (k <= j)
    {
        if (arr[k] < arr[start])
        {
            swap(&arr[k], &arr[i]);
            i++;
        }
        else
        {
            while (arr[j] > arr[end] && j > k)
            {
                j--;
            }
            swap(&arr[k], &arr[j]);
            j--;
            if (arr[k] < arr[start])
            {
                swap(&arr[k], &arr[i]);
                i++;
            }
        }
        k++;
    }
    *lp = --i;
    *rp = ++j;
    swap(&arr[start],&arr[*lp]);
    swap(&arr[end],&arr[*rp]);
}

void dual_pivot_quick_sort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int lp;
    int rp;
    partition(arr, start, end, &lp, &rp);
    dual_pivot_quick_sort(arr, start, lp - 1);
    dual_pivot_quick_sort(arr, lp + 1, rp - 1);
    dual_pivot_quick_sort(arr, rp + 1, end);
}

int main(void)
{
    int arr[] = {5, 1, 8, 6, 9, 4, 3, 10, 5};
    dual_pivot_quick_sort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        cout << arr[i] << " ";
    }
}