/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:09:30 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/28 17:24:47 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_list *elem;

	if (!begin_list)
		return ;
	elem = begin_list;
	while (elem)
	{
		if (!((*cmp)(elem->data, data_ref)))
			(*f)(elem->data);
		elem = elem->next;
	}
}
