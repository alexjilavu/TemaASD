#include <iostream>
using namespace std;
int lenght, arr[100], number;
void sterg(int i){
    for(int j = i; j<lenght-1; j++)
        arr[j] = arr[j+1];
    lenght--;
}
void afis(int it){
    cout << "Dupa " << it << " stergeri vectorul este : ";
    for(int i = 0; i<lenght; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

int main()
{
    int it = 0;
    cin >> lenght;
    for(int i = 0; i<lenght; i++)
        cin >> arr[i];
    cin >> number;
    for(int i = 0; i<lenght; i++)
        if(arr[i] == number){
            sterg(i);
            i--;
            it++;
            afis(it);
        }
    cout << '\n' << "La sfarsit vectorul este: ";
    for(int i = 0; i<lenght; i++)
        cout << arr[i] << " ";

}
