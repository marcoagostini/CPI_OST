#ifndef SRC_Ring13_H_
#define SRC_Ring13_H_

#include <array>
#include <cctype>
#include <stdexcept>


template <typename T>
class Ring13 {
  using list = std::array<T, 13>;
  using key_type = decltype(char{});
  using value_type = typename list::value_type;
  using reference_type = typename list::reference;
  using const_reference = typename list::const_reference;
  using size_type = typename list::size_type;

  list internal{};
public:
  Ring13() {
	  internal.fill(value_type{});
  }
  explicit Ring13(T value) {
	  internal.fill(value);
  }

  int size() const {
	  return internal.size();
  }

  reference_type at(char input) {
	  int in = valueCheck(input);
	  return internal.at(in % (int)13);
  }

  bool empty() const {
	  return internal.empty();
  }

  void erase(char input) {
	  int in = valueCheck(input);
	  internal.at(in) = value_type{};
  }

  int valueCheck(int i) {
	  if(std::isalpha(i)) {
		  throw std::invalid_argument{""};
	  }
	  return i;
  }

};

#endif
