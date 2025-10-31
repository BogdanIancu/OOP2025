#include <iostream>
using namespace std;

class Masina
{
private:
    string producator;
    string model;
    int anFabricatie = 0;
    float pret = 0;
    const int serieSasiu;
    static string normaPoluare;

public:
    Masina() : serieSasiu(0)
    {
        producator = "N/A";
        model = "N/A";
        anFabricatie = 1900;
        pret = 300;
    }

    Masina(int serieSasiu, string producator, string model) : serieSasiu(serieSasiu)
    {
        this->producator = producator;
        this->model = model;
        this->anFabricatie = 1900;
        this->pret = 300;
    }

    Masina(const Masina& m) : serieSasiu(m.serieSasiu)
    {
        this->producator = m.producator;
        this->model = m.model;
        this->anFabricatie = m.anFabricatie;
        this->pret = m.pret;
    }

    int getAnFabricatie() const
    {
        return anFabricatie;
    }

    void setAnFabricatie(int anFabricatie);

    int getSerieSasiu()
    {
        return serieSasiu;
    }

    static string getNormaPoluare() 
    {
        return normaPoluare;
    }

    static void setNormaPoluare(string normaPoluare)
    {
        Masina::normaPoluare = normaPoluare;
    }

    static double calculValoareFlota(Masina* masini, int nrMasini)
    {
        double suma = 0;
        if (masini != nullptr && nrMasini > 0) {
            for (int i = 0; i < nrMasini; i++) {
                suma += masini[i].pret;
            }
        }
        return suma;
    }
};
string Masina::normaPoluare = "euro 6";

void Masina::setAnFabricatie(int anFabricatie)
{
    if (anFabricatie >= 1900 && anFabricatie <= 2025)
    {
        this->anFabricatie = anFabricatie;
    }
}

int main()
{
    Masina m1;
    Masina m2(12345, "Dacia", "Logan");
    Masina m3(m2);
    Masina m4 = m3;

    m4.setAnFabricatie(2025);
    cout << m4.getAnFabricatie() << endl;

    cout << Masina::getNormaPoluare() << endl;
    Masina::setNormaPoluare("euro 7");
    cout << m4.getNormaPoluare() << endl;

    Masina vectorMasini[]{ m1, m2, m3 };
    cout << Masina::calculValoareFlota(vectorMasini, 3) << endl;
}