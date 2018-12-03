#include <iostream>
using namespace std;
int a[100][100], n;
const short int dirLine[4] = {-1, 1, 0, 0};
const short int dirColumn[4] = {0, 0, -1, 1};

void read()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
}

void Fill(int x, int y, int nr)
{
    if(a[x][y] == 1 && x >= 0 && x < n && y >=0 && y <n)
    {
        a[x][y] = nr;
        for(int h = 0; h < 4; h++)
            Fill(x + dirLine[h], y + dirColumn[h], nr);
    }
}

int main()
{
    read();
    int nr = 2;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] == 1)
            {
                Fill(i, j, nr);
                nr++;
            }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
