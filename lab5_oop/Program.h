 #include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

bool FileIsExist(std::string filePath){
    bool isExist = false;
    std::ifstream fin(filePath.c_str());
    if(fin.is_open())
        isExist = true;
 
    fin.close();
    return isExist;
}
 
 class matr {
 	enum var_print{POSTROCHNO,POSTOLBZAM,ODNOMERNO,INCORRECT};//1,2,3
	var_print variant;
	public:
		static matr* In(ifstream &ifst);
		virtual int InData(ifstream &ifst)=0;
		virtual void Out( ofstream &ofst)=0;
		virtual int Sum()=0;
		bool Compare(matr *other);
		virtual void Out_square(ofstream &ofst);
};
 
class square: public matr{
	int b;
	int** a;;
	public:
		int InData( ifstream &ifst);
		//void Out(ofstream &ofst);
		int Sum();	 
		void Out(ofstream &ofst);	 
		void Out_square(ofstream &ofst);
		square(){};
};

class diagol: public matr{
	int** x;
	int y;
	public:
	 	int InData( ifstream &ifst);
		void Out(ofstream &ofst);
		int Sum();	 
		diagol(){}
};

class down_triangle: public matr{
	int* x;
	int y;
	public:
	 	int InData( ifstream &ifst);
	 	int Sum();	
		void Out(ofstream &ofst);	 
		down_triangle(){}
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
		~container(){}
};
