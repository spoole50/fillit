/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_board_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:14:45 by spoole            #+#    #+#             */
/*   Updated: 2019/03/07 13:48:40 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		clean_last_pc(t_board *board, int pi)
{
	int		y;
	int		x;
	char	del;

	y = 0;
	x = 0;
	del = 'A' + pi;
	while (y < board->len)
	{
		while (x < board->len)
		{
			if (board->grid[y][x] == del)
				board->grid[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}

void		clean_grid(t_board *clean)
{
	int	x;

	x = 0;
	while (x < clean->len)
		free(clean->grid[x++]);
	free(clean->grid);
}

void		free_board(t_board *clean)
{
	int i;
	int	x;

	i = 0;
	x = 0;
	while (i < clean->num_pieces)
	{
		while (x < 4)
			free(clean->pieces[i][x++]);
		free(clean->pieces[i]);
		x = 0;
		i++;
	}
	free(clean->pieces);
	i = 0;
	while (i < clean->len)
		free(clean->grid[i++]);
	free(clean->grid);
	i = 0;
	while (i < clean->num_pieces)
		free(clean->iter[i++]);
	free(clean->iter);
	free(clean);
}

char		**make_board(int len)
{
	char	**temp;
	int		i;
	int		x;

	i = 0;
	x = 0;
	temp = (char**)malloc(sizeof(char*) * len);
	while (i < len)
		temp[i++] = (char*)malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		while (x <= len)
		{
			if (x == len)
				temp[i][x] = '\0';
			else
				temp[i][x] = '.';
			x++;
		}
		x = 0;
		i++;
	}
	return (temp);
}

t_board		*initialize_board(char *input)
{
	t_board *temp;

	temp = (t_board*)malloc(sizeof(t_board));
	temp->num_pieces = 0;
	if ((temp->pieces = split_pieces(input, temp)) == NULL ||
	(temp->iter = init_iter(temp->num_pieces)) == NULL)
		return (NULL);
	else
	{
		temp->len = ft_sqrt(temp->num_pieces);
		temp->grid = make_board(temp->len);
		return (temp);
	}
}
