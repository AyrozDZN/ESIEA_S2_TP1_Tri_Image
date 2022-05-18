#include <stdio.h>
#include <stdlib.h>

#include "libbmp.h"
#include "tri_image.h"

// Compare les pixels p1 et p2 selon un ordre lexicographique sur les composantes RGB
// Retourne -1 si p1<p2, 0 si p1=p2, 1 si p1>p2
// Exemple : compLexicoRGB ((23,104,236), (23,137,32)) retourne -1
int compLexicoRGB(Pixel *p1, Pixel *p2)
{
    if (p1->R < p2->R) {
        return -1;
    } else if (p1->R == p2->R) {
        if (p1->G < p2->G) {
            return -1;
        } else if (p1->G == p2->G) {
            if (p1->B < p2->B) {
                return -1;
            } else if (p1->B == p2->B) {
                return 0;
            } else return 1;
        } else return 1;
    } else return 1;
}

// Compare les pixels p1 et p2 selon la somme des composantes RGB
// Retourne -1 si p1<p2, 0 si p1=p2, 1 si p1>p2
// Exemple : compSommeRGB ((23,104,236), (23,137,32)) retourne 1
int compSommeRGB(Pixel *p1, Pixel *p2)
{
    if ((p1->R + p1->G + p1->B) < (p2->R + p2->G + p2->B)) return -1;
    else if ((p1->R + p1->G + p1->B) == (p2->R + p2->G + p2->B)) return 0;
    else return 1;
}

// Compare les pixels p1 et p2 selon un ordre lexicographique sur les composantes HSV
// Retourne -1 si p1<p2, 0 si p1=p2, 1 si p1>p2
int compLexicoHSV(Pixel *p1, Pixel *p2)
{
    if (p1->H < p2->H) {
        return -1;
    } else if (p1->H == p2->H) {
        if (p1->S < p2->S) {
            return -1;
        } else if (p1->S == p2->S) {
            if (p1->V < p2->V) {
                return -1;
            } else if (p1->V == p2->V) {
                return 0;
            } else return 1;
        } else return 1;
    } else return 1;
}

// Compare les pixels p1 et p2 selon un ordre lexicographique sur les composantes YCbCr
// Retourne -1 si p1<p2, 0 si p1=p2, 1 si p1>p2
int compLexicoYCbCr(Pixel *p1, Pixel *p2)
{
    if (p1->Y < p2->Y) {
        return -1;
    } else if (p1->Y == p2->Y) {
        if (p1->Cb < p2->Cb) {
            return -1;
        } else if (p1->Cb == p2->Cb) {
            if (p1->Cr < p2->Cr) {
                return -1;
            } else if (p1->Cr == p2->Cr) {
                return 0;
            } else return 1;
        } else return 1;
    } else return 1;
}

// Trie l'image img a l'aide d'un tri a bulles en utilisant 
// la fonction compFunc pour comparer deux pixels
int triBulles(Image *img, pFunc compFunc)
{
    return 42;
}

// Trie l'image img a l'aide d'un tri insertion en utilisant 
// la fonction compFunc pour comparer deux pixels
int triInsertion(Image *img, pFunc compFunc)
{
    return 42;
}

// Trie l'image img a l'aide d'un tri selection en utilisant 
// la fonction compFunc pour comparer deux pixels
int triSelection(Image *img, pFunc compFunc)
{
    return 42;
}

// Partitionne l'image ig entre les pixels en position G et D,
// suivant la valeur du pixel en position pivot et en utilisant
// la fonction compFunc pour comparer deux pixels
// Retourne la position du pivot une fois le partitionnement effectue
int partitionner(Image *img, int G, int D, int pivot, pFunc compFunc)
{
    return 42;
}

// Trie les pixels de l'image img entre les positions G et D en utilisant
// la fonction compFunc pour comparer deux pixels
int triRapide(Image *img, int G, int D, pFunc compFunc)
{
    return 42;
}

// Trie les pixels de l'image img en utilisant
// la fonction compFunc pour comparer deux pixels
int quicksort (Image *img, pFunc compFunc)
{
    return 42;
}

