/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:15:45 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/30 14:15:16 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*refill(char *str, unsigned int index)
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (!(new = malloc(sizeof(char) * index + 1)))
		return (NULL);
	while (i < index)
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	return (new);
}

short	set_input_file(t_file *file)
{
	char		*input;
	char		c;
	static long	i = -1;

	input = file->buff;
	file->file_size = file->nb_lines * file->line_size + file->size_descript;
	if (!(file->buff = malloc(sizeof(char) * file->file_size + 1)))
		return (FALSE);
	while (input[++i])
		file->buff[i] = input[i];
	while (read(0, &c, 1))
	{
		if (i == file->file_size)
		{
			free(input);
			return (FALSE);
		}
		file->buff[i] = c;
		i++;
	}
	file->buff[i] = 0;
	free(input);
	return (TRUE);
}

void	get_input(t_file *file)
{
	static unsigned short	count = 0;
	char					c;

	if (!(file->buff = malloc(sizeof(char) * 1)))
		return ;
	while (read(0, &c, 1) && count < 2)
	{
		file->buff[file->file_size] = c;
		file->file_size += 1;
		file->buff = refill(file->buff, file->file_size);
		c == 10 ? count += 1 : 0;
		count == 1 ? file->line_size += 1 : 0;
	}
	file->buff[file->file_size] = c;
	file->buff[file->file_size + 1] = 0;
	set_description_line(file);
	set_input_file(file) == TRUE ? (check_map(file)) : (file->err = TRUE);
}

void	read_input(t_file *file)
{
	file->file_size = 0;
	file->err = FALSE;
	file->bsq = init_square(0, 0, 0);
	file->line_size = 0;
	get_input(file);
	file->buff += file->size_descript;
	if (file->err != FALSE)
		write(2, "map error\n", 10);
	else
	{
		find_bsq(file);
		display_bsq(file);
	}
	file->buff -= file->size_descript;
	free(file->buff);
}
