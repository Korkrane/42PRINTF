/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:26:41 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/09 13:51:22 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	i_length(long i)
{
	int len;

	len = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr(long nbr)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			write(1, "2147483648", 10);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

static void	minus_0(t_struct *data, long i, int i_len)
{
	if (data->zero == 0 || data->prec != -1)
	{
		if (data->prec > i_len)
			print_space(data->width - data->prec, data);
		else
			print_space(data->width - i_len, data);
	}
	if (data->zero == 1 && data->prec == -1)
	{
		if (data->prec > i_len)
			print_zero(data->width - data->prec, data);
		else
			print_zero(data->width - i_len, data);
	}
	if (data->prec > i_len && data->prec != -1)
		print_zero(data->prec - i_len, data);
	ft_putnbr(i);
}

static void	minus_1(t_struct *data, long i, int i_len)
{
	if (data->zero == 1 && data->prec == -1)
	{
		if (data->prec > i_len)
			print_zero(data->width - data->prec, data);
		else
			print_zero(data->width - i_len, data);
	}
	if (data->prec > i_len && data->prec != -1)
		print_zero(data->prec - i_len, data);
	ft_putnbr(i);
	if (data->zero == 0 || data->prec != -1)
	{
		if (data->prec > i_len)
			print_space(data->width - data->prec, data);
		else
			print_space(data->width - i_len, data);
	}
}

int			u_convert(va_list args, t_struct *data, int count)
{
	long	i;
	int		i_len;

	i = va_arg(args, unsigned int);
	i_len = i_length(i);
	if (i == 0 && data->prec == 0)
	{
		print_space(data->width, data);
		return (count);
	}
	if (data->minus_align == 0)
		minus_0(data, i, i_len);
	else if (data->minus_align == 1)
		minus_1(data, i, i_len);
	clean_struct(data);
	return (count + i_len);
}
