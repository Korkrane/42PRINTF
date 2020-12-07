/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:36:24 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 14:44:58 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	select_conversion(char c, va_list args, t_struct *my_struct)
{
	int count;

	count = 0;
	if (c == 'c')
		count += c_convert(args, my_struct, count);
	else if (c == 's')
		count += s_convert(args, my_struct, count);
	else if (c == 'p')
		count += p_convert(args, my_struct, count);
	else if (c == 'd')
		count += d_convert(args, my_struct, count);
	/*
	else if (c == 'i')
		count += i_convert(args, my_struct);
	else if (c == 'u')
		count += u_convert(args, my_struct);
	*/
	else if (c == 'x')
		count += x_convert(args, my_struct, count);
	else if (c == 'X')
		count += X_convert(args, my_struct, count);
	else if (c == '%')
		count += percent_convert(my_struct, count);
	return (count);
}
