/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 08:13:00 by eoliveir          #+#    #+#             */
/*   Updated: 2020/09/27 22:36:55 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_key_number
{
	char		*key;
	char		*data;
	int			size;
	int			size_max;
}				t_key_number;

int				ft_strlen(char *str);
int				ft_putstr(char *str);
int				ft_dict_is_valid(char *str);
int				is_printable(char c);
int				is_space(char c);

int				ft_spe_strlen(char *str);
char			*ft_strdup_spe2(char *str, int size);
char			*ft_str_clear_spaces(char *str);

int				ft_is_sep(char *charset, char c);
char			*ft_strdup_spe1(char *src, char *charset);
t_key_number	*ft_split(char *str, int nbr_of_lines);

t_key_number	ft_init_struct(char *key, char *data);
char			*ft_fill_tab(char *file, int size);

int				number_is_valid(char *str);
int				ft_file_size(char *file_name);
int				ft_argc_two(char **argv);
int				ft_argc_three(char **argv);

char			*ft_strndup_n(char *str, int n);
char			*ft_strndup(char *str, int n);
int				ft_strcmp(char *s1, char *s2);

int				ft_display_nb(t_key_number *tab, char *nbr);
int				ft_uni(t_key_number *tab, char *nbr, int comp);
int				ft_dec(t_key_number *tab, char *nbr, int comp);
int				ft_dec_bis(t_key_number *tab, char *nbr, int comp, int i);
int				ft_hun(t_key_number *tab, char *nbr, int comp);

int				ft_displ_first(t_key_number *tab, char *nbr, int *flag, int *i);
int				ft_displ_second(t_key_number *tab, char *nbr,
														int *flag, int *i);
int				ft_displ_third(t_key_number *tab, char *nbr, int *flag, int *i);

int				ft_check_key(char *key);
int				ft_inside(t_key_number *tmp_tab, char *key, int tmp_size);
int				ft_key_valide_fin(char *key, int *nb_zero);
int				ft_check(t_key_number *tab, t_key_number *tmp_tab, int size);
t_key_number	*ft_sort_in_tab(t_key_number *tab, int size);

int				ft_struct_cmp(t_key_number t1, t_key_number t2i);
void			ft_write_number(char *nbr);
int				ft_is_zero(t_key_number *tab, char *nbr);
int				ft_nbr_size(char *str, t_key_number *tab, int size_tab);

int				ft_free_final_tab(t_key_number *final_tab, int size);
int				ft_putstr_final_tab(char *str, t_key_number *final_tab,
																int size);
int				ft_putstr_dict_saver(char *str, char *dict_saver);
#endif
