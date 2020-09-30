/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:47:42 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/18 10:48:10 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_sep(char *charset, char c)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup_spe(char *src, char *charset)
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

char	**ft_tab_n_str_size(char *str, char *charset, int *count_bis)
{
	int		i;
	int		size;
	int		count;
	char	**tab;

	i = 0;
	size = -1;
	count = 0;
	while (str[size])
		size++;
	while (ft_is_sep(charset, str[i]))
		i++;
	while (str[i])
	{
		if (ft_is_sep(charset, str[i]) && !ft_is_sep(charset, str[i + 1]))
			count++;
		i++;
		if (!str[i] && !ft_is_sep(charset, str[i - 1]))
			count++;
	}
	if (!(tab = malloc(sizeof(char *) * count + 1)))
		return (0);
	*count_bis = count;
	tab[count] = 0;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		count;
	char	**tab;

	if (!(tab = ft_tab_n_str_size(str, charset, &count)))
		return (0);
	i = 0;
	j = 0;
	while (j < count)
	{
		while (ft_is_sep(charset, str[i]))
			i++;
		if (str[i])
		{
			tab[j++] = ft_strdup_spe(str + i, charset);
			while (!ft_is_sep(charset, str[i]) && str[i])
				i++;
		}
	}
	return (tab);
}
