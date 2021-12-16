#ifndef WORD_C_
#define WORD_C_

#include <string>

namespace text {

class Word {
	std::string word{"default"};
public:
	Word() = default;
	// does block unwanted casting
	explicit Word(std::string const input);
	explicit Word(std::istream & in);
	bool operator <(Word const & w) const;
	bool operator ==(Word const & w) const;
	void read(std::istream & in);

	// a friend has access to private members
	friend std::istream & operator>>(std::istream & is, Word & word);
	friend std::ostream & operator<<(std::ostream & os, Word const & word);
};

inline bool operator>(Word const& lhs, Word const& rhs) {
	return rhs < lhs;
}
inline bool operator>=(Word const& lhs, Word const& rhs) {
	return !(lhs < rhs);
}
inline bool operator<=(Word const& lhs, Word const& rhs) {
	return !(rhs < lhs);
}
inline bool operator!=(Word const& lhs, Word const& rhs) {
	return !(lhs == rhs);
}

}


#endif

