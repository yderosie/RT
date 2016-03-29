# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:25:08 by rlambert          #+#    #+#              #
#    Updated: 2016/02/10 14:50:58 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT
CC=clang
PRINTF_PATH ?= ft_printf/

LIBFT_PATH ?= libft/

ifeq ($(shell uname), Linux)
	MLX_PATH ?= mlx_x11/
else
	MLX_PATH ?= mlx_mac/
endif

CFLAGS += -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra

SRCS =	src/main.c 												\
		src/ft_env.c

SRCS += src/parser.c											\
		src/parse_function.c									\
		src/parse_type.c										\
		src/foreach.c

SRCS += src/framework_math/vector/fk_vcpy.c						\
		src/framework_math/vector/fk_vdiv.c						\
		src/framework_math/vector/fk_vmul.c						\
		src/framework_math/vector/fk_vsum.c						\
		src/framework_math/vector/fk_vsub.c						\
		src/framework_math/vector/fk_vadd.c						\
		src/framework_math/vector/fk_vproduct.c					\
		src/framework_math/vector/fk_vdotproduct.c				\
		src/framework_math/vector/fk_vmagnitude.c				\
		src/framework_math/vector/fk_vnew.c						\
		src/framework_math/vector/fk_vreverse.c					\
		src/framework_math/vector/fk_vsubstract.c				\
		src/framework_math/vector/fk_vtranslation.c				\
		src/framework_math/vector/fk_vunit.c					\
		src/framework_math/vector/fk_cnew.c

SRCS += src/framework_collision/fk_collision.c					\
		src/framework_collision/texture.c						\
		src/framework_collision/fk_intersect.c

SRCS += src/framework_light/fk_light.c							\
		src/framework_light/fk_normal_sphere.c					\
		src/framework_light/fk_normal_cylinder.c				\
		src/framework_light/fk_normal_cone.c					\
		src/framework_light/fk_normal_paraboloid.c				\
		src/framework_light/fk_normal_triangle.c				\
		src/framework_light/fk_normal_plan.c					\
		src/framework_light/fk_luminance.c						\
		src/framework_light/fk_shadow.c

SRCS += src/framework_math/math/fk_isqrt.c

SRCS +=	src/framework_shape/fk_intersect_sphere.c				\
		src/framework_shape/fk_intersect_plan.c					\
		src/framework_shape/fk_intersect_cylinder.c				\
		src/framework_shape/fk_intersect_paraboloid.c			\
		src/framework_shape/fk_intersect_triangle.c				\
		src/framework_shape/fk_intersect_cone.c

INC_FILES = include/ft_env.h									\
			include/parser.h									\
			include/parser_union.h								\
			include/framework_light/fk_light.h					\
			include/framework_light/fk_normal_sphere.h			\
			include/framework_light/fk_normal_paraboloid.h		\
			include/framework_light/fk_normal_triangle.h		\
			include/framework_light/fk_normal_plan.h			\
			include/framework_light/fk_normal.h					\
			include/framework_collision/fk_collision.h			\
			include/framework_collision/fk_intersect.h			\
			include/framework_shape/fk_listobj.h				\
			include/framework_shape/fk_objects.h				\
			include/framework_shape/fk_sphere.h					\
			include/framework_shape/fk_triangle.h				\
			include/framework_shape/fk_paraboloid.h				\
			include/framework_shape/fk_plan.h					\
			include/framework_shape/fk_cylinder.h				\
			include/framework_shape/fk_cone.h					\
			include/framework_shape/fk_ray.h					\
			include/framework_shape/fk_type.h					\
			include/framework_math/stuff.noth					\
			include/framework_math/fk_math.h


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

LDFLAGS += -L$(PRINTF_PATH) -lftprintf -L$(MLX_PATH) -lmlx -lm
all: $(NAME)

MKDIR ?= mkdir

obj/%.o: src/%.c $(INC_FILES)
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(MLX_PATH)/libmlx.a:
	$(MAKE) -C $(MLX_PATH)

$(PRINTF_PATH)/libftprintf.a:
	$(MAKE) -C $(PRINTF_PATH)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(PRINTF_PATH)/libftprintf.a $(MLX_PATH)/libmlx.a $(LIBFT_PATH)/libft.a $(OBJS)
	$(CC) -O3 -o $@ $(OBJS) $(LDFLAGS)


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
