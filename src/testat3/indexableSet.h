#ifndef SRC_INDEXABLESET_H_
#define SRC_INDEXABLESET_H_

#include <functional>
#include <set>
#include <stdexcept>


template <typename T, typename COMPARE=std::less<T>>
struct indexableSet : std::set<T, COMPARE> {
	using indexableSetType = std::set<T, COMPARE>;
	using const_reference = typename indexableSetType::const_reference;
	using indexableSetType :: indexableSetType;

	const_reference operator[] (signed int i) const {
		int size = this->size();
		if(i >= size || i < - size) {
			throw std::out_of_range("Index out of bound exception!");
		}

		if(i < 0) {
			i = size + i;
		}

		auto itr = this->begin();
		for(int j = 0; j < i; j++) {
			itr++;
		}
		return *itr;
	}

	const_reference at(int i) const {
		return (*this)[i];
	}

	const_reference front() const {
		return (*this)[0];
	}

	const_reference back() const {
		return (*this)[-1];
	}
};

#endif /* SRC_INDEXABLESET_H_ */

