#include <iostream>
using namespace std;
int n, arr[100], k;
int secvential(){
    for(int i = 0; i<n; i++)
        if(arr[i] == k)
            return i;
    return -1;
}
int binary(int st, int dr){
    int mid = (st + dr)/2;
    if(st>dr)
        return -1;
    if(arr[mid] == k)
        return mid;
    if(arr[mid] > k)
        return binary(st, mid-1);
    return binary(mid + 1, dr);
}
int main()
{
    cin >> n >> k;
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    //cout << secvential();
    cout << binary(0, n-1);
}
