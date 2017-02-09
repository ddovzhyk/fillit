/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 14:26:05 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/01/22 14:26:07 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **g_field;

void	print_field(void)
{
	int i;
	int j;

	i = -1;
	while (g_field[++i][0] != '\0')
	{
		j = -1;
		while (g_field[i][++j] != '\n')
			write(1, &g_field[i][j], 1);
		write(1, &g_field[i][j], 1);
	}
}

int		set_reset_fig(t_fig tetr, int *i, char c, int n)
{
	int v;
	int u;
	int k;

	k = -1;
	while (++k < 3)
	{
		v = i[0] - tetr.x[k];
		u = i[1] - tetr.y[k];
		if ((v < n) && (u < n) &&
			(g_field[v][u] == ((c == '.') ? tetr.ch : '.')))
			g_field[v][u] = c;
		else if ((c == tetr.ch) && set_reset_fig(tetr, i, '.', n))
			return (0);
	}
	g_field[i[0]][i[1]] = c;
	return (1);
}

int		try_fig(t_fig *tetr, int n)
{
	int i[2];

	if (!tetr->ch)
		return (1);
	i[0] = -1;
	while (g_field[++i[0]][0] != '\0')
	{
		i[1] = -1;
		while (g_field[i[0]][++i[1]] != '\n')
			if (g_field[i[0]][i[1]] == '.')
				if (set_reset_fig(*tetr, i, tetr->ch, n))
				{
					if (try_fig(tetr + 1, n))
						return (1);
					set_reset_fig(*tetr, i, '.', n);
				}
	}
	return (0);
}

void	fill_field(t_fig *tetr, int n)
{
	g_field = new_field(n);
	while (!try_fig(tetr, n))
	{
		del_field(g_field, n);
		g_field = new_field(++n);
	}
	print_field();
}
