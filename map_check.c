/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:20:53 by amalangin         #+#    #+#             */
/*   Updated: 2023/12/16 02:28:52 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_valid_prop(t_data *data)
{
	int	content[3];
	int	x;
	int	y;

	y = 0;
	while (y < 3)
		content[y++] = 0;
	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'C')
				content[0]++;
			else if (data->map->map[y][x] == 'E')
				content[1]++;
			else if (data->map->map[y][x] == 'P')
				content[2]++;
			x++;
		}
		y++;
	}
	map_fill_data(data, content, x, y);
}

int	map_is_valid_helper(t_data *data, int *content)
{
	int	return_code;

	return_code = 0;
	if (content[0] != data->map->items || content[1] != data->map->exit
		|| content[2] != data->map->player)
		return_code = 2;
	if (data->map->items < 1)
		return_code = 5;
	if (data->map->exit != 1)
		return_code = 6;
	if (data->map->player != 1)
		return_code = 7;
	return (return_code);
}

int	map_is_valid(t_data *data, char *buffer)
{
	int		i;
	int		content[3];
	char	**cpymap;
	int		return_code;

	cpymap = buffer_to_map(buffer);
	if (!cpymap)
	{
		free(buffer);
		exit_second_stage(data);
	}
	i = 0;
	while (i < 3)
		content[i++] = 0;
	map_valid_prop(data);
	return_code = map_check_wall(cpymap, data->map->x_max, data->map->y_max);
	if (return_code == 0)
		map_fill_flood(cpymap, get_pos(data, 'x', 'P'), get_pos(data, 'y', 'P'),
			content);
	if (return_code == 0)
		return_code = map_is_valid_helper(data, content);
	if (!map_is_rectangle(cpymap))
		return_code = 3;
	free_tab(cpymap);
	return (return_code);
}

int	map_is_rectangle(char **map)
{
	int	oldx;
	int	x;
	int	y;

	y = 0;
	oldx = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			x++;
		}
		if (oldx != 0)
		{
			if (oldx != x)
				return (0);
		}
		oldx = x;
		y++;
	}
	if (x == y)
		return (0);
	return (1);
}

int	map_check_wall(char **map, int x_max, int y_max)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((x == 0 || y == 0 || x == x_max || y == y_max)
				&& map[y][x] != '1')
				return (1);
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'P')
				return (8);
			x++;
		}
		y++;
	}
	if (y < 3 && x < 3)
		return (1);
	return (0);
}
