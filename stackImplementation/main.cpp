#include <iostream>

using namespace std;

struct nod
{
    int inf;
    nod *urm;
} *stackTop;

void push(int value)
{
    nod *ins = new nod;
    ins->inf = value;
    if(stackTop != 0)
    {
        ins->urm = stackTop;
        stackTop = ins;
    }
    else
    {
        stackTop = ins;
        stackTop->urm = NULL;
    }
}

int pop()
{
    int value;
    if(stackTop != 0)
    {
        nod *q = stackTop;
        stackTop = stackTop->urm;
        value = q->inf;
        delete q;
        return value;
    }
    else
        return -1;

}

void write()
{
    nod *q;
    q = stackTop;
    if(q == 0)
    {
        cout << "stiva vida \n";
        return ;
    }
    cout << "varf ";
    while(q)
    {
        cout << q->inf << " ";
        q = q->urm;
    }
    cout << "baza \n";
}

int peek()
{
    if(stackTop != 0)
        return stackTop->inf;
    return -1;
}

bool empty()
{
    if(stackTop != 0)
        return false;
    return true;
}

int search(int value)
{
    int distance = 0;
    nod *q = stackTop;
    while(q)
    {
        if(q->inf == value)
            return distance;
        q = q->urm;
        distance++;
    }
    return -1;
}

int main()
{
    write();
    push(1);
    push(2);
    push(3);
    write();
    cout << search(2) << '\n' << search(4) << '\n';
    cout << empty() << '\n';
    cout << pop() << '\n';
    write();
    cout << peek() << '\n';
    write();
    pop();
    pop();
    write();
    cout << pop() << '\n';
    cout << empty();

}
