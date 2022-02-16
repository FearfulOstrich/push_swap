/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:05:27 by aalleon           #+#    #+#             */
/*   Updated: 2021/12/01 18:44:52 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cpt;
	size_t	l_dst;

	l_dst = ft_strlen(dst);
	if (dstsize < (l_dst + 1))
		return (dstsize + ft_strlen(src));
	cpt = 0;
	while (src[cpt] && cpt < (dstsize - l_dst - 1))
	{
		dst[l_dst + cpt] = src[cpt];
		cpt++;
	}
	dst[l_dst + cpt] = '\0';
	return (l_dst + ft_strlen(src));
}
