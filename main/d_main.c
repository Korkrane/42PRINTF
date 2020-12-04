/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:41:58 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/04 22:29:18 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int main(void)
{
	// 0		marche
	// 0-9 		marche
	// *		marche
	// -		marche
	// .		marche
	// -0		compil. error
	// .0		compil. error

	ft_printf("bonjour %d, ca va %-d ?\n", 42, 42);
	printf("bonjour %d, ca va %-d ?\n", 42, 42);
	
	ft_printf("bonjour %0d, ca va %.4d ?\n", 42, 42);
	printf("bonjour %0d, ca va %.4d ?\n", 42, 42);
	
	ft_printf("bonjour %05d, ca va %-*.*d ?\n", -42, 6, 4,  42);
	printf("bonjour %05d, ca va %-*.*d ?\n", -42, 6, 4,  42);
	
	//ft_printf("bonjour %-10d, ca va %5.1d ?\n", 42, 42);
	//printf("bonjour %-10d, ca va %5.1d ?\n", 42, 42);
	
	//ft_printf("bonjour %1d, ca va %-.6d ?\n", 42, 42);
	//printf("bonjour %1d, ca va %-.6d ?\n", 42, 42);

	//ft_printf("bonjour %*.3d, ca va %012d ?\n", 2, 42, 42);
	//printf("bonjour %*.3d, ca va %012d ?\n", 2, 42, 42);

	//ft_printf("bonjour %*d, ca va %-.*d ?\n", 4, 42, 1, 42);
	//printf("bonjour %*d, ca va %-.*d ?\n", 4, 42, 1, 42);
	return (0);
}
