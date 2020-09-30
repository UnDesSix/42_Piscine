/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:11:55 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/28 16:12:36 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 28000
# define TRUE 1
# define FALSE 0

typedef	struct		s_position
{
	unsigned int	y;
	unsigned int	x;
}					t_position;

typedef struct		s_square
{
	t_position		base;
	unsigned int	size;
}					t_square;

typedef struct		s_file
{
	char			*buff;
	unsigned int	file_size;
	unsigned int	nb_lines;
	unsigned int	map_size;
	unsigned int	line_size;
	unsigned short	size_descript;
	unsigned short	err;
	char			c_empt;
	char			c_obst;
	char			c_sqr;
	t_square		bsq;
}					t_file;

unsigned long		get_file_size(char *filename);
short				find_params(t_file *file, unsigned short index);
void				set_description_line(t_file *file);
t_file				init_file(char *filename);
void				check_map(t_file *file);

unsigned int		gety(t_file *file, unsigned int index);
unsigned int		getx(t_file *file, unsigned int index);
t_position			get_position(t_file *file, unsigned int index);
t_position			set_position(unsigned int x, unsigned int y);
unsigned int		get_index(t_file *file, t_position position);

unsigned int		go_next_index(t_file *file, unsigned int *index
					, t_position current, unsigned int size);
unsigned int		get_sqr_size(t_file *file, unsigned int *index);
void				find_bsq(t_file *file);
void				display_bsq(t_file *file);
void				fill_map(t_file *file);

char				*refill(char *str, unsigned int index);
short				set_input_file(t_file *file);
void				get_input(t_file *file);
void				read_input(t_file *file);

unsigned int		ft_strlen(char *str);
t_square			init_square(unsigned int x, unsigned int y
					, unsigned int size);
void				fill_buff(t_file *file, int fd);

#endif
