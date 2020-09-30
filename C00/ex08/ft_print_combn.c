/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn_v4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 13:42:43 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/08 16:36:09 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		tab_is_last(int n, int *tab)
{
	int i;
	int diff;

	if (tab[n - 1] == 9)
	{
		if (n == 1)
			return (1);
		i = 1;
		while (i < n)
		{
			diff = tab[i] - tab[i - 1];
			if (diff != 1)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	display_tab(int n, int *tab)
{
	char	value;
	int		i;

	i = 0;
	while (i < n)
	{
		value = tab[i] + 48;
		write(1, &value, 1);
		i++;
	}
	if (!tab_is_last(n, tab))
		write(1, ", ", 2);
}

int		tab_is_valid(int n, int *tab)
{
	int i;

	i = 0;
	while (i + 1 < n)
	{
		if (tab[i] >= tab[i + 1])
			return (0);
		i++;
	}
	display_tab(n, tab);
	return (1);
}

void	ft_print_combn(int n)
{
	int i;
	int	tab[9];

	i = -1;
	while (++i < n)
		tab[i] = i;
	while (!(tab_is_last(n, tab)))
	{
		i = n - 1;
		tab_is_valid(n, tab);
		tab[i] += 1;
		while (i > 0)
		{
			tab[i] == 10 ? tab[i - 1]++ : 0;
			tab[i] == 10 ? tab[i] = tab[i - 1] - 1 : 0;
			i--;
		}
	}
	display_tab(n, tab);
}
