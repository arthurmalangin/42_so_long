/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 01:07:14 by amalangi          #+#    #+#             */
/*   Updated: 2023/12/16 07:32:45 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_first_stage(t_data *data, void *map)
{
	write(2, "Error\nCan't open map file !\n", 28);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	if (map)
		free(map);
	exit(0);
	return (0);
}

int	exit_second_stage(t_data *data)
{
	if (data->win_ptr)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	mlx_destroy_display(data->mlx_ptr);
	if (data->map && data->map->map)
		free_map(data);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
