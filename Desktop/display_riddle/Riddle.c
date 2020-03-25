#include "Riddle.h"

void  game_over(char ch[],SDL_Surface *ecran)
{
    SDL_Surface *gameover=NULL,*word;
    SDL_Color color={255,255,255};
    SDL_Rect word_pos;
    TTF_Font *font;
    font=TTF_OpenFont("p.ttf",50);
    word_pos.x=(int) gameover->w/2;
    word_pos.y=(int) gameover->h/2;
    gameover=IMG_Load("game over.png");
    word=TTF_RenderText_Blended(font,ch,color);
    SDL_BlitSurface(gameover,NULL,ecran,NULL);
    int i=0;

        while (1){
        if (i==0)
        {
            while (i<4){
            word_pos.x=(int) gameover->w/2+i*20;

            SDL_BlitSurface(gameover,NULL,ecran,&word_pos);
            i++;SDL_Delay(1000);
        }
        }
        else
        {
            while (i>0){
            word_pos.x=(int) gameover->w/2-i*20;
            SDL_BlitSurface(gameover,NULL,ecran,&word_pos);
            i--;SDL_Delay(1000);
        }
        }}


}
int display_enigme (enigme e,SDL_Surface *ecran ,int *score)
{
  int done=0;
  TTF_Font *font;
  font=TTF_OpenFont("p.ttf",50);
  int a;
  SDL_Surface *question;
  SDL_Rect question_pos;
  char ch[100];
  question_pos.x=100;question_pos.y=100;
  SDL_Color color ={255,255,255};
  question=TTF_RenderText_Blended(font,e.question,color);
  SDL_BlitSurface (question,NULL,ecran,&question_pos);
  SDL_Event event;
  while (e.testreponse)
  {
      SDL_Cursor *cursor=SDL_CreateCursor(32,32,1,15,20,20);
      SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
      SDL_ShowCursor(SDL_ENABLE);
      scanf(" %s",ch);
      if (strcmp(ch,e.reponse)==0)
      {
          e.image=IMG_Load("right.png");
          e.testreponse=0;
      }
      else
      {
          e.image=IMG_Load("Wrong.png");
         (*score)-=50;
      }
      if (score<=0) {game_over("GAME OVER",ecran);e.testreponse=0;}
      SDL_BlitSurface(e.image,NULL,ecran,&e.pos);

  }
  //sdl_freecursor(cursor);
  SDL_FreeSurface(e.image);


}
