/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:06:49 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/10 17:59:49 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_new;
	size_t	len_s;
	size_t	cont;

	len_s = 0;
	while (s[len_s])
		len_s++;
	if (len_s < start)
		len = 0;
	else if (len >= (len_s - start))
		len = len_s - start;
	str_new = malloc(sizeof(char) * (len + 1));
	if (!str_new)
		return (NULL);
	cont = 0;
	while (cont < len)
	{
		str_new[cont] = s[start];
		cont++;
		start++;
	}
	str_new[cont] = '\0';
	return (str_new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		cont_s1;
	int		cont_s2;
	char	*s3;

	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	cont_s1 = 0;
	cont_s2 = 0;
	while (s1[cont_s1])
	{
		s3[cont_s1] = s1[cont_s1];
		cont_s1++;
	}
	while (s2[cont_s2])
	{
		s3[cont_s1 + cont_s2] = s2[cont_s2];
		cont_s2++;
	}
	s3[cont_s1 + cont_s2] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
			return ((char *)(s + cont));
		cont++;
	}
	if (s[cont] == (char)c)
		return ((char *)(s + cont));
	return (NULL);
}
