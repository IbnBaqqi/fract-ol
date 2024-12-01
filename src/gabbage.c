// int32_t	main(void)
// {

// 	// MLX allows you to define its core behaviour before startup.
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
// 	if (!mlx)
// 		return 0;

// 	// Create and display the image.
// 	mlx_image_t* img = mlx_new_image(mlx, 1000, 1000);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		return 0;
// 	int i = 0, y = 0;
// 	while ((i < 100))
//   	{
// 		mlx_put_pixel(img, i, y, 255);
// 		i++;
// 		y++;
//   	}
// 	//mlx_put_pixel(img, 0, 0, 0xFF000000);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }