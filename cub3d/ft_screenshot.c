#include "cub3d.h"

void	image_to_sreenshot(t_all *all, int fd)
{
	int y;

	y = all->m.r[1];
	while (y >= 0)
	{
		y--;
		write(fd, all->img.line_len * y + all->img.addr, all->img.line_len);
	}
	close (fd);
    exit(0);
}

void	render_bmp(t_all *all)
{
	int fd;
	unsigned int	n;
	unsigned int	i;
	short			b;

	if ((fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666)) < 0)
		print_error("Fail with creating screenshot file");
	n = all->img.line_len * (all->m.r[1]) + 54;
	write(fd, "BM", 2);
	write(fd, &n, 4);
	i = 0;
	write(fd, &i, 4);
	i = 54;
	write(fd, &i, 4);
	i = 40;
	write(fd, &i, 4);
	write(fd, &all->m.r[0], 4);
	write(fd, &all->m.r[1], 4);
	b = 1;
	write(fd, &b, 2);
	b = all->img.bpp;
	write(fd, &b, 2);
	i = 0;
	write(fd, &i, 4);
	write(fd, &i, 4);
	write(fd, &i, 4);
	write(fd, &i, 4);
	write(fd, &i, 4);
	image_to_sreenshot(all, fd);
}