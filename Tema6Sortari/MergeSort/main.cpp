#include <iostream>
#include <stdio.h>

using namespace std;

void interclasare(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = j = 0;
    k = left;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++; k++;
    }
    while(j < n2)
    {
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        interclasare(arr, left, mid, right);
    }


}



int main()
{
    int i, arrSize, arr[100];
    scanf("%d", &arrSize);
    for(i = 0; i < arrSize; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, arrSize - 1);
    for(i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);
    return 0;
}
