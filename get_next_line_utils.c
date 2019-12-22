/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:20:01 by blacking          #+#    #+#             */
/*   Updated: 2019/11/25 18:59:38 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nelem, size_t type)
{
	unsigned char *data;
	size_t i;

	i = 0;
	if(!(data = (unsigned char *)malloc(nelem * type)))
		return (NULL);
	while(i < nelem * type)
	{
		data[i] = '\0';
		i++;
	}
	return (data);
}

char *ft_substr(char *prev_cumul, unsigned int start, size_t len)
{
	char *line_or_cumul;
	unsigned int i = 0;
	unsigned int j = 0;
	if(!(line_or_cumul = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while(prev_cumul[i])
	{
		if(start == 0 && prev_cumul[i] == '\n')
			return(line_or_cumul);
		if(i >= start)
		{
			line_or_cumul[j] = prev_cumul[i];
			j++;
		}
		i++;
	}
	if(start != 0)
		free(prev_cumul);
	return (line_or_cumul);
}

size_t	ft_strlen(const char *s)
{
	size_t count = 0;

	if(s == 0)
		return (0);
	while(s[count])
		count++;
	return (count);
}
