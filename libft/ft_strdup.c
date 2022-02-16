/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:26:15 by aalleon           #+#    #+#             */
/*   Updated: 2021/12/09 13:17:43 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		str_len;

	str_len = ft_strlen(s1);
	dest = malloc(sizeof(*dest) * (str_len + 1));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, str_len + 1);
	return (dest);
}
