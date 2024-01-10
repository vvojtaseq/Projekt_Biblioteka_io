#pragma once
#include "includy.h"
#include "Autor.h"
class Ksiazka : public Autor 
{
private:
	std::string Tytul;
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
	int setID (int noweID) { ID = noweID; }
	int getID() { return ID; }
};

