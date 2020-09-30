/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:13:58 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/28 16:15:43 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

unsigned int	go_next_index(t_file *file, unsigned int *index
				, t_position current, unsigned int size)
{
	t_position base;

	base = get_position(file, *index);
	*index += current.x - base.x + 1;
	if (file->line_size - getx(file, *index) <= file->bsq.size)
		*index += file->line_size - getx(file, *index);
	return (size);
}

unsigned int	get_sqr_size(t_file *file, unsigned int *index)
{
	unsigned int	size;
	t_position		base;
	t_position		check;

	size = 1;
	base = get_position(file, *index);
	while (1)
	{
		check = set_position(base.x, base.y + size);
		while (check.x < base.x + size)
		{
			if ((file->buff)[get_index(file, check)] != file->c_empt)
				return (go_next_index(file, index, check, size));
			check.x++;
		}
		while (check.y > base.y)
		{
			if ((file->buff)[get_index(file, check)] != file->c_empt)
				return (go_next_index(file, index, check, size));
			check.y--;
		}
		if ((file->buff)[get_index(file, check)] != file->c_empt)
			return (go_next_index(file, index, check, size));
		size++;
	}
}

void			find_bsq(t_file *file)
{
	unsigned int	i;
	unsigned int	max;
	t_square		next;

	i = 0;
	max = file->nb_lines < file->line_size ? file->nb_lines : file->line_size;
	while (file->nb_lines - gety(file, i) > file->bsq.size
			&& i < file->map_size)
	{
		while ((file->buff)[i] != file->c_empt && i < file->map_size)
			i++;
		if (i >= file->map_size)
			return ;
		else if (file->nb_lines - gety(file, i) > file->bsq.size)
		{
			next.base = get_position(file, i);
			next.size = get_sqr_size(file, &i);
			if (next.size > file->bsq.size)
			{
				file->bsq = next;
				if (file->bsq.size == max)
					return ;
			}
		}
	}
}

void			fill_map(t_file *file)
{
	unsigned long	i;
	unsigned short	j;
	unsigned short	k;

	i = get_index(file, file->bsq.base);
	j = 0;
	while (j < file->bsq.size)
	{
		k = 0;
		while (k < file->bsq.size)
		{
			file->buff[i] = file->c_sqr;
			i++;
			k++;
		}
		i += file->line_size - file->bsq.size;
		j++;
	}
}

void			display_bsq(t_file *file)
{
	unsigned long	remaining;
	unsigned long	index;
	unsigned int	to_disp;

	remaining = file->map_size;
	index = 0;
	if (file->bsq.size > 0)
		fill_map(file);
	while (remaining > 0)
	{
		to_disp = remaining < BUFF_SIZE ? remaining : BUFF_SIZE;
		write(1, file->buff + index, to_disp);
		index += to_disp;
		remaining -= to_disp;
	}
}
