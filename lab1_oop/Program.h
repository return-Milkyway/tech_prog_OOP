 #include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
 
 class matr {
	public:
		static matr* In(ifstream &ifst);
		virtual void InData(ifstream &ifst)=0;
		virtual void Out( ofstream &ofst)=0;
};
 
class square: public matr{
	int b;
	int** a;;
	public:
		void InData( ifstream &ifst);
		void Out(ofstream &ofst);	 
		square(){};
};

class diagol: public matr{
	int** x;
	int y;
	public:
	 	void InData( ifstream &ifst);
		void Out(ofstream &ofst);	 
		diagol(){}
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
		~container(){}
};
