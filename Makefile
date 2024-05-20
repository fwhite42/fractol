# Default library path
MK	?= mk
# Force the value of $(NAME)
NAME	:= fractol
# Tells core.mk to link X11 libraries when compiling $(NAME).c
X11	:= FALSE

MLX_MACOS := TRUE

# Source libraries
RARIES	:=		\
	mlx			\
	ft			\
	ftprintf	\
	error		\
	parser		\
	cplx		\
	color		\
	iterator	\
	screen		\
	camera		\
	fractol		

.DEFAULT_GOAL	:= all
include $(MK)/core.mk
