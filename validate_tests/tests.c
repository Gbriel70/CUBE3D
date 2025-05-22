#include "minunit.h"
#include <stdio.h>
#include "../includes/cube.h"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"

MU_TEST(test_valid_map_name)
{
	printf("----------------------------------------");
	printf("\n--Testing valid_map_name function---\n");
	printf("--------------VALID MAP---------------\n");
	printf("--------------------------------------\n");

	char *filename = "test.cub";
	
	mu_assert(valid_map_name(filename) == TRUE, "Map name is valid");
}

MU_TEST(test_invalid_map_name)
{
	printf("----------------------------------------");
	printf("\n--Testing valid_map_name function---\n");
	printf("------------INVALID MAP---------------\n");
	printf("--------------------------------------\n");

	char *filename = "test.txt";
	
	mu_assert(valid_map_name(filename) == FALSE, "Map name is invalid");
}

MU_TEST_SUITE(validation_tests)
{
	MU_RUN_TEST(test_valid_map_name);
	MU_RUN_TEST(test_invalid_map_name);
}

int main(void)
{
	MU_RUN_SUITE(validation_tests);
	MU_REPORT();
	return MU_EXIT_CODE;
}