/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:41:58 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 14:18:10 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int main(void)
{
	// 0		compil error
	// 0-9 		marche
	// *		marche
	// -		marche
	// .		compil error

	char *str1 = "Baudoin";
	char *str2 = "bien";
	
	//OK
//	ft_printf("bonjour %-20p, ca va %18p ?\n", (void *)str1, (void *)str2);
//	printf("bonjour %-20p, ca va %18p ?\n", (void *)str1, (void *)str2);
//	
//	ft_printf("bonjour %*p, ca va %-24p ?\n", 30, (void *)str1, (void *)str2);
//	printf("bonjour %*p, ca va %-24p ?\n", 30, (void *)str1, (void *)str2);
//	
//	ft_printf("bonjour %*p, ca va %19p ?\n", 33, (void *)str1, (void *)str2);
//	printf("bonjour %*p, ca va %19p ?\n", 33, (void *)str1, (void *)str2);
//	
//	ft_printf("bonjour %p, ca va %26p ?\n", (void *)str1, (void *)str2);
//	printf("bonjour %p, ca va %26p ?\n", (void *)str1, (void *)str2);
//	
//	ft_printf("bonjour %p\n", (void *)str2);
//	printf("bonjour %p\n", (void *)str2);
//
//	ft_printf("bonjour %22p, ca va %-26p ?\n", (void *)str1, (void *)str2);
//	printf("bonjour %22p, ca va %-26p ?\n", (void *)str1, (void *)str2);
//
//	ft_printf("bonjour %-*p, ca va %19p ?\n", 40, (void *)str1, (void *)str2);
//	printf("bonjour %-*p, ca va %19p ?\n", 40, (void *)str1, (void *)str2);
	return (0);
}
