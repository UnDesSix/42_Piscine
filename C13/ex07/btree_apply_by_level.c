/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:32:51 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/30 14:45:55 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
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

void	start(t_btree *root, int current_level, int *levels_list,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (current_level == 1 && root)
	{
		applyf(root->item, levels_list[0], levels_list[1]);
		levels_list[1] = 0;
	}
	else if (current_level > 1 && root)
	{
		start(root->left, current_level - 1, levels_list, applyf);
		start(root->right, current_level - 1, levels_list, applyf);
	}
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	count;
	int	levels_list[2];
	int	i;

	i = 0;
	if (!root)
		return ;
	count = btree_level_count(root);
	while (i < count)
	{
		levels_list[0] = i;
		levels_list[1] = 1;
		start(root, ++i, levels_list, applyf);
	}
}
