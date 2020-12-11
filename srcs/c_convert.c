/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:24:08 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/11 19:33:07 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		c_convert(va_list args, t_struct *data, int count)
{
	char	c;

	c = (char)va_arg(args, int);
	if (data->minus_align == 1)
	{
		ft_putchar(c);
		print_space(data->width - 1, data);
	}
	else if (data->minus_align == 0)
	{
		if (data->width < 0)
			data->width *= -1;
		if (data->zero == 1)
			print_zero(data->width - 1, data);
		else
			print_space(data->width - 1, data);
		ft_putchar(c);
	}
	clean_struct(data);
	return (1 + count);
}
