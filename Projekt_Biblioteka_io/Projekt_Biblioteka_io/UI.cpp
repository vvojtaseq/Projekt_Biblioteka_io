#include "Includy.h"
#include "IncludyKlasy.h"
#define HASLOPRACOWNIKOW = 88987
void userInterface()
{
	system("CLS");
	std::cout << "**<< Biblioteka dla Student�w >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "1 - U�ytkownik		2 - Pracownik " << std::endl;
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
		std::cout << "Niepoprawne dane, spr�buj jeszcze raz" << std::endl;
		system("pause");
		userInterface();
	}
}
void userInterfaceUzytkownik()
{
	system("CLS");
	std::cout << "**<< Biblioteka dla Student�w >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "1 - Zaloguj si�		2 - Zarejestruj si� " << std::endl;
	int decide;
	std::cin >> decide;
	switch (decide)
	{
	case 1:
		
		break;
	case 2:
		
		break;
	default:
		std::cout << "Niepoprawne dane, spr�buj jeszcze raz" << std::endl;
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
	//tutaj taki pomysl zeby miec jakies set haslo ktore trzeba podac zanim ci da mozliwosc stworzenia konta
	
	int decide;
	std::cin >> decide;
	switch (decide)
	{
	case 1:
		
		break;
	case 2:
		
		break;
	default:
		std::cout << "Niepoprawne dane, spr�buj jeszcze raz" << std::endl;
		system("pause");
		userInterfacePracownik();
	}
}