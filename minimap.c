#include "header.h"

void initminimap (minimap *m,personne *p,SDL_Rect camera)
{

 m->img=IMG_Load ("minimap.png");
  	if (m->img==NULL)
	{return ;}
  	m->pos_img.x=300;
 	m->pos_img.y=20;
m->img_joueur= IMG_Load ("bonhomme.png");
	if (m->img_joueur==NULL)
	{return ; }
	m->posjoueur.x=(((p->pos_hero.x+ camera.x)*10)/100)+300;
	m->posjoueur.y=((p->pos_hero.y)*10/100)+127;
}


void MAJminimap (personne *p, minimap *m ,SDL_Rect camera,int r,int vitesse )
{ 
	SDL_Rect posJoueurABS;
	posJoueurABS.x = p->pos_hero.x + camera.x;
	posJoueurABS.y = p->pos_hero.y + camera.y;
	//m->posjoueur.x=(posJoueurABS.x * r)/100;
	//m->posjoueur.y=(posJoueurABS.y * r)/100;
}



void afficherminimap (minimap m,SDL_Surface *screen)
{

	SDL_BlitSurface(m.img,NULL,screen,&m.pos_img);
	SDL_BlitSurface(m.img_joueur,NULL,screen,&m.posjoueur);
}

void Liberer (minimap * m)
{
	SDL_FreeSurface(m->img); 
	SDL_FreeSurface(m->img_joueur);
}

void ajouternom (SDL_Surface *Screen,char *nom, SDL_Event event)
{
char tmp[20];
strcpy (tmp,"");
switch (event.type) {
  case  SDL_KEYDOWN:
{
	switch (event.key.keysym.sym)
	{
	case SDLK_BACKSPACE:
	strncat(tmp,nom,strlen(nom)-1);
	strcpy (nom,tmp);break;
	case SDLK_a:
         strncat (nom,"a",1); break;
	case SDLK_b:
         strncat (nom,"b",1); break;
	case SDLK_c:
         strncat (nom,"c",1);break;
	case SDLK_d:
         strncat (nom,"d",1);break;
	case SDLK_e:
         strncat (nom,"e",1);break;
	case SDLK_f:
         strncat (nom,"f",1);break;
	case SDLK_g:
         strncat (nom,"g",1);break;
	case SDLK_h:
         strncat (nom,"h",1);break;
	case SDLK_i:
         strncat (nom,"i",1);break;
	case SDLK_j:
         strncat (nom,"j",1);break;
	case SDLK_k:
         strncat (nom,"k",1);break;
	case SDLK_l:
         strncat (nom,"l",1);break;
	case SDLK_m:
         strncat (nom,"m",1);break;
	case SDLK_n:
         strncat (nom,"n",1);break;
	case SDLK_o:
         strncat (nom,"o",1);break;
	case SDLK_p:
         strncat (nom,"p",1);break;
	case SDLK_q:
         strncat (nom,"q",1);break;
	case SDLK_r:
         strncat (nom,"r",1);break;
	case SDLK_s:
         strncat (nom,"s",1);break;
	case SDLK_t:
         strncat (nom,"t",1);break;
	case SDLK_u:
         strncat (nom,"u",1);break;
	case SDLK_v:
         strncat (nom,"v",1);break;
	case SDLK_w:
         strncat (nom,"w",1);break;
	case SDLK_x:
         strncat (nom,"x",1);break;
	case SDLK_y:
         strncat (nom,"y",1);break;
	case SDLK_z:
         strncat (nom,"z",1);break;

	}
}
}
}
void sauvgarder (int score, char nom[],char nomfichier[],int x)
{
int tab[50];
char tab1[50][20];
int i=0,j=0,k;
int tmp;
char tmp1[20];
FILE *F;
F= fopen (nomfichier,"a+");
if ((F!=NULL)&&(x==1))
{
fprintf (F,"%d \n",score);
fclose (F);
}
else
{
fprintf (F,"%s ",nom);
fclose (F);
}
F=fopen (nomfichier,"r");
if (x==1)
{
if (F!=NULL)
{
while ((fscanf (F,"%s %d \n",tab1[i],&tab[i])!=EOF))
{
i++;
}
k=i;
for (i=0;i<k-1;i++)
{
for (j=0;j<k-1-i;j++)
{
if (tab[j]<tab[j+1])
{
tmp=tab[j];
//tmp1[1]=tab1[j];
strcpy (tmp1,tab1[j]);
tab[j]=tab[j+1];
//tab1[j]=tab1[j+1];
strcpy (tab1[j],tab1[j+1]);
tab[j+1]=tmp;
//tab1[j+1]=tmp1[1];
strcpy (tab1[j+1],tmp1);
}
}
}
fclose(F);
}
F=fopen(nomfichier,"w");

if ((F!=NULL))
{
for (i=0;i<k;i++)
{
fprintf (F,"%s %d \n",tab1[i],tab[i]);
}
fclose (F);
}
}
}

void meilleur (char nomfichier[],int *score,char *nom)
{
int max=0;
char nommeilleur[20];
FILE *F;
F= fopen (nomfichier,"r");
if (F!=NULL)
{
while ((fscanf (F,"%s %d \n",nom,score)!=EOF))
{
if (*score >max)
{
max= *score;
strcpy(nommeilleur,nom);
}
}
*score=max;
strcpy (nom,nommeilleur);
}
}





