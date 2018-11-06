#include <iostream>
using namespace std;
struct nod
{
    int inf;
    nod *urm;
}*firstPrim, *firstUltim, *secondPrim, *secondUltim;

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
void afis(nod *firstPrim){
    nod *q;
    q = firstPrim;
    while(q != 0){
        cout << q->inf << " ";
        q = q->urm;
    }
    cout << '\n';
}

void interclasare()
{
    nod *q, *last = NULL, *aux;
    q = secondPrim;
    while(q != 0)
    {
        if(firstPrim == 0)
            return;
        if(((q->inf) > (firstPrim->inf)) && (q == secondPrim))
        {
            aux = firstPrim;
            firstPrim->urm = q;
            secondPrim = firstPrim;
            firstPrim = aux->urm;

        }
        if((q->inf) >= (firstPrim->inf))
        {
            aux = firstPrim;
            firstPrim = firstPrim->urm;
            last->urm = aux;
            aux->urm = q;
            last = aux;
        }
        else
        {
            last = q;
            q = q->urm;
        }

    }
    if(firstPrim != 0)
        while(firstPrim)
        {
            aux = firstPrim;
            firstPrim = firstPrim->urm;
            secondUltim->urm = aux;
            secondUltim = aux;
        }

}
int main()
{
    // * Consideram cazul in care lista 2 are mai multe elemente ca lista 1
    pushBackFirst(4);
    pushBackFirst(6);
    pushBackFirst(8);
    pushBackSecond(1);
    pushBackSecond(2);
    pushBackSecond(5);
    pushBackSecond(9);
    pushBackSecond(9);
    afis(firstPrim);
    afis(secondPrim);
    interclasare();
    afis(secondPrim);
    //cout << '\n';
    //afis(firstPrim);
    //afis(secondPrim);

}
