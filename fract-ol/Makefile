SRCS			:=	\
					01_julia.c\
					02_mendelbrot.c\
					03_burning_ship.c\
					04_leaf.c\
					05_leaft.c\
					06_newton.c\
					07_nova.c\
					colors.c\
					fractol.c\
					hook.c\
					hook2.c\
					hud.c\
					math_utils.c\
					math_utils2.c\
					math_utils3.c\
					mlx_utils.c\

SRCS_D			:=	srcs/

OBJS_D			:=	objs/

OBJS			:=	$(SRCS:%.c=$(OBJS_D)%.o)

HEAD			:=	fractol.h

HEAD_D			:=	incs/

NAME			:=	fractol

LIB				:=	libft.a

LIB_D			:=	libft/

LIB_H			:=	$(LIB_D)$(HEAD_D)

LIB_A			:=	$(LIB_D)$(LIB)

MLX				:=	libmlx.a

CC				:=	cc

RM				:=	rm -rf

CFLAGS			:=	-Wall -Wextra -Werror

ASAN_F			:=	-g3 #-fsanitize=address

OPTI_F			:= -o2 -march=native -fomit-frame-pointer -funroll-loops

UNAME_S			:=	$(shell uname -s)
ifeq ($(UNAME_S),Linux)
MLX_D			:=	MLX_Linux/
MLX_F			:=	-L$(MLX_D) -L/usr/lib -lmlx -lXext -lX11 -lm -lz
MLX_A			:=	$(MLX_D)$(MLX)
endif
ifeq ($(UNAME_S),Darwin)
MLX_D			:=	MLX_MacOS/
MLX_A			:=	$(MLX_D)$(MLX)
MLX_F			:=	-framework OpenGL -framework AppKit
endif

all				:	$(NAME)

$(NAME)			:	$(OBJS_D) $(OBJS) $(HEAD_D)$(HEAD) Makefile
				$(CC) $(CFLAGS) $(ASAN_F) $(OPTI_F) -o $(NAME) $(OBJS) $(MLX_A) $(LIB_A) $(MLX_F)

$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_D)$(HEAD) $(MLX_A) $(LIB_A)
				$(CC) $(CFLAGS) $(ASAN_F) $(OPTI_F) -I$(HEAD_D) -I$(LIB_H) -I$(MLX_D) -c $< -o $@

$(OBJS_D)		:
				mkdir -p $(OBJS_D)

$(MLX_A)		:	FORCE
				make -j -C $(MLX_D) >/dev/null 2>/dev/null

$(LIB_A)		:	FORCE
				make -j -C $(LIB_D)

FORCE			:

clean			:
				$(RM) $(OBJS) $(OBJS_D)
				make clean -C $(LIB_D) >/dev/null

fclean			:	clean
				$(RM) $(NAME)
				make fclean -C $(LIB_D) >/dev/null
				make clean -C $(MLX_D) >/dev/null

re				:	fclean all

.PHONY			:	all clean fclean re FORCE
