/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cord_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:52:18 by spoole            #+#    #+#             */
/*   Updated: 2019/02/18 19:03:41 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_cord	**init_cord(void)
{
	t_cord	**temp;
	int		i;

	temp = (t_cord**)malloc(sizeof(t_cord*) * 4);
	i = 0;
	while (temp != NULL && i < 4)
	{
		if ((temp[i] = (t_cord*)malloc(sizeof(t_cord))) != NULL)
		{
			temp[i]->x = 0;
			temp[i]->y = 0;
			i++;
		}
		else
			return (NULL);
	}
	return (temp == NULL ? NULL : temp);
}

void	det_cords(char q, int *y, int *x)
{
	if (q == '\n')
	{
		*x -= 4;
		*y += 1;
	}
	else if (*x > 3)
	{
		*x = 0;
		*y += 1;
	}
	else
		*x += 1;
}

t_cord	**get_coords(char *in, int i, int y, int x)
{
	t_cord	**result;
	int		pce;

	pce = 0;
	if ((result = init_cord()) == NULL)
		return (NULL);
	while (in[i] != '#')
		i++;
	while (pce < 4)
	{
		if (in[i] == '#')
		{
			result[pce]->y = y;
			result[pce++]->x = x;
		}
		if (pce > 0)
			det_cords(in[i], &y, &x);
		i++;
	}
	return (result);
}

t_cord	**create_piece(char *data_in)
{
	t_cord **temp;

	if (!validate_pieces(data_in))
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	temp = get_coords(data_in, 0, 0, 0);
	free(data_in);
	return (temp == NULL ? NULL : temp);
}

t_cord	***split_pieces(char *s1, t_board *board)
{
	int		i;
	int		total_num;
	t_cord	***list;

	i = 0;
	total_num = count_pieces(s1);
	list = (t_cord***)malloc(sizeof(t_cord**) * total_num);
	while (i < total_num)
	{
		list[i] = create_piece(ft_strsub(s1, (i * 21), 20));
		if (list[i] != NULL && board->num_pieces <= 26)
		{
			board->num_pieces++;
			i++;
		}
		else
			return (NULL);
	}
	return (list);
}
