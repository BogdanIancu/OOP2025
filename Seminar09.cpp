#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Masina
{
private:
	string producator;
	char* model = nullptr;
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
		model = new char[strlen("N/A") + 1];
		strcpy_s(model, strlen("N/A") + 1, "N/A");
		anFabricatie = 1900;
		pretDeBaza = 300;
	}

	Masina(int serieSasiu, string producator, const char* model) : serieSasiu(serieSasiu)
	{
		this->producator = producator;
		if (model != nullptr)
		{
			this->model = new char[strlen(model) + 1];
			strcpy_s(this->model, strlen(model) + 1, model);
		}

		this->anFabricatie = 1900;
		this->pretDeBaza = 300;
	}

	Masina(int serieSasiu, float pretDeBaza, float* preturiDotariExtra, int nrDotariExtra) : serieSasiu(serieSasiu)
	{
		this->anFabricatie = 1900;
		this->pretDeBaza = pretDeBaza;
		if (preturiDotariExtra != nullptr && nrDotariExtra > 0) 
		{
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
		if (m.model != nullptr)
		{
			this->model = new char[strlen(m.model) + 1];
			strcpy_s(this->model, strlen(m.model) + 1, m.model);
		}
		this->anFabricatie = m.anFabricatie;
		this->pretDeBaza = m.pretDeBaza;

		if (m.preturiDotariExtra != nullptr && m.nrDotariExtra > 0) 
		{
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
		if (preturiDotariExtra != nullptr)
		{
			delete[] preturiDotariExtra;
		}
		if (model != nullptr)
		{
			delete[] model;
		}
	}

	Masina& operator=(const Masina& m)
	{
		if (this != &m)
		{
			if (preturiDotariExtra != nullptr)
			{
				delete[] preturiDotariExtra;
			}
			if (model != nullptr)
			{
				delete[] model;
			}

			this->producator = m.producator;
			if (m.model != nullptr)
			{
				this->model = new char[strlen(m.model) + 1];
				strcpy_s(this->model, strlen(m.model) + 1, m.model);
			}
			else
			{
				this->model = nullptr;
			}
			this->anFabricatie = m.anFabricatie;
			this->pretDeBaza = m.pretDeBaza;

			if (m.preturiDotariExtra != nullptr && m.nrDotariExtra > 0)
			{
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

	string getModel()
	{
		string copie = model;
		return copie;
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

	void serializare()
	{
		ofstream f("masina.bin", ios::binary);
		int lungime = producator.length();
		f.write((char*)&lungime, sizeof(lungime));
		f.write(producator.c_str(), lungime + 1);
		if (model != nullptr)
		{
			lungime = strlen(model);
			f.write((char*)&lungime, sizeof(lungime));
			f.write(model, lungime + 1);
		}
		else
		{
			lungime = 0;
			f.write((char*)&lungime, sizeof(lungime));
		}
		f.write((char*)&anFabricatie, sizeof(anFabricatie));
		f.write((char*)&pretDeBaza, sizeof(pretDeBaza));
		if (nrDotariExtra > 0 && preturiDotariExtra != nullptr)
		{
			f.write((char*)&nrDotariExtra, sizeof(nrDotariExtra));
			for (int i = 0; i < nrDotariExtra; i++)
			{
				f.write((char*)&preturiDotariExtra[i], sizeof(preturiDotariExtra[i]));
			}
		}
		else
		{
			lungime = 0;
			f.write((char*)&lungime, sizeof(lungime));
		}
		f.close();
	}

	void deserializare()
	{
		ifstream f("masina.bin", ios::binary);
		int lungime = 0;
		f.read((char*)&lungime, sizeof(lungime));
		char* p = new char[lungime + 1];
		f.read(p, lungime + 1);
		producator = p;
		delete[]p;
		p = nullptr;
		lungime = 0;
		f.read((char*)&lungime, sizeof(lungime));
		delete[]model;
		if (lungime > 0)
		{
			model = new char[lungime + 1];
			f.read(model, lungime + 1);
		}
		else
		{
			model = nullptr;
		}
		f.read((char*)&anFabricatie, sizeof(anFabricatie));
		f.read((char*)&pretDeBaza, sizeof(pretDeBaza));
		f.read((char*)&nrDotariExtra, sizeof(nrDotariExtra));
		delete[]preturiDotariExtra;
		if (nrDotariExtra > 0)
		{
			preturiDotariExtra = new float[nrDotariExtra];
			for (int i = 0; i < nrDotariExtra; i++)
			{
				f.read((char*)&preturiDotariExtra[i], sizeof(preturiDotariExtra[i]));
			}
		}
		else
		{
			preturiDotariExtra = nullptr;
		}
		f.close();
	}

	bool operator!()
	{
		return preturiDotariExtra != nullptr;

	}

	Masina& operator++()
	{
		this->pretDeBaza += 100;
		return *this;
	}

	Masina operator++(int)
	{
		Masina copie = *this;
		this->pretDeBaza += 100;
		return copie;
	}

	Masina operator*(float valoare)
	{
		Masina copie = *this;
		copie.pretDeBaza = copie.pretDeBaza * valoare;
		return copie;
	}

	float& operator[](int index)
	{
		if (index >= 0 && index < nrDotariExtra)
		{
			return preturiDotariExtra[index];
		}
		throw exception("Index invalid");
	}

	explicit operator int()
	{
		return nrDotariExtra;
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

	friend ostream& operator<<(ostream& out, Masina m);
	friend istream& operator>>(istream& in, Masina& m);
	friend ofstream& operator<<(ofstream& out, Masina m);
};
string Masina::normaPoluare = "euro 6";

void Masina::setAnFabricatie(int anFabricatie)
{
	if (anFabricatie >= 1900 && anFabricatie <= 2025)
	{
		this->anFabricatie = anFabricatie;
	}
}

Masina operator*(float valoare, Masina m)
{
	return m * valoare;
}

ostream& operator<<(ostream& out, Masina m)
{
	out << "Serie sasiu: " << m.serieSasiu << endl;
	out << "Producator: " << m.producator << endl;
	out << "Model: ";
	if (m.model != nullptr)
	{
		out << m.model;
	}
	out << endl;
	out << "An fabricatie: " << m.anFabricatie << endl;
	out << "Pret de baza: " << m.pretDeBaza << endl;
	out << "Nr dotari extra: " << m.nrDotariExtra << endl;
	out << "Preturi dotari extra: ";
	if (m.preturiDotariExtra != nullptr)
	{
		for (int i = 0; i < m.nrDotariExtra; i++)
		{
			out << m.preturiDotariExtra[i] << " ";
		}
	}
	return out;
}

ofstream& operator<<(ofstream& f, Masina m)
{
	if (f.is_open()) 
	{
		f << m.producator << endl;
		if (m.model != nullptr)
		{
			f << m.model;
		}
		f << endl;
		f << m.anFabricatie << endl;
		f << m.pretDeBaza << endl;
		f << m.nrDotariExtra << endl;

		if (m.preturiDotariExtra != nullptr)
		{
			for (int i = 0; i < m.nrDotariExtra; i++)
			{
				f << m.preturiDotariExtra[i] << endl;
			}
		}
	}
	return f;
}

istream& operator>>(istream& in, Masina& m)
{
	cout << "Producator: ";
	getline(in, m.producator);
	cout << "Model: ";
	char buffer[100];
	in.getline(buffer, 99);
	if (m.model != nullptr)
	{
		delete[] m.model;
	}
	m.model = new char[strlen(buffer) + 1];
	strcpy_s(m.model, strlen(buffer) + 1, buffer);
	cout << "An fabricatie: ";
	in >> m.anFabricatie;
	cout << "Pret de baza: ";
	in >> m.pretDeBaza;
	cout << "Nr dotari extra: ";
	in >> m.nrDotariExtra;
	if (m.preturiDotariExtra != nullptr)
	{
		delete[] m.preturiDotariExtra;
	}
	if (m.nrDotariExtra > 0)
	{
		m.preturiDotariExtra = new float[m.nrDotariExtra];
		for (int i = 0; i < m.nrDotariExtra; i++)
		{
			cout << "Pret dotare " << i + 1 << ": ";
			in >> m.preturiDotariExtra[i];
		}
	}
	else
	{
		m.nrDotariExtra = 0;
		m.preturiDotariExtra = nullptr;
	}
	in.ignore();

	return in;
}

class MasinaElectrica : public Masina
{
private:
	int capacitateBaterie;
	char* producatorBaterie = nullptr;
public:

	MasinaElectrica()
	{
		capacitateBaterie = 0;
	}

	MasinaElectrica(string producator, const char* model, int capacitate,
		const char* producatorBaterie) :Masina(1, producator, model)
	{
		this->capacitateBaterie = capacitate;
		if (producatorBaterie != nullptr)
		{
			this->producatorBaterie = new char[strlen(producatorBaterie) + 1];
			strcpy_s(this->producatorBaterie, strlen(producatorBaterie) + 1,
				producatorBaterie);
		}
	}

	MasinaElectrica(const MasinaElectrica& m) : Masina(m)
	{
		this->capacitateBaterie = m.capacitateBaterie;
		if (m.producatorBaterie != nullptr)
		{
			this->producatorBaterie = new char[strlen(m.producatorBaterie) + 1];
			strcpy_s(this->producatorBaterie, strlen(m.producatorBaterie) + 1,
				m.producatorBaterie);
		}
	}

	~MasinaElectrica()
	{
		if (producatorBaterie != nullptr)
		{
			delete[] producatorBaterie;
		}
	}

	MasinaElectrica& operator=(const MasinaElectrica& m)
	{
		if (this != &m)
		{
			Masina::operator=(m);
			if (producatorBaterie != nullptr)
			{
				delete[] producatorBaterie;
				producatorBaterie = nullptr;
			}
			this->capacitateBaterie = m.capacitateBaterie;
			if (m.producatorBaterie != nullptr)
			{
				this->producatorBaterie = new char[strlen(m.producatorBaterie) + 1];
				strcpy_s(this->producatorBaterie, strlen(m.producatorBaterie) + 1,
					m.producatorBaterie);
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, MasinaElectrica e);
	friend istream& operator>>(istream& in, MasinaElectrica& e);
};

ostream& operator<<(ostream& out, MasinaElectrica e) {
	out << (Masina)e;
	out << "Capacitate baterie: " << e.capacitateBaterie << endl;
	out << "Producator baterie: ";

	if (e.producatorBaterie != nullptr) {
		out << e.producatorBaterie;
	}
	out << endl;

	return out;
}

istream& operator>>(istream& in, MasinaElectrica& e) {
	in >> (Masina&)e;
	cout << "Capacitate baterie: ";
	in >> e.capacitateBaterie;
	in.ignore();

	return in;
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
	cout << !m6 << endl;
	m2 = ++m6;
	m1 = m6++;
	m3 = m6 * 2;
	m4 = 1.5 * m6;
	int nrDotari = (int)m6;
	try
	{
		m6[1] = 100;
		cout << m6[1] << endl;
		m6[4] = 400;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Eroare" << endl;
	}
	cin >> m6;
	cout << m6 << endl;

	MasinaElectrica e1;
	MasinaElectrica e2("Dacia", "Spring", 30, "ZTE");
	MasinaElectrica e3 = e2;
	e1 = e2;
	cout << e2;

	cin >> e1;
	cout << e1;

	ofstream f("masina.txt");
	f << m6;
	f.close();

	ifstream g;
	g.open("masina.txt");

	Masina m7;
	g >> m7;
	g.close();

	m6.serializare();

	Masina m8;
	m8.deserializare();
}