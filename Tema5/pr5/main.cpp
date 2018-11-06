#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("date.in");

struct nod
{
    int inf;
    nod *urm;
} *firstPrim, *secondPrim, *firstUltim, *secondUltim, *resultPrim, *resultUltim;
int inm;

void pushBackFirst(int val);
void pushBackSecond(int val);
void pushBackResult(int val);
void citirePr5()
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
void adunare()
{
    nod *first = firstPrim, *second = secondPrim;
    int carry = 0, add = 0;
    while(first != NULL)
    {
        add = (first->inf) + (second->inf) + carry;
        if(add > 9)
        {
            carry = 1;
            add = add - 10;
        }
        else
            carry = 0;
        pushBackResult(add);
        first = first->urm;
        if(second->urm)
            second = second->urm;
        else
            second->inf = 0;
    }
    if(carry)
        pushBackResult(carry);
}

int main()
{
    citirePr5();
    adunare();
    afis(resultPrim);

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
