#include <iostream>
using namespace std;

class CelulaBaterie
{
private:
	int tensiuneElectrica;
	int intensitateElectrica;

public:
	CelulaBaterie()
	{
		tensiuneElectrica = 0;
		intensitateElectrica = 0;
	}

	CelulaBaterie(int tensiune, int intensitate)
	{
		this->tensiuneElectrica = tensiune;
		this->intensitateElectrica = intensitate;
	}

	int getTensiune()
	{
		return tensiuneElectrica;
	}

	int getIntensitate()
	{
		return intensitateElectrica;
	}
};

class Baterie
{
private:
	CelulaBaterie* celule = nullptr;
	int numarCelule = 0;

public:
	Baterie() 
	{
	}

	Baterie(CelulaBaterie celula, unsigned int numarCelule)
	{
		celule = new CelulaBaterie[numarCelule];
		this->numarCelule = numarCelule;
		for (unsigned int i = 0; i < numarCelule; i++)
		{
			this->celule[i] = celula;
		}
	}

	Baterie(const Baterie& b)
	{
		if (b.numarCelule > 0 && b.celule != nullptr)
		{
			this->celule = new CelulaBaterie[b.numarCelule];
			this->numarCelule = b.numarCelule;
			for (int i = 0; i < b.numarCelule; i++)
			{
				this->celule[i] = b.celule[i];
			}
		}
	}

	~Baterie()
	{
		if (celule != nullptr)
		{
			delete[] celule;
		}
	}

	Baterie& operator=(const Baterie& b)
	{
		if (this != &b)
		{
			if (celule != nullptr)
			{
				delete[] celule;
			}
			if (b.numarCelule > 0 && b.celule != nullptr)
			{
				this->celule = new CelulaBaterie[b.numarCelule];
				this->numarCelule = b.numarCelule;
				for (int i = 0; i < b.numarCelule; i++)
				{
					this->celule[i] = b.celule[i];
				}
			}
			else
			{
				this->celule = nullptr;
				this->numarCelule = 0;
			}
		}
		return *this;
	}

	int getTensiune()
	{
		int suma = 0;
		if (numarCelule > 0 && celule != nullptr)
		{
			for (int i = 0; i < numarCelule; i++)
			{
				suma += celule[i].getTensiune();
			}
		}
		return suma;
	}
};

class VehiculElectric
{
private:
	string producator;
	float pret;
	Baterie baterie;

public:
	VehiculElectric(string producator, float pret, Baterie baterie)
	{
		this->producator = producator;
		this->pret = pret;
		this->baterie = baterie;
	}

	int getTensiuneBaterie()
	{
		return baterie.getTensiune();
	}
};

class Masina
{
private:
	string model;
	int anFabricatie;
protected:
	string producator;
public:
	Masina()
	{
		producator = "N/A";
		model = "N/A";
		anFabricatie = 1900;
	}

	Masina(string producator, string model)
	{
		this->producator = producator;
		this->model = model;
		this->anFabricatie = 1900;
	}

	string getProducator()
	{
		return producator;
	}
};

class MasinaElectrica : public Masina, public VehiculElectric
{
private:
	int timpIncarcare = 0;

public:
	MasinaElectrica() : Masina(), VehiculElectric("", 0, Baterie())
	{
	}

	MasinaElectrica(string producator, string model, Baterie baterie) :
		VehiculElectric(producator, 0, baterie), Masina(producator, model)
	{
	}

	string getProducator()
	{
		return Masina::producator;
	}
};

int main()
{
	CelulaBaterie c(4, 1);
	Baterie b1;
	Baterie b2(c, 1000);
	cout << b2.getTensiune() << endl;
	Baterie b3 = b2;
	b1 = b3;

	MasinaElectrica e1;
	MasinaElectrica e2("Mercedes", "EQS", b2);

	VehiculElectric v("Tesla", 30000, b3);
	v = e2;
	Masina m1;
	m1 = e2;

	cout << "Producator masina electrica: " << e2.getProducator() << endl;
	cout << "Producator masina: " << e1.Masina::getProducator() << endl;
}