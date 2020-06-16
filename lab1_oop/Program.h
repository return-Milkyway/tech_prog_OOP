 #include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
 
 class matr {
	public:
		static matr* In(ifstream &ifst);
		virtual void InData(ifstream &ifst)=0;
		virtual void Out( ofstream &ofst)=0;
		virtual int Sum()=0;
		bool Compare(matr *other);
		virtual void Out_square(ofstream &ofst);
};
 
class square: public matr{
	int b;
	int** a;;
	public:
		void InData( ifstream &ifst);
		void Out(ofstream &ofst);
		int Sum();	 
		void Out(ofstream &ofst);	 
		void Out_square(ofstream &ofst);
		square(){};
};

class diagol: public matr{
	int** x;
	int y;
	public:
	 	void InData( ifstream &ifst);
		void Out(ofstream &ofst);
		int Sum();	 
		diagol(){}
};

class down_triangle: public matr{
	int* x;
	int y;
	public:
	 	void InData( ifstream &ifst);
		void Out(ofstream &ofst);	 
		down_triangle(){}
};
  	
 class container{
 	matr *cont;
 	public :class container* next;	
 			class container* prev;
 	public :
 		container* In(ifstream &ifst);
 		void Out(ofstream &ofst);
 		container(){
			this->next = this;
		};
		container *  Init();
		container   *Init2(matr  *a);
		container * Clear();
		void Out_Sum(ofstream &ofst);
		void Sort();
		container * Swap( container *lst1, container *lst2,  container *head);
		void Out_square(ofstream &ofst);
		~container(){}
};
