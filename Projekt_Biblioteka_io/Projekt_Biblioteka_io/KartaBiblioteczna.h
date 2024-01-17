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
// 	  **Sprawdzanie wszystkich wypo¿yczonych tytu³ów przez danego u¿ytkownika**
// 	 void checkWypozyczenia(const KartaBiblioteczna karta[]) const
//
//	**Zapisywanie danych z karty bibliotecznej do pliku**
//	void saveKartaBiblioteczna() const
// 
// **Sprawdzanie ilosci wpisow na karcie bibliotecznej**
//	int getIloscWpisow() const
// 
// **Usuwanie wpisu**
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

	// Metoda do sprawdzania wszystkich wypo¿yczonych tytu³ów przez danego u¿ytkownika
	void checkWypozyczenia(const KartaBiblioteczna karta[]) const {
		int ilosc = getIloscWpisow();
		std::cout << "Wypo¿yczone tytu³y przez " << Imie << " " << Nazwisko << " (ID: " << IDuzytkownika << "):\n";

		for (int i = 0; i < ilosc; i++) {
			if (karta[i].getIDuzytkownika() == getIDuzytkownika()) {
				std::cout << karta[i].getTytul() << " (ID: " << karta[i].getIDksiazki()<< ")\n";
			}
		}
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

























//	ZASADA DZIA£ANIA - plik posiada linie w formacie: IDuzytkownika|IDksiazki|dataWypozyczenia|dataZwrotu	
//  Zalecam pobieranie danych z pliku do tablicy, w niej trzymane s¹ wszystkie dane, a nastêpnie operowanie na tablicy
// 
//	**Obs³uga klasy karty bibliotecznej**
//	int getIDuzytkownika() { return IDuzytkownika; }
//	void setIDuzytkownika(int noweID) { IDuzytkownika = noweID; }
//	int getIDksiazki() { return IDksiazki; }
//	void setIDksiazki(int noweID) { IDksiazki = noweID; }
//	std::string getDataWypozyczenia() { return dataWypozyczenia; }
//	void setDataWypozyczenia(std::string nowaData) { dataWypozyczenia = nowaData; }
//	std::string getDataZwrotu() { return dataZwrotu; }
//	void setDataZwrotu(std::string nowaData) { dataZwrotu = nowaData; }
//
//	**Dodanie karty bibliotecznej do pliku** (jedna pozycja, np jeœli czytelnik wypo¿yczy³ sobie ksi¹¿kê) 
//	void addKartaBiblioteczna(KartaBiblioteczna kartaBiblioteczna)
//
//	**Pobieranie kart bibliotecznych z pliku**
//	KartaBiblioteczna getKartaBiblioteczna(int IDuzytkownika, int IDksiazki)
//	KartaBiblioteczna* getKartaBibliotecznaTab(int IDuzytkownika) - tworzy tablicê ze wszystkimi pozycjami danego uzytkownika
//
//	**Aktualizacja danych karty bibliotecznej*
//	1. Pobieramy tablicê z wszystkimi pozycjami danego uzytkownika
//	2. W tablicy zmieniamy dane
//	3. Zapisujemy tablicê do pliku
//	void updateKartaBiblioteczna(KartaBiblioteczna* kartaBiblioteczna)



/*	int getIDuzytkownika() { return IDuzytkownika; }
	void setIDuzytkownika(int noweID) { IDuzytkownika = noweID; }

	int getIDksiazki() { return IDksiazki; }
	void setIDksiazki(int noweID) { IDksiazki = noweID; }

	std::string getDataWypozyczenia() { return dataWypozyczenia; }
	void setDataWypozyczenia(std::string nowaData) { dataWypozyczenia = nowaData; }

	std::string getDataZwrotu() { return dataZwrotu; }
	void setDataZwrotu(std::string nowaData) { dataZwrotu = nowaData; }

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

	//tworzenie tablicy ze wszyskimi pozycjami danego uzytkownika
	KartaBiblioteczna* getKartaBibliotecznaTab(int IDuzytkownika)
	{
	std::fstream plik;
		plik.open(PLIK_KARTA_BIBLIOTECZNA, std::ios::in);
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

	//iloœæ pozycji w tablicy Karta Biblioteczna
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
		plik.open(PLIK_KARTA_BIBLIOTECZNA, std::ios::out);
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
		plik.open(PLIK_KARTA_BIBLIOTECZNA, std::ios::out | std::ios::app);
		plik << kartaBiblioteczna.getIDuzytkownika() << "|" << kartaBiblioteczna.getIDksiazki() << "|" << kartaBiblioteczna.getDataWypozyczenia() << "|" << kartaBiblioteczna.getDataZwrotu() << std::endl;
		plik.close();
	}

	void setKartaBiblioteczna(int IDuzytkownika, int IDksiazki, std::string dataWypozyczenia, std::string dataZwrotu)
	{
		std::fstream plik;
		plik.open(PLIK_KARTA_BIBLIOTECZNA, std::ios::out | std::ios::app);
		plik << IDuzytkownika << "|" << IDksiazki << "|" << dataWypozyczenia << "|" << dataZwrotu << std::endl;
		plik.close();
	}

	//pobieranie kart bibliotecznych z pliku 
	KartaBiblioteczna getKartaBiblioteczna(int IDuzytkownika, int IDksiazki)
	{
		std::fstream plik;
		plik.open(PLIK_KARTA_BIBLIOTECZNA, std::ios::in);
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
*/
