#include "calc.h" //Eigener Include zuerst

#include <istream> //Gut
#include <stdexcept>

int calc(int lhs, int rhs, char op) {
	int result = 0; //Den Umweg über die lokale Variable bräuchte es nicht. Direkt mit return das Resultat zurückgeben wäre besser.

	switch (op)
	{
		case '+':
			result = lhs + rhs;
			break;
		case '-' :
			result = lhs - rhs;
			break;
		case '*' :
			result = lhs * rhs;
			break;
		case '/' :
			//Gut / 0 abgefangen
			if (rhs == 0) throw std::invalid_argument("Division by 0 is forbidden!"); //Auch Exceptions mit {} initialisieren
			result =  lhs / rhs;
			break;
		case '%' :
			//Gut % 0 abgefangen
			if (rhs == 0) throw std::invalid_argument("Modulo by 0 is forbidden!");
			result = lhs % rhs;
			break;
			//Gut, ungültigen Operator abgefangen
		default:  throw std::invalid_argument("Not available operator used.");
	}
	return result;
}

int calc(std::istream & in) {
	int lhs, rhs = 0; //Dürfte man hier uninitialisiert lassen, da sie sowieso eingelesen oder sonst nicht verwendet werden.
	char op;

	if(in >> lhs >> op >> rhs) { //Gut
		return calc(lhs, rhs, op);
	}
	throw std::invalid_argument{"Invalid input!"};

}
