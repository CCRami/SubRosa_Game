#include "header.h"


void generer(enigmeif *e){
	
	srand(time(NULL));
	e->d=rand()%7; 
}

void InitEnigmeif(enigmeif *e,char *nomfichie[]){

	char im[100],imr1[100],imr2[100],imr3[100];
	char nomfichier[100];
 	e->pos_image.x=200;
  	e->pos_image.y=50;
  	
  	e->pos_reponse.x=200;
  	e->pos_reponse.y=50;

	sprintf(nomfichier,"fichierenigme/%d.txt",e->d);    
	sprintf(imr1,"reponse/%d/1.png",e->d); 
    	sprintf(imr2,"reponse/%d/2.png",e->d); 
    	sprintf(imr3,"reponse/%d/3.png",e->d); 
	
   
	FILE * f  = fopen(nomfichier,"r");   
	if(f==NULL){
		printf("cant open file");
	}
	else{
	    	fscanf(f,"%s",im); 
	    	fclose(f);
	    	
	    	e->image= IMG_Load(im);       
		e->reponse1= IMG_Load(imr1);
		e->reponse2= IMG_Load(imr2);
    		e->reponse3= IMG_Load(imr3);
    		e->image=e->reponse3;
    		
	    
	    }

	(*e).image_clock=IMG_Load("clock2.png");  

	e->pos_image_clock.x=0;
	e->pos_image_clock.y=0;
	
	e->single_Clock.w=143;
	e->single_Clock.h=202;
	e->single_Clock.x=0;
	e->single_Clock.y=0;

	e->clock_num=0;


}

int afficherEnigmeif(enigmeif e,SDL_Surface *screen){
		int v;
		SDL_BlitSurface(e.image,NULL,screen,&e.pos_image);
 		SDL_BlitSurface(e.reponse3,NULL, screen, &e.pos_reponse);
		SDL_Flip(screen);
		//SDL_Delay(200);				
		v=resolution(screen,&e);
		return v;

}
void displayClockif(enigmeif e,SDL_Surface *screen){
			
 		SDL_BlitSurface(e.image_clock,&(e.single_Clock), screen, &e.pos_image_clock);
                SDL_Delay(200); 
              	SDL_Flip(screen);
}
void correct(SDL_Surface *screen,enigmeif *e){

	char im[100];
 
	sprintf(im,"check.png");
	e->correct= IMG_Load(im);
	e->pos_correct.x=200;
	e->pos_correct.y=50;
	SDL_BlitSurface(e->correct,NULL,screen,&e->pos_correct);
	//SDL_Flip(screen);
	SDL_Delay(200);

}

void wrong(SDL_Surface *screen,enigmeif *e){
 	char im[100];
     
    	e->wrong= IMG_Load("wrong.png");
    	e->pos_wrong.x=200;
    	e->pos_wrong.y=50;
    	SDL_BlitSurface(e->wrong,NULL,screen,&e->pos_wrong);
    	SDL_Flip(screen);
    	SDL_Delay(1000);
    	sprintf(im,"solution/%d.png",e->d);
	e->solution= IMG_Load(im);
	e->pos_solution.x=200;
	e->pos_solution.y=50;
    	SDL_BlitSurface(e->solution,NULL,screen,&e->pos_solution);
    	SDL_Flip(screen);
    	SDL_Delay(200);

}


int resolution(SDL_Surface *screen,enigmeif *e){
	SDL_Event event;
	int v=2;
	int continuer =1;
	int i=1;
	while (continuer)
	    {
while (SDL_PollEvent(&event)){
		//SDL_WaitEvent(&event);
		switch(event.type)
		{
		case SDL_QUIT:
		    continuer=0;
		    break;

		case SDL_KEYDOWN:
		    switch(event.key.keysym.sym)
		    {

		    case SDLK_RETURN:
		        if(i>=1 && i<=3)
		        {

		            if (i==1 && e->d%3==1)
		            {
				correct(screen,e);
				continuer=0;
		            }
		            else if (i==2 && e->d%3==2)
		            {
				correct(screen,e);
				continuer=0;
		            }
		            else if (i==3 && e->d%3==0)
		            {
				correct(screen,e);
				continuer=0;
		            }
		            else
		            {
				wrong(screen,e);
				SDL_Delay(1000);
				continuer=0;
				v=1;
		            }
		        }
		        break;

		    case SDLK_DOWN:
		        i--;
		         if(i<1)
		        {
		          i=3;	
		            
		        }
		        if(i==1)
		        {		          
		            e->image=e->reponse1;
		        }
		        if(i==2)
		        {		       
		         e->image=e->reponse2;		            
		        }
		        if(i==3)
		        {
		        	e->image=e->reponse3;		            
		        }
		        ;
		        break;
		    case SDLK_UP:
		        i++;
		         if(i>3)
		        {
		            i=1;
		        
		        }
		       
		        
		        if(i==1)
		        {
		        	e->image = e->reponse1;
		        }
		        if(i==2)
		        {
		        	e->image = e->reponse2;
		        }
		        if(i==3)
		        {
		        	e->image=e->reponse3;		     
		        }
		        break;
		    }
		}
}
		SDL_BlitSurface(e->image,NULL,screen,&e->pos_image);
		displayClockif(*e,screen);
		animerEnigme(e);
		//SDL_Delay (200);
		SDL_Flip(screen);
	}
    	return v;
}

void animerEnigme(enigmeif *e){
		 	
	if (e->clock_num >=0 && e->clock_num <8) {
	e->single_Clock.x=e->clock_num * e->single_Clock.w;
	e->clock_num++;
	
	}
	
	if ( e->clock_num == 8) {
	e->single_Clock.x=e->clock_num * e->single_Clock.w;
	e->clock_num=0;
	
	}
	//printf("%d ",e->clock_num);
}




























