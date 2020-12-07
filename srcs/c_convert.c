/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:24:08 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 15:15:27 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		c_convert(va_list args, t_struct *my_struct, int count)
{
	int		n;
	char	c;

	c = (char)va_arg(args, int);
	n = my_struct->width - 1;
	count = n;
	if (my_struct->minus_align == 1)
		ft_putchar(c);
	if (my_struct->width > 0)
	{
		while (n-- > 0)
			ft_putchar(' ');
		if (my_struct->minus_align == 0)
			ft_putchar(c);
	}
	if (my_struct->width == 0 && my_struct->minus_align == 0)
	{
		ft_putchar(c);
		return (1);
	}
	my_struct->width = 0;
	my_struct->minus_align = 0;
	return (1 + count);
}
