/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_copy_hexa_with_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:48:43 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:22:44 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	copy_hexa_with_c(char *final_line, char *line, int line_len)
{
	int	i;
	int	n;

	i = 0;
	n = 9;
	final_line[8] = ' ';
	while (i < line_len && i < 16)
	{
		n = copy_hexa_with_c_one(final_line, line, i, n);
		n += 2;
		i++;
	}
	while (i >= line_len && i < 16)
	{
		n = copy_hexa_with_c_two(final_line, i, n);
		n += 2;
		i++;
	}
}

int		copy_hexa_with_c_one(char *final_line, char *line, int i, int n)
{
	const char	hexa[] = "0123456789abcdef";

	final_line[i + n] = ' ';
	final_line[i + n + 1] = hexa[(unsigned char)line[i] / 16];
	final_line[i + n + 2] = hexa[(unsigned char)line[i] % 16];
	if (i == 7)
	{
		final_line[i + n + 3] = ' ';
		n++;
	}
	return (n);
}

int		copy_hexa_with_c_two(char *final_line, int i, int n)
{
	final_line[i + n] = ' ';
	final_line[i + n + 1] = ' ';
	final_line[i + n + 2] = ' ';
	if (i == 7)
	{
		final_line[i + n + 3] = ' ';
		n++;
	}
	return (n);
}
