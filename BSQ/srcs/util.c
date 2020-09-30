/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:31:08 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/28 16:31:09 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_square		init_square(unsigned int x, unsigned int y, unsigned int size)
{
	t_square	square;

	square.base.x = x;
	square.base.y = y;
	square.size = size;
	return (square);
}

void			fill_buff(t_file *file, int fd)
{
	ssize_t			bytes;
	unsigned long	index;

	index = 0;
	while ((bytes = read(fd, file->buff + index, 1000000000)))
	{
		if (bytes == -1)
		{
			file->err = 7;
			return ;
		}
		index += bytes;
	}
}
