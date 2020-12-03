/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:21:40 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/02 20:02:49 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	set_struct(t_struct *my_struct, char const *format)
{
	my_struct->format = (char *)format;
	my_struct->count_char = 0; 
	my_struct->zero_padding = 0;
	my_struct->minus_align = 0;
	my_struct->width = 0;
	my_struct->precision = 0;
}

/*
int		check_options(t_struct *my_struct, const char *format, va_list args)
{
	return (0);
}

int	select_conversion(char c, va_list args, t_struct *my_struct)
{
	int count;

	count = 0;

	if (c == 'c')
		count += c_convert(args, my_struct);
	else if (c == 's')
		count += s_convert(args, my_struct);
	else if (c == 'p')
		count += p_convert(args, my_struct);
	else if (c == 'd')
		count += d_convert(args, my_struct);
	else if (c == 'i')
		count += i_convert(args, my_struct);
	else if (c == 'u')
		count += u_convert(args, my_struct);
	else if (c == 'x')
		count += x_convert(args, my_struct);
	else if (c == 'X')
		count += X_convert(args, my_struct);
	else if (c == '%')
		count += percent_convert(args, my_struct);
	return (count);
}
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

int		str_parsing(const char *format, t_struct *my_struct, va_list args)
{
	int i;
	//char *to_conv;
	
	i = 0;
	while(format[i])
	{
		if(format[i] != '%')
		{
			ft_putchar(format[i]);
			my_struct->count_char += 1;
		}
		else
		{
			while(ft_strchr("cspdiuxX%-0123465789.*", format[i + 1]))
			{
				i++;
				//to_conv = ft_substr --> IDEE A CHIER (requiert strdup + substr + calloc) et + de chance de leaks...
				//check_options(format, &format[i], args, my_struct);
				if(ft_strchr("cspdiuxX%", format[i]))
				{
					//i += select_conversion(format[i], args, my_struct);
					break ;
				}
				else
					i++;
			}
		}
		//if(format[i])
		//	i++;
	}
	return (my_struct->count_char);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	t_struct *my_struct;
	int count;
	
	count = 0;
	if(!(my_struct = malloc(sizeof(t_struct))))
		return (0);
	if((format[0] == '%' && format[1] == '\0') || format[0] == '\0')
		return (0);
	set_struct(my_struct, format); 
	va_start(args, format); 
	count = str_parsing(format, my_struct, args);
	va_end(args);
	free(my_struct);
	return	(count);
}
