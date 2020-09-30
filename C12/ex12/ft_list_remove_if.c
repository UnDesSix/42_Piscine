/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:25:47 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/28 19:16:48 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
													void (*free_fct)(void *))
{
	t_list *elem;
	t_list *temp;

	while (*begin_list && !((*cmp)((*begin_list)->data, data_ref)))
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		(*free_fct)(temp->data);
		free(temp);
	}
	elem = *begin_list;
	while (elem && elem->next)
	{
		if (!((*cmp)(elem->next->data, data_ref)))
		{
			temp = elem->next;
			elem->next = temp->next;
			(*free_fct)(temp->data);
			free(temp);
		}
		else
			elem = elem->next;
	}
}
