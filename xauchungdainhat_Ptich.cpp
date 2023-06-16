#include <iostream>
#include <string.h>
#define MAX 10000

using namespace std;

class Xau_Con
{
private:
    void QHXau_Con(char* s1, char* s2);
public:
    void menu();
    void Xu_Ly();
};

void Xau_Con::QHXau_Con(char* s1, char* s2)
{
    int m = strlen(s1), n = strlen(s2);

    // Create 2D arrays
    int** B = new int* [m + 1];
    int** T = new int* [m + 1];
    for (int i = 0; i <= m; i++)
    {
        B[i] = new int[n + 1];
        T[i] = new int[n + 1];
    }

    // Initialize the solution matrix
    for (int i = 0; i <= n; i++)
        B[0][i] = 0;
    for (int i = 0; i <= m; i++)
        B[i][0] = 0;

    // Compute the solution matrix and trace the optimal subsequence
    cout << "\n---------------------- Tao Bang ----------------------\n";
    for (int i = 1; i <= m; i++)
    {
        cout << endl;
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
            {
                B[i][j] = B[i - 1][j - 1] + 1;
                T[i][j] = 0;
            }
            else
            {
                if (B[i - 1][j] > B[i][j - 1])
                {
                    B[i][j] = B[i - 1][j];
                    T[i][j] = -1;
                }
                else
                {
                    B[i][j] = B[i][j - 1];
                    T[i][j] = 1;
                }
                cout << B[i][j] << " ";
            }
        }
    }

    cout << "\n\nTong so ky tu co trong xau con: " << B[m][n];

    int len = B[m][n];
    char* s = new char[len + 1];
    s[len] = 0;

    // Trace the optimal subsequence
    while (m >= 0 && n >= 0)
    {
        if (T[m][n] == 0)
        {
            s[--len] = s1[m - 1];
            m--;
            n--;
        }
        else if (T[m][n] == -1)
            m--;
        else
            n--;
    }
    cout << "\nXau con chung dai nhat la: " << s << endl;

    // Free allocated memory
    for (int i = 0; i <= m; i++)
    {
        delete[] B[i];
        delete[] T[i];
    }
    delete[] B;
    delete[] T;
}

void Xau_Con::menu()
{
    cout << "\n\t*********************** MENU LUA CHON ***********************" << endl << endl;
    cout << "\t\t0: Thoat chuong trinh\n";
    cout << "\t\t1: Nhap du lieu tu ban phim\n";
}

void Xau_Con::Xu_Ly()
{
    Xau_Con c;
    int chon;
    cout << "\nXin moi chon muc thuc hien: ";
    cin >> chon;
    switch (chon) {
    case 1: {
        char s1[MAX], s2[MAX];
        cout << "Nhap xau s1: ";
        cin >> s1;
        cout << "Nhap xau s2: ";
        cin >> s2;
        QHXau_Con(s1, s2);
        break;
    }
    default:
        cout << "Muc lua chon khong hop le!" << endl;
    }
}

int main()
{
    Xau_Con x;
    x.menu();
    x.Xu_Ly();
    return 0;
}
