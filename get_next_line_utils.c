/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:21:44 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/03 13:23:33 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*str;
	int		buff_size;

	if (ft_check_nl(s2) != -1)
		buff_size = ft_check_nl(s2) + 1;
	else
		buff_size = ft_strlen(s2);
	str = malloc(sizeof(char) * (ft_strlen(s1) + buff_size + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	free(s1);
	while (s2[j])
	{
		str[i++] = s2[j++];
		if (s2[j - 1] == '\n')
		{
			str[i] = '\n';
			break ;
		}
	}
	str[i] = '\0';
	return (str);
}

int	ft_check_nl(char *buff)
{
	int	i;

	if (!buff)
		return (-1);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
