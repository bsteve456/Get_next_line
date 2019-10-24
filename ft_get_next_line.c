/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:41:30 by blacking          #+#    #+#             */
/*   Updated: 2019/10/24 11:40:38 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_line_read(char *cumul)
{
	char *dest;
	int next_newline_found;
	int i;

	next_newline_found = 0;
	if(!(dest = ft_calloc(sizeof(char), ft_length_btn_nl(cumul))))
		return (NULL);
	i = 0;
	while(*cumul && next_newline_found != 1)
	{
		if(*cumul != '\n')
		{
			dest[i] = *cumul;
			i++;
		}
		else
			next_newline_found++;
		cumul++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strmcat(char *line, const char *buf, int read_file)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if(!(dest = ft_calloc(sizeof(char), (ft_strlen(line) + read_file + 1))))
		return (NULL);
	while (line[i])
	{
			dest[i] = line[i];
			i++;
	}
	free(line);
	while(j < read_file)
	{
		dest[i + j] = buf[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}


int get_next_line(int fd, char **line)
{
	static char *cumul = NULL;
	int read_file;
	char *buf;

	read_file = 1;
	if(line && *line)
		free(*line);
	if(!cumul)
		cumul = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if(!(buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1))) ||
	!line || fd == -1)
		return (-1);
	while(read_file > 0 || *cumul)
	{
		read_file = read(fd, buf, BUFFER_SIZE);
		if(read_file != 0)
			cumul = ft_strmcat(cumul, buf, read_file);
		free(buf);
		if (*cumul)
		{
			*line = ft_line_read(cumul);
			cumul = ft_substr(cumul, ft_length_btn_nl(cumul), ft_strlen(cumul));
			return (1);
		}
	}
	free(cumul);
	*line = NULL;
	return (0);
}
