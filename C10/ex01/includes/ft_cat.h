/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:29:13 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/23 18:24:41 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H
# define N 4096
# include <fcntl.h>
# include <unistd.h>
# include <libgen.h>
# include <string.h>
# include <sys/errno.h>

void	ft_error_msg(char *prog_name, char *file_name);
int		ft_strlen(char *str);
void	ft_putstr_error(char *str);

int		ft_open_n_read(char *prog_name, char *file_name);
int		read_stdin(void);
int		ft_cat(int argc, char **argv);

#endif
