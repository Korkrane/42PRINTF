/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:26:41 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/10 17:28:39 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	i_length(int i)
{
	int len;

	len = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= BASE_10;
		len++;
	}
	return (len);
}

static void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / BASE_10);
		ft_putnbr(nbr % BASE_10);
	}
	else
		ft_putchar(nbr + '0');
}

static void	minus_0(t_struct *data, long i, int i_len, int sign)
{
	if (sign == 1)
		data->count_char += 1;
	if (data->zero == 0 || data->prec > -1)
	{
		if (data->prec > i_len)
			print_space(data->width - data->prec - sign, data);
		else
			print_space(data->width - i_len - sign, data);
	}
	if (sign == 1)
		ft_putchar('-');
	if (data->zero == 1 && data->prec <= -1)
	{
		if (data->prec > i_len)
			print_zero(data->width - data->prec - sign, data);
		else
			print_zero(data->width - i_len - sign, data);
	}
	if (data->prec > i_len && data->prec != -1)
		print_zero(data->prec - i_len, data);
	ft_putnbr(i);
	if (data->width < 0)
	{
		data->width *= -1;
		if(data->prec <= 0)
		print_space(data->width - i_len - sign, data);
		else if(data->prec < data->width)
		print_space(data->width - i_len - sign, data);
	}
}

static void	minus_1(t_struct *data, int i, int i_len, int sign)
{
	if (sign == 1)
	{
		data->count_char += 1;
		ft_putchar('-');
	}
	if (data->zero == 1 && data->prec == -1)
	{
		if (data->prec > i_len)
			print_zero(data->width - data->prec - sign, data);
		else
			print_zero(data->width - i_len - sign, data);
	}
	if (data->prec > i_len && data->prec != -1)
		print_zero(data->prec - i_len, data);
	ft_putnbr(i);
	if(data->width < 0)
		data->width *= -1;
	if (data->prec > i_len)
		print_space(data->width - data->prec - sign, data);
	else
		print_space(data->width - i_len - sign, data);
}

int			d_convert(va_list args, t_struct *data, int count)
{
	long	i;
	int		i_len;
	int		sign;

	i = (int)va_arg(args, int);
	i_len = i_length(i);
	sign = 0;
	if (i < 0)
		sign = 1;
	if (i == 0 && data->prec == 0)
	{
		if(data->width < 0)
			data->width *= -1;
		print_space(data->width, data);
		return (count);
	}
	if (data->minus_align == 0)
		minus_0(data, i, i_len, sign);
	else if (data->minus_align == 1)
		minus_1(data, i, i_len, sign);
	clean_struct(data);
	return (count + i_len);
}

/*
static int			print_moins(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

static int			len_nbr(int nbr)
{
	int				i;
	unsigned int	nb;

	i = 1;
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int			ft_print_long(long nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	if (nbr >= 10)
	{
		ft_print_long(nbr / 10);
		ft_print_long(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
	return (len_nbr(nbr));
}

int					d_convert(va_list args, t_struct *data, int count)
{
	int				i;
	int				nbr;
	int				len;
	int				len_nosign;

	i = 0;
	len = 0;
	nbr = (int)va_arg(args, int);
	len_nosign = len_nbr(nbr);
	if (nbr < 0)
		data->width--;
	len = (data->prec > len_nosign) ? data->prec : len_nosign;
	if (data->prec == 0 && nbr == 0)
	{
		print_space(data->width, data);
		return (count);
	}
	if (data->minus_align == 0 && (data->zero == 0 || data->prec != -1))
		print_space(data->width - len, data);
	i += print_moins(nbr);
	if (data->zero == 1 && data->prec == -1)
		print_zero(data->width - len, data);
	if (data->prec > len_nosign && data->prec != -1)
		print_zero(data->prec - len_nosign, data);
	i += ft_print_long(nbr);
	if (data->minus_align == 1)
		print_space(data->width - len, data);
	return (i);
}
*/
/*
static int			print_moins(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

int		ft_putnchar(const char c, const int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

static int			len_nbr(int nbr)
{
	int				i;
	unsigned int	nb;

	i = 1;
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int			ft_print_long(long nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	if (nbr >= 10)
	{
		ft_print_long(nbr / 10);
		ft_print_long(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
	return (len_nbr(nbr));
}
#include <stdio.h>
int					d_convert(va_list param, t_struct *flags)
{
	int				i;
	int				nbr;
	int				len;
	int				len_nosign;

	i = 0;
	len = 0;
	nbr = (int)va_arg(param, int);
	len_nosign = len_nbr(nbr);
	if(flags->width < 0)
	{
		flags->width *= -1;
		flags->zero = 0;
		flags->minus_align = 1;
	}
	if (nbr == 0 && flags->prec == 0)
	{
		if(flags->width < 0)
			flags->width *= -1;
		print_space(flags->width, flags);
		return(0);
	}
	if (nbr < 0)
		flags->width--;
	len = (flags->prec > len_nosign) ? flags->prec : len_nosign;
	if (flags->prec == 0 && nbr == 0)
		return (i += ft_putnchar(' ', flags->width));
	if (flags->minus_align == 0 && (flags->zero == 0 || flags->prec > -1))
		i += ft_putnchar(' ', flags->width - len);
	i += print_moins(nbr);
	if (flags->zero == 1 && flags->prec <= -1)
		i += ft_putnchar('0', flags->width - len);
	if (flags->prec > len_nosign && flags->prec > -1)
		i += ft_putnchar('0', flags->prec - len_nosign);
	i += ft_print_long(nbr);
	if (flags->minus_align == 1)
		i += ft_putnchar(' ', flags->width - len);
	return (i);
}*/
