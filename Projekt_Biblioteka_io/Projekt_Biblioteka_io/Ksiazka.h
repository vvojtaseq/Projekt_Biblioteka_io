#pragma once
#include "includy.h"
class Ksiazka
{
private:
	std::string tytul;
	std::string rokWydania;
	int iloscStron;
	int iloscEgzemplarzy;
public:
	std::string getTytul() { return tytul; }
	void setTytul(std::string nowyTytul) { tytul = nowyTytul; }
	std::string getRokWydania() { return rokWydania; }
	void setRokWydania(std::string nowyRokWydania) { rokWydania = nowyRokWydania; }
	int getIloscStron() { return iloscStron; }

};

