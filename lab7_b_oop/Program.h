#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

bool FileIsExist5(std::string filePath) ;
 
class matr {
 	enum var_print{POSTROCHNO,POSTOLBZAM,ODNOMERNO,INCORRECT};//1,2,3
	var_print variant;
	public:
		static matr* In(ifstream &ifst);
		virtual int InData(ifstream &ifst) = 0;
		virtual void Out( ofstream &ofst) = 0;
		virtual int Sum() = 0;
		bool Compare(matr *other);
		virtual void Out_square(ofstream &ofst);
		virtual void MultiMethod(matr *other,ofstream &ofst)=0;
 		virtual void MMSquare(ofstream &ofst)=0;
 		virtual void MMDiagol(ofstream &ofst)=0;
 		virtual void MMDown_triangle(ofstream &ofst)=0;
};
 
class square: public matr {
	int razm;
	int** arr;
	public:
		int InData( ifstream &ifst);
		int Sum();	 
		void Out(ofstream &ofst);	 
		void Out_square(ofstream &ofst);
		void MultiMethod(matr *other,ofstream &ofst);
 		void MMSquare(ofstream &ofst);
 		void MMDiagol(ofstream &ofst);
 		void MMDown_triangle(ofstream &ofst);
		square(){};
};

class diagol: public matr {
	int** arr;
	int razm;
	public:
	 	int InData( ifstream &ifst);
		void Out(ofstream &ofst);
		int Sum();	 
		diagol(){}
		void MultiMethod(matr *other,ofstream &ofst);
		void MMSquare(ofstream &ofst);
 		void MMDiagol(ofstream &ofst);
 		void MMDown_triangle(ofstream &ofst);
};

class down_triangle: public matr {
	int* arr;
	int razm;
	public:
	 	int InData( ifstream &ifst);
	 	int Sum();	
		void Out(ofstream &ofst);	 
		down_triangle(){}
		void MultiMethod(matr *other,ofstream &ofst);
		void MMSquare(ofstream &ofst);
 		void MMDiagol(ofstream &ofst);
 		void MMDown_triangle(ofstream &ofst);
};
  	
class container{
 	matr *cont;
 	public :class container* next;	
 			class container* prev;
 	public :
 		int In(ifstream &ifst);
 		void Out(ofstream &ofst);
 		container(){
			this->next = this;
		};
		container *  Init();
		container   *Init2(matr  *a);
		container * Clear();
		void Out_Sum(ofstream &ofst);
		int Sort();
		container * Swap( container *lst1, container *lst2,  container *head);
		void Out_square(ofstream &ofst);
		void MultiMethod(ofstream &ofst);
		~container(){}
};
