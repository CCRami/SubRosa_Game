#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include "stdbool.h"
#define SCREEN_W 1920
#define SCREEN_H 1080
typedef struct{
	SDL_Rect pos;
	SDL_Surface *img;
}image;
typedef struct
{
SDL_Surface *img;
SDL_Rect pos_img;
SDL_Surface *img_joueur ;
SDL_Rect posjoueur;
}minimap;
typedef struct {
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface * surfaceTexte;
	SDL_Color textColor;
	char texte [50];
}text;
typedef enum SPRITE SPRITE;
enum SPRITE {idle,idle1,idle2,walking,jumping,doublejumping,attacking,hit,die,crouch};
typedef struct 
{
	SDL_Surface *vie[4];
	SDL_Surface *bar_score;
	SDL_Surface *hero_right;
	SDL_Surface *hero_left;
	SDL_Rect pos_hero,pos_vie,pos_score;
	int direction,health,score,death,vitesse,acceleration,jump,jump_count;
	SDL_Rect animheroRight[10][20];
	SDL_Rect animheroLeft[10][20];
	int frame_i,frame_i1,frame_i2,frame_wl,frame_j,frame_dj,frame_a,frame_h,frame_d,frame_c;
	SPRITE state;
	TTF_Font *police;
}personne;
typedef struct {
	SDL_Surface *ennemie ;  
	SDL_Rect pos_ennemie; 
	SDL_Rect anim_ennemie[70]; 
	int frame_ennemie;
	int direction;
	int col ;
	int type;
	int maxi_up,maxi_down;
	int show;

}Ennemie;
typedef struct {   
	  

	SDL_Surface *entity; 
	SDL_Rect pos_entity; 
	SDL_Rect anim_entity[70];  // l tab ali fih l les surfaces mta3 kol frame  o kol frame andha indice ( frame_entity )
	int frame_entity;
	int direction;
	int col ;
	int maxi_up,maxi_down;
	int show;

}entity ;
typedef struct
{ // type define structure

	SDL_Surface *background;  // l background ali besh nafficher fiha l question o les reponses
	SDL_Surface *question;	  // l surface ali besh nafficher feha l question
	SDL_Surface *reponses[4]; // l surface ali besh nafficher feha les reponses
	SDL_Surface *button;	  // l button ali besh nenzl alih
	SDL_Surface *button_s;

	char  chquestion[50];
	char chrep[2][50];
	int rc; // l reponse l s7i7a yam loula wala l thenya wala l theltha


	int pos_selected;	   // 1 2 3
	SDL_Rect pos_question; // l position mta3 l question
	SDL_Rect pos_reponse1; // l position mta3 lreponse
	SDL_Rect pos_reponse2; // l position mta3 l reponse
	SDL_Rect pos_reponse3; // l position mta3 l reponse
	int num_question;

	SDL_Rect pos_reponse1txt; // l position mta3 l txt ali besh nhoto fouk l image ta3 l reponse
	SDL_Rect pos_reponse2txt; // l position mta3 l txt ali besh nhoto fouk l image ta3 l reponse
	SDL_Rect pos_reponse3txt; // l position mta3 l txt ali besh nhoto fouk l image ta3 l reponse		  
	TTF_Font *police;
	TTF_Font *police1;

	SDL_Surface *image_clock;
	SDL_Rect pos_image_clock;

	SDL_Rect single_Clock;

	int clock_num;

} enigmetf;
typedef struct{ 
	
	SDL_Surface *image;  
	SDL_Rect pos_image;
       
        SDL_Surface *image_clock;  
	SDL_Rect pos_image_clock;
	
	SDL_Rect single_Clock;
	
	SDL_Surface *reponse1; 
	SDL_Surface *reponse2; 
	SDL_Surface *reponse3; 
	SDL_Rect pos_reponse;
	
	SDL_Surface *correct; 
	SDL_Rect pos_correct;
	
	SDL_Surface *wrong; 
	SDL_Rect pos_wrong;
	
	SDL_Surface *solution; 
	SDL_Rect pos_solution;
	
	int d; 
        int clock_num;
	
}enigmeif;
typedef struct background
	{
        SDL_Surface *image,*mask,*sprite,*sprite2;
        SDL_Rect camera;
        Mix_Music *music;
    int i;
    int j ;  
    SDL_Rect pos_anim;
    SDL_Rect pos_sprite; 
    int x;
    int y;  
    SDL_Rect pos_anim2;
    SDL_Rect pos_sprite2; 
    }background;
typedef struct
{
 	int tabsuivi[9];
	int tour;
	int joueur;
	image A,B,C;
	text *te;
	
}tic;


void initText(text *A,text *B,text *C,text *D);
void freeText(text A,text B,text C, text D);
void displayText(text t,SDL_Surface *screen);
void initButtons(image *A,image *B, image *C,image *D,image *E, image *F);
void initBackground(image *Backg);
void afficher(image A,SDL_Surface *screen);
void libererButtons(image A,image B, image C,image E,image F,image G);
void afficherparposition(int position, image *A,image *B, image *C,image *D);
void closeEverything();

void initSettingsButtons(image *A,image *B, image *C,image *D,image *E,Mix_Chunk *chunk);
int paintOptionsScreen(SDL_Surface* screen,SDL_Event *event,Mix_Chunk *chunk,int *volume);

void initTextagent(text *A,text *B);
void freeTextagent(text A,text B);
void displayTextagent(text t,SDL_Surface *screen);
void afficherparpositionagent(int position, image *A,image *B, image *C,image *D,image *E,image *F,image *G, image *H,image *I,image *J);
void initSettingsButtonsagent(image *A,image *B, image *C,image *D,image *E,image *F,image *G, image *H,image *I,image *J);
int paintOptionsScreenagent (SDL_Surface *screen,SDL_Event *event2,Mix_Chunk *chunk,int *gamemode,int *duo,int *pic,int *input, int *choice);
void afficherparpositionsettings(int position, image *A,image *B);

void initanimation(image tabimg[],image tabintro[]);
void libereranimation (image tabimg[],image tabintro[]);
//perso
void initPerso(personne *p);
void initPerso2(personne *p);
void afficherPerso(personne p, SDL_Surface * screen_p);
void deplacerPerso (personne *p);
void animerPerso (personne* p);
void saut (personne* p);
void pulltrigger(personne* p);
void randomizer(personne *p,int state_i);
void afficherscorevie(personne p, SDL_Surface * screen_s);
void free_perso(personne *p);
//minimap
void initminimap (minimap *m,personne *p,SDL_Rect camera);
void MAJminimap (personne *p, minimap *m,SDL_Rect camera,int r,int vitesse);
void afficherminimap (minimap m,SDL_Surface *screen);
void Liberer (minimap * m);
void ajouternom (SDL_Surface *Screen,char *nom, SDL_Event event);
void sauvgarder (int score, char nom[],char nomfichier[],int x);
void meilleur (char nomfichier[],int *score,char *nom);

//score
void initscore(text *A,text *B,char meilleurnom[],int meilleurscore);
void freescore(text A,text B);

void displayscore(text t,SDL_Surface *screen);
int rollscore (SDL_Surface *screen,SDL_Event *event1,char meilleurnom[],int meilleurscore);

//ets
void init_tab_anim_entity(SDL_Rect* clip,entity *e);   
void initentity (entity *e) ;
void afficherentity(entity e , SDL_Surface *screen);
void animerentity(entity *e);
void deplacer(entity *e);
void update_entity(entity *e);

int detect_collision(personne *p, entity* e);  
int gestion(entity* e);

void init_tab_anim_ennemie (SDL_Rect* clip,Ennemie *e); 
void initEnnemi  (Ennemie *e) ;
void afficherEnnemi (Ennemie e, SDL_Surface *screen);
void animerEnnemi (Ennemie *e);
void deplacerIA (Ennemie *e,personne *p);
void update_ennemie (Ennemie *e,personne *p);

int detect_collision_ennemie(personne *p, Ennemie *e);
int gerer(Ennemie *e) ; 

//enigmetf
void InitEnigme(enigmetf *e, char nomfichier[]);
void afficherEnigme(enigmetf e, SDL_Surface *ecran);
void displayClock(enigmetf e, SDL_Surface *ecran);
int verify_enigme(enigmetf e, SDL_Surface *ecran);
void animer(enigmetf *e);
void free_Surface_enigme(enigmetf *e);
void sauvegarder(personne p, background b, char * nomfichier,int min, int sec);
void charger(personne *p, background *b , char * nomfichier,int *min , int *sec);

//enigmeif
void InitEnigmeif(enigmeif *e ,char *nomfichie[] );
int afficherEnigmeif(enigmeif e,SDL_Surface *screen);
int resolution(SDL_Surface *screen,enigmeif *e);
void correct(SDL_Surface *screen,enigmeif *e);
void wrong(SDL_Surface *screen,enigmeif *e);
void generer(enigmeif *e);
void displayClockif(enigmeif e,SDL_Surface *screen);
void animerEnigme(enigmeif *e);

//backg
void initBack(background * b, int x,int y);
void afficherBack(background b, SDL_Surface * screen,int x,int y);
void scrolling(background * b, int direction, int pasAvancement);
void animation(background * b, SDL_Surface * screen) ;
void animation2(background *b, SDL_Surface *screen);
SDL_Color GetPixel(SDL_Surface *pSurface , int x,int y);

int collision_parfaite_right(SDL_Surface *mask , SDL_Rect posjoueur,SDL_Rect camera );
int collision_parfaite_left(SDL_Surface *mask , SDL_Rect posjoueur ,SDL_Rect camera);
int collision_parfaite_up(SDL_Surface *mask , SDL_Rect posjoueur ,SDL_Rect camera);
int collision_parfaite_down(SDL_Surface *mask , SDL_Rect posjoueur ,SDL_Rect camera);


//tictactoe
void initialiserTic (tic * t) ;
void afficherTic(tic t,SDL_Surface* screen );
int atilganer(int tabsuivi[]);
void Resultat (int tabsuivi[9],SDL_Surface* screen);
void liberer( tic t);
int minmax(int tabsuivi[], int joueur);
void calcul_coup(int tabsuivi[]);
int play (SDL_Surface *screen);
