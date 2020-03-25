#ifndef DEPLACER_ALEATOIRE_H_INCLUDED
#define DEPLACER_ALEATOIRE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct
{
    SDL_Surface *objet;
    SDL_Rect pos_objet;
    int direction;
}entity;
entity init_entity (char ch[]);
entity deplacer_entity (entity e);

#endif // DEPLACER_ALEATOIRE_H_INCLUDED
