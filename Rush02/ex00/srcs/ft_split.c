/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:09:20 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/27 22:33:52 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			fill_size(t_key_number *tab, int j)
{
	tab[j].size = ft_strlen(tab[j].key);
	if (tab[j].size >= 4 && (tab[j].size % 3) == 1)
		tab[j].size_max = tab[j].size + 2;
	else
		tab[j].size_max = tab[j].size;
}

int				ft_is_sep(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strdup_spe1(char *src, char *charset)
{
	int		i;
	char	*dst;

	i = 0;
	while (!ft_is_sep(charset, src[i]) && src[i])
		i++;
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (!ft_is_sep(charset, src[i]) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void			ft_while(int *i, char *str, char charset)
{
	while (str[*i] == charset)
		(*i)++;
}

t_key_number	*ft_split(char *str, int nbr_of_lines)
{
	int				i;
	int				j;
	t_key_number	*final_tab;

	if (!(final_tab = malloc(sizeof(t_key_number) * nbr_of_lines)))
		return (0);
	i = 0;
	j = 0;
	while (j < nbr_of_lines)
	{
		ft_while(&i, str, '\n');
		if (!(final_tab[j].key = ft_strdup_spe1(str + i, " :")))
			return (0);
		while (str[i] != ':')
			i++;
		i++;
		ft_while(&i, str, ' ');
		if (!(final_tab[j].data = ft_str_clear_spaces(str + i)))
			return (0);
		fill_size(final_tab, j++);
		while (str[i] != '\n')
			i++;
		ft_while(&i, str, '\n');
	}
	return (final_tab);
}
