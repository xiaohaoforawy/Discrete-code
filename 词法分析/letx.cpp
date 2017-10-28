//  Created by 魏晓 on 10/23/17.
//  Copyright © 2017 魏晓. All rights reserved.
/*改进要点：
* 1：正则表达式匹配
* 2：查找字典树返回结果不正确
* 3：注释处理!!!!
*/
#include <regex>
#include "letx.hpp"
#include <fstream>
#include <sstream>
using namespace std;
void Vname::add(const std::string &str, int loc) {
    Dic *p = this->root, *q;
    unsigned long tp=str.length();
    for(int i=0; i<tp; i++) {
        int id;
        if(str[i]>='0'&&str[i]<='9')
            id=str[i]-'0'+26;
        else
            id = str[i] - 'a';
        if(p->next[id] == nullptr){
            q = new Trie();
            p->next[id] = q;
        }
        p = p->next[id];
    }
    p->isEnd = true;
    p->loc = loc;
}
void Vname::add(vector<string> strs) {
    int loc = 0;
    for(const auto a: strs) {
        this->add(a, loc++);
    }
}
int Vname::find(const string &str) {
    Trie *p = this->root;
    unsigned long tp=str.length();
    for(int i=0; i<tp; ++i) {
        int id;
        if(str[i]<='9'&&str[i]-'0'>=0)
            id=str[i]-'0'+26;
        else
            id = str[i] - 'a';
        if(id < 0 || id >= 36)
            return -1;
        p = p->next[id];
        if(p == nullptr) return -1;
    }
    if(p->isEnd)
        return p->loc;
    return -1;
}
void Vname::free(Trie *p) {
    if(p == nullptr) return;
    for(int i=0; i<36; ++i) this->free(p->next[i]);
    delete p;
}
string Lexical::cut(int i, int j) {
    return string(in.begin() + i, in.begin() + j);
}
Lexical::Lexical() {
    keyword={"main","if","then","while","do","static",
        "defualt","do","int","double","struct","break",
        "else","long","swtich","case","typedf","char",
        "return","const","float","short","continue",
        "for","void","sizeof","string","cout","cin",
        "include","define","endl"};
    optrs={ {"+","ARITHMETICOPTR"},{"-","ARITHMETICOPTR"},{"*","ARITHMETICOPTR"},{"/","ARITHMETICOPTR"},
            {"%","ARITHMETICOPTR"},{"++","ARITHMETICOPTR"},{"--","ARITHMETICOPTR"},
            {">>","ARITHMETICOPTR"},{"<<","ARITHMETICOPTR"},{"&","ARITHMETICOPTR"},{",","DELIMITER"},
            {";","DELIMITER"},{"{","DELIMITER"},{"}","DELIMITER"},{"(","DELIMITER"},
            {"#","ARITHMETICOPTR"},{")","DELIMITER"},{"[","DELIMITER"},{"]","DELIMITER"},{">","RELATIONOPTR"},
            {"<","RELATIONOPTR"},{">=","RELATIONOPTR"},{"<=","RELATIONOPTR"},
            {"=","RELATIONOPTR"},{"<>","RELATIONOPTR"},{"->","RELATIONOPTR"},{"!=","RELATIONOPTR"}};
    row=0;
    column=0;
    cha=0;
    duohang=true;
}
Lexical::~Lexical() {
    cout<<"This file has\t"<<row-1<<"row\t"<<column<<"col\t"<<cha<<"char\t"<<endl;
}
bool Lexical::isKey(const std::string &str) {
    unsigned long temp=keyword.size();
    for(int i=0;i<temp;i++)
        if(str==keyword[i]) return true;
    return false;
}
bool Lexical::isChar(const std::string &str) {
    if(str.length() == 1) return true;
    if(str[0]=='\\'&&str.length()==2) return true;
    return false;
}
bool Lexical::isNum(std::string str) {//匹配无符号数
    //const regex pattern("d+.?d*");
    //return regex_match(str,pattern);
    for(auto c:str)
        if(!(bool)isdigit(c)) return false;
    return true;
}
bool Lexical::isId(const std::string &str) {
    if(!(bool)isalpha(str.c_str()[0]) && str.c_str()[0] != '_')
        return false;
    for(auto c: str)
        if(!(bool)isalnum(c) && c != '_') return false;
    return true;
}
bool Lexical::isString(const std::string &str) {
    return true;
}
string Lexical::isOptr(std::string str) {
    map<string,string>::iterator iter;
    iter=optrs.find(str);
    if(iter!=optrs.end()) return optrs[str];
    return "ERR";
}
string Lexical::processspace(std::string str) {
    string temp="";
    auto n=(int)str.length();
    int i;
        for(i=0;i<n;i++){
            if(duohang==false){
                string com="";
                for(int m=i;m<n&&duohang==false;m++,i++){
                    if(str[m-1]=='*'&&str[m]=='/') duohang=true;
                    com+=str[m];
                    }
                i=i-1;
                cout<<"Comment:"<<com<<"location:"<<row<<endl;
            }
            else if(str[i]=='/'&&str[i+1]=='/'){
                string com="";
                for(int m=i;m<n;m++) com+=str[m];
                cout<<"Comment:"<<com<<"location:"<<row<<endl;
                break;
            }
            else if(str[i]=='/'&&str[i+1]=='*') duohang=false;
            else if(str[i]!=' '&&str[i]!='\t') temp=temp+str[i];
            if(str[i-1]!=' '&&str[i]==' '&&i>1) temp+=' ';
        }
        return temp;
}
void Lexical::analysis() {
    in=processspace(in);
    auto Inlength=(int)in.length();
    cha+=Inlength;
    for(int i=0;i<Inlength;i++) {
        char C=in.c_str()[i];
        if((bool)isalpha(C)){
            int j=0;
            for(j=i;j<Inlength&&(in[j]=='_'||(bool)isalnum(in[j]));j++);
            string temp=cut(i,j);
            column++;
            if(isKey(temp)) {
                Ans te={temp,"KEYWORD",row,column,"^"};
                Lans.push_back(te);
            }else if(isId(temp)) {
                int jj=indetifiers.find(temp);
                if(jj==-1) indetifiers.add(temp,column);
                jj=indetifiers.find(temp);
                stringstream s;
                s<<jj;
                string ttp=s.str();
                Ans te={temp,"ID"+ttp,row,column,"^"};
                Lans.push_back(te);
            }
            else {
                Ans te={temp,"ERROR!",row,column,"$"};
                Lans.push_back(te);
            }
            i=j-1;
        }
        else if((bool)isdigit(C)){
            int j=0;
            for(j=i+1;j<Inlength&&((bool)isalnum(in[j])||in[j]=='_');j++);
            if(in[j]=='.'&&isdigit(in[j+1]))
                for(j=j+1;j<Inlength&&((bool)isalnum(in[j])||in[j]=='_');j++);
            string s=cut(i,j);
            column++;
            if(isNum(s)){
                Ans te={s,"NUMBER",row,column,"^"};
                Lans.push_back(te);
            }
            else {
                Ans te={s,"ERROR NUMBER",row,column,"$"};
                Lans.push_back(te);
            }
            i=j-1;
        }
        else if("ERR"!=isOptr(string(1,C))){
            string s;
            char temp=in[i+1];
            column++;
            if("ERR"!=isOptr(string(1,temp))){
                s=C;
                s=s+string(1,temp);
                i+=1;
            }
            else
                s=string(1,C);
            map<string, string>::iterator iter;
            iter = optrs.find(s);
            if("ERR"!=isOptr(s)){
                Ans te={s,iter->second,row,column,"^"};
                Lans.push_back(te);
            }
            else{
                Ans te={s,"ERROR OPTR",row,column,"$"};
                Lans.push_back(te);
            }
        }
        else if(C == '"' || C== '\'') {
            int j=0;
            for(j=i+1;j<Inlength&&(in[j]!=C);++j);
            string s=cut(i+1,j);
            column++;
            if(C=='"'&&j<Inlength){
                Ans te={s,"COMMENT",row,column,"^"};
                Lans.push_back(te);
            }
            else if(C=='\''&&isChar(s)){
                Ans te={s,"CHAR",row,column,"^"};
                Lans.push_back(te);
            }
            else{
                Ans te={s,"ERROR CHAR",row,column,"$"};
                Lans.push_back(te);
            }
            i=j;
        }
        else if(C!=' '){
            column++;
            Ans te={string(1,C),"USELESS CHAR",row,column,"$$$"};
            Lans.push_back(te);
        }
    }
}
void Lexical::run() {
    int choice;
    cout<<"If you want input file,please press 1:";
    cin>>choice;
    if(choice==1) {
        fstream  fin;
        fin.open("/Users/weixiao/Documents/Xcode/词法分析/词法分析/test.txt",fstream::in);
        while(!fin.eof()){
            getline(fin,in);
            ++row;
            analysis();
        }
    }
    else {
        cout<<"input\"$\"to exit"<<endl;
        while (getline(cin, in) && in != "$") {
            ++row;
            analysis();
            show();
        }
    }
}
void Lexical::show() {
    unsigned long len=Lans.size();
    for(int i=0;i<len;i++) {
    cout<<"\t"<<Lans[i].sign<<"\t\t\t\t"<<Lans[i].type<<"\t\t\t\t\tLocation:("<<Lans[i].hang<<","<<Lans[i].lie<<")$"<<endl;
    }
}
