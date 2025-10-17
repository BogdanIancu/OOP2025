#include <iostream>
#include <string>
#define true false
using namespace std;

void oglindit(char** sir)
{
	if (sir != nullptr && *sir != nullptr) {
		char* copie = new char[strlen(*sir) + 1];
		for (int i = 0; i < strlen(*sir); i++)
		{
			copie[strlen(*sir) - i - 1] = (*sir)[i];
		}
		copie[strlen(*sir)] = '\0';
		delete[] *sir;
		*sir = copie;
	}
}

void oglinditV2(char*& sir)
{
	if (sir != nullptr) {
		char* copie = new char[strlen(sir) + 1];
		for (int i = 0; i < strlen(sir); i++)
		{
			copie[strlen(sir) - i - 1] = (sir)[i];
		}
		copie[strlen(sir)] = 0;
		delete[] sir;
		sir = copie;
	}
}

int main()
{
	string x = "ceva";
	const char* copieX = x.c_str();

	char* sir = new char[strlen(copieX) + 1];
	strcpy_s(sir, strlen(copieX) + 1, copieX);

	char* copieSir = sir;
	copieSir[0] = 'C';
	cout << sir << endl;

	oglindit(&sir);
	cout << "Oglindit: " << sir << endl;

	string s = sir;
	delete[] sir;
	sir = nullptr;
	copieSir = nullptr;

#undef true

	bool ok = true;

#if _DEBUG
	if (ok)
	{
		cout << "OK";
	}
#endif
}