/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mempad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:26:36 by spoole            #+#    #+#             */
/*   Updated: 2019/02/26 18:40:20 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(void)
{
	printf("t_cord (Expexted 8=2(int)): %lu\n", sizeof(t_cord));
	int a = sizeof(t_cord***);
	printf("t_board_components:\nt_cord ***pieces = %d\n", a);
	int b = sizeof(char**);
	printf("char **grid = %d\n", b);
	int c = sizeof(int**);
	printf("int **iter = %d\n", c);
	int d = sizeof(int);
	printf("int len = %d\nint num_pieces = %d\n", d, d);
	printf("t_board (Expected %d): %lu\n", a+b+c+d+d,  sizeof(t_board));
	return (0);
}
