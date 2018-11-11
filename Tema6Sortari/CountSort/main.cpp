#include <iostream>
#include <string.h>
using namespace std;
void countSort(char arr[])
{
    int length = strlen(arr);
    char output[length];
    int count[256];
    memset(count, 0, sizeof(count));

    for(int i = 0; i < length; i++)
        count[arr[i]]++;
    for(int i = 1; i <= 256; i++)
        count[i] += count[i - 1];
    for(int i = 0; i < length; i++)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for(int i = 0; i < length; i++)
        arr[i] = output[i];
}

int main()
{
    char arr[] = "421521342132415214";
    countSort(arr);
    cout << arr;
    return 0;

}
