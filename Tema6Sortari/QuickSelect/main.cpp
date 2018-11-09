#include <iostream>
using namespace std;
int partition(int arr[], int left, int right)
{
    int x = arr[right];
    int i = left;
    for(int j = left; j <= right - 1; j++)
        if(arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    swap(arr[i], arr[right]);
    return i;
}
int kthSmallest(int arr[], int left, int right, int k)
{
    if(k > 0 && k <= right - left + 1)
    {
        int index = partition(arr, left, right);
        if(index - left == k - 1)
            return arr[index];
        if(index - left > k - 1)
            return kthSmallest(arr, left, index - 1, k);
        return kthSmallest(arr, index + 1, right, k - index + left - 1);
    }
    return -1;
}


int main()
{
    int arr[]= {4, 8, 12, 3, 1, 17};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;
    cout << kthSmallest(arr, 0, n - 1, k);

}
