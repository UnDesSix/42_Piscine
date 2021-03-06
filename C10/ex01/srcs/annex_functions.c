/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:30:20 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/23 14:56:49 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_error_msg(char *prog_name, char *file_name)
{
	ft_putstr_error(basename(prog_name));
	ft_putstr_error(": ");
	ft_putstr_error(file_name);
	ft_putstr_error(": ");
	ft_putstr_error(strerror(errno));
	ft_putstr_error("\n");
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_error(char *str)
{
	write(2, str, ft_strlen(str));
}
