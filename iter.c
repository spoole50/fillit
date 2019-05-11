/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 23:05:53 by spoole            #+#    #+#             */
/*   Updated: 2019/02/17 23:06:05 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			**init_iter(int len)
{
	int i;
	int **temp;

	i = 0;
	temp = (int**)malloc(sizeof(int*) * len);
	while (i < len && temp != NULL)
	{
		if ((temp[i] = (int*)malloc(sizeof(int))))
			*temp[i++] = 0;
		else
			return (NULL);
	}
	if (temp)
		return (temp);
	else
		return (NULL);
}

void		zero_iter(t_board *board, int start)
{
	int i;

	i = start;
	while (i < board->num_pieces)
		*(board->iter[i++]) = 0;
}
