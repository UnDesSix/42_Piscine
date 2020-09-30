/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:06:54 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/30 14:45:41 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int count;
	int temp;

	count = 0;
	if (!root)
		return (0);
	if (root->left)
	{
		temp = btree_level_count(root->left);
		if (temp > count)
			count = temp;
	}
	if (root->right)
	{
		temp = btree_level_count(root->right);
		if (temp > count)
			count = temp;
	}
	return (count + 1);
}
