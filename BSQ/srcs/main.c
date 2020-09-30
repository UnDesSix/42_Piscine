/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:16:30 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/28 16:17:08 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		main(int argc, char **argv)
{
	static unsigned short	i = 1;
	t_file					file;

	if (argc == 1)
		read_input(&file);
	while (i < argc)
	{
		file = init_file(argv[i]);
		if (file.err != FALSE)
			write(2, "map error\n", 10);
		else
		{
			file.buff += file.size_descript;
			find_bsq(&file);
			display_bsq(&file);
			file.buff -= file.size_descript;
		}
		i < argc - 1 ? write(1, "\n", 1) : 0;
		file.buff ? free(file.buff) : 0;
		i++;
	}
	return (0);
}
