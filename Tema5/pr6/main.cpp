#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("date.in");

struct nod
{
    int inf;
    nod *urm;
} *firstPrim, *firstUltim, *resultPrim, *resultUltim;

int inm;

void pushBackFirst(int val){
    nod *q = new nod;
    q->inf = val;
    if(firstUltim != 0)
    {
        firstUltim->urm = q;
        firstUltim = q;
        firstUltim->urm = 0;
    }
    else
    {
        firstPrim = firstUltim = new nod;
        firstPrim->inf = val;
        firstPrim->urm = NULL;
    }
}
void pushBackResult(int val){
    nod *q = new nod;
    q->inf = val;
    if(resultUltim != 0)
    {
        resultUltim->urm = q;
        resultUltim = q;
        resultUltim->urm = 0;
    }
    else
    {
        resultPrim = resultUltim = new nod;
        resultPrim->inf = val;
        resultPrim->urm = NULL;
    }
}

void citirePr6()
{
    int nrCif, x;
    fin >> nrCif;
    for(int i = 1; i <= nrCif; i++)
    {
        fin >> x;
        pushBackFirst(x);
    }
    fin >> inm;
}

void inmultireCif(nod *&firstPrim, int inm)
{
    nod *first = firstPrim;
    int carry = 0, add = 0;
    while(first != NULL)
    {
        add = (first->inf) * inm + carry;
        carry = add / 10;
        add = add % 10;
        pushBackResult(add);
        first = first->urm;
    }
    if(carry)
        pushBackResult(carry);
}

void afis(nod *firstPrim)
{
    nod *q;
    q = firstPrim;
    while(q != 0){
        cout << q->inf << " ";
        q = q->urm;
    }
    cout << '\n';
}
int main()
{
    citirePr6();
    inmultireCif(firstPrim, inm);
    afis(resultPrim);
}
