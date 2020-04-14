

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <ctype.h>
/* Start the timer; the callback below will be executed after the delay */


int main (  )

{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
    TTF_Font *font=NULL;
    font=TTF_OpenFont("/home/anas/Desktop/test123/pix.ttf",60);
    if (font==NULL) printf("failed to load ttf (fuck my life ) %S\n", TTF_GetError);
    SDL_Surface *s=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF),*image,*bg=IMG_Load("bgmask.png");
    char ch[50]="30",*c;
    SDL_Rect pos;
    pos.x=pos.y=100;

    SDL_Color color ={0,0,0};
    image=TTF_RenderText_Blended(font,ch,color);
Uint32 time1,time2=30;

    while (1)
    {

    time1=SDL_GetTicks()/1000;
    //SDL_Delay(10);
     //printf("%d\t%x\n",time2-time1,font);
     if (time2-time1==0) {
            //c=(char*)realloc(ch,sizeof(char)*strlen("you lost"));
     strcpy(ch,"you lost");
     image=TTF_RenderText_Blended(font,ch,color);
    SDL_BlitSurface (bg,NULL,s,NULL);
    SDL_BlitSurface(image,NULL,s,&pos);
    SDL_Flip(s);
    SDL_Delay (3000);
    return 0;
     }
   // itoa(time2-time1,ch,10);
     sprintf(ch,"%d",time2-time1);
    image=TTF_RenderText_Blended(font,ch,color);
    SDL_BlitSurface (bg,NULL,s,NULL);
    SDL_BlitSurface(image,NULL,s,&pos);
    SDL_Flip(s);
    sprintf(ch,"%d",time2-time1);


    }

}
