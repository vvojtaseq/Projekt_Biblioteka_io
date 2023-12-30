#include "Includy.h"
#include "IncludyKlasy.h"



int main()
{
	setlocale(LC_CTYPE, "Polish");  // robi nam polskie litery w coutach
	Osoba Nowa;
	Nowa.setAdres("Kraków 555");
	std::cout << Nowa.getAdres() << std::endl;
	//Nowa.setPESEL("85858585858");
	//std::cout << Nowa.getPESEL()<< std::endl;
	// test co sie stanie jak wpiszemy zly pesel
	Nowa.setPESEL("8484848448484848484");
	//std::cout << Nowa.getPESEL() << std::endl;
	// dzia³a jak powinno

}