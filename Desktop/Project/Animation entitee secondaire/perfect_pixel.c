#include "collision.h"
SDL_Color getpixel(SDL_Surface *s,int x,int y)
{
    SDL_Color color;
    Uint32 col=0;
    char *ppos=(char*) s->pixels;
    ppos+=(s->pitch*y);
    ppos+=s->format->BytesPerPixel*x;
    memcpy(&col,ppos,s->format->BytesPerPixel);
    SDL_GetRGB(col,s->format,&color.r,&color.g,&color.b);
    return color;
}
int collision_parfaite(SDL_Surface *per ,SDL_Rect pos_per,SDL_Surface *bgmask)
{
    int i,j;
    SDL_Color color={0,0,0};
    int posx[]={pos_per.x,per->w/2+pos_per.x,per->w+pos_per.x},posy[]={pos_per.y,per->h/2+pos_per.y,per->h+pos_per.y};
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%d\t%d\t%d\n",getpixel(bgmask,posx[i],posy[i]).r,posx[i],posy[i]);
            if (getpixel(bgmask,posx[i],posy[i]).r==color.r && getpixel(bgmask,posx[i],posy[i]).g==color.g && getpixel(bgmask,posx[i],posy[i]).b==color.b) return 1;
        }
    }
    return 0;
}
