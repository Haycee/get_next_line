/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:33:32 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/03 18:09:54 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*get_line(int fd, char *line, char *buff);
char	*ft_strjoin(char *s1, char *s2, int i, int j);
int		ft_strlen(char *str);
int		ft_check_nl(char *buff);
void	ft_save_rest(char *buff, char *buff_rest);

#endif
