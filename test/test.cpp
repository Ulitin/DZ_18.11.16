#include <gtest/gtest.h>
#include"header.h"

TEST(Smoke, esey_test)
{
	int** a;
	a = new int *[5];
	for (int i = 0; i < 5; i++) {
		a[i] = new int[5];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = 0;
		}
	}
	EXPECT_TRUE(find_road(a,5,0,0,4,4) == 7 );
}

TEST(barrier, nomrmal_test)
{
	int** a;
	a = new int *[5];
	for (int i = 0; i < 5; i++) {
		a[i] = new int[5];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = 0;
		}
	}
	a[3][1] = -1;
	a[3][2] = -1;
	a[3][3] = -1;
	a[3][4] = -1;
	EXPECT_TRUE(find_road(a, 5, 0, 0, 4, 4) == 7);
}

TEST(barrier, hard_test)
{
	int** a;
	a = new int *[5];
	for (int i = 0; i < 5; i++) {
		a[i] = new int[5];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = 0;
		}
	}
	a[3][1] = -1;
	a[3][2] = -1;
	a[3][3] = -1;
	a[3][4] = -1;
	a[2][1] = -1;
	a[1][1] = -1;
	a[0][3] = -1;
	a[1][3] = -1;
	EXPECT_TRUE(find_road(a, 5, 0, 4, 4, 4) == 15);
}

TEST(test_fun, finish_equally_start)
{
	int** a;
	a = new int *[5];
	for (int i = 0; i < 5; i++) {
		a[i] = new int[5];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = 0;
		}
	}
	EXPECT_TRUE(find_road(a, 5, 0, 0, 0, 0) == 0);
}

TEST(test_fun, throw1)
{
	int** a = 0;
	ASSERT_ANY_THROW(find_road(a, 5, 0, 0, 4, 4));
}

TEST(test_fun, throw2)
{
	int** a;
	a = new int *[5];
	for (int i = 0; i < 5; i++) {
		a[i] = new int[5];
	}
	ASSERT_ANY_THROW(find_road(a, 5, -1, 0, 4, 4));
}
TEST(test_fun, throw3)
{
	int** a;
	a = new int *[5];
	for (int i = 0; i < 5; i++) {
		a[i] = new int[5];
	}
	ASSERT_ANY_THROW(find_road(a, -5, 0, 0, 4, 5));
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}