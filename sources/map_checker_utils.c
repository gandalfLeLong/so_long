/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:38:17 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/19 11:29:55 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_display(t_data *game)
{
	if (game->map.len * PXL > DISPLAY_LEN)
		return (1);
	if (game->map.hight * PXL > DISPLAY_HIGHT)
		return (1);
	return (0);
}

void	get_positions(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.layout[i])
	{
		j = 0;
		while (game->map.layout[i][j] != '\n')
		{
			if (game->map.layout[i][j] == 'E')
			{
				game->map.exit_y = i;
				game->map.exit_x = j;
			}
			if (game->map.layout[i][j] == 'P')
			{
				game->player.pos_y = i;
				game->player.pos_x = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_data *game, int x, int y)
{
	char	c;

	if (x > 0 && x < game->map.len - 1 && y > 0 && y < game->map.hight - 1)
	{
		c = game->check_map.layout[y][x];
		if (c == '1' || c == '.')
			return ;
		if (c == '0' || c == 'P')
			game->check_map.layout[y][x] = '.';
		if (c == 'C')
		{
			game->check_map.layout[y][x] = '.';
			game->check_map.collectible++;
		}
		if (c == 'E')
		{
			game->check_map.layout[y][x] = '.';
			game->check_map.exit = 1;
		}
		flood_fill(game, x + 1, y);
		flood_fill(game, x - 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
	return ;
}
