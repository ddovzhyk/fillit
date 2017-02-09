/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 14:26:49 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/01/22 14:26:50 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	**del_field(char **p, int i)
{
	if (!p)
		return (NULL);
	while (--i >= 0)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;
	return (NULL);
}

char	**new_field(int n)
{
	char	**res;
	int		i;
	int		j;

	if (!(res = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	i = -1;
	while (++i < n)
		if (!(res[i] = (char *)malloc(sizeof(char) * (n + 1))))
			return ((char **)del_field(res, i));
	if (!(res[n] = (char *)malloc(sizeof(char))))
		return ((char **)del_field(res, i));
	i = -1;
	while ((++i < n) && (j = -1))
	{
		while (++j < n)
			res[i][j] = '.';
		res[i][j] = '\n';
	}
	res[n][0] = '\0';
	return (res);
}

int		check_map(size_t *i, char *s)
{
	int k;

	if (!(i[1]) || (i[1] % 12 != 0) || (i[2] % 4 != 0) || ((i[3] + 1) % 5) != 0)
		return (0);
	k = 0;
	while (s[k])
		if ((((s[k] == '.') || (s[k] == '#')) && ((k % 21 + 1) % 5) != 0) ||
			(s[k] == '\n' && (k % 21 + 1) % 5 == 0) ||
			(s[k] == '\n' && (k % 21 + 1) % 21 == 0))
			k++;
		else
			return (0);
	return (1);
}

int		open_count(char *argv, size_t *i, char *buf)
{
	int		fd;
	char	tmp;

	if ((fd = open(argv, O_RDONLY)) == (-1))
	{
		write(1, "error\n", 6);
		return (0);
	}
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	while (read(fd, &tmp, 1) && (i[0] < 546))
	{
		buf[i[0]] = tmp;
		if (buf[i[0]] == '.')
			i[1]++;
		else if (buf[i[0]] == '#')
			i[2]++;
		else if (buf[i[0]] == '\n')
			i[3]++;
		i[0]++;
	}
	close(fd);
	return (1);
}
