/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:20:58 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/01 15:52:48 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_window,
		game->mlx.texture_object[0], x * PXL, y * PXL);
}

void	put_wall(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_window,
		game->mlx.texture_object[1], x * PXL, y * PXL);
}

void	put_exit(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_window,
		game->mlx.texture_object[2], x * PXL, y * PXL);
}

void	put_player(t_data *game, int x, int y, int dir)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_window,
		game->mlx.texture_player[dir], x * PXL, y * PXL);
}

void	put_collectible(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_window,
		game->mlx.texture_object[3], x * PXL, y * PXL);
}
