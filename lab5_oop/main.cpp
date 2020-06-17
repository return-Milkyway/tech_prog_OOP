
#include "Program.h"
//using namespace std;
int main(int argc, char* argv[]) {
	if(argc !=3) {
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		return(1);
	}
	
	ofstream ofst(argv[2]);
	if(FileIsExist(argv[1])){}
	else{
		cout << "File is not exist!\n";
		return 1;
	}
    	ifstream ifst(argv[1]);
//	ifstream ifst("in.txt");
//	ofstream ofst("out.txt");
	cout << "Start"<< endl;
	container c;
	int test=1;
	test=c.In(ifst);
	if (test==0) {
	return 1;
	}
	ofst << "Filled container. " << endl;
	
	test=c.Sort();
	if (test==0) {
	cout<< "incorrect input"<<endl;
	return 1;
	}
	c.Out_Sum(ofst);	
	//c.Out(ofst);	
	ofst<<endl;
	c.Out_square(ofst);
	c.Clear();
	ofst << "Empty container. " << endl;
	c.Out(ofst);
	cout << "Stop"<< endl;
	return 0;
}

