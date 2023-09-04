NAME =		cub3d

CC =		cc -g3
CFLAGS =	-Wall -Wextra -Werror
INCLUDE = 	-I includes \
			-I libft/includes \
			-I mlx
LIB =		-lmlx

RM =		rm -rf
BUILD_LIBFT = make -C libft $@
BUILD_MLX = make -C mlx $@

SRCS_RT_DIR =	srcs/

SRCS_DIR =		gnl \

CFILES =		main.c

CFILES :=		$(addprefix $(SRCS_RT_DIR), $(CFILES))

SRCS = 			$(notdir $(CFILES))

OBJS_DIR = 		objs/
OBJS = 			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

VPATH = 		$(SRCS_RT_DIR) \
				$(addprefix $(SRCS_RT_DIR), $(SRCS_DIR))

$(OBJS_DIR)%o: %c
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

$(NAME): make_mlx make_mandatory

all: $(NAME)

bonus: all

make_mlx:
	make -C mlx

make_mandatory: $(OBJS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $^
	touch $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) make_mandatory make_bonus
	$(BUILD_LIBFT)
	$(BUILD_MLX)

fclean: clean
	$(RM) $(NAME)
	$(BUILD_LIBFT)
	$(BUILD_MLX)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus
