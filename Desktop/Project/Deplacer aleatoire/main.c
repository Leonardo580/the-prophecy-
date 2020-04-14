//#include "collision.h"
#include "deplacer_aleatoire.h"

int main()
{
    SDL_Surface *s=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF),*bgmask=IMG_Load("bgmask.png"),*per=IMG_Load ("per.png");
    SDL_Rect pos_per,psprite;
    SDL_Surface *sprite=IMG_Load("sprite sheet.png");
    SDL_Event event;
    int x;
    entity e=init_entity("per.png");
    pos_per.x=200;
    pos_per.y=300;
    //SDL_BlitSurface (bgmask,NULL,s,NULL);
    //SDL_BlitSurface (sprite,NULL,s,&pos_per);

    SDL_Flip(s);
    while (1)

    {   printf("%d   %d\n",e.pos_objet.x,e.direction );
        //SDL_WaitEvent(&event);
         //if(event.key.keysym.sym==SDLK_RIGHT){
       // case event.key.keysym.sym:
        //if(SDLK_RIGHT)
          //  pos_per.x+=50;
 

       e= deplacer_entity (e);
    
   // SDL_BlitSurface (bgmask,NULL,s,NULL);
    //SDL_BlitSurface (bg,NULL,bgmask,NULL);
   
    SDL_Delay(100);
      //SDL_Flip(s);
  SDL_BlitSurface (e.objet,NULL,s,&e.pos_objet);
    SDL_Flip(s);
}
SDL_FreeSurface (s);

}
