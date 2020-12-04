/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:27:05 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/04 14:15:52 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	clean_struct(t_struct *my_struct)
{
	my_struct->zero_padding = 0;
	my_struct->minus_align = 0;
	my_struct->width = 0;
	my_struct->precision = -1;
}

static int	print_str(char *str, int str_len)
{
	int i;

	i = 0;
	if(str_len == 0)
		return (0);
	if(str_len > 0)
	{
		while(i < str_len)
		{
			ft_putchar(str[i]);
			i++;
		}
		return (i);
	}
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return(i);
}

static int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

static int print_space(int size)
{
	int count;

	count = 0;
	while(size > 0)
	{
		ft_putchar(' ');
		size--;
		count++;
	}
	return (count);
}

int	s_convert(va_list args, t_struct *my_struct, int count)
{
	int		width;
	int		str_len;
	char	*str;

	str = va_arg(args, char *);
	width = my_struct->width;
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (my_struct->precision && my_struct->precision < str_len)
		str_len = my_struct->precision;
	if (my_struct->minus_align != 0)
		count += print_str(str, str_len) + print_space(width - str_len);
	else if (my_struct->minus_align == 0 && width > 0)
		count += print_space(width - str_len) + print_str(str, str_len);
	else
		count += print_str(str, str_len);
	clean_struct(my_struct);
	return (count);
}
