/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:39:24 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:23:37 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int		ft_hexdump(int argc, char **argv)
{
	t_file	*file;
	t_save	*saver;

	saver = init_saver();
	if (argc > 1)
		saver->flag_c = is_flag_c(argv[1]);
	if (argc < 2 || (argc < 3 && (saver->flag_c)))
		return (hexdump_stdin(saver));
	else
	{
		file = open_files(argc, argv, saver);
		hexdump_files(argv[0], file, saver);
	}
	free_file(file);
	return (0);
}

int		is_flag_c(char *str)
{
	if (str[0] != '-')
		return (0);
	if (str[1] != 'C')
		return (0);
	return (1);
}

int		hexdump_stdin(t_save *saver)
{
	int		no_input;
	int		i;
	char	c;
	char	line[16];

	i = 0;
	no_input = 1;
	while (read(0, &c, 1))
	{
		line[i++] = c;
		no_input = 0;
		if (i == 16)
			i = make_final_line(16, line, saver);
	}
	if (no_input)
		return (free_saver(saver));
	if (i)
		make_final_line(i, line, saver);
	last_counter(saver->counter, i, saver);
	return (free_saver(saver));
}

int		hexdump_files(char *prog_name, t_file *file, t_save *saver)
{
	int	i;
	int	all_files_wrong;

	i = -1;
	all_files_wrong = 1;
	while (file[++i].name)
	{
		if (file[i].fd < 0)
			error_message(file[i].error_nbr, prog_name, file[i].name);
		else
		{
			all_files_wrong = 0;
			read_file(prog_name, file[i], saver);
		}
	}
	if (!(all_files_wrong))
	{
		if (saver->line_rest)
			make_final_line(saver->size_rest, saver->line_rest, saver);
		if (saver->counter)
			last_counter(saver->counter, saver->size_rest, saver);
	}
	else
		bad_file_descriptor(prog_name, file[i - 1].name);
	return (free_saver(saver));
}
