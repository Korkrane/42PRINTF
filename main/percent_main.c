/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:41:58 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/07 14:19:42 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int main(void)
{
	// flag 0 	impossible
	// 0-9		impossible
	// * 		impossible
	// -		impossible
	// .		impossible
/*
	//OK
	ft_printf("bonjour %%, ca va %% ?\n");
	printf("bonjour %%, ca va %% ?\n");

	//OK
	ft_printf("%%");
	printf("%%\n");

	//ok
	ft_printf("bonjour %%, ça va ?\n"); //+1 car unicode ç
	printf("bonjour %%, ça va ?\n"); //+1 car unicode ç
	
	//OK
	ft_printf("bonjour %%, ca va  %% ?\n");
	printf("bonjour %%, ca va  %% ?\n");

	//ok
	ft_printf("bonjour %%\n"); //+1 car unicode ç
	printf("bonjour %%\n"); //+1 car unicode ç
*/
	return (0);
}
