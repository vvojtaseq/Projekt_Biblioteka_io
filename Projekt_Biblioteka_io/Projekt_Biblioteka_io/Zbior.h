#pragma once
#include "Autor.h"
#include "Ksiazka.h"
class Zbior
{
};

void addKsiazka(Ksiazka ksiazka, Autor autor);
std::string getTytulFromFiles(unsigned int id);
std::string getAutorFromFiles(unsigned int id);

Ksiazka getKsiazkaFromFiles(unsigned int id);