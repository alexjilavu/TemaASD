#include <iostream>
using namespace std;

void push(int stack[100], int &stackSize, int value)
{
    stack[++stackSize] = value;
}

void pop(int stack[100], int &stackSize)
{
    if(stackSize != 0)
        stackSize--;
}

int main()
{
    int stack[100], stackSize = 0;
    int n, number;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> number;
        if(stackSize == 0 || stack[stackSize] != number)
            push(stack, stackSize, number);
        else
            if(stackSize != 0)
                pop(stack, stackSize);
    }
    if(stackSize == 0)
        cout << "corect";
    else
        cout << "incorect";
}
