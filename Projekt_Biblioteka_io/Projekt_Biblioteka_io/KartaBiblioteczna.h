#pragma once
#include "includy.h"
#include "Ksiazka.h"
#include "Czytelnik.h"
#include "Wypozyczenia.h"
class KartaBiblioteczna
{
private:
	int IDuzytkownika;
	int IDksiazki;
	std::string dataWypozyczenia;
	std::string dataZwrotu;

public:

//	ZASADA DZIA�ANIA - plik posiada linie w formacie: IDuzytkownika|IDksiazki|dataWypozyczenia|dataZwrotu	
//  Zalecam pobieranie danych z pliku do tablicy, w niej trzymane s� wszystkie dane, a nast�pnie operowanie na tablicy
// 
//	**Obs�uga klasy karty bibliotecznej**
//	int getIDuzytkownika() { return IDuzytkownika; }
//	void setIDuzytkownika(int noweID) { IDuzytkownika = noweID; }
//	int getIDksiazki() { return IDksiazki; }
//	void setIDksiazki(int noweID) { IDksiazki = noweID; }
//	std::string getDataWypozyczenia() { return dataWypozyczenia; }
//	void setDataWypozyczenia(std::string nowaData) { dataWypozyczenia = nowaData; }
//	std::string getDataZwrotu() { return dataZwrotu; }
//	void setDataZwrotu(std::string nowaData) { dataZwrotu = nowaData; }
//
//	**Dodanie karty bibliotecznej do pliku** (jedna pozycja, np je�li czytelnik wypo�yczy� sobie ksi��k�) 
//	void addKartaBiblioteczna(KartaBiblioteczna kartaBiblioteczna)
//
//	**Pobieranie kart bibliotecznych z pliku**
//	KartaBiblioteczna getKartaBiblioteczna(int IDuzytkownika, int IDksiazki)
//	KartaBiblioteczna* getKartaBibliotecznaTab(int IDuzytkownika) - tworzy tablic� ze wszystkimi pozycjami danego uzytkownika
//
//	**Aktualizacja danych karty bibliotecznej*
//	1. Pobieramy tablic� z wszystkimi pozycjami danego uzytkownika
//	2. W tablicy zmieniamy dane
//	3. Zapisujemy tablic� do pliku
//	void updateKartaBiblioteczna(KartaBiblioteczna* kartaBiblioteczna)



	int getIDuzytkownika() { return IDuzytkownika; }
	void setIDuzytkownika(int noweID) { IDuzytkownika = noweID; }

	int getIDksiazki() { return IDksiazki; }
	void setIDksiazki(int noweID) { IDksiazki = noweID; }

	std::string getDataWypozyczenia() { return dataWypozyczenia; }
	void setDataWypozyczenia(std::string nowaData) { dataWypozyczenia = nowaData; }

	std::string getDataZwrotu() { return dataZwrotu; }
	void setDataZwrotu(std::string nowaData) { dataZwrotu = nowaData; }

	//dzieli string ze wzgl�du na podany znak i zwraca wybrany string
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

	//tworzenie tablicy ze wszyskimi pozycjami danego uzytkownika
	KartaBiblioteczna* getKartaBibliotecznaTab(int IDuzytkownika)
	{
	std::fstream plik;
		plik.open("kartabiblioteczna.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string idKsiazkiString;
		std::string dataWypozyczenia;
		std::string dataZwrotu;
		int i = 0;
		KartaBiblioteczna* kartaBiblioteczna = new KartaBiblioteczna;
		//kartaBiblioteczna = NULL;
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			std::cout << idString << std::endl;
			if (IDuzytkownika == std::stoi(idString))
			{
				i++;
				std::cout << "Dodano: "<< i << std::endl;
				idKsiazkiString = ZnajdzSubstring(2, linia, "|");
				dataWypozyczenia = ZnajdzSubstring(3, linia, "|");
				dataZwrotu = ZnajdzSubstring(4, linia, "|");
				kartaBiblioteczna[i].setIDuzytkownika(std::stoi(idString));
				kartaBiblioteczna[i].setIDksiazki(std::stoi(idKsiazkiString));
				kartaBiblioteczna[i].setDataWypozyczenia(dataWypozyczenia);
				kartaBiblioteczna[i].setDataZwrotu(dataZwrotu);
				
			}
		}
		plik.close();
		return kartaBiblioteczna;

	}

	//ilo�� pozycji w tablicy Karta Biblioteczna
	int getIloscPozycji(KartaBiblioteczna* kartaBiblioteczna)
	{
		int i = 0;
		while (kartaBiblioteczna[i].getIDuzytkownika() != 0)
		{
			std::cout << "Zliczanie: " << i << std::endl;
			i++;
		}
		return i;
	}

	//nadpisanie pozycji konkretnego uzytkownika w pliku
	void updateKartaBiblioteczna(KartaBiblioteczna* kartaBiblioteczna)
	{
		std::fstream plik;
		plik.open("kartabiblioteczna.txt", std::ios::out);
		std::string linia;
		std::string idString;
		while (getline(plik, linia))
		{
			if (kartaBiblioteczna->getIDuzytkownika() == std::stoi(ZnajdzSubstring(1, linia, "|")))
			{
				plik << kartaBiblioteczna->getIDuzytkownika() << "|" << kartaBiblioteczna->getIDksiazki() << "|" << kartaBiblioteczna->getDataWypozyczenia() << "|" << kartaBiblioteczna->getDataZwrotu() << std::endl;
			}
		}
		plik.close();
	}


	//zapisywanie karty bibliotecznej do pliku
	void addKartaBiblioteczna(KartaBiblioteczna kartaBiblioteczna)
	{
		std::fstream plik;
		plik.open("kartabiblioteczna.txt", std::ios::out | std::ios::app);
		plik << kartaBiblioteczna.getIDuzytkownika() << "|" << kartaBiblioteczna.getIDksiazki() << "|" << kartaBiblioteczna.getDataWypozyczenia() << "|" << kartaBiblioteczna.getDataZwrotu() << std::endl;
		plik.close();
	}

	void setKartaBiblioteczna(int IDuzytkownika, int IDksiazki, std::string dataWypozyczenia, std::string dataZwrotu)
	{
		std::fstream plik;
		plik.open("kartabiblioteczna.txt", std::ios::out | std::ios::app);
		plik << IDuzytkownika << "|" << IDksiazki << "|" << dataWypozyczenia << "|" << dataZwrotu << std::endl;
		plik.close();
	}

	//pobieranie kart bibliotecznych z pliku 
	KartaBiblioteczna getKartaBiblioteczna(int IDuzytkownika, int IDksiazki)
	{
		std::fstream plik;
		plik.open("kartabiblioteczna.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string idKsiazkiString;
		std::string dataWypozyczenia;
		std::string dataZwrotu;
		while (getline(plik, linia))
		{
idString = ZnajdzSubstring(1, linia, "|");
			idKsiazkiString = ZnajdzSubstring(2, linia, "|");
			if (IDuzytkownika == std::stoi(idString) && IDksiazki == std::stoi(idKsiazkiString))
			{
				dataWypozyczenia = ZnajdzSubstring(3, linia, "|");
				dataZwrotu = ZnajdzSubstring(4, linia, "|");
				break;
			}
		}
		plik.close();
		KartaBiblioteczna kartaBiblioteczna;
		return kartaBiblioteczna;
		
	}

	


};

