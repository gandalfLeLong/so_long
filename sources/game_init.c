/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:03:20 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/11 14:34:58 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_item_to_window(t_data *game, int x, int y)
{
	put_floor(game, x, y);
	if (game->map.layout && game->map.layout[y][x] == '1')
		put_wall(game, x, y);
	if (game->map.layout && game->map.layout[y][x] == 'P')
		put_player(game, x, y, 0);
	if (game->map.layout && game->map.layout[y][x] == 'E')
		put_exit(game, x, y);
	if (game->map.layout && game->map.layout[y][x] == 'C')
		put_collectible(game, x, y);
}

static void	put_map_to_window(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (game->map.hight))
	{
		x = 0;
		while (x < (game->map.len))
		{
			put_item_to_window(game, x, y);
			x++;
		}
		y++;
	}
}

static int	key_press(int key, t_data *game)
{
	if (key == W)
		move_player_up(game, game->player.pos_x, game->player.pos_y - 1);
	if (key == S)
		move_player_down(game, game->player.pos_x, game->player.pos_y + 1);
	if (key == A)
		move_player_left(game, game->player.pos_x - 1, game->player.pos_y);
	if (key == D)
		move_player_right(game, game->player.pos_x + 1, game->player.pos_y);
	if (key == ESC)
		destroy_all(game);
	return (0);
}

void	game_init(t_data *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		destroy_all(game);
	game->mlx.mlx_window = mlx_new_window(game->mlx.mlx_ptr,
			(game->map.len * PXL), (game->map.hight * PXL), "So_long");
	if (!game->mlx.mlx_window)
		destroy_all(game);
	if (init_object_sprites(game))
		destroy_all(game);
	put_map_to_window(game);
	mlx_hook(game->mlx.mlx_window, 17, 0, &destroy_all, game);
	mlx_hook(game->mlx.mlx_window, 2, 0, &key_press, game);
	mlx_loop(game->mlx.mlx_ptr);
}
