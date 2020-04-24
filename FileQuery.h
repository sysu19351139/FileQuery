#include<iostream>
#include<string>
#include<set>
#include<fstream>
#include<map>
#include<vector>
#include<memory>
using namespace std;

class FileQuery;
class QueryResult {                                                                  
	friend class FileQuery;
public:
	typedef vector<string>::size_type line_no;

	QueryResult(string s, set<line_no>* p,vector<string>* f) :
		sought(s), lines(p), sentences_(f) {};

private:
	string sought;  
	set<line_no>* lines; 
	vector<string>* sentences_;  
};
class FileQuery                                                                          
{
public:
	using line_no = vector<string>::size_type;
	FileQuery(ifstream&);                                                         
	~FileQuery();
	QueryResult query(string&);
	void PrintSentencesOrdered();
	void PrintSentencesFiltered(string& str, QueryResult& qr);
	void PrintWorldCount();
	void ReplaceWord(string& old, string& new_, QueryResult& qr);
private:
	vector <string >* sentences_;
	static string cleanup_str(string&);
	map<string,set<line_no>*> wm;
};
