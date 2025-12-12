#include <iostream>
#include <string>
using namespace std;

class TelefonMobil
{
private:
	string model;
protected:
	int durataIncarcare;

public:
	TelefonMobil(int durataIncarcare)
	{
		this->durataIncarcare = durataIncarcare;
	}

	virtual ~TelefonMobil()
	{
		cout << "Destructor TelefonMobil" << endl;
	}

	virtual float getDurataIncarcare()
	{
		return durataIncarcare;
	}
};

class TelefonMobilPliabil : public TelefonMobil
{
private:
	int dimensiunePliat;

public:
	TelefonMobilPliabil() : TelefonMobil(20)
	{
		dimensiunePliat = 0;
	}

	TelefonMobilPliabil(int durataIncarcare, int dimensiunePliat) : TelefonMobil(durataIncarcare)
	{
		this->dimensiunePliat = dimensiunePliat;
	}

	~TelefonMobilPliabil()
	{
		cout << "destructor TelefonMobilPliabil" << endl;
	}

	float getDurataIncarcare() override
	{
		return durataIncarcare * 1.1;
	}
};

class Animal
{
public:
	virtual void scoateSunet() = 0;
};

class Caine : public Animal
{
public:
	void scoateSunet() override
	{
		cout << "Ham! ";
	}
};

class Pisica : public Animal
{
public:
	void scoateSunet() override
	{
		cout << "Miau! ";
	}
};

class Rata : public Animal
{
public:
	void scoateSunet() override
	{
		cout << "Mac! ";
	}
};

struct VTable
{
	float (TelefonMobil::*f1)() = &TelefonMobil::getDurataIncarcare;
};

int main()
{
	TelefonMobil tm1(2);
	TelefonMobilPliabil tmp1(2, 10);
	cout << tm1.getDurataIncarcare() << endl;
	cout << tmp1.getDurataIncarcare() << endl;

	TelefonMobil* ptm = nullptr;
	int x = 0;
	cout << "Introduceti un numar par sau impar: ";
	cin >> x;

	if (x % 2 == 0)
	{
		//ptm = &tmp1;
		ptm = new TelefonMobilPliabil(2, 10);
	}
	else
	{
		//ptm = &tm1;
		ptm = new TelefonMobil(2);
	}

	cout << ptm->getDurataIncarcare() << endl;

	delete ptm;
	ptm = nullptr;

	Caine caine; Pisica pisica; Rata rata;
	Animal* v[]{ &caine, &pisica, &rata };
	for (int i = 0; i < 3; i++)
	{
		v[i]->scoateSunet();
	}
	cout << endl;
}