/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:17:56 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/29 11:16:59 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

unsigned long	get_file_size(char *filename)
{
	unsigned long	size;
	ssize_t			bytes;
	int				fd;
	char			buff[BUFF_SIZE];

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes == -1)
			return (0);
		size += bytes;
	}
	close(fd);
	return (size);
}

short			find_params(t_file *file, unsigned short index)
{
	unsigned short	i;

	i = 0;
	file->c_sqr = file->buff[index - 1];
	file->c_obst = file->buff[index - 2];
	file->c_empt = file->buff[index - 3];
	while (i < index - 3)
	{
		if (file->buff[i] < 48 || file->buff[i] > 57)
			return (FALSE);
		file->nb_lines *= 10;
		file->nb_lines += file->buff[i] - 48;
		i++;
	}
	if (file->nb_lines < 1 || file->c_empt == file->c_obst
		|| file->c_empt == file->c_sqr || file->c_obst == file->c_sqr)
		return (FALSE);
	return (TRUE);
}

void			set_description_line(t_file *file)
{
	unsigned short i;

	i = 0;
	file->size_descript = 0;
	file->c_empt = 0;
	file->c_obst = 0;
	file->c_sqr = 0;
	file->nb_lines = 0;
	while (file->buff[i] != 10 && i < file->file_size)
		i++;
	if (file->buff[i] != 10 || find_params(file, i) == FALSE
		|| file->buff[i + 1] == 0)
		file->err = 3;
	else
		file->size_descript = i + 1;
}

void			check_map(t_file *file)
{
	unsigned long		i;
	unsigned long		j;
	unsigned int		count_l;

	i = file->size_descript;
	j = file->size_descript;
	count_l = 0;
	while (file->buff[i] != 10 && i < file->file_size)
		i++;
	i > j ? file->line_size = i - j + 1 : 0;
	i <= j ? file->err = TRUE : 0;
	while (j < file->file_size && file->err == FALSE)
	{
		if (file->buff[j] != 10 && file->buff[j] != file->c_empt
			&& file->buff[j] != file->c_obst)
			file->err = 4;
		else if (file->buff[j] == 10)
		{
			j != i ? (file->err = TRUE) : (count_l += 1);
			i += file->line_size;
		}
		j++;
	}
	file->buff[j - 1] != 10 || count_l != file->nb_lines ? file->err = 5 : 0;
	file->map_size = file->file_size - file->size_descript;
}

t_file			init_file(char *filename)
{
	t_file	file;
	int		fd;

	file.err = FALSE;
	file.file_size = get_file_size(filename);
	file.bsq = init_square(0, 0, 0);
	fd = open(filename, O_RDONLY);
	file.buff = NULL;
	if (fd < 0)
	{
		file.err = TRUE;
		return (file);
	}
	if (!(file.buff = malloc(sizeof(char) * file.file_size)))
		file.err = 6;
	else
	{
		file.err == FALSE ? fill_buff(&file, fd) : 0;
		file.err == FALSE ? set_description_line(&file) : 0;
		file.err == FALSE ? check_map(&file) : 0;
	}
	close(fd);
	return (file);
}
