/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:42:04 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 15:37:04 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_file_size(char *file_name)
{
	int		fd;
	int		buff_size;
	int		file_size;
	char	buffer[N];

	file_size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-2);
	while ((buff_size = read(fd, buffer, N)))
	{
		if (buff_size < 0)
		{
			close(fd);
			return (-1);
		}
		file_size += buff_size;
	}
	close(fd);
	return (file_size);
}

int	ft_atoi_spe(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-2);
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}

int	flag_is_ok(char **argv)
{
	int tail;

	if (argv[1][0] != '-' || argv[1][1] != 'c' || argv[1][2] != '\0')
		return (-2);
	tail = ft_atoi_spe(argv[2]);
	return (tail);
}
