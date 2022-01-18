#
#

NOM		= libmlx.a
SRC		= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC		+= mlx_png.c mlx_mouse.m
SRC		+= mlx_opengl.m
OBJ1	= $(SRC:.c=.o)
OBJ		= $(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -w

all: $(NOM)

$(NOM):	$(OBJ)
	@echo	"\033[1m\033[35m===	COMPILATION MLX...	===\033[0m"
	@(ar -rc $(NOM) $(OBJ))
	@(ranlib $(NOM))
	@echo	"\033[32m===	MLX COMPILATION OK	===\033[0m"
	@echo	

clean:
	@(rm -f $(NOM) $(OBJ) *~)
	@(rm -f mlx_app)
	@echo	"\033[33m===	MLXDIR CLEANED	===\033[0m"

re: clean all fclean
