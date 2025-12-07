#include <iostream>
#include <string>
using namespace std;

class TelefonMobil
{
private:
	string producator;
	string model;
public:
	TelefonMobil()
	{
	}

	TelefonMobil(string producator, string model)
	{
		this->producator = producator;
		this->model = model;
	}

	void afiseaza()
	{
		cout << "Producator: " << producator << " Model: " << model;
	}
};

class DispozitivPliabil
{
private:
	int dimensiunePliat;

public:
	DispozitivPliabil(int dimensiunePliat)
	{
		this->dimensiunePliat = dimensiunePliat;
	}

	void afiseaza()
	{
		cout << "Dimensiune pliat: " << dimensiunePliat;
	}
};

class TelefonMobilPliabil : public TelefonMobil, public DispozitivPliabil
{
private:
	int rezolutie;
public:
	TelefonMobilPliabil() : DispozitivPliabil(0)
	{
		rezolutie = 0;
	}

	TelefonMobilPliabil(string producator, string model, int dimensiunePliat,
		int rezolutie) : DispozitivPliabil(dimensiunePliat), TelefonMobil(producator, model)
	{
		this->rezolutie = rezolutie;
	}

	void afiseaza()
	{
		TelefonMobil::afiseaza();
		cout << " ";
		DispozitivPliabil::afiseaza();
		cout << " Rezolutie: " << rezolutie;
	}
};

class MagazinOnline
{
private:
	DispozitivPliabil** telefoane = nullptr;
	int numarTelefoane = 0;

public:
	MagazinOnline()
	{
		telefoane = new DispozitivPliabil*[1];
		telefoane[0] = new DispozitivPliabil(0);
		numarTelefoane = 1;
	}

	MagazinOnline(DispozitivPliabil** telefoane, int nrTelefoane)
	{
		if (telefoane != nullptr && nrTelefoane > 0)
		{
			this->numarTelefoane = nrTelefoane;
			this->telefoane = new DispozitivPliabil * [nrTelefoane];
			for (int i = 0; i < nrTelefoane; i++)
			{
				this->telefoane[i] = new DispozitivPliabil(0);
				*(this->telefoane[i]) = *(telefoane[i]);
			}
		}
	}

	MagazinOnline(const MagazinOnline& m)
	{
		if (m.telefoane != nullptr && m.numarTelefoane > 0)
		{
			this->numarTelefoane = m.numarTelefoane;
			this->telefoane = new DispozitivPliabil*[m.numarTelefoane];
			for (int i = 0; i < m.numarTelefoane; i++)
			{
				this->telefoane[i] = new DispozitivPliabil(0);
				*(this->telefoane[i]) = *(m.telefoane[i]);
			}
		}
	}

	~MagazinOnline()
	{
		if (telefoane != nullptr)
		{
			for (int i = 0; i < numarTelefoane; i++)
			{
				if (telefoane[i] != nullptr)
				{
					delete telefoane[i];
				}
			}
			delete[] telefoane;
		}
	}

	MagazinOnline& operator=(const MagazinOnline& m)
	{
		if (this != &m)
		{
			if (telefoane != nullptr)
			{
				for (int i = 0; i < numarTelefoane; i++)
				{
					if (telefoane[i] != nullptr)
					{
						delete telefoane[i];
					}
				}
				delete[] telefoane;
			}

			if (m.telefoane != nullptr && m.numarTelefoane > 0)
			{
				this->numarTelefoane = m.numarTelefoane;
				this->telefoane = new DispozitivPliabil * [m.numarTelefoane];
				for (int i = 0; i < m.numarTelefoane; i++)
				{
					this->telefoane[i] = new DispozitivPliabil(0);
					*(this->telefoane[i]) = *(m.telefoane[i]);
				}
			}
			else
			{
				this->telefoane = nullptr;
				this->numarTelefoane = 0;
			}
		}
		return *this;
	}
};
 
int main()
{
	TelefonMobilPliabil t1;
	TelefonMobilPliabil t2("Samsung", "Z fold", 10, 4000);
	t2.TelefonMobil::afiseaza();
	cout << endl;
	t2.afiseaza();
	cout << endl;

	MagazinOnline m1;
	DispozitivPliabil* vector[2];
	DispozitivPliabil p1(10);
	DispozitivPliabil p2(20);
	vector[0] = &p1;
	vector[1] = &p2;
	MagazinOnline m2(vector, 2);
}