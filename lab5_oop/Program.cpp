#include "Program.h"
container *  container::Init(){
	container *c ;
	c=new container;
	c->next = c; 
	c->prev=c;
	return c;
};
  
container*   container::Init2(matr  *a) {
	container* c ;
	c=new container;
	c->cont = a;
	c->next = c; 
	c->prev=c;
	return c;
};
  
container * container::Clear( ){
	container *p;
	p=this->next;
	do {
		container *temp;
		temp = p;
		while (temp->next != p) { 
			temp = temp->next;
		};
  		temp->next = p->next; 
		p = p->next; // переход к следующему узлу
	} while (p != this); // условие окончания обхода
};

bool matr::Compare(matr *other) {
	try
{
	return this->Sum() < other->Sum();
	throw -1;
}
catch (int){
	return(-1);
}
}

int container::Sort(){
 	 container *p;
	p = this->next;
	int num=0;
	do {
	    num=num+1;
	    p = p->next; 
	 } while (p != this); 
	 p = this->next; 
	for (int count3=0;count3<num;count3++){
		for (int count2=0;count2<num-1;count2++){
			p=this->next;
			for(int tmp=0;tmp<count2-1;tmp++){p=p->next;}
			int tmp=0;
			tmp=p->cont->Compare( p->next->cont);
			if (tmp==-1){
				return 0;
			}			
			if(tmp){
	 			this->Swap(p,p->next,this);
	 		}	
		}
	  }
	  return 1;
 }

container * container::Swap( container *lst1,  container *lst2,  container *head){
  // Возвращает новый корень списка
  struct container *prev1, *prev2, *next1, *next2;
  prev1 = head;
  prev2 = head;
  while (prev1->next != lst1) // поиск узла предшествующего lst1
    prev1 = prev1->next;
  while (prev2->next != lst2) // поиск узла предшествующего lst2
    prev2 = prev2->next;
  next1 = lst1->next; // узел следующий за lst1
  next2 = lst2->next; // узел следующий за lst2
  if (lst2 == next1)
  {	
    // обмениваются соседние узлы
    lst2->next = lst1;
    lst1->next = next2;
    prev1->next = lst2;
  }
  else if (lst1 == next2)
  {
    // обмениваются соседние узлы
    lst1->next = lst2;
    lst2->next = next1;
    prev2->next = lst2;
  }
  else
  {
    // обмениваются отстоящие узлы
    prev1->next = lst2;
    lst2->next = next1;
    prev2->next = lst1;
    lst1->next = next2;
  }
  if (lst1 == head)
    return(lst2);
  if (lst2 == head)
    return(lst1);
  return(head);
}  
   
void container::Out(ofstream &ofst){ 
	container p;
	container* tmp;
	
	p = *this;
	int num=0;
	do {
		num=num+1;
		p = *p.next; 
		tmp=p.next;
	} while (p.next != this->next); 
	ofst<<"Container contains " << num -1	<< " elements." << endl;
		if(this->next==this){
		ofst<<"none"<<endl;
		return;
	}
	p = *this->next;
	do {
		matr *s=p.cont;
	    s->Out(ofst);
		container *tmp;
		tmp=p.next;	    
	    p = *p.next; 
	} while (p.next != this->next); 
};
   
void square::Out( ofstream &ofst){
	 ofst << "It is Square matrix: len = "
	 << this->b << ", matr = " << endl;
	 for (int count=0;count<this->b;count++){
		for (int count2=0;count2<this->b;count2++){
			ofst<<this->a[count][count2]<<" ";
		}
		ofst<<endl;
	}
	matr::Out(ofst);
};
 
void diagol::Out( ofstream &ofst) {
	ofst << "It is Diagol Matrix: len = " << this->y
	<< ", matr: = " <<endl;
	for (int count=0;count<this->y;count++){
		for (int count2=0;count2<this->y;count2++){
			if (count!=count2){
				ofst<<"0 ";
			}
			else{
			ofst<<this->x[count][count]<<" ";
			}
		}
		ofst<<endl;
	}
	matr::Out(ofst);
};

void down_triangle::Out( ofstream &ofst) {
	ofst << "It is Down Triangle Matrix: len = " << this->y
	<< ", matr: = " <<endl;
	int i=0;
	for (int count=0;count<this->y;count++){
		for (int count2=0;count2<this->y;count2++){
			if (count<count2){
				ofst<<"0 ";
			}
			else{
			ofst<<this->x[i]<<" ";
			i=i+1;
			}
		}
		ofst<<endl;
	}
	matr::Out(ofst);
};
 
matr* matr::In(ifstream &ifst){
 	matr *sp;
 	int k;
 	ifst >> k;
 	switch(k) {
 		case 1:
 			sp = new square ;
 			break;
 		case 2:
 			sp = new diagol;
 			break;
 		case 3:
 			sp = new down_triangle;
 			break;
 		default:
 		return 0;
 	}
 	int test=1;
 	test=sp->InData(ifst);
 	if (test==0) {
	cout<< "incorrect input"<<endl;
	sp=0;
	}
 	return	sp;
 }
 
int diagol::InData( ifstream &ifst) {
	//char str[20];
	//ifst.get();
	ifst>>this->y;

	//cout<<y<<endl;
	if ((y)>(1000)){
	return 0;	
	}
 	this->x=new int*;
	for (int count=0;count<this->y;count++){
	 	this->x[count]=new int[this->y];
 	}
	for (int count=0;count<this->y;count++){
		ifst>>this->x[count][count];
		if (this->x[count][count]>(1000)){
		return 0;	
		}
	}
	matr::InData(ifst);
	return 1;
}
 
int square::InData( ifstream &ifst){
	ifst.get();
	this->a=new int*;
	ifst>>this->b;
	if (this->b>(1000)){
	return 0;	
	}
	for (int count=0;count<this->b;count++){
 		this->a[count]=new int[this->b];
 	}
	for (int count=0;count<this->b;count++){
 		//p.a[count]=new int[p.b];
 		for (int count2=0;count2<this->b;count2++){
 		ifst>>	this->a[count][count2];
 		if (this->a[count][count2]>(1000)){
		return 0;	
		}
 	}
 	}
 	matr::InData(ifst);
 	return 1;
}

int down_triangle::InData( ifstream &ifst){
	ifst.get();
	ifst>>this->y;
	if (this->y >(1000)){
	return 0;	
	}
 	this->x=new int;
 	int len=0;
 	for (int j=1;j<(this->y);j++) {
		len=len+(this->y -j);		
	}
 	len=(this->y*this->y)-len;
	for (int count=0;count<len;count++){
 		ifst>>	this->x[count];
 		if (this->x[count]>(1000)){
		return 0;	
		}
 	}
 	matr::InData(ifst);
 	return 1;
}

int container::In(ifstream &ifst){
	container *last = this->Init2(matr::In(ifst));
	if(last->cont==0){
		cout<<"Incorrect input"<<endl;
		return 0;
	}
	container tmp;
	tmp = *this->next; 
	this->next = last; 
	last->next = tmp.next;
	this->prev=last;
	last->prev=this; 	 
	while(!ifst.eof()) {
		container *newItem = last->Init2(matr::In(ifst));
		if(newItem->cont==0){
			cout<<"Incorrect input"<<endl;
			return 0;
		}
		container tmp=*last->Init();		  
		tmp.cont = last->cont;
		tmp.next = last->next;
		last->next = newItem;
		newItem->next = tmp.next;
		newItem->prev=last;
		this->prev=newItem;
		last=newItem;
	}
	return(1);
}
 	
int square::Sum() {
	int sum=0;
	for (int count=0;count<this->b;count++){
		for (int count2=0;count2<this->b;count2++){
			sum=sum+this->a[count][count2];
		}
	}
	return sum;
}

int diagol::Sum() {
	int sum=0;
	for (int count=0;count<this->y;count++){
		for (int count2=0;count2<this->y;count2++){
			if (count==count2){
			sum=sum+this->x[count][count];
			}
		}
	}
	return sum;
}

int matr::InData(ifstream &ifst){
	int t=0;
	//ifst.get();
	//	ifst.get();
	ifst >> t;
 	switch(t) {
 		case 1:	
		 	this->variant=matr::var_print::POSTROCHNO;
		 	return 1;
		case 2:	
		 	this->variant=matr::var_print::POSTOLBZAM;
			return 1;	
		case 3:	
			this->variant=matr::var_print::ODNOMERNO;
			 return 1;	
		default:
 			this->variant=matr::var_print::INCORRECT;
 			return 1;				
	}
}

int down_triangle::Sum() {
	int len=0;
	int sum=0;
	for (int j=1;j<(this->y);j++) {
		len=len+(this->y -j);		
	}
	len=(this->y)*(this->y) -len;
	for (int count=0;count<len;count++){
		sum=sum+this->x[count];
	}
	return sum;
}

void container::Out_Sum(ofstream &ofst){
	container *p;
	p=this;
	int num=0;
	  do {
	    num=num+1;
	    p = p->next; 
	  } while (p != this); 
	  ofst<<"Container contains " << num-1 	<< " elements." << endl;
  	if(this->next==this){
		return;
	}
  	p = this->next;
	  do {
	    matr *s=p->cont;
	    s->Out(ofst);
	    ofst<<"Sum_matr = " << s->Sum()  << endl;
	    p = p->next; 
	  } while (p != this); 
}

void matr::Out(ofstream &ofst){
	if (this->variant == 0)
        ofst << "Print need POSTROCHNO"<<endl;
    else if (this->variant == 1)
         ofst << "Print need POSTOLBZAM"<<endl;
    else if (this->variant == 2)
         ofst << "Print need ODNOMERNO"<<endl;
    else 
         ofst << "Incorrect variant of print"<<endl;
}

void matr::Out_square(ofstream &ofst){
	ofst << endl;	
}
void square::Out_square(ofstream &ofst){
	this->Out(ofst);
}

void container::Out_square(ofstream &ofst){ 	
	container p;
	container* tmp;
	p = *this;
	int num=0;
	do {
		num=num+1;
		p = *p.next; 
		tmp=p.next;
	} while (p.next != this->next); 
	ofst<<"Container contains " << num -1	<< " elements." << endl;
	ofst<<"Only square" <<  endl;
		if(this->next==this){
		ofst<<"none"<<endl;
		return;
	}
	p = *this->next;
	do {
		matr *s=p.cont;
	    s->Out_square(ofst);
		container *tmp;
		tmp=p.next;	    
	    p = *p.next; 
	} while (p.next != this->next); 
};

