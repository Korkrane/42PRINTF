/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:36 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/09 13:44:40 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	check_flags(char *format, t_struct *data)
{
	int i;

	i = 1;
	while (ft_strchr("-0", format[i]))
	{
		if (format[i] == '-')
			data->minus_align = 1;
		if (format[i] == '0')
			data->zero = 1;
		i++;
	}
	return (i);
}

static int	check_width(char *format, t_struct *data, va_list args)
{
	int i;
	int pos;

	pos = 0;
	i = 0;
	while (format[pos] == '0' || format[pos] == '%' || format[pos] == '-')
		pos++;
	if (format[pos] == '*')
	{
		data->width = va_arg(args, int);
		return (i + 1);
	}
	if (ft_strchr("0123456789", format[pos]))
		data->width = atoi(&format[pos]);
	while (ft_strchr("0123456789", format[pos]))
	{
		i++;
		pos++;
	}
	return (i);
}

static int	check_prec(char *format, t_struct *data, va_list args)
{
	int i;
	int pos;

	i = 0;
	pos = 0;
	while (ft_isdigit(format[pos]) || format[pos] == '%' || format[pos] == '-')
		pos++;
	if (format[pos] == '.')
	{
		i = 1;
		if (format[pos + 1] == '*')
		{
			data->prec = va_arg(args, int);
			return (i + 1);
		}
		if (ft_strchr("uidpXxs0123456789", format[pos + 1]))
			data->prec = atoi(&format[pos + 1]);
		while (ft_strchr("0123456789", format[pos + 1]))
		{
			i++;
			pos++;
		}
	}
	return (i);
}

int			check_options(t_struct *data, va_list args, char const *format)
{
	int i;

	i = 0;
	i += check_flags((char *)format, data);
	i += check_width((char *)format, data, args);
	i += check_prec((char *)format, data, args);
	return (i);
}
