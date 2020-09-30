/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 21:21:37 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/20 15:14:52 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscrapper.h"

int		ft_iterative_factorial(int nb)
{
	int result;

	result = 1;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	while (nb > 1)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}

void	print_square(int **square, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			square[i][j] += 48;
			write(1, &square[i][j], 1);
			if (j != n - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		*ft_intdup(int n, int *line_saver)
{
	int i;
	int *final_line;

	i = 0;
	if (!(final_line = malloc(sizeof(int) * n)))
		return (0);
	while (i < n)
	{
		final_line[i] = line_saver[i];
		i++;
	}
	return (final_line);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_size_of_n(int *pov)
{
	int i;

	i = 0;
	while (pov[i])
		i++;
	return (i / 4);
}
