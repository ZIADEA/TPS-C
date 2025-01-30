#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20

typedef struct livre {
	int Cote;
	char *Titre ;
	char *Auteur;
	char *Discipline ;
	char *Editeur ;
	int NbExemplaires;
}Livre;
typedef struct Books {
	Livre L;
	struct Books *suivant;
}book;
book *debut,*fin ;
int taille ;
initialisation()
{
	debut = NULL;
	fin = NULL;
	taille =0;
}
int Ajouter_Livre(int co,char *tit,char *aut,char *disc,char *edit,int nbrexm){
	book *element,*courant;
	if(taille!=0){
		courant = debut;
		while(courant!=NULL){
			if(courant->L.Cote==co &&
			strcmp(courant->L.Titre,tit)==0 &&
			strcmp(courant->L.Auteur,aut)==0 &&
			strcmp(courant->L.Discipline,disc)==0 &&
			strcmp(courant->L.Editeur,edit)==0 )
//			courant->L.NbExemplaires==nbrexm)
			{
				courant->L.NbExemplaires +=nbrexm;
				return 0;
			}
			courant = courant->suivant; 
		}
		
	}
	if((element=(book*)malloc(sizeof(book))) == NULL){
		printf("echec de reservation");
		return -1;
	}
	if((element->L.Titre =(char*)malloc(max*sizeof(char))) == NULL){
		printf("echec de reservation");
		return -1;
	}
	if((element->L.Auteur =(char*)malloc(max*sizeof(char))) == NULL){
		printf("echec de reservation");
		return -1;
	}
	if((element->L.Discipline =(char*)malloc(max*sizeof(char))) == NULL){
		printf("echec de reservation");
		return -1;
	}
	if((element->L.Editeur =(char*)malloc(max*sizeof(char))) == NULL){
		printf("echec de reservation");
		return -1;
	}
	
	element->L.Cote = co;
	strcpy(element->L.Titre , tit);
	strcpy(element->L.Auteur , aut);
	strcpy(element->L.Discipline , disc);
	strcpy(element->L.Editeur , edit);
	element->L.NbExemplaires = nbrexm;
	// ajout a laa fin 	
	element->suivant = NULL;
	if(taille == 0 )
		debut = element;
	else fin->suivant=element;
	fin = element;
	taille++;
	return 1;
}

int Retirer_Livre(int co){
	book *courant,*supp,*precd;
	if(taille ==0){
		printf("aucun livre");
		return -1;

	}
		courant=debut;
		while(courant!=NULL){
			if(courant->L.Cote == co){
				courant->L.NbExemplaires-=1;
				if(courant->L.NbExemplaires==0){
					supp=courant;
					if(courant==debut){
						debut = courant->suivant;
						
					}
					else{
						courant=courant->suivant;
						if(courant== NULL){
							precd=debut;
							while(precd->suivant !=fin)
							{
								precd=precd->suivant;
							}
							supp=precd;
						}
					}
					free(supp->L.Auteur);
					free(supp->L.Discipline);
					free(supp->L.Editeur);
					free(supp->L.Titre);
					free(supp);
					taille--;
				}
				return 0;
			}
			courant = courant->suivant;
		}
		printf("le livre n est pas en bibliotheque");
		return-1;
}

int Trier_Bibio(){
	book *courant,*temp,*courant2,*temp2,*debg,*deb3,*courant3,*temp3,*finin;
	if(taille==0){
		printf("aucun livre");
		return -1;
	}
	debg=debut;
	deb3=debut;
	courant=debut;
	while(courant!=NULL){
		if(strcmp(courant->L.Discipline,"Info")==0){
			if(courant!=debut){
				temp=courant;
				courant=courant->suivant;
				temp->suivant=debut;
				debut = temp;
			}
			else courant=courant->suivant;
		}
		else{
			courant=courant->suivant;
		}
	}
	courant2=debg;
	while(courant2!=NULL){
		if(strcmp(courant2->L.Discipline,"Math")==0){
			if(courant2!=debg ){
				temp2=courant2;
				courant2=courant2->suivant;
				temp2->suivant=debg;
				debg=temp2;		
			}
			else courant2=courant2->suivant;
		}
		else{
			courant2=courant2->suivant;
		}
	}
//	courant3=deb3;
//	while(courant3!=NULL){
//		if(strcmp(courant3->L.Discipline,"Phys")==0){
//			if(courant3!=deb3){
//				temp3=courant3;
//				courant3=courant3->suivant;
//				temp3->suivant=debg;
//				debg=temp3;
//			}
//			else courant3=courant3->suivant;
//		}
//		else{
//			courant3=courant3->suivant;
//		}
//	}
//	finin=debut;
//	while(finin->suivant!=NULL){
//		finin=finin->suivant;
//	}
//	fin = finin;
	return 0;
}


//int Trier_Bibio(){
//	book *courant,*courant2,*courant3,*temp,*temp2,*temp3,*deb1,*deb2,*deb3,*finin,*sub;
//	if(taille==0){
//		printf("aucun livre");
//		return -1;
//	}
//	sub=debut;
//	courant=debut;
//	while(courant!=NULL){
//		if(strcmp(courant->L.Discipline,"Chim")==0){
//			if(courant!=debut ){
//				temp=courant;
//				courant=courant->suivant;
//				temp->suivant=debut;
//				debut = temp;
//			}
//			
//			else courant=courant->suivant;
//		}
//		else{
//			courant=courant->suivant;
//		}
//	}
//	courant=sub;
//	while(courant!=NULL){
//		if(strcmp(courant->L.Discipline,"Phys")==0){
//			if(courant!=debut ){
//				temp=courant;
//				courant=courant->suivant;
//				temp->suivant=debut;
//				debut = temp;
//			}
//			
//			else courant=courant->suivant;
//		}
//		else{
//			courant=courant->suivant;
//		}
//	}
//	courant=sub;
//	while(courant!=NULL){
//		if(strcmp(courant->L.Discipline,"Math")==0){
//			if(courant!=debut ){
//				temp=courant;
//				courant=courant->suivant;
//				temp->suivant=debut;
//				debut = temp;
//			}
//			
//			else courant=courant->suivant;
//		}
//		else{
//			courant=courant->suivant;
//		}
//	}
//	courant=sub;
//	while(courant!=NULL){
//		if(strcmp(courant->L.Discipline,"Info")==0){
//			if(courant!=debut ){
//				temp=courant;
//				courant=courant->suivant;
//				temp->suivant=debut;
//				debut = temp;
//			}
//			
//			else courant=courant->suivant;
//		}
//		else{
//			courant=courant->suivant;
//		}
//	}
////	courant2=deb2;
////	while(courant2!=NULL){
////		if(strcmp(courant2->L.Discipline,"Math")==0){
////			if(courant2!=deb2){
////				temp2=courant2;
////				courant2=courant2->suivant;
////				temp2->suivant=deb2->suivant;
////				deb2->suivant=temp2;
////				deb2=temp;
////			}
////			else courant2=courant2->suivant;
////		}
////		else{
////			courant2=courant2->suivant;
////		}
////	}
////	courant3=deb3;
////	while(courant3!=NULL){
////		if(strcmp(courant3->L.Discipline,"Phys")==0){
////			if(courant3!=deb3){
////				temp3=courant3;
////				courant3=courant3->suivant;
////				temp3->suivant=debg;
////				debg=temp3;
////			}
////			else courant3=courant3->suivant;
////		}
////		else{
////			courant3=courant3->suivant;
////		}
////	}
//	finin=debut;
//	while(finin->suivant!=NULL){
//		finin=finin->suivant;
//	}
//	fin = finin;
//	return 1;
//}
int main(){
	initialisation();
	Ajouter_Livre(12,"ama","kwatcha" ,"Phys", "shey", 2);
	Ajouter_Livre(3,"ama","kwatcha" ,"Chim", "shey", 2);
	Ajouter_Livre(0,"ama","kwatcha" ,"Math", "shey", 2);
	Ajouter_Livre(6,"ama","kwatcha" ,"Info", "shey", 2);
	Ajouter_Livre(1,"ama","kwatcha" ,"Info", "shey", 2);
	Trier_Bibio();
//	Retirer_Livre(12);
	printf("%s",debut->suivant->suivant->L.Discipline);
	
	return 0;
}









































//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define max 20
//typedef struct livre {
//	int Cote ;
//	char *Titre ;
//	char *Auteur ;
//	char *Discipline ;
//	char *Editeur ;
//	int NbExemplaires ;
//}Livre;
//typedef struct books {
//	Livre L;
//	Livre *suivant;	
//}book;
//
//book *debut ,*fin;
//int taille ;
//
//int Ajouter_Livre(int co,char *tit,char *aut , char *disc, char *edit,int nbrexm)
//{
//	book *element;
//	if((element=(book*)malloc(sizeof(book))) == NULL){
//		printf("echec de reservation");
//		return -1;
//	}
//	if((element->L.Titre=(char*)malloc(max*sizeof(char))) == NULL){
//		printf("echec de reservation");
//		return -1;
//	}
//	if((element->L.Auteur=(char*)malloc(max*sizeof(char))) == NULL){
//		printf("echec de reservation");
//		return -1;
//	}
//	if((element->L.Discipline=(char*)malloc(max*sizeof(char))) == NULL){
//		printf("echec de reservation");
//		return -1;
//	}
//	if((element->L.Editeur=(char*)malloc(max*sizeof(char))) == NULL){
//		printf("echec de reservation");
//		return -1;
//	}
//	element->L.Cote =co;
//	strcpy(element->L.Titre, tit);
//	strcpy(element->L.Auteur , aut);
//	strcpy(element->L.Discipline , disc);
//	strcpy(element->L.Editeur , edit);
//	element->L.NbExemplaires =nbrexm;
//	element->suivant = NULL;
//	//inserer a la fin 
//	if(taille == 0){
//		debut = element;
//	}
//	fin = element;
//	return 1;
//}
//
//
//int main()
//{
//	Ajouter_Livre(12,"ama","kwatcha" ,"math", "shey", 2);
//	printf("%s",debut->L.Auteur);
//	return 0;
//}

