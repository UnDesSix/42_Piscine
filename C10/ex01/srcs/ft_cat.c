/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:35:58 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:26:35 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int		ft_open_n_read(char *prog_name, char *file_name)
{
	int		fd;
	int		buff_size;
	char	buffer[4096];

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_error_msg(prog_name, file_name);
		return (0);
	}
	while ((buff_size = read(fd, buffer, 4096)))
	{
		if (buff_size < 0)
		{
			ft_error_msg(prog_name, file_name);
			return (0);
		}
		write(1, buffer, buff_size);
	}
	close(fd);
	return (0);
}

int		read_stdin(void)
{
	int		buff_size;
	char	buffer[4096];

	while ((buff_size = read(0, buffer, 4096)))
		write(1, buffer, buff_size);
	return (0);
}

int		ft_cat(int argc, char **argv)
{
	int i;

	if (argc == 1)
	{
		read_stdin();
		return (0);
	}
	i = 1;
	while (i < argc)
		ft_open_n_read(argv[0], argv[i++]);
	return (0);
}
