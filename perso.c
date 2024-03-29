#include "header.h"
void initPerso(personne *p)
{
	int j=0;
//right
	//idle	 
	for(int i=0;i<6;i++)
	{
		p->animheroRight[0][i].x= (0+(i*192));
		p->animheroRight[0][i].y= 0;
		p->animheroRight[0][i].w= 195;
		p->animheroRight[0][i].h= 195;
	}
	//idle1
	for(int i=0;i<6;i++)
	{
		p->animheroRight[1][i].x= (0+(i*192));
		p->animheroRight[1][i].y= 197;
		p->animheroRight[1][i].w= 196;
		p->animheroRight[1][i].h= 196;
	}
	//idle2
	for(int i=0;i<15;i++)
	{
		p->animheroRight[2][i].x= (0+(i*192));
		p->animheroRight[2][i].y= 393;
		p->animheroRight[2][i].w=196;
		p->animheroRight[2][i].h= 196;
	}
	//walking
	for(int i=0;i<6;i++)
	{
		p->animheroRight[3][i].x= (0+(i*192));
		p->animheroRight[3][i].y= 630;
		p->animheroRight[3][i].w= 196;
		p->animheroRight[3][i].h= 196;
	}
	//jumping
		for(int i=0;i<6;i++)
	{
		p->animheroRight[4][i].x= (0+(i*195));
		p->animheroRight[4][i].y= 846;
		p->animheroRight[4][i].w= 196;
		p->animheroRight[4][i].h= 210;
	}
	//doublejump
		for(int i=0;i<4;i++)
	{
		p->animheroRight[5][i].x= (1392+(i*192));
		p->animheroRight[5][i].y= 846;
		p->animheroRight[5][i].w= 196;
		p->animheroRight[5][i].h= 210;
	}
	//attackhalf1
		for(int i=0;i<3;i++)
	{
		p->animheroRight[6][i].x= (0+(i*267));
		p->animheroRight[6][i].y= 1290;
		p->animheroRight[6][i].w= 258;
		p->animheroRight[6][i].h= 210;
	}
	//attackhalf2
	for(int i=3;i<6;i++) // Attack-half#2:
	{
		p->animheroRight[6][i].x= (840+(j*240));
		p->animheroRight[6][i].y= 1290;
		p->animheroRight[6][i].w= 225;
		p->animheroRight[6][i].h= 210;
		j++;
	}
	j=0;
	//hit
	for(int i=0;i<2;i++)
	{
		p->animheroRight[7][i].x= (0+(i*270));
		p->animheroRight[7][i].y= 10275;
		p->animheroRight[7][i].w= 270;
		p->animheroRight[7][i].h= 210;
	}
	//deathhalf1
	for(int i=0;i<4;i++)
	{
		p->animheroRight[8][i].x= (0+(i*270));
		p->animheroRight[8][i].y= 11520;
		p->animheroRight[8][i].w= 255;
		p->animheroRight[8][i].h= 195;
	}
	//deathhalf2
	for(int i=4;i<9;i++)
	{
		p->animheroRight[8][i].x= (1050+(j*228));
		p->animheroRight[8][i].y= 11520;
		p->animheroRight[8][i].w= 210;
		p->animheroRight[8][i].h= 195;
		j++;
	}
	j=0;
	//crouch
	for(int i=0;i<2;i++)
	{
		p->animheroRight[9][i].x= (0+(i*195));
		p->animheroRight[9][i].y= 1065;
		p->animheroRight[9][i].w= 192;
		p->animheroRight[9][i].h= 180;
	}

//left
	//idle
	for(int i=0;i<6;i++) // 
	{
		p->animheroLeft[0][i].x= (4125-(i*192));
		p->animheroLeft[0][i].y= 0;
		p->animheroLeft[0][i].w= 195;
		p->animheroLeft[0][i].h= 195;
	}
	//idle1
	for(int i=0;i<6;i++) 
	{
		p->animheroLeft[1][i].x= (4125-(i*192));
		p->animheroLeft[1][i].y= 196;
		p->animheroLeft[1][i].w= 195;
		p->animheroLeft[1][i].h= 196;
	}
	//idle2
	for(int i=0;i<15;i++)
	{
		p->animheroLeft[2][i].x= (4125-(i*192));
		p->animheroLeft[2][i].y= 392;
		p->animheroLeft[2][i].w= 195;
		p->animheroLeft[2][i].h= 196;
	}
	//walking
	for(int i=0;i<6;i++)
	{
		p->animheroLeft[3][i].x= (4125-(i*192));
		p->animheroLeft[3][i].y= 630;
		p->animheroLeft[3][i].w= 195;
		p->animheroLeft[3][i].h= 195;
	}
	//jumping
	for(int i=0;i<6;i++)
	{
		p->animheroLeft[4][i].x= (4125-(i*195));
		p->animheroLeft[4][i].y= 846;
		p->animheroLeft[4][i].w= 195;
		p->animheroLeft[4][i].h= 210;
	}
	//doublejumping
		for(int i=0;i<4;i++) 
	{
		p->animheroLeft[5][i].x= (2730-(i*192));
		p->animheroLeft[5][i].y= 846;
		p->animheroLeft[5][i].w= 195;
		p->animheroLeft[5][i].h= 210;
	}
	//attackhalf1
	for(int i=0;i<3;i++) 
	{
		p->animheroLeft[6][i].x= (4080-(i*270));
		p->animheroLeft[6][i].y= 1290;
		p->animheroLeft[6][i].w= 240;
		p->animheroLeft[6][i].h= 210;
	}
	//attackhalf2
	for(int i=3;i<6;i++) 
	{
		p->animheroLeft[6][i].x= (3240-(j*240));
		p->animheroLeft[6][i].y= 1290;
		p->animheroLeft[6][i].w= 225;
		p->animheroLeft[6][i].h= 210;
		j++;
	}
	j=0;
	//hit
	for(int i=0;i<2;i++)
	{
		p->animheroLeft[7][i].x= (4050-(i*270));
		p->animheroLeft[7][i].y= 10350;
		p->animheroLeft[7][i].w= 270;
		p->animheroLeft[7][i].h= 210;
	}
	//deathhalf1
	for(int i=0;i<4;i++) 
	{
		p->animheroLeft[8][i].x= (4050-(i*270));
		p->animheroLeft[8][i].y= 11520;
		p->animheroLeft[8][i].w= 255;
		p->animheroLeft[8][i].h= 195;
	}
	//deathhalf2
	for(int i=3;i<9;i++) 
	{
		p->animheroLeft[8][i].x= (3270-(j*225));
		p->animheroLeft[8][i].y= 11520;
		p->animheroLeft[8][i].w= 225;
		p->animheroLeft[8][i].h= 195;
		j++;
	}
	//crouch
		for(int i=0;i<2;i++) 
	{
		p->animheroLeft[9][i].x= (4128-(i*192));
		p->animheroLeft[9][i].y= 1065;
		p->animheroLeft[9][i].w= 192;
		p->animheroLeft[9][i].h= 180;
	}
	p->hero_right = IMG_Load("hero/personnageD.png");
	p->hero_left = IMG_Load("hero/personnageG.png");
	p->vie[0] = IMG_Load("backg/vie3.png");
	p->vie[1] = IMG_Load("backg/vie2.png");
	p->vie[2] = IMG_Load("backg/vie1.png");
	p->vie[3] = IMG_Load("backg/vie0.png");	
	p->bar_score=NULL;
	p->pos_vie.x=1500;p->pos_vie.y=50;
	p->pos_score.x=1700;p->pos_score.y=55;
	p->score=0;
	p->health=100;
	p->death=0;
	p->direction=0;
	p->vitesse = 30;
	p->jump=150;
	p->jump_count=0;
	p->acceleration = 0;
	p->state=idle;
	p->pos_hero.x=60;
	p->pos_hero.y=800;
	p->pos_hero.w=195;
	p->pos_hero.h=195;
	p->frame_i=0;p->frame_i1=0;p->frame_i2=0;p->frame_wl=0;p->frame_j=0;p->frame_dj=0;p->frame_a=0;p->frame_h=0;p->frame_d=0;p->frame_c=0;
	p->police = TTF_OpenFont("SF_TransRobotics_Bold.ttf",40);
}
void initPerso2(personne *p)
{
	int j=0;
//right
	//idle	 
	for(int i=0;i<6;i++)
	{
		p->animheroRight[0][i].x= (0+(i*192));
		p->animheroRight[0][i].y= 0;
		p->animheroRight[0][i].w= 195;
		p->animheroRight[0][i].h= 195;
	}
	//idle1
	for(int i=0;i<6;i++)
	{
		p->animheroRight[1][i].x= (0+(i*192));
		p->animheroRight[1][i].y= 197;
		p->animheroRight[1][i].w= 196;
		p->animheroRight[1][i].h= 196;
	}
	//idle2
	for(int i=0;i<15;i++)
	{
		p->animheroRight[2][i].x= (0+(i*192));
		p->animheroRight[2][i].y= 393;
		p->animheroRight[2][i].w=196;
		p->animheroRight[2][i].h= 196;
	}
	//walking
	for(int i=0;i<6;i++)
	{
		p->animheroRight[3][i].x= (0+(i*192));
		p->animheroRight[3][i].y= 630;
		p->animheroRight[3][i].w= 196;
		p->animheroRight[3][i].h= 196;
	}
	//jumping
		for(int i=0;i<6;i++)
	{
		p->animheroRight[4][i].x= (0+(i*195));
		p->animheroRight[4][i].y= 846;
		p->animheroRight[4][i].w= 196;
		p->animheroRight[4][i].h= 210;
	}
	//doublejump
		for(int i=0;i<4;i++)
	{
		p->animheroRight[5][i].x= (1392+(i*192));
		p->animheroRight[5][i].y= 846;
		p->animheroRight[5][i].w= 196;
		p->animheroRight[5][i].h= 210;
	}
	//attackhalf1
		for(int i=0;i<3;i++)
	{
		p->animheroRight[6][i].x= (0+(i*267));
		p->animheroRight[6][i].y= 1290;
		p->animheroRight[6][i].w= 258;
		p->animheroRight[6][i].h= 210;
	}
	//attackhalf2
	for(int i=3;i<6;i++) // Attack-half#2:
	{
		p->animheroRight[6][i].x= (840+(j*240));
		p->animheroRight[6][i].y= 1290;
		p->animheroRight[6][i].w= 225;
		p->animheroRight[6][i].h= 210;
		j++;
	}
	j=0;
	//hit
	for(int i=0;i<2;i++)
	{
		p->animheroRight[7][i].x= (0+(i*270));
		p->animheroRight[7][i].y= 10275;
		p->animheroRight[7][i].w= 270;
		p->animheroRight[7][i].h= 210;
	}
	//deathhalf1
	for(int i=0;i<4;i++)
	{
		p->animheroRight[8][i].x= (0+(i*270));
		p->animheroRight[8][i].y= 11520;
		p->animheroRight[8][i].w= 255;
		p->animheroRight[8][i].h= 195;
	}
	//deathhalf2
	for(int i=4;i<9;i++)
	{
		p->animheroRight[8][i].x= (1050+(j*228));
		p->animheroRight[8][i].y= 11520;
		p->animheroRight[8][i].w= 210;
		p->animheroRight[8][i].h= 195;
		j++;
	}
	j=0;
	//crouch
	for(int i=0;i<2;i++)
	{
		p->animheroRight[9][i].x= (0+(i*195));
		p->animheroRight[9][i].y= 1065;
		p->animheroRight[9][i].w= 192;
		p->animheroRight[9][i].h= 180;
	}

//left
	//idle
	for(int i=0;i<6;i++) // 
	{
		p->animheroLeft[0][i].x= (4125-(i*192));
		p->animheroLeft[0][i].y= 0;
		p->animheroLeft[0][i].w= 195;
		p->animheroLeft[0][i].h= 195;
	}
	//idle1
	for(int i=0;i<6;i++) 
	{
		p->animheroLeft[1][i].x= (4125-(i*192));
		p->animheroLeft[1][i].y= 196;
		p->animheroLeft[1][i].w= 195;
		p->animheroLeft[1][i].h= 196;
	}
	//idle2
	for(int i=0;i<15;i++)
	{
		p->animheroLeft[2][i].x= (4125-(i*192));
		p->animheroLeft[2][i].y= 392;
		p->animheroLeft[2][i].w= 195;
		p->animheroLeft[2][i].h= 196;
	}
	//walking
	for(int i=0;i<6;i++)
	{
		p->animheroLeft[3][i].x= (4125-(i*192));
		p->animheroLeft[3][i].y= 630;
		p->animheroLeft[3][i].w= 195;
		p->animheroLeft[3][i].h= 195;
	}
	//jumping
	for(int i=0;i<6;i++)
	{
		p->animheroLeft[4][i].x= (4125-(i*195));
		p->animheroLeft[4][i].y= 846;
		p->animheroLeft[4][i].w= 195;
		p->animheroLeft[4][i].h= 210;
	}
	//doublejumping
		for(int i=0;i<4;i++) 
	{
		p->animheroLeft[5][i].x= (2730-(i*192));
		p->animheroLeft[5][i].y= 846;
		p->animheroLeft[5][i].w= 195;
		p->animheroLeft[5][i].h= 210;
	}
	//attackhalf1
	for(int i=0;i<3;i++) 
	{
		p->animheroLeft[6][i].x= (4080-(i*270));
		p->animheroLeft[6][i].y= 1290;
		p->animheroLeft[6][i].w= 240;
		p->animheroLeft[6][i].h= 210;
	}
	//attackhalf2
	for(int i=3;i<6;i++) 
	{
		p->animheroLeft[6][i].x= (3240-(j*240));
		p->animheroLeft[6][i].y= 1290;
		p->animheroLeft[6][i].w= 225;
		p->animheroLeft[6][i].h= 210;
		j++;
	}
	j=0;
	//hit
	for(int i=0;i<2;i++)
	{
		p->animheroLeft[7][i].x= (4050-(i*270));
		p->animheroLeft[7][i].y= 10350;
		p->animheroLeft[7][i].w= 270;
		p->animheroLeft[7][i].h= 210;
	}
	//deathhalf1
	for(int i=0;i<4;i++) 
	{
		p->animheroLeft[8][i].x= (4050-(i*270));
		p->animheroLeft[8][i].y= 11520;
		p->animheroLeft[8][i].w= 255;
		p->animheroLeft[8][i].h= 195;
	}
	//deathhalf2
	for(int i=3;i<9;i++) 
	{
		p->animheroLeft[8][i].x= (3270-(j*225));
		p->animheroLeft[8][i].y= 11520;
		p->animheroLeft[8][i].w= 225;
		p->animheroLeft[8][i].h= 195;
		j++;
	}
	//crouch
		for(int i=0;i<2;i++) 
	{
		p->animheroLeft[9][i].x= (4128-(i*192));
		p->animheroLeft[9][i].y= 1065;
		p->animheroLeft[9][i].w= 192;
		p->animheroLeft[9][i].h= 180;
	}
	p->hero_right = IMG_Load("hero/personnageD_red.png");
	p->hero_left = IMG_Load("hero/personnageG_red.png");
	p->vie[0] = IMG_Load("backg/vie3.png");
	p->vie[1] = IMG_Load("backg/vie2.png");
	p->vie[2] = IMG_Load("backg/vie1.png");
	p->vie[3] = IMG_Load("backg/vie0.png");	
	p->bar_score=NULL;
	p->pos_vie.x=1500;p->pos_vie.y=50;
	p->pos_score.x=1700;p->pos_score.y=55;
	p->score=0;
	p->health=100;
	p->death=0;
	p->direction=0;
	p->vitesse = 30;
	p->jump=150;
	p->jump_count=0;
	p->acceleration = 0;
	p->state=idle;
	p->pos_hero.x=300;
	p->pos_hero.y=800;
	p->pos_hero.w=195;
	p->pos_hero.h=195;
	p->frame_i=0;p->frame_i1=0;p->frame_i2=0;p->frame_wl=0;p->frame_j=0;p->frame_dj=0;p->frame_a=0;p->frame_h=0;p->frame_d=0;p->frame_c=0;
	p->police = TTF_OpenFont("SF_TransRobotics_Bold.ttf",40);
}
void afficherPerso(personne p, SDL_Surface * screen_p)
{	//conditions d'affichage:
	//idle
	if(p.direction==0 && p.state==idle) SDL_BlitSurface(p.hero_right,&p.animheroRight[idle][p.frame_i],screen_p,&p.pos_hero);
	else if(p.direction==1 && p.state==idle) SDL_BlitSurface(p.hero_left,&p.animheroLeft[idle][p.frame_i],screen_p,&p.pos_hero);
	//idle1
	if(p.direction==0 && p.state==idle1) SDL_BlitSurface(p.hero_right,&p.animheroRight[idle1][p.frame_i1],screen_p,&p.pos_hero);
	else if(p.direction==1 && p.state==idle1) SDL_BlitSurface(p.hero_left,&p.animheroLeft[idle1][p.frame_i1],screen_p,&p.pos_hero);
	//idle2
	if(p.direction==0 && p.state==idle2) SDL_BlitSurface(p.hero_right,&p.animheroRight[idle2][p.frame_i2],screen_p,&p.pos_hero);
	else if(p.direction==1 && p.state==idle2) SDL_BlitSurface(p.hero_left,&p.animheroLeft[idle2][p.frame_i2],screen_p,&p.pos_hero);
	//walking
	if(p.direction==0 && p.state==walking) SDL_BlitSurface(p.hero_right,&p.animheroRight[walking][p.frame_wl],screen_p,&p.pos_hero);
	else if(p.direction==1 && p.state==walking) SDL_BlitSurface(p.hero_left,&p.animheroLeft[walking][p.frame_wl],screen_p,&p.pos_hero);
	//jumping
	if(p.direction==0 && p.state==jumping) SDL_BlitSurface(p.hero_right,&p.animheroRight[jumping][p.frame_j],screen_p,&p.pos_hero);
	else if(p.direction==1 && p.state==jumping) SDL_BlitSurface(p.hero_left,&p.animheroLeft[jumping][p.frame_j],screen_p,&p.pos_hero);
	//doublejumping
	if(p.direction==0 && p.state==doublejumping) SDL_BlitSurface(p.hero_right,&p.animheroRight[doublejumping][p.frame_dj],screen_p,&p.pos_hero);
	else if(p.direction==1 && p.state==doublejumping) SDL_BlitSurface(p.hero_left,&p.animheroLeft[doublejumping][p.frame_dj],screen_p,&p.pos_hero);
	//attacking
	if(p.direction==0 && p.state==attacking) SDL_BlitSurface(p.hero_right,&p.animheroRight[attacking][p.frame_a],screen_p,&p.pos_hero);
	else if(p.direction==1 && p.state==attacking) SDL_BlitSurface(p.hero_left,&p.animheroLeft[attacking][p.frame_a],screen_p,&p.pos_hero);
	//death
	if(p.direction==0 && p.state==die) SDL_BlitSurface(p.hero_right,&p.animheroRight[die][p.frame_d],screen_p,&p.pos_hero);
	else if(p.direction==1 && p.state==die) SDL_BlitSurface(p.hero_left,&p.animheroLeft[die][p.frame_d],screen_p,&p.pos_hero);
	//hit
	if(p.direction==0 && p.state==hit) SDL_BlitSurface(p.hero_right,&p.animheroRight[hit][p.frame_h],screen_p,&p.pos_hero);
	else if(p.direction==1 && p.state==hit) SDL_BlitSurface(p.hero_left,&p.animheroLeft[hit][p.frame_h],screen_p,&p.pos_hero);
	//crouching
	if(p.direction==0 && p.state==crouch) SDL_BlitSurface(p.hero_right,&p.animheroRight[9][p.frame_c],screen_p,&p.pos_hero);
	else if(p.direction==1 && p.state==crouch) SDL_BlitSurface(p.hero_left,&p.animheroLeft[9][p.frame_c],screen_p,&p.pos_hero);
}

void deplacerPerso (personne *p)
{
	if((p->direction==0)&&(p->pos_hero.x<5000-195)) //right
	{
		p->pos_hero.x+=(p->vitesse+p->acceleration);
	}
	else if((p->direction==1)&&(p->pos_hero.x>0))//left
	{
		p->pos_hero.x-=(p->vitesse+p->acceleration);
	}
}
void animerPerso (personne* p)
{	//animation par codition:
	//idle
	if((p->direction==0 || p->direction==1) && p->state==idle)
	{
		p->frame_i++;
		if(p->frame_i==5)
		p->frame_i=0;
	}
	//idle1
	if((p->direction==0 || p->direction==1) && p->state==idle1)
	{
		p->frame_i1++;
		if(p->frame_i1==5)
		p->frame_i1=0;
	}
	//idle2
	if((p->direction==0 || p->direction==1) && p->state==idle2)
	{
		p->frame_i2++;
		if(p->frame_i2==14)
		p->frame_i2=0;
	}
	//walking
	if((p->direction==0 || p->direction==1) && p->state==walking)
	{
		p->frame_wl++;
		if(p->frame_wl==6)
		p->frame_wl=0;
	}
	//jumping
	if((p->direction==0 || p->direction==1) && p->state==jumping)
	{
		p->frame_j++;
		if(p->frame_j==6)
		p->frame_j=0;
	}
	//doublejumping
	if((p->direction==0 || p->direction==1) && p->state==doublejumping)
	{
		p->frame_dj++;
		if(p->frame_dj==4)
		p->frame_dj=0;
	}
	//attacking
	if((p->direction==0 || p->direction==1) && p->state==attacking)
	{
		p->frame_a++;
		if(p->frame_a==6)
		p->frame_a=0;
	}
	//hit
	if((p->direction==0 || p->direction==1) && p->state==hit)
	{
		p->frame_h++;
		if(p->frame_h==2)
		p->frame_h=0;
	}
	//death
	if((p->direction==0 || p->direction==1) && p->state==die)
	{
		p->frame_d++;
		if(p->frame_d>=8)
		p->frame_d=8;
	}
	//crouching
	if((p->direction==0 || p->direction==1) && p->state==crouch)
	{
		p->frame_c++;
		if(p->frame_c>=2)
		p->frame_c=1;
	}
}

void saut (personne* p)
{
	//jump
	if(p->jump_count==1 || p->jump_count==2)
	{
		p->pos_hero.y-=p->jump;
	}
}
void pulltrigger(personne* p)
{
	if(p->pos_hero.y <800)//triggered by "fonction saut"
	{
		p->pos_hero.y+=15;	
	}
	//reached the usual y
	if(p->pos_hero.y>=800 && (p->state==jumping || p->state==doublejumping || p->state==die))
	{
		p->pos_hero.y=800;
		if(p->state!=die)
			p->state=idle;
	}
}
void randomizer(personne *p,int state_i)
{
	
	if(!state_i) p->state = idle; 
	else if(state_i==1) p->state = idle1; 
	else if(state_i==2) p->state = idle2; 
}
void afficherscorevie(personne p, SDL_Surface * screen_s)
{
	//affichage score : 
	SDL_Color RED ={255,0,0};
	char tab[80];
	sprintf(tab,"Score : %d",p.score);
	p.bar_score=TTF_RenderText_Blended(p.police,tab,RED);
	SDL_BlitSurface(p.bar_score,NULL,screen_s,&p.pos_score);
	//affichage bar de vie :
	if(p.health<=100 && p.health>=66)
	{
		SDL_BlitSurface(p.vie[0],NULL,screen_s,&p.pos_vie);
	}
	else if(p.health<66 && p.health>=33)
	{
		SDL_BlitSurface(p.vie[1],NULL,screen_s,&p.pos_vie);
	}
	else if(p.health<33 && p.health>=10)
	{
		SDL_BlitSurface(p.vie[2],NULL,screen_s,&p.pos_vie);
	}
	else if(p.health<=0)
	{
		SDL_BlitSurface(p.vie[3],NULL,screen_s,&p.pos_vie);
	}
	
}
void free_perso(personne *p)
{
	SDL_FreeSurface(p->bar_score);
	SDL_FreeSurface(p->hero_right);
	SDL_FreeSurface(p->hero_left);
	SDL_FreeSurface(p->vie[0]);
	SDL_FreeSurface(p->vie[1]);
	SDL_FreeSurface(p->vie[2]);
	SDL_FreeSurface(p->vie[3]);
	TTF_CloseFont(p->police);
}
