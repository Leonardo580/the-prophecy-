#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

void init_anim_sec  (SDL_Surface *sprite,SDL_Rect *psprite,int num_w,int num_h,int move)
{
    if (move==0) 
    {
 psprite->x=0;
        psprite->y=0;
    psprite->w=(int)sprite->w/4;
    psprite->h=(int)sprite->h/2;
    } 
    else 
    {
        psprite->x=sprite->w-sprite->w/num_w;
         psprite->y=sprite->h/num_h;
    psprite->w=sprite->w/num_w;
    psprite->h=sprite->h/num_h;
    }
}
void animation_entitee_secondaire(SDL_Surface *sprite,SDL_Rect *psprite,int num_w,int num_h,int move)
{

    if(move==0){
        
     
        if (psprite->x<= sprite->w-(sprite->w/num_w)-5){
            
        psprite->x=(int)(psprite->x+ (float)sprite->w/(float)num_w);
       // psprite->y+=(int)sprite->h/num_h;
        psprite->w=sprite->w/num_w;
       // psprite->h+=(int)sprite->h/num_h;

        }
        else{
            printf("fucking piece of shit </> %d\t%d\t%d\t%f\n",psprite->x,sprite->w,psprite->w,(float)sprite->w-((float)sprite->w/(float)num_w));
             psprite->x=0;
             psprite->y=0;
             psprite->w=sprite->w/num_w;
   // psprite->h=(int)sprite->h/num_h;
    }}
    else if (move ==1) {
         
    if (psprite->x>=sprite->w/num_w)
    {
        printf("%d\t%d\t%d\t%d\n",psprite->x,psprite->y,psprite->w,psprite->h );
         //psprite->y-=sprite->h/num_h;
        psprite->x-=sprite->w/num_w;
        //psprite->y=sprite->h;
    }
    else
    {
        psprite->x=(sprite->w/num_w)*(num_w-1);
         psprite->y=sprite->h/num_h;
    }
    }
}
