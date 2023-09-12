NAME =		PARSE_TESTER

CC =		cc -g3
CFLAGS =	-Wall -Wextra -Werror
INCLUDE = 	-I ../../includes \
			-I ../../libft/includes \

LIB = -L../../libft -lft

BUILD_LIBFT = make -C ../../libft $@

SRCS =		tester.c \
			valid_extension.c \
			read_file.c \
			nomalize_file.c \
			parse_map.c \
			valid_map.c \
			../get_next_line/get_next_line.c \
			../get_next_line/get_next_line_utils.c

OBJS = 		$(SRCS:.c=.o)

%o: %c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

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
