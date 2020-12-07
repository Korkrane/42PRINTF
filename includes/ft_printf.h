/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:42:16 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 15:25:16 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"

// TO DELETE LATER
#include <stdio.h>
#include <string.h>

typedef	struct	s_struct
{
	char 		*format;		// initial string given without conversion
	int			count_char;		// value to return (nb of char wrote)
	int			zero_padding;	// 0 option
	int			minus_align;	// - option
	int			width;			// 0-9 + *  option 
	int			precision;		// . option
}				t_struct;

void	ft_putchar(char c);
int		ft_printf(const char *, ...);
void	set_struct(t_struct *my_struct, char const *format);
int		check_options(t_struct *my_struct, va_list args, const char *format);
int		select_conversion(char c, va_list args, t_struct *my_struct);
int		c_convert(va_list args, t_struct *my_struct, int count);
int		s_convert(va_list args, t_struct *my_struct, int count);
int		p_convert(va_list args, t_struct *my_struct, int count);
int		d_convert(va_list args, t_struct *my_struct, int count);
int		i_convert(va_list args, t_struct *my_struct);
int		u_convert(va_list args, t_struct *my_struct);
int		x_convert(va_list args, t_struct *my_struct, int count);
int		X_convert(va_list args, t_struct *my_struct, int count);
int		percent_convert(t_struct *my_struct, int count);

#	endif
