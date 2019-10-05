#include <fstream>
#include<ctime>
#include <chrono>
#include <iomanip>
#include <queue>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include "time.h"
using namespace std;

int aux[100][100];
int tmp[100][100];

void LCS(char * x, char * y, int sizeX, int sizeY);
void imprimir(char * x, int i, int j);


int main() {

    char xchar[] = "AGGTAB";  
    char ychar[] = "GXTXAYB";     
    int sizeX = strlen(xchar);  
    int sizeY = strlen(ychar); 

    LCS(xchar, ychar, sizeX, sizeY);
    cout << "Resultado: ";
    imprimir(xchar, sizeX-1, sizeY-1);
    cout << endl;

    return 0;
}

void LCS(char * X, char * Y, int sizeX, int sizeY)
{
    int m,n;
    m = sizeX;
    n = sizeY;

    for(int i = 1; i <= m; i++)
         tmp[i][0] = 0;

    for(int j = 0; j <= n; j++)
        tmp[0][j] = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (X[i] == Y[j])
            {
                tmp[i][j] = tmp[i-1][j-1] + 1;
                aux[i][j] = 1;
            } else {
                if (tmp[i-1][j] >= tmp[i][j-1])
                {
                    tmp[i][j] = tmp[i-1][j];
                    aux[i][j] = 2;
                } else {
                    tmp[i][j] = tmp[i][j-1];
                    aux[i][j] = 3;
                }
            }
        }
    }
}

void imprimir(char * x, int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (aux[i][j] == 1)
    {
        imprimir(x, i - 1, j - 1);
        cout << x[i];
    } else {
        if (aux[i][j] == 2)
            imprimir(x, i - 1, j);
        else
            imprimir(x, i, j -1);
    }
}