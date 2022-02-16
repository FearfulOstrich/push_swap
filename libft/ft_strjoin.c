/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:22:42 by aalleon           #+#    #+#             */
/*   Updated: 2021/12/04 16:29:03 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(size + 1, sizeof(*str));
	if (!str)
		return (0);
	ft_strlcat(str, s1, size + 1);
	ft_strlcat(str, s2, size + 1);
	return (str);
}
