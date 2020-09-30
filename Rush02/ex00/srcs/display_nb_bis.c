/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nb_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:46:26 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/27 20:57:50 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_displ_first(t_key_number *tab, char *nbr, int *flag, int *i)
{
	int nb_len;

	nb_len = ft_strlen(nbr);
	if (nbr[*i] != '0')
		if ((*flag = ft_hun(tab, nbr + (*i), (nb_len - 1 - (*i)) / 3)) < 0)
			return (0);
	(*i)++;
	return (1);
}

int		ft_displ_second(t_key_number *tab, char *nbr, int *flag, int *i)
{
	int nb_len;

	nb_len = ft_strlen(nbr);
	if (*flag && nbr[*i] != '0')
		if ((*flag = ft_dec(tab, nbr + (*i), (nb_len - 1 - *i) / 3)) < 0)
			return (0);
	(*i)++;
	return (1);
}

int		ft_displ_third(t_key_number *tab, char *nbr, int *flag, int *i)
{
	int nb_len;

	nb_len = ft_strlen(nbr);
	if (*flag && nbr[*i] != '0')
		if (ft_uni(tab, nbr + (*i), (nb_len - 1 - *i) / 3))
			return (0);
	(*i)++;
	return (1);
}
