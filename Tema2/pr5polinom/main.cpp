#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
void firstTask(){
    int gradMaxim, coef[100], val;
    int sum = 0;
    fin >> gradMaxim;
    for(int i = 0; i<=gradMaxim; i++)
        fin >> coef[i];
    fin >> val;
    for(int i = 0; i<=gradMaxim; i++){
        fout << coef[i]*pow(val, i);
        sum += coef[i]*pow(val, i);
        if(i < gradMaxim)
            fout << " + ";
    }
    fout << " = " << sum;
    }
void secondTask(){
    int gradFirst, gradSecond , rez[100];
    int firstCoef[100], secondCoef[100];
    fin >> gradFirst;
    memset(firstCoef, 0, sizeof(firstCoef));
    memset(secondCoef, 0, sizeof(secondCoef));
    memset(rez, 0, sizeof(rez));
    for(int i = 0; i<=gradFirst; i++)
        fin >> firstCoef[i];
    fin >> gradSecond;
    for(int i = 0; i<=gradSecond; i++)
        fin >> secondCoef[i];
    int gradRez = max(gradFirst, gradSecond);
    for(int i = 0; i<=gradRez; i++)
        rez[i] = firstCoef[i] + secondCoef[i];
    for(int i = 0; i<=gradRez; i++)
        fout << rez[i] << " ";
}

void thirdTask(){
    int gradFirst, gradSecond , rez[100];
    int firstCoef[100], secondCoef[100];
    fin >> gradFirst;
    memset(firstCoef, 0, sizeof(firstCoef));
    memset(secondCoef, 0, sizeof(secondCoef));
    memset(rez, 0, sizeof(rez));
    for(int i = 0; i<=gradFirst; i++)
        fin >> firstCoef[i];
    fin >> gradSecond;
    for(int i = 0; i<=gradSecond; i++)
        fin >> secondCoef[i];
    int gradRez = gradFirst + gradSecond;
    for(int i = 0; i<=gradFirst; i++)
        for(int j = 0; j<=gradSecond; j++)
            rez[i + j] = rez[i + j] + firstCoef[i]*secondCoef[j];

    for(int i = 0; i<=gradRez; i++)
        fout << rez[i] << " ";
}

int main()
{
    //firstTask();
    //secondTask();
    thirdTask();
}
