#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int partition_rand(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}

void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition_rand(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[100], sizeOfArr;
    cin >> sizeOfArr;
    for(int i = 0; i < sizeOfArr; i++)
        cin >> arr[i];
    quicksort(arr, 0, sizeOfArr - 1);
    for(int i = 0; i < sizeOfArr; i++)
        cout << arr[i] << " ";
    return 0;
}
