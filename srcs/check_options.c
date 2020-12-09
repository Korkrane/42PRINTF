/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:36 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/09 16:58:46 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	check_flags(char *format, t_struct *data)
{
	while (ft_strchr("-0", format[data->pos]))
	{
		if (format[data->pos] == '-')
			data->minus_align = 1;
		if (format[data->pos] == '0')
			data->zero = 1;
		data->pos++;
	}
	return (data->pos);
}

static int	check_width(char *format, t_struct *data, va_list args)
{
	int i;

	i = 0;
	data->width_len = 0;
	while (format[i] == '0' || format[i] == '%' || format[i] == '-')
	{
		if (format[i + 1] == '%')
			return (0);
		i++;
	}
	if (format[i] == '*')
	{
		data->width = va_arg(args, int);
		return (1);
	}
	if (ft_strchr("0123456789", format[i]))
		data->width = ft_atoi(&format[i]);
	while (ft_strchr("0123456789", format[i]))
	{
		data->width_len++;
		i++;
	}
	return (data->width_len);
}

static int	check_prec(char *format, t_struct *data, va_list args)
{
	int i;

	i = 0;
	while (ft_isdigit(format[i]) || format[i] == '%' || format[i] == '-'
			|| format[i] == '*')
	{
		if (format[i + 1] == '%')
			return (data->prec_len);
		i++;
	}
	if (format[i] == '.')
	{
		data->prec_len = 1;
		if (format[i + 1] == '*')
		{
			data->prec = va_arg(args, int);
			return (data->prec_len + 1);
		}
		if (ft_strchr("uidpXxs0123456789", format[i + 1]))
			data->prec = ft_atoi(&format[i + 1]);
		while (ft_strchr("0123456789", format[i++ + 1]))
			data->prec_len++;
	}
	return (data->prec_len);
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
