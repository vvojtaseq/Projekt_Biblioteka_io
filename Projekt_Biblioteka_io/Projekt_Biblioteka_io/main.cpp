#include "includy.h"
void userInterface();
void userInterfaceUzytkownik();
void userInterfacePracownik();


int main()
{
	setlocale(LC_CTYPE, "Polish");  // robi nam polskie litery w coutach
	userInterface();

	// clear console  to  system("CLS");, musi byc <stdlib.h>
	return 0;
}
void userInterface()
{
	std::cout << "<< Biblioteka dla Champion�w >>" << std::endl << std::endl << std::endl;
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
		userInterface();
	}
}
void userInterfaceUzytkownik()
{
	std::cout << "<< Biblioteka dla Champion�w >>" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "1 - Zaloguj si�		2 - Zarejestruj si� " << std::endl;
}
void userInterfacePracownik()
{
	std::cout << "<< Biblioteka dla Champion�w >>" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "1 - Zaloguj si�		2 - Zarejestruj si� (potrzebny kod) >> std::endl";
	//tutaj taki pomysl zeby miec jakies set haslo ktore trzeba podac zanim ci da mozliwosc stworzenia konta

}