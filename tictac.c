#include "header.h"
void initialiserTic (tic * t) 
{
int i;
   for (i=0;i<9;i++)
	{
		t->tabsuivi[i]=0;
	}

//background&&images 
t->A.img=IMG_Load ("tictac.png");
t->A.pos.x=0;
t->A.pos.y=0;
t->B.img=IMG_Load ("x.png");
t->C.img=IMG_Load ("o.png");
t->tour=0;
t->joueur=1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void afficherTic(tic t,SDL_Surface* screen )
{
int i;
SDL_BlitSurface(t.A.img,NULL,screen,&t.A.pos);
for (i=0;i<9;++i)
{
if (t.tabsuivi[i]==-1)
{
t.B.pos.x=110*(i%3);
t.B.pos.y=110*(i/3);
SDL_BlitSurface(t.B.img,NULL,screen,&t.B.pos);
}
else 
{
if (t.tabsuivi[i]==1)
{

t.C.pos.x=110*(i%3);
t.C.pos.y=110*(i/3);
SDL_BlitSurface(t.C.img,NULL,screen,&t.C.pos);
}
}
}
 SDL_Flip(screen);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
int atilganer(int tabsuivi[])
{
  int lignes_gagnantes[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
  int i;
	for (i=0;i<8;++i)

  if (tabsuivi[lignes_gagnantes[i][0]]!=0 && tabsuivi[lignes_gagnantes[i][0]]==tabsuivi[lignes_gagnantes[i][1]]&&
	tabsuivi[lignes_gagnantes[i][0]]==tabsuivi[lignes_gagnantes[i][2]])
	return tabsuivi[lignes_gagnantes[i][2]];
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Resultat (int tabsuivi[],SDL_Surface* screen)
{
	TTF_Font * font = TTF_OpenFont("Whirlywood-9pRy.ttf", 100);
	SDL_Color color = {255,255, 255};
	SDL_Surface *message1;
	SDL_Rect Message;
	Message.x = 0;  
	Message.y = 10;
       
switch (atilganer(tabsuivi))
{
case 1: message1= TTF_RenderText_Solid(font,"defaite", color);
SDL_BlitSurface (message1,NULL,screen,&Message);break;
case -1:  message1= TTF_RenderText_Solid(font,"victoire", color);
SDL_BlitSurface (message1,NULL,screen,&Message);break;
case 0: message1= TTF_RenderText_Solid(font,"null", color);
SDL_BlitSurface (message1,NULL,screen,&Message);break;

}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void liberer( tic t)
{
	SDL_FreeSurface(t.A.img); 
	SDL_FreeSurface(t.B.img);
	SDL_FreeSurface(t.C.img);
	
	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int minmax (int tabsuivi[],int joueur)
{
int gagnant=atilganer(tabsuivi);
if (gagnant!=0)
return gagnant*joueur;
int coup=-1;
int score=-2;

int i=0;
for (i=0;i<9;++i)
{
if (tabsuivi[i]==0)
{
tabsuivi[i]=joueur;
int mmscore=-minmax(tabsuivi,joueur*-1);
if (mmscore>score)
{
score=mmscore;
coup=i;
}
tabsuivi[i]=0;
}
}
if (coup==-1)
{
return 0;
}
return score;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcul_coup (int tabsuivi[9])
{
int coup=-1;
int score=-2;
int i;
for (i=0;i<9;++i)
{
	if (tabsuivi[i]==0)
	{
	tabsuivi[i]=1;
	int mmscore=-minmax(tabsuivi,-1);
	tabsuivi[i]=0;
		if (mmscore>score)
		{
		score=mmscore;
		coup=i;
		}
	}
}
	tabsuivi[coup]=1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int play (SDL_Surface *screen)
{
SDL_Event event;
int coup=0;
tic t;
int x=0,y=0;
int joueur=1;
int a=0,b=0;
initialiserTic (&t) ;
while (1)
{
if ((t.tour<=9) && (atilganer(t.tabsuivi)==0))
{

if ((t.tour+t.joueur)%2==0) //ordinateur
{
calcul_coup (t.tabsuivi);
t.tour++;
}
else
{
 while (SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_QUIT:
return 0;
break;
case SDL_KEYDOWN:

	    if (event.key.keysym.sym == SDLK_ESCAPE)
		{
		//event1->key.keysym.sym=SDLK_ESCAPE;
		//freescore(A,B);
		return 0;
		}
	     break;
case SDL_MOUSEBUTTONUP:
 	a=event.button.x/110;
	b=event.button.y/110;
	if ((a>=0)&&(a<=3)&&(b>=0)&&(b<=3))
	{
	coup=3*b+a; // l’indice de la case à mettre à jour dans  le tableau tabsuivi  
	t.tabsuivi[coup]=-1;        
	t.tour++;
	}
break;
}
//switch 
}
afficherTic(t,screen);
SDL_Flip(screen);
//while
}
}
else 
{
Resultat (t.tabsuivi,screen);

SDL_Flip(screen);
SDL_Delay(1500);
return 0;
}
//while 
}
//liberer(t);

}













