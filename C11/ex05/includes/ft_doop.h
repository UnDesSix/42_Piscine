/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:51:14 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/21 15:04:42 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOP_H
# define FT_DOOP_H
# include <unistd.h>

void	ft_putnbr(int nbr);
int		ft_atoi(char *str);
int		is_an_ope(char *str);
void	ft_doop(int a, int b, char *sign);

void	ft_add(int a, int b);
void	ft_sub(int a, int b);
void	ft_mult(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);

#endif
