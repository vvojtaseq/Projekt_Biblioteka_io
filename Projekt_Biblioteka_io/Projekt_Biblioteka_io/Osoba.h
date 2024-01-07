#pragma once
#include "Includy.h"
#define MAXPESEL 99999999999
#define MINPESEL 1000000000
#define PESELLENGTH 11
class Osoba
{
private:
	std::string Imie;
	std::string Nazwisko;
	std::string Adres;
	std::string DataUrodzenia;
	std::string Telefon;
	std::string PESEL;
	std::string Email;
	
	std::string Haslo;
	int PowerLevel; //0 - czytelnik, 1 - pracownik, 2 - menadzer

public:
	//metody 
	//trzeba zrobic metody get i set, set potrzebne do tworzenia uzytkownika, get do logowania i innych klas 
	std::string getImie() { return Imie; }
	void setImie(std::string noweImie) { Imie = noweImie; }
	std::string getNazwisko() { return Nazwisko; }
	void setNazwisko(std::string noweNazwisko) { Nazwisko = noweNazwisko; }
	std::string getAdres() { return Adres; }
	void setAdres(std::string nowyAdres) { Adres = nowyAdres; }
	std::string getDataUrodzenia() { return DataUrodzenia; }
	void setDataUrodzenia(std::string nowaDataUrodzenia) { DataUrodzenia = nowaDataUrodzenia; }
	std::string getTelefon() { return Telefon; }
	void setTelefon(std::string nowyTelefon) { Telefon = nowyTelefon; }
	std::string getPESEL() { return PESEL; }
	void setPESEL(std::string nowyPESEL) {
		while (true) {
			if (nowyPESEL.length() != PESELLENGTH) {
				std::cout << "Niepoprawna dlugosc numeru PESEL. Wprowadz 11 znakow." << std::endl;
			}
			else if (!std::all_of(nowyPESEL.begin(), nowyPESEL.end(), ::isdigit)) {
				std::cout << "Numer PESEL powinien zawierac tylko cyfry." << std::endl;
			}
			else {
				long long pesel = std::stoll(nowyPESEL);
				if (pesel > MAXPESEL || pesel < MINPESEL) {
					std::cout << "Niepoprawny nr PESEL. Numer PESEL powinien zawierac 11 cyfr." << std::endl;
				}
				else {
					PESEL = nowyPESEL;
					//std::cout << "Nowy pesel to: " << PESEL << std::endl; wyœwietla podczas wprowadzania
					break; // Exit the loop after setting the valid PESEL
				}
			}
			std::cout << "Wprowadz nowy PESEL: ";
			std::cin >> nowyPESEL;
		}
	}

	std::string getHaslo() { return Haslo; }
	void setHaslo(std::string noweHaslo) { Haslo = noweHaslo; }

	void setPowerLevel(int powerlevel) { PowerLevel = powerlevel; };
	int getPowerLevel() { return PowerLevel; };

	void setEmail(std::string email) {
		if (email.find("@") == std::string::npos || email.find(".") == std::string::npos)
		{
			std::cout << "Niepoprawny adres email. Wprowadz ponownie." << std::endl;
			std::cin >> email;
			setEmail(email);

		}
		else
		{
			Email = email;
		}
	}
	std::string getEmail() { return Email; }
};
	/*
	void setPESEL( std::string nowyPESEL) {
		if (nowyPESEL.length() != PESELLENGTH) {
			std::cout << "Niepoprawna dlugosc numeru PESEL. Wprowadz 11 znakow." << std::endl;  
			std::cin >> nowyPESEL;
			setPESEL(nowyPESEL);
		}

		if (!std::all_of(nowyPESEL.begin(), nowyPESEL.end(), ::isdigit)) {
			std::cout << "Numer PESEL powinien zawierac tylko cyfry." << std::endl;
			std::cin >> nowyPESEL;
			setPESEL(nowyPESEL);
		}

		long long pesel = std::stoll(nowyPESEL);

		if (pesel > MAXPESEL || pesel < MINPESEL) {
			std::cout << "Niepoprawny nr PESEL. Numer PESEL powinien zawierac 11 cyfr." << std::endl;
			std::cin >> nowyPESEL;
			setPESEL(nowyPESEL);
		}

		else {
			PESEL = nowyPESEL;
			std::cout << "Nowy pesel to: ";
		}
	}
	*/

