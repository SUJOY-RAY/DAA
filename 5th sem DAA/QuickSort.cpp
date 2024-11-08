#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int arr[]={7,6,5,4,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr,0,n-1);
    for (auto i : arr)
    {
        cout<<i;
    }
    
    return 0;
}