# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 17:29:37 by youjeong          #+#    #+#              #
#    Updated: 2023/09/04 18:03:39 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: minilib

DIR_MINILIB = minilibx_opengl_20191021
BUILD_MINILIB = make -C $(DIR_MINILIB) $@

clean:
	rm -rf mlx.h $(BUILD_MINILIB)

fclean:
	rm -rf libmlx.a mlx.h $(DIR_MINILIB)
re:
	$(MAKE) fclean
	$(MAKE) all

minilib:
	$(MAKE) fclean
	tar -xzf ./minilibx_opengl.tgz
	make -C $(DIR_MINILIB)
	cp $(DIR_MINILIB)/libmlx.a ./libmlx.a
	cp $(DIR_MINILIB)/mlx.h ./mlx.h
	
.PHONY: all clean fclean re
