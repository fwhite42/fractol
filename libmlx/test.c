#include"libmlx.h"

int main()
{
	void *mlx;
	mlx = mlx_init();
	mlx_new_window(mlx, 100, 100, "win");
	mlx_loop(mlx);
}
