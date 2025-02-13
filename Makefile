########################################################################################################################
#                                                       VARIABLE                                                       #
########################################################################################################################
SRCS		:=	\
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

SRCS_D		:=	srcs/

OBJS_D		:=	objs/

OBJS		:=	$(SRCS:%.c=$(OBJS_D)%.o)

INCS		:=	\
				fractol.h\

INCS_D		:=	incs/

DEPS_D		:=	deps/

DEPS		:=	$(SRCS:%.c=$(DEPS_D)%.d)

NAME		:=	fractol

########################################################################################################################
#                                                         LIB                                                          #
########################################################################################################################
LIB			:=	libft.a

LIB_D		:=	libft

LIB_I		:=	$(LIB_D)/$(INCS_D)

LIB_H		:=	$(LIB_I)libft.h

LIB_A		:=	$(LIB_D)/$(LIB)

MLX			:=	libmlx.a

MLX_D		:=	MLX_Linux

MLX_F		:=	-L$(MLX_D) -L/usr/lib -lmlx -lXext -lX11 -lm -lz

MLX_I		:=	$(MLX_D)

MLX_H		:=	$(MLX_I)/mlx.h

MLX_A		:=	$(MLX_D)/$(MLX)

########################################################################################################################
#                                                        FLAGS                                                         #
########################################################################################################################
CC			:=	cc

RM			:=	rm -rf

IFLAGS		:=	-I$(INCS_D) -I$(LIB_I) -I$(MLX_I)

DFLAGS		=	-MMD -MP -MT $@ -MF $(DEPS_D)$*.d

DFLAGS_B	=	-MMD -MP -MT $@ -MF $(DEPS_B_D)$*.d

CFLAGS		=	-Wall -Wextra -Werror -g3 $(IFLAGS)

OFLAGS		:=	-Ofast -march=native -fomit-frame-pointer -funroll-loops

ARGS		?=	Mandelbrot

########################################################################################################################
#                                                        DEBUG                                                         #
########################################################################################################################
DEBUG		=	no

ifeq ($(DEBUG), yes)
	CFLAGS	+=	-fsanitize=address
endif

IGN_LEAK	:=	valgrind_ignore_leaks.txt

VALGRIND	:=	valgrind --leak-check=full --show-leak-kinds=all\
				--track-fds=yes --show-mismatched-frees=yes --read-var-info=yes --track-origins=yes -s
#				--default-suppressions=no

########################################################################################################################
#                                                        COLORS                                                        #
########################################################################################################################
BLUE		:=	\001\033[34m\002

BOLD		:=	\001\033[1m\002

ITALIC		:=	\001\033[3m\002

RESET		:=	\001\033[0m\002

PSEUDO		:=	$(BOLD)$(ITALIC)xcharra$(RESET)$(BLUE)

########################################################################################################################
#                                                        RULES                                                         #
########################################################################################################################
-include $(DEPS)

.DEFAULT_GOAL = all

all			:	$(NAME) $(BONUS) banner

$(NAME)		:	$(OBJS) $(LIB_A) $(MLX_A)
			$(CC) $(CFLAGS) $(OFLAGS) -o $(NAME) $(OBJS) $(MLX_A) $(LIB_A) $(MLX_F)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c | $(OBJS_D) $(DEPS_D)
			$(CC) $(CFLAGS) $(OFLAGS) $(DFLAGS) -c $< -o $@

$(OBJS_D)	:
			mkdir -p $@

$(DEPS_D)	:
			mkdir -p $@

$(LIB_A)	:	FORCE
			$(MAKE) -C $(LIB_D)

$(MLX_A)	:	FORCE
			$(MAKE) -C $(MLX_D) 2>/dev/null

leaks		:	$(NAME)
			$(VALGRIND) ./$(NAME) $(ARGS)

run			:	all banner
			./$(NAME) $(ARGS)

fsan		:
			$(MAKE) fclean $(NAME) DEBUG=yes

########################################################################################################################
#                                                    MISCELLANEOUS                                                     #
########################################################################################################################
banner		:
			@echo -e '$(BLUE)'
			@echo -e '                                   @@                                     '
			@echo -e '                                 =@##@                                    '
			@echo -e '                                 @#**%                                    '
			@echo -e '                          @  @@%  %###%@@  =                              '
			@echo -e '                          ==%#*#%%===***#+@%                              '
			@echo -e '           @@= ==      =@@%#******###******#=                             '
			@echo -e '          +#=%%%@@    =%********************@              =#             '
			@echo -e '        @@#******%@   @#*#%=%#**************@        =@@@ @@#             '
			@echo -e '   @@+ @#*##*****#=  @#=======@#***********#@     @@@%**###=%@=           '
			@echo -e '@=@%*%=#*% =*****%  +%***#%=   =#**********@    @@%####*******%=          '
			@echo -e ' = @#*#%@@ @*****#= =%#***#@   =#*********%   -@#*=====%******#@   @+@    '
			@echo -e '    @*@=  =%******%=====*#@=   **********#=   *#***#%=  #*****@ =@%#*#@   '
			@echo -e '          =%*******#####%@    @#*********#=   =%#***#@  %*****= %*#=#*#@=@'
			@echo -e '           @@%=###**#@@@=    ##***********#@=======*%. =%*****####@ +@@=  '
			@echo -e '             =@@ @@@=        @**************#%=%#**%=  =%****###%@        '
			@echo -e '             =+              @***********$(PSEUDO)%#    @@%#*==@          '
			@echo -e '                             %#*******#********#%@=       ==@@@           '
			@echo -e '                              =%=#***===@%#**#=%                          '
			@echo -e '                              @= @@%#=#=  @@@= @                          '
			@echo -e '                                   =%**%@                                 '
			@echo -e '                                    @##@=                                 '
			@echo -e '                                     @@                                   '
			@echo -e '$(RESET)'


clean		:
			$(RM) $(OBJS) $(OBJS_D) $(DEPS_D) $(OBJS_B_D) $(DEPS_B_D)

fclean		:	clean
			$(RM) $(NAME) $(NAME_B)
			$(MAKE) fclean -C $(LIB_D)
			$(MAKE) clean -C $(MLX_D)

re			:	fclean all

FORCE		:

.PHONY		:	all debug leaks re clean fclean FORCE
