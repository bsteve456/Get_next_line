/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:52:44 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/28 21:50:55 by blacking         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2, int read_file)
{
	char	*dst;
	int		j;
	size_t	i;

	i = 0;
	if (!(dst = ft_calloc(sizeof(char), (ft_strlen(s1) + read_file + 1))))
		return (NULL);
	j = 0;
	if (s1)
	{
		while (i < ft_strlen(s1))
		{
			dst[i] = s1[i];
			i++;
		}
		free(s1);
		s1 = NULL;
	}
	while (j < read_file)
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

int		ft_check_gnl(char **buf, char **cumul, int read_file, char **line)
{
	int	x;

	x = 0;
	if ((x = ft_newline(*cumul)) == 1 ||
		(read_file == 0 && (*cumul && **cumul)))
	{
		if (buf && *buf && x == 1)
			free(*buf);
		if (line && *line)
			free(*line);
		*line = ft_substr(*cumul, 0, ft_strlen(*cumul));
		*cumul = ft_substr(*cumul, ft_strlen(*line) + 1, ft_strlen(*cumul));
		if (x == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*cumul = NULL;
	int			read_file;
	char		*buf;

	if (BUFFER_SIZE == 0 || fd == -1 || !line ||
	!(buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return (-1);
	*line = ft_calloc(1, sizeof(char));
	read_file = 1;
	while (read_file > 0 || (read_file == 0 && (cumul && *cumul)))
	{
		if (ft_check_gnl(&buf, &cumul, read_file, line) == 1)
			return (1);
		if ((read_file = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		if (read_file != 0)
			cumul = ft_strjoin(cumul, buf, read_file);
	}
	if (cumul)
		free(cumul);
	free(buf);
	cumul = NULL;
	return (0);
}
