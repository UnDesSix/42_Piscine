/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_functions_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:26:52 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/27 22:35:48 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

int		ft_dict_is_valid(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] == '\n')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		while ((str[i] >= '0' && str[i] <= '9') || str[i] == ' '
											|| (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i++] != ':')
			return (-1);
		while (str[i] >= 32 && str[i] <= 126)
			i++;
		if (str[i] != '\n')
			return (-1);
		while (str[i] == '\n')
			i++;
		nb++;
	}
	return (nb);
}

int		is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int		is_space(char c)
{
	if (c == 32)
		return (1);
	return (0);
}
