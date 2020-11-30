/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wip_parsing_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:54:40 by bahaas            #+#    #+#             */
/*   Updated: 2020/11/27 16:48:03 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

	set = "0123456789+-.*";
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			printf("%c", s[i]);
			i++;
		}
		else if (s[i] == '%')
		{
			printf("1");
			while (ft_strchr(set, s[i + 1]))
			{
				printf("0");
				i++;
				if (ft_strchr("cspdiuxX%", s[i + 1]))
				{
					printf("1");
					i++;
					break ;
				}
			}
			i++;
		}
	}
	return (s);
}

char	*ft_printf(char *s)
{
	return (parse(s));
}

int		main(void)
{
	char	*result;
	int		i;

	i = 4;
	result = ft_printf("Print with s : %+.5d and %s");
	//printf("%s\n", result);
	printf("\n%+.5d\n", i);
	return (0);
}
