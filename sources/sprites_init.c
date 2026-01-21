/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:31:22 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/11 14:34:19 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_sprites(t_data *game)
{
	int	i;

	i = 0;
	while (i < TEXTURE_MAX - 1)
	{
		if (!game->mlx.texture_object[i])
			return (1);
		if (!game->mlx.texture_player[i])
			return (1);
		i++;
	}
	return (0);
}

static void	init_player_sprite(t_data *game)
{
	int	w;
	int	h;

	game->mlx.texture_player[0] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./sprites/char_down.xpm", &w, &h);
	game->mlx.texture_player[1] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./sprites/char_up.xpm", &w, &h);
	game->mlx.texture_player[2] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./sprites/char_left.xpm", &w, &h);
	game->mlx.texture_player[3] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./sprites/char_right.xpm", &w, &h);
	game->mlx.texture_player[4] = NULL;
}

int	init_object_sprites(t_data *game)
{
	int	w;
	int	h;

	game->mlx.texture_object[0] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./sprites/floor.xpm", &w, &h);
	game->mlx.texture_object[1] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./sprites/wall.xpm", &w, &h);
	game->mlx.texture_object[2] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./sprites/baril.xpm", &w, &h);
	game->mlx.texture_object[3] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./sprites/jus_de_baguarre.xpm", &w, &h);
	game->mlx.texture_object[4] = NULL;
	init_player_sprite(game);
	if (check_sprites(game))
		return (1);
	return (0);
}
