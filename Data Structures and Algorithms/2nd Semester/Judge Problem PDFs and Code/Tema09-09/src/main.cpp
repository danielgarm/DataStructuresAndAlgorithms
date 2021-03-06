#include "Arbin.h"
#include "List.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

Arbin<int> reconstruir(vector<int> const &postorden, vector<int> const &inorden, int postIni, int postFin, int inIni, int inFin)
{
	if (postFin < postIni) // no hay nada
		return Arbin<int>();
	else if (postFin == postIni)
		return Arbin<int>(postorden.at(postIni));
	else
	{
		int PIzIni, PIzFin;
		int PDrIni, PDrFin;
		int IIzIni, IIzFin;
		int IDrIni, IDrFin;

		int raiz = postorden.at(postFin);
		int pos = inIni;

		while (inorden.at(pos) != raiz)
			++pos;
		// Calcular indices de preorden
		PIzIni = postIni;
		PIzFin = postIni + (pos - inIni - 1);
		PDrIni = PIzFin + 1;
		PDrFin = postFin - 1;

		// Calcular indices de inorden
		IIzIni = inIni;
		IIzFin = pos - 1;
		IDrIni = pos + 1;
		IDrFin = inFin;
		Arbin<int> a1 = reconstruir(postorden, inorden, PIzIni, PIzFin, IIzIni, IIzFin);
		Arbin<int> a2 = reconstruir(postorden, inorden, PDrIni, PDrFin, IDrIni, IDrFin);

		return Arbin<int>(a1, raiz, a2);
	}
}

template <class T>
void mostrar(List<T>* const& l)
{
	typename List<T>::ConstIterator it = l->cbegin();
	typename List<T>::ConstIterator itFin = l->cend();

	if (it != itFin)
	{
		cout << *it;
		++it;
	}
	while (it != itFin)
	{
		cout << ' ' << *it;
		++it;
	}
}

bool resuelveCaso()
{
	vector<int> postorden;
	vector<int> inorden;
	int aux;

	cin >> aux;
	if (!cin)
		return false;

	while (aux != -1)
	{
		postorden.push_back(aux);
		cin >> aux;
	}
	cin >> aux;

	while (aux != -1)
	{
		inorden.push_back(aux);
		cin >> aux;
	}
	Arbin<int> a = reconstruir(postorden, inorden, 0, postorden.size() - 1, 0, inorden.size() - 1);
	List<int>* l = a.niveles();

	if (postorden.size() > 0)
	{
		mostrar(l);
		cout << '\n';
	}

	return true;
}

int main()
{
	while (resuelveCaso());
	return 0;
}


