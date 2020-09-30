/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:21:49 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/29 13:49:17 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *elem;

	if (!begin_list)
		return (0);
	elem = begin_list;
	while (elem)
	{
		if (!((*cmp)(elem->data, data_ref)))
			return (elem);
		elem = elem->next;
	}
	return (0);
}
