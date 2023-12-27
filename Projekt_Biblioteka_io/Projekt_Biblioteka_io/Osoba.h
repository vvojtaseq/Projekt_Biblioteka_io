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
	unsigned int Telefon; 
	std::string PESEL;
	
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
	unsigned int getTelefon() { return Telefon; }
	void setTelefon(unsigned int nowyTelefon) { Telefon = nowyTelefon; }
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
					std::cout << "Nowy pesel to: " << PESEL << std::endl;
					break; // Exit the loop after setting the valid PESEL
				}
			}
			std::cout << "Wprowadz nowy PESEL: ";
			std::cin >> nowyPESEL;
		}
	}

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
};

