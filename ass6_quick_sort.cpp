#include <iostream>
using namespace std;

int partition(float arr[], int s, int e)
{
    float pivot = arr[s];

    // Count elements smaller than pivot
    int count = 0;
    for (int i = s + 1; i <= e; i++)  // Start from 's + 1'
    {
        if (arr[i] < pivot)
        {
            count++;
        }
    }
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        if (arr[i] > pivot && arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        if (arr[i] <= pivot)
        {
            i++;
        }
        if (arr[j] >= pivot)
        {
            j--;
        }
    }

    return pivotIndex;
}

void quick_sort(float arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    quick_sort(arr, s, p - 1);
    quick_sort(arr, p + 1, e);
}

int main()
{
    float percentages[] = {85.6, 90.3, 78.5, 92.4, 88.1};

    int n = sizeof(percentages) / sizeof(percentages[0]);

    quick_sort(percentages, 0, n - 1);

    cout << "Sorted percentages: ";
    for (int i = 0; i < n; i++)
    {
        cout << percentages[i] << " ";
    }
    return 0;
}
