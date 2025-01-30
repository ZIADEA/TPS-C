//exercice 2
#include<stdio.h>
#include<stdlib.h>
 #define max 100 
typedef int element ;
typedef struct {
	int av;
	int ar;
	int FILE[max];
}file;
void initialiser(file *f)
{
	f->av=0;
	f->ar=0;
}
int fileVide(file *f)
{
	return((f->av) == (f->ar));
}
void emfiler (file *f,int x)
{
	if(f->av == (f->ar +1)%max)
	{
		printf("overflow");
	}
	else
	{
		if(f->ar == max-1) f->ar = 0;
		else f->ar +=1;
		f->FILE[f->ar] = x;
	}
}

int defiler(file *f)
{
	int x;
	if(fileVide(f)) 
	{
		printf("underflow ");
	}
	else
	{
		if(f->av == max-1) f->av = 0;
		else f->av = f->av +1;
		x= f->FILE[f->av];
		return x;
	}
	
}

void defilerEnfiler(file *f1,file *f2)
{
	int x;
	if(fileVide(f1)  || (f2->av == (f2->ar +1)%max))
	{
		printf("action impossible");
	}
	else
	{
		x= defiler(f1);
		emfiler(f1,x);
		
	}
}

int comparer(file *f1,file *f2)
{
	if(fileVide(f1) || fileVide(f2) )
	{
		printf("impossible 1 ou les 2 file vide");
		return 0;
	}
	else
	{
		if(f1->FILE[f1->av+1] >= f2->FILE[f2->av+1]) return 1;
		else return 0;
	}
	
}



void trier(file *f1, file *f2) {
    while (!fileVide(f1)) {
        int mx = defiler(f1);
        while (!fileVide(f1)) {
            int current = defiler(f1);
            if (current > mx) {
                emfiler(f2, mx); // Placer l'ancien mx dans f2
                mx = current; // Mettre à jour le maximum
            } else {
                emfiler(f2, current); // Placer l'élément courant dans f2
            }
        }
        emfiler(f1, mx); // Remettre le maximum dans f1
    }
}


main()
{
	file F1,F2,F3;
	initialiser(&F1);
	initialiser(&F2);
	initialiser(&F3);
	emfiler (&F1,5);
	emfiler (&F1,1);
	emfiler (&F1,7);
	emfiler (&F1,2);
	emfiler (&F1,10);
	emfiler (&F1,0);
	emfiler (&F1,8);
	trier(&F1,&F2);
	printf("%d",F2.FILE[F2.ar]);
}









// exzecice 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define max 20 
//typedef struct elt{
//	int priorite ;
//	char donnee ;
//}element ;
//
//typedef element pile [max];
//pile p ;
//int sommet ;
//void initialisation ()
//{
//	sommet = -1 ;
//}
//int pile_vide()
//{
//	return(sommet <0);
//}
//void ajouter (element x)
//{
//	if(sommet >=max-1)
//	printf("stock overflow : capacité pleine ");
//	
//	else
//	{
//		sommet+=1;
//		p[sommet] = x ;
//	}
//}
//int position()
//{
//	int i=0,j,pos;
//	pos = i ;
//	for (j=sommet;j>=0;j--)
//	{
//		if(p[j].priorite>p[pos].priorite) pos = j ;
//	}
//
//	return pos;
//}
//
//element retirer()
//{
//	int somt= -1,init,pos;
//	pile secour;
//	element prio ;
//	init = sommet ;
//	pos = position();
//	if (pile_vide()) 
//	{
//		printf("pile vide ");
//	}
//	else
//	{
//		if (sommet == pos )
//		{
//			prio = p[sommet];
//		}
//		else 
//		{
//		
//			while (sommet!=pos )
//			{
//				somt ++;
//				secour[somt] =p[sommet];
//				sommet--;
//			}
//			prio = p[sommet];
//			while(sommet<= init-1 && somt !=-1)
//			{
//				sommet ++;
//				p[sommet]=secour[somt];
//				somt--;
//			}
//		}
//		return prio ;	
//	}
//}
//
//void ajouter2( element x) 
//{
//	int somt= -1,init;
//	pile secour;
//	element prio ;
//	init = sommet ;
//	if (sommet >=max-1) 
//	printf("stock overflow capacité pleine");
//	else 
//	{
//		if(pile_vide()) 
//		{
//			sommet ++ ;
//			p[sommet]=x;
//		}
//		else
//		{
//		if(x.priorite >= p[sommet].priorite )
//		{
//			sommet ++ ;
//			p[sommet]=x;
//		}
//		else 
//		{
//			while (x.priorite < p[sommet].priorite)
//				{
//					somt ++;
//					secour[somt] =p[sommet];
//					sommet--;
//				}
//			sommet ++ ;
//			p[sommet]=x;
//			while(sommet<= init+1 && somt !=-1)
//				{
//				sommet ++;
//				p[sommet]=secour[somt];
//				somt--;
//				}
//		}
//		}
//		
//	}
//	
//}
//
//
//int main ()
//{
//	element a,b,c,d,e;
//	a.donnee = 'a';
//	a.priorite = 23;
//	b.donnee = 'b';
//	b.priorite = 1;
//	c.donnee = 'c';
//	c.priorite = 50;
//	d.donnee = 'd';
//	d.priorite = 299;
//	e.donnee = 'e';
//	e.priorite = 43;
//	initialisation ();
//	ajouter2 (a);
//	ajouter2 (b);
//	ajouter2 (c);
//	ajouter2 (d);
//	ajouter2 (e);
//	printf("%d",p[sommet].priorite );
//	
//	return 0;
//}

