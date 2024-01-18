#include "Includy.h"
#include "IncludyKlasy.h"

static const int HASLOPRACOWNIKOW = 88987;
int ID = 0;

void userInterface()
{
	system("CLS");
	std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :"<<std::endl;
	std::cout <<"[1] - Użytkownik"<<std::setw(20)<<"[2] - Pracownik"<< std::setw(19) << "[3] - Wyjście" << std::endl;
	// to będzie po wybraniu jakis if czy cos, i beda dwie rozne opcje , jedna dla uzytkownika, druga dla pracownika
	int decide;
	std::cin >> decide;
	std::cin.ignore();
	switch (decide)
	{
	case 1:
		userInterfaceUzytkownik();
		break;
	case 2:
		userInterfacePracownik();
		break;
	case 3:
		exit(0);
		break;
	default:
		std::cout << "Opcja o id: "<<decide<<" nie istnieje! Spróbuj ponownie!" << std::endl;
		system("pause");
		userInterface();
	}
}
void userInterfaceUzytkownik()
{
	system("CLS");
	std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :" << std::endl;
	std::cout << "[1] - Zaloguj się" << std::setw(28) << "[2] - Zarejestruj się" << std::setw(19) << "[3] - Powrót" << std::endl;
	int decide;
	std::cin >> decide;
	std::cin.ignore();
	switch (decide)
	{
	case 1:
		userInterfaceZalogujSie();
		break;
	case 2:
		userInterfaceZarejestrujSie();
		break;
	case 3:
		userInterface();
		break;
	default:
		std::cout << "Opcja o id: " << decide << " nie istnieje! Podaj właściwą opcję!" << std::endl;
		system("pause");
		userInterfaceUzytkownik();
	}
}

bool sprawdzPoprawnoscNazwy(const std::string& imie) {
	// Sprawdzenie, czy imię zawiera tylko litery i spacje
	for (char znak : imie) {
		if (!isalpha(znak) && !isspace(znak)) {
			return false;
		}
	}

	// Imię nie powinno być puste
	if (imie.empty()) {
		return false;
	}

	// Jeśli wszystkie warunki są spełnione, imię jest poprawne
	return true;
}
bool sprawdzPoprawnoscAdresu(const std::string& ulica, const std::string& numerBudynku, const std::string& kodPocztowy, const std::string& miasto) {
	sprawdzPoprawnoscNazwy(ulica);
	// Sprawdzenie, czy numer budynku zawiera tylko cyfry i ewentualnie literę lub znak '/'
	for (char znak : numerBudynku) {
		if (!isdigit(znak) && !isalpha(znak) && znak != '/') {
			return false;
		}
	}
	// Sprawdzenie, czy kod pocztowy ma poprawny format (np. "00-000")
	if (kodPocztowy.length() != 6 || !isdigit(kodPocztowy[0]) || !isdigit(kodPocztowy[1]) ||
		kodPocztowy[2] != '-' || !isdigit(kodPocztowy[3]) || !isdigit(kodPocztowy[4]) || !isdigit(kodPocztowy[5])) {
		return false;
	}
	sprawdzPoprawnoscNazwy(miasto);
	// Jeśli wszystkie warunki są spełnione, dane są poprawne
	return true;
}
bool sprawdzPoprawnoscDatyUrodzenia(const std::string& dataUrodzenia) {
	// Sprawdzenie, czy data urodzenia ma odpowiednią długość
	if (dataUrodzenia.length() != 10) {
		return false;
	}
	// Sprawdzenie, czy odpowiednie znaki są na odpowiednich miejscach
	for (int i = 0; i < 10; ++i) {
		if ((i == 2 || i == 5) && dataUrodzenia[i] != '-') {
			return false;
		}
		else if (i != 2 && i != 5 && !isdigit(dataUrodzenia[i])) {
			return false;
		}
	}
	// Sprawdzenie, czy miesiąc mieści się w zakresie 01-12
	int miesiac = std::stoi(dataUrodzenia.substr(3, 2));
	if (miesiac < 1 || miesiac > 12) {
		return false;
	}
	// Sprawdzenie, czy dzień mieści się w zakresie 01-31 (uproszczenie, bez uwzględniania różnych dni w miesiącach)
	int dzien = std::stoi(dataUrodzenia.substr(0, 2));
	if (dzien < 1 || dzien > 31) {
		return false;
	}
	// Jeśli wszystkie warunki są spełnione, data urodzenia jest poprawna
	return true;
}
bool sprawdzPoprawnoscEmaila(const std::string& email) {
	// Prosta weryfikacja przy użyciu wyrażenia regularnego
	std::regex wzorEmaila("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

	// Sprawdzenie, czy email pasuje do wzorca
	return std::regex_match(email, wzorEmaila);
}
bool sprawdzPoprawnoscHasla(const std::string& haslo) {
	// Sprawdzenie, czy hasło ma odpowiednią długość (np. minimum 8 znaków)
	if (haslo.length() < 8) {
		return false;
	}
	// Sprawdzenie, czy hasło zawiera przynajmniej jedną małą literę
	bool maMalaLitere = false;
	for (char znak : haslo) {
		if (islower(znak)) {
			maMalaLitere = true;
			break;
		}
	}
	if (!maMalaLitere) {
		return false;
	}
	// Sprawdzenie, czy hasło zawiera przynajmniej jedną dużą literę
	bool maDuzaLitere = false;
	for (char znak : haslo) {
		if (isupper(znak)) {
			maDuzaLitere = true;
			break;
		}
	}
	if (!maDuzaLitere) {
		return false;
	}
	// Sprawdzenie, czy hasło zawiera przynajmniej jedną cyfrę
	bool maCyfre = false;
	for (char znak : haslo) {
		if (isdigit(znak)) {
			maCyfre = true;
			break;
		}
	}
	if (!maCyfre) {
		return false;
	}
	// Jeśli wszystkie warunki są spełnione, hasło jest poprawne
	return true;
}
bool sprawdzPoprawnoscNumeruTelefonu(const std::string& numerTelefonu) {
	// Sprawdzenie, czy numer telefonu ma odpowiednią długość
	if (numerTelefonu.length() < 9 || numerTelefonu.length() > 15) {
		return false;
	}

	// Sprawdzenie, czy numer telefonu zawiera tylko cyfry, spacje, myślniki
	for (char znak : numerTelefonu) {
		if (!isdigit(znak) && !isspace(znak) && znak != '-') {
			return false;
		}
	}

	// Jeśli wszystkie warunki są spełnione, numer telefonu jest poprawny
	return true;
}

void userInterfaceZarejestrujSie()
{
	Czytelnik czytelnik;
	bool wlasciweDane;
	int decyzja;
	std::string imie;
	std::string nazwisko;
	std::string adres;
	std::string ulica;
	std::string numer_domu;
	std::string kod_pocztowy;
	std::string miasto;
	std::string dataUrodzenia;
	std::string telefon;
	std::string pesel;
	std::string adres_email;
	std::string haslo;
	std::string powtórz_haslo;
	while (true)
	{
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		if (imie.empty())
		{
			std::cout << "Podaj Imię: ";
			std::getline(std::cin, imie);
			if (sprawdzPoprawnoscNazwy(imie) == false)
			{
				std::cout << "Imię które podałeś jest niepoprawne! Nie możesz używać spacji!" << std::endl;
				system("pause");
				imie = "";
			}
			else
			{
				std::cout << "Czy " << imie << " to na pewno twoje imie?\n[1] - Tak"<<std::setw(20)<<"[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: czytelnik.setImie(imie); wlasciweDane = true; break;
					case 2: imie = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}


			}
		}
		else if (nazwisko.empty())
		{
			std::cout << "Podaj Nazwisko: ";
			std::getline(std::cin, nazwisko);
			if (sprawdzPoprawnoscNazwy(imie) == false)
			{
				std::cout << "Nazwisko które podałeś jest niepoprawne! Nie możesz używać spacji!" << std::endl;
				system("pause");
				nazwisko = "";
			}
			else
			{
				std::cout << "Czy " << nazwisko << " to na pewno twoje nazwisko?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: czytelnik.setNazwisko(nazwisko); wlasciweDane = true; break;
					case 2: nazwisko = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}
			}
		}
		else if (adres.empty())
		{
			std::cout << "[Wprowadzanie Adresu]" << std::endl;
			std::cout << "Podaj ulicę: ";
			std::getline(std::cin, ulica);
			std::cout << "Podaj numer domu: ";
			std::getline(std::cin, numer_domu);
			std::cout << "Podaj kod pocztowy: ";
			std::getline(std::cin, kod_pocztowy);
			std::cout << "Podaj miasto: ";
			std::getline(std::cin, miasto);
			adres = ulica + " " + numer_domu + ", " + kod_pocztowy + " " + miasto;
			if (sprawdzPoprawnoscAdresu(ulica, numer_domu, kod_pocztowy, miasto) == false)
			{
				std::cout << "Adres który podałeś jest niepoprawny!" << std::endl;
				system("pause");
				adres = "";
			}
			else
			{
				std::cout << "Czy " << adres << " to na pewno twój adres?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: czytelnik.setAdres(adres);; wlasciweDane = true; break;
					case 2: adres = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}
			}
		}
		else if (dataUrodzenia.empty())
		{
			std::cout << "Podaj datę urodzenia: ";
			std::getline(std::cin, dataUrodzenia);
			if (sprawdzPoprawnoscDatyUrodzenia(dataUrodzenia) == false)
			{
				std::cout << "Data urodzenia, którą podałeś jest niepoprawne! Nie możesz używać spacji!" << std::endl;
				system("pause");
				dataUrodzenia = "";
			}
			else
			{
				std::cout << "Czy " << dataUrodzenia << " to na pewno twoja data urodzin?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: czytelnik.setDataUrodzenia(dataUrodzenia); wlasciweDane = true; break;
					case 2: dataUrodzenia = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}
			}
		}
		else if (telefon.empty())
		{
			std::cout << "Podaj numer telefonu: ";
			std::getline(std::cin, telefon);
			if (sprawdzPoprawnoscNumeruTelefonu(telefon)==false)
			{
				std::cout << "Data urodzenia, którą podałeś jest niepoprawne! Nie możesz używać spacji!" << std::endl;
				system("pause");
				telefon = "";
			}
			else
			{
				std::cout << "Czy " << telefon << " to na pewno twój numer telefonu?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: czytelnik.setTelefon(telefon); wlasciweDane = true; break;
					case 2: telefon = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}
			}
		}
		else if (pesel.empty())
		{
			std::cout << "Podaj numer PESEL: ";
			std::getline(std::cin, pesel);
			if (pesel.length() != PESELLENGTH) {
				std::cout << "Niepoprawna dlugosc numeru PESEL. Wprowadz 11 znakow." << std::endl;
				system("pause");
				pesel = "";
			}
			else if (!std::all_of(pesel.begin(), pesel.end(), ::isdigit)) {
				std::cout << "Numer PESEL powinien zawierac tylko cyfry." << std::endl;
				system("pause");
				pesel = "";
			}
			else {
				long long pesel_lenght = std::stoll(pesel);
				if (pesel_lenght > MAXPESEL || pesel_lenght < MINPESEL) {
					std::cout << "Niepoprawny nr PESEL. Numer PESEL powinien zawierac 11 cyfr." << std::endl;
					system("pause");
					pesel = "";
				}
				else {
					std::cout << "Czy " << pesel << " to na pewno twój numer PESEL?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
					wlasciweDane = false;
					while (!wlasciweDane)
					{
						std::cin >> decyzja;\
						std::cin.ignore();
						switch (decyzja)
						{
						case 1: czytelnik.setPESEL(pesel); wlasciweDane = true; break;
						case 2: pesel = "";  wlasciweDane = true; break;
						default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
						}
					}
				}
			}
		}
		else if (adres_email.empty())
		{
			std::cout << "Podaj e-mail: ";
			std::getline(std::cin, adres_email);
			if (sprawdzPoprawnoscEmaila(adres_email) == false)
			{
				std::cout << "email który podałeś jest niepoprawny!" << std::endl;
				system("pause");
				imie = "";
			}
			else
			{
				std::cout << "Czy " << adres_email << " to na pewno twój email?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: czytelnik.setEmail(adres_email); wlasciweDane = true; break;
					case 2: adres_email = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}


			}
		}
		else if (haslo.empty())
		{
			std::cout << "Utwórz hasło: ";
			std::getline(std::cin, haslo);
			if (sprawdzPoprawnoscHasla(haslo) == false)
			{
				std::cout << "Haslo, którą podałeś jest niepoprawne! Użyj minimum 8 znaków, co najmniej jednej małej litery i dużej litery oraz liczby!" << std::endl;
				system("pause");
				haslo = "";
			}
			else
			{
				std::cout << "Powtórz hasło: ";
				std::getline(std::cin, powtórz_haslo);
				if (haslo == powtórz_haslo)
				{
					czytelnik.setHaslo(haslo);
				}
				else
				{
					std::cout << "Nie zgadza się! Jeszcze raz..." << std::endl;
					system("pause");
					haslo = "";
				}
			}
		}
		else
		{
			KatalogUzytkownikow katalog;
			czytelnik.setPowerLevel(0);
			czytelnik.setID();
			katalog.addCzytelnik(czytelnik);
			katalog.setHaslo(czytelnik.getID(), haslo, adres_email);
			break;
		}
		
	}
	userInterfaceUzytkownik();
}

void userInterfaceZalogujSie()
{
	std::string haslo;
	std::string email;
	int counter = 0;
	while (true)
	{
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		if (email.empty())
		{
			std::cout << "Podaj e-mail: ";
			std::getline(std::cin, email);
		}
		else if (haslo.empty())
		{
			std::cout << "Podaj hasło: ";
			std::getline(std::cin, haslo);
		}
		else
		{
			KatalogUzytkownikow katalog;
			if (katalog.Autoryzacja(email, haslo)==1)
			{
				ID = katalog.getID(email);
				std::cout << "Logowanie..." << std::endl;
				system("pause");
				userInterfaceUzytkownikZalogowany();
			}
			else
			{
				counter++;
				if (counter < 3)
				{
					std::cout << "Hasło, bądź e-mail są nie poprawne, spróbuj ponownie..." << std::endl;
					system("pause");
					email = "";
					haslo = "";
				}
				else
				{
					counter = 0;
					WielokrotnePodanieZlegoHasla();
					email = "";
					haslo = "";
				}
				

			}
		}
		
	}
}

void WielokrotnePodanieZlegoHasla()
{
	int decide;
	while (true)
	{
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		std::cout << "Wielokrotnie podałeś błędne dane logowania! Nie pamiętasz hasła?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
		std::cin >> decide;
		std::cin.ignore();
		switch (decide)
		{
		case 1: ZmianaHasla(); break;
		case 2: break; break;
		default:
			std::cout << "Opcja o id: " << decide << " nie istnieje! Spróbuj ponownie!" << std::endl;
			system("pause");
		}
	}
}

void ZmianaHasla()
{
	KatalogUzytkownikow katalog;
	bool zweryfikowany = false;
	std::string adres_email;
	std::string dataUrodzenia;
	std::string haslo;
	std::string powtórz_haslo;
	while (true)
	{
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		std::cout << "[Zmiana Hasla]" << std::endl;
		if (adres_email.empty())
		{
			std::cout << "Podaj e-mail: ";
			std::getline(std::cin, adres_email);
			ID = katalog.getID(adres_email);
			if (ID <= 0)
			{
				std::cout << "Podanego adresu e-mail nie ma w bazie!\nCzy chcesz się zarejstrować?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				while (true)
				{
					int decide;
					std::cin >> decide;
					std::cin.ignore();
					switch (decide)
					{
					case 1:
						userInterfaceZarejestrujSie();
						break;
					case 2: break;
						break;
					default:
						std::cout << "Opcja o id: " << decide << " nie istnieje! Spróbuj ponownie!" << std::endl;
						system("pause");
					}
				}
			}
		}
		else if (!zweryfikowany)
		{
			
			std::cout << "Podaj datę urodzenia: ";
			std::getline(std::cin, dataUrodzenia);
			if (sprawdzPoprawnoscDatyUrodzenia(dataUrodzenia) == false)
			{
				std::cout << "Data urodzenia, którą podałeś jest niepoprawna!" << std::endl;
				system("pause");
				dataUrodzenia = "";
			}
			else
			{
				std::string dataUrodzeniaPlik = katalog.getDataUrodzenia(ID);
				if (dataUrodzenia == dataUrodzeniaPlik)
				{
					zweryfikowany = true;
				}
				else
				{
					std::cout << "Nie zgadza się!" << std::endl;
					system("pause");
				}
				
			}
		}
		else
		{
			std::cout << "Utwórz hasło: ";
			std::getline(std::cin, haslo);
			if (sprawdzPoprawnoscHasla(haslo) == false)
			{
				std::cout << "Haslo, którą podałeś jest niepoprawne! Użyj minimum 8 znaków, co najmniej jednej małej litery i dużej litery oraz liczby!" << std::endl;
				system("pause");
				haslo = "";
			}
			else
			{
				std::cout << "Powtórz hasło: ";
				std::getline(std::cin, powtórz_haslo);
				if (haslo == powtórz_haslo)
				{
					katalog.editHaslo(haslo, ID);
					break;
				}
				else
				{
					std::cout << "Nie zgadza się! Jeszcze raz..." << std::endl;
					system("pause");
					haslo = "";
				}
			}
		}
	}
	userInterfaceZalogujSie();
}
void wyswietlDaneUżytkownika()
{
	KatalogUzytkownikow katalog;
	Osoba użytkownik = katalog.getWszystkieDane(ID, "czytelnicy.txt");
	system("CLS");
	std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
	std::cout << "Imie: " << użytkownik.getImie() << std::endl;
	std::cout << "Nazwisko: " << użytkownik.getNazwisko() << std::endl;
	std::cout << "Status: Użytkownik" << std::endl;
	std::cout << "E-mail: " << użytkownik.getEmail() << std::endl;
	std::cout << "Adres: " << użytkownik.getAdres() << std::endl;
	std::cout << "Tel.: " << użytkownik.getTelefon() << std::endl;
	std::cout << "PESEL: " << użytkownik.getPESEL() << std::endl;
	system("pause");
	userInterfaceUzytkownikZalogowany();
}

void wyswietlZbior()
{
	KartaBiblioteczna kartaBiblioteczna;
	KatalogUzytkownikow katalog;
	Ksiazka ksiazka;
	unsigned int IDksiazki;
	int poczatek = 1;
	int koniec = 10;
	Zbior zbior;
	while (true)
	{
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		std::cout << "Pozycje:\n";
		zbior.WypiszTytuly(poczatek, koniec);
		std::cout <<std::endl<<std::endl<< "[1] - Następna strona" << std::setw(29) << "[2] - Poprzednia strona" << std::setw(21) << "[3] - Wypożycz" << std::setw(19) << "[4] - Powrót" << std::endl;
		int decide;
		std::cin >> decide;
		std::cin.ignore();
		switch (decide)
		{
		case 1:
			poczatek += 10;
			koniec += 10;
			break;
		case 2:
			poczatek -= 10;
			koniec -= 10;
			break;
		case 3:
			
			std::cout << "Podaj ID książki: ";
			std::cin >> IDksiazki;
			std::cin.ignore();
			ksiazka = zbior.getKsiazka(IDksiazki);
			kartaBiblioteczna.addKartaBiblioteczna(katalog.getImie(ID), katalog.getNazwisko(ID), ID ,ksiazka.getTytul(), IDksiazki, "18-01-2024", "01-02-2024");
			kartaBiblioteczna.saveKartaBiblioteczna();
			std::cout << "Wyporzyczono!!!" << std::endl;
			system("pause");
			break;
		case 4:
			userInterfaceUzytkownikZalogowany();
			break;
		default:
			std::cout << "Opcja o id: " << decide << " nie istnieje! Spróbuj ponownie!" << std::endl;
			system("pause");
		}
	}
}

void WyszukajKsiazke()
{
		Zbior zbior;
		KartaBiblioteczna kartaBiblioteczna;
		KatalogUzytkownikow katalog;
		Ksiazka ksiazka;
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		std::cout << "[Wyszukiwarka pozycji] Podaj tytuł: ";
		std::string tytul;
		std::getline(std::cin, tytul);
		ksiazka = zbior.getKsiazkabyTytul(tytul);
		if (ksiazka.getTytul().empty()) 
		{
			std::cout << "Wyszukiwanie nie powiodło się!" << std::endl;
			WyszukajKsiazke();
		}
		else
		{
			while (true)
			{
				system("CLS");
				std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
				std::cout << "Znaleziona pozycja:" << std::endl;
				std::cout << "Tytuł: " << ksiazka.getTytul() << "; Autor: " << ksiazka.getAutorImie() << " " << ksiazka.getNazwisko() << "; Rok wydania: " << ksiazka.getRokWydania() <<"; Ilość stron: " << ksiazka.getIloscStron() << "; Ilość egzemplarzy: " << ksiazka.getIloscEgzemplarzy() << std::endl;
				std::cout << "Opis: " << ksiazka.getOpis() << std::endl;
				std::cout << std::endl << "-------------------------------------------\nOpcje:\n[1] - Wyporzycz" << std::setw(20) << "[2] - Wyszukaj ponownie" << std::setw(20) << "[3] Wyjście" << std::endl;
			
				int decyzja;
				std::cin >> decyzja;
				std::cin.ignore();
				switch (decyzja)
				{
				case 1:
				{
					kartaBiblioteczna.addKartaBiblioteczna(katalog.getImie(ID), katalog.getNazwisko(ID), ID, ksiazka.getTytul(), ksiazka.getID(), "18-01-2024", "01-02-2024");
					kartaBiblioteczna.saveKartaBiblioteczna();
					std::cout << "Wyporzyczono!!!" << std::endl;
					system("pause");
					userInterfaceUzytkownikZalogowany();
				}
				break;
				case 2: WyszukajKsiazke(); break;
				case 3:
					userInterfaceUzytkownikZalogowany();
					break;
				default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
				}
			}
		}
}

void userInterfaceUzytkownikZalogowany()
{
	KartaBiblioteczna kartaBiblioteczna;
	system("CLS");
	std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "[1] - Wyświetl zbiór" << std::setw(39) << "[2] - Wyszukaj książkę " << std::endl;
	std::cout << "[3] - Zobacz swoje książki " << std::setw(29) <<"[4] - Zobacz swoje dane"<< std::endl;
	std::cout << "[5] - Wyloguj się " << std::endl;
	int decide;
	std::cin >> decide;
	switch (decide)
	{
	case 1:
		wyswietlZbior();
		break;
	case 2:
		WyszukajKsiazke();
		break;
	case 3:
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		kartaBiblioteczna.checkWypozyczenia(ID);
		system("pause");
		userInterfaceUzytkownikZalogowany();
		break;
	case 4: 
		wyswietlDaneUżytkownika();
	break;
	case 5:
		std::cout << "Wylogowywanie..." << std::endl;
		system("pause");
		userInterface();
		break;
	default:
		std::cout << "Opcja o id: " << decide << " nie istnieje! Podaj właściwą opcję!" << std::endl;
		system("pause");
		userInterfaceUzytkownikZalogowany();
	}
}

void userInterfacePracownik()
{
	system("CLS");
	std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "[1] - Zaloguj się" << std::setw(43) << "[2] - Zarejestruj się (potrzebny kod)" << std::setw(19) << "[3] - Powrót"<< std::endl;
	int decide;
	std::cin >> decide;
	std::cin.ignore();
	switch (decide)
	{
	case 1:
		userInterfacePracownikZalogujSie();
		break;
	case 2:
		int kod;
		std::cout << "Podaj kod autoryzacyjny: ";
		std::cin >> kod;
		std::cin.ignore();
		if (kod == HASLOPRACOWNIKOW) userInterfacePracownikZarejestrujSie();
		else userInterfacePracownik();
		break;
	case 3:
		userInterface();
		break;
	default:
		std::cout << "Opcja o id: " << decide << " nie istnieje! Podaj właściwą opcję!" << std::endl;
		system("pause");
		userInterfacePracownik();
	}
}

void userInterfacePracownikZarejestrujSie()
{
	Bibliotekarz bibliotekarz;
	bool wlasciweDane;
	int decyzja;
	std::string imie;
	std::string nazwisko;
	std::string adres;
	std::string ulica;
	std::string numer_domu;
	std::string kod_pocztowy;
	std::string miasto;
	std::string dataUrodzenia;
	std::string telefon;
	std::string pesel;
	std::string adres_email;
	std::string haslo;
	std::string powtórz_haslo;
	while (true)
	{
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		if (imie.empty())
		{
			std::cout << "Podaj Imię: ";
			std::getline(std::cin, imie);
			if (sprawdzPoprawnoscNazwy(imie) == false)
			{
				std::cout << "Imię które podałeś jest niepoprawne! Nie możesz używać spacji!" << std::endl;
				system("pause");
				imie = "";
			}
			else
			{
				std::cout << "Czy " << imie << " to na pewno twoje imie?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: bibliotekarz.setImie(imie); wlasciweDane = true; break;
					case 2: imie = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}


			}
		}
		else if (nazwisko.empty())
		{
			std::cout << "Podaj Nazwisko: ";
			std::getline(std::cin, nazwisko);
			if (sprawdzPoprawnoscNazwy(imie) == false)
			{
				std::cout << "Nazwisko które podałeś jest niepoprawne! Nie możesz używać spacji!" << std::endl;
				system("pause");
				nazwisko = "";
			}
			else
			{
				std::cout << "Czy " << nazwisko << " to na pewno twoje nazwisko?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: bibliotekarz.setNazwisko(nazwisko); wlasciweDane = true; break;
					case 2: nazwisko = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}
			}
		}
		else if (adres.empty())
		{
			std::cout << "[Wprowadzanie Adresu]" << std::endl;
			std::cout << "Podaj ulicę: ";
			std::getline(std::cin, ulica);
			std::cout << "Podaj numer domu: ";
			std::getline(std::cin, numer_domu);
			std::cout << "Podaj kod pocztowy: ";
			std::getline(std::cin, kod_pocztowy);
			std::cout << "Podaj miasto: ";
			std::getline(std::cin, miasto);
			adres = ulica + " " + numer_domu + ", " + kod_pocztowy + " " + miasto;
			if (sprawdzPoprawnoscAdresu(ulica, numer_domu, kod_pocztowy, miasto) == false)
			{
				std::cout << "Adres który podałeś jest niepoprawny!" << std::endl;
				system("pause");
				adres = "";
			}
			else
			{
				std::cout << "Czy " << adres << " to na pewno twój adres?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: bibliotekarz.setAdres(adres);; wlasciweDane = true; break;
					case 2: adres = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}
			}
		}
		else if (dataUrodzenia.empty())
		{
			std::cout << "Podaj datę urodzenia: ";
			std::getline(std::cin, dataUrodzenia);
			if (sprawdzPoprawnoscDatyUrodzenia(dataUrodzenia) == false)
			{
				std::cout << "Data urodzenia, którą podałeś jest niepoprawne! Nie możesz używać spacji!" << std::endl;
				system("pause");
				dataUrodzenia = "";
			}
			else
			{
				std::cout << "Czy " << dataUrodzenia << " to na pewno twoja data urodzin?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: bibliotekarz.setDataUrodzenia(dataUrodzenia); wlasciweDane = true; break;
					case 2: dataUrodzenia = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}
			}
		}
		else if (telefon.empty())
		{
			std::cout << "Podaj numer telefonu: ";
			std::getline(std::cin, telefon);
			if (sprawdzPoprawnoscNumeruTelefonu(telefon) == false)
			{
				std::cout << "Data urodzenia, którą podałeś jest niepoprawne! Nie możesz używać spacji!" << std::endl;
				system("pause");
				telefon = "";
			}
			else
			{
				std::cout << "Czy " << telefon << " to na pewno twój numer telefonu?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: bibliotekarz.setTelefon(telefon); wlasciweDane = true; break;
					case 2: telefon = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}
			}
		}
		else if (pesel.empty())
		{
			std::cout << "Podaj numer PESEL: ";
			std::getline(std::cin, pesel);
			if (pesel.length() != PESELLENGTH) {
				std::cout << "Niepoprawna dlugosc numeru PESEL. Wprowadz 11 znakow." << std::endl;
				system("pause");
				pesel = "";
			}
			else if (!std::all_of(pesel.begin(), pesel.end(), ::isdigit)) {
				std::cout << "Numer PESEL powinien zawierac tylko cyfry." << std::endl;
				system("pause");
				pesel = "";
			}
			else {
				long long pesel_lenght = std::stoll(pesel);
				if (pesel_lenght > MAXPESEL || pesel_lenght < MINPESEL) {
					std::cout << "Niepoprawny nr PESEL. Numer PESEL powinien zawierac 11 cyfr." << std::endl;
					system("pause");
					pesel = "";
				}
				else {
					std::cout << "Czy " << pesel << " to na pewno twój numer PESEL?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
					wlasciweDane = false;
					while (!wlasciweDane)
					{
						std::cin >> decyzja; \
							std::cin.ignore();
						switch (decyzja)
						{
						case 1: bibliotekarz.setPESEL(pesel); wlasciweDane = true; break;
						case 2: pesel = "";  wlasciweDane = true; break;
						default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
						}
					}
				}
			}
		}
		else if (adres_email.empty())
		{
			std::cout << "Podaj e-mail: ";
			std::getline(std::cin, adres_email);
			if (sprawdzPoprawnoscEmaila(adres_email) == false)
			{
				std::cout << "email który podałeś jest niepoprawny!" << std::endl;
				system("pause");
				imie = "";
			}
			else
			{
				std::cout << "Czy " << adres_email << " to na pewno twój email?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				wlasciweDane = false;
				while (!wlasciweDane)
				{
					std::cin >> decyzja;
					std::cin.ignore();
					switch (decyzja)
					{
					case 1: bibliotekarz.setEmail(adres_email); wlasciweDane = true; break;
					case 2: adres_email = "";  wlasciweDane = true; break;
					default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
					}
				}


			}
		}
		else if (haslo.empty())
		{
			std::cout << "Utwórz hasło: ";
			std::getline(std::cin, haslo);
			if (sprawdzPoprawnoscHasla(haslo) == false)
			{
				std::cout << "Haslo, którą podałeś jest niepoprawne! Użyj minimum 8 znaków, co najmniej jednej małej litery i dużej litery oraz liczby!" << std::endl;
				system("pause");
				haslo = "";
			}
			else
			{
				std::cout << "Powtórz hasło: ";
				std::getline(std::cin, powtórz_haslo);
				if (haslo == powtórz_haslo)
				{
					bibliotekarz.setHaslo(haslo);
				}
				else
				{
					std::cout << "Nie zgadza się! Jeszcze raz..." << std::endl;
					system("pause");
					haslo = "";
				}
			}
		}
		else
		{
			KatalogUzytkownikow katalog;
			bibliotekarz.setPowerLevel(1);
			bibliotekarz.setID();
			katalog.addBibliotekarz(bibliotekarz);
			katalog.setHaslo(bibliotekarz.getID(), haslo, adres_email);
			break;
		}

	}
	userInterfacePracownik();
}
void userInterfacePracownikZalogujSie()
{
	std::string haslo;
	std::string email;
	int counter = 0;
	while (true)
	{
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		if (email.empty())
		{
			std::cout << "Podaj e-mail: ";
			std::getline(std::cin, email);
		}
		else if (haslo.empty())
		{
			std::cout << "Podaj hasło: ";
			std::getline(std::cin, haslo);
		}
		else
		{
			KatalogUzytkownikow katalog;
			if (katalog.Autoryzacja(email, haslo) && katalog.getPowerLevel(katalog.getID(email)) == 1)
			{
				ID = katalog.getID(email);
				std::cout << "Logowanie..." << std::endl;
				system("pause");
				userInterfacePracownikZalogowany();
			}
			else
			{
				counter++;
				if (counter < 3)
				{
					std::cout << "Hasło, bądź e-mail są nie poprawne, spróbuj ponownie..." << std::endl;
					system("pause");
					email = "";
					haslo = "";
				}
				else
				{
					counter = 0;
					WielokrotnePodanieZlegoHaslaPracownika();
					email = "";
					haslo = "";
				}


			}
		}

	}
}

void WielokrotnePodanieZlegoHaslaPracownika()
{
	int decide;
	while (true)
	{
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		std::cout << "Wielokrotnie podałeś błędne dane logowania! Nie pamiętasz hasła?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
		std::cin >> decide;
		std::cin.ignore();
		switch (decide)
		{
		case 1: ZmianaHaslaPracownika(); break;
		case 2: break; break;
		default:
			std::cout << "Opcja o id: " << decide << " nie istnieje! Spróbuj ponownie!" << std::endl;
			system("pause");
		}
	}
}

void ZmianaHaslaPracownika()
{
	KatalogUzytkownikow katalog;
	bool zweryfikowany = false;
	std::string adres_email;
	std::string dataUrodzenia;
	std::string haslo;
	std::string powtórz_haslo;
	while (true)
	{
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		std::cout << "[Zmiana Hasla]" << std::endl;
		if (adres_email.empty())
		{
			std::cout << "Podaj e-mail: ";
			std::getline(std::cin, adres_email);
			ID = katalog.getID(adres_email);
			if (ID <= 0)
			{
				std::cout << "Podanego adresu e-mail nie ma w bazie!\nCzy chcesz się zarejstrować?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
				while (true)
				{
					int decide;
					std::cin >> decide;
					std::cin.ignore();
					switch (decide)
					{
					case 1:
						userInterfacePracownikZarejestrujSie();
						break;
					case 2: break;
						break;
					default:
						std::cout << "Opcja o id: " << decide << " nie istnieje! Spróbuj ponownie!" << std::endl;
						system("pause");
					}
				}
			}
		}
		else if (!zweryfikowany)
		{

			std::cout << "Podaj datę urodzenia: ";
			std::getline(std::cin, dataUrodzenia);
			if (sprawdzPoprawnoscDatyUrodzenia(dataUrodzenia) == false)
			{
				std::cout << "Data urodzenia, którą podałeś jest niepoprawna!" << std::endl;
				system("pause");
				dataUrodzenia = "";
			}
			else
			{
				std::string dataUrodzeniaPlik = katalog.getDataUrodzenia(ID);
				if (dataUrodzenia == dataUrodzeniaPlik)
				{
					zweryfikowany = true;
				}
				else
				{
					std::cout << "Nie zgadza się!" << std::endl;
					system("pause");
				}

			}
		}
		else
		{
			std::cout << "Utwórz hasło: ";
			std::getline(std::cin, haslo);
			if (sprawdzPoprawnoscHasla(haslo) == false)
			{
				std::cout << "Haslo, którą podałeś jest niepoprawne! Użyj minimum 8 znaków, co najmniej jednej małej litery i dużej litery oraz liczby!" << std::endl;
				system("pause");
				haslo = "";
			}
			else
			{
				std::cout << "Powtórz hasło: ";
				std::getline(std::cin, powtórz_haslo);
				if (haslo == powtórz_haslo)
				{
					katalog.editHaslo(haslo, ID);
					break;
				}
				else
				{
					std::cout << "Nie zgadza się! Jeszcze raz..." << std::endl;
					system("pause");
					haslo = "";
				}
			}
		}
	}
	userInterfacePracownikZalogujSie();
}
void wyswietlDanePracownika()
{
	KatalogUzytkownikow katalog;
	Osoba użytkownik = katalog.getWszystkieDane(ID, "bibliotekarze.txt");
	system("CLS");
	std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
	std::cout << "Imie: " << użytkownik.getImie() << std::endl;
	std::cout << "Nazwisko: " << użytkownik.getNazwisko() << std::endl;
	std::cout << "Status: Pracownik" << std::endl;
	std::cout << "E-mail: " << użytkownik.getEmail() << std::endl;
	std::cout << "Adres: " << użytkownik.getAdres() << std::endl;
	std::cout << "Tel.: " << użytkownik.getTelefon() << std::endl;
	std::cout << "PESEL: " << użytkownik.getPESEL() << std::endl;
	system("pause");
	userInterfacePracownikZalogowany();
}

void Zwroc()
{
	KartaBiblioteczna karta;
	Zbior zbior;
	Ksiazka ksiazka;
	KatalogUzytkownikow katalog;
	Osoba osoba;
	int idKaiazki=0;
	int idUzytkownik;
	system("CLS");
	std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
	std::cout << "[Zwrot]\nPodaj ID Książki: ";
	std::cin >> idKaiazki;
	std::cin.ignore();
	ksiazka = zbior.getKsiazka(idKaiazki);
	if (ksiazka.getTytul().empty())
	{
		std::cout << "Nie znaleziono!!!" << std::endl;
		system("pause");
		userInterfacePracownikZalogowany();
	}
	std::cout << "Podaj ID Karty Bibliotecznej Czytelnika: ";
	std::cin >> idUzytkownik;
	std::cin.ignore();
	osoba = katalog.getWszystkieDane(idUzytkownik, "czytelnicy.txt");
	if (osoba.getImie().empty())
	{
		std::cout << "Nie znaleziono!!!" << std::endl;
		system("pause");
		userInterfacePracownikZalogowany();
	}
	karta.deleteWpis(idUzytkownik, idKaiazki);
	std::cout << "Zwracanie..." << std::endl;
	system("pause");
	userInterfacePracownikZalogowany();
}

void dodajPozycje()
{
	std::cin.ignore();
	Zbior zbior;
	Ksiazka ksiazka;
	Autor autor;
	bool wlasciweDane;
	int decyzja;
	std::string tytul;
	std::string rokWydania;
	std::string autorImie;
	std::string autorNazwisko;
	int iloscStron=-1;
	int iloscEgzemplarzy = -1;
	while (true)
	{
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		if (tytul.empty())
		{
		
			std::cout << "Podaj Tytul: ";
			std::getline(std::cin, tytul);
			std::cout << "Czy " << tytul << " to na pewno właściwy tytuł?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
			wlasciweDane = false;
			while (!wlasciweDane)
				{
				std::cin >> decyzja;
				std::cin.ignore();
				switch (decyzja)
				{
				case 1: ksiazka.setTytul(tytul); wlasciweDane = true; break;
				case 2: tytul = "";  wlasciweDane = true; break;
				default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
				}
			}	
		
		}
		else if (autorImie.empty())
		{

			std::cout << "Podaj imie autora: ";
			std::getline(std::cin, autorImie);
			std::cout << "Czy " << autorImie << " to na pewno właściwe imie autora?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
			wlasciweDane = false;
			while (!wlasciweDane)
			{
				std::cin >> decyzja;
				std::cin.ignore();
				switch (decyzja)
				{
				case 1: ksiazka.setAutorImie(autorImie); autor.setImie(autorImie); wlasciweDane = true; break;
				case 2: autorImie = "";  wlasciweDane = true; break;
				default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
				}
			}
		}
		else if (autorNazwisko.empty())
		{

			std::cout << "Podaj nazwisko autora: ";
			std::getline(std::cin, autorNazwisko);
			std::cout << "Czy " << autorNazwisko << " to na pewno właściwe nazwisko autora?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
			wlasciweDane = false;
			while (!wlasciweDane)
			{
				std::cin >> decyzja;
				std::cin.ignore();
				switch (decyzja)
				{
				case 1: ksiazka.setAutorNazwisko(autorNazwisko); autor.setNazwisko(autorNazwisko); wlasciweDane = true; break;
				case 2: autorNazwisko = "";  wlasciweDane = true; break;
				default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
				}
			}
		}
		else if (rokWydania.empty())
		{

			std::cout << "Podaj rok wydania: ";
			std::getline(std::cin, rokWydania);
			std::cout << "Czy " << rokWydania << " to na pewno właściwy rok wydania?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
			wlasciweDane = false;
			while (!wlasciweDane)
			{
				std::cin >> decyzja;
				std::cin.ignore();
				switch (decyzja)
				{
				case 1: ksiazka.setRokWydania(rokWydania); wlasciweDane = true; break;
				case 2: rokWydania = "";  wlasciweDane = true; break;
				default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
				}
			}
		}
		else if (iloscStron==-1)
		{

			std::cout << "Podaj ilosc stron: ";
			std::cin >> iloscStron;
			std::cin.ignore();
			std::cout << "Czy " << iloscStron << " to na pewno właściwy rok wydania?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
			wlasciweDane = false;
			while (!wlasciweDane)
			{
				std::cin >> decyzja;
				std::cin.ignore();
				switch (decyzja)
				{
				case 1: ksiazka.setIloscStron(iloscStron); wlasciweDane = true; break;
				case 2: iloscStron = -1;  wlasciweDane = true; break;
				default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
				}
			}
		}
		else if (iloscEgzemplarzy == -1)
		{

			std::cout << "Podaj ilosc egzemplarzy: ";
			std::cin >> iloscEgzemplarzy;
			std::cin.ignore();
			std::cout << "Czy " << iloscEgzemplarzy << " to na pewno właściwy rok wydania?\n[1] - Tak" << std::setw(20) << "[2] - Nie" << std::endl;
			wlasciweDane = false;
			while (!wlasciweDane)
			{
				std::cin >> decyzja;
				std::cin.ignore();
				switch (decyzja)
				{
				case 1: ksiazka.setIloscEgzemplarzy(iloscEgzemplarzy); wlasciweDane = true; break;
				case 2: iloscEgzemplarzy = -1;  wlasciweDane = true; break;
				default: std::cout << "Opcja o id: " << decyzja << " nie istnieje! Podaj właściwą opcję!" << std::endl;
				}
			}
		}
		else
		{
			ksiazka.setID();
			zbior.addKsiazka(ksiazka, autor);
			std::cout << "Dodano pozycję!" << std::endl;
			system("pause");
			userInterfacePracownikZalogowany();
		}
	}
}

void usunPozycje()
{
	Zbior zbior;
	Ksiazka ksiazka;
	int idKaiazki;
	std::cout << "[Zwrot]\nPodaj ID Książki: ";
	std::cin >> idKaiazki;
	std::cin.ignore();
	ksiazka = zbior.getKsiazka(idKaiazki);
	if (ksiazka.getTytul().empty())
	{
		std::cout << "Nie znaleziono!!!" << std::endl;
		system("pause");
		userInterfacePracownikZalogowany();
	}
	zbior.deleteKsiazka(idKaiazki);
	userInterfacePracownikZalogowany();
}

void userInterfacePracownikZalogowany()
{
	system("CLS");
	std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
	std::cout << "Opcje :\n";
	std::cout << "[1] - Zwróć" << std::setw(33) << "[2] - Dodaj pozycję " << std::endl;
	std::cout << "[3] - Usuń pozycję" << std::setw(38)<<"[4] - Przeglądaj zbiór"<<std::endl;
	std::cout << "[5] - Zobacz swoje dane" << std::setw(38)<< "[6] - Wyloguj się " << std::endl;
	int decide;
	std::cin >> decide;
	switch (decide)
	{
	case 1:
		Zwroc();
		break;
	case 2:
		dodajPozycje();
		break;
	case 3:
		usunPozycje();
		break;
	case 4:
		wyswietlZbiorPracownik();
		break;
	case 5:
		wyswietlDanePracownika();
		break;
	case 6:
		std::cout << "Wylogowywanie..." << std::endl;
		system("pause");
		userInterface();
		break;
	default:
		std::cout << "Opcja o id: " << decide << " nie istnieje! Podaj właściwą opcję!" << std::endl;
		system("pause");
		userInterfacePracownikZalogowany();
	}
}


void wyswietlZbiorPracownik()
{
	KartaBiblioteczna kartaBiblioteczna;
	KatalogUzytkownikow katalog;
	Ksiazka ksiazka;
	unsigned int IDksiazki;
	int poczatek = 1;
	int koniec = 10;
	Zbior zbior;
	while (true)
	{
		system("CLS");
		std::cout << "**<< Biblioteka >>**" << std::endl << std::endl << std::endl;
		std::cout << "Pozycje:\n";
		zbior.WypiszTytuly(poczatek, koniec);
		std::cout << std::endl << std::endl << "[1] - Następna strona" << std::setw(29) << "[2] - Poprzednia strona" << std::setw(21)  << "[3] - Powrót" << std::endl;
		int decide;
		std::cin >> decide;
		std::cin.ignore();
		switch (decide)
		{
		case 1:
			poczatek += 10;
			koniec += 10;
			break;
		case 2:
			poczatek -= 10;
			koniec -= 10;
			break;
		case 3:
			userInterfacePracownikZalogowany();
			break;
		default:
			std::cout << "Opcja o id: " << decide << " nie istnieje! Spróbuj ponownie!" << std::endl;
			system("pause");
		}
	}
}