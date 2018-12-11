#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <string.h>
#include <stdlib.h>
#include "profil.h"
#include <gtk/gtk.h>
#include <stdio.h>


void creer_p(prof m)
{
	FILE *f;
        
	f=fopen("/home/hela/Projects/project1/src/profil.txt","a+");
	if (f!=NULL)
	{

	
	fprintf(f,"%s %s %s %s %s\n",m.id,m.num,m.adresse,m.email,m.specialite);
	fclose(f);
	}
	else printf("impossssible d'ouvrir\n");

}


void modifier_p(prof m)
{
    prof m1;
    FILE *f;
    FILE *f2;
    f2=NULL;
    f=fopen("/home/hela/Projects/project1/src/profil.txt","r");
    f2=fopen("/home/hela/Projects/project1/src/profil1.txt","a+");
    if (f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%s %s %s %s %s\n",m1.id,m1.num,m1.adresse,m1.email,m1.specialite);
            if(strcmp(m1.id,m.id)==0)
            {
			fprintf(f2,"%s %s %s %s %s\n",m.id,m.num,m.adresse,m.email,m.specialite);
            }
  	    else
            {
	     		fprintf(f2,"%s %s %s %s %s\n",m1.id,m1.num,m1.adresse,m1.email,m1.specialite);
	    }	
	}
}
    fclose(f2);
    fclose(f);
    
    rename("/home/hela/Projects/project1/src/profil1.txt","/home/hela/Projects/project1/src/profil.txt");
int verifier1(char num[50])
{
	int res=0;
	prof m1;
	FILE *f;
	f=fopen("/home/hela/Projects/project1/src/profil.txt","r");
	if(f!=NULL)
	{
		while (fscanf(f,"%s %s %s %s %s\n",m1.id,m1.num,m1.adresse,m1.email,m1.specialite)!=EOF)
		{
			if(strcmp(m.id,m1.id)==0)
			{
				res=1;
				
			}
		}
	}
	return res;
	}
}
