#include <stdio.h>
#include "lib_ppm.h"

void amplify(char inputImage[], char outputImage[]);
void paintItRed(struct image_s *image, struct image_s *newImage, int x, int y);
void paintItGreen(struct image_s *image, struct image_s *newImage, int x, int y);
void paintItBlue(struct image_s *image, struct image_s *newImage, int x, int y);

int main()
{
	int i = 0;
	int total = 1; // 15;

	printf("Carregando imagem %d de %d\n", ++i, total);
	amplify("assets/input/maru.ppm", "assets/output/maru.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/belem.ppm", "assets/output/belem.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/cavalo.ppm", "assets/output/cavalo.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/construcao.ppm", "assets/output/construcao.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/drinks.ppm", "assets/output/drinks.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/flores.ppm", "assets/output/flores.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/fontedeagua.ppm", "assets/output/fontedeagua.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/paisagem.ppm", "assets/output/paisagem.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/palmeiras.ppm", "assets/output/palmeiras.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/pavao.ppm", "assets/output/pavao.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/salsicha.ppm", "assets/output/salsicha.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/test.ppm", "assets/output/test.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/test2.ppm", "assets/output/test2.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/toelho.ppm", "assets/output/toelho.ppm");

	// printf("Carregando imagem %d de %d\n", ++i, total);
	// amplify("assets/input/underground.ppm", "assets/output/underground.ppm");

	return 0;
}

void amplify(char inputImage[], char outputImage[])
{
	struct image_s data, newData;
	struct image_s *image = &data, *newImage = &newData;
	int r,
		// coluna
		x,
		// linha
		y;

	r = read_ppm(inputImage, image);

	// Criando nova imagem vazia com 3x o tamanho original.
	r = new_ppm(newImage, image->width * 3, image->height * 3);

	if (r == 0)
	{
		for (y = 0; y < image->height; y++)
			for (x = 0; x < image->width; x++)
			{
				paintItRed(image, newImage, x, y);
				paintItGreen(image, newImage, x, y);
				paintItBlue(image, newImage, x, y);
			}

		write_ppm(outputImage, newImage);
		free_ppm(image);
	}
}

void paintItRed(struct image_s *image, struct image_s *newImage, int x, int y)
{
	int top = 0, middle = 0, bottom = 0;

	// cor = [0 ... 74]
	if (image->pix[y * image->width + x].r < 75)
	{
		top = 0;
		middle = 0;
		bottom = 0;
	}
	// cor = [75 ... 134]
	else if (image->pix[y * image->width + x].r < 135)
	{
		top = 0;
		middle = 255;
		bottom = 0;
	}
	// cor = [135 ... 179]
	else if (image->pix[y * image->width + x].r < 180)
	{
		top = 255;
		middle = 0;
		bottom = 255;
	}
	// cor = [180 ... 255]
	else if (image->pix[y * image->width + x].r < 255)
	{
		top = 255;
		middle = 255;
		bottom = 255;
	}

	newImage->pix[(3 * y) * newImage->width + 3 * x].r = top;
	newImage->pix[(3 * y + 1) * newImage->width + 3 * x].r = middle;
	newImage->pix[(3 * y + 2) * newImage->width + 3 * x].r = bottom;
}

void paintItGreen(struct image_s *image, struct image_s *newImage, int x, int y)
{
	int top = 0, middle = 0, bottom = 0;

	// cor = [0 ... 74])
	if (image->pix[y * image->width + x].g < 75)
	{
		top = 0;
		middle = 0;
		bottom = 0;
	}
	// cor = [75 ... 134]
	else if (image->pix[y * image->width + x].g < 135)
	{
		top = 0;
		middle = 255;
		bottom = 0;
	}
	// cor = [135 ... 179]
	else if (image->pix[y * image->width + x].g < 180)
	{
		top = 255;
		middle = 0;
		bottom = 255;
	}
	// cor = [180 ... 255]
	else if (image->pix[y * image->width + x].g < 255)
	{
		top = 255;
		middle = 255;
		bottom = 255;
	}

	newImage->pix[(3 * y) * newImage->width + 3 * x + 1].g = top;
	newImage->pix[(3 * y + 1) * newImage->width + 3 * x + 1].g = middle;
	newImage->pix[(3 * y + 2) * newImage->width + 3 * x + 1].g = bottom;
}

void paintItBlue(struct image_s *image, struct image_s *newImage, int x, int y)
{
	int top = 0, middle = 0, bottom = 0;

	// cor = [0 ... 74]
	if (image->pix[y * image->width + x].b < 75)
	{
		top = 0;
		middle = 0;
		bottom = 0;
	}
	// cor = [75 ... 134]
	else if (image->pix[y * image->width + x].b < 135)
	{
		top = 0;
		middle = 255;
		bottom = 0;
	}
	// cor = [135 ... 179]
	else if (image->pix[y * image->width + x].b < 180)
	{
		top = 255;
		middle = 0;
		bottom = 255;
	}
	// cor = [180 ... 255]
	else if (image->pix[y * image->width + x].b < 255)
	{
		top = 255;
		middle = 255;
		bottom = 255;
	}

	newImage->pix[(3 * y) * newImage->width + 3 * x + 2].b = top;
	newImage->pix[(3 * y + 1) * newImage->width + 3 * x + 2].b = middle;
	newImage->pix[(3 * y + 2) * newImage->width + 3 * x + 2].b = bottom;
}
