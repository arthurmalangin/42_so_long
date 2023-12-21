/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:49:08 by amalangi          #+#    #+#             */
/*   Updated: 2023/12/16 01:07:39 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
	{
		free(data->map->map[i]);
		i++;
	}
	free(data->map->map);
	free(data->map);
}

void	free_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_next(t_data *data)
{
	if (data->mlx_ptr && data->img->tile_map)
		mlx_destroy_image(data->mlx_ptr, data->img->tile_map);
	if (data->mlx_ptr && data->img->tile_exit)
		mlx_destroy_image(data->mlx_ptr, data->img->tile_exit);
	if (data->mlx_ptr && data->img->tile_item)
		mlx_destroy_image(data->mlx_ptr, data->img->tile_item);
	if (data->mlx_ptr && data->img->tile_wall)
		mlx_destroy_image(data->mlx_ptr, data->img->tile_wall);
	if (data->mlx_ptr && data->img->main_walk_right)
		mlx_destroy_image(data->mlx_ptr, data->img->main_walk_right);
	if (data->mlx_ptr && data->img->tile_img)
		mlx_destroy_image(data->mlx_ptr, data->img->tile_img);
}

int	on_destroy(t_data *data)
{
	if (data->mlx_ptr && data->win_ptr)
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr && data->img->main_idle_1)
		mlx_destroy_image(data->mlx_ptr, data->img->main_idle_1);
	if (data->mlx_ptr && data->img->main_idle_2)
		mlx_destroy_image(data->mlx_ptr, data->img->main_idle_2);
	if (data->mlx_ptr && data->img->main_idle_3)
		mlx_destroy_image(data->mlx_ptr, data->img->main_idle_3);
	if (data->mlx_ptr && data->img->main_walk_up)
		mlx_destroy_image(data->mlx_ptr, data->img->main_walk_up);
	if (data->mlx_ptr && data->img->main_walk_left)
		mlx_destroy_image(data->mlx_ptr, data->img->main_walk_left);
	destroy_next(data);
	free_map(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->img);
	exit(0);
	return (0);
}
