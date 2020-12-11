/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:26:41 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/11 21:15:01 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	address_length(long long address_len)
{
	int len;

	len = 0;
	if (address_len == 0)
		return (1);
	while (address_len > 0)
	{
		address_len /= BASE_16;
		len++;
	}
	return (len);
}

static void	ft_putnbr_base(long long unsigned nbr, char *base)
{
	if (nbr >= BASE_16)
	{
		ft_putnbr_base(nbr / BASE_16, base);
		ft_putnbr_base(nbr % BASE_16, base);
	}
	else
		ft_putchar(base[nbr % BASE_16]);
}

static void	minus_0(t_struct *data, long long unsigned addr, long long addr_len)
{
	if (addr_len == 0)
		addr_len = 16;
	print_space(data->width - 2 - addr_len, data);
	ft_putstr_fd("0x", 1);
	print_zero(data->prec - addr_len, data);
	ft_putnbr_base(addr, HEX_MIN);
}

static void	minus_1(t_struct *data, long long unsigned addr, long long addr_len)
{
	ft_putstr_fd("0x", 1);
	print_zero(data->prec - addr_len, data);
	ft_putnbr_base(addr, HEX_MIN);
	if (addr_len == 0)
		addr_len = 16;
	if (data->minus_align)
		print_space(data->width - 2 - addr_len, data);
}

int			p_convert(va_list args, t_struct *data, int count)
{
	long long unsigned	address;
	long long			address_len;

	address = va_arg(args, long long);
	address_len = address_length(address);
	if (data->prec == 0 && address == 0)
	{
		if (data->minus_align == 1)
			ft_putstr_fd("0x", 1);
		if (data->width > 0)
			print_space(data->width - 2, data);
		if (data->minus_align == 0)
			ft_putstr_fd("0x", 1);
		return (count + 2);
	}
	if (data->minus_align == 0)
		minus_0(data, address, address_len);
	else if (data->minus_align == 1)
		minus_1(data, address, address_len);
	clean_struct(data);
	return (count + 2 + address_len);
}
