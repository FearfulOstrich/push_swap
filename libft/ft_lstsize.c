/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:20:24 by aalleon           #+#    #+#             */
/*   Updated: 2021/12/03 10:33:01 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cpt;

	if (!lst)
		return (0);
	cpt = 1;
	while (lst->next)
	{
		cpt++;
		lst = lst->next;
	}
	return (cpt);
}
