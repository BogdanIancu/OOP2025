#include <iostream>
#include <map>
#include <stack>
using namespace std;


int main()
{
	map<string, int> m;
	m.insert(pair<string, int>("Ionel", 12345));
	m.insert(make_pair("Gigel", 4567));
	m.insert(make_pair("Vasile", 7800));
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	map<string, int>::iterator i = m.find("Ionel");
	cout << (i != m.end() ? i->second : -1) << endl;
	cout << m["Vasile"] << endl;
}

