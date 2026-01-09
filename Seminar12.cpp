#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

template <typename T>
T suma(T a, T b)
{
	return a + b;
}

template<class T = int, unsigned int size = 100>
class Vector
{
private:
	//static const int size = 100;
	T elemente[size];
public:
	unsigned int getSize()
	{
		return size;
	}

	T& operator[](int index)
	{
		if (index >= 0 && index < size)
		{
			return elemente[index];
		}
		else
		{
			throw exception("index invalid");
		}
	}
};

int main()
{
	cout << suma(2, 3) << endl;
	cout << suma<double>(4.5, 2) << endl;
	cout << suma<string>("alt", "ceva") << endl;

	Vector <short, 4> v1;
	v1[0] = 1;
	v1[1] = 3;
	v1[2] = 4;
	cout << v1[1] << endl;

	Vector <double> v2;
	Vector<> v3;

	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(7);
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.pop_back();
	cout << v.capacity() << endl;

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	list<double> l;
	l.push_back(5.2);
	l.push_front(3.2);
	l.insert(++l.begin(), 4.5);

	for (auto it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	deque<string> d;
	d.push_back("Viorel");
	d.push_front("Gigel");
	d.insert(next(d.begin(), 2), "Ionel");
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << endl;
	}
	cout << endl;

	for (string x : d)
	{
		cout << x << endl;
	}
}