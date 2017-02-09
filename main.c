/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgogol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:36:38 by tgogol            #+#    #+#             */
/*   Updated: 2016/12/28 16:54:05 by tgogol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	buf[546];
	size_t	i[4];
	t_fig	*tetr;
	size_t	n;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (-1);
	}
	if (!open_count(argv[1], i, buf))
		return (-2);
	buf[i[0]] = '\0';
	if (!check_map(i, buf) || !(tetr = check_fill_fig(i, buf)))
	{
		write(1, "error\n", 6);
		return (-3);
	}
	n = 2;
	while (i[2] > n * n)
		n++;
	fill_field(tetr, n);
	free(tetr);
	return (0);
}
