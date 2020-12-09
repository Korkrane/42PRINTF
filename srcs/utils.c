/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:24:19 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/09 13:46:50 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	clean_struct(t_struct *data)
{
	data->zero = 0;
	data->minus_align = 0;
	data->width = 0;
	data->prec = -1;
}

void	print_space(int size, t_struct *data)
{
	int count;

	count = 0;
	while (size > 0)
	{
		ft_putchar(' ');
		size--;
		count++;
	}
	data->count_char += count;
}

void	print_zero(int size, t_struct *data)
{
	int count;

	count = 0;
	while (size > 0)
	{
		ft_putchar('0');
		size--;
		count++;
	}
	data->count_char += count;
}
