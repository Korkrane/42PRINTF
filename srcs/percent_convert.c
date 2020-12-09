/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:26:55 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/09 17:14:02 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*
int	percent_convert(t_struct *data, int count)
{
	
	ft_putchar('%');
	clean_struct(data);
	return (count + 1);
}
*/
int		percent_convert(t_struct *data, int count)
{
	int		len;

	len = data->width - 1;
	if (data->minus_align == 1 && data->width > 0)
	{
		ft_putchar('%');
		print_space(len, data);
	}
	else if (data->minus_align == 0 && data->width > 0)
	{
		if (data->zero > 0)
			print_zero(len, data);
		else if (data->zero == 0)
			print_space(len, data);
		ft_putchar('%');
	}
	else
		ft_putchar('%');
	clean_struct(data);
	return (1 + count);
}
