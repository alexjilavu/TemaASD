#include <iostream>

using namespace std;

int findSingle(int arr[], int lenght)
    {
        int res = arr[0];
        for (int i = 1; i<lenght; i++)
            res = res ^ arr[i];
        return res;
    }
int main()
{
    int lenght, arr[100];
    cin >> lenght;
    for(int i = 0; i<lenght; i++)
        cin >> arr[i];
    cout << findSingle(arr, lenght);
}
