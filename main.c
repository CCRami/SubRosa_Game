#include"header.h"
int arduinoWriteData(int x);
int arduinoReadData(int *x);
int main(int argc, char *argv[])
 
{	SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_AUDIO );
	TTF_Init();
	image playon ,playoff;
	playon.img=IMG_Load("1x/xoselected.png");
	playoff.img=IMG_Load("1x/xounselected.png");
	playon.pos.x=1500;
	playon.pos.y=700;
	playoff.pos.x=1500;
	playoff.pos.y=700;
	SDL_Surface* screen;
	int gamemode=0;
	int enigmemode=0;
  	int count=1;
  	int pic=1;
  	int rangex=0,rangey=0;
int received;
int test=0;
	int input=1;
	int choice=1;
  	int duo=0;
  	int i=0,j=0;
	int meilleurscore;
	char meilleurnom[20];
  	int volume=100;
	bool IsFullscreen= false; //fullscreen or not 
	image start,settings,exit,music,gamelogo,score;
	image tabimg[36],tabintro[52];
	SDL_Event event,event1;
	int position = 1,settingsverif=0,playverif=0,musicverif=1,scoreverif=0,xoverif=0;
	int t,a=1,an=1;
	system("stty -F /dev/ttyUSB0 9600 -parenb cs8 -cstopb");
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
	TTF_Font * font1 = TTF_OpenFont("SF_TransRobotics_Bold.ttf", 30);
	SDL_Surface * message1 = TTF_RenderText_Solid(font1,"Press p", color);
	SDL_Rect Message_rect1;
	Message_rect1.x = 1770;  
	Message_rect1.y = 180;
SDL_Surface * mess = TTF_RenderText_Solid(font1,"entrer le nom:", color);
SDL_Rect Mess_rect1;
	Mess_rect1.x = 500;  
	Mess_rect1.y = 200;
//nomaff
SDL_Surface *messagescore;
	SDL_Rect message02;
	message02.x = 400;  
	message02.y = 400;
TTF_Font * font3 = TTF_OpenFont("SF_TransRobotics_Bold.ttf", 50);
//scoreaff
SDL_Surface *messagemeilleur;
	SDL_Rect message01;
	message01.x = 600;  
	message01.y = 400;
//perso init
SDL_Surface *backg=NULL,*youwon;
SDL_Rect pos_backg;
youwon=IMG_Load("youwon.png");
int standing,keypressed=0;
personne perso,perso1;
TTF_Init();
//fps variable 
Uint32 startt;
int FPS=13;
// INIT SCREEN :
SDL_Init(SDL_INIT_VIDEO);	
SDL_WM_SetCaption("SUBROSA",NULL);
   if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
	  printf("Unable to initialize SDL :%s \n",SDL_GetError());
	  return 1;
	}

	screen =SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	if ( !screen ) {
		printf("Unable to set 1920x1080 video: %s\n", SDL_GetError());
		return 1;}
	pos_backg.x=0;
	pos_backg.y=0;
backg=IMG_Load("backg/desert.png");

initPerso(&perso);
initPerso2(&perso1);
//minimap init
SDL_Rect camera;

minimap minibackg;
unsigned int timee=0;
char temps[4];
char temps1[4];
image A;
// text 

	//sprintf (temps,"%d",time);
	SDL_Surface *message2;
	SDL_Rect Message;
	Message.x = 1590;  
	Message.y = 20;
SDL_Surface *messagenom;
	SDL_Rect Messagen;
	Messagen.x = 800;  
	Messagen.y = 500;

//initminimap (&minibackg,&perso,b.camera);

A.img= IMG_Load ("fond.png");
if (A.img == NULL) {
		printf("Unable to load : %s\n", SDL_GetError());
		return 0;
		}
char ch[10];
A.pos.x=0;
A.pos.y=0;
int sec=0;
int min=0;
char nom[20];
SDL_Surface *message3;
	SDL_Rect Messagem;
	Messagem.x = 1550;  
	Messagem.y = 20;
strcpy(nom,"");
int verif=0;
//init ets
	/*SDL_Surface *sorry ;
	SDL_Rect pos_sorry ; 
	sorry=IMG_Load("youlost.png");
	pos_sorry.x=300;
	pos_sorry.y=300;*/
	entity e;
	Ennemie en;
	initentity (&e) ;
	initEnnemi (&en) ;
//init enigmetf
	enigmetf eg;
	InitEnigme(&eg, "fichier.txt");
// init enigmeif
		char *nomfichier[100];
		enigmeif ee;
		ee.d=1;
		generer(&ee);
		InitEnigmeif(&ee ,&nomfichier[100]);
//init background
	    background b;
	    SDL_Surface *mask;
	    mask = IMG_Load("background resources/desertmask.png");
	    int direction = 'N',direction1 = 'N', vitesse = 0,vitesse1=0;
	    int resx = 1920, resy = 1080;
	    int bgw = 5000, bgh = 1080;
	    int persow = 195, persoh = 195;
	    initBack(&b, resx, resy);
	//initialisation
	//initBackground(&backg);
	initButtons(&start,&settings,&exit,&music,&score,&gamelogo);
	initanimation(tabimg,tabintro);
	Mix_PlayMusic(musique,-1);
	//SDL_putenv("SDL_VIDEODRIVER=directx");
	while (1)
	{
if (enigmemode==0)
{
perso.state=idle;

}
		if (gamemode==0)//intro
		{
		i++;
		if (i==52)
		{
			gamemode=1;
			i=0;
		}
		afficher(tabintro[i],screen);
		SDL_Flip(screen);
		SDL_Delay(35);
		}
		if (gamemode==1)//menu
		{
		i++;
		if (i==36)
			i=0;
		perso.score=0;
		sec=0;
		min=0;
		input=1;
		choice=1;
		duo=0;
		pic=1;
		afficher(tabimg[i],screen);
		afficher(start,screen);
		afficher(settings,screen);
		afficher(exit,screen);
		afficher(music,screen);
		afficher(gamelogo,screen);
		afficher(score,screen);
        	afficher(playoff,screen);
		if ((playverif==0)&&(settingsverif==0)&&(scoreverif==0)&&(xoverif==0))
			{//SDL_BlitSurface(message,NULL,screen,&Message_rect);
			SDL_BlitSurface(message1,NULL,screen,&Message_rect1);}
		
		SDL_Flip(screen);
		while (SDL_PollEvent(&event))
		{switch (event.type)
		{
		case SDL_QUIT:
		{
			SDL_FreeSurface(screen);
			libereranimation (tabimg,tabintro);
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
        	if ((playverif==0)&&(settingsverif==0)&&(scoreverif==0)&&(xoverif==0))
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
 	 if( ( x > playoff.pos.x ) && ( y > playoff.pos.y) && ( x < (playoff.pos.x+365) ) && ( y < (playoff.pos.y+177)))
       	 {
       	 		//SDL_BlitSurface(playon.img,NULL,screen,&playon.pos);
			afficher(playon,screen);
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
				if ((playverif==0)&&(settingsverif==0)&&(scoreverif==0)&&(xoverif==0))
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
				if ((playverif==0)&&(settingsverif==0)&&(scoreverif==0)&&(xoverif==0))
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
				playverif=paintOptionsScreenagent (screen,&event,chunk,&gamemode,&duo,&pic,&input,&choice);
				if (pic==2)
					{
					perso.hero_right = IMG_Load("hero/personnageD_red.png");
					perso.hero_left = IMG_Load("hero/personnageG_red.png");
					}
				}
				else if (position==2)
				{
				Mix_PlayChannel(-1,chunk,0);
				settingsverif=1;
				settingsverif=paintOptionsScreen(screen,&event,chunk,&volume);
				}
				else if (position==3)
				{
				Mix_PlayChannel(-1,chunk,0);
				scoreverif=1;
				meilleur ("score.txt",&meilleurscore,meilleurnom);
				scoreverif=rollscore (screen,&event,meilleurnom,meilleurscore);
				
		

				}
				else if (position==4)
				{
				Mix_PlayChannel(-1,chunk,0);
				SDL_FreeSurface(screen);
				libereranimation (tabimg,tabintro);
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
			afficher(playoff,screen);
			if (musicverif==1)
				music.img=IMG_Load("1x/Musicon.png");
			else
				music.img=IMG_Load("1x/Musicoff.png");
			}
			else if (settingsverif==1)
			{
			settingsverif=0;
			start.img = IMG_Load("1x/Startunselected.png");
			settings.img= IMG_Load("1x/Settingsselected.png");
			exit.img = IMG_Load("1x/Quitunselected.png");
			afficher(playoff,screen);
			if (musicverif==1)
				music.img=IMG_Load("1x/Musicon.png");
			else
				music.img=IMG_Load("1x/Musicoff.png");
			}
			else if (scoreverif==0)
		        {

			scoreverif=0;
			start.img = IMG_Load("1x/Startunselected.png");
			settings.img= IMG_Load("1x/Settingsunselected.png");
			score.img= IMG_Load("1x/Scoreselected.png");
			exit.img = IMG_Load("1x/Quitunselected.png");
			afficher(playoff,screen);
			if (musicverif==1)
				music.img=IMG_Load("1x/Musicon.png");
			else
				music.img=IMG_Load("1x/Musicoff.png");
			}
			else if (xoverif==1)
		        {

			xoverif=0;
			start.img = IMG_Load("1x/Startselected.png");
			settings.img= IMG_Load("1x/Settingsunselected.png");
			score.img= IMG_Load("1x/Scoreunselected.png");
			exit.img = IMG_Load("1x/Quitunselected.png");
			afficher(playoff,screen);
			if (musicverif==1)
				music.img=IMG_Load("1x/Musicon.png");
			else
				music.img=IMG_Load("1x/Musicoff.png");
			}
			
			else
			{
			SDL_FreeSurface(screen);
			libereranimation (tabimg,tabintro);
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
				playverif=paintOptionsScreenagent (screen,&event,chunk,&gamemode,&duo,&pic,&input,&choice);
				if (pic==2)
					{
					perso.hero_right = IMG_Load("hero/personnageD_red.png");
					perso.hero_left = IMG_Load("hero/personnageG_red.png");
					}
			
				}
			else if ((position==2)&&( x > settings.pos.x ) && ( y > settings.pos.y) && ( x < (settings.pos.x+365) ) && ( y < (settings.pos.y+177)))
				{
				Mix_PlayChannel(-1,chunk,0);
				settingsverif=1;
				settingsverif=paintOptionsScreen(screen,&event,chunk,&volume);
				
				
				}
				
			else if( ( x > score.pos.x ) && ( y > score.pos.y) && ( x < (score.pos.x+365) ) && ( y < (score.pos.y+177)))
       			 {
       	 			Mix_PlayChannel(-1,chunk,0);
				scoreverif=1;
				meilleur ("score.txt",&meilleurscore,meilleurnom);
				scoreverif=rollscore (screen,&event,meilleurnom,meilleurscore);
       			 }
       			 
			else if ((position==4)&&( x > exit.pos.x ) && ( y > exit.pos.y) && ( x < (exit.pos.x+260) ) && ( y < (exit.pos.y+124)))
				{
				Mix_PlayChannel(-1,chunk,0);
				SDL_FreeSurface(screen);
				libereranimation (tabimg,tabintro);
				libererButtons(start,settings, exit,music,score,gamelogo);
				closeEverything();
				return 0;
				}
			else if( ( x > playoff.pos.x ) && ( y > playoff.pos.y) && ( x < (playoff.pos.x+365) ) && ( y < (playoff.pos.y+177)))
       	 {
       	 		//SDL_BlitSurface(playon.img,NULL,screen,&playon.pos);
			Mix_PlayChannel(-1,chunk,0);
			afficher(playon,screen);
			xoverif=1;
			xoverif=play(screen);

       	 }
       	 
}
		break;
		}
                      
}
}
}//gamemode1
if (gamemode==2)
{
j=0;
SDL_EnableKeyRepeat(0, 2000);
	if ((verif==0)&&(choice==1))
{
SDL_BlitSurface (A.img,NULL,screen,&A.pos);
SDL_BlitSurface(mess,NULL,screen,&Mess_rect1);
ajouternom(screen,nom,event);	
messagenom = TTF_RenderText_Solid(font,nom, color);
SDL_BlitSurface (messagenom,NULL,screen,&Messagen);
SDL_Flip (screen);
SDL_Delay(40);
}
while (SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_QUIT:
return 0;
break;
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
			{ 
case SDLK_RETURN:
verif=1;
timee=0;
sauvgarder (perso.score, nom , "score.txt",gamemode);
break;
}
}
}
if (verif==1)
{
//jeu 
timee= SDL_GetTicks();
min=(timee/60000);
sec=(timee/1000)-60*min;

if (min<10)
{
 sprintf (temps1,"0%d:",min);
}
else 
{
sprintf (temps1,"%d:",min);
}

if (sec<10)
{
 sprintf (temps,"0%d",sec);
}
else 
{
sprintf (temps,"%d ",sec);
}
message2 = TTF_RenderText_Solid(font1,temps, color);
message3 = TTF_RenderText_Solid(font1,temps1, color);
//initminimap (&minibackg,&perso);
//initminimap (&minibackg,&perso,b.camera);
afficherBack(b, screen, resx, resy);
SDL_BlitSurface (message2,NULL,screen,&Message);
SDL_BlitSurface (message3,NULL,screen,&Messagem);	
afficherminimap (minibackg,screen);
keypressed=0;
if (choice==2)
{
charger(&perso, &b , "test.txt",&min , &sec);
choice=1;
}
	//quitter
	while(SDL_PollEvent(&event1)){
			switch(event1.type)
		   {
			case SDL_QUIT:
			return 0;
			break;
			case SDL_KEYDOWN:
			if(event1.key.keysym.sym==SDLK_ESCAPE)
				{
				gamemode=1;
				a=1,an=1;
				sauvegarder(perso, b, "test.txt",min,sec);
				}
			if (event1.key.keysym.sym==SDLK_f)
           		{
           		count++;
			if (count%2==1)
				{IsFullscreen=false;}
			else
				{IsFullscreen=true;}
                      	if (IsFullscreen==true)
				{screen=SDL_SetVideoMode (1920,1080,32,SDL_HWSURFACE|SDL_FULLSCREEN);	}
			else
				{screen=SDL_SetVideoMode (1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);	}
			}	
			break;
		   }
		}
	// if we pressed a key= no idle spirit loaded
	if (!keypressed)
	{	
		if(perso.state!=jumping && perso.state!=doublejumping && perso.state!=die && perso.state!=crouch && perso.pos_hero.y==800)
		{
			srand(time(NULL));
			standing= (rand()%(3));
			randomizer(&perso,standing);
		}
		if(duo==1 && perso1.state!=jumping && perso1.state!=doublejumping && perso1.state!=die && perso1.state!=crouch && perso1.pos_hero.y==800)
		{
			srand(time(NULL));
			standing= (rand()%(3));
			randomizer(&perso1,standing);
		}
	}




/*if(perso.health<=0)perso.death=1;
if(perso.death==1){
perso.state=die;
//sauvgarder (perso.score, nom , "score.txt",perso);
//gamemode=1;
}*/
	const Uint8 *key= SDL_GetKeyState(NULL);//Gets a snapshot of the current keyboard state
if((!perso.death)&&(!perso1.death)&&(enigmemode==0))//if the person is not dead
{
if (input==1)
{
	if(key[SDLK_UP]) //jumping key
	{
		if((perso.jump_count>=0 && perso.jump_count<=1) && (perso.pos_hero.y<=800 && perso.pos_hero.y>=650))
		{
			perso.jump_count++; 
			perso.score+=10;
			saut(&perso);
		}
	}
	//if the person jumped and got down again
	if(perso.jump_count>=2 && perso.pos_hero.y==800) perso.jump_count=0;
	//if the person jumped once
	if(perso.pos_hero.y<800 && perso.pos_hero.y>=650) 
	 {
		perso.state=jumping;
	 }
	 //if the person jumped twice
	else if(perso.pos_hero.y<650 && perso.pos_hero.y>=500) 
	{
		perso.state=doublejumping;
	}
	
	if(key[SDLK_RIGHT])//moving right key
	{	direction = 'R';
		if (perso.pos_hero.x >= resx - persow)
                    {
                        perso.pos_hero.x = resx - persow;
                        vitesse = 0;
                        b.camera.x = bgw - resx;
                    }
                    else
                        vitesse = perso.vitesse+perso.acceleration;
		keypressed=1;
		perso.score+=1;
		if(perso.state!=doublejumping && perso.state!=doublejumping) 
			perso.state=walking;
		perso.direction=0;
		//deplacerPerso(&perso);
	}
	else
		vitesse=0;
	if(key[SDLK_LEFT]) //moving left key
	{	direction = 'L';
		if (perso.pos_hero.x <= 0)
                    {
                        perso.pos_hero.x = 0;
                        vitesse = 0;
                        b.camera.x = 0;
                    }
                 else
                        vitesse = perso.vitesse+perso.acceleration;
		keypressed=1;
		if(perso.state!=jumping && perso.state!=doublejumping) 
			perso.state=walking;
		perso.direction=1;
		//deplacerPerso(&perso);
	}
	if(key[SDLK_RSHIFT]) // acceleration key
	{
		if(perso.acceleration<20)
		 perso.acceleration+=5;
	}
	else
	{	while (perso.acceleration!=0)
		{
			perso.acceleration-=20;	
		}
	}
	if(key[SDLK_DOWN]) //crouching key
	{
		if(perso.frame_c==1) perso.frame_c=0;
		perso.state=crouch;	
	}
	if(key[SDLK_SPACE]) // attacking key
	{
		perso.state=attacking;
		if(perso.direction==0)
		perso.pos_hero.x+=2;
		else if(perso.direction==1)
		perso.pos_hero.x-=2;
		perso.score+=2;
	}
	
	if(key[SDLK_h]) // hit key (test)
	{
		perso.state=hit;
		perso.health-=10;
		perso.score-=20;
	}
	if (duo==1)
	{
	if(key[SDLK_z]) //jumping key
	{
		if((perso1.jump_count>=0 && perso1.jump_count<=1) && (perso1.pos_hero.y<=800 && perso1.pos_hero.y>=650))
		{
			perso1.jump_count++; 
			perso1.score+=10;
			saut(&perso1);
		}
	}
	//if the person jumped and got down again
	if(perso1.jump_count>=2 && perso1.pos_hero.y==800) perso1.jump_count=0;
	//if the person jumped once
	if(perso1.pos_hero.y<800 && perso1.pos_hero.y>=650) 
	 {
		perso1.state=jumping;
	 }
	 //if the person jumped twice
	else if(perso1.pos_hero.y<650 && perso1.pos_hero.y>=500) 
	{
		perso1.state=doublejumping;
	}
	
	if(key[SDLK_d])//moving right key
	{	direction1 = 'R';
		if (perso1.pos_hero.x >= resx - persow)
                    {
                        perso1.pos_hero.x = resx - persow;
                        vitesse1 = 0;
                        b.camera.x = bgw - resx;
                    }
                    else
                        vitesse1 = perso1.vitesse+perso1.acceleration;
		keypressed=1;
		perso1.score+=1;
		if(perso1.state!=doublejumping && perso1.state!=doublejumping) 
			perso1.state=walking;
		perso1.direction=0;
		//deplacerPerso(&perso);
	}
	else
		vitesse1=0;
	if(key[SDLK_q]) //moving left key
	{	direction1 = 'L';
		if (perso1.pos_hero.x <= 0)
                    {
                        perso1.pos_hero.x = 0;
                        vitesse1 = 0;
                        b.camera.x = 0;
                    }
                 else
                        vitesse1 = perso1.vitesse+perso1.acceleration;
		keypressed=1;
		if(perso1.state!=jumping && perso1.state!=doublejumping) 
			perso1.state=walking;
		perso1.direction=1;
		//deplacerPerso(&perso);
	}
	if(key[SDLK_e]) // acceleration key
	{
		if(perso1.acceleration<20)
		 perso1.acceleration+=5;
	}
	else
	{	while (perso1.acceleration!=0)
		{
			perso1.acceleration-=20;	
		}
	}
	if(key[SDLK_s]) //crouching key
	{
		if(perso1.frame_c==1) perso1.frame_c=0;
		perso1.state=crouch;	
	}
	if(key[SDLK_a]) // attacking key
	{
		perso1.state=attacking;
		if(perso1.direction==0)
		perso1.pos_hero.x+=2;
		else if(perso1.direction==1)
		perso1.pos_hero.x-=2;
		perso1.score+=2;
	}
	
	if(key[SDLK_c]) // hit key (test)
	{
		perso1.state=hit;
		perso1.health-=10;
		perso1.score-=20;
	}
	}
} else if (input==2)
{		//event.type=' ';
      		SDL_PollEvent(&event);
      		
			switch(event.type)
		   {
			case SDL_MOUSEBUTTONDOWN:
		{
		 rangex = perso.pos_hero.x - event.motion.x; // rangex and rangey declared outisde of the main 
                rangey = perso.pos_hero.y - event.motion.y;

                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (rangex < -200) // same changes as keyboard mouvement right in your code 
                    {
                        direction = 'R';
		if (perso.pos_hero.x >= resx - persow)
                    {
                        perso.pos_hero.x = resx - persow;
                        vitesse = 0;
                        b.camera.x = bgw - resx;
                    }
                    else
                        vitesse = perso.vitesse+perso.acceleration;
		keypressed=1;
		perso.score+=1;
		if(perso.state!=doublejumping && perso.state!=doublejumping) 
			perso.state=walking;
		perso.direction=0;
                    }
                    else if (rangex > 200) // same changes as keyboard mouvement left in your code 
                    {
                        direction = 'L';
		if (perso.pos_hero.x <= 0)
                    {
                        perso.pos_hero.x = 0;
                        vitesse = 0;
                        b.camera.x = 0;

                    }
                 else
                        vitesse = perso.vitesse+perso.acceleration;
		keypressed=1;
		if(perso.state!=jumping && perso.state!=doublejumping) 
			perso.state=walking;
		perso.direction=1;
                    }
                    else vitesse=0;
                    if (rangey > 200) // same changes as keyboard jump in your code 
                    {
                        if((perso.jump_count>=0 && perso.jump_count<=1) && (perso.pos_hero.y<=800 && perso.pos_hero.y>=650))
		{
			perso.jump_count++; 
			perso.score+=10;
			saut(&perso);
		}
	//if the person jumped and got down again
	if(perso.jump_count>=2 && perso.pos_hero.y==800) perso.jump_count=0;
	//if the person jumped once
	if(perso.pos_hero.y<800 && perso.pos_hero.y>=650) 
	 {
		perso.state=jumping;
	 }
	 //if the person jumped twice
	else if(perso.pos_hero.y<650 && perso.pos_hero.y>=500) 
	{
		perso.state=doublejumping;
	}
                    }
                }
                if (event.button.button == SDL_BUTTON_RIGHT) // same changes for a full stop in your code using keyboard
                {
                    srand(time(NULL));
			standing= (rand()%(3));
			randomizer(&perso,standing);
                }
      		}
      		break;
      		case SDL_MOUSEBUTTONUP:
      		vitesse=0;
      		break;
		   }
      		
}

                   
else if (input==3)
{
     //input from arduino
		arduinoReadData(&received);
	     if(received==1)//moving right key
	{	direction = 'R';
		//printf("%d",1);
		if (perso.pos_hero.x >= resx - persow)
                    {
                        perso.pos_hero.x = resx - persow;
                        vitesse = 0;
                        b.camera.x = bgw - resx;
                    }
                    else
                        vitesse = perso.vitesse+perso.acceleration;
		keypressed=1;
		perso.score+=1;
		if(perso.state!=doublejumping && perso.state!=doublejumping) 
			perso.state=walking;
		perso.direction=0;
		//deplacerPerso(&perso);
	}
	else
		vitesse=0;
	if(received==2) //moving left key
	{	//printf("%d",2);
		direction = 'L';
		if (perso.pos_hero.x <= 0)
                    {
                        perso.pos_hero.x = 0;
                        vitesse = 0;
                        b.camera.x = 0;
                    }
                 else
                        vitesse = perso.vitesse+perso.acceleration;
		keypressed=1;
		if(perso.state!=jumping && perso.state!=doublejumping) 
			perso.state=walking;
		perso.direction=1;
		//deplacerPerso(&perso);
	}
}
}
//////////////////////////////////////////////////////////////////////////////////////// right
	   if (collision_parfaite_right(mask, perso.pos_hero, b.camera) == 0)
        {arduinoWriteData(0);
            if ((perso.pos_hero.x >= resx / 2) && (direction == 'R') && (b.camera.x <= bgw - resx))
            {

                scrolling(&b, direction, vitesse);
                perso1.pos_hero.x-=vitesse;
                en.pos_ennemie.x-=vitesse;
                e.pos_entity.x-=vitesse;
            }
            else if ((direction == 'R') && (perso.pos_hero.x < resx - persow))
            {
                perso.pos_hero.x += vitesse;
            }
        }
        else
        	{
		perso.state=die;
		//perso.death=1;
		perso.health=0;
		enigmemode=2;
	}

        //////////////////////////////////////////////////////////////////////////////////////// left
        if (collision_parfaite_left(mask, perso.pos_hero, b.camera) == 0)
        {arduinoWriteData(0);
            if ((perso.pos_hero.x<= resx / 2) && (direction == 'L') && (b.camera.x >= 0))
            {
                scrolling(&b, direction, vitesse);
                perso1.pos_hero.x+=vitesse;
                en.pos_ennemie.x+=vitesse;
                e.pos_entity.x+=vitesse;
                
            }
           else if ((direction == 'L') && (perso.pos_hero.x >= 0))
            {
                perso.pos_hero.x-= vitesse;
                
            }
          }
          else
        	{
		perso.state=die;
		//perso.death=1;
		perso.health=0;
		enigmemode=2;
		}
	if (duo==1)
	{
	//////////////////////////////////////////////////////////////////////////////////////// right
	   if (collision_parfaite_right(mask, perso1.pos_hero, b.camera) == 0)
        {
            if ((perso1.pos_hero.x >= resx / 2) && (direction1 == 'R') && (b.camera.x <= bgw - resx))
            {

                scrolling(&b, direction1, vitesse1);
                perso.pos_hero.x-=vitesse1;
                en.pos_ennemie.x-=vitesse1;
                e.pos_entity.x-=vitesse1;
            }
            else if ((direction1 == 'R') && (perso1.pos_hero.x < resx - persow))
            {
                perso1.pos_hero.x += vitesse1;
            }
        }
        else
        	{
		perso1.state=die;
		//perso.death=1;
		perso1.health=0;
		enigmemode=2;
	}

        //////////////////////////////////////////////////////////////////////////////////////// left
        if (collision_parfaite_left(mask, perso.pos_hero, b.camera) == 0)
        {
            if ((perso1.pos_hero.x<= resx / 2) && (direction1 == 'L') && (b.camera.x >= 0))
            {
                scrolling(&b, direction1, vitesse1);
                perso.pos_hero.x+=vitesse1;
                en.pos_ennemie.x+=vitesse1;
                e.pos_entity.x+=vitesse1;
                
            }
           else if ((direction1 == 'L') && (perso1.pos_hero.x >= 0))
            {
                perso1.pos_hero.x-= vitesse1;
                
            }
          }
          else
        	{
		perso1.state=die;
		//perso.death=1;
		perso1.health=0;
		enigmemode=2;
		}
	}
	// if the hero died
	/*if(key[SDLK_d]) //death key (test)
	{
		perso.state=die;
		//perso.death=1;
		perso.health=0;
		enigmemode=2;
	}*/
//main fonctions
initminimap (&minibackg,&perso,b.camera);
pulltrigger(&perso);
MAJminimap (&perso,&minibackg,b.camera,40,vitesse);
animerPerso(&perso);
if (duo==1)
{pulltrigger(&perso1);
animerPerso(&perso1);}
//afficherPerso(perso,screen);
afficherscorevie(perso,screen);
if (enigmemode==0)
{
update_entity(&e);
update_ennemie (&en,&perso);
 
	if(detect_collision(&perso,&e)) a=gestion(&e);

	if (a){ afficherPerso(perso ,screen);afficherentity(e ,screen);}
   	
   	if (detect_collision_ennemie(&perso,&en)) an=gerer(&en);
   	
   	if (an) {afficherPerso(perso ,screen);afficherEnnemi (en ,screen);}
   	else{
   	enigmemode=1;
	//perso.health-=50;
   	//SDL_BlitSurface(sorry,NULL,screen,&pos_sorry);
   	}
   	if (duo==1)
   	{
   	if(detect_collision(&perso1,&e)) a=gestion(&e);

	if (a){ afficherPerso(perso1 ,screen);afficherentity(e ,screen);}
   	
   	if (detect_collision_ennemie(&perso1,&en)) an=gerer(&en);
   	
   	if (an) {afficherPerso(perso1 ,screen);afficherEnnemi (en ,screen);}
   	else{
   	enigmemode=1;
	//perso.health-=50;
   	//SDL_BlitSurface(sorry,NULL,screen,&pos_sorry);
   	}
   	}
   	
   }
   if (enigmemode==1)
{
arduinoWriteData(1);
perso.pos_hero.x=60;
//a=1;
perso.health=50;
srand(time(NULL));
afficherEnigme(eg, screen);
		animer(&eg);

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_DOWN:
				i++;
				if(i>=4){i=1;}
				if(i==1){eg.pos_selected = 1;}
				if(i==2){eg.pos_selected = 2;}
				if(i==3){eg.pos_selected = 3;}
                                break;
 				case SDLK_UP:
				i--;
				if(i<=0){i=3;}
				if(i==1){eg.pos_selected = 1;}
				if(i==2){eg.pos_selected = 2;}
				if(i==3){eg.pos_selected = 3;}
                                break;

				case SDLK_RETURN:
					{
						gamemode=verify_enigme(eg, screen);
						//SDL_Delay(2000);
						enigmemode = 0;
						an=1;
					}
					break;
				}
				break;
			case SDL_MOUSEMOTION:
			{
				if ((event.motion.x > eg.pos_reponse1.x) && (event.motion.x < eg.pos_reponse1.x + 240 ) && (event.motion.y > eg.pos_reponse1.y) && (event.motion.y < eg.pos_reponse1.y + 90))
				{
					eg.pos_selected = 1;
				}
				else if ((event.motion.x > eg.pos_reponse2.x) && (event.motion.x < eg.pos_reponse2.x + 240) && (event.motion.y > eg.pos_reponse2.y ) && (event.motion.y < eg.pos_reponse2.y + 90))
				{
					eg.pos_selected = 2;

				}
				else if ((event.motion.x > eg.pos_reponse3.x) && (event.motion.x < eg.pos_reponse3.x + 240) && (event.motion.y > eg.pos_reponse3.y ) && (event.motion.y < eg.pos_reponse3.y + 90))
				{
					eg.pos_selected = 3;
				}
				else
					{
						eg.pos_selected = 0;
					}
			}
			break;

			case SDL_MOUSEBUTTONDOWN:
				{
					if( event.button.button == SDL_BUTTON_LEFT )
					{
						if(eg.pos_selected == 1 )
						{
							gamemode=verify_enigme(eg,screen);
							
							enigmemode = 0;
							an=1;
						}
						else if(eg.pos_selected == 2 )
						{
							gamemode=verify_enigme(eg,screen);
							
							enigmemode = 0;
							an=1;
						}
						else if(eg.pos_selected == 3 )
						{
							gamemode=verify_enigme(eg,screen);
							
							enigmemode = 0;
							an=1;
						}

					}
				}
				break;
			}
		}

}

if (enigmemode==2)

{
arduinoWriteData(2);
gamemode=afficherEnigmeif(ee,screen); //1 si perdu 2 si gagner
generer(&ee);
InitEnigmeif(&ee ,&nomfichier[100]);
if (gamemode==1)//perdu
{
sauvgarder (perso.score, nom , "score.txt",gamemode);
enigmemode=0;
perso.pos_hero.x=80;
pic=1;
perso.score=0;
if (duo==1)
{
perso1.pos_hero.x=80;
perso1.score=0;
}
perso.health=100;
duo=0;
timee=0;
}
else //gagne 
{
enigmemode=0;
gamemode=2;
perso.pos_hero.x=80;
perso.health=50;
perso.state=idle;
if (duo==1)
{
perso1.pos_hero.x=80;
perso1.state=idle;
}
}

}
if (perso.pos_hero.x == resx - persow)
            {
            	SDL_BlitSurface (youwon,NULL,screen,&pos_backg);
            	enigmemode=0;
		perso.pos_hero.x=80;
		pic=1;
		perso.health=100;
		b.camera.x=0;
		perso.score=0;
            	SDL_Flip(screen);
            	SDL_Delay(1000);
            	gamemode=1;
            	sauvgarder (perso.score, nom , "score.txt",gamemode);
            }
/*if (enigmemode==0)
{//perso.death==0;
//perso.health=100;
perso.state=idle;
//sauvgarder (perso.score, nom , "score.txt",perso);
}
//sauvgarder (perso.score, nom , "score.txt");

//if the person is dead (dead permanently)
*/

SDL_Flip(screen);
SDL_Delay (25);
}
}
			
}

	SDL_FreeSurface(screen);
	SDL_FreeSurface(message1);
	free_Surface_enigme(&eg);
	TTF_CloseFont(eg.police1);
	TTF_CloseFont(eg.police);
	SDL_FreeSurface(backg);
	Liberer (&minibackg);
	//SDL_FreeSurface(sorry);
	SDL_FreeSurface (message1);
	SDL_FreeSurface (message2);
	SDL_FreeSurface (message3);
	free_perso(&perso);
	free_perso(&perso1);
	libereranimation (tabimg,tabintro);
	libererButtons(start,settings, exit,music,score,gamelogo);
	TTF_CloseFont(font);
	Mix_FreeChunk (chunk);
	Mix_FreeMusic (musique);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
	return 0;
}
int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}

int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}
