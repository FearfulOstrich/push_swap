/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:11:16 by aalleon           #+#    #+#             */
/*   Updated: 2021/12/04 16:07:16 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s1, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	size;

	s_len = ft_strlen(s1);
	if (start > s_len)
		return (ft_calloc(sizeof(*str), 1));
	if (s_len - start < len)
		size = s_len - start + 1;
	else
		size = len + 1;
	str = malloc(size);
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + start, size);
	return (str);
}
