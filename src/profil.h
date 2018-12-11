#include <gtk/gtk.h>

struct profil
{ 
  char id[50];
  char num[50];
  char adresse[50];
  char email[50];
  char specialite[50];

};
typedef struct profil prof;

void creer_p(prof m);
void modifier_p(prof m);
int verifier(char id[50]);
