#include <iostream>
using namespace std;
struct nod{
    float inf;
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

void rezolvare(){
    nod *q, *ins;
    q = prim;
    float medie = 0;
    while(q->urm != 0){
        ins = new nod;
        medie = (q->inf + q->urm->inf)/2;
        ins->inf = medie;
        ins->urm = q->urm;
        q->urm = ins;
        q = ins->urm;
    }
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
    rezolvare();
    afis();
    return 0;
}
