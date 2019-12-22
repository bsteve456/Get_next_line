/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:15:14 by blacking          #+#    #+#             */
/*   Updated: 2019/11/25 18:49:19 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 4096
# include <stdlib.h>
# include <unistd.h>
void	*ft_calloc(size_t nelem, size_t type);
size_t	ft_strlen(const char *s);
char *ft_substr(char *prev_cumul, unsigned int start, size_t len);
#endif
