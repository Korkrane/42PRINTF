/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:36 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 21:44:46 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int check_flags(char *format, t_struct *my_struct)
{
	int i;

	i = 1;
	while (ft_strchr("-0", format[i]))
	{
		if (format[i] == '-')
			my_struct->minus_align = 1;
		if (format[i] == '0')
			my_struct->zero_padding = 1;
		i++;
	}
	//printf("\ncheck flags... leftover : %s", &format[i]); //REPERE
	return (i);
}

static int check_width(char *format, t_struct *my_struct, va_list args)
{
	int i;
	int pos;

	pos = 0;
	i = 0;
	//printf("check width... string start of checking width : %s", &format[pos]); //REPERE
	while (format[pos] == '0' || format[pos] == '%' || format[pos] == '-')
		pos++;
	if (format[pos] == '*')
	{
		my_struct->width = va_arg(args, int);
		return (i + 1); //pour passer *
	}
	if (ft_strchr("0123456789", format[pos]))
		my_struct->width = atoi(&format[pos]);
	while (ft_strchr("0123456789", format[pos]))
	{
		i++;
		pos++;
	}
	//printf("check width... string end of checking width : %s", &format[pos]); //REPERE
	return (i);
}

static int check_precision(char *format, t_struct *my_struct, va_list args)
{
	int i;
	int pos;

	i = 0;
	pos = 0;
	//printf("check precision... string start of checking precision : %s", &format[pos]); //REPERE
	while ((format[pos] >= '0' && format[pos] <= '9') || format[pos] == '%' || format[pos] == '-')
		pos++;
	//printf("check precision... string start of checking precision : %s", &format[pos]); //REPERE
	if (format[pos] == '.')
	{
		i = 1; //pr le .
		if (format[pos + 1] == '*')
		{
			my_struct->precision = va_arg(args, int);
			return (i + 1);
		}
		//printf("a :%s\n", &format[pos + 1]);
		if (ft_strchr("pXxs0123456789", format[pos + 1]))
			my_struct->precision = atoi(&format[pos + 1]);
		while (ft_strchr("0123456789", format[pos + 1]))
		{
			i++;
			pos++;
		}
	}
	//printf("check precision... leftover : %s", &format[i]); //REPERE
	return (i);
}

int			check_options(t_struct *my_struct, va_list args, char const *format)
{
	int i;
	
	i = 0;
	i += check_flags((char *)format, my_struct);			// -0
	i += check_width((char *)format, my_struct, args);		// *0-9
	i += check_precision((char *)format, my_struct, args);	// .*0-9
	//printf("Check struct data :\nzero_padding: %d\nwidth: %d\nprecision: %d\nminus_align: %d\n\n", my_struct->zero_padding, my_struct->width, my_struct->precision, my_struct->minus_align);
	return (i);
}

