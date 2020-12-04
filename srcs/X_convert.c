/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:27:33 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/04 17:49:58 by bahaas           ###   ########.fr       */
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

static int	u_length(unsigned int u)
{
	int len;

	len = 0;
	while(u > 0)
	{
		u /= 16;
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

int	X_convert(va_list args, t_struct *my_struct, int count)
{
	unsigned int	u;
	int				u_len;

	u = va_arg(args, unsigned int);
	u_len = u_length(u);
	if(my_struct->minus_align == 0)
	{
		if(my_struct->zero_padding)
			count += print_zero(my_struct->width - u_len);
		else if(my_struct->precision > u_len && my_struct->width > u_len)
			count += print_space(my_struct->width - u_len - (my_struct->precision - u_len)) + print_zero(my_struct->precision - u_len);
		else if(my_struct->precision > u_len)
			count += print_zero(my_struct->precision - u_len);
		else if(my_struct->width > 0)
			count += print_space(my_struct->width - u_len);
		ft_putnbr_base(u);
	}
	if(my_struct->minus_align == 1)
	{
		ft_putnbr_base(u);
		count += print_space(my_struct->width - u_len);
	}
	clean_struct(my_struct);
	return (count + u_len);
}
