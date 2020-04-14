#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include <time.h> 
#include <unistd.h>
#include "main1.c"

int main(){
	SDL_Surface *ecran=NULL,*background=NULL,*bplay=NULL,*beplay=NULL,*besetting=NULL,*bsetting=NULL,*bquit=NULL,*bequit=NULL,*bcredits=NULL,*becredits=NULL;
SDL_Rect positionecran,positionbplay,positionbsettings,positionbcredits,positionbquit;
	SDL_Event e;
	int continuer=1;
	int x,y;
Mix_Music *musique;
	background=IMG_Load("background.jpg");
	bplay=IMG_Load("play.png");
	beplay=IMG_Load("playe.png");
	bsetting=IMG_Load("option.png");
	besetting=IMG_Load("optione.png");
	bquit=IMG_Load("exit.png");
	bequit=IMG_Load("exite.png");
	bcredits=IMG_Load("credits.png");
	becredits=IMG_Load("creditse.png");


	positionecran.x=0;
	positionecran.y=0;

	positionbplay.x=20;
	positionbplay.y=20;

	positionbsettings.x=20;
	positionbsettings.y=130;
	
	positionbcredits.x=20;
	positionbcredits.y=240;

	positionbquit.x=750;
	positionbquit.y=10;

	

	SDL_Init(SDL_INIT_VIDEO);
    	ecran = SDL_SetVideoMode(900, 600, 32, SDL_HWSURFACE );
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)//Initialisation de l'API Mixer
    {
        printf ("%s",Mix_GetError());
    }

    Mix_VolumeMusic(MIX_MAX_VOLUME / 1); //Mettre le volume à 1 Pour la moitié remplacer Par 2
    musique =Mix_LoadMUS("music.mp3");//chargement de la musique
    
    Mix_Chunk *son;

    son = Mix_LoadWAV("click.wav");
Mix_PlayMusic(musique,-1);
	while(continuer){
		SDL_WaitEvent(&e);
		SDL_GetMouseState(&x,&y);
		if (e.type == SDL_QUIT)
            		continuer=0;

		if ((43<=x)&&(x<=246)&&(y<=140)&&(49<=y)){            Mix_PlayChannel(1, son, 0);
if(e.type == SDL_MOUSEBUTTONDOWN){jeuuuccc();}
			SDL_BlitSurface(background, NULL, ecran, &positionecran);
			SDL_BlitSurface(beplay, NULL, ecran, &positionbplay);
			SDL_BlitSurface(bsetting, NULL, ecran, &positionbsettings);
			SDL_BlitSurface(bcredits, NULL, ecran, &positionbcredits);
			SDL_BlitSurface(bquit, NULL, ecran, &positionbquit);
		}
		
		else if ((43<=x)&&(x<=246)&&(y<=246)&&(162<=y)){Mix_PlayChannel(1, son, 0);
			SDL_BlitSurface(background, NULL, ecran, &positionecran);
			SDL_BlitSurface(bplay, NULL, ecran, &positionbplay);
			SDL_BlitSurface(besetting, NULL, ecran, &positionbsettings);
			SDL_BlitSurface(bcredits, NULL, ecran, &positionbcredits);
			SDL_BlitSurface(bquit, NULL, ecran, &positionbquit);
		}
		
		else if ((43<=x)&&(x<=246)&&(y<=355)&&(276<=y)){Mix_PlayChannel(1, son, 0);
			SDL_BlitSurface(background, NULL, ecran, &positionecran);
			SDL_BlitSurface(bplay, NULL, ecran, &positionbplay);
			SDL_BlitSurface(bsetting, NULL, ecran, &positionbsettings);
			SDL_BlitSurface(becredits, NULL, ecran, &positionbcredits);
			SDL_BlitSurface(bquit, NULL, ecran, &positionbquit);
		}
		else if ((764<=x)&&(x<=886)&&(y<=88)&&(21<=y)){Mix_PlayChannel(1, son, 0);
			if(e.type == SDL_MOUSEBUTTONDOWN){continuer=0;}
			SDL_BlitSurface(background, NULL, ecran, &positionecran);
			SDL_BlitSurface(bplay, NULL, ecran, &positionbplay);
			SDL_BlitSurface(bsetting, NULL, ecran, &positionbsettings);
			SDL_BlitSurface(bcredits, NULL, ecran, &positionbcredits);
			SDL_BlitSurface(bequit, NULL, ecran, &positionbquit);
		}
		else {
			SDL_BlitSurface(background, NULL, ecran, &positionecran);
			SDL_BlitSurface(bplay, NULL, ecran, &positionbplay);
			SDL_BlitSurface(bsetting, NULL, ecran, &positionbsettings);
			SDL_BlitSurface(bcredits, NULL, ecran, &positionbcredits);
			SDL_BlitSurface(bquit, NULL, ecran, &positionbquit);
		}

		SDL_Flip(ecran);
		printf("%d \t %d \n",x,y);


	}


}
