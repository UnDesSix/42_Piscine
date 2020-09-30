/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:30:50 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:24:01 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

t_file	*open_files(int argc, char **argv, t_save *saver)
{
	int		i;
	int		j;
	t_file	*file;

	if (!(file = malloc(sizeof(t_file) * (argc - (saver->flag_c)))))
		return (0);
	i = 0;
	j = 1 + saver->flag_c;
	while (j < argc)
	{
		errno = 0;
		file[i].fd = open(argv[j], O_RDONLY);
		file[i].error_nbr = errno;
		file[i].name = ft_strcpy(file[i].name, argv[j]);
		j++;
		i++;
	}
	file[i].name = NULL;
	return (file);
}

t_save	*init_saver(void)
{
	t_save *saver;

	if (!(saver = malloc(sizeof(t_save))))
		return (0);
	saver->counter = NULL;
	saver->last_dspl = NULL;
	saver->line_rest = NULL;
	saver->size_rest = 0;
	saver->flag_c = 0;
	return (saver);
}

int		free_file(t_file *file)
{
	int i;

	i = 0;
	while (file[i].name)
	{
		free(file[i].name);
		i++;
	}
	free(file);
	return (0);
}

int		free_saver(t_save *saver)
{
	if (saver->counter)
		free(saver->counter);
	if (saver->last_dspl)
		free(saver->last_dspl);
	if (saver->line_rest)
		free(saver->line_rest);
	free(saver);
	return (0);
}
