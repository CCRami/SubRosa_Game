#include"header.h"
void initanimation(image tabimg[],image tabintro[])
{
int i;
char path[20];
for (i=0;i<36;i++)
{
sprintf(path,"backg/%d.png",i);
tabimg[i].img=IMG_Load(path);

}
    for (i=0;i<36;i++)
    	{
    	tabimg[i].pos.y=0;
    	tabimg[i].pos.x = 0;
    	}
for (i=0;i<52;i++)
{
sprintf(path,"intro/%d.jpg",i+1);
tabintro[i].img=IMG_Load(path);

}
    for (i=0;i<52;i++)
    	{
    	tabintro[i].pos.y=0;
    	tabintro[i].pos.x = 0;
    	}
}
void libereranimation (image tabimg[],image tabintro[])
{
int i;
for (i=0;i<36;i++)
    	SDL_FreeSurface(tabimg[i].img);
for (i=0;i<52;i++)
    	SDL_FreeSurface(tabintro[i].img);
}

