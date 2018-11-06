#include <iostream>
using namespace std;
struct nod{
    int inf;
    nod *urm;
}*prim, *ultim;

void insertSort(int val){
    nod *q, *ins;
    q = prim;
    if(prim == 0)
    {
        prim = ultim = new nod;
        prim->inf = val;
        prim->urm = NULL;
        return ;
    }
    ins = new nod;
    ins->inf = val;
    if(val < prim->inf)
    {
        ins->urm = prim;
        prim = ins;
    }
    else
        while(q->urm)
            if((val >= (q->inf)) && (val <= (q->urm->inf)))
               {
                   ins->urm = q->urm;
                   q->urm = ins;
                   return ;
               }
            else
                q = q->urm;
    if(ultim->inf < val)
    {
        ultim->urm = ins;
        ultim = ins;
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
    insertSort(4);
    insertSort(2);
    insertSort(5);
    insertSort(4);
    insertSort(4);
    insertSort(1);
    afis();
    return 0;
}
