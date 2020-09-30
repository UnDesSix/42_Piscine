/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:24:55 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/20 19:38:06 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*final_tab;

	i = 0;
	if (!(final_tab = malloc(sizeof(int) * length)))
		return (0);
	while (i < length)
	{
		final_tab[i] = (*f)(tab[i]);
		i++;
	}
	return (final_tab);
}
