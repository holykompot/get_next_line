/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spmerced <spmerced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:06:19 by spmerced          #+#    #+#             */
/*   Updated: 2021/11/08 17:38:55 by spmerced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	if (!dst && !src)
		return (dst);
	d = dst;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*p;
	unsigned char	ch;
	size_t			n;

	ch = '\0';
	if (count == 0)
		count = 1;
	if (size == 0)
		size = 1;
	ptr = malloc(size * count);
	if (!ptr)
		return ((void *)0);
	n = count * size;
	p = ptr;
	while (n > 0)
	{
		*p++ = ch;
		n--;
	}
	return (ptr);
}

int		has_new_line(char *buf)
{
	int i;

	i = 0;
	if (!buf)
		return 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return 0;
}