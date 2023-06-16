#include <iostream>
using namespace std;

int dong[8], cot[8], cheosac[15], cheohuyen[15], dem = 0;

void print()
{
    int board[8][8] = { 0 };

    for (int i = 0; i < 8; i++)
    {
        board[i][dong[i]] = 1;
    }

    cout << "Ma tran 8x8:\n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << "Buoc " << i + 1 << ": Tren dong " << i << " dat quan Hau o cot " << dong[i] << endl;
    }
}


void thu(int i)
{
    int j;
    if (i <= 7)
    {
        for (j = 0; j < 8; j++)
        {
            if (cot[j] == 1 && cheosac[i + j] == 1 && cheohuyen[i - j + 7] == 1)
            {
                dong[i] = j;
                cot[j] = 0;
                cheosac[i + j] = 0;
                cheohuyen[i - j + 7] = 0;
                thu(i + 1);
                cot[j] = 1;
                cheosac[i + j] = 1;
                cheohuyen[i - j + 7] = 1;
            }
        }
    }
    else
    {
        print();
        dem++;
    }
}

void tim()
{
    int i, q;
    for (i = 0; i < 8; i++)
    {
        cot[i] = 1;
        dong[i] = -1;
    }
    for (i = 0; i < 15; i++)
    {
        cheosac[i] = 1;
        cheohuyen[i] = 1;
    }
    thu(0);
    cout << "\nTong so cach dat quan Hau: " << dem;
}

int main()
{
    tim();
    return 0;
}
