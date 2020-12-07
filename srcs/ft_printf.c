/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:21:40 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 15:27:08 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_struct(t_struct *my_struct, char const *format)
{
	my_struct->format = (char *)format;
	my_struct->count_char = 0; 
	my_struct->zero_padding = 0;
	my_struct->minus_align = 0;
	my_struct->width = 0;
	my_struct->precision = -1; //prec 0 with s return null
}

int		str_parsing(const char *format, t_struct *my_struct, va_list args)
{
	int i;

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
			//Permet de bien déplacer mon index juste après la fin d'un arg et
			//recuperer les options
			i += check_options(my_struct, args, &format[i]);
			//printf("String after checking options : %s\n", &format[i]);
			//Maintenant convertir avec les params l'arg en question
			//printf("Count char after checking options %d\n", my_struct->count_char);
			my_struct->count_char += select_conversion(format[i], args, my_struct);
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
