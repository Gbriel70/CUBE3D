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

MU_TEST(test_player_initial_setup)
{
    printf("%s----------------------------------------%s\n", GREEN, RESET);
    printf("%s--Testing player_initial_setup function--%s\n", GREEN, RESET);
    printf("%s----------------------------------------%s\n", GREEN, RESET);

    t_data game;
    char **file;
    int *player;

    // Preparar o teste
    setup_game(&game);

    // Primeiro carregar o arquivo
    file = load_file(game.map.path);
    if (!file) {
        printf("%sERRO: Falha ao carregar arquivo%s\n", RED, RESET);
        mu_assert(0, "load_file falhou");
        return;
    }

    // Depois obter as informações do jogador do arquivo
    player = load_player(file);
    if (!player) {
        printf("%sERRO: Falha ao carregar dados do jogador%s\n", RED, RESET);
        ft_free_matrix(file);
        mu_assert(0, "load_player falhou");
        return;
    }

    // Opcionalmente, extrair o conteúdo (necessário para outros testes)
    extract_content(&game, file);

    // Agora sim, inicializar o jogador
    player_initial_setup(&game, player);

    // Verificações
    mu_assert_int_eq(20, game.player.x);
    mu_assert_int_eq(16, game.player.y);

    // Limpar recursos
    free(player);
    ft_free_matrix(file);
    cleanup_game(&game);
}

MU_TEST(test_extract_map_simple)
{
    printf("%s----------------------------------------%s\n", GREEN, RESET);
    printf("%s--Simple Extract Map Test-----------------%s\n", GREEN, RESET);

    t_data game;
    char **file;
    int *player;

    setup_game(&game);

    file = load_file(game.map.path);
    mu_assert(file != NULL, "load_file falhou");

    player = load_player(file);
    mu_assert(player != NULL, "load_player falhou");

    extract_content(&game, file);
    player_initial_setup(&game, player);

    // Só agora chamamos extract_map
    extract_map(&game);

    // Verificações
    mu_assert(game.map.layout != NULL, "layout não foi inicializado");
    mu_assert_int_eq(game.map.content_rows - 6, game.map.layout_rows);

    mu_assert_string_eq("11111111111111111111111111111", game.map.layout[0]);
	mu_assert_string_eq("10000000001100000000000000001", game.map.layout[1]);

	for (size_t i = 0; i < game.map.layout_rows; i++) 
	{
		mu_assert(game.map.layout[i][0] == '1', "borda esquerda não é parede");
		mu_assert(game.map.layout[i][game.map.layout_columns -1] == '1', "borda direita não é parede");
	}

	mu_assert_string_eq("11111111111111111111111111111", game.map.layout[game.map.layout_rows -1]);

    // Limpeza
    free(player);
    ft_free_matrix(file);
    cleanup_game(&game);
}

MU_TEST(test_extract_floor_ceiling_color)
{
	printf("%s----------------------------------------%s\n", GREEN, RESET);
	printf("%s--Testing extract_floor_ceiling_color--%s\n", GREEN, RESET);
	printf("%s----------------------------------------%s\n", GREEN, RESET);

	t_data game;
	char **file;

	setup_game(&game);

	file = load_file(game.map.path);
	mu_assert(file != NULL, "load_file falhou");

	extract_content(&game, file);
	extract_floor_ceiling_color(&game);

	// Verificações
	mu_assert_int_eq(0xFFDFBAFF, game.map.floor_color); // 255,223,186
	mu_assert_int_eq(0xBAE1FFFF, game.map.ceiling_color); // 186,225,255

	// Limpeza
	ft_free_matrix(file);
	cleanup_game(&game);
}

MU_TEST_SUITE(validation_tests)
{
	MU_RUN_TEST(test_extract_content);
	MU_RUN_TEST(test_player_initial_setup);
	MU_RUN_TEST(test_extract_map_simple);
	MU_RUN_TEST(test_extract_floor_ceiling_color);
}

int	main(void)
{
	MU_RUN_SUITE(validation_tests);
	MU_REPORT();
	return (MU_EXIT_CODE);
}