#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>


int	press_key(int keycode, void* win_ptr)
{
	if (keycode == 53 || keycode == 12)
	{
		exit(0);
	}
	printf("%d\n", keycode);
	return (0);
}

int main()
{
    void *mlx = mlx_init();
    void *win_ptr =  mlx_new_window(mlx, 240, 320, "hello");
    mlx_key_hook(win_ptr, press_key, mlx);
    mlx_loop(mlx);
}