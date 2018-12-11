
#include <gtk/gtk.h>
typedef struct 
{
int jour;
int mois;
int annee;
}date;
char hr[50];
char num[10];

void ajouter_disponibilite(char num[10],date d,int h);
int supprimer(char num[10]);
void afficher(GtkWidget *liste);
//void modifier(date d);
