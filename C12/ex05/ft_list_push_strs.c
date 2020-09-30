/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:58:44 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/29 11:44:54 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_elem, void *data)
{
	t_list	*elem;

	if (!(*begin_elem))
		*begin_elem = ft_create_elem(data);
	else
	{
		elem = ft_create_elem(data);
		elem->next = *begin_elem;
		*begin_elem = elem;
	}
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = 0;
	if (!strs)
		return (0);
	while (i < size)
	{
		ft_list_push_front(&elem, strs[i]);
		i++;
	}
	return (elem);
}
