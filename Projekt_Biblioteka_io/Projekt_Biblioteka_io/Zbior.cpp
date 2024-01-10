#include "Zbior.h"
#include "Autor.h"
#include "Ksiazka.h"

void addKsiazka(Ksiazka ksiazka, Autor autor)
{
	std::fstream plik;
	plik.open("ksiazki.txt", std::ios::out | std::ios::app);
	plik << ksiazka.getID() << "|" << ksiazka.getTytul() << "|" << autor.getImie() << "|" << autor.getNazwisko() << "|" << ksiazka.getRokWydania() << "|" << ksiazka.getIloscStron() << "|" << ksiazka.getIloscEgzemplarzy() << std::endl;
	plik.close();

}

