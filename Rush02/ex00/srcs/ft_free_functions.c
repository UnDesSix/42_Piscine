/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 21:17:17 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/27 22:45:22 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_free_final_tab(t_key_number *final_tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (final_tab[i].key)
			free(final_tab[i].key);
		if (final_tab[i].data)
			free(final_tab[i].data);
		i++;
	}
	free(final_tab);
	return (0);
}

int		ft_putstr_final_tab(char *str, t_key_number *final_tab, int size)
{
	write(1, str, ft_strlen(str));
	ft_free_final_tab(final_tab, size);
	return (0);
}

int		ft_putstr_dict_saver(char *str, char *dict_saver)
{
	write(1, str, ft_strlen(str));
	free(dict_saver);
	return (0);
}
