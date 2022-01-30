#include "calc.h"
#include "pocketcalculator.h"
#include "sevensegment.h"

#include <iostream>
#include <stdexcept>

void pocketcalculator(std::istream & is, std::ostream & os) {
	while (is.good()) { //Hier koennte mit std::getline einfach eine Zeile gelesen werden, von welcher man einen neuen istringstream konstrutiert. Dann muesste man den Stream-State nicht explizit veraendern und das return bei peek() ==-1 waere nicht noetig.
		int result = 0; //Die Variable sollte bei der ersten verwendung deklariert werden.
		if (is.peek() == -1)
		{
			return;
		}

		try {
			result = calc(is);
			printLargeNumber(result, os); //Die Limitierung der Ausgabebreite nicht beachtet.
		} catch (std::invalid_argument const &) //Gut, per const & gefangen.
		{
			printLargeError(os);
			is.setstate(std::ios::goodbit); //Hier koennte man einfach is.clear() aufrufen. Das goodbit ist quasi kein gesetzter Wert (der Name ist irrefuehrend).
		}
	}
}
