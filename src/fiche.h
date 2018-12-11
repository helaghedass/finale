#include <gtk/gtk.h>
struct nouv
{char id[50];
 char nom[50];
 char prenom[50];
 char nee[50];
 char taille[50];
 char poids[50];
 char groupe[50];
 char description[50];
};
typedef struct nouv nouv;
       
 
void ajout_fiche(nouv f1);
int verifier(char id[50]);
int supprimer_fiche(char id[50]);
void afficher_fiche(GtkWidget *liste);
void modifier(nouv f1);
