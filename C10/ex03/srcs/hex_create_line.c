/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_create_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:41:18 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:23:11 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

char	*malloc_final_line(t_save *saver)
{
	int		i;
	int		length;
	char	*final_line;

	if (saver->flag_c)
	{
		length = 8 + (1 + 16 * 3 + 1) + 2 + (16 + 2) + 1;
		if (!(final_line = malloc(sizeof(char) * (length + 1))))
			return (0);
		final_line[length] = '\0';
		i = -1;
		while (final_line[++i])
			final_line[i] = ' ';
	}
	else
	{
		length = 7 + (16 * 3) + 1;
		if (!(final_line = malloc(sizeof(char) * (length + 1))))
			return (0);
		final_line[length - 1] = '\n';
		final_line[length] = '\0';
	}
	return (final_line);
}

int		make_final_line(int line_len, char *line, t_save *saver)
{
	char	*final_line;

	final_line = NULL;
	if (!(saver->counter))
		saver->counter = init_counter(saver);
	else
		incr_counter(saver->counter, saver);
	if (!final_line)
		final_line = malloc_final_line(saver);
	copy_counter(final_line, saver->counter, saver);
	copy_hexa(final_line, line, line_len, saver);
	if (saver->flag_c)
		copy_text_flag_c(final_line, line, line_len);
	display_final_line(line_len, line, final_line, saver);
	free(saver->last_dspl);
	saver->last_dspl = ft_strncpy(line, line_len);
	free(final_line);
	return (0);
}

void	display_final_line(int line_len, char *line,
								char *final_line, t_save *saver)
{
	static int	flag_asterisk = 0;

	if (saver->last_dspl && !special_cmp(line, saver->last_dspl, line_len))
	{
		if (!flag_asterisk)
			ft_putstr("*\n", 1);
		flag_asterisk = 1;
	}
	else
	{
		flag_asterisk = 0;
		if (!(saver->flag_c))
			write(1, final_line, 56);
		else
			write(1, final_line, (79 - (16 - line_len)));
	}
}
