/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 13:25:35 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/09 18:55:56 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert_addr(unsigned long addr, char *final_line)
{
	static char	hexa[] = "0123456789abcdef";
	int			i;

	i = 15;
	while (addr)
	{
		final_line[i] = hexa[addr % 16];
		addr = addr / 16;
		i--;
	}
	while (i >= 0)
		final_line[i--] = '0';
	final_line[16] = ':';
}

void	ft_convert_text(char *addr, char *final_line, int size_line)
{
	static char hexa[] = "0123456789abcdef";
	int			i;
	int			j;

	i = 17;
	j = 0;
	while (j < size_line)
	{
		if (j % 2 == 0)
			final_line[i++] = ' ';
		final_line[i++] = hexa[(unsigned char)addr[j] / 16];
		final_line[i++] = hexa[(unsigned char)addr[j] % 16];
		j++;
	}
	while (j < 16)
	{
		if (j % 2 == 0)
			final_line[i++] = ' ';
		final_line[i++] = ' ';
		final_line[i++] = ' ';
		j++;
	}
}

void	ft_printable_text(char *addr, char *final_line, int size_line)
{
	int	i;
	int j;

	i = 57;
	j = 0;
	final_line[i++] = ' ';
	while (j < size_line)
	{
		if (addr[j] >= 32 && addr[j] <= 126)
			final_line[i] = addr[j];
		else
			final_line[i] = '.';
		j++;
		i++;
	}
	final_line[i] = '\n';
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	char			final_line[75];

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16 && i < size)
		{
			j++;
			i++;
		}
		ft_convert_addr((unsigned long)(addr + i - j), final_line);
		ft_convert_text((char *)(addr + i - j), final_line, (int)j);
		ft_printable_text((char *)(addr + i - j), final_line, (int)j);
		write(1, final_line, (59 + j));
	}
	return (addr + size);
}
