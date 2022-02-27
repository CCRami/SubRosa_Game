#include"header.h"

int main(int argc, char *argv[])
 
{	SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_AUDIO );
	TTF_Init();
	SDL_EnableKeyRepeat(0, 0);
	SDL_Surface* screen;
  	int count=1;
  	int i=0;
  	int volume=100;
	bool IsFullscreen= false; //fullscreen or not 
	image start,settings,exit,music,gamelogo,score;
	image tabimg[35];
	SDL_Event event;
	int position = 1,settingsverif=0,playverif=0,musicverif=1;
	//load music
	if( Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0 )
    {
        printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    	Mix_Music *musique=Mix_LoadMUS("1x/musique.mp3");
	Mix_Chunk *chunk= Mix_LoadWAV ("1x/CLIC.wav");
	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32,SDL_HWSURFACE);
	if ( !screen ) {
		printf("Unable to set 1920x1080 video: %s\n", SDL_GetError());
		return 1;}
	TTF_Font * font = TTF_OpenFont("ARIAL.ttf", 80);
	SDL_Color color = { 255, 0, 0 };
	//bonus
	SDL_WM_SetCaption("Sub Rosa", NULL);
	//text 2
	TTF_Font * font1 = TTF_OpenFont("ARIAL.ttf", 30);
	SDL_Surface * message1 = TTF_RenderText_Solid(font1,"Press p", color);
	SDL_Rect Message_rect1;
	Message_rect1.x = 1770;  
	Message_rect1.y = 180;
	//initialisation
	//initBackground(&backg);
	initButtons(&start,&settings,&exit,&music,&score,&gamelogo);
	initanimation(tabimg);
	Mix_PlayMusic(musique,-1);
	
	while (1)
	{
		i++;
		if (i==36)
			i=0;
		
		afficher(tabimg[i],screen);
		afficher(start,screen);
		afficher(settings,screen);
		afficher(exit,screen);
		afficher(music,screen);
		afficher(gamelogo,screen);
		afficher(score,screen);
		if ((playverif==0)&&(settingsverif==0))
			{//SDL_BlitSurface(message,NULL,screen,&Message_rect);
			SDL_BlitSurface(message1,NULL,screen,&Message_rect1);}
		
		SDL_Flip(screen);
		while (SDL_PollEvent(&event))
		{switch (event.type)
		{
		case SDL_QUIT:
		{
			SDL_FreeSurface(screen);
			libereranimation (tabimg);
			libererButtons(start,settings, exit,music,score,gamelogo);
			closeEverything();
			return 0;
		break;
		}
		case SDL_MOUSEMOTION:
    		{
       	 int x=0, y=0 ;
      		//Get the mouse offsets
      		SDL_GetMouseState(&x,&y);
        	//If the mouse is over the button
        	if ((playverif==0)&&(settingsverif==0))
       	 {if( ( x > start.pos.x ) && ( y > start.pos.y) && ( x < (start.pos.x+365) ) && ( y < (start.pos.y+177)))
       	 {		position=1;
       	 		afficherparposition(position, &start,&settings,&score, &exit);
       	 }
       	 if( ( x > settings.pos.x ) && ( y > settings.pos.y) && ( x < (settings.pos.x+365) ) && ( y < (settings.pos.y+177)))
       	 {		position=2;
       	 		afficherparposition(position, &start,&settings,&score, &exit);
       	 }
       	  if( ( x > score.pos.x ) && ( y > score.pos.y) && ( x < (score.pos.x+365) ) && ( y < (score.pos.y+177)))
       	 {		position=3;
       	 		afficherparposition(position, &start,&settings,&score, &exit);
       	 }
       	 
       	 if( ( x > exit.pos.x ) && ( y > exit.pos.y) && ( x < (exit.pos.x+260) ) && ( y < (exit.pos.y+124)))
       	 {
       	 		position=4;
       	 		afficherparposition(position, &start,&settings,&score, &exit);
       	 }
       	 
       	 }
       	 break;
       	 }
		case SDL_KEYDOWN:
		{
		switch (event.key.keysym.sym)
		{
			case SDLK_f:
           		count++;
			if (count%2==1)
				{IsFullscreen=false;}
			else
				{IsFullscreen=true;}
                      	if (IsFullscreen==true)
				{screen=SDL_SetVideoMode (SCREEN_W,SCREEN_H,32,SDL_HWSURFACE|SDL_FULLSCREEN);	}
			else
				{screen=SDL_SetVideoMode (SCREEN_W,SCREEN_H,32,SDL_HWSURFACE|SDL_DOUBLEBUF);	}
			break ;	
			case SDLK_p:
			
				if (!Mix_PlayingMusic())
					{
					Mix_PlayMusic(musique,-1);
					music.img=IMG_Load("1x/Musicon.png");
					musicverif=1;
					}
				else if (Mix_PausedMusic())
					{
					Mix_ResumeMusic();
					music.img=IMG_Load("1x/Musicon.png");
					musicverif=1;
					}
				else
					{
					Mix_PauseMusic();
					music.img=IMG_Load("1x/Musicoff.png");
					musicverif=0;
					}
			
			break;
			case SDLK_UP:
				if ((playverif==0)&&(settingsverif==0))
				{position--;
				if (position == 0)
				{position = 4;
				afficherparposition(position, &start,&settings,&score, &exit);
				}
				else if (position==3)
				{
				afficherparposition(position, &start,&settings,&score, &exit);
				}
				else if (position==2)
				{
				afficherparposition(position, &start,&settings,&score, &exit);
				}
				else if (position==1)
				{
				afficherparposition(position, &start,&settings,&score, &exit);
				}}
				
			break;
			case SDLK_DOWN:
				if ((playverif==0)&&(settingsverif==0))
				{position++;
				if (position == 5)
				{position = 1;
				afficherparposition(position, &start,&settings,&score, &exit);
				}
				else if (position==2)
				{
				afficherparposition(position, &start,&settings,&score, &exit);
				}
				else if (position==3)
				{
				afficherparposition(position, &start,&settings,&score, &exit);
				}
				else if (position==4)
				{
				afficherparposition(position, &start,&settings,&score, &exit);
				}
				}
			break;
			case SDLK_RETURN:
				if (position==1)
				{
				Mix_PlayChannel(-1,chunk,0);
				playverif=1;
				playverif=paintOptionsScreenagent (screen,&event,chunk);
				}
				else if (position==2)
				{
				Mix_PlayChannel(-1,chunk,0);
				settingsverif=1;
				settingsverif=paintOptionsScreen(screen,&event,chunk,&volume);
				}
				else if (position==3)
				{
				//Score
				}
				else if (position==4)
				{
				Mix_PlayChannel(-1,chunk,0);
				SDL_FreeSurface(screen);
				libereranimation (tabimg);
				libererButtons(start,settings, exit,music,score,gamelogo);
				closeEverything();
				return 0;
				}
			break;
			case SDLK_ESCAPE:
			if (playverif==1)
			{
			playverif=0;
			//backg.img = IMG_Load("1x/img.jpg");
			start.img = IMG_Load("1x/Startselected.png");
			settings.img=IMG_Load("1x/Settingsunselected.png");
			exit.img = IMG_Load("1x/Quitunselected.png");
			if (musicverif==1)
				music.img=IMG_Load("1x/Musicon.png");
			else
				music.img=IMG_Load("1x/Musicoff.png");
			}
			else if (settingsverif==1)
			{
			settingsverif=0;
			//backg.img = IMG_Load("1x/img.jpg");
			start.img = IMG_Load("1x/Startunselected.png");
			settings.img= IMG_Load("1x/Settingsselected.png");
			exit.img = IMG_Load("1x/Quitunselected.png");
			if (musicverif==1)
				music.img=IMG_Load("1x/Musicon.png");
			else
				music.img=IMG_Load("1x/Musicoff.png");
			}
			else
			{
			SDL_FreeSurface(screen);
			libereranimation (tabimg);
			libererButtons(start,settings, exit,music,score,gamelogo);
			closeEverything();
			return 0;
			}
			break;	
		}

		break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
		 int x=0, y=0 ;
      		//Get the mouse offsets
      		SDL_GetMouseState(&x,&y);
		if ((playverif==0)&&(settingsverif==0))
			{if ((position==1)&& ( x > start.pos.x ) && ( y > start.pos.y) && ( x < (start.pos.x+365) ) && ( y < (start.pos.y+177)))
				{
				Mix_PlayChannel(-1,chunk,0);
				playverif=1;
				playverif=paintOptionsScreenagent (screen,&event,chunk);
				
				}
			else if ((position==2)&&( x > settings.pos.x ) && ( y > settings.pos.y) && ( x < (settings.pos.x+365) ) && ( y < (settings.pos.y+177)))
				{
				Mix_PlayChannel(-1,chunk,0);
				settingsverif=1;
				settingsverif=paintOptionsScreen(screen,&event,chunk,&volume);
				
				
				}
				
			else if( ( x > score.pos.x ) && ( y > score.pos.y) && ( x < (score.pos.x+365) ) && ( y < (score.pos.y+177)))
       			 {
       	 			//Score Affichage
       			 }
       			 
			else if ((position==4)&&( x > exit.pos.x ) && ( y > exit.pos.y) && ( x < (exit.pos.x+260) ) && ( y < (exit.pos.y+124)))
				{
				Mix_PlayChannel(-1,chunk,0);
				SDL_FreeSurface(screen);
				libereranimation (tabimg);
				libererButtons(start,settings, exit,music,score,gamelogo);
				closeEverything();
				return 0;
				}}
		break;
		}
                      
}
}
		SDL_Delay (20);	
	}
	SDL_FreeSurface(screen);
	SDL_FreeSurface(message1);
	libereranimation (tabimg);
	libererButtons(start,settings, exit,music,score,gamelogo);
	TTF_CloseFont(font);
	Mix_FreeChunk (chunk);
	Mix_FreeMusic (musique);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
	return 0;
}
// gcc main.c -lSDL -lSDL_image -lSDL_mixer -o Game -g
