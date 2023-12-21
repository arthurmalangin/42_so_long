/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:09:04 by amalangin         #+#    #+#             */
/*   Updated: 2023/12/16 07:00:32 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_to_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != 0)
		i++;
	return (i);
}

void	map_fill_data(t_data *data, int *content, int x, int y)
{
	data->map->items = content[0];
	data->map->exit = content[1];
	data->map->player = content[2];
	data->map->x_max = x - 1;
	data->map->y_max = y - 1;
}

void	map_fill_flood(char **map, int x, int y, int *content)
{
	if (map[y][x] == '1')
		return ;
	else if (map[y][x] == 'C')
		content[0]++;
	else if (map[y][x] == 'E')
		content[1]++;
	else if (map[y][x] == 'P')
		content[2]++;
	map[y][x] = '1';
	map_fill_flood(map, x + 1, y, content);
	map_fill_flood(map, x - 1, y, content);
	map_fill_flood(map, x, y - 1, content);
	map_fill_flood(map, x, y + 1, content);
}

void	print_error_code(int error_code)
{
	if (error_code == 1)
		write(2, "Error\nWall is missing in Border of map or map empy !\n", 52);
	else if (error_code == 2)
		write(2, "Error\nPlayer can't reach all item's or exit !\n", 45);
	else if (error_code == 3)
		write(2, "Error\nMap is not rectangle !\n", 29);
	else if (error_code == 4)
		write(2, "Error\nCan't open map file !\n", 28);
	else if (error_code == 5)
		write(2, "Error\nMissing item !\n", 21);
	else if (error_code == 6)
		write(2, "Error\nBad amout of Exit !\n", 26);
	else if (error_code == 7)
		write(2, "Error\nBad amout of Player !\n", 28);
	else if (error_code == 8)
		write(2, "Error\nBad characters in map !\n", 30);
}

int	get_pos(t_data *data, char c, char type)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == type)
			{
				if (c == 'x')
					return (x);
				if (c == 'y')
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
