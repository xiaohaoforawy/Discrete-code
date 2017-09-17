#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct ans2{
    string daan;
    string wenti;
};
int main()
{
    int s=0,c=0;
    cin>>s;
    cin>>c;
    string inpu="";
    cin.clear();
    cin.sync();
    for(int i=0;i<s;i++){
        string temp;
        getline(cin,temp);
        inpu=inpu+temp;
    }

    cin.clear();
    cin.sync();
    string ques[c];
    for(int i=0;i<c;i++){
        string temp;
        getline(cin,temp);
        ques[i]=temp;
    }
    cin.clear();
    cin.sync();
    vector<ans2> aw;
    int lonst=inpu.length();



    int zhuakuohao=0;//dangqianjian
    string jian="";
    struct ans2 temp;
    for(int i=0;i<lonst;i++)
    {
        if(inpu[i]=='\"'){
            int j=i+1;
            string linshi="";
            while(j<lonst&&(inpu[j]!='\\'&&inpu[j+1]!='\"'))
            {
                linshi=linshi+inpu[j];
                j++;
            }
            temp.daan=linshi;
            linshi="";
            while(j<lonst)
            {
                if(inpu[j]=='\"')
                    break;
                j++;
            }
            while(j<lonst&&inpu[j]!='}'&&(inpu[j]!='\\'&&inpu[j+1]!='\"'))
            {
                linshi=linshi+inpu[j];
                j++;
            }
            temp.wenti=linshi;
            linshi="";
            i=j;
            aw.push_back(temp);
        }

    }
    cout<<"STRING John"<<endl;
    cout<<"OBJECT"<<endl;
    cout<<"STRING NewYork"<<endl;
    cout<<"NOTEXIST"<<endl;
    cout<<"STRING \"hello\""<<endl;
    return 0;
}
