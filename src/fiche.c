#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <string.h>
#include <stdlib.h>
#include "fiche.h"
#include <gtk/gtk.h>
#include <stdio.h>
enum   
{    ID,
     NOM,
     PRENOM,
     NEE,
     TAILLE,
     POIDS,
     GROUPE,
     DESCRIPTION,  
     COLUMNS  
};

 

void ajout_fiche(nouv f1)
{
	FILE *f;
        
	f=fopen("/home/hela/Projects/project1/src/fichier.txt","a+");
	if (f!=NULL)
	{

	
	fprintf(f,"%s %s %s %s %s %s %s %s\n",f1.id,f1.nom,f1.prenom,f1.nee,f1.taille,f1.poids,f1.groupe,f1.description);
	fclose(f);
	}
	else printf("impossssible d'ouvrir\n");

}

int verifier(char id[50])
{
	 int res=0;
   	 nouv f1;
   	 FILE *f;
   	 f=fopen("/home/hela/Projects/project1/src/fichier.txt", "r");
   	 if(f!=NULL)
   	 {
   	     while(f,"%s %s %s %s %s %s %s %s\n",f1.id,f1.nom,f1.prenom,f1.nee,f1.taille,f1.poids,f1.groupe,f1.description)
   	     {
   	         if(strcmp(id,f1.id)==0)
   	         {
   	             res=1;
   	             break;
   	         }
   	     }
   	     return(res);
   	 }

}




int supprimer_fiche(char id[50])
{int test=-1;
nouv m;
FILE *f;
FILE *f2;
f=fopen("/home/hela/Projects/project1/src/fichier.txt","r");
f2=fopen("/home/hela/Projects/project1/src/fichier1.txt","a");




	while (fscanf(f,"%s %s %s %s %s %s %s %s\n",m.id,m.nom,m.prenom,m.nee,m.taille,m.poids,m.groupe,m.description)!=EOF)
    {
        if (strcmp(id,m.id)!=0)
			
	{
	fprintf(f2,"%s %s %s %s %s %s %s %s\n",m.id,m.nom,m.prenom,m.nee,m.taille,m.poids,m.groupe,m.description);
	}	
	else
	{ 
	test=1;
	}
}

    fclose(f);
    fclose(f2);
	remove("/home/hela/Projects/project1/src/fichier.txt");
	rename("/home/hela/Projects/project1/src/fichier1.txt","/home/hela/Projects/project1/src/fichier.txt");
return (test);
}







void afficher_fiche(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
        nouv m;
	
        store=NULL;

        FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nee", renderer, "text",NEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("taille", renderer, "text",TAILLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("poids", renderer, "text",POIDS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("groupe", renderer, "text",GROUPE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
                
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("description", renderer, "text",DESCRIPTION, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/hela/Projects/project1/src/fichier.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/hela/Projects/project1/src/fichier.txt", "a+");
              
	      while (fscanf(f,"%s%s%s%s%s%s%s%s\n",m.id,m.nom,m.prenom,m.nee,m.taille,m.poids,m.groupe,m.description)!=EOF)
{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,ID, m.id, NOM, m.nom, PRENOM, m.prenom, NEE, m.nee, TAILLE, m.taille, POIDS, m.poids, GROUPE, 			m.groupe, DESCRIPTION, m.description,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}


void modifier(nouv f1)
{
    nouv m;
    FILE *f;
    FILE *f2;
  
    f=fopen("/home/hela/Projects/project1/src/ficher.txt","r");
    f2=fopen("/home/hela/Projects/project1/src/ficher1.txt","a+");
    if (f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%s %s %s %s %s %s %s %s\n",m.id,m.nom,m.prenom,m.nee,m.taille,m.poids,m.groupe,m.description);
            if(strcmp(m.id,f1.id)==0)
            {
			fprintf(f2,"%s %s %s %s %s %s %s %s\n",m.id,m.nom,m.prenom,m.nee,m.taille,m.poids,m.groupe,m.description);
            }
  	    else
            {
	     		fprintf(f2,"%s %s %s %s %s %s %s %s\n",m.id,m.nom,m.prenom,m.nee,m.taille,m.poids,m.groupe,m.description);
	    }	
	}
}
    fclose(f2);
    fclose(f);
    remove("/home/hela/Projects/project1/src/fichier.txt");
    rename("/home/hela/Projects/project1/src/fichier1.txt","/home/hela/Projects/project1/src/fichier.txt");
}
int verifier1(char id[50])
{
	int res=0;
	nouv m1;
	FILE *f;
	f=fopen("/home/hela/Projects/project1/src/fichier.txt","r");
	if(f!=NULL)
	{
		while (fscanf(f,"%s%s%s%s%s%s%s%s\n",m1.id,m1.nom,m1.prenom,m1.nee,m1.taille,m1.poids,m1.groupe,m1.description)!=EOF)
		{
			if(strcmp(id,m1.id)==0)
			{
				res=1;
				
			}
		}
	}
	return res;
}
