/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:55:28 by aalleon           #+#    #+#             */
/*   Updated: 2021/12/02 09:57:55 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new_s;

	new_s = (char *)s + ft_strlen(s);
	while (new_s >= s)
	{
		if (*new_s == (char) c)
			return (new_s);
		new_s--;
	}
	return (0);
}
