#ifndef RIDDLE_H_INCLUDED
#define RIDDLE_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
typedef struct enigme{
SDL_Surface *image;
char question[100],reponse[100];
SDL_Rect pos;
int testreponse;
int affenigme;
FILE *file;
}enigme;


void  game_over(char ch[],SDL_Surface *ecran);
enigme init_enigme(enigme e);
int display_enigme (enigme e,SDL_Surface *ecran ,int *score);
FILE* random_enigme(int a,int b);
void enigme_sol(char name[],char *que,char *ans);

#endif // RIDDLE_H_INCLUDED
