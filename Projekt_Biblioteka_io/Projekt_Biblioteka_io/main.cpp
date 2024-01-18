#include "Includy.h"
#include "IncludyKlasy.h"



int main()
{

	std::locale::global(std::locale("pl_PL.utf8"));
	std::wcout.imbue(std::locale());  // robi nam polskie litery w coutach
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	userInterface();



}
