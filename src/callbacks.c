#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fiche.h"
#include "disponibilite.h"
#include "profil.h"

#include <string.h>
//ajout fiche
 void on_button10_clicked (GtkWidget *objet_graphique , gpointer user_data)

{
        nouv f1;
        GtkWidget *entry12;
        GtkWidget *entry13;
        GtkWidget *entry14;
        GtkWidget *entry15;
        GtkWidget *entry16;
        GtkWidget *entry17;
        GtkWidget *entry26;
        GtkWidget *entry27;
       
	GtkWidget *input13=lookup_widget(objet_graphique,"entry13");
	GtkWidget *input14=lookup_widget(objet_graphique,"entry14");
	GtkWidget *input16=lookup_widget(objet_graphique,"entry16");
	GtkWidget *input26=lookup_widget(objet_graphique,"entry26");
	GtkWidget *input27=lookup_widget(objet_graphique,"entry27");
	GtkWidget *input15=lookup_widget(objet_graphique,"entry15");
	GtkWidget *input17=lookup_widget(objet_graphique,"entry17");
	GtkWidget *input12=lookup_widget(objet_graphique,"entry12");
	
	strcpy(f1.id,gtk_entry_get_text(GTK_ENTRY(input12)));
	strcpy(f1.nom,gtk_entry_get_text(GTK_ENTRY(input13)));
	strcpy(f1.prenom,gtk_entry_get_text(GTK_ENTRY(input14)));
	strcpy(f1.nee,gtk_entry_get_text(GTK_ENTRY(input16)));
	strcpy(f1.taille,gtk_entry_get_text(GTK_ENTRY(input26)));
	strcpy(f1.poids,gtk_entry_get_text(GTK_ENTRY(input27)));
	strcpy(f1.groupe,gtk_entry_get_text(GTK_ENTRY(input15)));
	strcpy(f1.description,gtk_entry_get_text(GTK_ENTRY(input17)));

      ajout_fiche(f1);
      
} 




 /*

void on_button8_clicked(GtkWidget *object_graphique , gpointer user_data)
{

char id[20];
GtkWidget *input;
GtkWidget *output;
char error[50];
char succes[70];
int l;
nouv f1;
input=lookup_widget(object_graphique,"entry11");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
output=lookup_widget(object_graphique,"label58");


if (verifier(id)==1)
	{
		l=rechercher_fiche(id);
		strcpy(succes,"L'adherent portant cet ID est dans notre base");
		gtk_label_set_text(GTK_LABEL(output),succes);
                
	}
	else
	{
		strcpy(error,"adherent inexistant! Vérifiez S.V.P.");
		
	}
*/




void on_button6_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
	
}













// bouton pour la suppression
void
on_button_medecin_clicked              (GtkWidget *objet_graphique,gpointer user_data)
{
	GtkWidget *input;
	GtkWidget *output;
	char id[50];
        int r;
	output=lookup_widget(objet_graphique,"label59");
	input=lookup_widget(objet_graphique,"entry10");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
	r=supprimer_fiche(id);
	if (r==1)
	{
	gtk_label_set_text(GTK_LABEL(output),"succes");
	}
	else
	gtk_label_set_text(GTK_LABEL(output),"erreur");
}
 
// boutton pour l'affichage
void
on_button21_clicked                    (GtkWidget *objet_graphique,gpointer user_data)
{


GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
GtkWidget *liste;

fenetre_afficher=lookup_widget(objet_graphique,"window2");
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_fiche(treeview1);



}

// boutton pour la modification
void
on_button4_clicked                     (GtkWidget *objet_graphique,gpointer user_data)
{
        GtkWidget *input9;
        GtkWidget *input4;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input6;
        GtkWidget *input7;
        GtkWidget *input5;
        GtkWidget *input8;
	GtkWidget *output;
	GtkWidget *window2;
	GtkWidget *window1;
	nouv f1;
	nouv m;
   	FILE *f9;
	char id[50];
	char error[100];
	int x;
	input4=lookup_widget(objet_graphique,"entry4");
        input9=lookup_widget(objet_graphique,"entry9");
        input1=lookup_widget(objet_graphique,"entry1");
        input2=lookup_widget(objet_graphique,"entry2");
        input3=lookup_widget(objet_graphique,"entry3");
	input6=lookup_widget(objet_graphique,"entry7");
        input7=lookup_widget(objet_graphique,"entry6");
        input5=lookup_widget(objet_graphique,"entry5");
        input8=lookup_widget(objet_graphique,"entry8");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input9)));
	x=verifier1(id);
	if (x==1)
	{
		window2=lookup_widget(objet_graphique,"window2");
		gtk_widget_hide(window2);
		f9=fopen("/home/hela/Projects/project1/src/fichier.txt", "r");
		if(f9!=NULL)
   	 	{
   	 	    while(fscanf(f9,"%s %s %s %s %s %s %s %s\n",f1.id,f1.nom,f1.prenom,f1.nee,f1.taille,f1.poids,f1.groupe,f1.description)!=EOF)
   	 	    {
   	 	        if(strcmp(id,f1.id)==0)
   	 	        {
				window1=create_window1();
				gtk_widget_show (window1);
			
				
				/*gtk_entry_set_text (GTK_ENTRY (input4),f1.id);
				gtk_entry_set_text (GTK_ENTRY (input1),f1.nom);
				gtk_entry_set_text (GTK_ENTRY (input2),f1.prenom);
                                gtk_entry_set_text (GTK_ENTRY (input3),f1.nee);
                                gtk_entry_set_text (GTK_ENTRY (input6),f1.poids);
                                gtk_entry_set_text (GTK_ENTRY (input7),f1.taille);
                                gtk_entry_set_text (GTK_ENTRY (input5),f1.groupe);
                                gtk_entry_set_text (GTK_ENTRY (input8),f1.description);*/

				
			}
   	 	    }
   	 	}
	}
	else if (x==0)
	{
		strcpy(error,"medecin inexistant! Vérifiez S.V.P.");
		output=lookup_widget(objet_graphique,"label61");
		gtk_label_set_text(GTK_LABEL(output),error);
	}
}

						
       

// ajout dispo
void on_button31_clicked                    (GtkButton *objet_graphique,gpointer user_data)
{ 
char num[10];
date d;
int h;
GtkWidget *input1=lookup_widget(objet_graphique,"entry28");
GtkWidget *j=lookup_widget(objet_graphique,"spinbutton1");
GtkWidget *m=lookup_widget(objet_graphique,"spinbutton2");
GtkWidget *a=lookup_widget(objet_graphique,"spinbutton3");
GtkWidget *combobox=lookup_widget(objet_graphique,"combobox3");

strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));

d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));

if (strcmp("9h==>12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
{
h=1;
}
else if (strcmp("14h==>17h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
{
h=2;
}
ajouter_disponibilite(num,d,h);




}

// boutton de retour
void on_button12_clicked                    (GtkButton *objet_graphique,gpointer user_data)
{

	GtkWidget *window2;
	GtkWidget *window3;
	window2=lookup_widget(objet_graphique,"window2");
	gtk_widget_hide(window2);
	window3=create_window3();
	gtk_widget_show (window3);
}

void
on_button15_clicked                    (GtkButton *objet_graphique,gpointer user_data)
{
        GtkWidget *window3;
	GtkWidget *window6;
	window3=lookup_widget(objet_graphique,"window3");
	gtk_widget_hide(window3);
	window6=create_window6();
	gtk_widget_show (window6);

}


void
on_button13_clicked                    (GtkButton *objet_graphique,gpointer user_data)
{
   GtkWidget *window3;
	GtkWidget *window2;
	window3=lookup_widget(objet_graphique,"window3");
	gtk_widget_hide(window3);
	window2=create_window2();
	gtk_widget_show (window2);

}



void
on_button14_clicked                    (GtkButton *objet_graphique,gpointer user_data)
{
        GtkWidget *window3;
	GtkWidget *window5;
	window3=lookup_widget(objet_graphique,"window3");
	gtk_widget_hide(window3);
	window5=create_window5();
	gtk_widget_show (window5);


}


void
on_button32_clicked                    (GtkButton *objet_graphique,gpointer user_data)
{
        GtkWidget *window5;
	GtkWidget *window3;
	window3=lookup_widget(objet_graphique,"window5");
	gtk_widget_hide(window5);
	window3=create_window3();
	gtk_widget_show (window3);


}
/*

void
on_button24_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}
*/

void
on_button33_clicked                    (GtkButton *objet_graphique,gpointer user_data)
{
   GtkWidget *window6;
	GtkWidget *window3;
	window3=lookup_widget(objet_graphique,"window6");
	gtk_widget_hide(window6);
	window3=create_window3();
	gtk_widget_show (window3);


}

// supp
void
on_button28_clicked                    (GtkButton *objet_graphique,gpointer user_data)
{GtkWidget *input;
	GtkWidget *output;
	char num[10];
        int r;
	output=lookup_widget(objet_graphique,"label76");
	input=lookup_widget(objet_graphique,"entry30");
	strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));
	
        r=supprimer(num);
	if (r==1)
	{
	gtk_label_set_text(GTK_LABEL(output),"succes");
	}
	else
	gtk_label_set_text(GTK_LABEL(output),"erreur");

}
//affichage fiche

void
on_button29_clicked                    (GtkWidget *objet_graphique,gpointer user_data)
{



GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
GtkWidget *liste;

fenetre_afficher=lookup_widget(objet_graphique,"window6");
treeview1=lookup_widget(fenetre_afficher,"treeview2");
afficher(treeview1);



}
 //ajout profil
void
on_button19_clicked                    (GtkWidget *objet_graphique,gpointer user_data)
{


        prof m;
  
        
        GtkWidget *input31=lookup_widget(objet_graphique,"entry31");
	GtkWidget *input22=lookup_widget(objet_graphique,"entry22");
	GtkWidget *input23=lookup_widget(objet_graphique,"entry23");
	GtkWidget *input24=lookup_widget(objet_graphique,"entry24");
	GtkWidget *input25=lookup_widget(objet_graphique,"entry25");
	
	strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(input31)));
        strcpy(m.num,gtk_entry_get_text(GTK_ENTRY(input22)));
	strcpy(m.adresse,gtk_entry_get_text(GTK_ENTRY(input23)));
	strcpy(m.email,gtk_entry_get_text(GTK_ENTRY(input24)));
	strcpy(m.specialite,gtk_entry_get_text(GTK_ENTRY(input25)));
	
	creer_p(m);
      
} 



void
on_button34_clicked                    (GtkWidget *objet_graphique,gpointer user_data)
{

        GtkWidget *input32;
	GtkWidget *input33;
	GtkWidget *input34;
	GtkWidget *input35;
	GtkWidget *input36;
        GtkWidget *input37;
	GtkWidget *output;
	GtkWidget *window7;
	GtkWidget *window5;
	prof m1;
	prof m;
   	FILE *f9;
	char id[50];
	char error[100];
	int x;
	x=verifier1(id);
	input32=lookup_widget(objet_graphique,"entry32");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input32)));
	if (x==0)
	{
		window5=lookup_widget(objet_graphique,"window5");
		gtk_widget_hide(window5);
		f9=fopen("/home/hela/Projects/project1/src/profil.txt", "r");
		if(f9!=NULL)
   	 	{
   	 	    while(fscanf(f9,"%s %s %s %s %s\n",m.id,m.num,m.adresse,m.email,m.specialite)!=EOF)
   	 	    {
   	 	        if(strcmp(id,m.id)==0)
   	 	        {
				window7=create_window7();
				gtk_widget_show (window7);
				input33=lookup_widget(window7,"entry33");
				input34=lookup_widget(window7,"entry34");
				input35=lookup_widget(window7,"entry35");
                                input36=lookup_widget(window7,"entry36");
                                input37=lookup_widget(window7,"entry37");
				gtk_entry_set_text (GTK_ENTRY (input33),m.id);
				gtk_entry_set_text (GTK_ENTRY (input34),m.num);
				gtk_entry_set_text (GTK_ENTRY (input35),m.adresse);
                                gtk_entry_set_text (GTK_ENTRY (input36),m.email);
                                gtk_entry_set_text (GTK_ENTRY (input37),m.specialite);
			}
   	 	    }
   	 	}
	}
	else if (x==1)
	{
		strcpy(error,"medecin inexistant! Vérifiez S.V.P.");
		output=lookup_widget(objet_graphique,"label84");
		gtk_label_set_text(GTK_LABEL(output),error);
	}
}

						




void
on_button35_clicked                    (GtkWidget *objet_graphique,gpointer user_data)
{
prof m;
	GtkWidget *input33;
	GtkWidget *input34;
	GtkWidget *input35;
        GtkWidget *input36;
        GtkWidget *input37;
	GtkWidget *output;
	char valide[100];
	char num[100];
	char nom[100];
	
	input33=lookup_widget(objet_graphique,"entry33");
	input34=lookup_widget(objet_graphique,"entry34");
	input35=lookup_widget(objet_graphique,"entry35");
        input36=lookup_widget(objet_graphique,"entry36");
        input37=lookup_widget(objet_graphique,"entry37");
	output=lookup_widget(objet_graphique,"label85");
	strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(input33)));
	strcpy(m.num,gtk_entry_get_text(GTK_ENTRY(input34)));
	strcpy(m.adresse,gtk_entry_get_text(GTK_ENTRY(input35)));
        strcpy(m.email,gtk_entry_get_text(GTK_ENTRY(input36)));
        strcpy(m.specialite,gtk_entry_get_text(GTK_ENTRY(input37)));
	modifier_p(m);
}

/*
void
on_button1_clicked                     (GtkWidget *objet_graphique,gpointer user_data)
{
nouv f1;
	GtkWidget *input4;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input6;
        GtkWidget *input7;
        GtkWidget *input5;
        GtkWidget *input8;
	//GtkWidget *output;
	GtkWidget *window2;

	char valide[100];
	char num[100];
	char nom[100];
	int x;
	
	input4=lookup_widget(objet_graphique,"entry4");
	input1=lookup_widget(objet_graphique,"entry1");
	input2=lookup_widget(objet_graphique,"entry2");
        input3=lookup_widget(objet_graphique,"entry3");
        input6=lookup_widget(objet_graphique,"entry6");
        input7=lookup_widget(objet_graphique,"entry7");
        input5=lookup_widget(objet_graphique,"entry5");
        input8=lookup_widget(objet_graphique,"entry8");
	
	strcpy(f1.id,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(f1.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(f1.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(f1.nee,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(f1.taille,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(f1.poids,gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(f1.groupe,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(f1.description,gtk_entry_get_text(GTK_ENTRY(input8)));

	
       
	modifier(f1);
}


void
on_valider_clicked                     (GtkWidget *objet_graphique,gpointer user_data)
{       
        GtkWidget *input29;
        GtkWidget *spin_button1;
        GtkWidget *spin_button2;
        GtkWidget *spin_button3;
	
	GtkWidget *output;
	GtkWidget *window6;
	GtkWidget *window8;
	date d1;
	char num[50];
        char hr[50];
   	FILE *f9;
	char num2[50];
	char error[100];
	int x;
	x=verifier1(num);
	input29=lookup_widget(objet_graphique,"entry29");
	strcpy(num2,gtk_entry_get_text(GTK_ENTRY(input29)));
        
	if (x==0)
	{
		window6=lookup_widget(objet_graphique,"window6");
		gtk_widget_hide(window6);
		f9=fopen("/home/hela/Projects/project1/src/dispo.txt", "r");
		if(f9!=NULL)
   	 	{
   	 	    while(fscanf(f9,"%s %s %s %s %s\n",num,d1.jour,d1.mois,d1.annee,hr)!=EOF)
   	 	    {
   	 	        if(strcmp(num2,num)==0)
   	 	        {
				window8=create_window8();
				gtk_widget_show (window8);
				
				
				gtk_entry_set_text (GTK_SPIN_BUTTON1 (spin_button1),d1.jour);
                                
				gtk_entry_set_text (GTK_SPIN_BUTTON2 (spin_button2),d1.mois);
                                gtk_entry_set_text (GTK_SPIN_BUTTON1 (spin_button3),d1.annee);
				
   	 	    }
   	 	}
	}
	else if (x==1)
	{
		strcpy(error,"medecin inexistant! Vérifiez S.V.P.");
		output=lookup_widget(objet_graphique,"label92");
		gtk_label_set_text(GTK_LABEL(output),error);
	}
}


}
/*

void
on__clicked                            (GtkWidget *objet_graphique,gpointer user_data)
{

}


void
on_button25_clicked                    (GtkWidget *objet_graphique,gpointer user_data)
{

}*/

