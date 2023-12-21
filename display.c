/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:06:21 by amalangi          #+#    #+#             */
/*   Updated: 2023/12/16 05:03:44 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y * 32 < (data->map->y_max + 1) * 32)
	{
		x = 0;
		while (x * 32 < (data->map->x_max + 5) * 32)
		{
			put_img(data, data->img->tile_img, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_print_player_helper(t_data *data)
{
	char	*tmp;
	char	*ito;

	ito = ft_itoa(data->move);
	if (!ito)
		on_destroy(data);
	tmp = join_free("Move: ", ito, 1);
	write(2, tmp, ft_strlen(tmp));
	write(2, "\n", 1);
	display_string(data, tmp, (data->map->x_max + 2),
		(data->map->y_max - 3));
	return (1);
}

void	ft_print_player_img(t_data *data, int x, int y)
{
	if (data->direction == 1)
		put_img(data, data->img->main_walk_up, x, y);
	if (data->direction == 2)
		put_img(data, data->img->main_idle_1, x, y);
	if (data->direction == 3)
		put_img(data, data->img->main_walk_left, x, y);
	if (data->direction == 4)
		put_img(data, data->img->main_walk_right, x, y);
}

int	ft_print_player(t_data *data, int x, int y)
{
	int		px;
	int		py;

	px = data->player_pos_x;
	py = data->player_pos_y;
	if (can_move(data, x, y) == 1)
	{
		if (data->move > 0 && data->map->map[py][px] != 'E')
			put_img(data, data->img->tile_map, px, py);
		if (data->map->map[y][x] != 'E')
			ft_print_player_img(data, x, y);
		data->player_pos_x = x;
		data->player_pos_y = y;
		data->move++;
		ft_print_player_helper(data);
	}
	return (0);
}

int	ft_print_map(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (d->map->map[y])
	{
		x = 0;
		while (d->map->map[y][x])
		{
			if (d->map->map[y][x] == '1')
				put_img(d, d->img->tile_wall, x, y);
			else if (d->map->map[y][x] == '0')
				put_img(d, d->img->tile_map, x, y);
			else if (d->map->map[y][x] == 'C')
				put_img(d, d->img->tile_item, x, y);
			else if (d->map->map[y][x] == 'P')
				ft_print_player(d, x, y);
			else if (d->map->map[y][x] == 'E')
				put_img(d, d->img->tile_exit, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
