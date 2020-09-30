/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_latin_square.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 21:37:56 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/20 16:33:19 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscrapper.h"

int		line_is_ok(int *line, int value, int column)
{
	int i;

	i = 0;
	while (i < column)
	{
		if (value == line[i])
			return (0);
		i++;
	}
	return (1);
}

int		check_column(int **square, int *current_line, int row, int n)
{
	int i;
	int j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < n)
		{
			if (current_line[j] == square[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		generate_all_squares(int *pov, int row, int **tab_saver, int **square)
{
	static int	flag_n = 0;
	static int	flag_over = 0;
	static int	n;
	int			i;

	if (!flag_n)
	{
		n = ft_size_of_n(pov);
		flag_n = 1;
	}
	i = -1;
	while (row < n && ++i < ft_iterative_factorial(n) && !flag_over)
	{
		square[row] = tab_saver[i];
		if (check_column(square, square[row], row, n))
		{
			generate_all_squares(pov, row + 1, tab_saver, square);
			if (row == n - 1)
			{
				if ((flag_over = ft_check_square(square, pov, n)))
					print_square(square, n);
			}
		}
	}
	return (flag_over);
}

void	generate_all_lines(int n, int column, int *line_saver, int **tab_saver)
{
	int			i;
	static int	j = 0;

	i = 1;
	while (column < n && i <= n)
	{
		line_saver[column] = i;
		if (line_is_ok(line_saver, i, column))
		{
			generate_all_lines(n, column + 1, line_saver, tab_saver);
			if (column == n - 1)
			{
				tab_saver[j] = ft_intdup(n, line_saver);
				j++;
			}
		}
		i++;
	}
}

int		generate_and_check(int *view)
{
	int	**tab_saver;
	int	**square;
	int	*line_saver;
	int	n;
	int return_val;

	n = ft_size_of_n(view);
	if (!(tab_saver = malloc(sizeof(int *) * ft_iterative_factorial(n))))
		return (0);
	if (!(square = malloc(sizeof(int *) * n)))
		return (0);
	if (!(line_saver = malloc(sizeof(int) * n)))
		return (0);
	generate_all_lines(n, 0, line_saver, tab_saver);
	free(line_saver);
	return_val = generate_all_squares(view, 0, tab_saver, square);
	free_tab(tab_saver, ft_iterative_factorial(n));
	free(square);
	free(tab_saver);
	return (return_val);
}
