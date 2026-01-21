/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:09:07 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/25 09:51:01 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_struct(t_data *game)
{
	game->moves = 0;
	game->player.collectible = 0;
	game->map.layout = NULL;
	game->check_map.layout = NULL;
	game->map.collectible = 0;
	game->check_map.collectible = 0;
	game->check_map.exit = 0;
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		return (ft_printf("Error\nWrong number of arguments.\n"), 1);
	init_struct(&game);
	if (parsing_map(av, &game))
		return (1);
	game_init(&game);
	return (0);
}
