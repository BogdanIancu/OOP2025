#include <iostream>
#include <set>
#include <map>
#include <stack>
using namespace std;

class Masina
{
public:
	string producator;
	int anFabricatie = 0;
};

bool operator<(const Masina& m1, const Masina& m2)
{
	return m1.anFabricatie < m2.anFabricatie;
}

int main()
{
	set<int> s;
	s.insert(4);
	s.insert(2);
	s.insert(7);

	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<Masina> s2;
	Masina m1;
	m1.producator = "Dacia";
	m1.anFabricatie = 2024;
	Masina m2;
	m2.producator = "Renault";
	m2.anFabricatie = 2020;
	s2.insert(m1);
	s2.insert(m2);

	for (Masina m : s2)
	{
		cout << m.anFabricatie << " " << m.producator << endl;
	}

	map<string, int> m;
	m.insert(make_pair("Ionel", 12));
	m.insert(pair<string, int>("Gigel", 10));

	cout << m["Gigel"] << endl;

	stack<int> st;
	st.push(4);
	st.push(2);
	st.push(7);

	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
}