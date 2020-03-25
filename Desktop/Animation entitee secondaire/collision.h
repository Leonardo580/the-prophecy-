#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


//--------------------------------------------------------------------------------------------------------------------------------------------


void vie(int nb , SDL_Surface p , SDL_Rect pos);
int collision_bounding(SDL_Rect pos_p, SDL_Rect pos_e);
int collision_parfaite(SDL_Surface *per ,SDL_Rect pos_per,SDL_Surface *bgmask);

void anniperso(SDL_Surface t[] , int n);
void animation_entitee_secondaire(SDL_Surface *sprite,SDL_Rect *psprite,int num_w,int num_h,int move);

#endif // COLLISION_H_INCLUDED
