/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:59:39 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/09 13:23:47 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_hexa(char c)
{
	static char hexa[] = "0123456789abcdef";

	ft_putchar(92);
	ft_putchar(hexa[(unsigned char)c / 16]);
	ft_putchar(hexa[(unsigned char)c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_printable(str[i]))
			ft_putchar(str[i]);
		else
			ft_putstr_hexa(str[i]);
		i++;
	}
}
