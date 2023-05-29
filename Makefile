CC         = @gcc
CFLAGS     = -Wall -Wextra -Werror -g
LDFLAGS    = -L./libft -lft
LINKS      = -framework OpenGL -framework AppKit
NAME       = cub3D

SRCDIR     = src
OBJDIR     = obj
GNL_DIR    = get_next_line

CFILES     = main.c \
             raycasting/init_raycasting.c \
             raycasting/raycasting.c \
			 raycasting/raycasting_utils.c \
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
             parsing/parse_step.c \
             parsing/parse_map_corner.c

GNL_FILES  = get_next_line.c \
             get_next_line_utils.c

SRCS       = $(addprefix $(SRCDIR)/, $(CFILES))
OBJS       = $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))
GNL_OBJS   = $(addprefix $(OBJDIR)/, $(GNL_FILES:.c=.o))

# Colors
GREEN      = \033[0;32m
YELLOW     = \033[0;33m
RED        = \033[0;31m
NC         = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS)
	@cd libft && make -s
	@cd minilibx_opengl && make -s
	@echo "$(YELLOW)Linking objects...$(NC)"
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(GNL_OBJS) ./libft/libft.a ./minilibx_opengl/libmlx.a $(LINKS) -o $@
	@echo "$(GREEN)$(NAME) created successfully!$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
#	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(@D)
#	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "$(RED)Cleaning objects...$(NC)"
	@rm -rf $(OBJDIR) libft/obj minilibx_opengl/*.o
	@find $(SRCDIR) -name '*.o' -delete

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@rm -f $(NAME)
	@cd libft && make fclean
	@cd minilibx_opengl && make clean

re: fclean all
