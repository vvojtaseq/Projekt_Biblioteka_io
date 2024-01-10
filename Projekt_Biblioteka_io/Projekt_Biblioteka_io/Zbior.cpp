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
std::string getTytulFromFiles(unsigned int id)
{
	std::fstream plik;
	plik.open("ksiazki.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string tytul;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, tytul, '|');
		if (id == std::stoi(idString))
		{
			return tytul;
		}
	}
	plik.close();
	return "Nie znaleziono tytulu";
}

//pobieranie autora z pliku
std::string getAutorFromFiles(unsigned int id)
{
	std::fstream plik;
	plik.open("ksiazki.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string autor;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, autor, '|');
		if (id == std::stoi(idString))
		{
			return autor;
		}
	}
	plik.close();
	return "Nie znaleziono autora";
}