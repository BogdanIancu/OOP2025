#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n";
    char c = 97;
    cout << c << endl;
    printf("%d\n", c);
    c = -100;
    cout << c << endl;
    unsigned char d = 255;
    d++;
    printf("%d\n", d);

    short x = 10000;
    cout << sizeof(x) << endl;

    int y = 20000000;
    cout << sizeof(y) << endl;

    long long z = 1234;
    cout << sizeof(z) << endl;

    bool ok = false;
    cout << sizeof(ok) << endl;

    if (c == -100)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "Not OK" << endl;
    }

    float a = 8.4;
    cout << sizeof(a) << endl;

    double b = 8.4;
    cout << sizeof(b) << endl;

    if (fabs(a - b) < 0.01)
    {
        cout << "egale";
    }
    else
    {
        cout << "inegale";
    }
}