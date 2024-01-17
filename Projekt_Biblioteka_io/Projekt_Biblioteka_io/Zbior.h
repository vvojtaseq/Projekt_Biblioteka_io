#pragma once
#include "Autor.h"
#include "Ksiazka.h"
class Zbior
{
public:
//	
//	void addKsiazka(Ksiazka ksiazka, Autor autor);
//	std::string getTytul(unsigned int id);
//	std::string getAutor(unsigned int id);
//
//	Ksiazka getKsiazka(unsigned int id);
//
// 
//	konstruktor domyslny
	Zbior() {};

	//dodawanie ksiazki do pliku
	void addKsiazka(Ksiazka ksiazka, Autor autor)
	{
		std::fstream plik;
		plik.open("ksiazki.txt", std::ios::out | std::ios::app);
		plik << ksiazka.getID() << "|" << ksiazka.getTytul() << "|" << autor.getImie() << "|" << autor.getNazwisko() << "|" << ksiazka.getRokWydania() << "|" << ksiazka.getIloscStron() << "|" << ksiazka.getIloscEgzemplarzy() << std::endl;
		plik.close();

	}

	//dzieli string ze wzglêdu na podany znak i zwraca wybrany string
	std::string ZnajdzSubstring(int number, std::string line, std::string delimiter)
	{
		std::string requestedSubstring;
		std::string token;
		std::istringstream tokenStream(line);
		int i = 0;
		while (std::getline(tokenStream, token, '|'))
		{
			i++;
			if (i == number)
			{
				requestedSubstring = token;
			}
		}
		return requestedSubstring;
	}

	//pobieranie ksiazek z pliku
	std::string getTytul(unsigned int IDksiazki)
	{
		std::fstream plik;
		plik.open("ksiazki.txt", std::ios::in);
		std::string linia;
		std::string IDksiazkiString;
		std::string tytul;
		while (getline(plik, linia))
		{
			IDksiazkiString = ZnajdzSubstring(1, linia, "|");
			if (IDksiazki == std::stoi(IDksiazkiString))
			{
				tytul = ZnajdzSubstring(2, linia, "|");
				return tytul;
			}
		}
		plik.close();
		return "Nie znaleziono tytulu";
	}

	//pobieranie autora z pliku
	std::string getImieAutora(unsigned int IDksiazki)
	{
		std::fstream plik;
		plik.open("ksiazki.txt", std::ios::in);
		std::string linia;
		std::string IDksiazkiString;
		std::string autorImie;
		while (getline(plik, linia))
		{
			IDksiazkiString = ZnajdzSubstring(1, linia, "|");
			if (IDksiazki == std::stoi(IDksiazkiString))
			{
				autorImie = ZnajdzSubstring(3, linia, "|");
				return autorImie;
			}
		}
		plik.close();
		return "Nie znaleziono imienia autora";
	}

	//pobieranie nazwiska autora z pliku
	std::string getNazwiskoAutora(unsigned int IDksiazki)
	{
			std::fstream plik;
		plik.open("ksiazki.txt", std::ios::in);
		std::string linia;
		std::string IDksiazkiString;
		std::string autorNazwisko;
		while (getline(plik, linia))
		{
			IDksiazkiString = ZnajdzSubstring(1, linia, "|");
			if (IDksiazki == std::stoi(IDksiazkiString))
			{
				autorNazwisko = ZnajdzSubstring(4, linia, "|");
				return autorNazwisko;
			}
		}
		plik.close();
		return "Nie znaleziono nazwiska autora";
	}

	//pobieranie roku wydania z pliku
	std::string getRokWydania(unsigned int IDksiazki)
	{
		std::fstream plik;
		plik.open("ksiazki.txt", std::ios::in);
		std::string linia;
		std::string IDksiazkiString;
		std::string rokWydania;
		while (getline(plik, linia))
		{
			IDksiazkiString = ZnajdzSubstring(1, linia, "|");
			if (IDksiazki == std::stoi(IDksiazkiString))
			{
				rokWydania = ZnajdzSubstring(5, linia, "|");
				return rokWydania;
			}
		}
		plik.close();
		return "Nie znaleziono roku wydania";
	}

	//pobieranie ilosci stron z pliku
	std::string getIloscStron(unsigned int IDksiazki)
	{
		std::fstream plik;
		plik.open("ksiazki.txt", std::ios::in);
		std::string linia;
		std::string IDksiazkiString;
		std::string iloscStron;
		while (getline(plik, linia))
		{
			IDksiazkiString = ZnajdzSubstring(1, linia, "|");
			if (IDksiazki == std::stoi(IDksiazkiString))
			{
				iloscStron = ZnajdzSubstring(6, linia, "|");
				return iloscStron;
			}
		}
		plik.close();
		return "Nie znaleziono ilosci stron";
	}

	//pobieranie ilosci egzemplarzy z pliku
	std::string getIloscEgzemplarzy(unsigned int IDksiazki)
	{
		std::fstream plik;
		plik.open("ksiazki.txt", std::ios::in);
		std::string linia;
		std::string IDksiazkiString;
		std::string iloscEgzemplarzy;
		while (getline(plik, linia))
		{
			IDksiazkiString = ZnajdzSubstring(1, linia, "|");
			if (IDksiazki == std::stoi(IDksiazkiString))
			{
				iloscEgzemplarzy = ZnajdzSubstring(7, linia, "|");
				return iloscEgzemplarzy;
			}
		}
		plik.close();
		return "Nie znaleziono ilosci egzemplarzy";
	}


	//pobieranie ksiazek z pliku
	Ksiazka getKsiazka(unsigned int IDksiazki)
	{
		std::fstream plik;
		plik.open("ksiazki.txt", std::ios::in);
		std::string linia;
		std::string IDksiazkiString;
		std::string tytul;
		std::string autorImie;
		std::string autorNazwisko;
		std::string rokWydania;
		std::string iloscStron;
		std::string iloscEgzemplarzy;
		while (getline(plik, linia))
		{
			IDksiazkiString = ZnajdzSubstring(1, linia, "|");
			if (IDksiazki == std::stoi(IDksiazkiString))
			{
				tytul = ZnajdzSubstring(2, linia, "|");
				autorImie = ZnajdzSubstring(3, linia, "|");
				autorNazwisko = ZnajdzSubstring(4, linia, "|");
				rokWydania = ZnajdzSubstring(5, linia, "|");
				iloscStron = ZnajdzSubstring(6, linia, "|");
				iloscEgzemplarzy = ZnajdzSubstring(7, linia, "|");
				Ksiazka ksiazka = Ksiazka(tytul, autorImie, autorNazwisko, rokWydania, std::stoi(iloscStron), std::stoi(iloscEgzemplarzy), std::stoi(IDksiazkiString));
				return ksiazka;
			}
		}
		plik.close();
		return Ksiazka();
	}


};

