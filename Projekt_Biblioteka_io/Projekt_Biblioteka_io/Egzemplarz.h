#pragma once
#include "Includy.h"
#include "Ksiazka.h"
class Egzemplarz : public Ksiazka
{
private:
	int Identyfikator;
	bool StatusWypozyczenia;
public:
	int getIdentyfikator() { return Identyfikator; }
	void setIdentyfikator(int nowyIdentyfikator) { Identyfikator = nowyIdentyfikator; }
	bool getStatusWypozyczenia() { return StatusWypozyczenia; }
	void changeStatusWypozyczenia() { StatusWypozyczenia = not StatusWypozyczenia; }

};

