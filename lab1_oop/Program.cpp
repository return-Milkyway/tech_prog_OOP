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
	return this->Sum() < other->Sum();
}
void container::Sort(){
 	 container *p;
	p = this->next;
	int num=0;
	do {
	    num=num+1;
	    p = p->next; 
	 } while (p != this); 
	 p = this->next; 
	for (int count3=0;count3<num;count3++){
		for (int count2=0;count2<num;count2++){
			p=this->next;
			for(int tmp=0;tmp<count2-1;tmp++){p=p->next;}			
			if(p->cont->Compare( p->next->cont)){
	 			this->Swap(p,p->next,this);
	 		}	
		}
	  }
 }
  container * container::Swap( container *lst1,  container *lst2,  container *head)
{
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
 	sp->InData(ifst);
 	return	sp;
 }
 
void diagol::InData( ifstream &ifst) {
	//char str[20];
	//ifst.get();
	ifst>>this->y;
 	this->x=new int*;
	for (int count=0;count<this->y;count++){
	 	this->x[count]=new int[this->y];
 	}
	for (int count=0;count<this->y;count++){
		ifst>>this->x[count][count];
	}
}
 
void square::InData( ifstream &ifst){
	ifst.get();
	this->a=new int*;
	ifst>>this->b;
	for (int count=0;count<this->b;count++){
 		this->a[count]=new int[this->b];
 	}
	for (int count=0;count<this->b;count++){
 		//p.a[count]=new int[p.b];
 		for (int count2=0;count2<this->b;count2++){
 		ifst>>	this->a[count][count2];
 	}
 	}
}

void down_triangle::InData( ifstream &ifst){
	ifst.get();
	ifst>>this->y;
 	this->x=new int;
 	int len=0;
 	for (int j=1;j<(this->y);j++) {
		len=len+(this->y -j);		
	}
 	len=(this->y*this->y)-len;
	for (int count=0;count<len;count++){
 		ifst>>	this->x[count];
 	}
}

container* container::In(ifstream &ifst){
	container *last = this->Init2(matr::In(ifst));
	container tmp;
	tmp = *this->next; 
	this->next = last; 
	last->next = tmp.next;
	this->prev=last;
	last->prev=this; 	 
	while(!ifst.eof()) {
		container *newItem = last->Init2(matr::In(ifst));
		container tmp=*last->Init();		  
		tmp.cont = last->cont;
		tmp.next = last->next;
		last->next = newItem;
		newItem->next = tmp.next;
		newItem->prev=last;
		this->prev=newItem;
		last=newItem;
	}
	return(last);
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




 	
