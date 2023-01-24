# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 10:01:50 by jyurrita          #+#    #+#              #
#    Updated: 2023/01/24 10:21:30 by jyurrita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Colors:
NC			=	\033[0m
LRED		=	\033[0;31m
GREEN		=	\033[0;32m
LRED		=	\033[1;31m
LGREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
LBLUE		=	\033[1;34m
TITLE		=	\033[38;5;33m

# Compile variables
LIB_CC			=	ar rcT
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -Imlx #-fsanitize=address
COMPILE			=	$(CC) $(FLAGS) -I include/ -I libftMaster/include/

# ************ CODE ************
LIBFT_DIR		=	./libftMaster
LIBFT			=	${LIBFT_DIR}/libft.a

NAME			=	fractol

EVENTS			=	key_hook.c \
					mouse_hook.c

FORMAT			=	format_julia_arg.c \
					format_user_input.c

INIT_PARAMS		=	inicialize_mlx.c

FRACTALS		=	paint_fractal.c \
					julia.c \
					mandelbrot.c \
					supermandelbrot.c

MAP				=	inicialize_map_params.c \
					map_point.c \
					zoom_map.c \
					zoom_out_map.c \
					center_map.c
					
SRCS			=	fractol.c \
					${EVENTS:%=events/%} \
					${FRACTALS:%=fractals/%} \
					${MAP:%=map/%} \
					${FORMAT:%=format/%} \
					${INIT_PARAMS:%=init_params/%}
					
OBJS			=	${SRCS:%.c=bin/%.o} 


# Makefile logic
all: $(NAME)

re: fclean all

$(NAME):	$(LIBFT) $(OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(NAME)${NC}\c"
	@$(COMPILE) $(OBJS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "${LGREEN} [OK]${NC}"


bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@ $(DEBUG)
	@echo "${GREEN} [OK]${NC}"

$(LIBFT):
	@echo "${TITLE}Compiling${NC} ${YELLOW}$(LIBFT)${NC}"
	@make -C $(LIBFT_DIR) all BIN="../bin/libft"

clean:
	@@echo "${LRED}Cleaning ${NC}libft"
	@make -C $(LIBFT_DIR) fclean BIN="../bin/libft"
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME)\c"
	@rm -f $(NAME)
	@echo "${LGREEN} [OK]${NC}"

.PHONY: all re fclean clean