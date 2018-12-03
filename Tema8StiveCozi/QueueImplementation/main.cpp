#include <iostream>

using namespace std;

struct nod
{
    int inf;
    nod *urm;
}*stanga, *dreapta;

void push(int value)
{
    nod *ins = new nod;
    ins->inf = value;
    if(dreapta != 0)
    {
        dreapta->urm = ins;
        dreapta = ins;
        dreapta->urm = 0;
    }
    else
    {
        stanga = dreapta = new nod;
        stanga->inf = value;
        stanga->urm = 0;
    }
}

int pop()
{
    if(stanga == NULL)
        return -1;
    nod *q = stanga;
    int del = q->inf;
    stanga = stanga->urm;
    delete q;
    return del;
}

int peek()
{
    return stanga->inf;
}

bool empty()
{
    if(stanga == NULL)
        return true;
    return false;
}
int search(int value)
{
    nod *q;
    int count = 0;
    q = stanga;
    while(q != NULL)
    {
        count++;
        if(q->inf == value)
            return count;
        q = q->urm;
    }
    if(q == NULL)
        return -1;
}

void write()
{
    if (stanga == NULL)
    {
        cout << "coada vida \n";
        return;
    }
    nod *q = stanga;
    cout << "out ";
    while(q)
    {
        cout << q->inf <<  " ";
        q = q->urm;
    }
    cout << "in \n";
}

int main()
{
    write();
    push(1);
    push(2);
    push(3);
    write();
    cout << search(2) << '\n';
    cout << search(4) << '\n';
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

