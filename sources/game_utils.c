/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:03:27 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/01 15:56:56 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_data *game, int x, int y)
{
	if (game->map.layout[y][x] == '1')
		return ;
	game->moves++;
	ft_printf("Numbers of moves : %d\n", game->moves);
	if (game->map.layout[y][x] == 'C' || game->map.layout[y][x] == '0'
			|| game->map.layout[y][x] == 'P')
	{
		if (game->map.layout[y][x] == 'C')
			game->player.collectible++;
		game->map.layout[y][x] = '0';
		put_floor(game, x, y);
		put_player(game, x, y, 1);
	}
	if (game->map.layout[y][x] == 'E')
	{
		if (game->player.collectible == game->map.collectible)
			destroy_all(game);
		put_player(game, x, y, 1);
	}
	game->player.pos_y -= 1;
	put_floor(game, x, y + 1);
	if (game->map.layout[y + 1][x] == 'E')
		put_exit(game, x, y + 1);
}

void	move_player_down(t_data *game, int x, int y)
{
	if (game->map.layout[y][x] == '1')
		return ;
	game->moves++;
	ft_printf("Numbers of moves : %d\n", game->moves);
	if (game->map.layout[y][x] == 'C' || game->map.layout[y][x] == '0'
			|| game->map.layout[y][x] == 'P')
	{
		if (game->map.layout[y][x] == 'C')
			game->player.collectible++;
		game->map.layout[y][x] = '0';
		put_floor(game, x, y);
		put_player(game, x, y, 0);
	}
	if (game->map.layout[y][x] == 'E')
	{
		if (game->player.collectible == game->map.collectible)
			destroy_all(game);
		put_player(game, x, y, 0);
	}
	game->player.pos_y += 1;
	put_floor(game, x, y - 1);
	if (game->map.layout[y - 1][x] == 'E')
		put_exit(game, x, y - 1);
}

void	move_player_left(t_data *game, int x, int y)
{
	if (game->map.layout[y][x] == '1')
		return ;
	game->moves++;
	ft_printf("Numbers of moves : %d\n", game->moves);
	if (game->map.layout[y][x] == 'C' || game->map.layout[y][x] == '0'
			|| game->map.layout[y][x] == 'P')
	{
		if (game->map.layout[y][x] == 'C')
			game->player.collectible++;
		game->map.layout[y][x] = '0';
		put_floor(game, x, y);
		put_player(game, x, y, 2);
	}
	if (game->map.layout[y][x] == 'E')
	{
		if (game->player.collectible == game->map.collectible)
			destroy_all(game);
		put_player(game, x, y, 2);
	}
	game->player.pos_x -= 1;
	put_floor(game, x + 1, y);
	if (game->map.layout[y][x + 1] == 'E')
		put_exit(game, x + 1, y);
}

void	move_player_right(t_data *game, int x, int y)
{
	if (game->map.layout[y][x] == '1')
		return ;
	game->moves++;
	ft_printf("Numbers of moves : %d\n", game->moves);
	if (game->map.layout[y][x] == 'C' || game->map.layout[y][x] == '0'
			|| game->map.layout[y][x] == 'P')
	{
		if (game->map.layout[y][x] == 'C')
			game->player.collectible++;
		game->map.layout[y][x] = '0';
		put_floor(game, x, y);
		put_player(game, x, y, 3);
	}
	if (game->map.layout[y][x] == 'E')
	{
		if (game->player.collectible == game->map.collectible)
			destroy_all(game);
		put_player(game, x, y, 3);
	}
	game->player.pos_x += 1;
	put_floor(game, x - 1, y);
	if (game->map.layout[y][x - 1] == 'E')
		put_exit(game, x - 1, y);
}

int	destroy_all(t_data *game)
{
	int	i;

	i = 0;
	free_map(game->map.layout);
	while (game->mlx.texture_object[i])
	{
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.texture_object[i]);
		i++;
	}
	while (game->mlx.texture_player[i])
	{
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.texture_player[i]);
		i++;
	}
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.mlx_window);
	exit(0);
	return (0);
}
