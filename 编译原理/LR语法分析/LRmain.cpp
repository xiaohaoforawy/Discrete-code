//
//  main.cpp
//  LR
//
//  Created by 魏晓 on 12/18/17.
//  Copyright © 2017 魏晓. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int stringtoint(string s)//基本函数
{
    int num;
    stringstream ss(s);
    ss>>num;
    return num;
}

string inttostring(int i)
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

int judgev(int num)
{
    return num%100;
}
int judgez(int num)
{
    return num/1000;
}
string zuozhanding(string temp)
{
    return temp.substr(0,1);
}
string zuotanzhan(string temp){
    string another=temp.substr(1,temp.size()-1);
    return another;
}
string shuzitan(string temp)
{
    if(isdigit(temp[0]))
        return temp;
    else
        return temp.substr(1,temp.size()-1);
}
string youtanzhan(string temp){
    string another=temp.substr(0,temp.size()-1);
    return another;
}
string youzhanding(string temp){
    if(temp[temp.size()-2]=='1')
        return temp.substr(temp.size()-2,2);
    return temp.substr(temp.size()-1,1);
}
string youruzhan(string temp,string tchar){
    return temp+tchar;
}
string reducestring(string a,int num)
{
    int  um=int(a.size());
    for(int i=um-1;i>0;i--)
    {
        if(!isdigit(a[i]))
            num--;
        if(num==0)
            return a.substr(0,i);
    }
    return a;
}
typedef struct rrrecord{
    string zhan;
    string shuru;
    string dongzuo;
    rrrecord(string a,string b,string c)
    {
        zhan=a;
        shuru=b;
        dongzuo=c;
    }
}record;
class Lr{
public:
    map <int,string> table;
    vector<string> v{"","+","-","*","/","(",")","N","$","E","T","F"};
    vector<string> anas{"","E->E+T","E->E-T","E->T","T->T*F","T->T/F","T->F","F->(E)","F->N"};
    string shuru;
    string fenxizhan="0";
    vector<record> re;
    Lr();
    ~Lr();
    void cifafenxi();
    int searchv(string a);
    void fenxi();
    int chaxunshu(string a,string b);
};
void Lr::cifafenxi()
{
    string temp=shuru;
    string ans;
    for(int i=0;i<shuru.size();i++)
    {
        if(isdigit(temp[i]))
        {
            ans=ans+"N";
            for(int j=i;j<shuru.size()&&isdigit(temp[j]);j++)
            {
                i=j+1;
            }
        }
        
        ans=ans+temp[i];
    }
    cout<<ans;
    shuru=ans;
}
int Lr::searchv(string a)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==a)
            return i;
    }
    return -1;
}
Lr::Lr()
{
    table[105]="S4";
    table[107]="S5";
    table[109]="1";
    table[110]="2";
    table[111]="3";
    table[1101]="S6";
    table[1102]="S7";
    table[1108]="ACC";
    table[2101]="R3";
    table[2102]="R3";
    table[2103]="S8";
    table[2104]="S9";
    table[2106]="R3";
    table[2108]="R3";
    table[3101]="R6";
    table[3102]="R6";
    table[3103]="R6";
    table[3104]="R6";
    table[3106]="R6";
    table[3108]="R6";
    table[4105]="S4";
    table[4107]="S5";
    table[4109]="10";
    table[4110]="2";
    table[4111]="3";
    table[5101]="R8";
    table[5102]="R8";
    table[5103]="R8";
    table[5104]="R8";
    table[5106]="R8";
    table[5108]="R8";
    table[6105]="S4";
    table[6107]="S5";
    table[6110]="11";
    table[6111]="3";
    table[7105]="S4";
    table[7107]="S5";
    table[7110]="12";
    table[7111]="3";
    table[8105]="S4";
    table[8107]="S5";
    table[8111]="13";
    table[9105]="S4";
    table[9107]="S5";
    table[9111]="14";
    table[10101]="S6";
    table[10102]="S7";
    table[10106]="S15";
    table[11101]="R1";
    table[11102]="R1";
    table[11103]="S8";
    table[11104]="S9";
    table[11106]="R1";
    table[11108]="R1";
    table[12101]="R2";
    table[12102]="R2";
    table[12103]="S8";
    table[12104]="S9";
    table[12106]="R2";
    table[12108]="R2";
    table[13101]="R4";
    table[13102]="R4";
    table[13103]="R4";
    table[13104]="R4";
    table[13106]="R4";
    table[13108]="R4";
    table[14101]="R5";
    table[14102]="R5";
    table[14103]="R5";
    table[14104]="R5";
    table[14106]="R5";
    table[14108]="R5";
    table[15101]="R7";
    table[15102]="R7";
    table[15103]="R7";
    table[15104]="R7";
    table[15106]="R7";
    table[15108]="R7";
    
}
Lr::~Lr()
{
    
}
int Lr::chaxunshu(string a, string b)
{
    int num=searchv(a);
    string ans;
    if(num>9)
        ans="1"+inttostring(num);
    else
        ans="10"+inttostring(num);
    ans=b+ans;
    return stringtoint(ans);
}
void Lr::fenxi(){
    shuru=shuru+"$";
    do{
        string a=zuozhanding(shuru);
        string b=youzhanding(fenxizhan);
        cout<<fenxizhan<<"\t\t\t"<<shuru<<"\t\t\t";
        string dongzuo=table[chaxunshu(a,b)];
        if(dongzuo[0]=='S')
        {
            fenxizhan=fenxizhan+a;
            string ttt=zuotanzhan(dongzuo);
            fenxizhan=fenxizhan+ttt;
            shuru=zuotanzhan(shuru);
            cout<<"shift->"<<zuotanzhan(dongzuo)<<endl;
        }
        else if(dongzuo[0]=='R')
        {
            string jianshao=anas[stringtoint(zuotanzhan(dongzuo))];
            cout<<"reduce BY->"<<anas[stringtoint(zuotanzhan(dongzuo))]<<endl;
            string A=zuozhanding(jianshao);
            string b=zuotanzhan(zuotanzhan(zuotanzhan(jianshao)));
            fenxizhan=reducestring(fenxizhan, int(b.size()));
            string douo=table[chaxunshu(A,youzhanding(fenxizhan))];
            //cout<<douo<<endl;
            fenxizhan=fenxizhan+A;
            fenxizhan=fenxizhan+shuzitan(douo);
            
            
        }
        else if(dongzuo=="ACC"){
            cout<<"ACC"<<endl;
            break;
        }
        else
        {
            cout<<"error!"<<endl;
            break;
        }
        
    }
    while(true);
}

int main(int argc, const char * argv[]) {
   
    Lr temp;
    string in="((23+3)*(13/542))";
    temp.shuru=in;
    temp.cifafenxi();
    temp.fenxi();
    return 0;
}
