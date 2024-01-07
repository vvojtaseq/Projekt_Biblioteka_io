#include "Includy.h"
#include "IncludyKlasy.h"
#define HASLOPRACOWNIKOW = 88987

void userInterface()
{
	system("CLS");
	std::cout << "**<< Biblioteka dla Student�w >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :"<<std::endl;
	std::cout << "[1] - U�ytkownik\t\t[2] - Pracownik " << std::endl;
	// to b�dzie po wybraniu jakis if czy cos, i beda dwie rozne opcje , jedna dla uzytkownika, druga dla pracownika
	int decide;
	std::cin >> decide;
	switch (decide)
	{
	case 1:
		userInterfaceUzytkownik();
		break;
	case 2:
		userInterfacePracownik();
		break;
	default:
		std::cout << "Opcja o id: "<<decide<<" nie istnieje! Spr�buj ponownie!" << std::endl;
		system("pause");
		userInterfaceUzytkownik();
	}
}
void userInterfaceUzytkownik()
{
	system("CLS");
	std::cout << "**<< Biblioteka dla Student�w >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :" << std::endl;
	std::cout << "[1] - Zaloguj si�\t\t[2] - Zarejestruj si� " << std::endl;
	int decide;
	std::cin >> decide;
	switch (decide)
	{
	case 1:
		
		break;
	case 2:
		userInterfaceZarejestrujSie();
		break;
	default:
		std::cout << "Opcja o id: " << decide << " nie istnieje! Podaj w�a�ciw� opcj�!" << std::endl;
		system("pause");
		userInterfaceUzytkownik();
	}
}
void userInterfacePracownik()
{
	system("CLS");
	std::cout << "**<< Biblioteka dla Student�w >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "1 - Zaloguj si�		2 - Zarejestruj si� (potrzebny kod) >> std::endl";

	
	int decide;
	std::cin >> decide;
	switch (decide)
	{
	case 1:
		
		break;
	case 2:
		
		break;
	default:
		std::cout << "Opcja o id: " << decide << " nie istnieje! Podaj w�a�ciw� opcj�!" << std::endl;
		system("pause");
		userInterfacePracownik();
	}
}

void userInterfaceZarejestrujSie()
{
	Czytelnik czytelnik;
<<<<<<< HEAD
	char input[256];
	system("CLS");
	std::cout << "**<< Biblioteka dla Student�w >>**" << std::endl << std::endl << std::endl;
	std::cout << "Podaj Imi�:" << std::endl;
	std::string imie;
	std::getline(std::cin, imie);
	czytelnik.setImie(imie);
	std::cout << "Podaj Nazwisko:";
	std::string nazwisko;
	std::getline(std::cin, nazwisko);
	czytelnik.setNazwisko(nazwisko);
=======
	bool zawieraSpacje;
	bool wlasciweDane;
	int decyzja;
	std::string imie;
	std::string nazwisko;
BEGIN:
	system("CLS");
	std::cout << "**<< Biblioteka dla Student�w >>**" << std::endl << std::endl << std::endl;
	if (imie.empty())
	{
		std::cout << "Podaj Imi�: ";
		std::cin.ignore();
		std::getline(std::cin, imie);
		zawieraSpacje = false;
		for (char c : imie) {
			if (c == ' ') {
				zawieraSpacje = true;
				break;
			}
		}
		if (zawieraSpacje)
		{
			std::cout << "Imi� kt�re poda�e� jest niepoprawne! Nie mo�esz u�ywa� spacji!" << std::endl;
			system("pause");
			imie = "";
		}
		else
		{
			std::cout << "Czy " << imie << " to na pewno twoje imie?\n[1] Tak\t\t[2] Nie" << std::endl;
			wlasciweDane = false;
			while (!wlasciweDane)
			{
				std::cin >> decyzja;
				switch (decyzja)
				{
				case 1: czytelnik.setImie(imie); wlasciweDane = true; break;
				case 2: imie = "";  wlasciweDane = true; break;
				default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj w�a�ciw� opcj�!" << std::endl;
				}
			}
			
			
		}
		goto BEGIN;
	}
	if (nazwisko.empty())
	{
		std::cout << "Podaj Nazwisko: ";
		std::cin.ignore();
		std::getline(std::cin, nazwisko);
		zawieraSpacje = false;
		for (char c : nazwisko) {
			if (c == ' ') {
				zawieraSpacje = true;
				break;
			}
		}
		if (zawieraSpacje)
		{
			std::cout << "Nazwisko kt�re poda�e� jest niepoprawne! Nie mo�esz u�ywa� spacji!" << std::endl;
			system("pause");
			nazwisko = "";
		}
		else
		{
			std::cout << "Czy " << nazwisko << " to na pewno twoje nazwisko?\n[1] Tak\t\t[2] Nie" << std::endl;
			wlasciweDane = false;
			while (!wlasciweDane)
			{
				std::cin >> decyzja;
				switch (decyzja)
				{
				case 1: czytelnik.setNazwisko(nazwisko); wlasciweDane = true; break;
				case 2: nazwisko = "";  wlasciweDane = true; break;
				default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj w�a�ciw� opcj�!" << std::endl;
				}
			}
		}
		goto BEGIN;
	}
>>>>>>> dc8a578c3a174e8aabda258310b8671fec0aab27
	std::cout << "Podaj Adres:";
	std::cin.ignore();
	std::string adres;
	std::getline(std::cin, adres);
	czytelnik.setAdres(adres);
	std::cout << "Podaj Dat� Urodzenia:";
	std::string dataUrodzenia;
	std::getline(std::cin, dataUrodzenia);
	czytelnik.setDataUrodzenia(dataUrodzenia); //je�li wprowadzi si� adres z numerem to przeskakuje wprowadzanie daty urodzenia
	std::cout << "Podaj Telefon:";
	std::string telefon;
	std::getline(std::cin, telefon);
	czytelnik.setTelefon(telefon);
	std::cout << "Podaj PESEL:";
	std::string pesel;
	while (true)
	{
		std::cin >> pesel;
		if (pesel.length() != PESELLENGTH) {
			std::cout << "Niepoprawna dlugosc numeru PESEL. Wprowadz 11 znakow." << std::endl;
		}
		else if (!std::all_of(pesel.begin(), pesel.end(), ::isdigit)) {
			std::cout << "Numer PESEL powinien zawierac tylko cyfry." << std::endl;
		}
		else {
			long long pesel_lenght = std::stoll(pesel);
			if (pesel_lenght > MAXPESEL || pesel_lenght < MINPESEL) {
				std::cout << "Niepoprawny nr PESEL. Numer PESEL powinien zawierac 11 cyfr." << std::endl;
			}
			else {
				break;
			}
		}
		std::cout << "Wprowadz nowy PESEL: ";
	}
	czytelnik.setPESEL(pesel);
	std::cout << "Podaj Has�o:";
	std::string haslo;
	std::cin >> haslo;
	czytelnik.setHaslo(haslo);
	czytelnik.setIDFromFile("czytelnicy.txt");
	addCzytelnik(czytelnik);

}

void userInterfaceUzytkownikZalogowany()
{
	system("CLS");
	std::cout << "**<< Biblioteka dla Student�w >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "1 - Wyszukaj ksi��k�		2 - Wypo�ycz ksi��k� " << std::endl;
	std::cout << "3 - Zwr�� ksi��k�		4 - Zobacz swoje ksi��ki " << std::endl;
	std::cout << "5 - Zobacz swoje dane		6 - Wyloguj si� " << std::endl;
	int decide;
	std::cin >> decide;
	switch (decide)
	{
	case 1:
		
		break;
	case 2:
		
		break;
	case 3:
		
		break;
	case 4:
		
		break;
	case 5:
		
		break;
	case 6:
		
		break;
	default:
		std::cout << "Niepoprawne dane, spr�buj jeszcze raz" << std::endl;
		system("pause");
		userInterfaceUzytkownikZalogowany();
	}
}

//