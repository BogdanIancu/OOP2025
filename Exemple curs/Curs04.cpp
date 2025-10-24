#include <iostream>
using namespace std;

enum culoare { rosu, galben, albastru };
enum ziLibera { luni = 1, miercuri = 3, vineri = 5 };

union Eticheta
{
	short v1;
	int v2;
	long long v3;
};

struct Carte
{
	int numarPagini;
	float pret;
	char* denumire;
	char* autor;
};

class TelefonMobil
{
public:
	float nivelBaterie;

	TelefonMobil()
	{
		producator = "N/A";
		model = "N/A";
		nivelBaterie = 0;
	}

	TelefonMobil(int _nivelBaterie) :  TelefonMobil()
	{
		nivelBaterie = _nivelBaterie;
	}


	TelefonMobil(string _producator, string _model)
	{
		producator = _producator;
		model = _model;
		nivelBaterie = 0;
	}

	void incarca(float nivelIncarcare)
	{
		nivelBaterie += nivelIncarcare;
	}
protected:
	string producator;
private:
	string model;
};


int main()
{
	culoare c = culoare::rosu;
	ziLibera zi = ziLibera::miercuri;
	zi = (ziLibera)5;
	cout << sizeof(c) << endl;

	Eticheta eticheta;
	eticheta.v3 = 9999999;
	printf("%lld\n", eticheta.v3); printf("%d\n", eticheta.v1); printf("%d\n", eticheta.v2);
	cout << endl;
	eticheta.v2 = 7;
	printf("%lld\n", eticheta.v3); printf("%d\n", eticheta.v1); printf("%d\n", eticheta.v2);
	cout << endl << sizeof(eticheta) << endl;

	Carte carte;
	carte.numarPagini = 200; 
	carte.pret = 99.99;
	carte.denumire = new char[14];
	strcpy_s(carte.denumire, 14, "Harry Potter");
	cout << carte.denumire << endl;
	cout << sizeof(carte) << endl;


	TelefonMobil telefonPersonal;
	telefonPersonal.nivelBaterie = 20;
	telefonPersonal.incarca(50);

	TelefonMobil* pTelefonDeServiciu = new TelefonMobil();
	cout << (*pTelefonDeServiciu).nivelBaterie << endl;
	pTelefonDeServiciu->incarca(20);
	cout << pTelefonDeServiciu->nivelBaterie << endl;
	delete pTelefonDeServiciu;
	pTelefonDeServiciu = nullptr;

	TelefonMobil telefonDeServiciu("Samsung", "S24");

	TelefonMobil* pTelefonPersonal = new TelefonMobil("Apple", "Iphone 17");
	cout << pTelefonPersonal->nivelBaterie << endl;
	//...
	delete pTelefonPersonal;
	pTelefonPersonal = nullptr;

	TelefonMobil t2(75);
	TelefonMobil t3 = 80;
}