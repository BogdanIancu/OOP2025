#include <iostream>
#include <list>
#include <set>
using namespace std;

class TelefonMobil
{
public:
	string model;
	string producator;
	int durataBaterie = 0;

	bool operator<(const TelefonMobil& t) const
	{
		return this->producator < t.producator;
	}
};

int main()
{
	list<double> l;
	l.push_back(1.5);
	l.push_front(2.5);
	l.insert(++l.begin(), 3.7);
	list<double>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	it = --l.end();
	cout << *it << endl;
	for (list<double>::reverse_iterator iter = l.rbegin();
		iter != l.rend(); iter++)
	{
		cout << *iter << " ";
	}

	cout << endl;
	set<int> s;
	s.insert(1); s.insert(5); s.insert(2); s.insert(7);
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;
	set<int>::iterator i = s.find(55);
	if (i != s.end()) 
	{
		cout << "exista";
	}
	else
	{
		cout << "nu exista";
	}

	cout << endl;
	set<TelefonMobil> s2;
	TelefonMobil t1;
	t1.producator = "Apple";
	TelefonMobil t2;
	t2.producator = "Samsung";
	s2.insert(t2);
	s2.insert(t1);
	for (set<TelefonMobil>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << it->producator << " ";
	}
}

