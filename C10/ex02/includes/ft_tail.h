/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:25:22 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:25:26 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# define N 4096
# define N_STDIN 28000
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <string.h>
# include <libgen.h>

void	ft_error_msg(char *prog_name, char *file_name);
int		ft_strlen(char *str);
void	ft_putstr_error(char *str);
void	ft_put_title(char *str);

int		ft_open_read(int file_size, int tail, char *file_name);
void	ft_tail_files(int tail, int argc, char **argv);
void	read_stdin(int tail);
int		ft_tail(int argc, char **argv);

int		ft_file_size(char *str);
int		ft_atoi_spe(char *str);
int		flag_is_ok(char **argv);

#endif
