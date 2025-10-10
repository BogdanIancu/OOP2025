#include <iostream>
using namespace std;

void afisare(void* pointer)
{
	cout << pointer << endl;
}

int main(int argc, char* argv[])
{
	if (argc > 1) 
	{
		cout << "Hello, " << argv[1] << endl;
	}
	else
	{
		cout << "Hello, world!" << endl;
	}

	float* p = nullptr;
	float f = 8.4;
	p = &f;
	afisare(p);
	cout << *p << endl;

	short* q = nullptr;
	q = q + 6;
	short* t = q + 1;
	cout << t - q << endl;

	short a = 10000;
	const short* pc = &a;
	q = (short*)pc;
	*q = 5000;
	cout << a << endl;
	cout << *pc << endl;

	int v[5];
	cout << sizeof(v) << endl;
	cout << v << endl;

	int* w = (int*)malloc(5 * sizeof(int));
	if (w != nullptr)
	{
		w[1] = 99;
		cout << *(w + 1) << endl;
		free(w);
		w = nullptr;
	}

	int* z = new int[5];
	z[1] = 99;
	//...
	delete[] z;
	z = nullptr;
}