#include <stdio.h>
#include <stdlib.h>
#include "program.h"
void draw(int a,int b,int c,int d,int e,int f)
{
    char guidao[8][7];
    extern struct train Atrain,Btrain,Ctrain;
    int m=0,n=0;
    for(m=0;m<8;m++)
    {
        for(n=0;n<7;n++)
            guidao[m][n]=' ';

    }
    guidao[0][4]='#';
    guidao[0][5]='#';
    guidao[0][6]='#';

    guidao[1][0]='#';
    guidao[1][1]='#';
    guidao[1][2]='#';
    guidao[1][3]='#';
    guidao[1][4]='@';
    guidao[1][6]='#';

    guidao[2][0]='#';
    guidao[2][4]='@';
    guidao[2][6]='#';

    guidao[3][0]='#';
    guidao[3][1]='@';
    guidao[3][2]='@';
    guidao[3][3]='@';
    guidao[3][4]='@';
    guidao[3][6]='#';

    guidao[4][1]='#';
    guidao[4][3]='#';
    guidao[4][4]='#';
    guidao[4][5]='#';
    guidao[4][6]='#';

    guidao[5][1]='#';
    guidao[5][3]='#';

    guidao[6][1]='#';
    guidao[6][3]='#';

    guidao[7][1]='#';
    guidao[7][2]='#';
    guidao[7][3]='#';

    guidao[7-b][a]='a';
    guidao[7-d][c]='b';
    guidao[7-f][e]='c';

    int o=0;
    int p=0;
    for(o=0;o<8;o++)
    {
        for(p=0;p<7;p++)
            printf("%c ",guidao[o][p]);
            printf("\n");

    }
    printf("输入CA,CB,CC代表A,B,C小车运行   输入PA,PB,PC分别代表A,B,C小车暂停\n输入PP代表程序结束运行------------------------输入结束输入回车\n");
    if(Atrain.X==Btrain.X&&Atrain.Y==Btrain.Y) 
       if(!(Atrain.X==4&&Atrain.Y==6))
	      if(!(Atrain.X==4&&Atrain.Y==4))  
             printf("AB小车相撞");
    if(Atrain.X==Ctrain.X&&Atrain.Y==Ctrain.Y) 
        if(!(Atrain.X==1&&Atrain.Y==4))
           if(!(Atrain.X==3&&Atrain.Y==6))
               printf("AC小车相撞");

}
