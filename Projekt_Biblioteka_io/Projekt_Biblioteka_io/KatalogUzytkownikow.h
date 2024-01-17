#pragma once
#include "Includy.h"
#include "Czytelnik.h"
#include "Bibliotekarz.h"

class KatalogUzytkownikow
{
public:
//  **Metody do dodawania uzytkownikow do plikow**

//  void addCzytelnik(Czytelnik czytelnik);
//	void addBibliotekarz(Bibliotekarz bibliotekarz);
//
//	**Metody do dodawania i pobierania danych z pliku ,,hasla.txt"**
//	void changeHaslo(std::string noweHaslo, unsigned int ID);
//	void setHaslo(unsigned int id, std::string haslo, std::string Email);
//	std::string getHaslo(unsigned int id);
//	bool Autoryzacja(std::string email, std::string haslo);
//	unsigned int getIDFromFiles(std::string email);
//
//	**Metody do pobierania danych z pliku ,,czytelnicy.txt"**
//	std::string getImie(unsigned int id);
//	std::string getNazwisko(unsigned int id);
//	std::string getEmail(unsigned int id);
//	std::string getAdres(unsigned int id);
//	std::string getTelefon(unsigned int id);
//	std::string getPESEL(unsigned int id);
//	int getPowerLevel(unsigned int id);
//
//	**Metody zwracaj¹ca obiekt ze wszytskimi danymi z plików z czytelnikami**
//	Osoba getWszystkieDane(unsigned int id, std::string nazwaPliku);
//	
//	//konstruktor domyslny
	KatalogUzytkownikow() {};

	//sprawdza czy istnieje plik
	bool czyIstniejePlik(std::string nazwaPliku)
	{
		std::fstream plik;
		plik.open(nazwaPliku, std::ios::in);
		if (plik.good() == true)
		{
			plik.close();
			return true;
		}
		else
		{
			plik.close();
			return false;
		}
	}

	//dodawanie uzytkownika do pliku
	void addCzytelnik(Czytelnik czytelnik)
	{
		std::fstream plik;
		plik.open("czytelnicy.txt", std::ios::out | std::ios::app);
		plik << czytelnik.getID() << "|" << czytelnik.getImie() << "|" << czytelnik.getNazwisko() << "|" << czytelnik.getEmail() << "|" << czytelnik.getAdres() << "|" << czytelnik.getTelefon() << "|" << czytelnik.getPESEL() << "|" << czytelnik.getPowerLevel() << std::endl;
		plik.close();
	}
	//dodawanie uzytkownika do pliku
	void addBibliotekarz(Bibliotekarz bibliotekarz)
	{
		std::fstream plik;
		plik.open("bibliotekarze.txt", std::ios::out | std::ios::app);
		plik << bibliotekarz.getID() << "|" << bibliotekarz.getImie() << "|" << bibliotekarz.getNazwisko() << "|" << bibliotekarz.getEmail() << "|" << bibliotekarz.getAdres() << "|" << bibliotekarz.getTelefon() << "|" << bibliotekarz.getPESEL() << "|" << bibliotekarz.getPowerLevel() << std::endl;
		plik.close();
	}

	//dodawanie id, hasla i ID do pliku
	void setHaslo(unsigned int id, std::string haslo, std::string email)
	{
		std::fstream plik;
		plik.open("hasla.txt", std::ios::out | std::ios::app);
		plik << id << "|" << haslo << "|" << email << std::endl;
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

	//pobieranie hasla z pliku
	std::string getHaslo(unsigned int id)
	{
		std::fstream plik;
		plik.open("hasla.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string haslo;
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				haslo = ZnajdzSubstring(2, linia, "|");
				return haslo;
			}
		}
		plik.close();
		return "Nie znaleziono hasla";
	}

	//zmiana hasla w pliku
	void changeHaslo(std::string noweHaslo, unsigned int ID)
	{
		std::fstream plik;
		plik.open("hasla.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string haslo;
		std::string noweHasloString = noweHaslo;
		std::string changedID = std::to_string(ID);
		std::string nowaLinia;
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (changedID == idString)
			{
				haslo = ZnajdzSubstring(2, linia, "|");
				nowaLinia = changedID + "|" + noweHasloString + "|" + haslo;
				break;
			}
		}
		plik.close();
		plik.open("hasla.txt", std::ios::out);
		while (getline(plik, linia))
		{
			if (linia != nowaLinia)
			{
				plik << linia << std::endl;
			}
			else
			{
				plik << nowaLinia << std::endl;
			}
		}
		plik.close();
	}

	//Autoryzacja zwraca 1 gdy zgadza siê mail i has³o 
	bool Autoryzacja(std::string email, std::string haslo)
	{
		std::fstream plik;
		plik.open("hasla.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string hasloString;
		std::string emailString;
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, hasloString, '|');
			getline(ss, emailString, '|');
			if (email == emailString && haslo == hasloString)
			{
				return true;
			}
		}
		plik.close();
		return false;
	}


	//pobieranie id z pliku za pomoc¹ maila 
	unsigned int getID(std::string email)
	{
		std::fstream plik;
		plik.open("hasla.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string hasloString;
		std::string emailString;
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, hasloString, '|');
			getline(ss, emailString, '|');
			if (email == emailString)
			{
				return std::stoi(idString);
			}
		}
		plik.close();
		return 0;
	}


	//pobieranie imienia z pliku (String pomiêdzi pierwszym a drugim "|")
	std::string getImie(unsigned int id)
	{
		std::fstream plik;
		plik.open("czytelnicy.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string imie;
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(2, linia, "|");
			}

		}
		plik.close();
		
		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(2, linia, "|");
			}

		}
		plik.close();
		return "Nie znaleziono nazwiska";
	}

	//pobieranie nazwiska z pliku (String pomiêdzi drugim a trzecim "|")
	std::string getNazwisko(unsigned int id)
	{
		std::fstream plik;
		plik.open("czytelnicy.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string nazwisko;
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(3, linia, "|");
			}

		}
		plik.close();

		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(3, linia, "|");
			}

		}
		plik.close();
		return "Nie znaleziono imienia";
		

	}

	std::string getEmail(unsigned int id)
	{
		std::fstream plik;
		plik.open("czytelnicy.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string email;
		std::string changedID = std::to_string(id);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(4, linia, "|");
			}

		}
		plik.close();

		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(4, linia, "|");
			}

		}
		plik.close();
		return "Nie znaleziono emaila";
	}

	std::string getAdres(unsigned int id)
	{
		std::fstream plik;
		plik.open("czytelnicy.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string adres;
		std::string changedID = std::to_string(id);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(5, linia, "|");
			}

		}
		plik.close();

		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(5, linia, "|");
			}

		}
		plik.close();
		return "Nie znaleziono adresu";
	}

	std::string getTelefon(unsigned int id)
	{
		std::fstream plik;
		plik.open("czytelnicy.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string telefon;
		std::string changedID = std::to_string(id);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(6, linia, "|");
			}

		}
		plik.close();

		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(6, linia, "|");
			}

		}
		plik.close();
		return "Nie znaleziono telefonu";
	}

	std::string getPESEL(unsigned int id)
	{
		std::fstream plik;
		plik.open("czytelnicy.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string pesel;
		std::string changedID = std::to_string(id);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(7, linia, "|");
			}

		}
		plik.close();

		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return ZnajdzSubstring(7, linia, "|");
			}

		}
		plik.close();
		return "Nie znaleziono peselu";
	}

	int getPowerLevel(unsigned int id)
	{
		std::fstream plik;
		plik.open("czytelnicy.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string powerlevel;
		std::string changedID = std::to_string(id);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return std::stoi(ZnajdzSubstring(8, linia, "|"));
			}

		}
		plik.close();

		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				return std::stoi(ZnajdzSubstring(8, linia, "|"));
			}

		}
		plik.close();
		return -1;
	}

	//funkcja do pobierania wszystkich danych uzytkownika z pliku
	Osoba getWszystkieDane(unsigned int id, std::string nazwaPliku)
	{
		Osoba osoba;
		std::fstream plik;
		plik.open(nazwaPliku, std::ios::in);
		std::string linia;
		std::string idString;
		std::string imie;
		std::string nazwisko;
		std::string email;
		std::string adres;
		std::string telefon;
		std::string pesel;
		std::string powerlevel;

		while (getline(plik, linia))
		{
			idString = ZnajdzSubstring(1, linia, "|");
			if (id == std::stoi(idString))
			{
				imie = ZnajdzSubstring(2, linia, "|");
				nazwisko = ZnajdzSubstring(3, linia, "|");
				email = ZnajdzSubstring(4, linia, "|");
				adres = ZnajdzSubstring(5, linia, "|");
				telefon = ZnajdzSubstring(6, linia, "|");
				pesel = ZnajdzSubstring(7, linia, "|");
				powerlevel = ZnajdzSubstring(8, linia, "|");
				osoba.setImie(imie);
				osoba.setNazwisko(nazwisko);
				osoba.setEmail(email);
				osoba.setAdres(adres);
				osoba.setTelefon(telefon);
				osoba.setPESEL(pesel);
				osoba.setPowerLevel(std::stoi(powerlevel));
				return osoba;
			}
		}

	}

};