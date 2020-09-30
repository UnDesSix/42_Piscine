/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_functions_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 12:22:30 by eoliveir          #+#    #+#             */
/*   Updated: 2020/09/27 20:18:16 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_struct_cmp(t_key_number t1, t_key_number t2)
{
	if (t1.size > t2.size)
		return (1);
	if (t1.size < t2.size)
		return (-1);
	return (ft_strcmp(t1.key, t2.key));
}

void	ft_write_number(char *nbr)
{
	static int	flag_first = 0;

	if (flag_first)
		write(1, " ", 1);
	flag_first = 1;
	write(1, nbr, ft_strlen(nbr));
}

int		ft_is_zero(t_key_number *tab, char *nbr)
{
	int i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] != '0')
			return (0);
		i++;
	}
	write(1, tab[0].data, ft_strlen(tab[0].data));
	write(1, "\n", 1);
	return (1);
}

int		ft_nbr_size(char *str, t_key_number *tab, int size_tab)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] && str[i] == '0')
		i++;
	len = ft_strlen(str);
	len -= i;
	if (len >= ft_strlen(tab[size_tab - 1].key) + 3)
		return (0);
	return (1);
}
