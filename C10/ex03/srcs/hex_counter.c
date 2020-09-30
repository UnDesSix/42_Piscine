/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:43:20 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:23:03 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

char	*init_counter(t_save *saver)
{
	int		i;
	char	*counter;

	i = 0;
	if (!(saver->flag_c))
	{
		if (!(counter = malloc(sizeof(char) * 8)))
			return (0);
		while (i < 7)
			counter[i++] = '0';
		counter[7] = '\0';
	}
	else
	{
		if (!(counter = malloc(sizeof(char) * 9)))
			return (0);
		while (i < 8)
			counter[i++] = '0';
		counter[8] = '\0';
	}
	return (counter);
}

int		incr_counter(char *counter, t_save *saver)
{
	int i;

	if (saver->flag_c)
		i = 6;
	else
		i = 5;
	while (counter[i] == 'f')
	{
		counter[i] = '0';
		if (i > 1)
			i--;
	}
	if ((counter[i] >= '0' && counter[i] < '9')
				|| (counter[i] >= 'a' && counter[i] < 'f'))
		counter[i]++;
	else if (counter[i] == '9')
		counter[i] = 'a';
	return (0);
}

void	last_counter(char *counter, int size_rest, t_save *saver)
{
	int			i;
	const char	hexa[] = "0123456789abcdef";

	if (size_rest == 16)
		size_rest = 0;
	if (saver->flag_c)
		i = 7;
	else
		i = 6;
	if (!(size_rest))
		incr_counter(counter, saver);
	else
		counter[i] = hexa[size_rest];
	ft_putstr(counter, 1);
	ft_putstr("\n", 1);
}
