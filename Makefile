NAME = cub3d
LIBFTNAME = libft.a
LIBFTPATH = ./libft

SRC_DIR = ./src/
SRC =  main.c \
		raycasting/init_raycasting.c \
		raycasting/raycasting.c \
		controller/game_loop.c \
		controller/hook.c \
		controller/move.c \
		texturing/texturing.c \
		parsing/parse_map.c \
		parsing/parse_map_funct.c \
		parsing/parse_cub.c \
		parsing/parse_data_init_and_free.c \
		parsing/parse_color.c \
		parsing/parse_error.c \
		parsing/parse_data_file.c \
		parsing/map_struct_funct.c \
		parsing/data_to_struct.c \
		parsing/parse_data_print_struct.c \
		parsing/parse_data_start.c \
		parsing/parse_step.c

OBJS = ${addprefix ${SRC_DIR}, ${SRC:.c=.o}}

GNL_DIR = ./get_next_line/
GNL = get_next_line.c \
	get_next_line_utils.c \

GNL_OBJS = ${addprefix ${GNL_DIR}, ${GNL:.c=.o}}


FLAGS = -Wall -Wextra -Werror -g
LINKS = -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@make -C ${LIBFTPATH}
	@cd minilibx_opengl && make
	@gcc $(FLAGS) $(OBJS) $(GNL_OBJS) ./libft/libft.a ./minilibx_opengl/libmlx.a $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJS) $(GNL_OBJS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@cd libft && make fclean
	@cd minilibx_opengl && make clean

re: fclean all
