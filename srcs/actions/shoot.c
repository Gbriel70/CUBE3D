/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:23:56 by gabastos          #+#    #+#             */
/*   Updated: 2025/05/27 14:46:26 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	change_weapon(t_data *game, int num)
{
	game->wand_img[num]->enabled = false;
	game->wand_img[(num + 1) % WEAPON_FRAMES]->enabled = true;
}

void	shoot(t_data *game)
{
	static int	frame;

	if (frame >= 0 && frame <= REPEAT_FRAME)
	{
		game->shoot = true;
		change_weapon(game, 0);
	}
	if (frame > REPEAT_FRAME && frame <= REPEAT_FRAME * 2)
		change_weapon(game, 1);
	if (frame > REPEAT_FRAME * 2 && frame <= REPEAT_FRAME * 3)
		change_weapon(game, 2);
	if (frame > REPEAT_FRAME * 3)
	{
		change_weapon(game, 3);
		frame = 0;
		game->shoot = false;
	}
	frame++;
}
