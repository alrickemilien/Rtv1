NAME=rtv1

OS="$(shell uname)"

CCFLAGS= -O3 -Wall -Wextra -Werror 

LIBFT= -lft -L srcs/libft -I srcs/libft

USAGE="Usage : ./rtv1 [scene file]"

LPTHREAD= -lpthread

FRAMEWORK= -framework OpenGL -framework AppKit

INCLUDE=-I include

SRCS= srcs/event/event.c		srcs/event/free_tab.c\
srcs/event/end_program.c	srcs/event/free_data.c\
srcs/math/cone.c		srcs/math/matrix_func.c		srcs/math/vector_1.c\
srcs/math/cylindre.c		srcs/math/plan.c		srcs/math/vector_2.c\
srcs/math/get_surface_normal.c	srcs/math/rotation.c\
srcs/math/light.c		srcs/math/sphere.c\
srcs/parser/error.c			srcs/parser/set_cone.c\
srcs/parser/func_nbr_parse.c		srcs/parser/set_cylinder.c\
srcs/parser/func_parse.c		srcs/parser/set_diffuse.c\
srcs/parser/init_default_camera.c	srcs/parser/set_light.c\
srcs/parser/init_parser.c		srcs/parser/set_normal.c\
srcs/parser/parser.c			srcs/parser/set_plan.c\
srcs/parser/recycle.c			srcs/parser/set_position.c\
srcs/parser/set_angle.c			srcs/parser/set_rayon.c\
srcs/parser/set_apex.c			srcs/parser/set_rotation.c\
srcs/parser/set_axis.c			srcs/parser/set_size.c\
srcs/parser/set_brillance.c		srcs/parser/set_specular.c\
srcs/parser/set_camera.c		srcs/parser/set_sphere.c\
srcs/parser/set_camera_data.c		srcs/parser/sort_camera.c\
srcs/parser/set_color.c\
srcs/raytracing/get_diffuse.c			srcs/raytracing/raytracing.c\
srcs/raytracing/get_specularity.c		srcs/raytracing/shadow.c\
srcs/raytracing/get_surface_caracter.c		srcs/raytracing/split_color.c\
srcs/raytracing/main.c				srcs/raytracing/thread.c\
srcs/raytracing/mlx_put_pixel_to_image.c\

OBJ=$(SRCS:.c=.o)

ifeq ($(OS), "Linux")
	TARGET= LINUX
	LIBMLX_SRCS= srcs/minilibx_linux
else
	TARGET= MACOS
	LIBMLX_SRCS= srcs/minilibx_macos
endif

LIBMLX= -lmlx -L $(LIBMLX_SRCS) -I $(LIBMLX_SRCS)


all: $(TARGET)

LINUX: $(OBJ)
	@make -C srcs/libft
	@make -C srcs/minilibx_linux
	@gcc -o $(NAME) $^ $(LIBFT) $(INCLUDE) $(LPTHREAD) \
		$(LIBMLX) $(CCFLAGS) -lX11 -lXext -lm \
		`pkg-config --libs --cflags x11` 

MACOS: $(OBJ)
	@make -C srcs/libft
	@make -C srcs/minilibx_macos
	@gcc -o $(NAME) $^ $(LIBFT) $(LPTHREAD) \
		$(LIBMLX) $(FRAMEWORK) $(CCFLAGS)

%.o: %.c
	@gcc -o $@ -c $< $(INCLUDE) $(CCFLAGS)

clean:
	@make clean -C srcs/libft
	@make clean -C $(LIBMLX_SRCS)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C srcs/libft
	@rm -rf $(NAME)

re: fclean all
