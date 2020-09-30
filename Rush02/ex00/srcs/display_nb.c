/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 22:38:40 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/27 20:58:38 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_uni(t_key_number *tab, char *nbr, int comp)
{
	int		i;
	char	*cmp_nbr;

	if (!(cmp_nbr = ft_strndup(nbr, 1)))
		return (-1);
	i = 0;
	while (ft_strcmp(tab[i].key, cmp_nbr) != 0)
		i++;
	if (cmp_nbr[0] != '0')
		ft_write_number(tab[i].data);
	free(cmp_nbr);
	if (comp != 0)
		ft_write_number(tab[comp + 28].data);
	return (0);
}

int		ft_dec(t_key_number *tab, char *nbr, int comp)
{
	int		i;
	char	*cmp_nbr;
	char	*cmp_nbr_dec;

	i = 0;
	if (nbr[0] < '2')
		return (ft_dec_bis(tab, nbr, comp, i));
	if (!(cmp_nbr_dec = ft_strndup_n(nbr, 2)))
		return (-1);
	while (ft_strcmp(tab[i].key, cmp_nbr_dec))
		i++;
	free(cmp_nbr_dec);
	ft_write_number(tab[i].data);
	if (!(cmp_nbr = ft_strndup_n(nbr + 1, 1)))
		return (-1);
	if (ft_uni(tab, cmp_nbr, 0) < 0)
		return (-1);
	free(cmp_nbr);
	if (comp != 0)
		ft_write_number(tab[comp + 28].data);
	return (0);
}

int		ft_dec_bis(t_key_number *tab, char *nbr, int comp, int i)
{
	char	*cmp_nbr;

	if (!(cmp_nbr = ft_strndup(nbr, 2)))
		return (-1);
	while (ft_strcmp(tab[i].key, cmp_nbr) != 0)
		i++;
	free(cmp_nbr);
	ft_write_number(tab[i].data);
	if (comp != 0)
		ft_write_number(tab[comp + 28].data);
	return (0);
}

int		ft_hun(t_key_number *tab, char *nbr, int comp)
{
	int		i;
	char	*cmp_nbr_hun;
	char	*cmp_nbr_dec;

	i = 0;
	if (!(cmp_nbr_hun = ft_strndup_n(nbr, 1)))
		return (-1);
	if (ft_uni(tab, cmp_nbr_hun, 0) < 0)
		return (-1);
	free(cmp_nbr_hun);
	ft_write_number(tab[28].data);
	if (!(cmp_nbr_dec = ft_strndup(nbr + 1, 2)))
		return (-1);
	if (cmp_nbr_dec[0] != '0')
		ft_dec(tab, cmp_nbr_dec, 0);
	else if (cmp_nbr_dec[0] == '0')
		if (ft_uni(tab, cmp_nbr_dec + 1, 0) < 0)
			return (-1);
	free(cmp_nbr_dec);
	if (comp != 0)
		ft_write_number(tab[comp + 28].data);
	return (0);
}

int		ft_display_nb(t_key_number *tab, char *nbr)
{
	int i;
	int nb_len;
	int	flag;

	i = 0;
	nb_len = ft_strlen(nbr);
	while (i < nb_len)
	{
		flag = 1;
		if ((nb_len - i) % 3 == 0)
			if (!(ft_displ_first(tab, nbr, &flag, &i)))
				return (-1);
		if ((nb_len - i) % 3 == 2)
			if (!(ft_displ_second(tab, nbr, &flag, &i)))
				return (-1);
		if ((nb_len - i) % 3 == 1)
			if (!(ft_displ_third(tab, nbr, &flag, &i)))
				return (-1);
	}
	return (0);
}
