/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:21:40 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/03 16:20:10 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <string.h>

void	set_struct(t_struct *my_struct, char const *format)
{
	my_struct->format = (char *)format;
	my_struct->count_char = 0; 
	my_struct->zero_padding = 0;
	my_struct->minus_align = 0;
	my_struct->width = 0;
	my_struct->precision = 0;
}

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

int check_flags(char *format, t_struct *my_struct)
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
	printf("\ncheck flags... leftover : %s", &format[i]); //REPERE
	return (i);
}

int check_width(char *format, t_struct *my_struct, va_list args)
{
	int i;
	int pos;

	pos = 0;
	i = 0;
	//printf("check width... string start of checking width : %s", &format[pos]); //REPERE
	while(format[pos] == '0' || format[pos] == '%' || format[pos] == '-')
		pos++;
	if (format[pos] == '*')
	{
		my_struct->width = va_arg(args, int);
		return (i + 1);
	}
	if (ft_strchr("0123456789", format[pos]))
		my_struct->width = atoi(&format[pos]);
	while (ft_strchr("0123456789", format[pos]))
	{
		i++;
		pos++;
	}
	printf("check width... string end of checking width : %s", &format[pos]); //REPERE
	return (i);
}

// [WIP] NON FONCTIONNEL -> BESOIN D'UTILISER VAR pos comme pour le check_width
int check_precision(char *format, t_struct *my_struct, va_list args)
{
	int i;

	i = 0;
	if (format[i] == '.')
	{
		if (format[i + 1] == '*')
		{
			my_struct->precision = va_arg(args, int);
			return (i + 1);
		}
		if (ft_strchr("0123456789", format[i]))
			my_struct->precision = atoi(&format[i]);
		while(ft_strchr ("0123456789", format[i]))
			i++;
	}
	printf("check precision... leftover : %s", &format[i]); //REPERE
	return (i);
}

int	check_options(t_struct *my_struct, va_list args, char const *format)
{
	int i;

	i = 0;
	i += check_flags((char *)format, my_struct);			// -0
	i += check_width((char *)format, my_struct, args);		// *0-9
	i += check_precision((char *)format, my_struct, args);	// .*0-9
	printf("Check struct data :\nzero_padding: %d\nwidth: %d\nprecision: %d\nminus_align: %d\n\n", my_struct->zero_padding, my_struct->width, my_struct->precision, my_struct->minus_align);
	return(i);
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

int		str_parsing(const char *format, t_struct *my_struct, va_list args)
{
	int i;

	i = 0;
	while(format[i])
	{
		if(format[i] != '%')
		{
			putchar(format[i]);
			my_struct->count_char += 1;
		}
		else
		{
			//Permet de bien déplacer mon index juste après la fin d'un arg et
			//recuperer les options
			i += check_options(my_struct, args, &format[i]);
			printf("String after checking options : %s\n", &format[i]);
			//Maintenant convertir avec les params l'arg en question
			my_struct->count_char += select_conversion(format[i], args, my_struct);
			//
		}
		i++;
	}
	printf("\nreturned value count_char: %d\n", my_struct->count_char);
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

int main(void)
{
	printf("My string : bonjour %%014d, ça va ?\n\n");
	ft_printf("bonjour %014d, ça va?\n", 42);
	return (0);
}
