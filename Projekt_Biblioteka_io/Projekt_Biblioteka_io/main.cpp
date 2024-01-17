#include "Includy.h"
#include "IncludyKlasy.h"



int main()
{
	

	std::locale::global(std::locale("pl_PL.utf8"));
	KatalogUzytkownikow katalogUzytkownikow;
	std::cout << katalogUzytkownikow.getImie(2);
	std::cout << katalogUzytkownikow.getNazwisko(2);
	std::cout << katalogUzytkownikow.getEmail(2);
	std::cout << katalogUzytkownikow.getAdres(2);
	std::cout << katalogUzytkownikow.getTelefon(2);
	std::cout << katalogUzytkownikow.getPESEL(2);
	std::cout << katalogUzytkownikow.getPowerLevel(2);

//	std::wcout.imbue(std::locale());  // robi nam polskie litery w coutach
//	SetConsoleOutputCP(CP_UTF8);
//	SetConsoleCP(CP_UTF8);
//	userInterface();
}
