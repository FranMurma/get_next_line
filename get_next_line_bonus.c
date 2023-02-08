/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:57:36 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/12 18:02:51 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_xtraspace(char *fed)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (fed[i] && fed[i] != '\n')
		i++;
	if (!fed[i])
	{
		free(fed);
		return (NULL);
	}
	if (fed[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(fed) - i + 1));
	if (!rest)
		return (NULL);
	while (fed[i])
		rest[j++] = fed [i++];
	rest[j] = '\0';
	free(fed);
	return (rest);
}

char	*ft_read(int fd, char *fed)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!ft_strchr(fed, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(temp);
			free(fed);
			return (NULL);
		}
		temp[bytes] = '\0';
		fed = ft_strjoin(fed, temp);
	}
	free(temp);
	return (fed);
}

char	*get_next_line(int fd)
{
	int			cont;
	char		*line;
	static char	*fed[1024];

	cont = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!fed[fd])
		fed[fd] = ft_strdup("");
	fed[fd] = ft_read(fd, fed[fd]);
	if (!fed[fd])
	{
		free(fed[fd]);
		return (NULL);
	}
	while (fed[fd][cont] != '\n' && fed[fd][cont])
		cont++;
	line = ft_substr(fed[fd], 0, cont + 1);
	fed[fd] = ft_xtraspace(fed[fd]);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
