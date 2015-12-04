# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:25:08 by rlambert          #+#    #+#              #
#    Updated: 2015/11/12 18:22:05 by roblabla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

PRINTF_PATH ?= ft_printf/

LIBFT_PATH ?= libft/

ifeq ($(shell uname), Linux)
MLX_PATH ?= mlx_x11/
else
MLX_PATH ?= mlx_mac/
endif

CFLAGS += -Wall -Wextra -Werror

SRCS = src/main.c

C_INCLUDE_PATH += $(LIBFT_PATH)/include/ include/ $(PRINTF_PATH)/include/ $(MLX_PATH)

CFLAGS += $(foreach d, $(C_INCLUDE_PATH), -I$d)

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

CP = cp

RM = rm -f

LDFLAGS += -L$(PRINTF_PATH) -lftprintf -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft

ifeq ($(shell uname), Linux)
LDFLAGS += $(shell pkg-config xext x11 --libs)
else
LDFLAGS += -framework OpenGL -framework AppKit
endif

all: $(NAME)

MKDIR ?= mkdir

obj/%.o: src/%.c
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(MLX_PATH)/libmlx.a:
	$(MAKE) -C $(MLX_PATH)

$(PRINTF_PATH)/libftprintf.a:
	$(MAKE) -C $(PRINTF_PATH)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(PRINTF_PATH)/libftprintf.a $(MLX_PATH)/libmlx.a $(LIBFT_PATH)/libft.a $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT_PATH)/libft.a $(PRINTF_PATH)/libftprintf.a $(MLX_PATH)/libmlx.a
