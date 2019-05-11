/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:58:29 by spoole            #+#    #+#             */
/*   Updated: 2019/03/08 15:27:01 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place(t_board *board, int pp, int y, int x)
{
	int		i;
	t_cord	**temp;
	char	print;

	i = 0;
	print = 'A' + pp;
	temp = board->pieces[pp];
	while (i < 4)
	{
		board->grid[y + temp[i]->y][x + temp[i]->x] = print;
		i++;
	}
}

int		place_piece(t_board *board, int pi, int iter)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < board->len)
	{
		while (x < board->len)
		{
			if (board->grid[y][x] == '.' && piece_fit(board, pi, y, x))
			{
				if (iter == 0)
				{
					place(board, pi, y, x);
					return (1);
				}
				else
					iter--;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	size_up_board(t_board *board, int *pp, int *cy)
{
	clean_grid(board);
	zero_iter(board, 0);
	board->len = board->len + 1;
	board->grid = make_board(board->len);
	*pp = 0;
	*cy = 0;
}

void	start_solve(t_board *board)
{
	int pieces_placed;
	int **iter;
	int cycles;

	iter = board->iter;
	pieces_placed = 0;
	cycles = 0;
	while (pieces_placed < board->num_pieces)
	{
		if (cycles < 250)
		{
			if (place_piece(board, pieces_placed, (*iter[pieces_placed])++))
			{
				print_board(board);
				pieces_placed++;
			}
			else if (pieces_placed > 0)
			{
				pieces_placed--;
				clean_last_pc(board, pieces_placed);
				zero_iter(board, pieces_placed + 1);
			}
			cycles++;
		}
		else
			size_up_board(board, &pieces_placed, &cycles);
	}
}

void	solve(t_board *board)
{
	int i;

	i = 0;
	start_solve(board);
	print_board(board);
}
