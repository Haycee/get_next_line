/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:33:18 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/05 11:25:02 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1] = {};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = 0;
	line = get_line(fd, line, buff[fd]);
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
