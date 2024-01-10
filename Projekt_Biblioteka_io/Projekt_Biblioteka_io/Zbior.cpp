#include "Zbior.h"
#include "Autor.h"
#include "Ksiazka.h"

//dodawanie ksiazki do pliku
void addKsiazka(Ksiazka ksiazka, Autor autor)
{
	std::fstream plik;
	plik.open("ksiazki.txt", std::ios::out | std::ios::app);
	plik << ksiazka.getID() << "|" << ksiazka.getTytul() << "|" << autor.getImie() << "|" << autor.getNazwisko() << "|" << ksiazka.getRokWydania() << "|" << ksiazka.getIloscStron() << "|" << ksiazka.getIloscEgzemplarzy() << std::endl;
	plik.close();

}

//pobieranie ksiazek z pliku
std::string getTytulFromFiles(unsigned int IDksiazki)
{
	std::fstream plik;
	plik.open("ksiazki.txt", std::ios::in);
	std::string linia;
	std::string IDksiazkiString;
	std::string tytul;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, IDksiazkiString, '|');
		getline(ss, tytul, '|');
		if (IDksiazki == std::stoi(IDksiazkiString))
		{
			return tytul;
		}
	}
	plik.close();
	return "Nie znaleziono tytulu";
}

//pobieranie autora z pliku
std::string getAutorFromFiles(unsigned int IDksiazki)
{
	std::fstream plik;
	plik.open("ksiazki.txt", std::ios::in);
	std::string linia;
	std::string IDksiazkiString;
	std::string autor;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, IDksiazkiString, '|');
		getline(ss, autor, '|');
		if (IDksiazki == std::stoi(IDksiazkiString))
		{
			return autor;
		}
	}
	plik.close();
	return "Nie znaleziono autora";
}

//pobieranie ksiazek z pliku
Ksiazka getKsiazkaFromFiles(unsigned int IDksiazki)
{
	std::fstream plik;
	plik.open("ksiazki.txt", std::ios::in);
	std::string linia;
	std::string IDksiazkiString;
	std::string tytul;
	std::string autor;
	std::string rokWydania;
	std::string iloscStron;
	std::string iloscEgzemplarzy;
	Ksiazka ksiazka;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, IDksiazkiString, '|');
		getline(ss, tytul, '|');
		getline(ss, autor, '|');
		getline(ss, rokWydania, '|');
		getline(ss, iloscStron, '|');
		getline(ss, iloscEgzemplarzy, '|');
		if (IDksiazki == std::stoi(IDksiazkiString))
		{
			ksiazka.setID(std::stoi(IDksiazkiString));
			ksiazka.setTytul(tytul);
			ksiazka.setAutor(autor);
			ksiazka.setRokWydania(rokWydania);
			ksiazka.setIloscStron(std::stoi(iloscStron));
			ksiazka.setIloscEgzemplarzy(std::stoi(iloscEgzemplarzy));
			return ksiazka;
		}
	}
	plik.close();
	return ksiazka;
}

