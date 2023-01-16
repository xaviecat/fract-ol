SRCS			=	\
					fractol.c\
					hook.c\
					julia.c\
					math_utils.c\
					mlx_utils.c\

SRCS_D			=	srcs/

OBJS			=	$(SRCS:%.c=$(OBJS_D)%.o)

OBJS_D			=	objs/

HEAD			=	fractol.h

HEAD_D			=	incs/

NAME			=	fractol

LIB				=	libft.a

LIB_D			=	libft/

LIB_H			=	$(LIB_D)$(HEAD_D)

LIB_A			=	$(LIB_D)$(LIB)

MLX				=	libmlx.a

MLX_D			=	mlx/

MLX_F			=	-Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_A			=	$(MLX_D)$(MLX)

CC				=	cc

RM				=	rm -rf

CFLAGS			=	 -Wall -Wextra -Werror -g3 #-o2 -march=native#-fsanitize=address

all				:	$(NAME)

$(NAME)			:	$(OBJS_D) $(OBJS) $(HEAD_D)$(HEAD)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_A) $(LIB_A) $(MLX_F)


$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_D)$(HEAD) $(MLX_A) $(LIB_A)
				$(CC) $(CFLAGS) -I$(HEAD_D) -I$(LIB_H) -I$(MLX_D) -c $< -o $@

$(OBJS_D)		:
				mkdir -p $(OBJS_D)

$(MLX_A)		:	FORCE
				make -j -C $(MLX_D) 2>/dev/null

$(LIB_A)		:	FORCE
				make -j -C $(LIB_D)

FORCE			:

clean			:
				$(RM) $(OBJS) $(OBJS_B) $(OBJS_D)
				make clean -C $(LIB_D) >/dev/null

fclean			:	clean
				$(RM) $(NAME) $(OBJS_B)
				make fclean -C $(LIB_D) >/dev/null
				make clean -C $(MLX_D) >/dev/null

re				:	fclean all

.PHONY			:	all clean fclean re mklib FORCE
