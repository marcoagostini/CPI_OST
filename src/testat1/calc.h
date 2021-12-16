#ifndef CALC //Guard vorhanden
#define CALC
#include <iosfwd> //Korrekter include

int calc(int lhs, int rhs, char op); //Deklarationen sind korrekt
int calc(std::istream & in);

#endif
