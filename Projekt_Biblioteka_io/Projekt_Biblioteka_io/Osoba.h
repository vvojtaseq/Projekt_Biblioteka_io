#pragma once
#include "Includy.h"
#define MAXPESEL 99999999999
#define MINPESEL 10000000000
class Osoba
{
private:
	std::string Imie;
	std::string Nazwisko;
	std::string Adres;
	std::string DataUrodzenia;
	unsigned int Telefon; 
	long long PESEL;
	
public:
	//metody 
	//trzeba zrobic metody get i set, set potrzebne do tworzenia uzytkownika, get do logowania i innych klas 
	std::string getImie() { return Imie; }
	void setImie(std::string noweImie) { Imie = noweImie; }
	std::string getNazwisko() { return Nazwisko; }
	void setNazwisko(std::string noweNazwisko) { Nazwisko = noweNazwisko; }
	std::string getAdres() { return Adres; }
	void setAdres(std::string nowyAdres) { Adres = nowyAdres; }
	std::string getDataUrodzenia() { return DataUrodzenia; }
	void setDataUrodzenia(std::string nowaDataUrodzenia) { DataUrodzenia = nowaDataUrodzenia; }
	unsigned int getTelefon() { return Telefon; }
	void setTelefon(unsigned int nowyTelefon) { Telefon = nowyTelefon; }
	long long getPESEL() { return PESEL; }
	void setPESEL(long long nowyPESEL) 
	{
		if (nowyPESEL > MAXPESEL || nowyPESEL < MINPESEL)
		{
			std::cout << "Niepoprawny nr PESEL, wprowadŸ jeszcze raz. \nNowy PESEL : ";
			nowyPESEL = 0;
				std::cin >> nowyPESEL;
				setPESEL(nowyPESEL);
		}
		else
		{
			PESEL = nowyPESEL;
		}
	}
};

