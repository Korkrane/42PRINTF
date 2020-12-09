/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:27:05 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/09 16:21:59 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_str(char *str, int str_len)
{
	int i;

	i = 0;
	if (str_len == 0)
		return (0);
	if (str_len > 0)
	{
		while (i < str_len)
		{
			ft_putchar(str[i]);
			i++;
		}
		return (i);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int			s_convert(va_list args, t_struct *data, int count)
{
	int		str_len;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (data->prec >= 0 && data->prec < str_len)
		str_len = data->prec;
	if (data->minus_align == 1)
	{
		count += print_str(str, str_len);
		print_space(data->width - str_len, data);
		if (data->width < 0)
			print_space(-data->width - str_len, data);
	}
	else if (data->minus_align == 0)
	{
		print_space(data->width - str_len, data);
		count += print_str(str, str_len);
		if (data->width < 0)
			print_space(-data->width - str_len, data);
	}
	clean_struct(data);
	return (count);
}
