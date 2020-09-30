/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:26:27 by eoliveir          #+#    #+#             */
/*   Updated: 2020/09/27 21:20:34 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_key_number	ft_init_struct(char *key, char *data)
{
	t_key_number tmp;

	tmp.key = key;
	tmp.data = data;
	tmp.size = 0;
	tmp.size_max = 0;
	return (tmp);
}

char			*ft_fill_tab(char *file, int size)
{
	int		fd;
	int		j;
	int		read_bytes;
	char	buffer;
	char	*tab;

	j = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	if (!(tab = malloc((size + 1) * sizeof(char))))
		return (0);
	while ((read_bytes = read(fd, &buffer, 1)))
	{
		if (read_bytes < 0)
			return (0);
		tab[j++] = buffer;
	}
	close(fd);
	tab[j] = '\0';
	return (tab);
}
