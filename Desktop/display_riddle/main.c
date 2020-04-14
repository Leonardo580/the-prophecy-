#include "Riddle.h"

int main ( void )
{
    enigme e;
    SDL_Surface *s=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    e=init_enigme();
    int score=-10;
    SDL_Init(SDL_INIT_EVERYTHING);
    while (1)
    {
    	//game_over("GAME OVER",s);
    	//printf("%p \n",e.image );printf(" %s %s\n",e.question,e.reponse );
    display_enigme(e,s,&score);

  //  SDL_BlitSurface (e.image,NULL,s,&e.pos);
  // SDL_Flip (s);
}


}
