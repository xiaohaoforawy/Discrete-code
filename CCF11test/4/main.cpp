#include <iostream>

using namespace std;

int main()
{
    int n=0,m=0;
    cin>>n;
    cin>>m;
    int timu[m][2];
    for(int i=0;i<m;i++)
    {
        cin>>timu[i][0];
        cin>>timu[i][1];
    }


    int xiang[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            xiang[i][j]=0;
    }
    for(int i=0;i<n;i++)
        xiang[i][i]=1;
    for(int i=0;i<m;i++)
    {
        xiang[timu[i][0]-1][timu[i][1]-1]=1;
        //xiang[timu[i][1]-1][timu[i][0]-1]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
             if(xiang[i][j]==1)
             {
                 for(int m=j;m<n;m++)
                 {
                     if(xiang[j][m]==1)
                        xiang[i][m]=1;
                 }
             }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(xiang[i][j]==1)
                xiang[j][i]=1;
        }
    }
    int ans=n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(xiang[i][j]==0)
            ans--;
    }
    cout<<ans;
    return 0;
}
