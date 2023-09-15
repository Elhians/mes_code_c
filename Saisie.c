#include "entete.h"

void vider_buffer()
{
    int c = 0;

    while( c != '\n' && c != EOF)
    {
        c = getchar();
    }
    
}

int saisir_texte(char *chaine, long longueur_chaine)
{

    char *position_du_entree = NULL;

    if (fgets(chaine, longueur_chaine, stdin) == NULL)
    {
        
        printf("ERREUR!\n");
        vider_buffer();

        return 0;
    }
    
    position_du_entree = strchr(chaine, '\n');

    if(position_du_entree != NULL)
    {
        *position_du_entree = '\0';
    }
    else
    {
        vider_buffer();
    }

    return 1;
}

int saisir_double(char *chaine, long longueur_chaine)
{

    char *position_du_entree = NULL;
    char *position_du_virgule = NULL;

    if (fgets(chaine, longueur_chaine, stdin) == NULL)
    {
        
        printf("ERREUR!\n");
        vider_buffer();

        return 0;
    }
    
    position_du_entree = strchr(chaine, '\n');
    position_du_virgule = strchr(chaine, ',');

    if(position_du_virgule != NULL)
    {
        *position_du_virgule = '.';
    }

    if(position_du_entree != NULL)
    {
        *position_du_entree = '\0';
    }
    else
    {
        vider_buffer();
    }

    return 1;
}


int saisir_long(char *chaine, long longueur_chaine)
{

    char *position_du_entree = NULL;

    if (fgets(chaine, longueur_chaine, stdin) == NULL)
    {
        
        printf("ERREUR!\n");
        vider_buffer();

        return 0;
    }

    strtol(chaine, NULL, 10);
    
    position_du_entree = strchr(chaine, '\n');

    if(position_du_entree != NULL)
    {
        *position_du_entree = '\0';
    }
    else
    {
        vider_buffer();
    }

    return 1;
}