/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:42:16 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/13 15:41:20 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define HEX_MIN "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"
# define BASE_10 10
# define BASE_16 16

typedef	struct	s_struct
{
	int			width_len;
	int			prec_len;
	int			pos;
	int			count_char;
	int			zero;
	int			minus_align;
	int			width;
	int			prec;
}				t_struct;

void			ft_putchar(char c);
void			clean_struct(t_struct *data);
void			print_space(int size, t_struct *data);
void			print_zero(int size, t_struct *data);
void			n_space_to_print(t_struct *data, int i_len, int sign);
void			n_zero_to_print(t_struct *data, int i_len, int sign);

int				ft_printf(const char *format, ...);
void			set_struct(t_struct *data);
int				check_options(t_struct *data, va_list args, const char *format);
int				select_conversion(char c, va_list args, t_struct *data);

int				c_convert(va_list args, t_struct *data, int count);
int				s_convert(va_list args, t_struct *data, int count);
int				p_convert(va_list args, t_struct *data, int count);
int				d_convert(va_list args, t_struct *data, int count);
int				u_convert(va_list args, t_struct *data, int count);
int				x_convert(va_list args, t_struct *data, int count);
int				xbig_convert(va_list args, t_struct *data, int count);
int				percent_convert(t_struct *data, int count);

#endif
