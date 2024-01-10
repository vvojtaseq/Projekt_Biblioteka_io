#pragma once
#include "Includy.h"
class Autor
{
private:
	std::string Imie;
	std::string Nazwisko;
	std::string Opis;
public:
	std::string getImie() { return Imie; }
	void getImie(std::string noweImie) { Imie = noweImie; }
	std::string getNazwisko() { return Nazwisko; }
	void setNazwisko(std::string noweNazwisko) { Nazwisko = noweNazwisko; }
	std::string getOpis() { return Opis; }
	void setOpis(std::string nowyOpis) { Opis = nowyOpis; }
};

