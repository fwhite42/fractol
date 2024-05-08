# Default library path
MK	?= mk
# Force the value of $(NAME)
NAME	:= fractol
# Tells core.mk to link X11 libraries when compiling $(NAME).c
X11	:= TRUE

# Source libraries
define RARIES
	mlx
	ft
	ftprintf
	error
	ui
	cplx
	fractol
endef

# Makefile Logic
include $(MK)/core.mk
