#include "minunit.h"
#include "../includes/cube.h"

MU_TEST(test_valid_map_name)
{
	char *filename = "test.cub";
	mu_assert(valid_map_name(filename) == TRUE, "Map name is valid");
}

MU_TEST_SUITE(validation_tests)
{
	MU_RUN_TEST(test_valid_map_name);
}

int main(void)
{
	MU_RUN_SUITE(validation_tests);
	MU_REPORT();
	return (MU_EXIT_CODE);
}