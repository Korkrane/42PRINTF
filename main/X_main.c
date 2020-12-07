/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:41:58 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 14:19:48 by bahaas           ###   ########.fr       */
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
	ft_printf("bonjour %-5X, ca va %.*X ?\n", ']', 4, '\t');
	printf("bonjour %-5X, ca va %.*X ?\n", ']', 4, '\t');
	
	ft_printf("bonjour %0*X, ca va %12X ?\n", 5, ']', '\t');
	printf("bonjour %0*X, ca va %12X ?\n", 5, ']', '\t');
	
	ft_printf("bonjour %.*X, ca va %12X ?\n", 5, ']', '\t');
	printf("bonjour %.*X, ca va %12X ?\n", 5, ']', '\t');
	
	ft_printf("bonjour %12.*X, ca va %3X ?\n", 4, ']', '\t');
	printf("bonjour %12.*X, ca va %3X ?\n", 4, ']', '\t');
	
	ft_printf("bonjour %.*X, ca va %4X ?\n", 8, ']', '\t');
	printf("bonjour %.*X, ca va %4X ?\n", 8, ']', '\t');
	
	ft_printf("bonjour %-*X, ca va %6X ?\n", 10, ']', '\t');
	printf("bonjour %-*X, ca va %6X ?\n", 10, ']', '\t');
	return (0);
}
