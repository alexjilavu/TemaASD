#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("date.in");

struct nod
{
    int inf;
    nod *urm;
} *firstPrim, *secondPrim, *firstUltim, *secondUltim, *resultPrim, *resultUltim;

void pushBackFirst(int val);
void pushBackSecond(int val);
void pushBackResult(int val);

void citirePr7()
{
    int nrCifFirst, nrCifSecond, x;
    fin >> nrCifFirst;
    for(int i = 1; i <= nrCifFirst; i++)
    {
        fin >> x;
        pushBackFirst(x);
    }
    fin >> nrCifSecond;
    for(int i = 1; i <= nrCifSecond; i++)
    {
        fin >> x;
        pushBackSecond(x);
    }
    for(int i = 1; i <= nrCifFirst + nrCifSecond; i++)
        pushBackResult(0);
}

void inmultireCifRez(nod *&firstPrim, nod *&resultPrim, int inm)
{
    nod *first = firstPrim;
    nod *rez = resultPrim;
    int carry = 0, add = 0;
    while(first)
    {
        add = (first->inf) * inm + carry;
        carry = add / 10;
        add = add % 10;
        rez->inf += add;
        rez->urm->inf += (rez->inf) / 10;
        rez->inf = rez->inf % 10;
        first = first->urm;
        rez = rez->urm;
    }
    if(carry)
        rez->inf = carry;
    }

void inmultireInt()
{
    nod *first = firstPrim, *second = secondPrim;
    while(second)
    {
        inmultireCifRez(firstPrim, resultPrim, (second->inf));
        resultPrim = resultPrim->urm;
        second = second->urm;
    }

}

void afis(nod *firstPrim){
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
    citirePr7();
    nod *rezStart = resultPrim;
    inmultireInt();
    afis(rezStart);

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
void pushBackSecond(int val)
{
    nod *q = new nod;
    q->inf = val;
    if(secondUltim != 0)
    {
        secondUltim->urm = q;
        secondUltim = q;
        secondUltim->urm = 0;
    }
    else
    {
        secondPrim = secondUltim = new nod;
        secondPrim->inf = val;
        secondPrim->urm = 0;
    }
}
