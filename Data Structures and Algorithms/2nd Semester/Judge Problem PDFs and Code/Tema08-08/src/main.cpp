#include "List.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

void mezclar(List<int> l1, List<int> l2, List<int> &unir)
{
	List<int>::Iterator it1 = l1.begin(), it2 = l2.begin();
	List<int>::Iterator itEnd1 = l2.end(), itEnd2 = l2.end();

	while(it1 != itEnd1 || it2 != itEnd2)
	{
		if(it1 != itEnd1 && it2 != itEnd2)
		{
			if(it1.elem() < it2.elem())
			{
				unir.push_back(it1.elem());
				++it1;
			}
			else
			{
				unir.push_back(it2.elem());
				++it2;
			}
		}
		else if(it1 != itEnd1)
		{
			unir.push_back(it1.elem());
			++it1;
		}
		else
		{
			unir.push_back(it2.elem());
			++it2;
		}
	}
}

void imprimir(List<int> l)
{
	List<int>::Iterator it = l.begin();
	List<int>::Iterator itEnd = l.end();

	while (it != itEnd)
	{
		cout << it.elem() << " ";
		++it;
	}
}

void resuelveCaso()
{
	List<int> l1,l2, unir;
	int aux;
	char c;
	string a;
	getline(cin, a);

	/*
	 * cin.get(c);
	 * c = cin.peek();
	 */

	c = cin.peek();

	while(c != '\n')
	{
		cin >> aux;
		l1.push_back(aux);

		c = cin.peek();
	}

	cin.get(c);
	c = cin.peek();

	while(c != '\n')
	{
		cin >> aux;
		l2.push_back(aux);

		c = cin.peek();
	}

	mezclar(l1, l2, unir);
	imprimir(unir);

	cout << endl;
}

int main()
{
	int nCasos;
	cin >> nCasos;

	for(int i = 0; i < nCasos; i++)
		resuelveCaso();
	return 0;
}
