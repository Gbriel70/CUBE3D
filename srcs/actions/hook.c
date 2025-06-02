/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:31:13 by gabastos          #+#    #+#             */
/*   Updated: 2025/05/27 14:54:59 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	key_press(void *param)
{
	t_data	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		close_game(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_player(game, SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_player(game, -SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game, SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game, SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(game, ROTATE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(game, -ROTATE_SPEED);
}

// Em srcs/actions/mouse_control.c
void cursor_movement(double xpos, double ypos, void *param)
{
    t_data *game = (t_data *)param;
    static double last_x = -1;
    
    // Na primeira chamada, apenas inicializa a posição
    if (last_x == -1) {
        last_x = xpos;
        return;
    }
    
    // Calcula o movimento horizontal do mouse
    double mouse_dx = xpos - last_x;
    last_x = xpos;
    
    // Fator de sensibilidade - ajuste conforme necessário
    float sensitivity = 1.0;
    
    // Rotaciona com base no movimento do mouse
    float rotation_speed = -mouse_dx * sensitivity;
    
    // Usa sua função de rotação já existente
    rotate_player(game, rotation_speed);
    
    // Centraliza o mouse novamente para movimento contínuo (opcional)
    // mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
    
    // Ignora o parâmetro ypos (não usado para olhar para cima/baixo em raycasters 2.5D)
    (void)ypos;
}

void	mouse_click(void *param)
{
	t_data	*game;

	game = param;
	if (game->shoot || mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT))
		shoot(game);
}
