#include <vector>
#include <algorithm>
#include <string>

#include "kwic.h"
#include "word.h"

#include <ostream>
#include <sstream>


namespace text {

using wordVector = std::vector<Word>;

void kwic(std::istream & is, std::ostream & os) {
	std::vector<wordVector> inputlines { };

	while (is.good()) {
		std::string inputline {};
		std::getline(is, inputline);
		std::stringstream ss(inputline);

		Word singleWord {};
		wordVector line;

		for (std::string::iterator it = inputline.begin(); it != inputline.end(); ++it) {
			if(ss >> singleWord) {
				line.push_back(singleWord);

			}
		}

		for (int i = 0; i < line.size(); i++) {
			inputlines.push_back(line);
			std::rotate(line.begin(), line.begin() + 1, line.end());
		}

	}

	std::sort(inputlines.begin(), inputlines.end());

	std::for_each(inputlines.begin(), inputlines.end(), [& os](auto line){

		std::for_each(line.begin(), line.end(), [& os](auto word){
			os << word << " ";
		});

		os << std::endl;
	});

}




}
