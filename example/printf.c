/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:00:15 by bahaas            #+#    #+#             */
/*   Updated: 2020/11/26 14:27:34 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int i = 42;
	char *str = "Hello World !";
	char c = 'A';

	printf("42 PRINTF EXAMPLES\n\n");

	printf("printf with d : %d (int signed)\n", i);
	printf("printf with s : %s\n", str);
	printf("printf with c : %c\n", c);
	printf("printf with p : %p\n", str);
	printf("printf with i : %i (int signed)\n", i);
	printf("printf with u : %u (int unsigned)\n", i);
	printf("printf with x : %x (hexa unsigned en min de %c)\n", c, c);
	printf("printf with X : %X (hexa unsigned en maj de %c)\n", c, c);
	//printf("printf with % : %%\n", c);
	return (0);
}
