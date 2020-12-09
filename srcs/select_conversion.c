/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:36:24 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/09 13:49:36 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	select_conversion(char c, va_list args, t_struct *data)
{
	int count;

	count = 0;
	if (c == 'c')
		count += c_convert(args, data, count);
	else if (c == 's')
		count += s_convert(args, data, count);
	else if (c == 'p')
		count += p_convert(args, data, count);
	else if (c == 'd')
		count += d_convert(args, data, count);
	else if (c == 'i')
		count += d_convert(args, data, count);
	else if (c == 'u')
		count += u_convert(args, data, count);
	else if (c == 'x')
		count += x_convert(args, data, count);
	else if (c == 'X')
		count += xbig_convert(args, data, count);
	else if (c == '%')
		count += percent_convert(data, count);
	return (count);
}
