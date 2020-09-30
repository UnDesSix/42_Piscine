/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pov_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 20:23:20 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/20 15:36:43 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscrapper.h"

void	free_tab(int **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
}

int		ft_check_col(int **square, int *pov, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (ft_nb_box_colup(square, i, size) != pov[i])
			return (0);
		i++;
	}
	while (i < size * 2)
	{
		if (ft_nb_box_coldown(square, i, size) != pov[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_row(int **square, int *pov, int size)
{
	int i;

	i = size * 2;
	while (i < size * 3)
	{
		if (ft_nb_box_rowleft(square, i, size) != pov[i])
			return (0);
		i++;
	}
	while (i < size * 4)
	{
		if (ft_nb_box_rowright(square, i, size) != pov[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_square(int **square, int *pov, int size)
{
	if (!ft_check_col(square, pov, size))
		return (0);
	if (!ft_check_row(square, pov, size))
		return (0);
	return (1);
}
