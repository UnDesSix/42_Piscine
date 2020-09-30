/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscrapper.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 15:15:20 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/20 15:39:59 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SKYSCRAPPER_H
# define FT_SKYSCRAPPER_H
# include <stdlib.h>
# include <unistd.h>

int		ft_put_error(void);
int		ft_is_valid_pov(char c, int n);
int		ft_size_of_n_from_char(char *str);
int		*check_n_convert_views(char *str);
int		ft_sky_scrapper(int argc, char **argv);

int		generate_and_check(int *view);
int		line_is_ok(int *line, int value, int column);
int		check_column(int **square, int *current_line, int row, int n);
void	generate_all_lines(int n, int column, int *line_saver, int **tab_saver);
int		generate_all_squares(int *view, int row, int **tab_saver, int **square);

int		ft_strlen(char *str);
int		ft_size_of_n(int *pov);
int		ft_iterative_factorial(int nb);
void	print_square(int **square, int n);
int		*ft_intdup(int n, int *line_saver);

int		ft_nb_box_colup(int **square, int i, int size);
int		ft_nb_box_coldown(int **square, int i, int size);
int		ft_nb_box_rowleft(int **square, int i, int size);
int		ft_nb_box_rowright(int **square, int i, int size);

void	free_tab(int **tab, int size);
int		ft_check_col(int **square, int *pov, int size);
int		ft_check_row(int **square, int *pov, int size);
int		ft_check_square(int **square, int *pov, int size);

#endif
