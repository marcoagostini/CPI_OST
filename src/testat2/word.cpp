#include "word.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <stdexcept>

namespace text {

Word::Word(std::string const input) {
	if(input.size() == 0) {
		throw std::invalid_argument("Can not create an empty word");
	}

	std::for_each(input.begin(), input.end(), [] (char const c) {
		if(isalpha(c) == 0) {
			throw std::invalid_argument("Can't create word with invalid args");
		}
	});

	word = input;
}

std::string toLowerCase(std::string const & s) {
	std::string temp = s;
	for (auto & c : temp) {
		c = tolower(c);
	}
	return temp;
}

bool Word::operator <(Word const & rhs) const {
	return toLowerCase(word) < toLowerCase(rhs.word);
}

bool Word::operator ==(Word const & rhs) const {
	return !toLowerCase(word).compare(toLowerCase(rhs.word));
}

std::ostream & operator<<(std::ostream & os, Word const & word) {
	os << word.word;
	return os;
}

std::istream & operator>>(std::istream & is, Word & word) {
	if(is.eof() || is.fail()) {
		is.setstate(std::ios::failbit);
		return is;
	}

	while (is.good()) {
		char input = is.peek();
		if (isalpha(input) == 0) {
			is.ignore();
		} else {
			break;
		}
	}

	std::string newword;

	while (is.good())
	{
		char x = is.peek();
		if(isalpha(x)) {
			newword.push_back(x);
			is.ignore();
		} else {
			break;
		}
	}

	if(!newword.empty()) {
		try {
			word = Word(newword);
		} catch (std::invalid_argument const &) {
			is.setstate(std::ios::failbit);
		}

	} else {
		is.setstate(std::ios::failbit);
	}

	return is;
}

}
