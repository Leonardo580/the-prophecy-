#include "Riddle.h"

void  game_over(char ch[],SDL_Surface *ecran)
{
    SDL_Surface *gameover=NULL,*word;
    SDL_Color color={255,255,255};
    SDL_Rect word_pos;
    TTF_Font *font;
    TTF_Init();
    font=TTF_OpenFont("p.ttf",100);
    gameover=IMG_Load("game over.png");
    word_pos.x=(int) gameover->w/2;
    word_pos.y=(int) gameover->h/2;

    word=TTF_RenderText_Blended(font,ch,color);
    SDL_BlitSurface(gameover,NULL,ecran,NULL);
    int i=0;

       // while (1){
        if (i==0)
        {
            while (i<4){
            word_pos.x=(int) gameover->w/3+i*50;

            SDL_BlitSurface(word,NULL,ecran,&word_pos);
            SDL_Flip(ecran);
            i++;SDL_Delay(1000);
        }
        }
        else
        {
            while (i>0){
            word_pos.x=(int) gameover->w/3-i*50;
            SDL_BlitSurface(word,NULL,ecran,&word_pos);
            SDL_Flip(ecran);
            i--;SDL_Delay(1000);
        }

        }
        return;


}

enigme init_enigme()
{
	enigme e;
    e.image=IMG_Load("riddle.png");
    e.affenigme=0;
   // e.file=fopen("enigme.txt");
    e.pos.x=0;
    e.pos.y=0;
    e.testreponse=1;
    enigme_que_ans("enigme.txt",e.question,e.reponse);
    return e;

}
int display_enigme (enigme e,SDL_Surface *ecran ,int *score)
{

  int done=0;
  TTF_Font *font=NULL;
  TTF_Init();
  font=TTF_OpenFont("p.ttf",50);
  int i,a=0;
  SDL_Color color ={255,255,255};
  SDL_Surface *question=NULL;
  SDL_Surface *reponse[3];
  SDL_Rect reponse_pos[3];
  SDL_Rect question_pos;
  char ch[2][100],tmp[100];
  reponse[0]=TTF_RenderText_Blended(font,e.reponse,color);
   question_pos.x=e.image->w/2-400;question_pos.y=e.image->h/2-100;
  for (i=0;i<2;i++)
  {
      do
      {
          enigme_que_ans("enigme.txt",tmp,ch[i]);
      }while (strcmp(ch[i],e.reponse)==0);
  }
  for (i=1;i<3;i++) reponse[i]=TTF_RenderText_Blended(font,ch[i-1],color);
  
  for (i=0;i<3;i++) {
    reponse_pos[i].x=question_pos.x;
    reponse_pos[i].y=question_pos.y+100+i*50;
  }
  for (i=0;i<3;i++){
  	do{
  srand(time(NULL));
  a=rand()%3;
}while (a==i);
  printf("%d  %d    %d\n", a,reponse_pos[i].y,reponse_pos[a].y);
  reponse_pos[i].y=reponse_pos[i].y+reponse_pos[a].y;
  reponse_pos[a].y=reponse_pos[i].y-reponse_pos[a].y;
  reponse_pos[i].y=reponse_pos[i].y-reponse_pos[a].y;
  }

 

  question=TTF_RenderText_Blended(font,e.question,color);
  e.image=IMG_Load("riddle.png");

 SDL_BlitSurface(e.image,NULL,ecran,&e.pos);
  SDL_BlitSurface (question,NULL,ecran,&question_pos);
    for(i=0;i<3;i++){ SDL_BlitSurface(reponse[i],NULL,ecran,&reponse_pos[i]);printf("%p   %d\n",reponse[i],reponse_pos[i].y );}
  SDL_Flip (ecran);
  //printf("%p  %p\n",font,question );
  SDL_Event event;
  Uint8 *data,*mask ;
// *(data)=0;
  //*(mask)=1;
       SDL_Cursor *cursor=SDL_CreateCursor((Uint8*) 1,(Uint8*)0,8,8,question_pos.x,question_pos.y+100);
      SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
     //cursor=SDL_GetCursor();
      //SDL_Event event ;


 while (e.testreponse)

  {


      /*SDL_ShowCursor(SDL_ENABLE);
      SDL_SetCursor (cursor);
     // scanf(" %s",ch);
      SDL_WaitEvent(&event);
        strcat(ch,(char)event.key.keysym.unicode);
      if (strcmp(ch,e.reponse)==0)
      {
          e.image=IMG_Load("right.png");
          e.testreponse=0;
      }
      else
      {
          e.image=IMG_Load("Wrong.png");
         (*score)-=50;
      }*/
  	SDL_WaitEvent(&event );
  	switch(event.type)
  	{
  	    case SDLK_ESCAPE :return -1;
  	    case SDL_MOUSEBUTTONUP:
            if (event.button.button==SDL_BUTTON_LEFT)
            {
                if (event.button.x>reponse_pos[0].x && event.button.x<reponse_pos[0].x+reponse[0]->w && event.button.y>reponse_pos[0].y && event.button.y<reponse_pos[0].y+reponse[0]->h)
                   { game_over("Right",ecran);return 1;}
                else if (event.button.x>reponse_pos[1].x && event.button.x<reponse_pos[1].x+reponse[1]->w && event.button.y>reponse_pos[1].y && event.button.y<reponse_pos[1].y+reponse[1]->h || event.button.x>reponse_pos[2].x && event.button.x<reponse_pos[2].x+reponse[2]->w && event.button.y>reponse_pos[2].y && event.button.y<reponse_pos[2].y+reponse[2]->h)
                         {
                         	game_over("Wrong",ecran);
                         *score-=10;
                         return 0;
                         }
            }
  	}


      //SDL_BlitSurface(e.image,NULL,ecran,&e.pos);
      //SDL_Flip(ecran);

  }
  //sdl_freecursor(cursor);
   SDL_FreeCursor(cursor);
  SDL_FreeSurface(e.image);


}