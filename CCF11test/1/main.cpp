#include <iostream>
int main(void)
{
    int ans=0,money=0;
    std::cin>>money;
    while(money>=50){
        ans+=7;
        money-=50;
    }
    while(money>=30){
        ans+=4;
        money-=30;
    }
    while(money>=10){
        ans++;
        money-=10;
    }
    std::cout << ans<< std::endl;
    return 0;
}
