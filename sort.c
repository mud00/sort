#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>


void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void trirapide(int *tab,int debut,int fin){
	int i,j,pivot;
	if(debut<fin){
		pivot=debut;
		i=debut;
		j=fin;
		do{
			while(tab[i]<=tab[pivot]&&i<fin){
				i++;
			}
			while(tab[j]>tab[pivot]){
				j--;
			}
			if(i<j){
				swap(&tab[i],&tab[j]);
			}
		}
		while(i<j);
		swap(&tab[pivot],&tab[j]);
		trirapide(tab, debut, j - 1);
       trirapide(tab, j + 1, fin);
	}
}
void tribulle(int *tab,int n){
	int i,j;
	int tmp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(tab[j]>tab[j+1]){
				tmp=tab[j];
				tab[j]=tab[j+1];
				tab[j+1]=tmp;
			}
		}
		if(tmp==INT_MAX) break;
	}
}

void triselection(int*tab,int n){
	int tmp=0,position=0;
	int i=0,j=0;
	for(i=0;i<n;i++){
		position=i;
		for(j=i;j<n;j++){
			if(tab[position]>tab[j]){
			position=j;
			}
		}
		tmp=tab[position];
		tab[position]=tab[i];
		tab[i]=tmp;
	}
}

void triinsertion(int*tab,int n){
	int i=0,j=0;
	int tmp=0;
	for(i=0;i<n;i++){
		j=i;
		while(j-1>=0&&tab[j-1]>tab[j]){
			tmp=tab[j-1];
			tab[j-1]=tab[j];
			tab[j]=tmp;
			j--;
		}
	}
}
void fusion1(int *tab,int debut,int milieu,int fin){
	int n1=milieu-debut+1;
	int n2=fin-milieu;
	int p,l;
	int G[n1],D[n2];
	for(p=0;p<n1;p++){
		G[p]=tab[debut+p];
	}
	for(l=0;l<n2;l++){
		D[l]=tab[milieu+1+l];
	}
	int i,j;
	int k=debut;
	i=0;
	j=0;
	while(i<n1&&j<n2){
		if(G[i]<=D[j]){
			tab[k]=G[i];
			i++;
		}
		else{
			tab[k]=D[j];
			j++;
		}
		k++;
		
	}
	
	while(i<n1){
		tab[k]=G[i];
		i++;
		k++;
	}
	while(j<n2){
		tab[k]=D[j];
		j++;
		k++;
	}
}

void tri_fusion1(int*tab,int debut,int fin){
	if(debut<fin){
		int m=(fin+debut)/2;
		
		tri_fusion1(tab,debut,m);
		tri_fusion1(tab,m+1,fin);
		
		fusion1(tab,debut,m,fin);
	}
}

void fusiontime(int *tab,int debut,int fin){
	
	
double time;
	clock_t start=clock();
	tri_fusion1(tab,debut,fin);
	clock_t end=clock();
	
 time=(double)((end-start)*1000/CLOCKS_PER_SEC); 
	printf("tri fusion: TOTAL TIME TAKEN BY CPU: %f s\n",time*0.001);
	
	
}
void bulltime(int *tab,int n){
	
double time;
	clock_t start=clock();
	tribulle(tab,n);
	clock_t end=clock();
	
 time=(double)((end-start)*1000/CLOCKS_PER_SEC); 
	printf("Tri a bulle: TOTAL TIME TAKEN BY CPU: %f s\n",time*0.001);
}
void selecttime(int *tab,int n){
	
double time;
	clock_t start=clock();
	triselection(tab,n);
	clock_t end=clock();
	
 time=(double)((end-start)*1000/CLOCKS_PER_SEC); 
	printf("Tri selection: TOTAL TIME TAKEN BY CPU: %f s\n",time*0.001);
}

void inserttime(int *tab,int n){
	
double time;
	clock_t start=clock();
	triinsertion(tab,n);
	clock_t end=clock();
	
 time=(double)((end-start)*1000/CLOCKS_PER_SEC); 
	printf("Tri insertion: TOTAL TIME TAKEN BY CPU: %f s\n",time*0.001);
}
	
void quicktime(int *tab,int debut,int fin){
	
double time;
	clock_t start=clock();
	trirapide(tab,debut,fin);
	clock_t end=clock();
	
 time=(double)((end-start)*1000/CLOCKS_PER_SEC); 
	printf("Tri rapide: TOTAL TIME TAKEN BY CPU: %f s\n",time*0.001);
}


int *rempliraleatoirement(int*tab,int n){
	int i=0;
	tab=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		tab[i]=rand()%100;
	}
	return tab;
}

void affiche(int *tab,int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d|",tab[i]);
	}
	printf("\n");
}
int main(){
	srand(time(NULL));
int *tab;
int *tab2;
int *tab3;
int *tab4;
int*tab5;
tab5=rempliraleatoirement(tab5,100000);
tab4=rempliraleatoirement(tab4,100000);
tab3=rempliraleatoirement(tab3,100000);
tab2=rempliraleatoirement(tab2,100000);
tab=rempliraleatoirement(tab,100000);
fusiontime(tab,0,100000-1);
bulltime(tab2,100000);
selecttime(tab3,100000);
inserttime(tab4,100000);
quicktime(tab5,0,100000-1);
free(tab5);
free(tab4);
free(tab3);
free(tab2);
free(tab);
}
