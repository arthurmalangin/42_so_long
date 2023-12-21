/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 04:09:32 by amalangin         #+#    #+#             */
/*   Updated: 2023/12/11 02:25:23 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*mxf(void *mlx_ptr, char *filemame)
{
	int	img_x;
	int	img_y;

	return (mlx_xpm_file_to_image(mlx_ptr, filemame, &img_x, &img_y));
}

int	put_img(t_data *data, void *img, int x, int y)
{
	return (mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, img, x * 32, y * 32));
}

int	ft_init_check(t_img *img)
{
	if (!img->tile_img || !img->tile_map || !img->tile_wall || !img->tile_item)
		return (0);
	if (!img->tile_exit || !img->main_idle_1 || !img->main_idle_2)
		return (0);
	if (!img->main_idle_3 || !img->main_walk_up || !img->main_walk_left)
		return (0);
	if (!img->main_walk_right)
		return (0);
	return (1);
}

int	ft_init_secure(t_data *data)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		exit_second_stage(data);
	img->tile_img = mxf(data->mlx_ptr, "./assets/tile.xpm");
	img->tile_map = mxf(data->mlx_ptr, "./assets/tile-map.xpm");
	img->tile_wall = mxf(data->mlx_ptr, "./assets/tile-wall.xpm");
	img->tile_item = mxf(data->mlx_ptr, "./assets/tile-item.xpm");
	img->tile_exit = mxf(data->mlx_ptr, "./assets/tile-exit.xpm");
	img->main_idle_1 = mxf(data->mlx_ptr, "./assets/idle-1.xpm");
	img->main_idle_2 = mxf(data->mlx_ptr, "./assets/idle-2.xpm");
	img->main_idle_3 = mxf(data->mlx_ptr, "./assets/idle-3.xpm");
	img->main_walk_up = mxf(data->mlx_ptr, "./assets/walk-up.xpm");
	img->main_walk_left = mxf(data->mlx_ptr, "./assets/walk-left.xpm");
	img->main_walk_right = mxf(data->mlx_ptr, "./assets/walk-right.xpm");
	data->img = img;
	if (!ft_init_check(img))
	{
		write(2, "Error: Missing Ressources\n", 26);
		return (0);
	}
	return (1);
}

int	ft_init(t_data *data)
{
	int	code;

	code = ft_init_secure(data);
	if (!code)
		return (0);
	data->key_pressed = 0;
	data->direction = 2;
	data->item_take = 0;
	data->move = 0;
	data->end_of_game = 0;
	ft_print_background(data);
	display_string(data, "Item: 0", (data->map->x_max + 2),
		(data->map->y_max - 4));
	display_string(data, "Move: 0", (data->map->x_max + 2),
		(data->map->y_max - 3));
	return (1);
}
