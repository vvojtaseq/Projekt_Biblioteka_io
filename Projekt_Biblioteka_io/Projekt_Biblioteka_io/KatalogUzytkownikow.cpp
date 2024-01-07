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

void addHaslo(std::string haslo, Osoba osoba)
{
	//dodawanie hasla do pliku
	std::fstream plik;
	plik.open("hasla.txt", std::ios::out | std::ios::app);
	plik << osoba.getID() << "|" << haslo << std::endl;
	plik.close();
}

void changeHaslo(std::string noweHaslo, Osoba osoba)
{

	std::fstream plik;
	plik.open("hasla.txt", std::ios::in);
	std::string linia;
	std::string id;
	std::string haslo;
	std::string nowyPlik;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, id, '|');
		getline(ss, haslo, '|');
		if (id == std::to_string(osoba.getID()))
		{
			haslo = noweHaslo;
		}
		nowyPlik += id + "|" + haslo + "\n";
	}
	plik.close();
	plik.open("hasla.txt", std::ios::out);
	plik << nowyPlik;
	plik.close();
}




