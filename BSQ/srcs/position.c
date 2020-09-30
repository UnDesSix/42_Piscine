/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:17:10 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/28 16:17:54 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

unsigned int	gety(t_file *file, unsigned int index)
{
	return (index / file->line_size);
}

unsigned int	getx(t_file *file, unsigned int index)
{
	return (index - gety(file, index) * file->line_size);
}

t_position		get_position(t_file *file, unsigned int index)
{
	t_position position;

	position.x = getx(file, index);
	position.y = gety(file, index);
	return (position);
}

t_position		set_position(unsigned int x, unsigned int y)
{
	t_position position;

	position.x = x;
	position.y = y;
	return (position);
}

unsigned int	get_index(t_file *file, t_position position)
{
	return (position.y * file->line_size + position.x);
}
