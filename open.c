/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:47:14 by spoole            #+#    #+#             */
/*   Updated: 2019/02/18 18:53:29 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_pieces(char *s1)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '\n' && s1[i + 1] == '\n')
			count++;
		else if (s1[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

void		print_board(t_board *board)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < board->len)
	{
		while (y < board->len)
		{
			write(1, &board->grid[x][y], 1);
			y++;
		}
		write(1, "\n", 1);
		y = 0;
		x++;
	}
}

char		*get_input(int fd)
{
	char	*input;
	int		temp_b;
	int		b_read;

	temp_b = 0;
	b_read = 0;
	input = (char*)malloc(sizeof(char) * BUFF_SIZE);
	ft_bzero(input, BUFF_SIZE);
	if (input == NULL || fd < 2)
		return (NULL);
	while ((temp_b = read(fd, (input + b_read), BUFF_SIZE)) != 0)
	{
		b_read += temp_b;
		input = ft_strbuf(input, BUFF_SIZE);
	}
	return (input);
}

t_board		*open_file(char *filename)
{
	int		fd;
	int		valid;
	char	*input;
	t_board	*result;

	fd = open(filename, O_RDONLY);
	input = get_input(fd);
	result = NULL;
	valid = validate_input(input, 0);
	if (!valid || input[0] == '\0')
		write(1, "error\n", 6);
	else
	{
		if ((result = initialize_board(input)) == NULL)
			return (NULL);
	}
	free(input);
	return (result);
}
