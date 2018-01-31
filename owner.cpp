#include <gtest/gtest.h>

#include <gsl/gsl>
#include <iostream>


TEST(owner, has_ownership) {
	gsl::owner<int*> ptr = new int;	
	
	// OK
	delete ptr;
}

TEST(owner, unknown_ownership) {
	int* ptr = new int;

	// technically OK, but static code analyzer should complain
	delete ptr;
}

