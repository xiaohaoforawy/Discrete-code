//
//  main.cpp
//  LL1
//
//  Created by 魏晓 on 11/7/17.
//  Copyright © 2017 魏晓. All rights reserved.
//-----------------------------------------------------
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iterator>
using namespace std;

typedef struct ffset{
    char nt;//NT
    vector<char> first;
    vector<char> follow;
    vector<string> production;
    ffset(char a,vector<char> b,vector<char> c,vector<string> d)
    {
        nt=a;
        first = b;
        follow = c;
        production=d;
    }
}set;
char zuozhanding(string temp)
{
    return temp[0];
}
string zuotanzhan(string temp){
    string another=temp.substr(1,temp.size()-1);
    return another;
}
string youtanzhan(string temp){
    string another=temp.substr(0,temp.size()-1);
    return another;
}
string youruzhan(string temp,string tchar){
    return temp+tchar;
}
char youzhanding(string temp){
    return temp[temp.size()-1];
}
string strrev(string str)
{
    string temp="";
    for(auto i:str){
        temp=i+temp;
    }
    return temp;
}
typedef struct programoutput{
    string anastack;
    string inputcomment;
    string outputcomment;
    string leftpattern;
    programoutput(string a,string b,string c,string d){
        anastack=a;
        inputcomment=b;
        outputcomment=c;
        leftpattern=d;
    }
}outp;
class excel{
private:
    vector<set> TT;
    map<string,string> analysistable;
    map<string,string>::iterator iter;
    std::vector<char> VN{'E','D','T','B','F'};
    std::vector<char> VT{'+','-','*','/','(',')','d','n','s'};
    vector<outp> ans;
public:
    
    excel();
    ~excel();
    void gene();//构造分析表
    string searchgene(char w,char m);//查找分析表
    void displaygene();//显示分析表
    void Syntaxanalysis(string analytarget);//语法分析
    void displayana();
    bool judgeNT( char ch);
    bool judgeVT( char ch);
};

bool excel::judgeNT(char ch){
    for(auto c:VN)
        if(ch==c)
            return true;
    return false;
}

bool excel::judgeVT(char ch){
    for(auto c:VT)
        if(ch==c)
            return true;
    return false;
}
excel::excel(){
    TT.push_back(set('E',{'d','(','n'},{'s',')'},{"TD"}));
    TT.push_back(set('D',{'+','-','e'},{'s',')'},{"+TD","-TD","e"}));
    TT.push_back(set('T',{'d','(','n'},{'+','-','s',')'},{"FB"}));
    TT.push_back(set('B',{'*','/','e'},{'+','-','s',')'},{"*FB","/FB","e"}));
    TT.push_back(set('F',{'d','(','n'},{'*','/','+','-','s',')'},{"d","(E)","n"}));
}


excel::~excel(){
    
}

void excel::gene(){
    for(auto se:TT){
        for(auto fi:se.first){
            if(fi=='e'){
                for(auto fo:se.follow){
                    string aa;
                    stringstream stream;
                    stream<<se.nt;
                    aa=stream.str();
                    aa=aa+fo;
                    analysistable[aa]="e";
                }
            }
            else{
                int choice=0;//choice
                int temp=(int)(se.production).size();
                for(int i=0;i<temp;i++){
                    if(se.production[i][0]==fi){
                        choice=i;
                        break;
                    }
                }
                string aa;
                stringstream stream;
                stream<<se.nt;
                aa=stream.str();
                aa=aa+fi;
                analysistable[aa]=se.production[choice];
            }
        }
    }
}

string excel::searchgene(char w,char m){
    string aa;
    stringstream stream;
    stream<<w;
    aa=stream.str();
    aa=aa+m;
    return analysistable[aa];
}
void excel::displaygene(){
    cout<<"\t\t";
    for(auto t:VT)
        cout<<t<<"\t\t";
    cout<<endl;
    for(auto p:VN){
        cout<<p<<"\t\t";
        for(auto q:VT){
            if(searchgene(p,q).length()>0)
                cout<<p<<"->"<<searchgene(p,q)<<"\t";
            else
                cout<<"\t\t";
        }
        cout<<endl;
    }
}
void excel::Syntaxanalysis(string analytarget){
    analytarget=analytarget+'s';
    string stak="sE";
    ans.push_back(outp(stak,analytarget,"\t",youtanzhan(strrev(stak))));
    do{
        //cout<<"1error!"<<endl;
        char X=youzhanding(stak);
        char A=zuozhanding(analytarget);
        if(judgeVT(X))
        {
            if(X==A)
            {
                stak=youtanzhan(stak);
                analytarget=zuotanzhan(analytarget);
                ans.push_back(outp(stak,analytarget,"\t",youtanzhan(strrev(stak))));
                if(X=='s'&&A=='s')
                    cout<<"success"<<endl;
            }
            else{
                cout<<"error!"<<endl;
                break;
            }
        }
        else{
            string wtemp=searchgene(X, A);
            //cout<<wtemp<<endl;
            if(wtemp.size()>0){
                stak=youtanzhan(stak);
                
                wtemp=strrev(wtemp);
                if(wtemp!="e")
                    stak=youruzhan(stak, wtemp);
                string ttmp="->";
                ttmp=ttmp+strrev(wtemp);
                ttmp=X+ttmp;
                ans.push_back(outp(stak,analytarget,ttmp,youtanzhan(strrev(stak))));
            }
            else{
                cout<<"error!"<<endl;
                break;
            }
        }
        
    }while(!(stak=="s"&&analytarget=="s"));
}

void excel::displayana()
{
    int i=1;
    for(auto tt:ans){
        
        cout<<i++<<"."<<tt.anastack<<"\t\t"<<tt.inputcomment<<"\t\t"<<tt.outputcomment<<"\t\t"<<tt.leftpattern<<endl;
    }
}
int main() {
    excel e;
    e.gene();
    cout<<"--------------------------语法分析表--------------------------------"<<endl;
    e.displaygene();
    cout<<"--------------------------分析过程--------------------------------"<<endl;
    string input="(d*n)+(d-n)-(n-d)";
    e.Syntaxanalysis(input);
    e.displayana();
    return 0;
}
