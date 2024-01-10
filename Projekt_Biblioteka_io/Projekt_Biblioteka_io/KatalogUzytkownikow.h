#pragma once
#include "Includy.h"
#include "Czytelnik.h"
#include "Bibliotekarz.h"
	//Tutaj ma byc baza danych wszystkich uzytkownikow, mysle ze tu powinni byc i bibliotekarze i uzytkownicy
	//mozna tu uzyc power level i np osoba z power level 2 ma dostep do uzytkownikow z level 1 i 0
	//uzytkownicy czyli power level 0 nie powinni miec do niczego dostepu


void addCzytelnik(Czytelnik czytelnik);
void addBibliotekarz(Bibliotekarz bibliotekarz);

//funkcje do pobierania danych z plikow z has³ami
void changeHaslo(std::string noweHaslo, unsigned int ID);
void addProtectiontoFiles(unsigned int id, std::string haslo, std::string Email);
std::string getHasloFromFiles(unsigned int id)
 
//funkcje do pobierania danych z plikow z czytelnikami 
std::string getImieFromFiles(unsigned int id);
std::string getNazwiskoFromFiles(unsigned int id);
std::string getEmailFromFiles(unsigned int id);
std::string getAdresFromFiles(unsigned int id);
std::string getTelefonFromFiles(unsigned int id);
std::string getPESELFromFiles(unsigned int id);
int getPowerLevelFromFiles(unsigned int id);

//funkcja zwracaj¹ca obiekt ze wszytskimi danymi z plików z czytelnikami 
Osoba getWszystkieDaneFromFiles(unsigned int id, std::string nazwaPliku);
