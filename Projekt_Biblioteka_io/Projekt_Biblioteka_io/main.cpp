#include "Includy.h"
#include "IncludyKlasy.h"



int main()
{

	std::locale::global(std::locale("pl_PL.utf8"));

//	std::wcout.imbue(std::locale());  // robi nam polskie litery w coutach
//	SetConsoleOutputCP(CP_UTF8);
//	SetConsoleCP(CP_UTF8);
//	userInterface();



/*
//	***TESTY***
//	Do sprawdzaenia czy dziala klasa KatalogUzytkownikow
	KatalogUzytkownikow katalogUzytkownikow;
	std::cout << katalogUzytkownikow.getImie(2) << "|";
	std::cout << katalogUzytkownikow.getNazwisko(2) << "|";
	std::cout << katalogUzytkownikow.getEmail(2) << "|";
	std::cout << katalogUzytkownikow.getAdres(2) << "|";
	std::cout << katalogUzytkownikow.getTelefon(2) << "|";
	std::cout << katalogUzytkownikow.getPESEL(2) << "|";
	std::cout << katalogUzytkownikow.getPowerLevel(2) << "|" << std::endl;

	//tworzenie czytelnika
Czytelnik czytelnik;
czytelnik.setImie("Jan");
czytelnik.setNazwisko("Kowalski");
czytelnik.setEmail("Jan@op.pl");
czytelnik.setAdres("ul. Kowalska 1");
czytelnik.setTelefon("123456789");
czytelnik.setPESEL("12345678901");
czytelnik.setPowerLevel(1);
czytelnik.setDataUrodzenia("01.01.2000");
czytelnik.setIDToFile("czytelnicy.txt");

katalogUzytkownikow.addCzytelnik(czytelnik);

Ksiazka ksiazka;
ksiazka.setTytul("Pan Tadeusz");
ksiazka.setAutorImie("Adam");
ksiazka.setAutorNazwisko("Mickiewicz");
ksiazka.setRokWydania("2000");
ksiazka.setIloscEgzemplarzy(5);
ksiazka.setID(1);
ksiazka.setIloscStron(100);

Autor autor("Kamil", "Pris", "Blabla");

Zbior zbior;
zbior.addKsiazka(ksiazka, autor);

KartaBiblioteczna kartaBiblioteczna;
kartaBiblioteczna.addKartaBiblioteczna(katalogUzytkownikow.getImie(9), katalogUzytkownikow.getNazwisko(9), 9, zbior.getTytul(1), 1, "1.02.2024", "15.02.2024");
kartaBiblioteczna.saveKartaBiblioteczna();

katalogUzytkownikow.setHaslo(1, "1234", "jan@onet.pl");
std::cout << katalogUzytkownikow.Autoryzacja("jan@onet.pl", "1234");

*/

}
