/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 06:07:25 by amalangi          #+#    #+#             */
/*   Updated: 2023/12/16 04:37:18 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_data *data, int x, int y)
{
	char	*tmp;

	if (data->map->map[y][x] == '1')
		return (0);
	else if (data->map->map[y][x] == 'C')
	{
		data->item_take++;
		data->map->map[y][x] = 0;
		tmp = join_free("Item: ", ft_itoa(data->item_take), 1);
		display_string(data, tmp, (data->map->x_max + 2),
			(data->map->y_max - 4));
	}
	else if (data->map->map[y][x] == 'E')
	{
		if (data->item_take == data->map->items)
		{
			write(2, "End of game, congratulation !", 29);
			data->end_of_game = 1;
			on_destroy(data);
		}
	}
	return (1);
}

void	player_update_direction(t_data *data, int keysym)
{
	if (keysym == W)
		data->direction = UP;
	else if (keysym == A)
		data->direction = LEFT;
	else if (keysym == S)
		data->direction = DOWN;
	else if (keysym == D)
		data->direction = RIGHT;
}
