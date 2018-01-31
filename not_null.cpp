#include <gtest/gtest.h>

#include <gsl/gsl>
#include <iostream>

oid nullAllowed(int* val)
{
	std::cout << *val << std::endl;
	*val = 271;
}

void nullProtected(gsl::not_null<int*> val)
{
	std::cout << *val << std::endl;
	*val = 271;
}

/* ========================================== */

TEST(not_null, valid_ptr_vs_allowed) {
	auto ptr = std::make_unique<int>(42);
	nullAllowed(ptr.get());
}

TEST(not_null, valid_ptr_vs_protected) {
	auto ptr = std::make_unique<int>(42);
	nullAllowed(ptr.get());
}

TEST(not_null, null_ptr_vs_allowed) {
	ASSERT_EXIT(
		(nullAllowed(nullptr), exit(0)),
		::testing::KilledBySignal(SIGSEGV),
		".*"
	);
}

TEST(not_null, null_ptr_vs_protected) {
	int* ptr = nullptr;
	EXPECT_DEATH(nullProtected(ptr), ".*"); // std::terminate to be called 
}

//TEST(not_null, null_ptr_vs_protected_2) {
//	nullProtected(nullptr);	
//}

