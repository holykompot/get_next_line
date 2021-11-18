/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spmerced <spmerced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:07:14 by spmerced          #+#    #+#             */
/*   Updated: 2021/11/08 18:23:29 by spmerced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*cut_save(char	*saved_line)
{
	char	*cutted_line;
	int		count_len;

	count_len = 0;
	while (saved_line[count_len]!= '\n' && saved_line[count_len]!= '\0')
		count_len++;
	cutted_line = malloc(sizeof(char) * (count_len + 1));
	ft_memcpy(cutted_line, saved_line, count_len);
	cutted_line[count_len] = '\0';
	return (cutted_line);
}

char	*add_buf(char *old_buf, char *new_buf)
{
	char	*new_save;
	int		old_len;
	int		new_len;

	if (!old_buf)
		return (new_buf);
	old_len = ft_strlen(old_buf);
	new_len = ft_strlen(new_buf);
	//printf("old_len is: %d\n", old_len);
	//printf("new_len is: %d\n", new_len);
	new_save = malloc(sizeof(char) * (old_len + new_len + 1));
	ft_memcpy(new_save, old_buf, old_len);
	ft_memcpy(&new_save[old_len], new_buf, new_len);
	new_save[old_len + new_len] = '\0';
	return (new_save);
}

char    *line_remainder(char *saved_line)
{

}

char	*get_next_line(int fd)
{
	static char	*saved_line;
	char		*buf;
	char		*output;
	int			read_symbs;
	
	read_symbs = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!has_new_line(saved_line) && read_symbs)
	{
		read_symbs = read(fd, buf, BUFFER_SIZE);
		if (read_symbs == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_symbs] = '\0';
		saved_line = add_buf(saved_line, buf);
	    free(buf);
    }
    output = cut_save(saved_line);
	saved_line = line_remainder(saved_line);

	return (saved_line);
}
