/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:08:01 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:29:01 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_open_n_read(char *name_file)
{
	int				fd;
	unsigned int	buff_size;
	char			buffer[4096];

	fd = open(name_file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((buff_size = read(fd, buffer, 4096)))
	{
		if (buff_size < 0)
			return (0);
		write(1, buffer, buff_size);
	}
	close(fd);
	return (1);
}

int		ft_display_file(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		if (!ft_open_n_read(argv[1]))
			ft_putstr("Cannot read file.\n");
	}
	return (0);
}
