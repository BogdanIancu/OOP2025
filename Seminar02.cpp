#include <iostream>
using namespace std;

int main()
{
	int* p = nullptr;
	int x = 5;
	p = &x;
	cout << p << endl;
	cout << *p << endl;
	cout << *(&x) << endl;
	void* t = p;
	cout << *(int*)t << endl;

	int* q = ++p;
	cout << q << endl;

	q = q + 4;
	cout << q << endl;

	int** s = &q;
	cout << s << endl;
	s = s - 4;
	cout << s << endl;

	cout << p - q << endl;

	int& r = x;
	x++;
	cout << r << endl;

	const int dimensiune = 5;
	int v[dimensiune]{ 1, 2, 3, 4, 5 };
	cout << sizeof(v) / sizeof(v[0]) << endl;
	cout << v[3] << endl;
	cout << *(v + 3) << endl;

	int dim = 5;
	int* w = (int*)malloc(dim * sizeof(int));
	w[1] = 100;
	cout << *(w + 1) << endl;
	free(w);
	w = nullptr;

	int* z = new int[5];
	z[1] = 120;
	cout << *(z + 1) << endl;
	delete[] z;
	z = nullptr;
}