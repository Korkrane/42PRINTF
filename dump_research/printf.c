/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:00:15 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/03 14:56:48 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	int		i;
	char	*str;
	char	c;

	i = 42;
	str = "Hello World !";
	c = 'A';
	printf("42 PRINTF EXAMPLES\n\n");
	printf("printf with d : %d (int signed)\n", i);
	printf("printf with s : %s\n", str);
	printf("printf with c : %c\n", c);
	printf("printf with p : %p\n", str);
	printf("printf with i : %i (int signed)\n", i);
	printf("printf with u : %u (int unsigned)\n", i);
	printf("printf with x : %x (hexa unsigned en min de %c)\n", c, c);
	printf("printf with X : %X (hexa unsigned en maj de %c)\n", c, c);
	printf("printf with percentage : %% (display a percentage)\n");
	printf("printf with - align on left\n");
	printf("printf with 0 fill with 0 till width is reached\n");
	printf("\nWIDTH :\nprintf with * will fill till n width is reached (n in args)\n");
	printf("ex: %0*d (input is : %%0*d with 6 in args)\n", 6, i);
	printf("ex: %*d (input is : %%*d with 6 in args)\n", 6, i);
	printf("\nPRECISION :\nprintf with . will fill till n width is reached (n in args)\n");
	printf("ex: %.4d (input is : %%.4d)\n", i);
	printf("ex: %.d (input is : %%.d)\n", i);
	printf("\nex : %.*d (input is : %%.*d with 4 in args)\n", 4, i);
	
	printf("ex: %14d (input is : %%14d)\n", i);
	printf("ex: %4d (input is : %%4d)\n", i);
	printf("ex: %14.*d (input is : %%14.*d)\n", 5, i);
	printf("ex: %*.*d (input is : %%*.*d)\n", 1, 5, i);
	printf("ex: %0*d (input is : %%0*d)\n", 5, i);

	printf("ex: %05d (input is : %%05d)\n", i);

	return (0);
}
