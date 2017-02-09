/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 14:26:25 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/01/22 14:26:26 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_fig
{
	int			x[3];
	int			y[3];
	char		ch;
}				t_fig;

t_fig			*check_fill_fig(size_t *i, char *s);
void			fill_field(t_fig *tetr, int n);
void			**del_field(char **p, int i);
char			**new_field(int n);
int				check_map(size_t *i, char *s);
int				open_count(char *argv, size_t *i, char *buf);

#endif
