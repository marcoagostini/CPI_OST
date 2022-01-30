#include "indexableSet.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <algorithm>
#include <cctype>

#include <string>
// Tests written with D.H.


void test_construction_of_empty_indexableSet(){
	auto set = indexableSet<int>{};
	ASSERT_EQUAL(set.size(), 0);
}

void test_accessing_empty_indexableSet(){
	auto set = indexableSet<int>{};
	ASSERT_THROWS(set.at(1), std::out_of_range);
}

void test_positiv_index_at(){
	indexableSet<int> set{1,2,3,4,5,6,7,8,9,10};
	ASSERT_EQUAL(set.at(8), 9);
}

void test_negative_index_at(){
	indexableSet<int> set{1,2,3,4,5,6,7,8,9,10};
	ASSERT_EQUAL(set.at(-8), 3);
}

void test_to_large_opositiv_index_at(){
	indexableSet<int> set{1,2,3,4,5,6,7,8,9,10};
	ASSERT_THROWS(set.at(12), std::out_of_range);
}

void test_positiv_index_acess_operator(){
	indexableSet<int> set{1,2,3,4,5,6,7,8,9,10};
	ASSERT_EQUAL(set[8], 9);
}

void test_negative_index_acess_operator(){
	indexableSet<int> set{1,2,3,4,5,6,7,8,9,10};
	ASSERT_EQUAL(set[-8], 3);
}

void test_to_large_opositiv_index_acess_operator(){
	indexableSet<int> set{1,2,3,4,5,6,7,8,9,10};
	ASSERT_THROWS(set[12], std::out_of_range);
}

void test_front_member_function(){
	indexableSet<int> set{1,2,3,4,5,6,7,8,9,10};
	ASSERT_EQUAL(set.front(), 1);
}

void test_back_member_function(){
	indexableSet<int> set{1,2,3,4,5,6,7,8,9,10};
	ASSERT_EQUAL(set.back(), 10);
}

struct caselessCompare{
	bool operator()(std::string const lhs, std::string const rhs) const {
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), [](char c1, char c2){
			return tolower(c1) < tolower(c2);
		});
	}
};

void test_indexableSet_with_caselessCompare(){
	indexableSet<std::string, caselessCompare> stringSet{"c", "bb", "bc", "ac", "ab", "aa"};
	ASSERT_EQUAL(stringSet[0], "aa");
	ASSERT_EQUAL(stringSet[-1], "c");
}


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(test_construction_of_empty_indexableSet));
	s.push_back(CUTE(test_accessing_empty_indexableSet));
	s.push_back(CUTE(test_positiv_index_at));
	s.push_back(CUTE(test_negative_index_at));
	s.push_back(CUTE(test_to_large_opositiv_index_at));
	s.push_back(CUTE(test_positiv_index_acess_operator));
	s.push_back(CUTE(test_negative_index_acess_operator));
	s.push_back(CUTE(test_to_large_opositiv_index_acess_operator));
	s.push_back(CUTE(test_front_member_function));
	s.push_back(CUTE(test_back_member_function));
	s.push_back(CUTE(test_indexableSet_with_caselessCompare));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
