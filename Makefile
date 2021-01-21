# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmogo <jmogo@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 14:15:15 by jmogo             #+#    #+#              #
#    Updated: 2021/01/21 17:10:31 by jmogo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

DIR		= ./srcs/

HEADERS	= ./includes/

HFILE	= minirt.h

HMLX	= mlx.h

FLAGS	= -Wall -Wextra -Werror

NAME	= miniRT

RM		= rm -f

MLX		= libmlx.dylib

SRCS	= 	check_file.c\
			finish_it.c\
			free_split.c\
			ft_atof.c\
			ft_atoi.c\
			ft_figadd_back.c\
			ft_isdigit.c\
			ft_num_utils.c\
			ft_split.c\
			get_clr_fig.c\
			get_next_line.c\
			get_next_line_utils.c\
			get_tr.c\
			main.c\
			manage_loop.c\
			mrt_add_next_cam.c\
			mrt_add_next_lght.c\
			mrt_clear_win.c\
			mrt_clr_utils.c\
			mrt_clr_utils2.c\
			mrt_cross_figs.c\
			mrt_doerr.c\
			mrt_filler.c\
			mrt_get_angle.c\
			mrt_get_screen_params.c\
			mrt_init_figs.c\
			mrt_init_objs.c\
			mrt_init_structs.c\
			mrt_mallocer.c\
			mrt_move_cam.c\
			mrt_paint.c\
			mrt_parse_color.c\
			mrt_parse_coord.c\
			mrt_parse_figs.c\
			mrt_parse_fov.c\
			mrt_parse_orient.c\
			mrt_put_pixel.c\
			mrt_saver.c\
			mrt_utils.c\
			mrt_vector_operations.c\
			mrt_vector_utils.c

vpath %.c	$(DIR)
vpath %.o	$(DIR)
vpath %.h	$(HEADERS)

OBJS	= $(SRCS:.c=.o)

%.o:	%.c $(HFILE) $(HMLX)
		$(CC) $(FLAGS) -c -I$(HEADERS) $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(MLX) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
