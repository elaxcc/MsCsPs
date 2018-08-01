#include "stdafx.h"

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	int test_res = RUN_ALL_TESTS();

	char a;
	std::cin >> a;

	return test_res;
}

