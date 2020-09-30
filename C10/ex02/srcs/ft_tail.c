/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:40:28 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 19:55:54 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		ft_open_read(int file_size, int tail, char *file_name)
{
	int		fd;
	int		offset;
	int		read_bytes;
	char	buffer[N];
	char	*buffer_tail;

	if (tail > file_size)
		tail = file_size;
	offset = file_size - tail;
	read_bytes = 0;
	if (!(buffer_tail = malloc(sizeof(char) * tail)))
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	while (N < offset)
	{
		read_bytes = read(fd, buffer, N);
		offset = offset - N;
	}
	read(fd, buffer, offset);
	read(fd, buffer_tail, tail);
	write(1, buffer_tail, tail);
	close(fd);
	return (0);
}

void	ft_tail_files(int tail, int argc, char **argv)
{
	static int	is_first_valid_file = 1;
	int			i;
	int			file_size;

	i = 2;
	while (++i < argc)
	{
		file_size = ft_file_size(argv[i]);
		if (argc == 4 && file_size >= -1)
			ft_open_read(file_size, tail, argv[i]);
		else if (file_size >= -1 && is_first_valid_file)
		{
			ft_put_title(argv[i]);
			is_first_valid_file = 0;
			ft_open_read(file_size, tail, argv[i]);
		}
		else if (file_size >= -1 && !is_first_valid_file)
		{
			write(1, "\n", 1);
			ft_put_title(argv[i]);
			ft_open_read(file_size, tail, argv[i]);
		}
		else
			ft_error_msg(argv[0], argv[i]);
	}
}

void	read_stdin(int tail)
{
	int		bytes;
	int		prev_bytes;
	int		read_bytes;
	char	buffer[N_STDIN];

	read_bytes = 0;
	while ((bytes = read(0, buffer, N_STDIN)))
	{
		prev_bytes = bytes;
		read_bytes += bytes;
	}
	if (tail > read_bytes)
		tail = read_bytes;
	write(1, buffer + prev_bytes - tail, tail);
}

int		ft_tail(int argc, char **argv)
{
	int tail;

	if (argc < 3)
		return (0);
	if (flag_is_ok(argv) < 0)
		return (0);
	tail = ft_atoi_spe(argv[2]);
	if (argc == 3)
		read_stdin(tail);
	else
		ft_tail_files(tail, argc, argv);
	return (0);
}
