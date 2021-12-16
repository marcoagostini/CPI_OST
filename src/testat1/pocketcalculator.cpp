#include <iostream>
#include <stdexcept>

#include "calc.h" //Eigene Includes ("") sollten vor System-Include (<>) stehen
#include "pocketcalculator.h" //Eigener Include sollte zuerst stehen
#include "sevensegment.h"

void pocketcalculator(std::istream & is, std::ostream & os) {
	while (is.good()) { //Hier könnte mit std::getline einfach eine Zeile gelesen werden, von welcher man einen neuen istringstream kosntruiert. Dann müsste man den Stream-State nicht explizit verändern und das return bei peek() == -1 wäre nicht nötig.
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
			is.setstate(std::ios::goodbit); //Hier könnte man einfach is.clear() aufrufen. Das goodbit ist quasi kein gesetzter Wert (der Name ist irreführend).
		}
	}
}
