/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:24:05 by amalangin         #+#    #+#             */
/*   Updated: 2023/12/16 05:05:40 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define IMG_W 32
# define IMG_H 32
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 1
# define LEFT 3
# define RIGHT 4
# define DOWN 2

typedef struct s_img
{
	void	*tile_img;
	void	*tile_map;
	void	*tile_exit;
	void	*tile_item;
	void	*tile_wall;
	void	*main_idle_1;
	void	*main_idle_2;
	void	*main_idle_3;
	void	*main_walk_up;
	void	*main_walk_left;
	void	*main_walk_right;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		items;
	int		x_max;
	int		y_max;
	int		exit;
	int		player;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_map		*map;
	int			player_pos_x;
	int			player_pos_y;
	int			anim_idle_num;
	int			direction;
	int			chrono;
	int			key_pressed;
	int			item_take;
	long long	move;
	int			check_id;
	int			end_of_game;
}	t_data;

int		ft_print_background(t_data *data);
int		ft_print_player(t_data *data, int x, int y);
int		ft_print_map(t_data *data);
int		ft_init(t_data *data);
int		frame(t_data *data);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_map(t_data *data);
void	ft_bzero(void *s, int n);
int		ft_strlen(const char *str);
char	*join_free(char *buffer, char *buf, int choice);
int		can_move(t_data *data, int x, int y);
void	free_map(t_data *data);
void	player_update_direction(t_data *data, int keysym);
int		put_img(t_data *data, void *img, int x, int y);
int		count_char(char *str, char c);
char	*buffer_to_map_integer(char *buffer, int kp);
int		ft_strlen_to_char(char *str, char c);
void	map_fill_data(t_data *data, int *content, int x, int y);
int		get_pos(t_data *data, char c, char type);
void	map_fill_flood(char **map, int x, int y, int *content);
char	**buffer_to_map(char *buffer);
int		map_is_valid(t_data *data, char *buffer);
int		on_destroy(t_data *data);
int		map_check_wall(char **map, int x_max, int y_max);
void	free_tab(char **map);
int		map_is_rectangle(char **map);
void	map_fill_flood(char **map, int x, int y, int *content);
void	print_error_code(int error_code);
void	display_string(t_data *data, char *str, int x, int y);
char	*ft_itoa(long long n);
int		ft_checkos(t_data *data, char *path_to_map);
int		exit_first_stage(t_data *data, void *map);
int		exit_second_stage(t_data *data);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*read_fill(char *path_to_map);
#endif