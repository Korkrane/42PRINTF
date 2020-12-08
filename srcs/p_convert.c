/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:26:41 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/08 16:31:17 by bahaas           ###   ########.fr       */
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

static void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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

int p_prec_0(t_struct *my_struct, int address, int count)
{
	if(my_struct->precision == 0 && address == 0)
		ft_putstr("0x");
	return (count + 2);
}

int minus_0(t_struct *my_struct, long address, int address_length, int count)
{
	count += print_space(my_struct->width - 2 - address_length);
	ft_putstr("0x");
	count += print_zero(my_struct->precision - address_length);
	ft_putnbr_base(address);
	return (count);
}

int minus_1(t_struct *my_struct, long address, int address_length, int count)
{
	ft_putstr("0x");
	count += print_zero(my_struct->precision - address_length);
	ft_putnbr_base(address);
	count += print_space(my_struct->width - 2 - address_length);
	return (count);
}

int	p_convert(va_list args, t_struct *my_struct, int count)
{
	long	address;
	int		address_len;

	address = va_arg(args, long);
	address_len = address_length(address);
	if(my_struct->precision == 0 && address == 0)
		return(p_prec_0(my_struct, address, count));
	if(my_struct->minus_align == 0)
		count += minus_0(my_struct, address, address_len, count);
	else if(my_struct->minus_align == 1)
		count += minus_1(my_struct, address, address_len, count);
	clean_struct(my_struct);
	return (count + 2 + address_len);
}
