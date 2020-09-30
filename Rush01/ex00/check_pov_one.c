/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pov_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 20:22:46 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/20 12:01:29 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscrapper.h"

int		ft_nb_box_colup(int **square, int i, int size)
{
	int y;
	int x;
	int nb_of_box;
	int max_heigh;

	nb_of_box = 1;
	y = i % size;
	x = 0;
	max_heigh = square[x][y];
	while (x < size - 1)
	{
		if (square[x][y] < square[x + 1][y] && max_heigh <= square[x + 1][y])
		{
			max_heigh = square[x + 1][y];
			nb_of_box++;
		}
		x++;
	}
	return (nb_of_box);
}

int		ft_nb_box_coldown(int **square, int i, int size)
{
	int y;
	int x;
	int nb_of_box;
	int max_heigh;

	nb_of_box = 1;
	y = i % size;
	x = size - 1;
	max_heigh = square[x][y];
	while (x > 0)
	{
		if (square[x][y] < square[x - 1][y] && max_heigh <= square[x - 1][y])
		{
			max_heigh = square[x - 1][y];
			nb_of_box++;
		}
		x--;
	}
	return (nb_of_box);
}

int		ft_nb_box_rowleft(int **square, int i, int size)
{
	int y;
	int x;
	int nb_of_box;
	int max_heigh;

	nb_of_box = 1;
	x = i % size;
	y = 0;
	max_heigh = square[x][y];
	while (y < size - 1)
	{
		if (square[x][y] < square[x][y + 1] && max_heigh <= square[x][y + 1])
		{
			max_heigh = square[x][y + 1];
			nb_of_box++;
		}
		y++;
	}
	return (nb_of_box);
}

int		ft_nb_box_rowright(int **square, int i, int size)
{
	int y;
	int x;
	int nb_of_box;
	int max_heigh;

	nb_of_box = 1;
	x = i % size;
	y = size - 1;
	max_heigh = square[x][y];
	while (y > 0)
	{
		if (square[x][y] < square[x][y - 1] && max_heigh <= square[x][y - 1])
		{
			max_heigh = square[x][y - 1];
			nb_of_box++;
		}
		y--;
	}
	return (nb_of_box);
}
