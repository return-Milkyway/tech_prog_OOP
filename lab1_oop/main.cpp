
#include "Program.h"
//using namespace std;
int main(int argc, char* argv[]) {
	if(argc !=3) {
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		return(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	//ifstream ifst("in.txt");
	//ofstream ofst("out.txt");
	cout << "Start"<< endl;
	container c;
	c.In(ifst);
	ofst << "Filled container. " << endl;
	//c.Out(ofst);
	c.Sort();
	c.Out_Sum(ofst);	
	c.Clear();
	ofst << "Empty container. " << endl;
	c.Out(ofst);
	cout << "Stop"<< endl;
	return 0;
}

