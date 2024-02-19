#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "./images.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);

	// Verifica si la imagen se cargó correctamente
	if (!img)
	{
		printf("Error al cargar la imagen.\n");
		return (1);
	}

	// Muestra la imagen en la ventana
	mlx_put_image_to_window(mlx, mlx_win, img, 960, 540);

	// Permite que la ventana sea visible
	mlx_loop(mlx);
	return (0);
}

