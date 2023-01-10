SRCS			=	\
					fractol.c\

SRCS_D			=	srcs/

OBJS			=	$(SRCS:%.c=$(OBJS_D)%.o)

OBJS_D			=	objs/

HEAD			=	fractol.h

HEAD_D			=	incs/

NAME			=	fractol

LIB				=	libft.a

LIB_D			=	libft/

LIB_H			=	$(LIB_D)$(HEAD_D)

MLX				=	libmlx.a

MLX_D			=	mlx/

MLX_F			=	-Lmlx -lmlx -framework OpenGL -framework AppKit

CC				=	cc

RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror -g #-fsanitize=address -g3

all				:	mklib $(NAME)

$(NAME)			:	$(OBJS_D) $(OBJS) $(HEAD_D)$(HEAD) $(MLX)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_D)$(LIB) $(MLX_D)$(MLX) $(MLX_F)


$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_D)$(HEAD) $(LIB_D)
				$(CC) $(CFLAGS) -I$(HEAD_D) -I$(LIB_H) -I$(MLX_D) -c $< -o $@

$(OBJS_D)		:
				mkdir -p $(OBJS_D)

$(MLX)			:	$(MLX_D)
				make -j -C $(MLX_D) 2>/dev/null >/dev/null

mklib			:
				make -j -C $(LIB_D) >/dev/null

clean			:
				$(RM) $(OBJS) $(OBJS_B) $(OBJS_D)
				make clean -C $(LIB_D) >/dev/null

fclean			:	clean
				$(RM) $(NAME) $(OBJS_B)
				make fclean -C $(LIB_D) >/dev/null
				make clean -C $(MLX_D) >/dev/null

re				:	fclean all

.PHONY			:	all clean fclean re mklib
