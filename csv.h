#ifndef CSV_H
#define CSV_H
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::istream ;
using std::ostream ;
using std::string ;
using std::vector ;
using std::cin ;

class Csv
{
    // read and parse comma-separated values
    // sample input: "LU",86.25,"11/4/1998","2:19PM",+4.0625

public:
    Csv(istream& fin, string sep = ","):fin(fin), fieldsep(sep) {}


    int getline(string&);
    string getfield(int n);                    //  get n column string
    int getnfield() const { return nfield; }   //get total column  of one line

    int read( vector< vector<string> > &vec);
    int write( vector< vector<string> > &vec , ostream& fout );



 private:
    istream& fin; // input file pointer
    string line; // input line
    vector<string> field; // field strings
    int nfield; // number of fields
    string fieldsep; // separator characters

    int split();
    int endofline(char);
    int advplain(const string& line, string& fld, int);
    int advquoted(const string& line, string& fld, int);
};

#endif // CSV_H
