#include "header.h"

void charger(personne *p, background *b , char * nomfichier, int *min, int *sec)
{
	
	FILE *f=fopen(nomfichier,"r");
	if(f==NULL)
	{
	     printf("Erreur !");
	}
	else
	{	
		printf("loading");
		while (fscanf(f,"%hd %hd %d %d %hd %hd %d %d\n",&(p->pos_hero.x),&(p->pos_hero.y),&(p->health),&(p->score),&(b->camera.x),&(b->camera.y),min,sec)!= EOF)
		{}
		
		
	}
	fclose(f);
}
void sauvegarder(personne p, background b , char * nomfichier,int min, int sec)
{
	
	FILE *f=fopen(nomfichier,"a+");
	if(f==NULL)
	{
	     printf("Erreur !");
	}
	else
	{	
		printf("saving");
		fprintf(f,"%hd %hd %d %d %hd %hd %d %d\n",p.pos_hero.x,p.pos_hero.y,p.health,p.score,b.camera.x,b.camera.y,min,sec);
		
	}
	fclose(f);
}

