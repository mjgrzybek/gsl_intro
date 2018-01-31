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
	// auto ss = s.subspan<2,5>();

	display(ss);

	EXPECT_TRUE(ss == ss);
	EXPECT_FALSE(ss != ss);

	EXPECT_TRUE(s != ss);
	EXPECT_FALSE(s == ss);
}


TEST(span, array) {
	using DataT = char;
	std::array<DataT, 9> v { 'D', 'y', 'n', 'a', 't', 'r', 'a', 'c', 'e'};

	gsl::span<DataT> s {v};
	display(s);

	auto ss = s.subspan(2,5);
	display(ss);

	EXPECT_TRUE(ss == ss);
	EXPECT_FALSE(ss != ss);

	EXPECT_TRUE(s != ss);
	EXPECT_FALSE(s == ss);
}


TEST(span, vector) {
	using DataT = char;
	std::vector<DataT> v { 'D', 'y', 'n', 'a', 't', 'r', 'a', 'c', 'e'};

	gsl::span<DataT> s {v};
	display(s);

	auto ss = s.subspan(2,5);
	display(ss);

	EXPECT_TRUE(ss == ss);
	EXPECT_FALSE(ss != ss);

	EXPECT_TRUE(s != ss);
	EXPECT_FALSE(s == ss);
}

TEST(span, element_access) {
	int arr[] = {1,2,3,4,5};
	gsl::span<int> s {arr};
	
	const auto sz = s.size();
	EXPECT_EQ(sz, 5);

	for(size_t i=0; i<sz; ++i)
		EXPECT_EQ(arr[i], s[i]); 

	// boundries safety:
	const size_t out_of_bounds_idx = 10;

	std::cout << ">>>>" << arr[out_of_bounds_idx] << "<<<<" << std::endl;

	//std::cout << ">>>>" << s[out_of_bounds_idx] << "<<<<" << std::endl;
	EXPECT_DEATH(std::cout << ">>>>" << s[out_of_bounds_idx] << "<<<<" << std::endl, ".*");
}
