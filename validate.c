/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 23:02:43 by spoole            #+#    #+#             */
/*   Updated: 2019/03/07 13:46:03 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		piece_fit(t_board *board, int pp, int y, int x)
{
	int		i;
	int		iy;
	int		ix;
	t_cord	**temp;

	i = 0;
	iy = 0;
	ix = 0;
	temp = board->pieces[pp];
	while (i < 4)
	{
		iy = y + temp[i]->y;
		ix = x + temp[i]->x;
		if (iy >= board->len || iy < 0 || ix >= board->len || ix < 0)
			return (0);
		else if (board->grid[iy][ix] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

int		hash_close(char *s1, int i)
{
	int n;
	int len;

	n = 0;
	len = ft_strlen(s1);
	if ((i - 1) >= 0 && s1[i - 1] == '#')
		n++;
	if ((i - 5) >= 0 && s1[i - 5] == '#')
		n++;
	if ((i + 1) < len && s1[i + 1] == '#')
		n++;
	if ((i + 5) < len && s1[i + 5] == '#')
		n++;
	return (n);
}

int		validate_pieces(char *s1)
{
	int i;
	int hash;
	int	close;

	i = 0;
	hash = 0;
	close = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '#')
		{
			hash++;
			close += hash_close(s1, i);
			if ((close == 6 || close == 8) && hash == 4)
				return (1);
		}
		i++;
	}
	return (0);
}

int		validate_input(char *s1, int i)
{
	int	len;
	int	line;

	i = -1;
	len = 0;
	line = 0;
	while (s1[++i] != '\0')
	{
		if ((s1[i] != '.' && s1[i] != '#' && s1[i] != '\n')
				|| len > 4 || line > 3)
			return (0);
		if (s1[i] == '.' || s1[i] == '#')
			len++;
		if (s1[i] == '\n' && (s1[i + 1] == '\n' || s1[i + 1] == '\0'))
		{
			len = 0;
			line = 0;
		}
		else if (s1[i] == '\n' && s1[i - 1] != '\n' && len == 4)
		{
			len = 0;
			line++;
		}
	}
	return (1);
}
