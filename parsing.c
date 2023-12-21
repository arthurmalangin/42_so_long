/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:26:37 by amalangin         #+#    #+#             */
/*   Updated: 2023/12/16 07:34:05 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map(t_data *data)
{
	if (data->check_id != 0)
	{
		print_error_code(data->check_id);
		on_destroy(data);
	}
	ft_print_map(data);
	return (0);
}

int	ft_checkos(t_data *data, char *path_to_map)
{
	t_map	*map;
	char	*buffer;
	char	**map_from_file;
	int		check_code;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_first_stage(data, map);
	buffer = read_fill(path_to_map);
	if (!buffer)
		exit_first_stage(data, map);
	map_from_file = buffer_to_map(buffer);
	if (!map_from_file)
	{
		free(map);
		free(buffer);
		data->map = NULL;
		exit_second_stage(data);
	}
	map->map = map_from_file;
	data->map = map;
	check_code = map_is_valid(data, buffer);
	free(buffer);
	return (check_code);
}

char	*buffer_to_map_integer(char *buffer, int kp)
{
	static int	k;
	char		*map;
	int			j;

	if (kp == 0)
		k = 0;
	map = ft_calloc((ft_strlen_to_char(&buffer[k], '\n') + 1), sizeof(char));
	if (!map)
		return (NULL);
	j = 0;
	while (buffer[j + k] != '\n' && buffer[j + k] != '\0')
	{
		map[j] = buffer[j + k];
		j++;
	}
	k += j + 1;
	return (map);
}
