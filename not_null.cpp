#include <gtest/gtest.h>

#include <gsl/gsl>
#include <iostream>

void null_allowed(int* val)
{
	std::cout << *val << std::endl;
	*val = 271;
}

void null_protected(gsl::not_null<int*> val)
{
	std::cout << *val << std::endl;
	*val = 271;
}

/* ========================================== */

TEST(not_null, valid_ptr_vs_allowed) {
	auto ptr = std::make_unique<int>(42);
	null_allowed(ptr.get());
}

TEST(not_null, valid_ptr_vs_protected) {
	auto ptr = std::make_unique<int>(42);
	null_allowed(ptr.get());
}

TEST(not_null, null_ptr_vs_allowed) {
	ASSERT_EXIT(
		(null_allowed(nullptr), exit(0)),
		::testing::KilledBySignal(SIGSEGV),
		""
	);
}

TEST(not_null, null_ptr_vs_protected) {
	int* ptr = nullptr;
	null_protected(ptr);
}

//TEST(not_null, null_ptr_vs_protected_2) {
//	null_protected(nullptr);	
//}

