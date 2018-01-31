#include <gtest/gtest.h>

#include <iostream>
#include <gsl/gsl>

TEST(finally, clean_memory) {
	int* i = new int[16];
	
	try {
		auto _ = gsl::finally(
			[&]() {
				std::cout << "Cleaning!" << std::endl;
				delete[] i;	
			}
		);

		throw std::exception();

		std::cout << "never printed" << std::endl;
	}
	catch(const std::exception&)
	{}
}
