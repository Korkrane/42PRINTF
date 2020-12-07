/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xbig_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:27:33 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 21:33:53 by bahaas           ###   ########.fr       */
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

static int	hex_length(unsigned int hex)
{
	int len;

	len = 0;
	if(hex == 0)
		return(1);
	while(hex > 0)
	{
		hex /= 16;
		len++;
	}
	return(len);
}

static void	ft_putnbr_base(unsigned int nbr)
{
	char		*base;

	base = "0123456789ABCDEF";
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

static int hex_prec_0(t_struct *my_struct, int hex, int count)
{
	if(my_struct->precision == 0 && hex == 0)
		count += print_space(my_struct->width);
	return	(count);
}

int	X_convert(va_list args, t_struct *my_struct, int count)
{
	unsigned int	hex;
	int				hex_len;
	int				len;	

	hex = va_arg(args, unsigned int);
	hex_len = hex_length(hex);
	len = (my_struct->precision > hex_len) ? my_struct->precision : hex_len;
	if(my_struct->precision == 0 && hex == 0)
		return(hex_prec_0(my_struct, hex, count));
	if (my_struct->minus_align == 0 && (my_struct->zero_padding == 0 || my_struct->precision != -1))
		count += print_space(my_struct->width - len);
	if (my_struct->zero_padding == 1 && my_struct->precision == -1)
		count += print_zero(my_struct->width - hex_len);
	if (my_struct->precision)
		count += print_zero(my_struct->precision - hex_len);
	ft_putnbr_base(hex);
	if (my_struct->minus_align)
		count += print_space(my_struct->width - len);
	clean_struct(my_struct);
	return (count + hex_len);
}
