/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:47:09 by victorcvaz        #+#    #+#             */
/*   Updated: 2023/09/04 03:31:50 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == (char) c)
			return ((char *) s + i);
	if (s[i] == (char) c)
		return ((char *) s + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	str_len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *) malloc(sizeof(char) * (str_len + NULL_BYTE));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1 && *s1 != '\0')
		ptr[i++] = *s1++;
	while (s2 && *s2 != '\0')
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc(sizeof(char) * ft_strlen(s) + NULL_BYTE);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	ptr = (char *) malloc(sizeof(char) * (len + NULL_BYTE));
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < len)
		ptr[i] = s[start + i];
	ptr[i] = '\0';
	return (ptr);
}
