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

//	**Obs³uga karty bibliotecznej**
//	int getIDuzytkownika() { return IDuzytkownika; }
//	void setIDuzytkownika(int noweID) { IDuzytkownika = noweID; }
//	int getIDksiazki() { return IDksiazki; }
//	void setIDksiazki(int noweID) { IDksiazki = noweID; }
//	std::string getDataWypozyczenia() { return dataWypozyczenia; }
//	void setDataWypozyczenia(std::string nowaData) { dataWypozyczenia = nowaData; }
//	std::string getDataZwrotu() { return dataZwrotu; }
//	void setDataZwrotu(std::string nowaData) { dataZwrotu = nowaData; }

//	**Zapisywanie karty bibliotecznej do pliku**
//	void addKartaBiblioteczna(KartaBiblioteczna kartaBiblioteczna)

//	**Pobieranie kart bibliotecznych z pliku**
//	KartaBiblioteczna getKartaBiblioteczna(int id)

	int getIDuzytkownika() { return IDuzytkownika; }
	void setIDuzytkownika(int noweID) { IDuzytkownika = noweID; }

	int getIDksiazki() { return IDksiazki; }
	void setIDksiazki(int noweID) { IDksiazki = noweID; }

	std::string getDataWypozyczenia() { return dataWypozyczenia; }
	void setDataWypozyczenia(std::string nowaData) { dataWypozyczenia = nowaData; }

	std::string getDataZwrotu() { return dataZwrotu; }
	void setDataZwrotu(std::string nowaData) { dataZwrotu = nowaData; }

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
	KartaBiblioteczna getKartaBiblioteczna(int id)
	{
		std::fstream plik;
		plik.open("kartabiblioteczna.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string idKsiazkiString;
		std::string dataWypozyczenia;
		std::string dataZwrotu;
		KartaBiblioteczna kartaBiblioteczna;
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, idKsiazkiString, '|');
			getline(ss, dataWypozyczenia, '|');
			getline(ss, dataZwrotu, '|');
			if (id == std::stoi(idString))
			{
				kartaBiblioteczna.setIDuzytkownika(std::stoi(idString));
				kartaBiblioteczna.setIDksiazki(std::stoi(idKsiazkiString));
				kartaBiblioteczna.setDataWypozyczenia(dataWypozyczenia);
				kartaBiblioteczna.setDataZwrotu(dataZwrotu);
				return kartaBiblioteczna;
			}
		}
		plik.close();
		return kartaBiblioteczna;
	}
	
	//Konstruktor domyœlny
	//KartaBiblioteczna ();
};

