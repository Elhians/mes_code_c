#ifndef _LISTECHAINEE_H
#define _LISTECHAINEE_H
#include "entete.h"

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};
typedef struct Liste Liste;
struct Liste
{
    Element *premier;
    long nombre_element;
};

void insertion_debut(Liste *liste, int nvNombre);
void insertion(Liste *liste, Element *precedent, int nvnombre);
Liste *initialisation();
void affiche_liste(Liste *liste);
void supprime_premier(Liste *liste);
void supprimer_element(Liste *liste, Element *asupprimer, Element *precedent);
void supprime_liste(Liste *liste);
long compte_element(Liste *liste);

#endif