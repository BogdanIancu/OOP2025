#include <iostream>
using namespace std;

class Impozabil 
{
public:
	virtual ~Impozabil() = default;
	virtual float calculeazaImpozit() = 0;
};

class VehiculElectric
{
private:
	string producator;
	float pret;
	int capacitateBaterie;

public:
	VehiculElectric(string producator, float pret, int capacitateBaterie)
	{
		this->producator = producator;
		this->pret = pret;
		this->capacitateBaterie = capacitateBaterie;
	}

	virtual ~VehiculElectric()
	{
	}

	int getCapacitateBaterie()
	{
		return capacitateBaterie;
	}

	virtual float getCostRovinieta() = 0;
};

class Masina : public Impozabil
{
private:
	string model;
	int anFabricatie;
protected:
	string producator;
	int consum = 0;
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

	~Masina()
	{
		cout << "Destructor masina" << endl;
	}

	string getProducator()
	{
		return producator;
	}

	virtual void afisareConsum()
	{
		cout << "consum: " << consum << "L/100km";
	}

	float calculeazaImpozit() override
	{
		return 100;
	}
};

class MasinaElectrica : public Masina, public VehiculElectric
{
private:
	int timpIncarcare = 0;

public:
	MasinaElectrica() : Masina(), VehiculElectric("", 0, 0)
	{
	}

	MasinaElectrica(string producator, string model, int capacitateBaterie) :
		VehiculElectric(producator, 0, capacitateBaterie), Masina(producator, model)
	{
	}

	string getProducator()
	{
		return Masina::producator;
	}

	void afisareConsum() override 
	{
		cout << "consum: " << consum << "KWh/100km";
	}

	float getCostRovinieta() override
	{
		return 250;
	}

	float calculeazaImpozit() override
	{
		return 0;
	}
};

int suma(int a, int b)
{
	return a + b;
}

int diferenta(int a, int b)
{
	return a - b;
}

int main()
{
	MasinaElectrica e1;
	MasinaElectrica e2("Mercedes", "EQS", 40);

	VehiculElectric* v = nullptr;
	v = &e2;
	Masina m1;
	m1 = e2;

	cout << "Producator masina electrica: " << e2.getProducator() << endl;
	cout << "Producator masina: " << e1.Masina::getProducator() << endl;

	Masina& r = e2;
	r.afisareConsum();
	cout << endl;

	int (*f)(int, int) = diferenta;
	cout << f(1, 2) << endl;

	cout << v->getCostRovinieta() << endl;

	Masina* pm = new Masina("Dacia", "Logan");

	Impozabil* vector[]{ &m1, &e1, pm };

	double impozitTotal = 0;
	for (int i = 0; i < 3; i++)
	{
		impozitTotal += vector[i]->calculeazaImpozit();
	}
	cout << impozitTotal << endl;

	delete vector[2];
	vector[2] = nullptr;
	pm = nullptr;

}