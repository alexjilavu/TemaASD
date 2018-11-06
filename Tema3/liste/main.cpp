#include <iostream>
using namespace std;
struct nod{
    int inf;
    nod *urm;
}*prim, *ultim;

void pushFront(int val){
    nod *q = new nod;
    q->inf = val;
    if(prim != 0){
        q->urm = prim;
        prim = q;
    }
    else{
        prim = q;
        ultim = prim;
    }
}
void pushBack(int val){
    nod *q = new nod;
    q->inf = val;
    if(ultim != 0){
        ultim->urm = q;
        ultim = q;
        ultim->urm = 0;
    }
    else{
        prim = ultim = new nod;
        prim->inf = val;
        prim->urm = NULL;
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

int cautareValoare(int val){
    nod *q;
    int poz = 0;
    q = prim;
    while(q != 0){
        poz++;
        if(q->inf == val)
            return poz;
        q = q->urm;
    }
    return -1;
}

int cautarePozitie(int poz){
    nod *q;
    int curentPoz = 0;
    q = prim;
    while(q != 0){
        curentPoz++;
        if(curentPoz == poz)
            return q->inf;
        q = q->urm;
    }
    return -1;
}

void inserareDupaValoare(int cautat, int val){
    nod *q, *ins;
    q = prim;
    while(q->inf!=cautat && q!=0)
        q = q->urm;

    ins = new nod;
    ins->inf = val;

    ins->urm = q->urm;
    q->urm = ins;
    if(q == ultim)
        ultim = ins;
}
void inserareDupaPozitie(int poz, int val){
    nod *q, *ins;
    q = prim;
    int curentPoz = 0;
    while(q!=0 && curentPoz < (poz - 1)){
        curentPoz++;
        q = q->urm;
    }
    if(q == prim){
        pushFront(val);
        return ;
    }

    ins = new nod;
    ins->inf = val;

    ins->urm = q->urm;
    q->urm = ins;

    if(q == ultim)
        ultim = ins;
}

/*void stergeValoare(int val){
    nod *q, *p;
    q = prim;
    if(prim->inf == val)
    {
        p = prim;
        prim = prim->urm;
        delete p;
    }
    else
    {
        while(q!=0 && (q->urm->inf!=val))
            q = q->urm;
        if(q == 0)
            return ;
        p = q->urm;
        q->urm = p->urm;
        if(p == ultim)
            ultim = q;
        delete p;
    }
}
*/
void stergeValoare(int x){
    nod *p = prim;
    nod *last = NULL;
    while(p!=NULL && p->inf != x){
        last = p;
        p = p->urm;
    }
    if(p == NULL)
        return ;
    if(p == prim){
        prim = prim->urm;
        //delete p;
        if(prim == ultim)
            ultim = NULL;
        delete p;
    }
    else
        if(p == ultim){
            last->urm = NULL;
            ultim = last;
            delete p;
        }
        else{
            last->urm = p->urm;
            delete p;
        }
}

void stergePozitie(int poz){
    nod *q, *p;
    int curentPoz = 0;
    q = prim;

    if(poz == 1)
    {
        p = prim;
        prim = prim->urm;
        delete p;
    }
    else
    {
        nod *pred = NULL;
        while(q!=0 && curentPoz < (poz - 1))
        {
            curentPoz++;
            pred = q;
            q = q->urm;
        }
        if(q == NULL)
            return ;
        if(q == ultim){
            pred->urm = NULL;
            ultim = pred;
            delete q;
        }
        else{
            pred->urm = q->urm;
            delete q;
        }
}}
int main()
{
    /*afis();
    pushFront(1);
    pushFront(2);
    pushFront(3);
    afis();
    pushBack(4);
    afis();
    cout << cautareValoare(5) <<'\n';
    cout << cautareValoare(1) <<'\n';
    cout << cautarePozitie(5) <<'\n';
    cout << cautarePozitie(3) <<'\n';
    stergePozitie(1);
    afis();
    stergePozitie(1);
    afis();
    stergeValoare(4);
    afis();
    pushBack(5);
    afis();
    stergeValoare(1);
    stergePozitie(1);
    afis();
    pushFront(8);
    afis();
    */
    pushBack(1);
    pushBack(2);
    pushBack(3);
    pushBack(2);
    afis();
    stergePozitie(4);
    afis();
    return 0;
}
