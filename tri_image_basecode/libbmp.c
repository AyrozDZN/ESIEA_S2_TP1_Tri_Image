#include <stdlib.h>
#include <stdio.h>

#include "libbmp.h"


int RGBtoHSV(Pixel *p)
{
	float r = p->R / 256.f, g = p->G / 256.f, b = p->B / 256.f;
	float max = r, min = r;

	p->H = 0;
	p->S = 0;
	p->V = 0;
	
	// Recherche du max et du min
	if (b > max)
		max = b;
	if (g > max)
		max = g;

	if (b < min)
		min = b;
	if (g < min)
		min = g;

	// Hue
	if (max == min)
		p->H = 0;
	if (max == r)
		p->H = (int)(60 * (float)(g - b) / (max-min) + 360) % 360;
	if (max == g)
		p->H = (int)(60 * (float)(b - r) / (max - min) + 120);
	if (max == b)
		p->H = (int)(60 * (float)(r - g) / (max - min) + 240);

	// Saturation
	p->S = (max == 0 ? 0.f : 1.f - ((float)min / max));

	// Value
	p->V = (float)max;

	return 0;
}

int RGBtoYCbCr(Pixel *p)
{
	unsigned char R = p->R, G = p->G, B = p->B;
	p->Y = (int)(0.299*R + 0.587 * G + 0.114 * B);
	p->Cb = (int)(-0.1687*R - 0.3313 * G + 0.5 * B + 128);
	p->Cr = (int)(0.5*R - 0.4187 * G  - 0.0813 * B + 128);
	return 0;
}

Image *readImage(char *imgpath)
{
	Image *img = NULL;
	FILE *pfile = NULL;
	int pad;
	int buf = 0, i, pos=0;

	img = (Image*)calloc(sizeof(Image), 1);

	// Ouverture de l'image
	//printf("Lecture de %s\n", imgpath);
	pfile = fopen(imgpath, "rb");
	if (!pfile)
	{
		printf("Impossible d'ouvrir %s\n", imgpath);
		return 0;
	}

	// Lecture du header
	fread(img->header, 54, 1, pfile);
	fseek(pfile, 18, SEEK_SET);
	fread(&img->width, 4, 1, pfile);
	//printf("width= %d\n", img->width);
	pad = (4 - (img->width * 3 % 4)) % 4;

	fread(&img->height, 4, 1, pfile);
	//printf("height= %d\n", img->height);

	img->size = img->height * img->width;

	// Allocation des pixels
	img->pix = (Pixel*)calloc(sizeof(Pixel), img->size);

	// Lecture des pixels
	fseek(pfile, 54, SEEK_SET);
	for (i = 0; i < img->height; i++)
	{
		for (int j=0; j<img->width; j++)
		{
			fread(&(img->pix[pos].B), 1, 1, pfile);
			fread(&(img->pix[pos].G), 1, 1, pfile);
			fread(&(img->pix[pos].R), 1, 1, pfile);
			pos++;
		}
		fread(&buf, pad, 1, pfile);
	}

	// Conversion au systeme HSV
	for (i = 0; i < img->size; i++)
	{
		 RGBtoHSV(&(img->pix[i]));
		 RGBtoYCbCr(&(img->pix[i]));
	}

	fclose(pfile);

	return img;
}


int writeImage (Image *img, char *imgpath)
{
	int pos = 0;
	int buf = 0;
	int pad;
	int i;
	FILE *output;

	// Ecriture du header et des pixels
	pad = (4 - (img->width * 3 % 4)) %4;
	output = fopen(imgpath, "wb");
	if (!output)
	{
		printf ("Impossible d'ouvrir le fichier %s en mode écriture.\n", imgpath);
		return -1;
	}
	fwrite(img->header, 54, 1, output);
	for (i = 0; i < img->height; i++)
	{
		for (int j=0; j<img->width; j++)
		{
			fwrite(&(img->pix[pos].B), 1, 1, output);
			fwrite(&(img->pix[pos].G), 1, 1, output);
			fwrite(&(img->pix[pos].R), 1, 1, output);
			pos++;
		}
		fwrite(&buf, pad, 1, output);
	}

	fclose(output);

	return 0;
}

int freeImage (Image *img)
{
	if (!img) return -1;
	if (img->pix)
		free(img->pix);
	free(img);
	return 0;	
}