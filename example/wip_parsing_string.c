/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wip_parsing_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:54:40 by bahaas            #+#    #+#             */
/*   Updated: 2020/12/02 19:37:03 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*parse(char *s)
{
	int		i;
	char	*set;

	set = "cspduixX%0123456789-.*";
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			printf("%c", s[i]);
		else if(s[i] == '%')
		{
			if(!ft_strchr(set, s[i + 1]))
				break ;
			printf("1");
			while (ft_strchr(set, s[i + 1]))
			{
				i++;
				if(ft_strchr("0123456789.-*", s[i]))
				{
					printf("0");
					i++;
				}
				if (ft_strchr("cspdiuxX%", s[i]))
				{
					i++;
					printf("1");
					break ;
				}
			}
			continue;
		}
		i++;
	}
	return (s);
}

char	*ft_test(char *s)
{
	parse(s);
	return (s);
}

int		main(void)
{
	char	*result;
	int		i;

	i = 4;
	printf("My parsing :\n");
	result = ft_test("Hello world ! Put some args %-.5d and %s");
	printf("\nlength : %lu\n", strlen(result));
	printf("\nParsed string :\n");
	printf("Hello world ! Put some args %%-.5d and %%s");
	printf("\nlength : %lu\n", strlen("Hello world ! Put some args %%-.5d and %%s")); //diff de 2 a cause des %%
	return (0);
}
