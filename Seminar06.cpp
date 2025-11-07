#include <iostream>
using namespace std;

class Masina
{
private:
    string producator;
    string model;
    int anFabricatie = 0;
    float pretDeBaza = 0;
    float* preturiDotariExtra = nullptr;
    int nrDotariExtra = 0;
    const int serieSasiu;
    static string normaPoluare;

public:
    Masina() : serieSasiu(0)
    {
        producator = "N/A";
        model = "N/A";
        anFabricatie = 1900;
        pretDeBaza = 300;
    }

    Masina(int serieSasiu, string producator, string model) : serieSasiu(serieSasiu)
    {
        this->producator = producator;
        this->model = model;
        this->anFabricatie = 1900;
        this->pretDeBaza = 300;
    }

    Masina(int serieSasiu, float pretDeBaza, float* preturiDotariExtra, int nrDotariExtra) : serieSasiu(serieSasiu)
    {
        this->anFabricatie = 1900;
        this->pretDeBaza = pretDeBaza;
        if (preturiDotariExtra != nullptr && nrDotariExtra > 0) {
            this->nrDotariExtra = nrDotariExtra;
            this->preturiDotariExtra = new float[nrDotariExtra];
            for (int i = 0; i < nrDotariExtra; i++)
            {
                this->preturiDotariExtra[i] = preturiDotariExtra[i];
            }
        }
    }

    Masina(const Masina& m) : serieSasiu(m.serieSasiu)
    {
        this->producator = m.producator;
        this->model = m.model;
        this->anFabricatie = m.anFabricatie;
        this->pretDeBaza = m.pretDeBaza;

        if (m.preturiDotariExtra != nullptr && m.nrDotariExtra > 0) {
            this->nrDotariExtra = m.nrDotariExtra;
            this->preturiDotariExtra = new float[m.nrDotariExtra];
            for (int i = 0; i < m.nrDotariExtra; i++)
            {
                this->preturiDotariExtra[i] = m.preturiDotariExtra[i];
            }
        }
    }

    ~Masina()
    {
        if (preturiDotariExtra != nullptr) {
            delete[] preturiDotariExtra;
        }
    }

    Masina& operator=(const Masina& m)
    {
        if (this != &m)
        {
            if (preturiDotariExtra != nullptr) {
                delete[] preturiDotariExtra;
            }

            this->producator = m.producator;
            this->model = m.model;
            this->anFabricatie = m.anFabricatie;
            this->pretDeBaza = m.pretDeBaza;

            if (m.preturiDotariExtra != nullptr && m.nrDotariExtra > 0) {
                this->nrDotariExtra = m.nrDotariExtra;
                this->preturiDotariExtra = new float[m.nrDotariExtra];
                for (int i = 0; i < m.nrDotariExtra; i++)
                {
                    this->preturiDotariExtra[i] = m.preturiDotariExtra[i];
                }
            }
            else
            {
                this->preturiDotariExtra = nullptr;
                this->nrDotariExtra = 0;
            }
        }
        return *this;
    }

    float* getPreturiDotariExtra()
    {
        if (preturiDotariExtra != nullptr)
        {
            float* copie = new float[nrDotariExtra];
            for (int i = 0; i < nrDotariExtra; i++)
            {
                copie[i] = preturiDotariExtra[i];
            }
            return copie;
        }
        else
        {
            return nullptr;
        }
    }

    float getPreturiDotariExtra(int index)
    {
        if (index >= 0 && index < nrDotariExtra && preturiDotariExtra != nullptr)
            return preturiDotariExtra[index];
        else
            return 0;
    }

    void setPreturiDotariExtra(float* preturi, int nrPreturi)
    {
        if (preturi != nullptr && nrPreturi > 0)
        {
            if (preturiDotariExtra != nullptr)
            {
                delete[] preturiDotariExtra;
            }

            preturiDotariExtra = new float[nrPreturi];
            nrDotariExtra = nrPreturi;
            for (int i = 0; i < nrPreturi; i++)
            {
                preturiDotariExtra[i] = preturi[i];
            }
        }
    }

    int getNrDotariExtra()
    {
        return nrDotariExtra;
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
                suma += masini[i].pretDeBaza;
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

    float preturi[]{ 100.99, 311.1, 400.2 };

    Masina m5(123, 5000, preturi, 3);
    preturi[0] = 500;

    Masina m6 = m5;

    float* v = m6.getPreturiDotariExtra();

    for (int i = 0; i < m6.getNrDotariExtra(); i++)
        cout << v[i] << ' ';
    cout << endl;

    delete[]v;
    v = nullptr;

    float vector[]{ 256.23, 332.99 };
    m6.setPreturiDotariExtra(vector, 2);

    cout << m6.getPreturiDotariExtra(1);
    cout << endl;

    m1 = m2 = m6;
}