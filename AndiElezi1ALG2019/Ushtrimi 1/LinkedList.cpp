#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

/*Deklaroj nje strukture qe permban nje string qe do te sherbej si celes dhe pasardhesin*/

typedef struct list{
	string a;
	struct list *pas;
}list;


/* Deklaroj dhe implementoj funksionin qe kontrollon nqs fjala ndodhet ne liste*/

bool gjendet(list *k,string fjala){
	if(k==NULL){
		return false;
	}
	struct list *tmp=k;
	while(tmp!=NULL){
		if(tmp->a.compare(fjala)==0){  //ben krahasimin e fjaleve dhe nqs jan te = kthen true
			return true;
		}
		tmp=tmp->pas;
	}
	return false;                      //perndryshe kthen false
}

/*Deklaroj dhe implementoj funksionin qe shton nje fjale ne liste*/

list *add(list *k,string vlera){
    if(gjendet(k,vlera))  //kontrolloj nqs fjala ndodhet ne liste
    return k;
	struct list *tmp=new list();
	tmp->a=vlera;
	tmp->pas=k;
	k=tmp;
	return k;
}

/*Deklaroj dhe implementoj funksionin qe afishon listen*/

void afisho(list *k){
	struct list *tmp=k;
	while(tmp!=NULL){   // perderi sa te kete element ne liste 													
		cout<<tmp->a<<" ";// e afishoj dhe vazhdoj
		tmp=tmp->pas;		//  tek fjala tjeter
		
	}
		
}



int main(){
	

	list *k=NULL;//deklaroj koken e listes
	fstream in; //krjoj objektin qe do lexoj skedarin
	in.open("skedar.txt",ios::in);
	string a;
	int counter=0;
	while(counter<1000000){
		in>>a;
		k=add(k,a);//shtoj me radhe fjalet ne liste per sa koh qe skedari permban fjale
		counter++;         
	}
	afisho(k);//bej afishimin e listes
	
	return 0;
}
