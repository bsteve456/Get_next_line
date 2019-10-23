/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_lines_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:49:04 by blacking          #+#    #+#             */
/*   Updated: 2019/10/22 22:43:18 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size) {
	size_t i;
	unsigned char *data;

	i = 0;
	if(!(data = (unsigned char *)malloc(size * count)))
		return (NULL);
	while(i < size * count)
	{
		data[i] = '\0';
		i++;
	}
	return (data);
}

size_t	ft_strlen(const char *s) {
	size_t count;

	count = 0;
	if(s == 0)
		return 0;
	while(s[count])
		count++;
	return count;
}

int		ft_length_btn_nl(int newline_read, char *cumul)
{
	int count;
	int next_newline_found;

	count = 0;
	next_newline_found = 0;
	while(*cumul && next_newline_found != -1)
	{
		if(next_newline_found == newline_read && *cumul != '\n')
			count++;
		else if(next_newline_found > newline_read)
			next_newline_found = -1;
		else if(*cumul == '\n')
			next_newline_found++;
		cumul++;
	}
	return (count + 1);

}
