#include <iostream>
using namespace std;

class TelefonMobil
{
private:
	string model;
	int* durataZilnicaUtilizare = nullptr;
	int nrZile = 0;
	const int durataMaximaBaterie;
	static int anulFabricatiei;

protected:
	char* producator = nullptr;
public:
	float nivelBaterie = 0;

	TelefonMobil() : durataMaximaBaterie(9)
	{
		producator = new char[strlen("N/A") + 1];
		strcpy_s(producator, strlen("N/A") + 1, "N/A");
		model = "N/A";
		nivelBaterie = 0;
	}

	TelefonMobil(int nivelBaterie) : TelefonMobil()
	{
		this->nivelBaterie = nivelBaterie;
	}

	TelefonMobil(int durataMaximaBaterie, const char* _producator, string _model) :
		durataMaximaBaterie(durataMaximaBaterie)
	{
		if (_producator != nullptr)
		{
			producator = new char[strlen(_producator) + 1];
			strcpy_s(producator, strlen(_producator) + 1, _producator);
		}
		model = _model;
		nivelBaterie = 0;
	}

	TelefonMobil(int durataMaximaBaterie,
		int* durataZilnicaUtilizare, int nrZile) :
		durataMaximaBaterie(durataMaximaBaterie)
	{
		if (durataZilnicaUtilizare != nullptr && nrZile > 0)
		{
			this->nrZile = nrZile;
			this->durataZilnicaUtilizare = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				this->durataZilnicaUtilizare[i] =
					durataZilnicaUtilizare[i];
			}
		}
	}

	TelefonMobil(const TelefonMobil& t) : durataMaximaBaterie(t.durataMaximaBaterie)
	{
		model = t.model;
		nivelBaterie = t.nivelBaterie;

		if (t.durataZilnicaUtilizare != nullptr && t.nrZile > 0)
		{
			this->nrZile = t.nrZile;
			this->durataZilnicaUtilizare = new int[t.nrZile];
			for (int i = 0; i < t.nrZile; i++)
			{
				this->durataZilnicaUtilizare[i] =
					t.durataZilnicaUtilizare[i];
			}
		}

		if (t.producator != nullptr)
		{
			producator = new char[strlen(t.producator) + 1];
			strcpy_s(producator, strlen(t.producator) + 1, t.producator);
		}
	}

	TelefonMobil& operator=(const TelefonMobil& t)
	{
		if (this != &t) {
			if (durataZilnicaUtilizare != nullptr)
			{
				delete[] durataZilnicaUtilizare;
			}
			if (producator != nullptr)
			{
				delete[] producator;
			}

			if (t.producator != nullptr)
			{
				producator = new char[strlen(t.producator) + 1];
				strcpy_s(producator, strlen(t.producator) + 1, t.producator);
			}
			else
			{
				producator = nullptr;
			}

			model = t.model;
			nivelBaterie = t.nivelBaterie;

			if (t.durataZilnicaUtilizare != nullptr && t.nrZile > 0)
			{
				this->nrZile = t.nrZile;
				this->durataZilnicaUtilizare = new int[t.nrZile];
				for (int i = 0; i < t.nrZile; i++)
				{
					this->durataZilnicaUtilizare[i] =
						t.durataZilnicaUtilizare[i];
				}
			}
			else
			{
				durataZilnicaUtilizare = nullptr;
				nrZile = 0;
			}
		}
		return *this;
	}


	~TelefonMobil()
	{
		if (durataZilnicaUtilizare != nullptr)
		{
			delete[] durataZilnicaUtilizare;
		}
		if (producator != nullptr)
		{
			delete[] producator;
		}
	}

	string getModel()
	{
		return model;
	}

	void setModel(string model)
	{
		if (model.length() > 2)
		{
			this->model = model;
			// (*this).model = model;
		}
	}

	int getDurataMaximaBaterie() const
	{
		return durataMaximaBaterie;
	}

	void setProducator(const char* producator)
	{
		if (producator != nullptr)
		{
			if (this->producator != nullptr)
			{
				delete[] this->producator;
			}

			this->producator = new char[strlen(producator) + 1];
			strcpy_s(this->producator, strlen(producator) + 1, producator);
		}
	}

	string getProducator()
	{
		return producator;
	}

	static int getAnulFabricatiei()
	{
		return anulFabricatiei;
	}

	static void setAnulFabricatiei(int anulFabricatiei)
	{
		TelefonMobil::anulFabricatiei = anulFabricatiei;
	}

	static float calculeazaNivelMediuBaterie(TelefonMobil* telefoane, int nrTelefoane)
	{
		float suma = 0;
		if (telefoane != nullptr && nrTelefoane > 0)
		{
			for (int i = 0; i < nrTelefoane; i++)
			{
				suma += telefoane[i].nivelBaterie;
			}
			return suma / nrTelefoane;
		}
		return suma;
	}

	void incarca(float);

	friend string operator+(TelefonMobil t, string s);
};
int TelefonMobil::anulFabricatiei = 2025;

void TelefonMobil::incarca(float nivelIncarcare)
{
	nivelBaterie += nivelIncarcare;
}

string operator+(TelefonMobil t, string s)
{
	return t.model + s;
}

string operator+(string s, TelefonMobil t)
{
	return t + s;
}
 
int main()
{
	TelefonMobil telefonPersonal;
	telefonPersonal.nivelBaterie = 20;
	telefonPersonal.incarca(50);

	TelefonMobil* pTelefonDeServiciu = new TelefonMobil();
	cout << (*pTelefonDeServiciu).nivelBaterie << endl;
	pTelefonDeServiciu->incarca(20);
	cout << pTelefonDeServiciu->nivelBaterie << endl;
	delete pTelefonDeServiciu;
	pTelefonDeServiciu = nullptr;

	TelefonMobil telefonDeServiciu(12, "Samsung", "S24");

	TelefonMobil* pTelefonPersonal = new TelefonMobil(15, "Apple", "Iphone 17");
	cout << pTelefonPersonal->nivelBaterie << endl;
	//...
	delete pTelefonPersonal;
	pTelefonPersonal = nullptr;

	TelefonMobil t2(75);
	TelefonMobil t3 = 80;

	TelefonMobil t4(t3);
	TelefonMobil t5 = t4;
	t5.setModel("Galaxy Fold");
	cout << t5.getModel() << endl;

	cout << TelefonMobil::getAnulFabricatiei() << endl;
	t4.setAnulFabricatiei(2026);
	cout << t5.getAnulFabricatiei() << endl;

	TelefonMobil vectorStatic[]{ t2, t4, t5 };
	cout << TelefonMobil::calculeazaNivelMediuBaterie(vectorStatic, 3) << endl;

	TelefonMobil* vectorDinamic = new TelefonMobil[3];
	vectorDinamic[0].nivelBaterie = 20;
	cout << TelefonMobil::calculeazaNivelMediuBaterie(vectorDinamic, 3) << endl;
	delete[] vectorDinamic;
	vectorDinamic = nullptr;

	int durateUtilizare[]{ 300, 250, 120, 60 };
	TelefonMobil t6(12, durateUtilizare, 4);

	TelefonMobil t7(t6);
	TelefonMobil t8 = t6;

	t3 = t6;
	t3.operator=(t6);
	t2 = t3 = t6;

	t6.setProducator("Huawei");
	cout << t6.getProducator() << endl;

	cout << t6 + "!";
}