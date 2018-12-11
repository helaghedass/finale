#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <string.h>
#include <stdlib.h>
#include "disponibilite.h"
#include <gtk/gtk.h>
#include <stdio.h>


enum   
{    NUM,
     JOUR,
     MOIS,
     ANNEE,
     HR,  
     COLUMNS  
};
void ajouter_disponibilite(char num[10],date d,int h)
{
	FILE *f;
        
	f=fopen("/home/hela/Projects/project1/src/dispo.txt","a+");
	if (f!=NULL)
	{

	
	fprintf(f,"%s %d %d %d %d\n",num,d.jour,d.mois,d.annee,h);
	fclose(f);
	}
	else printf("impossssible d'ouvrir\n");

}


int supprimer(char num[10])
{
int test=-1;
char m[10];
int h1;
date d1;
FILE *f;
FILE *f2;
f=fopen("/home/hela/Projects/project1/src/dispo.txt","r");
f2=fopen("/home/hela/Projects/project1/src/dispo1.txt","a");




	while (fscanf(f,"%s %d %d %d %d\n",m,&d1.jour,&d1.mois,&d1.annee,&h1)!=EOF)
    {
        if (strcmp(num,m)!=0)
			
	{
	fprintf(f2,"%s %d %d %d %d\n",m,d1.jour,d1.mois,d1.annee,h1);
	}	
	else
	{ 
	test=1;
	}
      }

    fclose(f);
    fclose(f2);
	remove("/home/hela/Projects/project1/src/dispo.txt");
	rename("/home/hela/Projects/project1/src/dispo1.txt","/home/hela/Projects/project1/src/dispo.txt");
return (test);
}



void afficher(GtkWidget *liste)
{
       
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
        date d1;
        char h1[50];
        char m[10];
        store=NULL;

        FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("d1.num", renderer, "text",NUM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("d1.jour", renderer, "text",JOUR, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("hr", renderer, "text",HR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
              
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/hela/Projects/project1/src/dispo.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/hela/Projects/project1/src/dispo.txt", "a+");
              
	      while (fscanf(f,"%s%d%d%d%s\n",m,&d1.jour,&d1.mois,&d1.annee,h1)!=EOF)
{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,NUM, m, JOUR, d1.jour, MOIS, d1.mois, ANNEE, d1.annee, HR, h1,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}


