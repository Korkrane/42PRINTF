/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:24:19 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/13 15:41:43 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void	n_space_to_print(t_struct *data, int i_len, int sign)
{
	if (data->prec > i_len)
		print_space(data->width - data->prec - sign, data);
	else
		print_space(data->width - i_len - sign, data);
}

void	n_zero_to_print(t_struct *data, int i_len, int sign)
{
	if (data->prec > i_len)
		print_zero(data->width - data->prec - sign, data);
	else
		print_zero(data->width - i_len - sign, data);
}
