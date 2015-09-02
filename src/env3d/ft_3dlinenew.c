/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dlinenew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 23:56:08 by ncoden            #+#    #+#             */
/*   Updated: 2015/09/02 09:50:27 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/basics/memory.h"
#include "libft-graphics/3denv.h"

t_3dline		*ft_3dlinenew(t_3dpos *from, t_3dpos *to, int color)
{
	t_3dline	*new;

	if (!(new = (t_3dline *)malloc(sizeof(t_3dline))))
		return (NULL);
	if (from != NULL)
		new->from = *from;
	else
		ft_bzero(&new->from, sizeof(t_3dpos));
	if (to != NULL)
		new->to = *to;
	else
		ft_bzero(&new->to, sizeof(t_3dpos));
	new->color = color;
	return (new);
}
