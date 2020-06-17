#include "Program.h"
container* container::Init() {
	container *c ;
	c=new container;
	c->next = c; 
	c->prev = c;
	return c;
};
  
container* container::Init2(matr  *a) {
	container* c ;
	c=new container;
	c->cont = a;
	c->next = c; 
	c->prev = c;
	return c;
};
  
container * container::Clear() {
	container *p;
	p = this->next;
	do {
		container *temp;
		temp = p;
		while (temp->next != p) { 
			temp = temp->next;
		};
  		temp->next = p->next;
		p = p->next;
	} while (p != this);
};

bool matr::Compare(matr *other) {
	try{
		return this->Sum() < other->Sum();
		throw -1;
	}
	catch (int){
		return(-1);
	}
}

int container::Sort() {
	container *tmp_container;
	tmp_container = this->next;
	int num = 0;
	do {
	    num = num + 1;
	    tmp_container = tmp_container->next; 
	} while (tmp_container != this); 
	tmp_container = this->next; 
	for (int count3 = 0; count3 < num; count3++){
		for (int count2 = 0; count2 < num-1; count2++){
			tmp_container = this->next;
			for(int tmp = 0; tmp < count2-1; tmp++){
				tmp_container = tmp_container->next;
			}
			int tmp = 0;
			tmp = tmp_container->cont->Compare(tmp_container->next->cont);
			if (tmp == -1){
				return 0;
			}			
			if(tmp){
	 			this->Swap(tmp_container,tmp_container->next,this);
	 		}	
		}
	  }
	  return 1;
 }

container * container::Swap( container *lst1,  container *lst2,  container *head) {
	struct container *prev1, *prev2, *next1, *next2;
	prev1 = head;
	prev2 = head;
	while (prev1->next != lst1) 
		prev1 = prev1->next;
	while (prev2->next != lst2) 
		prev2 = prev2->next;
	next1 = lst1->next;
	next2 = lst2->next;
	if (lst2 == next1){	
		lst2->next = lst1;
		lst1->next = next2;
		prev1->next = lst2;
	}
	else if (lst1 == next2){
		lst1->next = lst2;
		lst2->next = next1;
		prev2->next = lst2;
	}
	else{
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
   
void container::Out(ofstream &ofst) { 
	container tmp_container;
	container* tmp;	
	tmp_container = *this;
	int num = 0;
	do {
		num = num+1;
		tmp_container = *tmp_container.next; 
		tmp = tmp_container.next;
	} while (tmp_container.next != this->next); 
	ofst << "Container contains " << num-1	<< " elements." << endl;
	if(this->next == this){
		ofst << "none" << endl;
		return;
	}
	tmp_container = *this->next;
	do {
		matr *s = tmp_container.cont;
	    s->Out(ofst);
		container *tmp;
		tmp = tmp_container.next;	    
	    tmp_container = *tmp_container.next; 
	} while (tmp_container.next != this->next); 
};
   
void square::Out( ofstream &ofst){
	 ofst << "It is Square matrix: len = "
	 << this->razm << ", matr = " << endl;
	 for (int count = 0; count < this->razm; count++){
		for (int count2 = 0; count2 < this->razm; count2++){
			ofst << this->arr[count][count2] << " ";
		}
		ofst<<endl;
	}
	matr::Out(ofst);
};
 
void diagol::Out( ofstream &ofst) {
	ofst << "It is Diagol Matrix: len = " << this->razm
	<< ", matr: = " << endl;
	for (int count = 0; count < this->razm ; count++){
		for (int count2 = 0; count2 < this->razm; count2++){
			if (count != count2){
				ofst << "0 ";
			}
			else{
				ofst<<this->arr[count][count]<<" ";
			}
		}
		ofst<<endl;
	}
	matr::Out(ofst);
};

void down_triangle::Out( ofstream &ofst) {
	ofst << "It is Down Triangle Matrix: len = " << this->razm
	<< ", matr: = " << endl;
	int i = 0;
	for (int count = 0; count < this->razm; count++){
		for (int count2 = 0; count2 < this->razm; count2++){
			if (count < count2){
				ofst<<"0 ";
			}
			else{
			ofst << this->arr[i] << " ";
			i = i + 1;
			}
		}
		ofst << endl;
	}
	matr::Out(ofst);
};
 
matr* matr::In(ifstream &ifst) {
 	matr *mtrx;
 	int k;
 	ifst >> k;
 	switch(k) {
 		case 1:
 			mtrx = new square ;
 			break;
 		case 2:
 			mtrx = new diagol;
 			break;
 		case 3:
 			mtrx = new down_triangle;
 			break;
 		default:
 			return 0;
 	}
 	int test = 1;
 	test = mtrx->InData(ifst);
	if (test==0) {
		cout<< "incorrect input"<<endl;
		mtrx=0;
	}
 	return	mtrx;
 }
 
int diagol::InData( ifstream &ifst) {
	ifst >> this->razm;
	if ((razm) > (1000)){
		return 0;	
	}
 	this->arr = new int*;
	for (int count = 0; count < this->razm; count++){
	 	this->arr[count] = new int[this->razm];
 	}
	for (int count = 0; count < this->razm; count++){
		ifst >> this->arr[count][count];
		if (this->arr[count][count] > (1000)){
			return 0;	
		}
	}
	matr::InData(ifst);
	return 1;
}
 
int square::InData( ifstream &ifst){
	ifst.get();
	this->arr = new int*;
	ifst >> this->razm;
	if (this->razm > (1000)){
		return 0;	
	}
	for (int count = 0; count < this->razm; count++){
 		this->arr[count] = new int[this->razm];
 	}
	for (int count = 0; count < this->razm; count++){
 		for (int count2 = 0; count2 < this->razm; count2++){
 			ifst >> this->arr[count][count2];
 			if (this->arr[count][count2] > (1000)){
				return 0;	
			}
 		}
 	}
 	matr::InData(ifst);
 	return 1;
}

int down_triangle::InData( ifstream &ifst){
	ifst.get();
	ifst >> this->razm;
	if (this->razm >(1000)){
		return 0;	
	}
 	this->arr = new int;
 	int len = 0;
 	for (int j = 1; j < (this->razm); j++) {
		len = len + (this->razm - j);		
	}
 	len = (this->razm * this->razm) - len;
	for (int count = 0;count < len; count++){
 		ifst >> this->arr[count];
 		if (this->arr[count] > (1000)){
			return 0;	
		}
 	}
 	matr::InData(ifst);
 	return 1;
}

int container::In(ifstream &ifst){
	container *last = this->Init2(matr::In(ifst));
	if(last->cont == 0){
		cout << "Incorrect input" << endl;
		return 0;
	}
	container tmp;
	tmp = *this->next; 
	this->next = last; 
	last->next = tmp.next;
	this->prev = last;
	last->prev = this; 	 
	while(!ifst.eof()) {
		container *newItem = last->Init2(matr::In(ifst));
		if(newItem->cont == 0){
			cout << "Incorrect input" << endl;
			return 0;
		}
		container tmp = *last->Init();		  
		tmp.cont = last->cont;
		tmp.next = last->next;
		last->next = newItem;
		newItem->next = tmp.next;
		newItem->prev = last;
		this->prev = newItem;
		last = newItem;
	}
	return(1);
}
 	
int square::Sum() {
	int sum = 0;
	for (int count = 0; count < this->razm; count++){
		for (int count2 = 0; count2 < this->razm; count2++){
			sum = sum + this->arr[count][count2];
		}
	}
	return sum;
}

int diagol::Sum() {
	int sum = 0;
	for (int count = 0; count < this->razm; count++){
		for (int count2 = 0; count2 < this->razm; count2++){
			if (count == count2){
			sum = sum + this->arr[count][count];
			}
		}
	}
	return sum;
}

int matr::InData(ifstream &ifst){
	int var_prt = 0;
	ifst >> var_prt;
 	switch(var_prt) {
 		case 1:	
		 	this->variant = matr::var_print::POSTROCHNO;
		 	return 1;
		case 2:	
		 	this->variant = matr::var_print::POSTOLBZAM;
			return 1;	
		case 3:	
			this->variant = matr::var_print::ODNOMERNO;
			 return 1;	
		default:
 			this->variant = matr::var_print::INCORRECT;
 			return 1;				
	}
}

int down_triangle::Sum() {
	int len = 0;
	int sum = 0;
	for (int j = 1; j < (this->razm); j++) {
		len = len + (this->razm - j);		
	}
	len = (this->razm) * (this->razm) - len;
	for (int count = 0; count < len; count++){
		sum = sum + this->arr[count];
	}
	return sum;
}

void container::Out_Sum(ofstream &ofst) {
	container *p;
	p = this;
	int num = 0;
	do {
		num = num + 1;
		p = p->next; 
	} while (p != this); 
	  ofst << "Container contains " << num-1 << " elements." << endl;
  	if(this->next == this){
		return;
	}
	p = this->next;
	do {
	    matr *s = p->cont;
	    s->Out(ofst);
	    ofst << "Sum_matr = " << s->Sum() << endl;
	    p = p->next; 
	} while (p != this); 
}

void matr::Out(ofstream &ofst) {
	if (this->variant == 0)
        ofst << "Print need POSTROCHNO"<<endl;
    else if (this->variant == 1)
         ofst << "Print need POSTOLBZAM"<<endl;
    else if (this->variant == 2)
         ofst << "Print need ODNOMERNO"<<endl;
    else 
         ofst << "Incorrect variant of print"<<endl;
}

void matr::Out_square(ofstream &ofst) {
	ofst << endl;	
}

void square::Out_square(ofstream &ofst) {
	this->Out(ofst);
}

void container::Out_square(ofstream &ofst) { 	
	
	container p;
	container* tmp;
	p = *this;
	int num = 0;
	do {
		num = num + 1;
		p = *p.next; 
		tmp = p.next;
	} while (p.next != this->next); 
	ofst << "Container contains " << num -1	<< " elements." << endl;
	ofst << "Only square" << endl;
	if(this->next == this) {
		ofst<<"none"<<endl;
		return;
	}
	p = *this->next;
	do {
		matr *s = p.cont;
	    s->Out_square(ofst);
		container *tmp;
		tmp = p.next;	    
	    p = *p.next; 
	} while (p.next != this->next); 
};

void square::MultiMethod(matr *other,ofstream &ofst) {
	other->MMSquare(ofst);
}
void diagol::MultiMethod(matr *other,ofstream &ofst) {
	other->MMDiagol(ofst);
}
void down_triangle::MultiMethod(matr *other,ofstream &ofst) {
	other->MMDown_triangle(ofst);
}

void square::MMSquare(ofstream &ofst) {
	ofst << "Square and Square" << endl;
}

void square::MMDiagol(ofstream &ofst) {
	ofst << "Diagol and Square" << endl;
}

void square::MMDown_triangle(ofstream &ofst) {
	ofst << "Down triangle and Square" << endl;
}


void diagol::MMSquare(ofstream &ofst) {
	ofst << "Square and Diagol" << endl;
}

void diagol::MMDiagol(ofstream &ofst) {
	ofst << "Diagol and Diagol" << endl;
}

void diagol::MMDown_triangle(ofstream &ofst) {
	ofst << "Down triangle and diagol" << endl;
}

void down_triangle::MMSquare(ofstream &ofst) {
	ofst << "Square and Down triangle" << endl;
}

void down_triangle::MMDiagol(ofstream &ofst) {
	ofst << "Diagol and  Down triangle" << endl;
}

void down_triangle::MMDown_triangle(ofstream &ofst) {
	ofst << "Down triangle and Down triangle" << endl;
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


bool FileIsExist5(std::string filePath){
    bool isExist = false;
    std::ifstream fin(filePath.c_str());
    if(fin.is_open())
        isExist = true;
    fin.close();
    return isExist;
}
 
