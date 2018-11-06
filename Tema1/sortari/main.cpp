#include <iostream>
using namespace std;
int n, arr[100];
void afis(int lenght){
    for(int i = 0; i<lenght; i++)
        cout << arr[i] << " ";
    cout<<'\n';
}
void bubblesort(int arr[], int n){

    int sortat = 0;
    int i;
    int p = 0 , it = 0;
    int lenght = n;
    while(!sortat){
        sortat = 1;
        for(i=0; i<n-1; i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                sortat = 0;
                p = i + 1;
            }
        it++;
        cout << "Dupa " << it << " comparatii vectorul arata asa: ";
        afis(lenght);
        }
        n = p;

    }
    cout <<'\n' << "La sfarsit vectorul este: ";
    for(int i = 0; i<lenght; i++)
        cout << arr[i] <<" ";
}

void insertsort(int arr[], int n){
    int j, current, it;
    for(int i=1;i<n;i++){
        current = arr[i];
        j = i-1;
        while(j >= 0 && arr[j]>current){
            arr[j+1] = arr[j];
            j--;
            it++;
            cout << "Dupa " << it << " comparatii vectorul arata asa: ";
            afis(n);
        }
        arr[j+1] = current;
    }
    cout <<'\n' << "La sfarsit vectorul este: ";
    afis(n);
}
void selectionsort(int arr[], int n){
    int Min, it = 0;
    for(int i = 0; i<n-1; i++){
        Min = i;
        for(int j = i+1; j<n; j++)
            if(arr[Min] > arr[j])
                swap(arr[Min], arr[j]);
        it++;
        cout << "Dupa " << it << " comparatii vectorul arata asa: ";
        afis(n);
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    //bubblesort(arr, n);
    //insertsort(arr, n);
    selectionsort(arr, n);
}
