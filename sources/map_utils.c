/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:02:25 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/25 10:11:51 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_hight(char **layout)
{
	int	i;

	i = 0;
	while (layout[i])
		i++;
	return (i);
}

int	get_lenght(char **layout)
{
	int	i;
	int	j;
	int	prev_j;

	i = 0;
	while (layout[i])
	{
		j = 0;
		while (layout[i][j])
			j++;
		if (i != 0)
		{
			if (j != prev_j)
			{
				free_map(layout);
				exit (ft_printf("Error\nThe map isn't rectangular\n"));
			}
		}
		prev_j = j;
		i++;
	}
	return (j - 1);
}

void	free_map(char **layout)
{
	int	i;

	i = 0;
	while (layout[i])
	{
		free(layout[i]);
		i++;
	}
	free(layout);
}
