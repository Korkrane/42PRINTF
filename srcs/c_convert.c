/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:24:08 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 16:38:32 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int print_zero(int size)
{
	int count;

	count = 0;
	while (size > 0)
	{
		ft_putchar('0');
		size--;
		count++;
	}
	return (count);
}

static int print_space(int size)
{
	int count;

	count = 0;
	while (size > 0)
	{
		ft_putchar(' ');
		size--;
		count++;
	}
	return (count);
}

int		c_convert(va_list args, t_struct *my_struct, int count)
{
	int		len;
	char	c;

	c = (char)va_arg(args, int);
	len = my_struct->width - 1;
	if (my_struct->minus_align == 1 && my_struct->width > 0)
	{
		ft_putchar(c);
		count += print_space(len); 
	}
	else if (my_struct->minus_align == 0 && my_struct->width > 0)
	{
		if (my_struct->zero_padding > 0)
			count += print_zero(len);
		else if(my_struct->zero_padding == 0)
			count += print_space(len);
		ft_putchar(c);
	}	
	else
		ft_putchar(c);
	my_struct->width = 0;
	my_struct->minus_align = 0;
	return (1 +  count);
}
