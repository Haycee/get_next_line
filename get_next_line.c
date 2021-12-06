/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:21:32 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/05 11:17:08 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = 0;
	line = get_line(fd, line, buff);
	if (line && ft_strlen(line))
		return (line);
	free(line);
	return (NULL);
}

char	*get_line(int fd, char *line, char *buff)
{
	int		read_ret;
	char	*buff_rest;

	read_ret = 1;
	while (read_ret > 0)
	{
		line = ft_strjoin(line, buff);
		if (!line)
			return (NULL);
		if (ft_check_nl(buff) != -1)
		{
			buff_rest = &buff[ft_check_nl(buff) + 1];
			while (*buff_rest)
				*buff++ = *buff_rest++;
			*buff = '\0';
			return (line);
		}
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
			free(line);
		if (read_ret == -1)
			return (NULL);
		buff[read_ret] = '\0';
	}
	return (line);
}
