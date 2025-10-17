#include <iostream>
#include <string>
using namespace std;

void afisare(int** matrice, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrice[i][j] << ' ';
        }
        cout << endl;
    }
}

void interschimbare(int& x, int& y)
{
    int aux = x;
    x = y;
    y = aux;
}

void interschimbare2(int* x, int* y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

int main()
{
    char s[20];
    strcpy_s(s, "Maria");
    cout << s << endl;
    cout << strlen(s) << endl;

    char* copie = new char[strlen(s) + 1];
    strcpy_s(copie, strlen(s) + 1, s);
    cout << copie << endl;

    delete[] copie;
    copie = nullptr;

    string sir = "Ion";
    cout << sir.length() << endl;

    string altSir = sir;
    cout << altSir << endl;

    altSir = s;
    const char* nume = altSir.c_str();

    int m[3][2]{ {1,2}, {3,4}, {5,6} };
    cout << sizeof(m) / sizeof(m[0]) << endl;
    cout << sizeof(m[0]) / sizeof(m[0][0]) << endl;

    cout << m[2][1] << endl;

    cout << *(*(m + 2) + 1) << endl;

    int** z = new int* [3];
    for (int i = 0; i < 3; i++)
    {
        z[i] = new int[2];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            z[i][j] = m[i][j];
        }
    }
    afisare(z, 3, 2);

    for (int i = 0; i < 3; i++)
    {
        delete[] z[i];
    }
    delete[] z;
    z = nullptr;

    int a = 7;
    int b = 2;
    interschimbare(a, b);
    cout << endl;
    cout << a << ' ' << b;

    interschimbare2(&a, &b);
    cout << endl;
    cout << a << ' ' << b;
}
