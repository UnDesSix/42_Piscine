/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:03:46 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/23 13:43:26 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_FILE_H
# define FT_DISPLAY_FILE_H
# include <fcntl.h>
# include <unistd.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_open_n_read(char *name_file);
int		ft_display_file(int argc, char **argv);

#endif
