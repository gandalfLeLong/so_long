/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:11:22 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/25 10:01:26 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_symbols(t_data *game)
{
	int		i;
	int		j;
	int		exit;
	char	c;

	i = 0;
	exit = 0;
	while (game->map.layout[i])
	{
		j = 0;
		while (game->map.layout[i][j] != '\n')
		{
			c = game->map.layout[i][j];
			if (c != '0' && c != '1' && c != 'E' && c != 'P' && c != 'C')
				return (1);
			if (c == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (1);
	return (0);
}

static int	check_symbols_number(t_data *game)
{
	int		i;
	int		j;
	int		player;
	int		collectible;

	i = 0;
	player = 0;
	collectible = 0;
	while (game->map.layout[i])
	{
		j = 0;
		while (game->map.layout[i][j] != '\n')
		{
			if (game->map.layout[i][j] == 'P')
				player++;
			if (game->map.layout[i][j] == 'C')
				collectible ++;
			j++;
		}
		i++;
	}
	if (player != 1 || collectible < 1)
		return (1);
	game->map.collectible = collectible;
	return (0);
}

static int	check_walls(char **layout, int len, int hight)
{
	int	i;
	int	j;

	i = 0;
	while (layout[i])
	{
		j = 0;
		while (layout[i][j] != '\n')
		{
			if (i == 0 || j == 0)
				if (layout[i][j] != '1')
					return (1);
			if (i == hight - 1 || j == len - 1)
				if (layout [i][j] != '1')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_clear_path(t_data *game)
{
	int	player_x;
	int	player_y;

	player_x = game->player.pos_x;
	player_y = game->player.pos_y;
	flood_fill(game, player_x, player_y);
	if (game->check_map.exit != 1)
		return (1);
	if (game->check_map.collectible != game->map.collectible)
		return (1);
	free_map(game->check_map.layout);
	return (0);
}

int	check_map_valid(t_data *game)
{
	if (game->check_map.layout == NULL)
		return (1);
	if (check_symbols(game))
		return (1);
	if (check_symbols_number(game))
		return (1);
	get_positions(game);
	if (check_walls(game->map.layout, game->map.len, game->map.hight))
		return (1);
	if (check_display(game))
		return (1);
	if (check_clear_path(game))
		return (1);
	return (0);
}
