#include<iostream>
#include<Math.h>
#include<fstream>
using namespace std;
  typedef struct peme{
  	string fjala;
  	struct peme *p,*m,*d;
  }peme;
  	
  
  
  
  peme *krijoNyje(string fjala){
  	
  	peme *kulm=new peme;
  	kulm->fjala=fjala;
  	kulm->m=NULL;
  	kulm->d=NULL;
  	kulm->p=NULL;
  	return kulm;
  }

 
  
  
  /*-----------------funksioni qe shton nje kulm ne peme-----------------*/

  
  peme *add(peme *T,string fjala){
  	peme *kulm=krijoNyje(fjala);	//krijohet nyja e re qe do te futet
  	peme *y=NULL;
  	peme *tmp=T;
  	
  	while(tmp!=NULL){
  		y=tmp;
  		if(kulm->fjala.compare(tmp->fjala)<0){	
  			tmp=tmp->m;							
		  }
  		else if(kulm->fjala.compare(tmp->fjala)>0){  //vazhdon kerkimi deri sa te gjendet  
  			tmp=tmp->d;								 //gjethja  dhe shtohet nyja 	
		  }											 			
		  else{										 							
		  	return T;
		  }
	  }
  	kulm->p=y;
  	if(y==NULL){
  		T=kulm;
  		return T;
	  }
	else if(kulm->fjala.compare(y->fjala)<0){			//vendoset kulmi ne anen e duhur 
	  	y->m=kulm;
	  	return T;
	  }
    else{
	  	y->d=kulm;
	  	return T;
	  }
  } 
  
 /*---------------------Afishimi---------------------*/
  
  void afisho(peme *k){
  	if(k==NULL)
  	return;
  	cout<<k->fjala<<" ";
  	afisho(k->m);
  	
  	afisho(k->d);
  }
  
  
  
  
  

  
  int main(){
  	peme *rr=NULL;
  fstream in;			// krijohet objekti per t lexuar skedari
	in.open("skedar.txt",ios::in);
	string a;
	int c;
	while(c<1000000){
		in>>a;
		rr=add(rr,a);  //vendosen fjalet ne peme
		c++;
	}

	
	afisho(rr);    //afishohet pema
  }
