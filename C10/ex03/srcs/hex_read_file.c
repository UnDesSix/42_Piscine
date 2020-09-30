/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:34:49 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:23:43 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	read_file(char *prog_name, t_file file, t_save *saver)
{
	int		read_bytes;
	char	buffer[BUFF_SIZE];

	if (saver->line_rest)
		merge_rest_n_buffer(file, saver);
	while ((read_bytes = read(file.fd, buffer, BUFF_SIZE)))
	{
		if (read_bytes < 0)
			return (err_mess_dir(prog_name, file.name));
		read_buffer(read_bytes, buffer, saver);
	}
	return (0);
}

int	merge_rest_n_buffer(t_file file, t_save *saver)
{
	int		offset;
	int		read_bytes;
	int		i;
	char	buffer[BUFF_SIZE];

	i = -1;
	offset = saver->size_rest;
	if ((read_bytes = read(file.fd, buffer + offset, BUFF_SIZE - offset)) >= 0)
	{
		while (++i < offset)
			buffer[i] = saver->line_rest[i];
		free(saver->line_rest);
		read_buffer(read_bytes + offset, buffer, saver);
		return (0);
	}
	return (0);
}

int	read_buffer(int read_bytes, char *buffer, t_save *saver)
{
	int		i;
	int		j;
	char	line[17];

	i = 0;
	while (i < read_bytes)
	{
		j = -1;
		while (++j < 16 && i < read_bytes)
			line[j] = buffer[i++];
		line[16] = '\0';
		if (j == 16)
		{
			make_final_line(j, line, saver);
			saver->line_rest = NULL;
			saver->size_rest = 0;
		}
		else
		{
			saver->line_rest = ft_strncpy(line, j);
			saver->size_rest = j;
		}
	}
	return (0);
}
