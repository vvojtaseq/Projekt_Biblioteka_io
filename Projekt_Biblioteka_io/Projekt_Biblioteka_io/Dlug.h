#pragma once
#include "includy.h"
class Dlug
{
	float WartoscDlugu;
	//to beda miec tylko uzytkownicy, bibliotekarz nie powinien miec dlugu
	// pomysl - co jesli bibliotekarz bedzie mogl zobaczyc swoje wynagrodzenie?
	//zalezne od power levelu
	public:
		float getWartoscDlugu() { return WartoscDlugu; }
		void setWartoscDlugu(float nowaWartoscDlugu) { WartoscDlugu = nowaWartoscDlugu; }
		Dlug(float wartoscDlugu)
		{
			WartoscDlugu = wartoscDlugu;
		}
		Dlug() {};
};

