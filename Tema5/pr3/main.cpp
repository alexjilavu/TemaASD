#include <iostream>
using namespace std;
struct nod
{
    int inf;
    nod *urm;
}*prim, *ultim;

void pushBack(int val){
    nod *q = new nod;
    q->inf = val;
    if(ultim != 0)
    {
        ultim->urm = q;
        ultim = q;
        ultim->urm = 0;
    }
    else
    {
        prim = ultim = new nod;
        prim->inf = val;
        prim->urm = NULL;
    }
}

void revert(){
    nod *curent, *previous = 0, *next = 0;
    curent = prim;
    while(curent)
    {
        next = curent->urm;
        curent->urm = previous;
        previous = curent;
        curent = next;
    }
    prim = previous;
}
void afis(){
    nod *q;
    q = prim;
    while(q != 0){
        cout << q->inf << " ";
        q = q->urm;
    }
    cout << '\n';
}


int main()
{
    pushBack(1);
    pushBack(2);
    pushBack(3);
    pushBack(4);
    revert();
    afis();
    return 0;
}
