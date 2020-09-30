/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:40:40 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:23:29 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	bad_file_descriptor(char *prog_name, char *last_file_name)
{
	ft_putstr(basename(prog_name), 2);
	ft_putstr(": ", 2);
	ft_putstr(last_file_name, 2);
	ft_putstr(": Bad file descriptor\n", 2);
}

int		error_message(int error_nbr, char *prog_name, char *file_name)
{
	ft_putstr(basename(prog_name), 2);
	ft_putstr(": ", 2);
	ft_putstr(file_name, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(error_nbr), 2);
	ft_putstr("\n", 2);
	return (0);
}

int		err_mess_dir(char *prog_name, char *file_name)
{
	ft_putstr(basename(prog_name), 2);
	ft_putstr(": ", 2);
	ft_putstr(file_name, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
	return (0);
}
