#include "../includes/cube.h"
#include "minunit.h"
#include <stdio.h>
#include <string.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"

#define TEST_MAP_PATH "../maps/42.cub"

static void setup_game(t_data *game)
{
    memset(game, 0, sizeof(t_data));
    game->map.path = ft_strdup(TEST_MAP_PATH);
}

// Função auxiliar para limpar recursos alocados
static void cleanup_game(t_data *game)
{
    if (game->map.path)
        free(game->map.path);
    if (game->map.content)
        ft_free_matrix(game->map.content);
    // Adicionar limpeza de outros recursos alocados por parse_map
    // como texturas, etc.
}

// PARSER TESTS
MU_TEST(test_extract_content)
{
	
	printf("%s----------------------------------------%s\n", GREEN, RESET);
    printf("%s--Testing extract_content function-----%s\n", GREEN, RESET);
    printf("%s----------------------------------------%s\n", GREEN, RESET);
	
	t_data game;
	char **file;
	
    // Preparar o teste
    setup_game(&game);

	file = load_file(game.map.path);
    if (!file) {
        printf("%sERRO: Falha ao carregar arquivo: %s%s\n", RED, game.map.path, RESET);
        mu_assert(0, "load_file falhou");
        return;
    }
    
    // Chamar parse_map que internamente chama extract_content
    extract_content(&game, file);
    
    // Verificações
    mu_assert_int_eq(25, game.map.content_rows);
    
    // Verificar algumas linhas específicas do conteúdo
    mu_assert_string_eq("./textures/42_map/pink_wall.png", game.map.content[0]);
    mu_assert_string_eq("255,223,186", game.map.content[4]);
    mu_assert_string_eq("186,225,255", game.map.content[5]);
    
    // Limpar recursos
    cleanup_game(&game);
}

MU_TEST_SUITE(validation_tests)
{
	MU_RUN_TEST(test_extract_content);
}

int	main(void)
{
	MU_RUN_SUITE(validation_tests);
	MU_REPORT();
	return (MU_EXIT_CODE);
}