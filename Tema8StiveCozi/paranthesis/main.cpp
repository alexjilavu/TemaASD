#include <iostream>

using namespace std;

int main()
{
    int i, stackCount = 0;
    char curent;
    cin >> curent;
    while(curent != '0')
    {
        if(curent == '(')
            stackCount++;
        if(curent == ')' && stackCount > 0)
            stackCount--;
        cin >> curent;
    }
    if(stackCount != 0)
        cout << "incorect";
    else
        cout << "corect";
}
