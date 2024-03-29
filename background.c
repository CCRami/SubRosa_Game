#include "header.h"

void initBack(background *b, int x, int y)
{
    b->image = IMG_Load("backg/desert.png");
    b->sprite = IMG_Load("background resources/spritesmall.png");
    b->sprite2 = IMG_Load("background resources/sprite22.png");
    if (b->sprite2 == NULL)
        printf("can't open sprite 2 \n");
    if (b->sprite == NULL)
        printf("error loading sprite \n ");
    b->camera.x = 0;
    b->camera.y = 0;
    b->camera.w = x;
    b->camera.h = y;
    b->mask = IMG_Load("background resources/desertmask.png");
    b->music = Mix_LoadMUS("background resources/music.mp3");
    Mix_PlayMusic(b->music, -1);
    b->i = 0;
    b->j = 0;
    b->pos_anim.x = 0;
    b->pos_anim.y = 200;
    b->pos_sprite.x = 0;
    b->pos_sprite.y = 0;
    b->pos_sprite.w = (int)(160 / 3);
    b->pos_sprite.h = (int)(160 / 3);
    b->x = 0;
    b->y = 0;
    b->pos_anim2.x = 1366 - (int)(626 / 5);
    b->pos_anim2.y = 0;
    b->pos_sprite2.x = 0;
    b->pos_sprite2.y = 0;
    b->pos_sprite2.w = (int)(626 / 5);
    b->pos_sprite2.h = (int)(626 / 5);
}

void afficherBack(background b, SDL_Surface *screen, int x, int y)
{
    SDL_BlitSurface(b.image, &(b.camera), screen, NULL);
}

void scrolling(background *b, int direction, int pasAvancement)
{

    switch (direction)
    {
    case 'R':
            b->camera.x += pasAvancement;
        break;
    case 'L':
            if (b->camera.x >= 0)
            b->camera.x -= pasAvancement;
        break;
    }
}
void animation(background *b, SDL_Surface *screen)
{

    if (b->pos_anim.x < 1920)
    {
        SDL_BlitSurface(b->sprite, &(b->pos_sprite), screen, &(b->pos_anim));
        b->pos_anim.x += 3;
        if (b->pos_anim.x >= 1920)
            b->pos_anim.x = 0;
    }

    b->pos_sprite.x = b->i * (int)(160 / 3);
    b->pos_sprite.y = b->j * (int)(160 / 3);
    (b->i)++;
    if ((b->i) == 3)
    {
        (b->i) = 0;
        (b->j)++;
        if (b->j == 3)
            b->j = 0;
    }
    if (((b->j) == 2) && (b->i == 0))
    {
        (b->i)++;
    }
}
void animation2(background *b, SDL_Surface *screen)
{
    SDL_BlitSurface(b->sprite2, &(b->pos_sprite2), screen, &(b->pos_anim2));

    b->pos_sprite2.x = b->x * (int)(626 / 5);
    b->pos_sprite2.y = b->y * (int)(626 / 5);
    (b->x)++;
    if ((b->x) == 5)
    {
        (b->y)++;
        (b->x) = 0;
        
    }
     if ((b->y == 4)&&(b->x == 1))
            {
                b->y=0;
                b->x=0;
            }
}
