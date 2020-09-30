/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:50:07 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:22:25 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H
# define BUFF_SIZE 40960
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <libgen.h>
# include <sys/errno.h>

typedef	struct	s_save
{
	char	*counter;
	char	*last_dspl;
	char	*line_rest;
	int		size_rest;
	int		flag_c;
}				t_save;

typedef	struct	s_file
{
	int		fd;
	int		error_nbr;
	char	*name;
}				t_file;

int				is_flag_c(char *str);
int				hexdump_stdin(t_save *saver);
int				ft_hexdump(int argc, char **argv);
int				hexdump_files(char *prog_name, t_file *file, t_save *saver);

t_save			*init_saver(void);
int				free_file(t_file *file);
int				free_saver(t_save *saver);
t_file			*open_files(int argc, char **argv, t_save *saver);

char			*init_counter(t_save *saver);
int				incr_counter(char *counter, t_save *saver);
void			last_counter(char *counter, int size_rest, t_save *saver);

int				merge_rest_n_buffer(t_file file, t_save *saver);
int				read_file(char *prog_name, t_file file, t_save *saver);
int				read_buffer(int read_bytes, char *buffer, t_save *saver);

char			*malloc_final_line(t_save *saver);
int				make_final_line(int line_len, char *line, t_save *saver);
void			display_final_line(int line_len, char *line,
										char *final_line, t_save *saver);

int				copy_counter(char *final_line, char *counter, t_save *saver);
void			copy_text_flag_c(char *final_line, char *line, int line_len);
void			copy_hexa_without_c(char *final_line, char *line, int line_len);
void			copy_hexa(char	*final_line, char *line,
											int line_len, t_save *saver);

void			copy_hexa_with_c(char *final_line, char *line, int line_len);
int				copy_hexa_with_c_one(char *final_line, char *line,
															int i, int n);
int				copy_hexa_with_c_two(char *final_line, int i, int n);

int				ft_strlen(char *str);
char			*ft_strncpy(char *src, int n);
void			ft_putstr(char *str, int output);
char			*ft_strcpy(char *dst, char *src);
int				special_cmp(char *s1, char *s2, int size);

int				err_mess_dir(char *prog_name, char *file_name);
void			bad_file_descriptor(char *prog_name, char *last_file_name);
int				error_message(int error_nbr, char *prog_name, char *file_name);

#endif
