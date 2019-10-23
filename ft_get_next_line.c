/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:41:30 by blacking          #+#    #+#             */
/*   Updated: 2019/10/23 14:24:42 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int ft_newline(char *buf)
{
	while(*buf)
	{
		if(*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

int		ft_count_newline(char *cumul)
{
	int count;

	count = 0;
	while(*cumul)
	{
		if(*cumul == '\n')
			count++;
		cumul++;
	}
	return (count);
}

char *ft_line_read(int newline_read, char *cumul)
{
	char *dest;
	int next_newline_found;
	int i;

	next_newline_found = 0;
	if(!(dest = ft_calloc(sizeof(char), ft_length_btn_nl(newline_read, cumul))))
		return (NULL);
	i = 0;
	while(*cumul && next_newline_found != -1)
	{
		if(next_newline_found == newline_read && *cumul != '\n')
		{
			dest[i] = *cumul;
			i++;
		}
		else if(next_newline_found > newline_read)
			next_newline_found = -1;
		else if(*cumul == '\n')
			next_newline_found++;
		cumul++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strmcat(const char *line, const char *buf, int read_file)
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
	free((void *)line);
	line = NULL;
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
	static int newline_read = 0;
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
	while(read_file > 0)
	{
		read_file = read(fd, buf, BUFFER_SIZE);
		if(read_file != 0)
			cumul = ft_strmcat(cumul, buf, read_file);
		if (ft_newline(buf) == 1 ||
		(read_file == 0 && newline_read < ft_count_newline(cumul)))
		{
			printf("line :%d\n", *line);
			if(!(*line = ft_line_read(newline_read, cumul)))
				return (-1);
			newline_read++;
			free(buf);
			buf = NULL;
			return (1);
		}
	}
	free(cumul);
	cumul = NULL;
	free(buf);
	buf = NULL;
	*line = NULL;
	return (0);
}
