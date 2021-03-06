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
		p = p->next; // ������� � ���������� ����
	} while (p != this); // ������� ��������� ������
};
   
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
 		default:
 		return 0;
 	}
 	sp->InData(ifst);
 	return	sp;
}
 
void diagol::InData( ifstream &ifst) {
	//char str[20];
 	ifst.get();
 	ifst>>this->y;
 	this->x=new int*;
 for (int count=0;count<this->y;count++){
 	this->x[count]=new int[this->y];
 }
 for (int count=0;count<this->y;count++){
 	ifst>>	this->x[count][count];
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

void square::MultiMethod(matr *other,ofstream &ofst) {
	other->MMSquare(ofst);
}

void diagol::MultiMethod(matr *other,ofstream &ofst) {
	other->MMDiagol(ofst);
}

void square::MMSquare(ofstream &ofst) {
	ofst << "Square and Square" << endl;
}

void square::MMDiagol(ofstream &ofst) {
	ofst << "Diagol and Square" << endl;
}

void diagol::MMSquare(ofstream &ofst) {
	ofst << "Square and Diagol" << endl;
}

void diagol::MMDiagol(ofstream &ofst) {
	ofst << "Diagol and Diagol" << endl;
}

void container::MultiMethod(ofstream &ofst) {
	ofst << "Multimethod." << endl;
	container *p;
	container *p2;
	p = this->next;
	int num = 0;
	do {
	    num = num + 1;
	    p = p->next; 
	} while (p != this); 
	p = this->next; 
	for (int count3 = 0; count3 < num; count3++){	
		p2 = this->next;
		for(int tmp= 0; tmp< count3; tmp++) {
			p2 = p2->next;
		}	
		for (int count2 = count3; count2 < num; count2++){
			p->cont->MultiMethod(p2->cont,ofst);
	 		p->cont->Out(ofst);
 			p2->cont->Out(ofst);;
 			ofst << endl;
 			p2 = p2->next;
		}
		p = p->next;
	}
} 	
