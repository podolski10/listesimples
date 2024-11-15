#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<conio.h>
typedef struct cell{
  int donne;
  struct cell *suivant;
}liste;
liste* ajoutfin(liste *l,int donne){
  liste *noufin;
  liste *p=l;
  noufin=(liste *)malloc(sizeof(liste));
  if(noufin==NULL){
    printf("il y'a un erreur.\n");
    exit(1);
  }
  noufin->donne=donne;
  noufin->suivant=NULL;
  if(l==NULL){
    return noufin;
  }
  else{
    while(p->suivant!=NULL){
      p=p->suivant;
    }
  }
  p->suivant=noufin;
  return l;//p designer l;
}
liste *circuliare(liste *l){
  if(l==NULL){
    printf("la liste est vide.\n");
    return l;
  }
  liste *p=l;
  while(p->suivant!=NULL){
    p=p->suivant;
  }
  p->suivant=l;
  return l;
}
liste *fusioner(liste *l1,liste *l2){
  liste *p=l1;
  while(p->suivant!=NULL){
    p=p->suivant;
  }
  p->suivant=l2;
  return l1;
}
void affichage(liste *l){
  liste *p=l;
  int i=0;
  while(p!=NULL){
    printf("le nombre %d est %d.\n",i+1,p->donne);
    p=p->suivant;
    i++;
  }
}
bool cherche(liste *l,int x){
  liste *p=l;
  bool a;
  while(p!=NULL){
    if(p->donne==x){
       a=true;
    }
    else{
      a=false;
    }
    p=p->suivant;
  }
   return a;
}
int taille(liste *l){
  liste *p=l;
  int i=0;
  while(p!=NULL){
    p=p->suivant;
    i++; 
    }
    return i;
}
void affichagecirculaiere(liste *l){
  liste *p=l;
  do{
    printf("%d.\n",p->donne);
    p=p->suivant;
  }while(p!=l);
}
void transfrom(liste *l){
  liste *p=l;
  int n=taille(l);
  int T[n];
    for(int i=0;i<n;i++){
      T[i]=p->donne;
       p=p->suivant;
    }
    printf("le tableau :\n");
    for(int i=0;i<n;i++){
      printf("%d",T[i]);
    }
    }
int main(){
liste *l1=NULL;
int n;
int nbr;
  printf("entrer  le nombre  des elements de la liste 1 :\n ");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("entrer le nombre %d de la liste:\n",i+1);
    scanf("%d",&nbr);
    l1=ajoutfin(l1,nbr);
  }
  l1=circuliare(l1);
  affichagecirculaiere(l1);
  affichage(l1);
  return 0;
}
