NAME =		cub3D

CC =		cc -g3
CFLAGS =	-Wall -Wextra -Werror
INCLUDE = 	-I includes \
			-I libft/includes \
			-I mlx
LIB =		-Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit

RM =		rm -rf
BUILD_LIBFT = make -C libft $@

SRCS_RT_DIR =	srcs/

SRCS_DIR =		config \
				window \
				map \
				render \
				get_next_line \
				exception \
				config \
				event \
				xmem

CFILES =		main.c \
				set_config.c \
				config_img.c \
				config_player.c \
				window_init.c \
				window_setting.c \
				window_draw.c \
				window_draw_one_line.c \
				draw_image_to_window.c \
				calc_and_put_window_image.c \
				event_hook_handler.c \
				raycasting.c \
				\
				create_map.c \
				valid_extension.c \
				read_file.c \
				nomalize_file.c \
				parse_map.c \
				valid_map.c \
				valid_closed_wall.c \
				parse_rgb.c \
				is_empty_line.c \
				\
				get_next_line.c \
				get_next_line_utils.c \
				\
				xmalloc.c \
				xtrim.c \
				xsubstr.c \
				xsplit.c \
				free_vector_arr.c \
				\
				exception_handler.c \
				wasd_event_handler.c \
				arrow_event_handler.c \
				xmalloc.c

CFILES :=		$(addprefix $(SRCS_RT_DIR), $(CFILES))

SRCS = 			$(notdir $(CFILES))

OBJS_DIR = 		objs/
OBJS = 			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

VPATH = 		$(SRCS_RT_DIR) \
				$(addprefix $(SRCS_RT_DIR), $(SRCS_DIR))

$(OBJS_DIR)%o: %c
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

$(NAME): make_mandatory

all: $(NAME)

bonus: all

make_mandatory: $(OBJS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(LIB) $^ -o $(NAME)
	touch $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) make_mandatory make_bonus
	$(BUILD_LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(BUILD_LIBFT)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus
