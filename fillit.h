/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:16:36 by spoole            #+#    #+#             */
/*   Updated: 2019/02/18 18:54:45 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "Libft/libft.h"
# define BUFF_SIZE 500

typedef	struct		s_cord
{
	int				x;
	int				y;
}					t_cord;
typedef struct		s_board
{
	t_cord			***pieces;
	char			**grid;
	int				**iter;
	int				len;
	int				num_pieces;
}					t_board;

t_cord				***split_pieces(char *s1, t_board *board);
t_board				*open_file(char *filename);
t_cord				**create_piece(char *data_in);
t_board				*initialize_board(char *input);
char				**make_board(int len);
void				print_board(t_board *board);
int					ft_sqrt(int num);
void				free_board(t_board *clean);
void				solve(t_board *board);
void				clean_grid(t_board *clean);
void				clean_last_pc(t_board *board, int pi);
void				zero_iter(t_board *board, int start);
int					hash_touch(char *s1, int i);
int					validate_pieces(char *s1);
int					**init_iter(int len);
void				zero_iter(t_board *board, int start);
int					validate_input(char *s1, int i);
int					piece_fit(t_board *board, int pp, int y, int x);
int					count_pieces(char *s1);

#endif
