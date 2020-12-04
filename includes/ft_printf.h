/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:42:16 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/04 01:21:48 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

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

int		ft_printf(const char *, ...);
void	ft_putchar(char c);
void	set_struct(t_struct *my_struct, char const *format);
char	*ft_strchr(const char *s, int c);
int		check_options(t_struct *my_struct, va_list args, const char *format);
int		select_conversion(char c, va_list args, t_struct *my_struct);
int		c_convert(va_list args, t_struct *my_struct, int count);
int		s_convert(va_list args, t_struct *my_struct, int count);
int		p_convert(va_list args, t_struct *my_struct);
int		d_convert(va_list args, t_struct *my_struct);
int		i_convert(va_list args, t_struct *my_struct);
int		u_convert(va_list args, t_struct *my_struct);
int		x_convert(va_list args, t_struct *my_struct);
int		X_convert(va_list args, t_struct *my_struct);
int		percent_convert(va_list args, t_struct *my_struct);

#	endif
