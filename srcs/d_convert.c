/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:26:41 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 14:45:43 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	clean_struct(t_struct *my_struct)
{
	my_struct->zero_padding = 0;
	my_struct->minus_align = 0;
	my_struct->width = 0;
	my_struct->precision = -1;
}

static int	i_length(int i)
{
	long len;

	len = 0;
	while(i != 0)
	{
		i /= 10;
		len++;
	}
	return(len);
}

static void	ft_putnbr(int nbr)
{
	if(nbr < 0)
	{
		ft_putchar('-');
		if (nbr == -2147483648)
			write(1, "2147483648", 10);
		nbr *= -1;
	}
	if(nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}
/*
static int print_space(int size)
{
	int count;

	count = 0;
	while(size > 0)
	{
		ft_putchar(' ');
		size--;
		count++;
	}
	return (count);
}
*/
static int print_zero(int size)
{
	int count;

	count = 0;
	while(size > 0)
	{
		ft_putchar('0');
		size--;
		count++;
	}
	return (count);
}

int	d_convert(va_list args, t_struct *my_struct, int count)
{
	int i;
	int i_len;

	i = va_arg(args, int);
	i_len = i_length(i);
	if(my_struct->minus_align == 0)
	{
		if(my_struct->precision > i_len)
			count += print_zero(my_struct->precision - i_len);
		else if(my_struct->width > i_len)
		{
			ft_putchar('-');
			count += print_zero(my_struct->width - i_len - 1);
		}
		ft_putnbr(i);
	}
	else if(my_struct->minus_align == 1)
	{
		ft_putnbr(i);
	}
	clean_struct(my_struct);
	return (count + i_len);
}
