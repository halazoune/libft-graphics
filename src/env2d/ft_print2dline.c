/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2dline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 17:54:51 by ncoden            #+#    #+#             */
/*   Updated: 2015/08/18 15:55:26 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft-graphics.h"

static inline void		print_pixel(t_img *img, int x, int y, int color)
{
	ft_memcpy(&img->buff[(y * img->size_x) + (x * img->bpp)], &color, img->bpp);
}

static inline void		print_right(t_2denv *e, t_2dline *line)
{
	int			x;

	x = line->from.x - 1;
	if (line->to.y - line->from.y)
	{
		if (line->to.y - line->from.y > 0)
		{
			if (line->to.x - line->from.x >= line->to.y - line->from.y)
				ft_print2dline_octant1(e, line);
			else
				ft_print2dline_octant2(e, line);
		}
		else
		{
			if (line->to.x - line->from.x >= line->from.y - line->to.y)
				ft_print2dline_octant8(e, line);
			else
				ft_print2dline_octant7(e, line);
		}
	}
	else
		while (++x < line->to.x)
			print_pixel(&e->img, x, line->from.y, line->color);
}

static inline void		print_left(t_2denv *e, t_2dline *line)
{
	int			x;

	x = line->from.x + 1;
	if (line->to.y - line->from.y)
	{
		if (line->to.y - line->from.y > 0)
		{
			if (-line->to.x + line->from.x >= line->to.y - line->from.y)
				ft_print2dline_octant4(e, line);
			else
				ft_print2dline_octant3(e, line);
		}
		else
		{
			if (line->to.x - line->from.x <= line->to.y - line->from.y)
				ft_print2dline_octant5(e, line);
			else
				ft_print2dline_octant6(e, line);
		}
	}
	else
		while (--x > line->to.x)
			print_pixel(&e->img, x, line->from.y, line->color);
}

static inline void		print_vertical(t_2denv *e, t_2dline *line)
{
	int			y;

	if (line->to.y - line->from.y > 0)
	{
		y = line->from.y - 1;
		while (++y < line->to.y)
			print_pixel(&e->img, line->from.x, y, line->color);
	}
	else
	{
		y = line->from.y + 1;
		while (--y > line->to.y)
			print_pixel(&e->img, line->from.x, y, line->color);
	}
}

void					ft_print2dline(t_2denv *e, t_2dline *line)
{
	if (line->to.x - line->from.x)
	{
		if (line->to.x - line->from.x > 0)
			print_right(e, line);
		else
			print_left(e, line);
	}
	else
	{
		if (line->to.y - line->from.y)
			print_vertical(e, line);
	}
}
