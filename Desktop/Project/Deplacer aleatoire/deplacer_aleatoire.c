#include "deplacer_aleatoire.h"
entity init_entity (char ch[])
{
    entity e;
    e.objet=IMG_Load(ch);
    e.pos_objet.x=0;e.pos_objet.y=0;
    e.direction=0;
    return e;
}
entity deplacer_entity (entity e)
{
    //e=init_entity(ch);
    if (e.pos_objet.x>=500)
        e.direction=1;
    if (e.pos_objet.x<=0)
        e.direction=0;
    if (e.direction==0) e.pos_objet.x+=50;
    else if (e.direction==1) e.pos_objet.x-=20;
    return e;
}
