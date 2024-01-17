#include "pch.h"
#include "CppUnitTest.h"
//#include "main.cpp"
#include "Includy.h"
#include "IncludyKlasy.h"

//Je�li nie dzia�a to w zak�adce 
//Projekt / W�a�ciwo�ci UnitTest1 / C/C++ / Og�lne / Dodatkowe Plki Katalog�w nag�owkowych
//Doda� �cie�k� w kt�rej znajduje si� ,,Projekt_Biblioteka_io"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	Osoba testOsoba;
	Autor testAutor;
	Ksiazka testKsiazka;
	Czytelnik testCzytelnik;
	Dlug testDlug;
	//Wypozyczenie testWypozyczenie;


	TEST_CLASS(Osoba)
	{

	public:

		TEST_METHOD(getImie)
		{
			testOsoba.setImie("Adam");
			std::string name = "Adam";
			Assert::AreEqual(testOsoba.getImie(), name);
		}
		TEST_METHOD(getNazwisko)
		{
			testOsoba.setNazwisko("Kowalski");
			std::string surename = "Kowalski";
			Assert::AreEqual(testOsoba.getNazwisko(), surename);
		}
		TEST_METHOD(getAdres)
		{
			testOsoba.setAdres("Prosta 4");
			std::string adres = "Prosta 4";
			Assert::AreEqual(testOsoba.getAdres(), adres);
		}
		TEST_METHOD(getDataUrodzenia)
		{
			testOsoba.setDataUrodzenia("11.12.1994");
			std::string data = "11.12.1994";
			Assert::AreEqual(testOsoba.getDataUrodzenia(), data);
		}
		TEST_METHOD(getTelefon)
		{
			//zmiana typu Telefon ze string na unsigned int
			testOsoba.setTelefon("123456789");
			std::string telefon ="123456789";
			Assert::AreEqual(testOsoba.getTelefon(), telefon);
		}
		TEST_METHOD(getPesel)
		{
			testOsoba.setPESEL("99999999999");
			std::string pesel = "99999999999";
			Assert::AreEqual(testOsoba.getPESEL(), pesel);
		}
	};
	TEST_CLASS(Ksiazka)
	{
		public:
			TEST_METHOD(getTytul)
			{
			testKsiazka.setTytul("Pan Tadeusz");
			std::string tytul = "Pan Tadeusz";
			Assert::AreEqual(testKsiazka.getTytul(), tytul);
		}
			TEST_METHOD(getRokWydania)
			{
			testKsiazka.setRokWydania("1999");
			std::string rok = "1999";
			Assert::AreEqual(testKsiazka.getRokWydania(), rok);
		}
			TEST_METHOD(getIloscStron)
			{
			testKsiazka.setIloscStron(100);
			int strony = 100;
			Assert::AreEqual(testKsiazka.getIloscStron(), strony);
		}
			TEST_METHOD(getIloscEgzemplarzy)
			{
			testKsiazka.setIloscEgzemplarzy(10);
			int egzemplarze = 10;
			Assert::AreEqual(testKsiazka.getIloscEgzemplarzy(), egzemplarze);
		}
			TEST_METHOD(getID)
			{
			testKsiazka.setID(1);
			int id = 1;
			Assert::AreEqual(testKsiazka.getID(), id);
		}
			TEST_METHOD(getAutor)
			{
			testKsiazka.setAutor("Adam Kowalski");
			std::string autor = "Adam Kowalski";
			Assert::AreEqual(testKsiazka.getAutor(), autor);
		}
	
	};
	TEST_CLASS(Autor)
	{
		public:
			TEST_METHOD(getImie)
			{
			testAutor.setImie("Adam");
			std::string imie = "Adam";
			Assert::AreEqual(testAutor.getImie(), imie);
		}
			TEST_METHOD(getNazwisko)
			{
			testAutor.setNazwisko("Kowalski");
			std::string nazwisko = "Kowalski";
			Assert::AreEqual(testAutor.getNazwisko(), nazwisko);
		}
			TEST_METHOD(getOpis)
			{
			testAutor.setOpis("Opis");
			std::string opis = "Opis";
			Assert::AreEqual(testAutor.getOpis(), opis);
		}
			
	};
	TEST_CLASS(Dlug)
	{
		public:
			TEST_METHOD(getWartoscDlugu)
			{
			testDlug.setWartoscDlugu(100);
			float wartosc = 100;
			Assert::AreEqual(testDlug.getWartoscDlugu(), wartosc);
		}
	};
	
}
