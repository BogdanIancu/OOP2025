#include <iostream>
using namespace std;

class TelefonMobil
{
private:
	string model;
	const int durataMaximaBaterie;
	static int anulFabricatiei;
protected:
	string producator;
public:
	float nivelBaterie;

	TelefonMobil() : durataMaximaBaterie(9)
	{
		producator = "N/A";
		model = "N/A";
		nivelBaterie = 0;
	}

	TelefonMobil(int nivelBaterie) :  TelefonMobil()
	{
		this->nivelBaterie = nivelBaterie;
	}


	TelefonMobil(int durataMaximaBaterie, string _producator, string _model) :
		durataMaximaBaterie(durataMaximaBaterie)
	{
		producator = _producator;
		model = _model;
		nivelBaterie = 0;
	}

	TelefonMobil(const TelefonMobil& t) : durataMaximaBaterie(t.durataMaximaBaterie)
	{
		producator = t.producator;
		model = t.model;
		nivelBaterie = t.nivelBaterie;
	}

	~TelefonMobil()
	{
		cout << "apel destructor" << endl;
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
};
int TelefonMobil::anulFabricatiei = 2025;

void TelefonMobil::incarca(float nivelIncarcare)
{
	nivelBaterie += nivelIncarcare;
}

void f()
{
	static int i = 0;
	cout << i << endl;
	i++;
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

	f(); f(); f();

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

}