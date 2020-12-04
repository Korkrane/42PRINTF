/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:41:58 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/04 14:15:14 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int main(void)
{
	// flag 0 impossible
	// 0-9 marche
	// * marche
	// - marche
	// . marche (semnble avoir aucun effet)

	//OK
/*
	ft_printf("bonjour %-*s, ca va %12s ?\n", 5, "toi", "comment");
	printf("bonjour %-*s, ca va %12s ?\n", 5, "toi", "comment");
*/
/*
	//OK
	ft_printf("%s", "bonjour");
	printf("%s", "bonjour");
*/
/*
	//ok
	char *s;
	
	printf("bonjour %.6s, ça va ?\n", s); //+1 car unicode ç
	ft_printf("bonjour %.6s, ça va ?\n", s); //+1 car unicode ç
	//printf("bonjour %.6s, ça va ?\n", s); //+1 car unicode ç
*/	
/*	
	//OK
	ft_printf("bonjour %-40c, ca va  %-*c ?\n", 'x', 'a', 5);
	printf("bonjour %-40c, ca va  %-*c ?\n", 'x', 'a', 5);
*/
/*
	//ok
	printf("bonjour %.6s, ça va ?\n", "Baudoin"); //+1 car unicode ç
	ft_printf("bonjour %.6s, ça va ?\n", "Baudoin"); //+1 car unicode ç
*/
	return (0);
}
