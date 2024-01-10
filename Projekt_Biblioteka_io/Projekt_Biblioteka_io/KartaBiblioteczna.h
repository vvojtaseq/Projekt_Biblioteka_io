#pragma once
#include "includy.h"
#include "Ksiazka.h"
#include "Czytelnik.h"
#include "Wypozyczenia.h"
class KartaBiblioteczna
{
private:
	int IDurzytkownika;
	int IDksiazki;
	std::string dataWypozyczenia;
	std::string dataZwrotu;

public:

	int getIDuzytkownika() { return IDurzytkownika; }
	void setIDuzytkownika(int noweID) { IDurzytkownika = noweID; }
	int getIDksiazki() { return IDksiazki; }
	void setIDksiazki(int noweID) { IDksiazki = noweID; }
	std::string getDataWypozyczenia() { return dataWypozyczenia; }
	void setDataWypozyczenia(std::string nowaData) { dataWypozyczenia = nowaData; }
	std::string getDataZwrotu() { return dataZwrotu; }
	void setDataZwrotu(std::string nowaData) { dataZwrotu = nowaData; }


};

