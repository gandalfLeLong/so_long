/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:00:17 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/25 09:57:48 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*-----------INCLUDES----------*/
# include "libft.h"
# include "mlx.h"

/*----------DEFINE----------*/
# define DISPLAY_LEN 2560
# define DISPLAY_HIGHT 1440
# define PXL 64
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define TEXTURE_MAX 5

/*----------STRUCTURES----------*/
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_window;
	void	*texture_object[TEXTURE_MAX];
	void	*texture_player[TEXTURE_MAX];
}	t_mlx;

typedef struct s_cpy
{
	int		collectible;
	int		exit;
	char	**layout;
}	t_cpy;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	collectible;
}	t_player;

typedef struct s_map
{
	int		fd;
	int		len;
	int		hight;
	int		exit_x;
	int		exit_y;
	int		collectible;
	char	**layout;
}	t_map;

typedef struct s_data
{
	int			moves;
	t_map		map;
	t_cpy		check_map;
	t_player	player;
	t_mlx		mlx;

}	t_data;

/*----------FUNCTIONS----------*/
//map_parsing.c
int		parsing_map(char **av, t_data *game);

//map_utils.c
int		get_hight(char **layout);
int		get_lenght(char **layout);
void	free_map(char **layout);
void	print_map(char **layout);

//map_checker.c
int		check_map_valid(t_data *game);

//map_checker_utils.c
int		check_display(t_data *game);
void	get_positions(t_data *game);
void	flood_fill(t_data *game, int pos_x, int pos_y);

//game_init.c
void	game_init(t_data *game);
int		init_object_sprites(t_data *game);

//game_utils.c
int		destroy_all(t_data *game);
void	move_player_up(t_data *game, int x, int y);
void	move_player_down(t_data *game, int x, int y);
void	move_player_right(t_data *game, int x, int y);
void	move_player_left(t_data *game, int x, int y);

//put_items.c
void	put_floor(t_data *game, int x, int y);
void	put_wall(t_data *game, int x, int y);
void	put_exit(t_data *game, int x, int y);
void	put_player(t_data *game, int x, int y, int dir);
void	put_collectible(t_data *game, int x, int y);

#endif
