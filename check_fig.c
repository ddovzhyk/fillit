/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 20:55:33 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/01/21 20:55:36 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		chkfig1(int *x, int *y)
{
	if (x[1] == -1 && y[1] == 0)
	{
		if (x[2] == -2 && y[2] == 0)
		{
			if (x[3] == -3 && y[3] == 0)
				return (1);
			else if (x[3] == -2 && y[3] == -1)
				return (12);
		}
		else if (x[2] == -1 && y[2] == -1)
		{
			if (x[3] == -2 && y[3] == -1)
				return (5);
			else if (x[3] == -1 && y[3] == -2)
				return (17);
			else if (x[3] == -2 && y[3] == 0)
				return (9);
		}
		else if (x[2] == -2 && y[2] == 1 && x[3] == -2 && y[3] == 0)
			return (16);
	}
	return (0);
}

int		chkfig2(int *x, int *y)
{
	if (x[1] == 0 && y[1] == -1)
	{
		if (x[2] == 0 && y[2] == -2)
		{
			if (x[3] == 0 && y[3] == -3)
				return (2);
			else if (x[3] == -1 && y[3] == -1)
				return (10);
			else if (x[3] == -1 && y[3] == 0)
				return (13);
			else if (x[3] == -1 && y[3] == -2)
				return (19);
		}
		else if (x[2] == -1 && y[2] == 0)
		{
			if (x[3] == -1 && y[3] == -1)
				return (3);
			else if (x[3] == -2 && y[3] == 0)
				return (18);
		}
		else if (x[2] == -1 && y[2] == 1 && x[3] == -1 && y[3] == 0)
			return (4);
	}
	return (0);
}

int		chkfig3(int *x, int *y)
{
	if (x[1] == -1 && y[1] == 1)
	{
		if (x[2] == -1 && y[2] == 0)
		{
			if (x[3] == -2 && y[3] == 1)
				return (7);
			else if (x[3] == -1 && y[3] == -1)
				return (8);
			else if (x[3] == -2 && y[3] == 0)
				return (11);
		}
	}
	else if (x[1] == -1 && y[1] == 2 && x[2] == -1 &&
			y[2] == 1 && x[3] == -1 && y[3] == 0)
		return (15);
	if (x[1] == 0 && y[1] == -1 && x[2] == -1 && y[2] == -1)
	{
		if (x[3] == -1 && y[3] == -2)
			return (6);
		else if (x[3] == -2 && y[3] == -1)
			return (14);
	}
	return (0);
}

int		fig(int *x, int *y, char *s)
{
	int i;
	int k;
	int j;

	k = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (*s == '#')
			{
				x[k] = (k == 0) ? i : x[0] - i;
				y[k] = (k == 0) ? j : y[0] - j;
				k++;
			}
			s++;
		}
		s++;
	}
	if (!chkfig1(x, y) && !chkfig2(x, y) && !chkfig3(x, y))
		return (0);
	return (1);
}

t_fig	*check_fill_fig(size_t *i, char *s)
{
	int		x[4];
	int		y[4];
	t_fig	*tetr;
	int		k;
	int		h;

	if (!(tetr = (t_fig *)malloc(sizeof(t_fig) * ((i[2] / 4) + 1))))
		return (NULL);
	k = 0;
	while (*s)
	{
		if (!fig(x, y, s))
			return (0);
		h = -1;
		while (++h < 3)
		{
			tetr[k].x[h] = x[h + 1];
			tetr[k].y[h] = y[h + 1];
			tetr[k].ch = k + 'A';
		}
		s += (s[20]) ? 21 : 20;
		k++;
	}
	tetr[k].ch = '\0';
	return (tetr);
}
