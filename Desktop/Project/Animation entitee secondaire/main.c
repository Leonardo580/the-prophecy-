#include "collision.h"
int main()
{
    SDL_Surface *s=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF),*bgmask=IMG_Load("bgmask.png"),*per=IMG_Load ("per.png");
    SDL_Rect pos_per,psprite;
    SDL_Surface *sprite=IMG_Load("sprite sheet.png");
    SDL_Event event;
    int x;
    pos_per.x=200;
    pos_per.y=300;

    SDL_BlitSurface (bgmask,NULL,s,NULL);
   // SDL_BlitSurface (per,NULL,s,&pos_per);
      init_anim_sec(sprite,&psprite,4,2,1);
    SDL_Flip(s);
    while (1)

    {
     
        //SDL_WaitEvent(&event);
         //if(event.key.keysym.sym==SDLK_RIGHT){
       // case event.key.keysym.sym:
        //if(SDLK_RIGHT)
          //  pos_per.x+=50;
          
   // if (collision_parfaite(per ,pos_per,bgmask)==1) printf("collision detected ");
    //else printf("you fuck it up \n");
           SDL_BlitSurface (bgmask,NULL,s,NULL);
    SDL_BlitSurface(sprite,&psprite,s,&pos_per);
   animation_entitee_secondaire(sprite,&psprite,4,2,1);
   pos_per.x+=20;
    //SDL_BlitSurface (bg,NULL,bgmask,NULL);
   // SDL_BlitSurface (per,NULL,s,&pos_per);
   // printf("fucking piece of shit </> %d\t%d\t%d\t%d\n",psprite.x,psprite.y,psprite.w,psprite.h);
    SDL_Flip(s);
    SDL_Delay(1000);
}
SDL_FreeSurface (s);

}
