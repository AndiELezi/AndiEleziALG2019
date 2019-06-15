#include <iostream>
#include <Math.h>
#include <fstream>
using namespace std;
typedef struct list{
	string celes;
	struct list *pas;
}list;

/*--------------------Funksioni qe kontrollon nqs fjala ndodhet ne liste----------------*/

bool gjendetNeListe(struct list *k,string fjala){
	if(k==NULL){
		return false;
	}
	struct list *tmp=k;
	while(tmp!=NULL){
		if(tmp->celes.compare(fjala)==0){
			return true;
		}
		tmp=tmp->pas;
	}
	return false;
}
 
 /*----------------Funksioni qe Shton fjalen  ne Liste--------------*/
 
struct list* shtoNeListe(struct list *k,string vlera){
    if(gjendetNeListe(k,vlera))		//nqs fjala gjendet kthejme koken e listes 
    return k;
	struct list *tmp=new list();
	tmp->celes=vlera;     //perndryshe e shtojme kete fjal 
	tmp->pas=k;
	k=tmp;
	return k;        //dhe ne fund kthejme koken e listes
	
}

/*---------------------funksioni qe heq nga lista nje fjale-------------------*/
			

struct list* hiqNgaLista(struct list *k,string vlera){
	if(!gjendetNeListe(k,vlera)){
		cout<<"fjala nk gjendet ne list";
		return k;
	}
	if(k==NULL){
		return k;
	}
    if(k->celes.compare(vlera)==0){
    	k=k->pas;
    	return k;
	}
	struct list *tmp=k;
	while(tmp->pas->celes.compare(vlera)!=0){
		tmp=tmp->pas;
	}
	tmp->pas=tmp->pas->pas;
	return k;
	
}


/*------------------------funksioni qe kthen fjalen ne int-----------------*/


int  celesInt(string fjala){
	
	int  i,s=0;
	for(i=0;i<fjala.length();i++){
		int vl=(int)fjala[i];
	    s+=vl*pow(3,i);
		}
		return s;
}


/*---gjeneron hashkodin qe percakton pozicionin qe do te vendoset fjala ne tabele-------*/


int hashCode(int vlera){
	if(vlera<0){
	return vlera%100000*(-1);  //nqs vlera int e numrit eshte negative
	}
	return vlera%100000;
}

/*---------------------funksini qe shton ne tabelen hash-----------------*/

void shtoElement(struct list *T[],int N,string fjala){
	int pozicioni=hashCode(celesInt(fjala));
	T[pozicioni]=shtoNeListe(T[pozicioni],fjala);
	
}

/*-------------------funksioni qe kontrollon nqs fjala gjendet en tabele--------------*/

bool gjendetNeHash(struct list *T[],int N,string fjala){
	int pozicioni=hashCode(celesInt(fjala));
	if(gjendetNeListe(T[pozicioni],fjala)){
		return true;
	}
	return false;
	
}

/*-------------funksioni qe heq nje fjale nga tabela------------------*/

void hiqElement(struct list *T[],int N,string fjala){
	if(!gjendetNeHash(T,N,fjala)){
		cout<<"Elementi nk gjendet ne Tabelen Hash";
		return;
	}
	int pozicioni=hashCode(celesInt(fjala));
	T[pozicioni]=hiqNgaLista(T[pozicioni],fjala);
}


/*-----------funkisoni per afishimin e tabeles-----------------*/

void afisho(list *T[],int N){
	for(int i=0;i<N;i++){
	struct list *tmp=T[i];
	while(tmp!=NULL){
		cout<<tmp->celes<<" ";
		tmp=tmp->pas;
		}
	}
}


int main(){
	int i;
	struct list *TabeleHash[100000];//deklarimi i tabeles hash

    for(i=0;i<100000;i++){
    	TabeleHash[i]=NULL;   //mbushet tabela hesh me vlera null
	}

fstream in;			//krijimi objektit per te marre fjalet nga skedari
	in.open("skedar.txt",ios::in);
	string a;
	int c=0;
	while(c<1000000){
		in>>a;    //merren fjalet nga skedari 
		shtoElement(TabeleHash,100000,a); //dhe shtohen ne tabelen hash
	c++;
	}


afisho(TabeleHash,100000);


	return 0;
}
