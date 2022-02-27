#include"header.h"
void initanimation(image tabimg[])
{
int i;
tabimg[0].img=IMG_Load("backg/00.png");
tabimg[1].img=IMG_Load("backg/01.png");
tabimg[2].img=IMG_Load("backg/02.png");
tabimg[3].img=IMG_Load("backg/03.png");
tabimg[4].img=IMG_Load("backg/04.png");
tabimg[5].img=IMG_Load("backg/05.png");
tabimg[6].img=IMG_Load("backg/06.png");
tabimg[7].img=IMG_Load("backg/07.png");
tabimg[8].img=IMG_Load("backg/08.png");
tabimg[9].img=IMG_Load("backg/09.png");
tabimg[10].img=IMG_Load("backg/10.png");
tabimg[11].img=IMG_Load("backg/11.png");
tabimg[12].img=IMG_Load("backg/12.png");
tabimg[13].img=IMG_Load("backg/13.png");
tabimg[14].img=IMG_Load("backg/14.png");
tabimg[15].img=IMG_Load("backg/15.png");
tabimg[16].img=IMG_Load("backg/16.png");
tabimg[17].img=IMG_Load("backg/17.png");
tabimg[18].img=IMG_Load("backg/18.png");
tabimg[19].img=IMG_Load("backg/19.png");
tabimg[20].img=IMG_Load("backg/20.png");
tabimg[21].img=IMG_Load("backg/21.png");
tabimg[22].img=IMG_Load("backg/22.png");
tabimg[23].img=IMG_Load("backg/23.png");
tabimg[24].img=IMG_Load("backg/24.png");
tabimg[25].img=IMG_Load("backg/25.png");
tabimg[26].img=IMG_Load("backg/26.png");
tabimg[27].img=IMG_Load("backg/27.png");
tabimg[28].img=IMG_Load("backg/28.png");
tabimg[29].img=IMG_Load("backg/29.png");
tabimg[30].img=IMG_Load("backg/30.png");
tabimg[31].img=IMG_Load("backg/31.png");
tabimg[32].img=IMG_Load("backg/32.png");
tabimg[33].img=IMG_Load("backg/33.png");
tabimg[34].img=IMG_Load("backg/34.png");
tabimg[35].img=IMG_Load("backg/35.png");

    
    for (i=0;i<36;i++)
    	{
    	tabimg[i].pos.y=0;
    	tabimg[i].pos.x = 0;
    	}
}
void libereranimation (image tabimg[])
{
int i;
for (i=0;i<36;i++)
    	SDL_FreeSurface(tabimg[i].img);
}

