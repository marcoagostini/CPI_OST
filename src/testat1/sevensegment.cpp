#include "sevensegment.h"
#include <array>
#include <vector>
#include <string>
#include <ostream>

//Die Magic Number 5 koennte man noch extrahieren. Wird weiter unten auch verwendet.
const std::array<std::string, 5> ZERO{" - ", "| |", "   ", "| |", " - "}; ///Namen die nur aus Grossbuchstaben bestehen, sollten in C++ nicht verwendet werden, da sie ein Praeprozessor-Makro implizieren.
const std::array<std::string, 5> ONE{"   ", "  |", "   ", "  |", "   "};
const std::array<std::string, 5> TWO{" - ", "  |", " - ", "|  ", " - "};
const std::array<std::string, 5> THREE{" - ", "  |", " - ", "  |", " - "};
const std::array<std::string, 5> FOUR{"   ", "| |", " - ", "  |", "   "};
const std::array<std::string, 5> FIVE{" - ", "|  ", " - ", "  |", " - "};
const std::array<std::string, 5> SIX{" - ", "|  ", " - ", "| |", " - "};
const std::array<std::string, 5> SEVEN{" - ", "  |", "   ", "  |", "   "};
const std::array<std::string, 5> EIGHT{" - ", "| |", " - ", "| |", " - "};
const std::array<std::string, 5> NINE{" - ", "| |", " - ", "  |", " - "};

const std::array<std::string, 5> E{" - ", "|  ", " - ", "|  ", " - "};
const std::array<std::string, 5> R{"   ", "   ", " - ","|  ", "   "};
const std::array<std::string, 5> O{"   ", "   ", " - ", "| |", " - "};
const std::array<std::string, 5> MINUS{"   ", "   ", " - ", "   ", "   "};

const std::array<std::array<std::string, 5>, 11> DIGITS{ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, MINUS};
const std::array<std::array<std::string, 5>, 10> ERROR{E, R, R, O, R};

void printLargeDigit(int i, std::ostream & out) {
	//Die lokale Kopie outString breauchte es nicht. Grundsaetzlich ist aber nichts gegen erklaerende lokale Variablen einzuwenden. outString ist aber kein sehr sprechender name und auch nicht so ganz richtig.
	std::array<std::string, 5> const outString = DIGITS.at(i);
		for (auto const & cref : outString){ //Hier haette man den copy-Algorithmus verwenden koennen
			out << cref << '\n';
		}
}

//Tipp: Dies koennte etwas einfacher mit std::to_stirng geloest werden.
void splitNumber(std::vector<int> & digits, int number){ //Statt digits ueber einen Seiteneffekt zu veraendern, waere es besser den digits-Vector nicht als Parameter zu nehmen, sondern einfach einen neuen digits-Vector zurueckzugeben (per value).
	if(number > 9){
		splitNumber(digits, (number/10));
	}
	digits.push_back(number%10);
}

void printLargeNumber(int number, std::ostream & out){
	std::vector<int> digits{}; //Variablen erst vor der ersten Verwendung deklarieren. Bzw. im Fall von digits besser direkt mit dem splitNumber-Call zusammenfassen (siehe Kommentar oben)
	bool negative = false;

	if(number < 0){
		negative = true;
		number *= -1;
	}
	splitNumber(digits, number);

	for (int i = 0; i<5;i++)
	{
		if(negative){
			out << MINUS[i];
		}

		for (int const digit : digits)
		{
			out << DIGITS[digit][i];
		}
			out << '\n'; //Einrueckung
	}
}

void printLargeError(std::ostream &out){
	for (int i = 0; i<5; i++){
		for(auto const & cref : ERROR){
			out << cref[i];
		}
		out << '\n';
	}
}

//Gute Loesung
