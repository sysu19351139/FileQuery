#include"Shape.h"
#include"FileQuery.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void TestShape()               
{
	Rectangle r(3, 5);
	cout << "the area of rectangle is:\n" << r.GetArea() << endl;
	Circle c(5);
	cout << "the area of the circle:\n" << c.GetArea() << endl;
	square s(5);
	cout << "the area of the square:\n" << s.GetArea() << endl;
}
void TestTextQuery(ifstream& infile)
{
	FileQuery tq(infile);
	cout << "This is the PrintSentencesOrdered function:\n";
	tq.PrintSentencesOrdered();
	cout << "\n";
	cout << "\nThis is the PrintWorldCount function :\n";
	tq.PrintWorldCount();
	while (true)                                        
	{
		cout << "enter word to look for, or q to quit: ";
		string str;
		if (!(cin >> str) || str == "q") break;
		cout << "\n";
		cout << "This is the PrintSentencesFiltered function :\n";
		tq.PrintSentencesFiltered(str, tq.query(str));
		cout << "\nThis is the ReplaceWord function\n";
		cout << "please input the old word:";
		string old, new_;                                              
		cin >> old;
		cout << "\ninput the new word:";
		cin >> new_;
		cout << "\n";
		tq.ReplaceWord(old, new_, tq.query(old));
		cout << "finished\n";
	}
}
int main()
{
	ifstream infile;
	if (argc < 2 || !(infile.open(argv[1]), infile)) 
	{
		cerr << "No input file!" << endl;
		return -1;
	}
	cout << "This is the TestTextQurry function:\n" << endl;
	TestTextQuery(infile);
	cout << "\n";
	cout << "This is the TestShape function" << endl;
	TestShape();
	return 0;
}