CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
INCLUDE = -I$(FDF_HEADERS) -I$(MYLIBC_HEADER) -I$(MLX_HEADER)  
LDFLAGS = -L$(MYLIBC_DIRECTORY) -L$(MLX_DIRECTORY) -lmlx -framework OpenGL -framework AppKit
SRCS = ./src/main.c\
		./src/init_tmap.c\
		./src/parse_inp_map.c\
		./src/parse_inp_map2.c\
		./src/str_to_clr.c\
		./src/draw_map.c\
		./src/position_line_points.c\
		./src/bresenham.c\
		./src/events.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

FDF_HEADERS = ./includes/

MYLIBC = $(MYLIBC_DIRECTORY)mylibc.a
MYLIBC_DIRECTORY = ./mylibc/
MYLIBC_HEADER = $(MYLIBC_DIRECTORY)

MLX = $(MLX_DIRECTORY)libmlx.a
MLX_DIRECTORY = ./minilibx_macos/
MLX_HEADER = $(MLX_DIRECTORY)

all: mylibc mlx $(NAME)

# %.o:%.c 
# 	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(MLX) $(MYLIBC)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LDFLAGS) $(MLX) $(MYLIBC) -o $(NAME)


bonus: mylibc mlx $(BONUS_NAME)
	
$(BONUS_NAME): $(BONUS_OBJS)  $(MLX) $(MYLIBC)
	$(CC) $(CFLAGS) $(INCLUDE) $(BONUS_OBJS) $(LDFLAGS) $(MLX) $(MYLIBC) -o $(BONUS_NAME)

mylibc:
	make -C $(MYLIBC_DIRECTORY)

mlx:
	make -C $(MLX_DIRECTORY)

clean:
	make -C $(MYLIBC_DIRECTORY) clean
	make -C $(MLX_DIRECTORY) clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	make -C $(MYLIBC_DIRECTORY) fclean
	make -C $(MLX_DIRECTORY) clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus mylibc mlx 
