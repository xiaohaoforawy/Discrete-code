#include <iostream>
using namespace std;

int main(void)
{
    int nkey=0,kman=0;
    std::cin>>nkey;
    std::cin>>kman;
    int input[kman][3];
    for(int i=0;i<kman;i++)
        for(int j=0;j<3;j++)
            cin>>input[i][j];
    int ans[nkey],sur[nkey];
    for(int i=0;i<nkey;i++){
        ans[i]=i+1;//ding yi
        sur[i]=1;
    }
    int maxtime=-1;
    for(int i=0;i<kman;i++){
        if(input[i][1]+input[i][2]>maxtime)
            maxtime=input[i][1]+input[i][2];
    }
    maxtime+=2;
    //right
    for(int i=1;i<maxtime;i++){
        for(int j=0;j<kman;j++){
            if(input[j][2]+input[j][1]==i){
                for(int m=0;m<nkey;m++){
                    if(sur[m]==0){
                        ans[m]=input[j][0];
                        sur[m]=1;
                        break;
                    }
                }
            }
            if(input[j][1]==i){
                for(int m=0;m<nkey;m++){
                    if(ans[m]==input[j][0]){
                         sur[m]=0;
                         break;
                     }
                }
            }
        }
    }
    for(int j=0;j<nkey-1;j++)
        cout<<ans[j]<<" ";
    cout<<ans[nkey-1];
    return 0;
}
