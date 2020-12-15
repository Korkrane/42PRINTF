/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:27:33 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/13 15:43:25 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hex_length(unsigned int hex)
{
	int len;

	len = 0;
	if (hex == 0)
		return (1);
	while (hex > 0)
	{
		hex /= BASE_16;
		len++;
	}
	return (len);
}

static void	ft_putnbr_base(unsigned int nbr, char *base)
{
	if (nbr >= BASE_16)
	{
		ft_putnbr_base(nbr / BASE_16, base);
		ft_putnbr_base(nbr % BASE_16, base);
	}
	else
		ft_putchar(base[nbr % BASE_16]);
}

static void	minus_0(t_struct *data, int i, int i_len)
{
	if (data->zero == 0 || data->prec > -1)
		n_space_to_print(data, i_len, 0);
	if (data->zero == 1 && data->prec <= -1)
		n_zero_to_print(data, i_len, 0);
	if (data->prec > i_len && data->prec > -1)
		print_zero(data->prec - i_len, data);
	ft_putnbr_base(i, HEX_MIN);
}

static void	minus_1(t_struct *data, int i, int i_len)
{
	if (data->zero == 1 && data->prec <= -1)
		n_zero_to_print(data, i_len, 0);
	if (data->prec > i_len && data->prec > -1)
		print_zero(data->prec - i_len, data);
	ft_putnbr_base(i, HEX_MIN);
	if (data->zero == 0 || data->prec > -1)
		n_space_to_print(data, i_len, 0);
}

int			x_convert(va_list args, t_struct *data, int count)
{
	unsigned int	hex;
	int				hex_len;

	hex = va_arg(args, unsigned int);
	hex_len = hex_length(hex);
	if (hex == 0 && data->prec == 0)
	{
		if (data->width < 0)
			data->width *= -1;
		print_space(data->width, data);
		return (count);
	}
	if (data->minus_align == 0)
		minus_0(data, hex, hex_len);
	else if (data->minus_align == 1)
		minus_1(data, hex, hex_len);
	clean_struct(data);
	return (count + hex_len);
}
