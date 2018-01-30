#include <gtest/gtest.h>

#include <gsl/gsl>
#include <iostream>
#include <limits>


TEST(narrow_cast, valid) {
	int a = 42;
	unsigned char c = a;

	std::cout << "a=" << a << "\tc=" << static_cast<int>(c) << std::endl;

	EXPECT_EQ(c, a);
}

TEST(narrow_cast, overflow_implicit_cast) {
	int a = std::numeric_limits<unsigned char>::max() + 15;
	unsigned char c = a;

	std::cout << "a=" << a << "\tc=" << static_cast<int>(c) << std::endl;

	EXPECT_NE(c, a);
}

TEST(narrow_cast, overflow_c_cast) {
	int a = std::numeric_limits<unsigned char>::max() + 15;
	unsigned char c = (unsigned char)a;

	std::cout << "a=" << a << "\tc=" << static_cast<int>(c) << std::endl;

	EXPECT_NE(c, a);
}

TEST(narrow_cast, overflow_static_cast) {
	int a = std::numeric_limits<unsigned char>::max() + 15;
	unsigned char c = static_cast<unsigned char>(a);

	std::cout << "a=" << a << "\tc=" << static_cast<int>(c) << std::endl;

	EXPECT_NE(c, a);
}

TEST(narrow_cast, overflow_narrow_cast) {
	int a = std::numeric_limits<unsigned char>::max() + 15;

	// we explicitly ask for narrowing conversion:
	unsigned char c = gsl::narrow_cast<unsigned char>(a);

	std::cout << "a=" << a << "\tc=" << static_cast<int>(c) << std::endl;

	EXPECT_NE(c, a);
}


TEST(narrow_cast, overflow_narrow) {
	int a = std::numeric_limits<unsigned char>::max() + 15;
	unsigned char c = 0;

	EXPECT_DEATH(
		c = gsl::narrow<unsigned char>(a),
		".*"
	);
}

TEST(narrow_cast, no_overflow_narrow) {
	int a = 0;
	unsigned char c = 0;

	c = gsl::narrow<unsigned char>(a);

	std::cout << "a=" << a << "\tc=" << static_cast<int>(c) << std::endl;

	EXPECT_EQ(c, a);
}


