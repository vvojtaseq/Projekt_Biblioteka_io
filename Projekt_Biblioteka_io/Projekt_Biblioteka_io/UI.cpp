#include "Includy.h"
#include "IncludyKlasy.h"
#define HASLOPRACOWNIKOW = 88987
void userInterface()
{
	system("CLS");
	std::cout << "**<< Biblioteka dla Studentów >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "1 - U¿ytkownik		2 - Pracownik " << std::endl;
	// to bêdzie po wybraniu jakis if czy cos, i beda dwie rozne opcje , jedna dla uzytkownika, druga dla pracownika
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
		std::cout << "Niepoprawne dane, spróbuj jeszcze raz" << std::endl;
		system("pause");
		userInterface();
	}
}
void userInterfaceUzytkownik()
{
	system("CLS");
	std::cout << "**<< Biblioteka dla Studentów >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "1 - Zaloguj siê		2 - Zarejestruj siê " << std::endl;
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
		std::cout << "Niepoprawne dane, spróbuj jeszcze raz" << std::endl;
		system("pause");
		userInterfaceUzytkownik();
	}
}
void userInterfacePracownik()
{
	system("CLS");
	std::cout << "**<< Biblioteka dla Studentów >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "1 - Zaloguj siê		2 - Zarejestruj siê (potrzebny kod) >> std::endl";

	
	int decide;
	std::cin >> decide;
	switch (decide)
	{
	case 1:
		
		break;
	case 2:
		
		break;
	default:
		std::cout << "Niepoprawne dane, spróbuj jeszcze raz" << std::endl;
		system("pause");
		userInterfacePracownik();
	}
}

void userInterfaceZarejestrujSie()
{
	Czytelnik czytelnik;
	char input[256];
	system("CLS");
	std::cout << "**<< Biblioteka dla Studentów >>**" << std::endl << std::endl << std::endl;
	std::cout << "Podaj Imiê:" << std::endl;
	std::string imie;
	std::getline(std::cin, imie);
	czytelnik.setImie(imie);
	std::cout << "Podaj Nazwisko:";
	std::string nazwisko;
	std::getline(std::cin, nazwisko);
	czytelnik.setNazwisko(nazwisko);
	std::cout << "Podaj Adres:";
	std::string adres;
	std::getline(std::cin, adres);
	czytelnik.setAdres(adres);
	std::cout << "Podaj Datê Urodzenia:";
	std::string dataUrodzenia;
	std::cin >> dataUrodzenia;
	//std::cout << dataUrodzenia;
	czytelnik.setDataUrodzenia(dataUrodzenia); //jeœli wprowadzi siê adres z numerem to przeskakuje wprowadzanie daty urodzenia
	std::cout << "Podaj Telefon:";
	std::string telefon;
	std::cin >> telefon;
	czytelnik.setTelefon(telefon);
	std::cout << "Podaj PESEL:";
	std::string pesel;
	std::cin >> pesel;
	czytelnik.setPESEL(pesel);
	std::cout << "Podaj Has³o:";
	std::string haslo;
	std::cin >> haslo;
	czytelnik.setHaslo(haslo);
	czytelnik.setIDFromFile("czytelnicy.txt");
	addCzytelnik(czytelnik);

}

void userInterfaceUzytkownikZalogowany()
{
	system("CLS");
	std::cout << "**<< Biblioteka dla Studentów >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "1 - Wyszukaj ksi¹¿kê		2 - Wypo¿ycz ksi¹¿kê " << std::endl;
	std::cout << "3 - Zwróæ ksi¹¿kê		4 - Zobacz swoje ksi¹¿ki " << std::endl;
	std::cout << "5 - Zobacz swoje dane		6 - Wyloguj siê " << std::endl;
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
		std::cout << "Niepoprawne dane, spróbuj jeszcze raz" << std::endl;
		system("pause");
		userInterfaceUzytkownikZalogowany();
	}
}

//