/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_copy_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:47:09 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:22:51 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	copy_text_flag_c(char *final_line, char *line, int line_len)
{
	int i;

	i = 0;
	final_line[58] = ' ';
	final_line[59] = ' ';
	final_line[60] = '|';
	while (i < line_len)
	{
		if (line[i] > 31 && line[i] < 127)
			final_line[i + 61] = line[i];
		else
			final_line[i + 61] = '.';
		i++;
	}
	final_line[i + 61] = '|';
	final_line[i + 62] = '\n';
	while (i + 62 < 79)
	{
		final_line[i + 63] = '\0';
		i++;
	}
}

int		copy_counter(char *final_line, char *counter, t_save *saver)
{
	int i;

	i = 0;
	if (saver->flag_c)
	{
		while (i < 9)
		{
			final_line[i] = counter[i];
			i++;
		}
	}
	else
	{
		while (i < 7)
		{
			final_line[i] = counter[i];
			i++;
		}
	}
	return (0);
}

void	copy_hexa(char *final_line, char *line, int line_len, t_save *saver)
{
	if (saver->flag_c)
		copy_hexa_with_c(final_line, line, line_len);
	else
		copy_hexa_without_c(final_line, line, line_len);
}

void	copy_hexa_without_c(char *final_line, char *line, int line_len)
{
	int			i;
	int			n;
	const char	hexa[] = "0123456789abcdef";

	i = 0;
	n = 7;
	while (i < line_len && i < 16)
	{
		final_line[i + n] = ' ';
		final_line[i + n + 1] = hexa[(unsigned char)line[i] / 16];
		final_line[i + n + 2] = hexa[(unsigned char)line[i] % 16];
		n += 2;
		i++;
	}
	while (i >= line_len && i < 16)
	{
		final_line[i + n] = ' ';
		final_line[i + n + 1] = ' ';
		final_line[i + n + 2] = ' ';
		n += 2;
		i++;
	}
}
