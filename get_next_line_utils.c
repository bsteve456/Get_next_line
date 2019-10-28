/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:31:10 by blacking          #+#    #+#             */
/*   Updated: 2019/10/28 00:29:27 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
void	*ft_calloc(size_t count, size_t size)
{

	unsigned char *data;
	if(!(data = (unsigned char *)malloc(size * count)))
		return NULL;
	ft_bzero((void *)data, size*count);
	return data;
}

void	ft_bzero(void *s, size_t n)
{
	size_t i;
	i = 0;
	while (i < n) {
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int i;
	size_t j;
	char *dst;

	i = 0;
	j = 0;
	if(!(dst = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while(s[i] && j < len)
	{
		if(start == 0 && s[i] == '\n')
		{
			dst[j] = '\0';
			return(dst);
		}
		else if(i >= start && j < len)
		{
			dst[j] = s[i];
			j++;
		}
		i++;
	}
	if(start != 0)
		free(s);
//	s = NULL;
	dst[j] = '\0';
	return (dst);
}


size_t ft_strlen(const char *s) {
	size_t count;

	count = 0;
	if(s == 0)
		return 0;
	while(s[count])
		count++;
	return count;
}

