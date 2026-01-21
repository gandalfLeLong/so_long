/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:57:49 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/25 10:08:06 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_input_type(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[--i] != 'r')
		return (1);
	if (str[--i] != 'e')
		return (1);
	if (str[--i] != 'b')
		return (1);
	if (str[--i] != '.')
		return (1);
	if (i == 0)
		return (1);
	return (0);
}

static void	copy_layout(char **dst, char **src)
{
	int	i;

	i = 0;
	if (!src)
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	free(src);
}

static char	**get_map(int fd)
{
	int		i;
	char	*res;
	char	**layout;
	char	**prev_layout;

	i = 0;
	res = get_next_line(fd);
	prev_layout = NULL;
	while (res)
	{
		layout = malloc (sizeof (char *) * (i + 2));
		if (!layout)
		{
			if (prev_layout)
				free_map(prev_layout);
			return (NULL);
		}
		copy_layout(layout, prev_layout);
		layout[i] = res;
		layout[i + 1] = NULL;
		res = get_next_line(fd);
		i++;
		prev_layout = layout;
	}
	return (layout);
}

int	parsing_map(char **av, t_data *game)
{
	if (check_input_type(av[1]))
		return (ft_printf("Error\nWrong input type.\n"), 1);
	game->map.fd = open(av[1], O_RDONLY);
	if (game->map.fd == -1)
		return (ft_printf("Error\nIssue opening the file.\n", 1));
	game->map.layout = get_map(game->map.fd);
	if (game->map.layout == NULL)
		return (ft_printf("Error.\nFile empty.\n", 1));
	game->map.hight = get_hight(game->map.layout);
	game->map.len = get_lenght(game->map.layout);
	close (game->map.fd);
	game->map.fd = open(av[1], O_RDONLY);
	if (game->map.fd == -1)
		return (ft_printf("Error\nIssue opening the file.\n", 1));
	game->check_map.layout = get_map(game->map.fd);
	close (game->map.fd);
	if (check_map_valid(game))
	{
		if (game->check_map.layout)
			free_map(game->check_map.layout);
		free_map(game->map.layout);
		return (ft_printf("Error\nMap invalid.\n"), 1);
	}
	return (0);
}
