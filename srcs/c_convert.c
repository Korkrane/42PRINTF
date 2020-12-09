/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:24:08 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/09 14:03:00 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		c_convert(va_list args, t_struct *data, int count)
{
	int		len;
	char	c;

	c = (char)va_arg(args, int);
	len = data->width - 1;
	if (data->minus_align == 1 && data->width > 0)
	{
		ft_putchar(c);
		print_space(len, data);
	}
	else if (data->minus_align == 0 && data->width > 0)
	{
		if (data->zero > 0)
			print_zero(len, data);
		else if (data->zero == 0)
			print_space(len, data);
		ft_putchar(c);
	}
	else
		ft_putchar(c);
	clean_struct(data);
	return (1 + count);
}
