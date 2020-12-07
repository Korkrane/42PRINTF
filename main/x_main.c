/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:41:58 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 14:19:52 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int main(void)
{
	// flag 0	marche
	// 0-9 		marche
	// *		marche
	// -		marche
	// .		marche
	//0. join	compil. error
	//OK
	ft_printf("bonjour %-5x, ca va %.*x ?\n", ']', 4, '\t');
	printf("bonjour %-5x, ca va %.*x ?\n", ']', 4, '\t');
	
	ft_printf("bonjour %0*x, ca va %12x ?\n", 5, ']', '\t');
	printf("bonjour %0*x, ca va %12x ?\n", 5, ']', '\t');
	
	ft_printf("bonjour %.*x, ca va %12x ?\n", 5, ']', '\t');
	printf("bonjour %.*x, ca va %12x ?\n", 5, ']', '\t');
	
	ft_printf("bonjour %12.*x, ca va %3x ?\n", 4, ']', '\t');
	printf("bonjour %12.*x, ca va %3x ?\n", 4, ']', '\t');
	
	ft_printf("bonjour %.*x, ca va %4x ?\n", 8, ']', '\t');
	printf("bonjour %.*x, ca va %4x ?\n", 8, ']', '\t');
	
	ft_printf("bonjour %-*x, ca va %6x ?\n", 10, ']', '\t');
	printf("bonjour %-*x, ca va %6x ?\n", 10, ']', '\t');
	return (0);
}
