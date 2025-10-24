#include <iostream>
using namespace std;

enum TipBursa { academica = 100, performanta = 200, sociala };

union Evaluare
{
    unsigned int nota;
    char calificativ[3];
};

struct Carte
{
    string titlu;
    string autor;
    int nrPagini = 0;
};

class Student
{
public:
    string nume;

    void afiseaza()
    {
        cout << "Nume: " << nume << "; " << "Grupa: " << grupa << endl;
    }

    /*Student()
    {
        nume = "Anonim";
        grupa = 1;
    }*/

    Student(int _grupa = 1)
    {
        nume = "Anonim";
        grupa = _grupa;
    }

    ~Student()
    {
        cout << "s-a apelat destructorul" << endl;
    }

private:
    int grupa = 0;
};


int main()
{
    TipBursa t = TipBursa::performanta;
    cout << t << endl;
    t = (TipBursa)201;

    Evaluare e;
    e.nota = 10;
    cout << e.nota << endl;
    strcpy_s(e.calificativ, "FB");
    cout << e.calificativ << endl;
    cout << e.nota << endl;

    Carte carte;
    carte.titlu = "Nexus";
    carte.autor = "Yuval Harari";
    carte.nrPagini = 450;
    cout << carte.titlu << ' ' << carte.autor << ' ' << carte.nrPagini << endl;

    cout << endl;

    Student student1;
    student1.nume = "Maria";
    cout << student1.nume << endl;
    student1.afiseaza();

    Student student2(1051);
    student2.afiseaza();

    Student* ps = new Student(1054);
    (*ps).nume = "Ion";
    ps->afiseaza();
    delete ps;
    ps = nullptr;

    cout << "MAIN ENDED" << endl;
}