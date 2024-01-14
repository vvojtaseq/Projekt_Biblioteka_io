#pragma once
#include "Includy.h"
#include "Czytelnik.h"
#include "Bibliotekarz.h"

class KatalogUzytkownikow
{
public:
	//Tutaj ma byc baza danych wszystkich uzytkownikow, mysle ze tu powinni byc i bibliotekarze i uzytkownicy
	//mozna tu uzyc power level i np osoba z power level 2 ma dostep do uzytkownikow z level 1 i 0
	//uzytkownicy czyli power level 0 nie powinni miec do niczego dostepu

//funkcje do dodawania uzytkownikow do plikow
/*	void addCzytelnik(Czytelnik czytelnik);
	void addBibliotekarz(Bibliotekarz bibliotekarz);

	//funkcje do dodawania i pobierania danych z pliku ,,hasla.txt"
	void changeHaslo(std::string noweHaslo, unsigned int ID);
	void setHaslo(unsigned int id, std::string haslo, std::string Email);
	std::string getHaslo(unsigned int id);
	bool Autoryzacja(std::string email, std::string haslo);
	unsigned int getIDFromFiles(std::string email);

	//funkcje do pobierania danych z pliku ,,czytelnicy.txt"
	std::string getImie(unsigned int id);
	std::string getNazwisko(unsigned int id);
	std::string getEmail(unsigned int id);
	std::string getAdres(unsigned int id);
	std::string getTelefon(unsigned int id);
	std::string getPESEL(unsigned int id);
	int getPowerLevel(unsigned int id);

	//funkcja zwracaj¹ca obiekt ze wszytskimi danymi z plików z czytelnikami 
	Osoba getWszystkieDane(unsigned int id, std::string nazwaPliku);
	*/
	//konstruktor domyslny
	KatalogUzytkownikow() {};
	

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
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, haslo, '|');
			if (id == std::stoi(idString))
			{
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
		std::vector<std::string> hasla;
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, haslo, '|');
			if (ID == std::stoi(idString))
			{
				hasla.push_back(idString + "|" + noweHaslo);
			}
			else
			{
				hasla.push_back(idString + "|" + haslo);
			}
		}
		plik.close();
		plik.open("hasla.txt", std::ios::out);
		for (int i = 0; i < hasla.size(); i++)
		{
			plik << hasla[i] << std::endl;
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
		return -1;
	}


	//pobieranie imienia z pliku 
	std::string getImie(unsigned int id)
	{
		std::fstream plik;
		plik.open("czytelnicy.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string imie;
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, imie, '|');
			if (id == std::stoi(idString))
			{
				return imie;
			}
		}
		plik.close();
		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, imie, '|');
			if (id == std::stoi(idString))
			{
				return imie;
			}
		}
		plik.close();
		return "Nie znaleziono imienia";
	}

	//pobieranie nazwiska z pliku
	std::string getNazwisko(unsigned int id)
	{
		std::fstream plik;
		plik.open("czytelnicy.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string nazwisko;
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, nazwisko, '|');
			if (id == std::stoi(idString))
			{
				return nazwisko;
			}
		}
		plik.close();
		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, nazwisko, '|');
			if (id == std::stoi(idString))
			{
				return nazwisko;
			}
		}
		plik.close();
		return "Nie znaleziono nazwiska";
	}

	std::string getEmail(unsigned int id)
	{
		std::fstream plik;
		plik.open("czytelnicy.txt", std::ios::in);
		std::string linia;
		std::string idString;
		std::string email;
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, email, '|');
			if (id == std::stoi(idString))
			{
				return email;
			}
		}
		plik.close();
		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, email, '|');
			if (id == std::stoi(idString))
			{
				return email;
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
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, adres, '|');
			if (id == std::stoi(idString))
			{
				return adres;
			}
		}
		plik.close();
		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, adres, '|');
			if (id == std::stoi(idString))
			{
				return adres;
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
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, telefon, '|');
			if (id == std::stoi(idString))
			{
				return telefon;
			}
		}
		plik.close();
		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, telefon, '|');
			if (id == std::stoi(idString))
			{
				return telefon;
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
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, pesel, '|');
			if (id == std::stoi(idString))
			{
				return pesel;
			}
		}
		plik.close();
		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, pesel, '|');
			if (id == std::stoi(idString))
			{
				return pesel;
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
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, powerlevel, '|');
			if (id == std::stoi(idString))
			{
				return std::stoi(powerlevel);
			}
		}
		plik.close();
		plik.open("bibliotekarze.txt", std::ios::in);
		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, powerlevel, '|');
			if (id == std::stoi(idString))
			{
				return std::stoi(powerlevel);
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
			std::stringstream ss(linia);
			getline(ss, idString, '|');
			getline(ss, imie, '|');
			getline(ss, nazwisko, '|');
			getline(ss, email, '|');
			getline(ss, adres, '|');
			getline(ss, telefon, '|');
			getline(ss, pesel, '|');
			getline(ss, powerlevel, '|');
			if (id == std::stoi(idString))
			{
				osoba.setID(id);
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