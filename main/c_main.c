/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:41:58 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/03 19:14:59 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int main(void)
{
	// flag 0 impossible
	// flag . impossible
	// any 0-9 marche
	
	//ft_printf("bonjour %-*c, ca va  %3c ?\n", 5, 'x', 'a');
	//printf("bonjour %-*c, ca va  %3c ?\n", 5, 'x', 'a');

	//ft_printf("%c", 'x');
	//printf("%c", 'x');
	
	//ft_printf("bonjour %c, ça va ?\n", 'x'); //+1 car unicode ç
	//printf("bonjour %c, ça va ?\n", 'x'); //+1 car unicode ç
	
	//ft_printf("bonjour %-40c, ca va  %-*c ?\n", 'x', 'a', 5);
	//printf("bonjour %-40c, ca va  %-*c ?\n", 'x', 'a', 5);
	return (0);
}
