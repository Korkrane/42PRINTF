/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:21:40 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/09 16:47:51 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_struct(t_struct *data)
{
	data->width_len = 0;
	data->prec_len = 0;
	data->pos = 1;
	data->count_char = 0;
	data->zero = 0;
	data->minus_align = 0;
	data->width = 0;
	data->prec = -1;
}

int		str_parsing(const char *format, t_struct *data, va_list args)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			data->count_char += 1;
		}
		else
		{
			i += check_options(data, args, &format[i]);
			if (!ft_strchr("cspdiuxX%", format[i]))
				return (data->count_char);
			data->count_char += select_conversion(format[i], args, data);
		}
		i++;
	}
	return (data->count_char);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_struct	*data;
	int			count;

	count = 0;
	if (!(data = malloc(sizeof(t_struct))))
		return (0);
	if ((format[0] == '%' && format[1] == '\0') || format[0] == '\0')
		return (0);
	set_struct(data);
	va_start(args, format);
	count = str_parsing(format, data, args);
	va_end(args);
	free(data);
	return (count);
}
