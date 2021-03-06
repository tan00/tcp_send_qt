#include "csv.h"


// endofline: check for and consume \r, \n, \r\n, or EOF
int Csv::endofline(char c)
{
    int eol;

    eol = (c=='\r' || c=='\n');
    if (c == '\r')
    {
        fin.get(c);
        if (!fin.eof() && c != '\n')
            fin.putback(c); // read too far
    }
    return eol;
}

// getline: get one line, grow as needed
int Csv::getline(string& str)
{
    char c;

    for (line = ""; fin.get(c) && !endofline(c); )
        line += c;
    split();
    str = line;
    return !fin.eof();
}

// split: split line into fields
int Csv::split()
{
    string fld;
    unsigned int i = 0;
    unsigned int j = 0;

    nfield = 0;
    if (line.length() == 0)
        return 0;

    do {
        if (i < line.length() && line[i] == '"')
            j = advquoted(line, fld, ++i); // skip quote
        else
            j = advplain(line, fld, i);
        if (nfield >= field.size())
            field.push_back(fld);
        else
            field[nfield] = fld;
        nfield++;
        i = j + 1;
    } while (j < line.length());

    return nfield;
}

// advquoted: quoted field; return index of next separator
int Csv::advquoted(const string& s, string& fld, int i)
{
    unsigned int j;

    fld = "";
    for (j = i; j < s.length(); j++)
    {
        if (s[j] == '"' && s[++j] != '"')
        {
            unsigned int k = s.find_first_of(fieldsep, j);
            if (k > s.length()) // no separator found
                k = s.length();
            for (k -= j; k-- > 0; )
                fld += s[j++];
            break;
        }
        fld += s[j];
    }
    return j;
}

// advplain: unquoted field; return index of next separator
int Csv::advplain(const string& s, string& fld, int i)
{
    unsigned int j;

    j = s.find_first_of(fieldsep, i); // look for separator
    if (j > s.length()) // none found
        j = s.length();
    fld = string(s, i, j-i);
    return j;
}


// getfield: return n-th field
string Csv::getfield(int n)
{
    if (n < 0 || n >= nfield)
        return "";
    else
        return field[n];
}

int Csv::read(vector<vector<std::string> > &vec)
{
    int lineNum = 0;
    vec.clear();

    vector<std::string> vec_str;
    while (getline(line) != 0)
    {
        if( line.length()>0 ){
            vec.push_back(vec_str);
            vec[lineNum].resize( getnfield() );
            for (int i = 0; i < getnfield(); i++){
                vec[lineNum][i] = getfield(i);
                //vec[lineNum]
            }
            lineNum++;
        }
    }
    return (lineNum);
}

int Csv::write(vector<vector<std::string> > &vec, std::ostream &fout)
{
   for( vector<vector<std::string> >::iterator iter1 = vec.begin();  iter1!=vec.end();iter1++)
   {
       for( vector<std::string>::iterator iter2 = (*iter1).begin();  iter2!= (*iter1).end(); iter2++)
       {
           if( *iter2== "," ){
               fout << " \",\" " ;
               continue;
           }else if( *iter2== "\"" ){
               fout << *iter2 << "\"\"\"\"";
               continue;
           }else{
               fout << *iter2 << ",";
               continue;
           }
           fout << std::endl;
       }
   }
   return vec.size();
}

// Csvtest main: test Csv class
//int main(void)
//{
//    string line;
//    Csv csv;

//    while (csv.getline(line) != 0)
//    {
//        cout << "line = `" << line <<"'\n";
//        for (int i = 0; i < csv.getnfield(); i++)
//            cout << "field[" << i << "] = `"
//            << csv.getfield(i) << "'\n";
//    }
//    return 0;
//}
