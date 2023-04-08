#include <stdio.h>
#include "lib_ppm.h"

int main()
{
	struct image_s data, newData;
	struct image_s *image = &data, *newImage = &newData;
	int r,
		// coluna
		x,
		// linha
		y;

	r = read_ppm("maru.ppm", image);

	// criando nova imagem vazia.
	r = new_ppm(newImage, image->width * 3, image->height * 3);

	if (r == 0)
	{
		for (y = 0; y < image->height; y++)
		{
			for (x = 0; x < image->width; x++)
			{
				// (Red) Primeira condição (cor = [0 ... 74])
				if (image->pix[y * image->width + x].r < 75)
				{
					newImage->pix[3 * y * newImage->width + 3 * x].r = 0;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x].r = 0;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x].r = 0;
				}
				// (Red) Segunda condição (cor = [75 ... 134])
				else if (image->pix[y * image->width + x].r < 135)
				{
					newImage->pix[3 * y * newImage->width + 3 * x].r = 0;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x].r = 255;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x].r = 0;
				}
				// (Red) Terceira condição (cor = [135 ... 179])
				else if (image->pix[y * image->width + x].r < 180)
				{
					newImage->pix[3 * y * newImage->width + 3 * x].r = 255;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x].r = 0;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x].r = 255;
				}
				// (Red) Quarta condição (cor = [180 ... 255])
				else if (image->pix[y * image->width + x].r < 255)
				{
					newImage->pix[3 * y * newImage->width + 3 * x].r = 255;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x].r = 255;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x].r = 255;
				}

				// (Green) Primeira condição (cor = [0 ... 74])
				if (image->pix[y * image->width + x].g < 75)
				{
					newImage->pix[3 * y * newImage->width + 3 * x + 1].g = 0;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x + 1].g = 0;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x + 1].g = 0;
				}
				// (Green) Segunda condição (de cor = [75 ... 134])
				else if (image->pix[y * image->width + x].g < 135)
				{
					newImage->pix[3 * y * newImage->width + 3 * x + 1].g = 0;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x + 1].g = 255;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x + 1].g = 0;
				}
				// (Green) Terceira condição (de cor = [135 ... 179])
				else if (image->pix[y * image->width + x].g < 180)
				{
					newImage->pix[3 * y * newImage->width + 3 * x + 1].g = 255;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x + 1].g = 0;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x + 1].g = 255;
				}
				// (Green) Quarta condição (de cor = [180 ... 255])
				else if (image->pix[y * image->width + x].g < 255)
				{
					newImage->pix[3 * y * newImage->width + 3 * x + 1].g = 255;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x + 1].g = 255;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x + 1].g = 255;
				}

				// (Blue) Primeira condição (cor = [0 ... 74])
				if (image->pix[y * image->width + x].b < 75)
				{
					newImage->pix[3 * y * newImage->width + 3 * x + 2].b = 0;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x + 2].b = 0;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x + 2].b = 0;
				}
				// (Blue) Segunda condição (de cor = [75 ... 134])
				else if (image->pix[y * image->width + x].b < 135)
				{
					newImage->pix[3 * y * newImage->width + 3 * x + 2].b = 0;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x + 2].b = 255;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x + 2].b = 0;
				}
				// (Blue) Terceira condição (de cor = [135 ... 179])
				else if (image->pix[y * image->width + x].b < 180)
				{
					newImage->pix[3 * y * newImage->width + 3 * x + 2].b = 255;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x + 2].b = 0;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x + 2].b = 255;
				}
				// (Blue) Quarta condição (de cor = [180 ... 255])
				else if (image->pix[y * image->width + x].b < 255)
				{
					newImage->pix[3 * y * newImage->width + 3 * x + 2].b = 255;
					newImage->pix[3 * y + 1 * newImage->width + 3 * x + 2].b = 255;
					newImage->pix[3 * y + 2 * newImage->width + 3 * x + 2].b = 255;
				}
			}
		}

		write_ppm("maru_copy.ppm", newImage);
		free_ppm(image);
	}

	return 0;
}
