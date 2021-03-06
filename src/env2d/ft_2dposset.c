/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dposset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 11:49:16 by ncoden            #+#    #+#             */
/*   Updated: 2015/09/02 09:09:55 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft-graphics/2denv.h"

void		ft_2dposset(t_2dpos *pos, int x, int y)
{
	if (pos)
	{
		pos->x = x;
		pos->y = y;
	}
}
