#include <gtest/gtest.h>

#include <gsl/gsl>
#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <string>

template<typename T>
void display(gsl::span<T> collection) 
{
	std::cout << "size=" << collection.size();
	std::cout << "\t";
	for(const auto& elem : collection)
		std::cout << elem << " ";

	std::cout << std::endl;	
}

template<typename T>
void display_old(T* collection, size_t len)
{
	for(size_t idx=0; idx<len; ++idx)
		std::cout << collection[idx];

        std::cout << std::endl;
}


/* ========================================== */

TEST(span, carray) {
	using DataT = char;
	DataT v[9] = { 'D', 'y', 'n', 'a', 't', 'r', 'a', 'c', 'e'};

	gsl::span<DataT> s {v};
	display(s);

	auto ss = s.subspan(2,5);
	display(ss);
}


TEST(span, array) {
	using DataT = char;
	std::array<DataT, 9> v { 'D', 'y', 'n', 'a', 't', 'r', 'a', 'c', 'e'};

	gsl::span<DataT> s {v};
	display(s);

	auto ss = s.subspan(2,5);
	display(ss);
}


TEST(span, vector) {
	using DataT = char;
	std::vector<DataT> v { 'D', 'y', 'n', 'a', 't', 'r', 'a', 'c', 'e'};

	gsl::span<DataT> s {v};
	display(s);

	auto ss = s.subspan(2,5);
	display(ss);
}

