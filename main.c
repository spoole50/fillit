/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:47:33 by spoole            #+#    #+#             */
/*   Updated: 2019/02/15 13:42:07 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int num)
{
	int area;
	int root;
	int x;

	area = num * 4;
	root = 1;
	x = 1;
	while (root < area)
	{
		x++;
		root = x * x;
	}
	return (x);
}

void	usage(void)
{
	write(1, "Usage: ./fillit source_file\n", 28);
}

int		main(int argc, char **argv)
{
	t_board *board;

	if (argc == 2)
	{
		board = open_file(argv[1]);
		if (board != NULL)
		{
			solve(board);
			free_board(board);
		}
	}
	else
		usage();
	return (0);
}
