#ifndef _TRI_IMG_H_
#define _TRI_IMG_H_

typedef int (*pFunc)(Pixel*, Pixel*);

int compLexicoRGB(Pixel *p1, Pixel *p2);
int compSommeRGB(Pixel *p1, Pixel *p2);
int compLexicoHSV(Pixel *p1, Pixel *p2);
int compLexicoYCbCr(Pixel *p1, Pixel *p2);

int triBulles(Image *img, pFunc compFunc);
int triInsertion(Image *img, pFunc compFunc);
int triSelection(Image *img, pFunc compFunction);

int partitionner(Image *img, int G, int D, int pivot, pFunc compFunc);
int triRapide(Image *img, int G, int D, pFunc compFunc);
int quicksort (Image *img, pFunc compFunc);
#endif