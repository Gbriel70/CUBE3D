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

MU_TEST(test_valid_map_count)
{
	printf("----------------------------------------");
	printf("\n--Testing valid_map_count function---\n");
	printf("--------------VALID COUNT--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/42.cub";
	
	mu_assert(valid_map_count(filename) == TRUE, "Map count is valid");
}

MU_TEST(test_invalid_map_count)
{
	printf("----------------------------------------");
	printf("\n--Testing valid_map_count function---\n");
	printf("--------------INVALID COUNT--------------\n");
	printf("--------------------------------------\n");

	char *filename = "maps/42.cub";
	
	mu_assert(valid_map_count(filename) == FALSE, "Map count is invalid");
}

MU_TEST(test_map_count_empty_file)
{
	printf("----------------------------------------");
	printf("\n--Testing valid_map_count function---\n");
	printf("--------------EMPTY FILE--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/04a-empty_file.cub";
	
	mu_assert(valid_map_count(filename) == FALSE, "Map count is empty");
}

MU_TEST(test_map_count_extra_elements)
{
	printf("----------------------------------------");
	printf("\n--Testing valid_map_count function---\n");
	printf("--------------EXTRA ELEMENTS--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/04b-extra_element.cub";
	
	mu_assert(valid_map_count(filename) == FALSE, "Map error");
}

MU_TEST(test_map_count_missing_elements)
{
	printf("----------------------------------------");
	printf("\n--Testing valid_map_count function---\n");
	printf("--------------MISSING ELEMENTS--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/04c-missing_element.cub";
	
	mu_assert(valid_map_count(filename) == FALSE, "Map error");
}

MU_TEST(test_map_count_only_map)
{
	printf("----------------------------------------");
	printf("\n--Testing valid_map_count function---\n");
	printf("--------------CONTAIN ONLY MAP--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/04d-only_map.cub";
	
	mu_assert(valid_map_count(filename) == FALSE, "Map error");
}

MU_TEST(test_map_count_elements_after_map)
{
	printf("----------------------------------------");
	printf("\n--Testing valid_map_count function---\n");
	printf("--------------ELEMENTS AFTER MAP--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/07a-element_after_map.cub";
	
	mu_assert(valid_map_count(filename) == FALSE, "Map error");
}

MU_TEST(test_map_count_map_after_map)
{
	printf("----------------------------------------");
	printf("\n--Testing valid_map_count function---\n");
	printf("--------------MAP AFTER MAP--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/07b-map_after_map.cub";
	
	mu_assert(valid_map_count(filename) == FALSE, "Map error");
}

MU_TEST(test_map_count_valid_map)
{
	printf("----------------------------------------");
	printf("\n--Testing valid_map_count function---\n");
	printf("--------------VALID MAP--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/21b-valid_file_map.cub";
	
	mu_assert(valid_map_count(filename) == TRUE, "Map error");
}

MU_TEST(test_validate_map_content)
{
	printf("----------------------------------------");
	printf("\n--Testing validate_map_content function---\n");
	printf("--------------VALID CONTENT--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/42.cub";
	
	mu_assert(validate_map_content(filename) == TRUE, "Map content is valid");
}

MU_TEST(test_validate_map_game)
{
	printf("----------------------------------------");
	printf("\n--Testing validate_map_game function---\n");
	printf("--------------VALID GAME MAP--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/42.cub";
	
	mu_assert(validate_map_game(filename) == TRUE, "Map game validation is valid");
}

MU_TEST(test_validate_map_game_two_players)
{
	printf("----------------------------------------");
	printf("\n--Testing validate_map_game function---\n");
	printf("--------------TWO PLAYERS--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/10a-two_players.cub";
	
	mu_assert(validate_map_game(filename) == FALSE, "Map game validation is invalid");
}

MU_TEST(test_map_game_missing_player)
{
	printf("----------------------------------------");
	printf("\n--Testing validate_map_game function---\n");
	printf("--------------MISSING PLAYER--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/10b-missing_player.cub";
	
	mu_assert(validate_map_game(filename) == FALSE, "Map game validation is invalid");
}

MU_TEST(test_map_game_open_wall_left)
{
	printf("----------------------------------------");
	printf("\n--Testing validate_map_game function---\n");
	printf("--------------OPEN WALL LEFT--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/11a-ope_wall_left.cub";
	
	mu_assert(validate_map_game(filename) == FALSE, "Map game validation is invalid");
}

MU_TEST(test_map_game_open_wall_right)
{
	printf("----------------------------------------");
	printf("\n--Testing validate_map_game function---\n");
	printf("--------------OPEN WALL RIGHT--------------\n");
	printf("--------------------------------------\n");

	char *filename = "../maps/11b-open_wall_right.cub";
	
	mu_assert(validate_map_game(filename) == FALSE, "Map game validation is invalid");
}

MU_TEST_SUITE(validation_tests)
{
	MU_RUN_TEST(test_valid_map_name);
	MU_RUN_TEST(test_invalid_map_name);
	MU_RUN_TEST(test_valid_map_count);
	MU_RUN_TEST(test_invalid_map_count);
	MU_RUN_TEST(test_map_count_empty_file);
	MU_RUN_TEST(test_map_count_extra_elements);
	MU_RUN_TEST(test_map_count_missing_elements);
	MU_RUN_TEST(test_map_count_only_map);
	MU_RUN_TEST(test_map_count_elements_after_map);
	MU_RUN_TEST(test_map_count_map_after_map);
	MU_RUN_TEST(test_map_count_valid_map);
	MU_RUN_TEST(test_validate_map_content);
	MU_RUN_TEST(test_validate_map_game);
	MU_RUN_TEST(test_validate_map_game_two_players);
	MU_RUN_TEST(test_map_game_missing_player);
	MU_RUN_TEST(test_map_game_open_wall_left);
	MU_RUN_TEST(test_map_game_open_wall_right);
}

int main(void)
{
	MU_RUN_SUITE(validation_tests);
	MU_REPORT();
	return MU_EXIT_CODE;
}