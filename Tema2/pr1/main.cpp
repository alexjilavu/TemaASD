#include <iostream>
using namespace std;
int main()
{
    int lenght, number, Min = 999999, Max = -999999;
    cin >> lenght;
    for(int i = 0; i<lenght; i++){
        cin >> number;
        if(number > Max)
            Max = number;
        if(number < Min)
            Min = number;
    }
    cout << Min << " " << Max;

}
