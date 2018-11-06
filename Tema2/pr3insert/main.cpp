#include <iostream>
using namespace std;
int arr[100], lenght, t, k, ins[100];
void insertElem(int i, int t){
    for(int j = lenght-1; j>=i; j--)
        arr[j+1] = arr[j];
    arr[i] = t;
    lenght++;
}
void insertArr(int i, int t, int ins[100]){
    for(int j = lenght - 1; j>=i; j--)
        arr[j+t] = arr[j];
    lenght = lenght + t;
    int index = 0;
    for(int j = i; j<i+t; j++)
        arr[j] = ins[index++];
}

void firstTask(){
    cin >> lenght;
    for(int i = 0; i<lenght; i++)
        cin >> arr[i];
    cin >> t;
    cin >> k;
    for(int i = 0; i<lenght; i++)
        if(arr[i] == k){
            insertElem(i + 1, t);
            break;
        }
    cout << '\n';
    cout << "Noul vector este: ";
    for(int i = 0; i<lenght; i++)
        cout << arr[i] << " ";
}
void secondTask(){
    cin >> lenght;
    for(int i = 0; i<lenght; i++)
        cin >> arr[i];
    cin >> t;
    for(int i = 0; i<t; i++)
        cin >> ins[i];
    cin >> k;
    for(int i = 0; i<lenght; i++)
        if(arr[i] == k){
            insertArr(i + 1, t, ins);
            break;}
    cout << '\n';
    cout << "Noul vector este: ";
    for(int i = 0; i<lenght; i++)
        cout << arr[i] << " ";

}
int main()
{
    //firstTask();
    secondTask();
}
