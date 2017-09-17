#include <iostream>

using namespace std;
int main()
{
    int n=0,m=0;
    cin>>n;
    cin>>m;
    long long caozuo[n];
    for(int i=0;i<n;i++)
    {
        cin>>caozuo[i];
    }
    int shuru[m][4];
    for(int i=0;i<m;i++)
    {
        cin>>shuru[i][0];
        if(shuru[i][0]==2)
        {
            for(int o=1;o<3;o++)
                cin>>shuru[i][o];
            shuru[m][3]=0;
        }
        else
        {
            for(int o=1;o<4;o++)
                cin>>shuru[i][o];

        }
    }
    for(int i=0;i<m;i++)
    {
        if(shuru[i][0]==1)
        {
            for(int j=shuru[i][1]-1;j<shuru[i][2];j++)
            {
                if(caozuo[j]%shuru[i][3]==0)
                    caozuo[j]/=shuru[i][3];
            }
        }
        else
        {
            long long qwe=0;
            for(int j=shuru[i][1]-1;j<shuru[i][2];j++)
            {
                qwe+=caozuo[j];
            }
            cout<<qwe<<endl;
        }
    }
    return 0;
}
