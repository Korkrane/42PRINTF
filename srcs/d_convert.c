/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:26:41 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/13 15:46:09 by bahaas           ###   ########.fr       */
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
		n_space_to_print(data, i_len, sign);
	if (sign == 1)
		ft_putchar('-');
	if (data->zero == 1 && data->prec <= -1)
		n_zero_to_print(data, i_len, sign);
	if (data->prec > i_len && data->prec != -1)
		print_zero(data->prec - i_len, data);
	ft_putnbr(i);
	if (data->width < 0)
	{
		data->width *= -1;
		if (data->prec <= 0)
			print_space(data->width - i_len - sign, data);
		else if (data->prec < data->width)
			n_space_to_print(data, i_len, sign);
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
	}
	if (data->prec > i_len && data->prec != -1)
		print_zero(data->prec - i_len, data);
	ft_putnbr(i);
	if (data->width < 0)
		data->width *= -1;
	n_space_to_print(data, i_len, sign);
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
		if (data->width < 0)
			data->width *= -1;
		print_space(data->width, data);
		return (count);
	}
	if (data->minus_align == 0)
		minus_0(data, i, i_len, sign);
	else if (data->minus_align == 1)
		minus_1(data, i, i_len, sign);
	return (count + i_len);
}
