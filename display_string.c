/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:59:44 by amalangin         #+#    #+#             */
/*   Updated: 2023/12/10 06:06:11 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_string(t_data *data, char *str, int x, int y)
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		put_img(data, data->img->tile_img, (x + i), y);
		i++;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, x * 32 + 5,
		y * 32 + 18, 0xFFFFFF, str);
	if (str && (data->move))
		free(str);
}
