/* file:          lib_ppm.c
 * description:   PPM library
 * date:          03/2023
 * author:        Sergio Johann Filho <sergio.johann@acad.pucrs.br>
 */
//imagem é um vetor.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib_ppm.h"

//recebe nome da imagem e ponteiro ppara preencher
int read_ppm(char *file, struct image_s *image)
{
	FILE *fptr;
	char *t;
	char buf[128];
	int r, d, i, j;
	struct pixel_s *img_data;
	//abre arquivo e cria novo fluxo; se for 0 não consegue ler arquivo.
	fptr = fopen(file, "rb");
	if (!fptr)
		return -1;
	//Lendo a primeira linha; goto = jump
	t = fgets(buf, sizeof(buf), fptr);
	if (!t)
		goto failread;
	
	if (strncmp(buf, "P6\n", 3) != 0)
		goto failread;

        do {
		t = fgets(buf, sizeof(buf), fptr);
		if (!t)
			goto failread;
	//espera encontrar o # (comentário); le enquanto n encontra esse cara, pois depois dessa linha vem o tamanho da imagem.			
	} while (strncmp(buf, "#", 1) == 0);
		//verificar se o arquivo está no formato adequado.
        r = sscanf(buf, "%u %u", &image->width, &image->height);
        if (r < 2)
		goto failread;
		//leitura textual
        r = fscanf(fptr, "%u", &d);
        if ((r < 1) || (d != 255))
		goto failread;
		//função de busca --> permite que ande pelo arquivo; avançando 1 bite, para pular o enter no .h;
		//fptr = ponteiro
        fseek(fptr, 1, SEEK_CUR);
        
        img_data = malloc(image->width * image->height * sizeof(struct pixel_s));
        if (!img_data)
		goto failread;
        //preenche o vetor.
        image->pix = img_data;
        //le linha e coluna --> ineficiente, lendo por bloco, um pixel de cada vez.
		//leitura binária (mistura de leitura textual com binária).
        for (j = 0; j < image->height; j++)
		for (i = 0; i < image->width; i++)
			fread(&img_data[j * image->width + i], 3, 1, fptr);
	
	fclose(fptr);

	return 0;
	
failread:
	fclose(fptr);
	
	return -1;
}


int write_ppm(char *file, struct image_s *image)
{
	FILE *fptr;
	int i, j;
	
	fptr = fopen(file, "wb");
	if (!fptr)
		return -1;
		
	fprintf(fptr, "P6\n%d %d\n255\n", image->width, image->height);
        for (j = 0; j < image->height; j++)
		for (i = 0; i < image->width; i++)
			fwrite(&image->pix[j * image->width + i], 3, 1, fptr);

	fclose(fptr);
	
	return 0;
}


int new_ppm(struct image_s *image, int width, int height)
{
	struct pixel_s *img_data;

	image->width = width;
	image->height = height;
	
        img_data = malloc(image->width * image->height * sizeof(struct pixel_s));
        if (!img_data)
		return -1;
        
        image->pix = img_data;
        memset(image->pix, 0, image->width * image->height * sizeof(struct pixel_s));
	
	return 0;
}


int free_ppm(struct image_s *image)
{
	if (image->pix) {
		free(image->pix);
		
		return 0;
	}
	
	return -1;
}
