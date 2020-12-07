/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:26:41 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 21:58:18 by bahaas           ###   ########.fr       */
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

static long	address_length(long address_len)
{
	long len;

	len = 0;
	if(address_len == 0)
		return(2);
	while(address_len > 0)
	{
		address_len /= 16;
		len++;
	}
	return(len);
}

static void	ft_putnbr_base(long nbr)
{
	char		*base;

	base = "0123456789abcdef";
	if(nbr >= 16)
	{
		ft_putnbr_base(nbr / 16);
		ft_putnbr_base(nbr % 16);
	}
	else
		ft_putchar(base[nbr % 16]);
}

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

int	p_convert(va_list args, t_struct *my_struct, int count)
{
	long	address;
	int					address_len;

	address = va_arg(args, long);
	address_len = address_length(address);
	if(my_struct->precision == 0 && address == 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		return(count + 2);
	}
	if(my_struct->minus_align == 0)
	{
		if(my_struct->width - 2 > 0)
			count += print_space(my_struct->width - 1 - address_len);
		ft_putchar('0');
		ft_putchar('x');
		ft_putnbr_base(address);
	}
	else if(my_struct->minus_align == 1)
	{
		ft_putchar('0');
		ft_putchar('x');
		ft_putnbr_base(address);
		count += print_space(my_struct->width - 1 - address_len);
	}
	clean_struct(my_struct);
	return (count + 2 + address_len);
}
