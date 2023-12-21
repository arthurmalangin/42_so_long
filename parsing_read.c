/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 01:04:36 by amalangi          #+#    #+#             */
/*   Updated: 2023/12/21 05:24:14 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_fill_helper(char *text, char *buffer, int fd)
{
	if (buffer)
		free(buffer);
	if (text)
		free(text);
	close(fd);
}

char	*read_file(int byte_read, char *buffer, char *text, int fd)
{
	while (byte_read > 0 && text)
	{
		byte_read = read(fd, buffer, 19);
		if (byte_read < 0)
			break ;
		buffer[byte_read] = 0;
		text = join_free(text, buffer, 0);
	}
	return (text);
}

int	count_occur(char *src, char *occ)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (src[i])
	{
		j = 0;
		if (src[i] == occ[j])
		{
			while (src[i + j] == occ[j] && occ[j] && src[j + i])
				j++;
			if (occ[j] == 0)
				count++;
		}
		i++;
	}
	return (count);
}

char	*read_fill(char *path_to_map)
{
	char	*buffer;
	char	*text;
	int		fd;

	fd = open(path_to_map, O_RDONLY);
	if (fd < 1)
		return (NULL);
	text = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(21, sizeof(char));
	if (!text || !buffer)
	{
		read_fill_helper(text, buffer, fd);
		return (NULL);
	}
	text = read_file(1, buffer, text, fd);
	free(buffer);
	close(fd);
	if (!count_occur(text, "\n\n"))
		return (text);
	write(2, "Error\nMap is not rectangle !\n", 29);
	free(text);
	return (NULL);
}

char	**buffer_to_map(char *buffer)
{
	char	**map;
	int		max_y;
	int		i;
	char	*tmp;

	if (!buffer)
		return (NULL);
	max_y = count_char(buffer, '\n');
	map = ft_calloc(max_y + 1, sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < max_y)
	{
		tmp = buffer_to_map_integer(buffer, 0 + i);
		if (!tmp)
		{
			free(map);
			return (NULL);
		}
		map[i] = tmp;
		i++;
	}
	return (map);
}
