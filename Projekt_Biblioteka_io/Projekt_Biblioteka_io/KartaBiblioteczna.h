#pragma once
#include "includy.h"
#include "Ksiazka.h"
#include "Czytelnik.h"
#include "Wypozyczenia.h"

#define PLIK_KARTA_BIBLIOTECZNA "kartabiblioteczna.txt"


class KartaBiblioteczna
{
private:
	int IDuzytkownika;
	std::string Imie;
	std::string Nazwisko;
	int IDksiazki;
	std::string Tytul;
	std::string dataWypozyczenia;
	std::string dataZwrotu;
	

public:

//	**Dodawanie nowego wpisu na kartê biblioteczn¹**
//	void addKartaBiblioteczna(const std::string& imie, const std::string& nazwisko, int iduzytkownika, const std::string& tytul, int idksiazki, const std::string& datawypozyczenia, const std::string& datazwrotu)
//		
//	**Pobieranie stanu wypozyczenia**
//	KartaBiblioteczna getStanWypozyczenia(int IDuzytkownika, int IDksiazki)
//
//	**Edycja danych na karcie bibliotecznej**
//	void editKartaBiblioteczna(const std::string& imie, const std::string& nazwisko, int iduzytkownika,
// 
// 	**Sprawdzanie wszystkich wypo¿yczonych tytu³ów przez danego u¿ytkownika**
// 	void checkWypozyczenia(int IDuzytkownika) 
//
//	**Zapisywanie danych z karty bibliotecznej do pliku**
//	void saveKartaBiblioteczna() const
// 
//	**Sprawdzanie ilosci wpisow na karcie bibliotecznej**
//	int getIloscWpisow() const
// 
//	**Usuwanie wpisu**
//	void deleteWpis(int IDuzytkownika, int IDksiazki)
// 
//	**Pobieranie pojedyñczych danych z wypo¿yczenia**
//	std::string getImie() const
//	std::string getNazwisko() const
//	int getIDuzytkownika() const
//	std::string getTytul() const
//	int getIDksiazki() const
//	std::string getDataWypozyczenia() const
//	std::string getDataZwrotu() const


	// Konstruktor
	KartaBiblioteczna() : IDuzytkownika(0), IDksiazki(0) {}

	// Metoda do dodawania nowego wpisu na kartê biblioteczn¹
	void addKartaBiblioteczna(const std::string& imie, const std::string& nazwisko, int iduzytkownika,
		const std::string& tytul, int idksiazki, const std::string& datawypozyczenia, const std::string& datazwrotu) {
		Imie = imie;
		Nazwisko = nazwisko;
		IDuzytkownika = iduzytkownika;
		Tytul = tytul;
		IDksiazki = idksiazki;
		dataWypozyczenia = datawypozyczenia;
		dataZwrotu = datazwrotu;
	}

	// Metoda do pobierania imienia u¿ytkownika
	std::string getImie() const {
		return Imie;
	}

	// Metoda do pobierania nazwiska u¿ytkownika
	std::string getNazwisko() const {
		return Nazwisko;
	}

	// Metoda do pobierania ID u¿ytkownika
	int getIDuzytkownika() const {
		return IDuzytkownika;
	}

	// Metoda do pobierania nazwy ksi¹¿ki
	std::string getTytul() const {
		return Tytul;
	}

	// Metoda do pobierania ID ksi¹¿ki
	int getIDksiazki() const {
		return IDksiazki;
	}

	// Metoda do pobierania daty wypo¿yczenia
	std::string getDataWypozyczenia() const {
		return dataWypozyczenia;
	}

	// Metoda do pobierania daty zwrotu
	std::string getDataZwrotu() const {
		return dataZwrotu;
	}

	// Metoda do edycji danych na karcie bibliotecznej
	void editKartaBiblioteczna(const std::string& imie, const std::string& nazwisko, int iduzytkownika, const std::string& tytul, int idksiazki, const std::string& datawypozyczenia, const std::string& datazwrotu) {
		Imie = imie;
		Nazwisko = nazwisko;
		IDuzytkownika = iduzytkownika;
		Tytul = tytul;
		IDksiazki = idksiazki;
		dataWypozyczenia = datawypozyczenia;
		dataZwrotu = datazwrotu;
	}

	// Metoda do zapisywania danych z karty bibliotecznej do pliku tekstowego
	void saveKartaBiblioteczna() const {
		std::ofstream file(PLIK_KARTA_BIBLIOTECZNA, std::ios::app);

		if (file.is_open()) {
			file << Imie << "|" << Nazwisko<< "|" << IDuzytkownika << "|"
				<< Tytul << "|" << IDksiazki << "|"
				<< dataWypozyczenia << "|" << dataZwrotu<< "\n";

			//std::cout << "Dane zapisano do pliku.\n";
			file.close();
		}
		else {
			std::cerr << "Nie mo¿na otworzyæ pliku do zapisu.\n";
		}
	}

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

	// Pobieranie stanu wypozyczenia
	KartaBiblioteczna getStanWypozyczenia(int IDuzytkownika, int IDksiazki)
	{
		std::ifstream file(PLIK_KARTA_BIBLIOTECZNA);
		std::string line;
		std::string idString;
		std::string idKsiazkiString;
		std::string dataWypozyczenia;
		std::string dataZwrotu;
		while (std::getline(file, line))
		{
			idString = ZnajdzSubstring(3, line, "|");
			idKsiazkiString = ZnajdzSubstring(5, line, "|");
			if (IDuzytkownika == std::stoi(idString) && IDksiazki == std::stoi(idKsiazkiString))
			{
				dataWypozyczenia = ZnajdzSubstring(6, line, "|");
				dataZwrotu = ZnajdzSubstring(7, line, "|");
				break;
			}
		}
		file.close();
		KartaBiblioteczna kartaBiblioteczna;
		return kartaBiblioteczna;
	}

	// Metoda do sprawdzania wszystkich wypo¿yczonych tytu³ów przez danego u¿ytkownika z pliku
	void checkWypozyczenia(int IDuzytkownika)  {
		std::ifstream file(PLIK_KARTA_BIBLIOTECZNA);
		std::string line;
		std::string idString;
		std::string idKsiazkiString;
		std::string dataWypozyczenia;
		std::string dataZwrotu;
		std::string Tytul;
		while (std::getline(file, line))
		{
			idString = ZnajdzSubstring(3, line, "|");
			if (IDuzytkownika == std::stoi(idString))
			{
				//idKsiazkiString = ZnajdzSubstring(5, line, "|");
				Tytul = ZnajdzSubstring(4, line, "|");
				dataWypozyczenia = ZnajdzSubstring(6, line, "|");
				dataZwrotu = ZnajdzSubstring(7, line, "|");
				std::cout << "Tytyl: " << Tytul << " Data wypozyczenia: " << dataWypozyczenia << " Data zwrotu: " << dataZwrotu << std::endl;
			}
		}
		file.close();

	}

	int getIloscWpisow() const
	{
		std::ifstream file(PLIK_KARTA_BIBLIOTECZNA);
		std::string line;
		int i = 0;
		while (std::getline(file, line))
		{
			i++;
		}
		file.close();
		return i;
	}

// Metoda do usuwania wpisu
	void deleteWpis(int IDuzytkownika, int IDksiazki)
	{
		std::ifstream file(PLIK_KARTA_BIBLIOTECZNA);
		std::string line;
		std::string idString;
		std::string idKsiazkiString;
		std::string dataWypozyczenia;
		std::string dataZwrotu;
		std::ofstream file2("kartabiblioteczna2.txt");
		while (std::getline(file, line))
		{
			idString = ZnajdzSubstring(3, line, "|");
			idKsiazkiString = ZnajdzSubstring(5, line, "|");
			if (IDuzytkownika != std::stoi(idString) || IDksiazki != std::stoi(idKsiazkiString))
			{
				file2 << line << std::endl;
			}
		}
		file.close();
		file2.close();
		remove(PLIK_KARTA_BIBLIOTECZNA);
		rename("kartabiblioteczna2.txt", PLIK_KARTA_BIBLIOTECZNA);
	}

};

