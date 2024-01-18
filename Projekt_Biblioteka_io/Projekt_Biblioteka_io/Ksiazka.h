#pragma once
#include "includy.h"
#include "Autor.h"
class Ksiazka : public Autor 
{
private:
	std::string Tytul;
	std::string AutorImie;
	std::string AutorNazwisko;
	std::string RokWydania;
	int IloscStron;
	int IloscEgzemplarzy;
	int ID;
public:
	std::string getTytul() { return Tytul; }
	void setTytul(std::string nowyTytul) { Tytul = nowyTytul; }

	std::string getRokWydania() { return RokWydania; }
	void setRokWydania(std::string nowyRokWydania) { RokWydania = nowyRokWydania; }

	int getIloscStron() { return IloscStron; }
	void setIloscStron(int nowaIloscStron) { IloscStron = nowaIloscStron; }

	int getIloscEgzemplarzy() { return IloscEgzemplarzy; }
	void setIloscEgzemplarzy(int nowaIloscEgzemplarzy) { IloscEgzemplarzy = nowaIloscEgzemplarzy; }

	void setID () { 
		std::ifstream plik("ksiazki.txt");
		std::string linia;
		int ostatnieId = 0;

		while (getline(plik, linia))
		{
			std::stringstream ss(linia);
			std::string id;
			getline(ss, id, '|');
			ostatnieId = std::stoi(id);
		}

		plik.close();

		ID = ostatnieId + 1;
	}
	int getID() { return ID; }

	std::string getAutorImie() { return AutorImie; }
	void setAutorImie(std::string noweAutorImie) { AutorImie = noweAutorImie; }

	std::string getAutorNazwisko() { return AutorNazwisko; }
	void setAutorNazwisko(std::string noweAutorNazwisko) { AutorNazwisko = noweAutorNazwisko; }

	Ksiazka(std::string tytul, std::string autorimie, std::string autornazwisko ,std::string rokWydania, int iloscStron, int iloscEgzemplarzy, int id)
	{
		Tytul = tytul;
		AutorImie = autorimie;
		AutorNazwisko = autornazwisko;
		RokWydania = rokWydania;
		IloscStron = iloscStron;
		IloscEgzemplarzy = iloscEgzemplarzy;
		ID = id;
	}
	Ksiazka() {};
};

