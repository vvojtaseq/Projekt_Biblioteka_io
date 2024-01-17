#include "pch.h"
#include "CppUnitTest.h"
//#include "main.cpp"
#include "Includy.h"
#include "IncludyKlasy.h"
#include "Autor.h"

//Jeœli nie dzia³a to w zak³adce 
//Projekt / W³aœciwoœci UnitTest1 / C/C++ / Ogólne / Dodatkowe Plki Katalogów nag³owkowych
//Dodaæ œcie¿kê w której znajduje siê ,,Projekt_Biblioteka_io"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	Osoba test;
	TEST_CLASS(Osoba)
	{

	public:

		TEST_METHOD(getImie)
		{
			test.setImie("Adam");
			std::string name = "Adam";
			Assert::AreEqual(test.getImie(), name);
		}
		TEST_METHOD(getNazwisko)
		{
			test.setNazwisko("Kowalski");
			std::string surename = "Kowalski";
			Assert::AreEqual(test.getNazwisko(), surename);
		}
		TEST_METHOD(getAdres)
		{
			test.setAdres("Prosta 4");
			std::string adres = "Prosta 4";
			Assert::AreEqual(test.getAdres(), adres);
		}
		TEST_METHOD(getDataUrodzenia)
		{
			test.setDataUrodzenia("11.12.1994");
			std::string data = "11.12.1994";
			Assert::AreEqual(test.getDataUrodzenia(), data);
		}
		TEST_METHOD(getTelefon)
		{
			//zmiana typu Telefon ze string na unsigned int
			test.setTelefon("123456789");
			std::string telefon ="123456789";
			Assert::AreEqual(test.getTelefon(), telefon);
		}
		TEST_METHOD(getPesel)
		{
			test.setPESEL("99999999999");
			std::string pesel = "99999999999";
			Assert::AreEqual(test.getPESEL(), pesel);
		}
	};
	TEST_CLASS(Czytelnik)
	{};
	TEST_CLASS(Ksiazka)
	{
	
	};
	TEST_CLASS(Wypozyczenie)
	{
	
	};
	TEST_CLASS(Autor)
	{
		Autor autor;
		public:
			TEST_METHOD(getImie)
			{
			testAutor.setImie("Adam");
			std::string name = "Adam";
			Assert::AreEqual(testAutor.getImie(), name);
		}
	
	};
	
}
