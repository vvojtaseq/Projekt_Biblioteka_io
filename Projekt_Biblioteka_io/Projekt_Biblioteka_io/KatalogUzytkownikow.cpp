#include "KatalogUzytkownikow.h"
#include "IncludyKlasy.h"

void addCzytelnik (Czytelnik czytelnik)
{
	//dodawanie uzytkownika do pliku
	std::fstream plik;
	plik.open("czytelnicy.txt", std::ios::out | std::ios::app);
	plik << czytelnik.getID() << "|" << czytelnik.getImie() << "|" << czytelnik.getNazwisko() << "|" << czytelnik.getAdres() << "|" << czytelnik.getTelefon() << "|" << czytelnik.getPESEL() << "|" << czytelnik.getPowerLevel() << std::endl;
	plik.close();
}

void addBibliotekarz (Bibliotekarz bibliotekarz)
{
	//dodawanie uzytkownika do pliku
	std::fstream plik;
	plik.open("bibliotekarze.txt", std::ios::out | std::ios::app);
	plik << bibliotekarz.getID() << "|" << bibliotekarz.getImie() << "|" << bibliotekarz.getNazwisko() << "|" << bibliotekarz.getAdres() << "|" << bibliotekarz.getTelefon() << "|" << bibliotekarz.getPESEL() << "|" << bibliotekarz.getPowerLevel() << std::endl;
	plik.close();
}


void changeHaslo(std::string noweHaslo, unsigned int ID)
{
	//zmiana hasla uzytkownika
	std::fstream plik;
	plik.open("czytelnicy.txt", std::ios::in);
	std::string linia;
	std::string nowaLinia;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		std::string IDString;
		getline(ss, IDString, '|');
		if (std::stoi(IDString) == ID)
		{
			std::string Imie;
			getline(ss, Imie, '|');
			std::string Nazwisko;
			getline(ss, Nazwisko, '|');
			std::string Adres;
			getline(ss, Adres, '|');
			std::string Telefon;
			getline(ss, Telefon, '|');
			std::string PESEL;
			getline(ss, PESEL, '|');
			nowaLinia = IDString + "|" + Imie + "|" + Nazwisko + "|" + Adres + "|" + Telefon + "|" + PESEL + "|" + noweHaslo;
		}
	}
	plik.close();
	plik.open("czytelnicy.txt", std::ios::out);
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
