
#include "header.h"

SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
    SDL_Color color;
    Uint32 col = 0;
    char *pPosition = (char *)pSurface->pixels;
    pPosition += (pSurface->pitch * y);
    pPosition += (pSurface->format->BytesPerPixel * x);
    memcpy(&col, pPosition, pSurface->format->BytesPerPixel);

    SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
    return (color);
}

int collision_parfaite_right(SDL_Surface *mask, SDL_Rect posjoueur, SDL_Rect camera)
{
    SDL_Color col, colp;
    SDL_Rect pos[8];
    int collision = 0;
    int i, w, h;

    col.r = 0;
    col.g = 0;
    col.b = 0; // cad : col c'est le couleur noir

    w = 195; // width for perso
    h = 195; // height for perso

    /*-------coordonnes d point n°1-------*/
    pos[5].x = posjoueur.x + w + camera.x;
    pos[5].y = posjoueur.y + camera.y;

    /*-------coordonnes d point n°2-------*/
    pos[6].x = posjoueur.x + w + camera.x;
    pos[6].y = posjoueur.y + h / 2 + camera.y;

    /*-------coordonnes d point n°3-------*/
    pos[7].x = posjoueur.x + w + camera.x;
    pos[7].y = posjoueur.y + h + camera.y;

    for (i = 5; (i < 8) && (collision == 0); i++)
    {
        colp = GetPixel(mask, pos[i].x, pos[i].y); // couleur point dans le mask
        if ((col.r == colp.r) && (col.g == colp.g) && (col.b == colp.b)) // comparaison colp par rapport couleur noir
            collision = 1;
    }

    return (collision);
}

int collision_parfaite_left(SDL_Surface *mask, SDL_Rect posjoueur, SDL_Rect camera)
{
    SDL_Color col, colp;
    SDL_Rect pos[8];
    int collision = 0;
    int i, w, h;
    col.r = 0;
    col.g = 0;
    col.b = 0;

    w = 195;
    h = 195;

    pos[0].x = posjoueur.x + camera.x;
    pos[0].y = posjoueur.y + camera.y;

    pos[1].x = posjoueur.x + camera.x;
    pos[1].y = posjoueur.y + h / 2 + camera.y;

    pos[2].x = posjoueur.x + camera.x;
    pos[2].y = posjoueur.y + h + camera.y;

    for (i = 0; (i < 3) && (collision == 0); i++)
    {
        colp = GetPixel(mask, pos[i].x, pos[i].y);
        if ((col.r == colp.r) && (col.g == colp.g) && (col.b == colp.b))
            collision = 1;
    }
    return (collision);
}

int collision_parfaite_up(SDL_Surface *mask, SDL_Rect posjoueur, SDL_Rect camera)
{
    SDL_Color col, colp;
    SDL_Rect pos;
    int collision = 0;
    int w, h;
    col.r = 0;
    col.g = 0;
    col.b = 0;

    w = 44;
    h = 70;

    pos.x = posjoueur.x + w / 2 + camera.x;
    pos.y = posjoueur.y + camera.y;

    colp = GetPixel(mask, pos.x, pos.y);

    if ((col.r == colp.r) && (col.g == colp.g) && (col.b == colp.b))
        collision = 1;

    return (collision);
}

int collision_parfaite_down(SDL_Surface *mask, SDL_Rect posjoueur, SDL_Rect camera)
{
    SDL_Color col, colp;
    SDL_Rect pos;
    int collision = 0;
    int  w,h;
    col.r = 0;
    col.g = 0;
    col.b = 0;

    w = 44;
    h = 70;

    pos.x = posjoueur.x + w / 2 + camera.x;
    pos.y = posjoueur.y + h + camera.y;

    colp = GetPixel(mask, pos.x, pos.y);

    if ((col.r == colp.r) && (col.g == colp.g) && (col.b == colp.b))
        collision = 1;

    return (collision);
}
