NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

CFLAGS+= -DSTRINGPUTX11

CFLAGS+= -w

all: $(NOM)

$(NOM): $(OBJ)
	@ar -r $(NOM) $(OBJ) > /dev/null 2>&1
	@ranlib $(NOM) > /dev/null 2>&1

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
