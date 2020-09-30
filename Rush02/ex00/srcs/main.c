/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:47:13 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/27 23:15:31 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		number_is_valid(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int		ft_file_size(char *file_name)
{
	char	buffer[4096];
	int		read_bytes;
	int		file_size;
	int		fd;

	file_size = 0;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (0);
	while ((read_bytes = read(fd, buffer, 4096)))
	{
		if (read_bytes < 0)
			return (0);
		file_size += read_bytes;
	}
	close(fd);
	return (file_size);
}

int		ft_argc_two(char **argv)
{
	char			*dict_saver;
	t_key_number	*final_tab;

	if (!number_is_valid(argv[1]))
		return (ft_putstr("Error\n"));
	if (!(dict_saver = ft_fill_tab("numbers.dict",
							ft_file_size("numbers.dict"))))
		return (ft_putstr("Error\n"));
	if (!(final_tab = ft_split(dict_saver, 41)))
		return (ft_putstr_dict_saver("Error\n", dict_saver));
	free(dict_saver);
	if (ft_is_zero(final_tab, argv[1]))
		return (ft_free_final_tab(final_tab, 41));
	if (!(ft_nbr_size(argv[1], final_tab, 41)))
		return (ft_putstr_final_tab("Error\n", final_tab, 41));
	if (ft_display_nb(final_tab, argv[1]) < 0)
		return (ft_putstr_final_tab("Error\n", final_tab, 41));
	write(1, "\n", 1);
	return (ft_free_final_tab(final_tab, 41));
}

int		ft_argc_three(char **argv)
{
	int				nb_of_lines;
	char			*dict_saver;
	t_key_number	*final_tab;

	nb_of_lines = 0;
	if (!number_is_valid(argv[2]))
		return (ft_putstr("Error\n"));
	if (!(dict_saver = ft_fill_tab(argv[1], ft_file_size(argv[1]))))
		return (ft_putstr("Error\n"));
	if ((nb_of_lines = ft_dict_is_valid(dict_saver)) < 0)
		return (ft_putstr_dict_saver("Error\n", dict_saver));
	if (!(final_tab = ft_split(dict_saver, nb_of_lines)))
		return (ft_putstr_dict_saver("Error\n", dict_saver));
	free(dict_saver);
	if (!(final_tab = ft_sort_in_tab(final_tab, nb_of_lines)))
		return (ft_putstr_final_tab("Error\n", final_tab, nb_of_lines));
	if (ft_is_zero(final_tab, argv[2]))
		return (ft_free_final_tab(final_tab, nb_of_lines));
	if (!(ft_nbr_size(argv[2], final_tab, nb_of_lines)))
		return (ft_putstr_final_tab("Error\n", final_tab, nb_of_lines));
	if (ft_display_nb(final_tab, argv[2]) < 0)
		return (ft_putstr_final_tab("Error\n", final_tab, nb_of_lines));
	write(1, "\n", 1);
	return (ft_free_final_tab(final_tab, nb_of_lines));
}

int		main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (ft_putstr("Error\n"));
	if (argc == 2)
		return (ft_argc_two(argv));
	else
		return (ft_argc_three(argv));
}
