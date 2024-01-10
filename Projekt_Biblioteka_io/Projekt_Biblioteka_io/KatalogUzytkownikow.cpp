#include "KatalogUzytkownikow.h"
//dodawanie uzytkownika do pliku
void addCzytelnik (Czytelnik czytelnik)
{
	std::fstream plik;
	plik.open("czytelnicy.txt", std::ios::out | std::ios::app);
	plik << czytelnik.getID() << "|" << czytelnik.getImie() << "|" << czytelnik.getNazwisko() << "|" << czytelnik.getEmail() << "|" << czytelnik.getAdres() << "|" << czytelnik.getTelefon() << "|" << czytelnik.getPESEL() << "|" << czytelnik.getPowerLevel() << std::endl;
	plik.close();
}
//dodawanie uzytkownika do pliku
void addBibliotekarz (Bibliotekarz bibliotekarz)
{
	std::fstream plik;
	plik.open("bibliotekarze.txt", std::ios::out | std::ios::app);
	plik << bibliotekarz.getID() << "|" << bibliotekarz.getImie() << "|" << bibliotekarz.getNazwisko() << "|" << bibliotekarz.getEmail() << "|" << bibliotekarz.getAdres() << "|" << bibliotekarz.getTelefon() << "|" << bibliotekarz.getPESEL() << "|" << bibliotekarz.getPowerLevel() << std::endl;
	plik.close();
}

//dodawanie id, hasla i ID do pliku
void addProtectionToFiles( unsigned int id, std::string haslo, std::string Email)
{
	std::fstream plik;
	plik.open("hasla.txt", std::ios::out | std::ios::app);
	plik << id << "|" << haslo << "|" << Email << std::endl;
	plik.close();
}

//pobieranie hasla z pliku
std::string getHasloFromProtectedFiles(unsigned int id)
{
	std::fstream plik;
	plik.open("hasla.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string haslo;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, haslo, '|');
		if (id == std::stoi(idString))
		{
			return haslo;
		}
	}
	plik.close();
	return "Nie znaleziono hasla";
}

//zmiana hasla w pliku
void changeHaslo(std::string noweHaslo, unsigned int ID)
{
	std::fstream plik;
	plik.open("hasla.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string haslo;
	std::vector<std::string> hasla;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, haslo, '|');
		if (ID == std::stoi(idString))
		{
			hasla.push_back(idString + "|" + noweHaslo);
		}
		else
		{
			hasla.push_back(idString + "|" + haslo);
		}
	}
	plik.close();
	plik.open("hasla.txt", std::ios::out);
	for (int i = 0; i < hasla.size(); i++)
	{
		plik << hasla[i] << std::endl;
	}
	plik.close();
}

//Autoryzacja zwraca 1 gdy zgadza si� mail i has�o 
bool Autoryzacja(std::string email, std::string haslo)
{
	std::fstream plik;
	plik.open("hasla.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string hasloString;
	std::string emailString;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, hasloString, '|');
		getline(ss, emailString, '|');
		if (email == emailString && haslo == hasloString)
		{
			return true;
		}
	}
	plik.close();
	return false;
}


//pobieranie imienia z pliku
std::string getImieFromFiles(unsigned int id)
{
	std::fstream plik;
	plik.open("czytelnicy.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string imie;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, imie, '|');
		if (id == std::stoi(idString))
		{
			return imie;
		}
	}
	plik.close();
	plik.open("bibliotekarze.txt", std::ios::in);
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, imie, '|');
		if (id == std::stoi(idString))
		{
			return imie;
		}
	}
	plik.close();
	return "Nie znaleziono imienia";
}

//pobieranie nazwiska z pliku
std::string getNazwiskoFromFiles(unsigned int id)
{
	std::fstream plik;
	plik.open("czytelnicy.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string nazwisko;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, nazwisko, '|');
		if (id == std::stoi(idString))
		{
			return nazwisko;
		}
	}
	plik.close();
	plik.open("bibliotekarze.txt", std::ios::in);
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, nazwisko, '|');
		if (id == std::stoi(idString))
		{
			return nazwisko;
		}
	}
	plik.close();
	return "Nie znaleziono nazwiska";
}

std::string getEmailFromFiles(unsigned int id)
{
	std::fstream plik;
	plik.open("czytelnicy.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string email;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, email, '|');
		if (id == std::stoi(idString))
		{
			return email;
		}
	}
	plik.close();
	plik.open("bibliotekarze.txt", std::ios::in);
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, email, '|');
		if (id == std::stoi(idString))
		{
			return email;
		}
	}
	plik.close();
	return "Nie znaleziono emaila";
}

std::string getAdresFromFiles(unsigned int id)
{
	std::fstream plik;
	plik.open("czytelnicy.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string adres;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, adres, '|');
		if (id == std::stoi(idString))
		{
			return adres;
		}
	}
	plik.close();
	plik.open("bibliotekarze.txt", std::ios::in);
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, adres, '|');
		if (id == std::stoi(idString))
		{
			return adres;
		}
	}
	plik.close();
	return "Nie znaleziono adresu";
}

std::string getTelefonFromFiles(unsigned int id)
{
	std::fstream plik;
	plik.open("czytelnicy.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string telefon;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, telefon, '|');
		if (id == std::stoi(idString))
		{
			return telefon;
		}
	}
	plik.close();
	plik.open("bibliotekarze.txt", std::ios::in);
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, telefon, '|');
		if (id == std::stoi(idString))
		{
			return telefon;
		}
	}
	plik.close();
	return "Nie znaleziono telefonu";
}

std::string getPESELFromFiles(unsigned int id)
{
	std::fstream plik;
	plik.open("czytelnicy.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string pesel;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, pesel, '|');
		if (id == std::stoi(idString))
		{
			return pesel;
		}
	}
	plik.close();
	plik.open("bibliotekarze.txt", std::ios::in);
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, pesel, '|');
		if (id == std::stoi(idString))
		{
			return pesel;
		}
	}
	plik.close();
	return "Nie znaleziono peselu";
}

int getPowerLevelFromFiles(unsigned int id)
{
	std::fstream plik;
	plik.open("czytelnicy.txt", std::ios::in);
	std::string linia;
	std::string idString;
	std::string powerlevel;
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, powerlevel, '|');
		if (id == std::stoi(idString))
		{
			return std::stoi(powerlevel);
		}
	}
	plik.close();
	plik.open("bibliotekarze.txt", std::ios::in);
	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, powerlevel, '|');
		if (id == std::stoi(idString))
		{
			return std::stoi(powerlevel);
		}
	}
	plik.close();
	return -1;
}

//funkcja do pobierania wszystkich danych uzytkownika z pliku
Osoba getWszystkieDaneFromFiles(unsigned int id, std::string nazwaPliku)
{
	Osoba osoba;
	std::fstream plik;
	plik.open(nazwaPliku, std::ios::in);
	std::string linia;
	std::string idString;
	std::string imie;
	std::string nazwisko;
	std::string email;
	std::string adres;
	std::string telefon;
	std::string pesel;
	std::string powerlevel;

	while (getline(plik, linia))
	{
		std::stringstream ss(linia);
		getline(ss, idString, '|');
		getline(ss, imie, '|');
		getline(ss, nazwisko, '|');
		getline(ss, email, '|');
		getline(ss, adres, '|');
		getline(ss, telefon, '|');
		getline(ss, pesel, '|');
		getline(ss, powerlevel, '|');
		if (id == std::stoi(idString))
		{
			osoba.setID(id);
			osoba.setImie(imie);
			osoba.setNazwisko(nazwisko);
			osoba.setEmail(email);
			osoba.setAdres(adres);
			osoba.setTelefon(telefon);
			osoba.setPESEL(pesel);
			osoba.setPowerLevel(std::stoi(powerlevel));
			return osoba;
		}
	}

}





