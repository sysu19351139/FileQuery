#include"FileQuery.h"
#include<iostream>
#include<string>
#include<set>
#include<fstream>
#include<map>
#include<vector>
#include<sstream>
#include<memory>
#include<iterator>
#include <iomanip>
using namespace std;

FileQuery::FileQuery(ifstream& is) :sentences_(new vector<string>)
{
	string text_, all;
	string separator1="., ";                                       
    string separator2 = ",.";
    string separator3 = "  ";
	while (getline(is, text_))                                  
	{
		all += text_;
		}
	string::size_type start = all.find_first_not_of(separator1);
	while(start != string::npos)                                 
	{
		string::size_type end = all.find_first_of(separator2, start);
		string text(all, start, end - start+1);
		sentences_->push_back(text);
		int n = sentences_->size() - 1;
		istringstream line(text);                                
		string w;
		while (line >> w)
		{
			if (!(w==separator3))
			{
				w = cleanup_str(w);                           
				auto& lines = wm[w];
				if (!lines)
				lines = new set<line_no>;
				lines->insert(n);
			}
		}
		start = all.find_first_not_of(separator1, end);
	}
}

FileQuery::~FileQuery()                                     
{
	for (auto item : wm) {
		delete item.second; 
	}
	delete sentences_;
}

QueryResult FileQuery::query(string&)
{
	return QueryResult();
}

string FileQuery::cleanup_str(string& word)           
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it) {
		if (!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}

QueryResult FileQuery::query(string& sought)        
{
	static set<line_no> nodata;

	auto loc = wm.find(cleanup_str(sought));

	if (loc == wm.end())
		return QueryResult(sought, &nodata, sentences_); 
	else {
		auto s = loc->first;
		return QueryResult(sought, loc->second, sentences_);
	}
}

void FileQuery::PrintSentencesOrdered()
{
	for (vector<string>::iterator it = sentences_->begin(); it < sentences_->end(); it++)
	{

		cout << *it << endl;

	}
}

void FileQuery::PrintSentencesFiltered(string& str, QueryResult& qr)
{
	for (auto num : *qr.lines) 
		cout << "\t(line " << num + 1 << ") " << qr.sentences_->at(num) << endl;
}

void FileQuery::PrintWorldCount()
{
	for (map<string, set<line_no>*>::iterator it_ = wm.begin(); it_ != wm.end(); it_++)
	{
		QueryResult qr(query(it_->first));
		cout <<"the word:"<< setiosflags(ios::left) <<setw(15)<< qr.sought << " occurrences: " << setiosflags(ios::left) << setw(22)<<qr.lines->size() <<endl;
	}
	cout << "\n";
}

void FileQuery::ReplaceWord(string& old, string& new_, QueryResult& qr)
{
	for (auto num : *qr.lines)
	{
		qr.sentences_->at(num).replace(qr.sentences_->at(num).find(old), old.length(), new_);
		cout << qr.sentences_->at(num) << endl;
	}
}