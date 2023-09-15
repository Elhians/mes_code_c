#include "liste_chainee.h"

void insertion_debut(Liste *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;
    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
    liste->nombre_element++;
}

void insertion(Liste *liste, Element *precedent, int nvnombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    Element *actuel = liste->premier;

    if (nouveau == NULL || precedent == NULL || actuel == NULL ||  liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (actuel != precedent)
    {
        actuel = actuel->suivant;
    }

    nouveau->nombre = nvnombre;
    nouveau->suivant = actuel->suivant;
    actuel->suivant = nouveau;
    liste->nombre_element++;
}

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;
    liste->nombre_element = 1;

return liste;
}

void affiche_liste(Liste *liste)
{
    Element *actuel = liste->premier;

    if (actuel == NULL || liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (actuel != NULL)
    {
        printf("%d->", actuel->nombre);
        
        actuel = actuel->suivant;
    }
    
}

void supprime_premier(Liste *liste)
{
    Element *asupprimer = malloc(sizeof(*asupprimer));

    if (liste == NULL || asupprimer == NULL)
    {
        exit(EXIT_FAILURE);
    }

    asupprimer = liste->premier;
    liste->premier = liste->premier->suivant;
    free(asupprimer);
    liste->nombre_element--;
    
}

void supprimer_element(Liste *liste, Element *asupprimer, Element *precedent)
{
    Element *actuel = liste->premier;

    if (actuel == NULL || asupprimer ==NULL || precedent == NULL || liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    while (actuel != asupprimer)
    {
        actuel = actuel->suivant;
    }

    precedent->suivant = actuel->suivant;
    free(actuel);
    liste->nombre_element--;

}

void supprime_liste(Liste *liste)
{
    Element *actuel= liste->premier;

    if (liste == NULL || actuel == NULL )
    {
        exit(EXIT_FAILURE);
    }
    
    while (actuel != NULL)
    {

        Element *suivant = actuel->suivant;
        free(actuel);
        actuel = suivant;
        
    }

    
}

long compte_element(Liste *liste)
{
    Element *actuel = liste->premier;
    long compteur = 0;

    if (actuel == NULL || liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    while (actuel != NULL)
    {
        actuel = actuel->suivant;
        compteur++;
    }
    
    return compteur;
}