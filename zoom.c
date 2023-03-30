#include <stdio.h>
#include "lib_ppm.h"

int main()
{
	struct image_s data;
	struct image_s *image = &data;
	int i, j, r;

	r = read_ppm("lena.ppm", image);

	if (r == 0)
	{
		printf("width: %d, height: %d\n", image->width, image->height);
		for (j = 0; j < image->height; j++)
		{
			for (i = 0; i < image->width; i++)
			{
				printf("(%d %d) %02x %02x %02x\n", i, j,
					   image->pix[j * image->width + i].r, //convertendo linha e coluna para um vetor (matriz n existe; quando termina a primeira linha de 512 pixels, vai ter a próxima linha (1º pixel dela)); transformando array em algo como se fosse uma matriz (largura multiplicada pela linha mais a coluna)
					   image->pix[j * image->width + i].g,
					   image->pix[j * image->width + i].b);
			}
		}
		//é possível alterar a imagem
		image->pix[50 * image->width + 20].r = 255;
		image->pix[50 * image->width + 20].g = 255;
		image->pix[50 * image->width + 20].b = 255;
		//criando outra imagem a partir do mesmo vetor --> cuidar com o nome, se colocar o mesmo vai substituir
		write_ppm("lena_copy.ppm", image);

		free_ppm(image);
	}
	//criando nova imagem vazia.
	r = new_ppm(image, 675, 428);
	//Escrevendo na imagem criada 3 pontos de cores diferentes (criei imagem do zero e to gravando nela)
	if (r == 0)
	{
		image->pix[100 * image->width + 125].r = 255;
		image->pix[27 * image->width + 440].g = 255;

		image->pix[371 * image->width + 10].r = 192;
		image->pix[371 * image->width + 10].g = 192;
		image->pix[371 * image->width + 10].b = 192;
		//free para liberar memória.
		write_ppm("test.ppm", image);
		free_ppm(image);
	}

	return 0;
}
