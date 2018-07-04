#include "stdafx.h"

#include "gtest/gtest.h"

#include <iostream>

unsigned fun(unsigned val)
{
	return val + 1;
}

TEST(my_test_group, test_fun)
{
	EXPECT_EQ(fun(2), 3);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	int test_res = RUN_ALL_TESTS();

	char a;
	std::cin >> a;

	return test_res;
}

