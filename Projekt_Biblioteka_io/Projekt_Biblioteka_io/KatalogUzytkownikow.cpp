#include "KatalogUzytkownikow.h"
#include "IncludyKlasy.h"

void addCzytelnik (Czytelnik czytelnik)
{
	//dodawanie uzytkownika do pliku
	std::fstream plik;
	plik.open("czytelnicy.txt", std::ios::out | std::ios::app);
	plik << czytelnik.getID() << "|" << czytelnik.getImie() << "|" << czytelnik.getNazwisko() << "|" << czytelnik.getEmail() << "|" << czytelnik.getAdres() << "|" << czytelnik.getTelefon() << "|" << czytelnik.getPESEL() << "|" << czytelnik.getPowerLevel() << std::endl;
	plik.close();
}

void addBibliotekarz (Bibliotekarz bibliotekarz)
{
	//dodawanie uzytkownika do pliku
	std::fstream plik;
	plik.open("bibliotekarze.txt", std::ios::out | std::ios::app);
	plik << bibliotekarz.getID() << "|" << bibliotekarz.getImie() << "|" << bibliotekarz.getNazwisko() << "|" << bibliotekarz.getEmail() << "|" << bibliotekarz.getAdres() << "|" << bibliotekarz.getTelefon() << "|" << bibliotekarz.getPESEL() << "|" << bibliotekarz.getPowerLevel() << std::endl;
	plik.close();
}

void addHaslo(std::string haslo, unsigned int ID)
{
	std::fstream plik;
	plik.open("hasla.txt", std::ios::out | std::ios::app);
	plik << ID << "|" << haslo << std::endl;
	plik.close();
}

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

std::string getImieFromFiles(unsigned int id)
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



