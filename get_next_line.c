/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:41:30 by blacking          #+#    #+#             */
/*   Updated: 2019/10/25 13:40:45 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_newline(char *cumul)
{
	if (!cumul)
		return (0);
	while (*cumul)
	{
		if (*cumul == '\n')
			return (1);
		cumul++;
	}
	return (0);
}

char	*ft_line_read(char *cumul)
{
	char	*dest;
	int		next_newline_found;
	int		i;

	next_newline_found = 0;
	if (!(dest = ft_calloc(sizeof(char), ft_length_btn_nl(cumul))))
		return (NULL);
	i = 0;
	while (*cumul && next_newline_found != 1)
	{
		if (*cumul != '\n')
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
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!(dest = ft_calloc(sizeof(char), (ft_strlen(line) + read_file + 1))))
		return (NULL);
	while (i < ft_strlen(line))
	{
		dest[i] = line[i];
		i++;
	}
	if (line)
		free(line);
	while (j < read_file)
	{
		dest[i + j] = buf[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_check_gnl(char **buf, char **cumul, int read_file, char **line)
{
	if (read_file != 0)
		*cumul = ft_strmcat(*cumul, *buf, read_file);
	if (ft_newline(*cumul) == 1 || (read_file == 0 && (*cumul && **cumul)))
	{
		free(*buf);
		*line = ft_line_read(*cumul);
		*cumul = ft_substr(*cumul, ft_length_btn_nl(*cumul), ft_strlen(*cumul));
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*cumul = NULL;
	int			read_file;
	char		*buf;

	if (line && *line)
		free(*line);
	read_file = 1;
	if (!(buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1))) ||
	!line || fd == -1)
		return (-1);
	while ((read_file != 0) || (read_file == 0 && (cumul && *cumul)))
	{
		read_file = read(fd, buf, BUFFER_SIZE);
		if (ft_check_gnl(&buf, &cumul, read_file, line) == 1)
			return (1);
	}
	free(buf);
	free(cumul);
	cumul = NULL;
	*line = NULL;
	return (0);
}
