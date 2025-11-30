#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class InvalidParametersException : public exception
{
public:
	InvalidParametersException()
	{
	}

	InvalidParametersException(const char* message) : exception(message)
	{
	}
};

class TelefonMobil
{
private:
	int* durataZilnicaUtilizare = nullptr;
	int nrZile = 0;
	const int durataMaximaBaterie;
	static int anulFabricatiei;

protected:
	string model;
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

	void setDurataZilnicaUtilizare(int* durate, int nr)
	{
		if (durate != NULL && nr > 0)
		{
			if (durataZilnicaUtilizare != NULL) delete[] durataZilnicaUtilizare;
			nrZile = nr;
			durataZilnicaUtilizare = new int[nr];
			for (int i = 0; i < nr; i++)
				durataZilnicaUtilizare[i] = durate[i];
		}
	}

	string getProducator()
	{
		return producator;
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < nrZile)
		{
			return durataZilnicaUtilizare[index];
		}
		throw exception("index invalid");
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

	friend ostream& operator<<(ostream&, TelefonMobil);

	friend istream& operator>>(istream&, TelefonMobil&);

	friend ofstream& operator<<(ofstream&, TelefonMobil);

	friend ifstream& operator>>(ifstream&, TelefonMobil&);
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

ostream& operator<<(ostream& out, TelefonMobil t)
{
	out << "Producator: ";
	if (t.producator != nullptr)
	{
		out << t.producator << endl;
	}
	out << "Model: " << t.model << endl;
	out << "Nivel baterie: " << t.nivelBaterie << endl;
	out << "Nr zile: " << t.nrZile << endl;
	out << "Durate zilnice:";
	if (t.durataZilnicaUtilizare != nullptr)
	{
		for (int i = 0; i < t.nrZile; i++)
		{
			out << " " << t.durataZilnicaUtilizare[i];
		}
	}
	out << endl;

	return out;
}

ofstream& operator<<(ofstream& f, TelefonMobil t)
{
	if (f.is_open()) {
		if (t.producator != nullptr)
		{
			f << t.producator;
		}
		f << endl;
		f << t.model << endl;
		f << "" << t.nivelBaterie << endl;
		f << "" << t.nrZile << endl;
		if (t.durataZilnicaUtilizare != nullptr)
		{
			for (int i = 0; i < t.nrZile; i++)
			{
				f << "" << t.durataZilnicaUtilizare[i] << endl;
			}
		}
	}
	return f;
}

istream& operator>>(istream& in, TelefonMobil& t)
{
	char buffer[100];
	if (t.producator != nullptr)
	{
		delete[] t.producator;
		t.producator = nullptr;
	}
	cout << "Producator: ";
	in.getline(buffer, 99);
	t.producator = new char[strlen(buffer) + 1];
	strcpy_s(t.producator, strlen(buffer) + 1, buffer);

	cout << "Model: ";
	getline(in, t.model);

	cout << "Nivel baterie: ";
	in >> t.nivelBaterie;

	int nr = 0;
	cout << "Nr zile: ";
	in >> nr;
	if (nr > 0)
	{
		int* durate = new int[nr];
		for (int i = 0; i < nr; i++)
		{
			cout << "Durata ziua " << (i + 1) << ": ";
			in >> durate[i];
		}
		t.setDurataZilnicaUtilizare(durate, nr);
	}

	return in;
}

ifstream& operator>>(ifstream& f, TelefonMobil& t)
{
	char buffer[100];
	if (t.producator != nullptr)
	{
		delete[] t.producator;
		t.producator = nullptr;
	}
	f.getline(buffer, 99);
	t.producator = new char[strlen(buffer) + 1];
	strcpy_s(t.producator, strlen(buffer) + 1, buffer);

	getline(f, t.model);

	f >> t.nivelBaterie;

	int nr = 0;
	f >> nr;
	if (nr > 0)
	{
		int* durate = new int[nr];
		for (int i = 0; i < nr; i++)
		{
			f >> durate[i];
		}
		t.setDurataZilnicaUtilizare(durate, nr);
	}

	return f;
}

class TelefonMobilPliabil : public TelefonMobil
{
private:
	int dimensiunePliat = 0;
	string model;
	int* durateIncarcare = nullptr;
	int nrIncarcari = 0;

public:
	TelefonMobilPliabil()
	{
		dimensiunePliat = 20;
	}

	TelefonMobilPliabil(int durataMaximaBaterie, const char* producator,
		string model, int dimensiunePliat) : TelefonMobil(durataMaximaBaterie,
			producator, model)
	{
		this->dimensiunePliat = dimensiunePliat;
	}

	TelefonMobilPliabil(const TelefonMobilPliabil& t) : TelefonMobil(t)
	{
		this->dimensiunePliat = t.dimensiunePliat;
		this->model = t.model;
		if (t.durateIncarcare != nullptr && t.nrIncarcari > 0)
		{
			this->nrIncarcari = t.nrIncarcari;
			this->durateIncarcare = new int[t.nrIncarcari];
			for (int i = 0; i < t.nrIncarcari; i++)
			{
				this->durateIncarcare[i] = t.durateIncarcare[i];
			}
		}
	}

	~TelefonMobilPliabil()
	{
		if (this->durateIncarcare != nullptr)
		{
			delete[] this->durateIncarcare;
		}
	}

	TelefonMobilPliabil& operator=(const TelefonMobilPliabil& t)
	{
		if (this != &t)
		{
			TelefonMobil::operator=(t);

			if (this->durateIncarcare != nullptr)
			{
				delete[] this->durateIncarcare;
			}

			this->dimensiunePliat = t.dimensiunePliat;
			this->model = t.model;
			if (t.durateIncarcare != nullptr && t.nrIncarcari > 0)
			{
				this->nrIncarcari = t.nrIncarcari;
				this->durateIncarcare = new int[t.nrIncarcari];
				for (int i = 0; i < t.nrIncarcari; i++)
				{
					this->durateIncarcare[i] = t.durateIncarcare[i];
				}
			}
			else
			{
				this->nrIncarcari = 0;
				this->durateIncarcare = nullptr;
			}
		}
		return *this;
	}

	void setDurateIncarcare(int* durate, int nrDurate)
	{
		if (durate != nullptr && nrDurate > 0)
		{
			if (this->durateIncarcare != nullptr)
			{
				delete[] this->durateIncarcare;
			}
			this->nrIncarcari = nrDurate;
			this->durateIncarcare = new int[nrDurate];
			for (int i = 0; i < nrDurate; i++)
			{
				this->durateIncarcare[i] = durate[i];
			}
		}
		else
		{
			throw new InvalidParametersException();
		}
	}

	string getModel()
	{
		return TelefonMobil::model;
	}
};
 
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

	cout << t6 + "!" << endl;

	cin >> t2;
	cout << t2;

	TelefonMobilPliabil tp1;
	TelefonMobilPliabil tp2(12, "OnePlus", "7", 10);
	cout << tp2.getModel();
	cout << tp2 + " ceva" << endl;
	try
	{
		cout << tp2[2] << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	catch (int i)
	{
		cout << "Cod eroare: " << i << endl;
	}
	catch (...)
	{
		cout << "Eroare generica" << endl;
	}

	int y = 15;
	float x = 9.2;
	cout << hex << y << endl;
	cout << y << endl;
	cout << setiosflags(ios::showbase | ios::showpoint);
	cout << x << endl;
	cout << resetiosflags(ios::showbase | ios::showpoint | ios::hex);
	cout << y << endl;
	
	cout << "y = ";
	cin >> y;
	if (!cin.good())
	{
		cout << "Eroare la citire" << endl;
	}

	int d[]{ 1, 2, 1, 2 };
	tp1.setDurateIncarcare(d, 4);

	ofstream f("telefon.txt");
	f << t2;
	f.close();

	ifstream g("telefon.txt");
	TelefonMobil t10;
	g >> t10;
	g.close();
}