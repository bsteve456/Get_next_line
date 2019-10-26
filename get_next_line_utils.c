/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_lines_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:49:04 by blacking          #+#    #+#             */
/*   Updated: 2019/10/26 15:15:23 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*data;

	i = 0;
	if (!(data = (unsigned char *)malloc(size * count)))
		return (NULL);
	while (i < size * count)
	{
		data[i] = '\0';
		i++;
	}
	return (data);
}

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	if (s == 0)
		return (0);
	while (s[count])
		count++;
	return (count);
}

int		ft_length_btn_nl(char *cumul)
{
	int	count;
	int	next_newline_found;

	count = 0;
	next_newline_found = 0;
	while (*cumul && next_newline_found != 1)
	{
		if (*cumul != '\n')
			count++;
		else
			next_newline_found++;
		cumul++;
	}
	return (count + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*dst;

	i = 0;
	j = 0;
	if (!(dst = ft_calloc(len, sizeof(char))))
		return (NULL);
	while (s[i] && j < len)
	{
		if (i >= start && j < len)
		{
			dst[j] = s[i];
			j++;
		}
		i++;
	}
	if(s)
		free((void *)s);
	dst[j] = '\0';
	return (dst);
}
