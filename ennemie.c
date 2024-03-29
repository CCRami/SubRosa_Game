/**
 * @file ennemie.c 
 */
#include "header.h"




int 
nb_frame1=12 ,
ennemie_h=100,
ennemie_w=100,
ennemie_y=100,
ennemie_x=100;


void init_tab_anim_ennemie(SDL_Rect *clip,Ennemie *e)
{	


for (int j=0;j<nb_frame1; j++)
	{
	clip[j].h=ennemie_h;
	clip[j].w=ennemie_w;
	clip[j].x = j*ennemie_w;
	clip[j].y = 0;
        }


}


/**
* @brief To initialize the ennemie en  .
* @param en the ennemie
* @return Nothing
*/

void initEnnemi(Ennemie *e)
{

    e->ennemie = IMG_Load("ENNEMIE.png");

    e->pos_ennemie.x = 1000;
    e->pos_ennemie.y = 700;
    init_tab_anim_ennemie(e->anim_ennemie,e);
    e->frame_ennemie=0;
    e->direction=0;  
    e->col=0;
    e->show=1;
    
    
}
/**
* @brief To show the ennemie en .
* @param screen the screen
* @param en the ennemie
* @return Nothing
*/


void afficherEnnemi(Ennemie e, SDL_Surface *screen)
{
   
   SDL_BlitSurface(e.ennemie,&e.anim_ennemie[e.frame_ennemie], screen, &e.pos_ennemie);
  
  

}
/**
* @brief for the random movement of  the automation ennemi  .
* @param en the ennemie
* @param p the personnage  
* @return Nothing
*/
void deplacerIA(Ennemie *e, personne *p)
{
	int waiting = 1;  // etat entité  // = 1 perso not in range // = 0 perso in range 
	int range = 500; 
	srand(time(0));
	int diff;
	int maxi_down = 700 + rand() % 300;
	int maxi_up = 450 + rand() % 300;

	//printf("maxup : %d\tmaxdown : %d\n", maxi_up, maxi_down);
	diff = e->pos_ennemie.x - p->pos_hero.x;
	if (abs(diff) <= range)  // detetction perso in range or not 
		{
			waiting = 0;
		}
	else
	{
		waiting = 1;
	}
	//printf("%d \n ",waiting);



	switch (waiting)
	{
	case 0:  // in range 
	{ // deplacement alea sur l'axe  Y 
		if (e->pos_ennemie.y >= maxi_down)
		{
			e->direction = 1;
		}
		if (e->pos_ennemie.y <= maxi_up)
		{
			e->direction = 0;
		}

		if (e->direction == 1)
		{
			e->pos_ennemie.y -= 7;
		}
		if (e->direction == 0)
		{
			e->pos_ennemie.y += 7;
		}
		///////////////////////////////////////////// 
		if (diff > 0)  // perso avant l'ennemi
		{

			e->pos_ennemie.x -= 3;  // l'ennemi recule 
		}

		if (diff < 0) // perso apres l'ennemi
		{

			e->pos_ennemie.x += 3; // l'ennemi avance 
		}
	}
	break;
	///////////////////////////////////////////////////////////////
	case 1: // not in range 
	{  // mouvement alea   sur l'axe Y 
		if (e->pos_ennemie.y >= maxi_down)
		{
			e->direction = 1;
		}
		if (e->pos_ennemie.y <= maxi_up)
		{
			e->direction = 0;
		}

		if (e->direction == 1)
		{
			e->pos_ennemie.y -= 7;
		}
		if (e->direction == 0)
		{
			e->pos_ennemie.y += 7;
		}
		/////////////////////////////////////////// retour a la position initiale = 900 sur l'axe X
		
		if (e->pos_ennemie.x > 1000)
			e->pos_ennemie.x -= 3;

		if (e->pos_ennemie.x < 1000)
			e->pos_ennemie.x += 3;
	}
	break;

	default:
		break;
	}
}
/*
void deplacerIA(Ennemie *e,personne *p)
{	srand (time(0));
	int diff;
	int maxi_down=700+rand()%300;
	int maxi_up=400+rand()%300;

  	//printf("maxup : %d\tmaxdown : %d\n",maxi_up,maxi_down );


if(e->pos_ennemie.y>= maxi_down)
{
e->direction =1;
}
if(e->pos_ennemie.y<=maxi_up)
{
e->direction =0;
}

if(e->direction==1)
{   
	e->pos_ennemie.y-=7;

}
if(e->direction==0)
{
	e->pos_ennemie.y+=7;
}

  diff=e->pos_ennemie.x-p->pos_hero.x;
  if (diff<400 && diff>0 ){

e->pos_ennemie.x-=3;
  }

if (diff >-400 && diff < 0){
  
  e->pos_ennemie.x+=3;
  }

}
*/
/**
* @brief for the animation the ennemie .
* @param en the ennemie 
* @return Nothing
*/

void animerEnnemi(Ennemie *e)
{   if (e->frame_ennemie >=0 && e->frame_ennemie <(nb_frame1-1)) 
 e->frame_ennemie++;
    if ( e->frame_ennemie ==(nb_frame1-1)) 
       e->frame_ennemie=0;
}
/**
* @brief for the integration of two functions (anim,mouv) .
* @param en the ennemie 
* @param p the personnage 
* @return Nothing
*/


void update_ennemie(Ennemie *e,personne *p)
{ 	deplacerIA(e,p);
	animerEnnemi(e);
	

}


int detect_collision_ennemie(personne *p, Ennemie *e)
{
	

if ((p->pos_hero.x + p->pos_hero. w< e->pos_ennemie. x) || (p->pos_hero.x> e->pos_ennemie. x + e->pos_ennemie. w) ||
(p->pos_hero.y + p->pos_hero.h< e->pos_ennemie. y) || (p->pos_hero.y> e->pos_ennemie. y + e->pos_ennemie. h ))
return 0;
else 
return 1;
 
}

int gerer(Ennemie *e) {
	
	e->show=0;
	
	return 0; 
}








