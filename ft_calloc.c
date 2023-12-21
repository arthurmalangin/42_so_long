/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 04:11:35 by amalangi          #+#    #+#             */
/*   Updated: 2023/12/16 01:06:36 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*ptr;

	if ((long long)elementCount < 0 || (long long)elementSize < 0)
	{
		if (((long long)elementCount < 0 && (long long)elementSize == 0)
			|| ((long long)elementCount == 0 && (long long)elementSize < 0))
			return (malloc(0));
		return (NULL);
	}
	ptr = malloc(elementCount * elementSize);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, elementSize * elementCount);
	return (ptr);
}
