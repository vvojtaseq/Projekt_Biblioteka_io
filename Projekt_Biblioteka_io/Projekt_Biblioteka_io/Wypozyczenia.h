// cd /c/Users/mania/Biblioteka
#pragma once
#include "Includy.h"
class Wypozyczenia
{
private:
	std::chrono::hours DwaTygodnie = std::chrono::hours(2*7*24);
	std::chrono::system_clock::time_point DataZwrotu;

public:
	void Przedluz() 
	{
		std::chrono::system_clock::time_point Temp = DataZwrotu + DwaTygodnie;
		DataZwrotu = Temp;
	}
	Wypozyczenia() : DwaTygodnie(2 * 7 * 24), DataZwrotu(std::chrono::system_clock::now() + DwaTygodnie) {}  // powinno automatycznie tworzyc date odbioru dwa tygodnie po stworzeniu var

	std::chrono::system_clock::time_point PobierzDataZwrotu() const {
		return DataZwrotu;
	}
	void WyswietlDate()
	{
		std::time_t Czas = std::chrono::system_clock::to_time_t(DataZwrotu);
		std::tm StrukturaCzasu;

		if (localtime_s(&StrukturaCzasu, &Czas) == 0)
		{
			const int bufferSize = 11; // buffer dla zformatowanej daty
			char buffer[bufferSize];

			// Format the date as day/month/year
			if (std::strftime(buffer, bufferSize, "%d/%m/%Y", &StrukturaCzasu) != 0) // robimy dzien/miesiac/rok
			{
				std::cout << "Data zwrotu ksi¹¿ki to : " << buffer << std::endl; // to do - z klasy wypozyczone pobrac wypozyczone przez nas ksiazki i w tym coucie dodac nazwe ksiazki, oraz dodac petle zeby sie powtarzalo dla kazdej ksiazki
			}
		}
	}
};