/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:41:29 by amalangin         #+#    #+#             */
/*   Updated: 2023/12/16 03:49:39 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keyrelease(int keysym, t_data *data)
{
	data->key_pressed = 0;
	if (keysym == ESC)
		return (on_destroy(data));
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	data->key_pressed = 1;
	while (data->key_pressed == 1 && !data->end_of_game)
	{
		player_update_direction(data, keysym);
		if (keysym == ESC)
			return (on_destroy(data));
		else if (keysym == W)
			return (ft_print_player(data, data->player_pos_x,
					data->player_pos_y - 1));
		else if (keysym == A)
			return (ft_print_player(data,
					data->player_pos_x - 1, data->player_pos_y));
		else if (keysym == S)
			return (ft_print_player(data,
					data->player_pos_x, data->player_pos_y + 1));
		else if (keysym == D)
			return (ft_print_player(data,
					data->player_pos_x + 1, data->player_pos_y));
		else
			break ;
	}
	return (0);
}

void	register_hook(t_data *data)
{
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keyrelease, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, data);
}

int	map_name_valid(int argc, char *argv, char *valid_format)
{
	int	i;
	int	j;

	if (argc < 2)
	{
		write(2, "Error\nNo Argument", 17);
		return (0);
	}
	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i] == valid_format[j])
		{
			while (argv[i + j] == valid_format[j] && valid_format[j])
				j++;
			if (valid_format[j] == 0 && argv[i + j] == 0)
				return (1);
		}
		i++;
	}
	write(2, "Error\nBad extension of map file !", 33);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!map_name_valid(argc, argv[1], ".ber"))
		return (1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = NULL;
	data.check_id = ft_checkos(&data, argv[1]);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.map->x_max + 5) * 32,
			(data.map->y_max + 1) * 32, "./so_long");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return (1);
	}
	if (!ft_init(&data))
	{
		on_destroy(&data);
		return (1);
	}
	ft_map(&data);
	register_hook(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
