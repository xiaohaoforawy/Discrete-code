#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "program.h"
void init()
{
   extern int command[4];
   extern struct train Atrain,Btrain,Ctrain;
   int DATA[10],data,data2,data3,stationnum;
   char ch;
   int i,j;
   FILE * fp;
   fp=(FILE*)fopen("初始化.txt","r");
   for(i=1;i<10;i++)
   {
        fscanf(fp,"%c",&ch);
        while(ch!='=')
        {
           fscanf(fp,"%c",&ch);
        }
	   	fscanf(fp,"%d",&DATA[i]);
   }
   Atrain.speed=DATA[1];
   Atrain.X=DATA[2];
   Atrain.Y=DATA[3];
   Atrain.starttime=DATA[4];
   Atrain.inpoint[0]=DATA[5];
   Atrain.inpoint[1]=DATA[6];
   Atrain.outpoint[0]=DATA[7];
   Atrain.outpoint[1]=DATA[8];
   Atrain.stationnum=DATA[9];
   for(i=0;i<DATA[9];i++)
   {
        for(j=0;j<3;j++)
		{
		   fscanf(fp,"%c",&ch);
           while(ch!='=')
           {
		      fscanf(fp,"%c",&ch);
           }
	       fscanf(fp,"%d",&Atrain.stationinf [i][j]);
        }
   }
   for(i=1;i<10;i++)
   {
        fscanf(fp,"%c",&ch);
        while(ch!='=')
        {
           fscanf(fp,"%c",&ch);
        }
	   	fscanf(fp,"%d",&DATA[i]);
   }
   Btrain.speed=DATA[1];
   Btrain.X=DATA[2];
   Btrain.Y=DATA[3];
   Btrain.starttime=DATA[4];
   Btrain.inpoint[0]=DATA[5];
   Btrain.inpoint[1]=DATA[6];
   Btrain.outpoint[0]=DATA[7];
   Btrain.outpoint[1]=DATA[8];
   Btrain.stationnum=DATA[9];
   for(i=0;i<DATA[9];i++)
   {
        for(j=0;j<3;j++)
		{
            fscanf(fp,"%c",&ch);
           while(ch!='=')
           {
               fscanf(fp,"%c",&ch);
           }
	       fscanf(fp,"%d",&Btrain.stationinf [i][j]);
        }
   }
  for(i=1;i<10;i++)
   {
        fscanf(fp,"%c",&ch);
        while(ch!='=')
        {
           fscanf(fp,"%c",&ch);
        }
	   	fscanf(fp,"%d",&DATA[i]);
   }
   Ctrain.speed=DATA[1];
   Ctrain.X=DATA[2];
   Ctrain.Y=DATA[3];
   Ctrain.starttime=DATA[4];
   Ctrain.inpoint[0]=DATA[5];
   Ctrain.inpoint[1]=DATA[6];
   Ctrain.outpoint[0]=DATA[7];
   Ctrain.outpoint[1]=DATA[8];
   Ctrain.stationnum=DATA[9];
   for(i=0;i<DATA[9];i++)
   {
        for(j=0;j<3;j++)
		{
            fscanf(fp,"%c",&ch);
           while(ch!='=')
           {
               fscanf(fp,"%c",&ch);
           }
	       fscanf(fp,"%d",&Ctrain.stationinf [i][j]);
        }
   }
   if(fclose(fp)!=0)
	    printf("File could not be closed.\n");


   	printf("Atrain.speed=%d\tAtrain.X=%d\tAtrain.Y=%d\tAtrain.starttime=%d\t\nAtrain.stationnum=%d",Atrain.speed,Atrain.X,Atrain.Y,Atrain.starttime);
	printf("Atrain.inpoint.X=%d\tAtrain.inpoint.Y=%d\t\n",Atrain.inpoint[0],Atrain.inpoint[1]);
	printf("Atrain.outpoint.X=%dAtrain.outpoint.Y=%d\t\n",Atrain.outpoint[0],Atrain.outpoint[1]);
	printf("Atrain.stationnum=%d\t\n",Atrain.stationnum);
	for(i=0;i<Atrain.stationnum;i++)
   {
     printf("Atrain.stationinf [i].X=%d\tAtrain.stationinf [i].Y=%d\t\nAtrain.stationinf [i].TIME=%d\t\n",Atrain.stationinf[i][0],Atrain.stationinf[i][1],Atrain.stationinf[i][2]);
   }


	printf("Btrain.speed=%d\tBtrain.X=%d\tAtrain.Y=%d\tBtrain.starttime=%d\t\n",Btrain.speed,Btrain.X,Btrain.Y,Btrain.starttime);
	printf("Btrain.inpoint.X=%d\tBtrain.inpoint.Y=%d\t\n",Btrain.inpoint[0],Btrain.inpoint[1]);
	printf("Btrain.outpoint.X=%d\tBtrain.outpoint.Y=%d\t\n",Btrain.outpoint[0],Btrain.outpoint[1]);
	printf("Btrain.stationnum=%d\t\n",Btrain.stationnum);
	for(i=0;i<Btrain.stationnum;i++)
   {
     printf("Btrain.stationinf [i].X=%d\tBtrain.stationinf [i].Y=%d\t\nBtrain.stationinf [i].TIME=%d\t\n",Btrain.stationinf[i][0],Btrain.stationinf[i][1],Btrain.stationinf[i][2]);
   }

	printf("Ctrain.speed=%d\tCtrain.X=%d\tCtrain.Y=%d\tCtrain.starttime=%d\t\n",Ctrain.speed,Ctrain.X,Ctrain.Y,Ctrain.starttime);
    printf("Ctrain.inpoint.X=%d\tCtrain.inpoint.Y=%d\t\n",Ctrain.inpoint[0],Ctrain.inpoint[1]);
	printf("Ctrain.outpoint.X=%dCtrain.outpoint.Y=%d\t\n",Ctrain.outpoint[0],Ctrain.outpoint[1]);
	printf("Ctrain.stationnum=%d\t\n",Ctrain.stationnum);
	for(i=0;i<Ctrain.stationnum;i++)
   {
     printf("Ctrain.stationinf [i].X=%d\tCtrain.stationinf [i].Y=%d\t\nCtrain.stationinf [i].TIME=%d\t\n",Ctrain.stationinf[i][0],Ctrain.stationinf[i][1],Ctrain.stationinf[i][2]);
   }

	printf("是否需要修改默认数据？\n1---需要\n2----不需要\n");
    scanf("%d",&i);
    if(i==1)
        {
		   printf("选择修改的数据\n1---A火车\n2---B火车\n3---C火车\n4---修改结束\n");
		   printf("ps:不修改输入-1\n");
	       scanf("%d",&i);
	       while(i!=4)
	       {
       		  if(i==1)
       		     {
					printf("1.speed:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Atrain.speed=data;
                    printf("2.X:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Atrain.X=data;
    		        printf("3.Y:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Atrain.Y=data;
                    printf("4.starttime:");
                   	scanf("%d",&data);
                    if(data!=-1)
       		           Atrain.starttime=data;
                    printf("5.inpoint X Y:");
					scanf("%d %d",&data,&data2);
       		        if(data!=-1)
       		           {Atrain.inpoint[0]=data;
       		            Atrain.inpoint[1]=data2;
       		           }
                    printf("6.outpoint X Y:");
					scanf("%d %d",&data,&data2);
       		        if(data!=-1)
       		           {Atrain.outpoint[0]=data;
       		            Atrain.outpoint[1]=data2;
       		           }
                    printf("7.stationnum:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Atrain.stationnum=data;
					for(i=0;i<Atrain.stationnum;i++)
                    {
                   	    printf("8.stationinf [%d] X Y TIME:",i);
					    scanf("%d %d %d",&data,&data2,&data3);
                        if(data!=-1)
                        {
			                Atrain.stationinf [i][0]=data;
       		                Atrain.stationinf [i][1]=data2;
  		                    Atrain.stationinf [i][2]=data3;
       		             }
                    }

				 }
              if(i==2)
       		     {
					printf("1.speed:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Btrain.speed=data;
                    printf("2.X:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Btrain.X=data;
    		        printf("3.Y:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Btrain.Y=data;
                    printf("4.starttime:");
                   	scanf("%d",&data);
                    if(data!=-1)
       		           Btrain.starttime=data;
    		        printf("5.outpoint X Y:");
					scanf("%d %d",&data,&data2);
       		        if(data!=-1)
       		           {Btrain.inpoint[0]=data;
       		            Btrain.inpoint[1]=data2;
       		           }
                    printf("6.outpoint X Y:");
					scanf("%d %d",&data,&data2);
       		        if(data!=-1)
       		           {Btrain.outpoint[0]=data;
       		            Btrain.outpoint[1]=data2;
       		           }
                    printf("7.stationnum:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Btrain.stationnum=data;
    		        for(i=0;i<Btrain.stationnum;i++)
                    {
                   	    printf("8.stationinf [%d] X Y TIME:",i);
					    scanf("%d %d %d",&data,&data2,&data3);
                        if(data!=-1)
                        {
			                Btrain.stationinf [i][0]=data;
       		                Btrain.stationinf [i][1]=data2;
  		                    Btrain.stationinf [i][2]=data3;
       		             }
                    }
				 }
			  if(i==3)
       		     {
					printf("1.speed:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Ctrain.speed=data;
                    printf("2.X:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Ctrain.X=data;
    		        printf("3.Y:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Ctrain.Y=data;
                    printf("4.starttime:");
                   	scanf("%d",&data);
                    if(data!=-1)
       		           Ctrain.starttime=data;
                    printf("5.inpoint X Y:");
					scanf("%d %d",&data,&data2);
       		        if(data!=-1)
       		           {Ctrain.inpoint[0]=data;
       		            Ctrain.inpoint[1]=data2;
       		           }
                    printf("6.outpoint X Y:");
					scanf("%d %d",&data,&data2);
       		        if(data!=-1)
       		           {Ctrain.outpoint[0]=data;
       		            Ctrain.outpoint[1]=data2;
       		           }
                    printf("7.stationnum:");
					scanf("%d",&data);
       		        if(data!=-1)
       		           Ctrain.stationnum=data;
    		        for(i=0;i<Ctrain.stationnum;i++)
                    {
                   	    printf("8.stationinf [%d] X Y TIME:",i);
					    scanf("%d %d %d",&data,&data2,&data3);
                        if(data!=-1)
                        {
			                Ctrain.stationinf [i][0]=data;
       		                Ctrain.stationinf [i][1]=data2;
  		                    Ctrain.stationinf [i][2]=data3;
       		             }
                    }
				 }
             printf("选择修改的数据\n1--A火车\n2--B火车\n3--C火车\n4--修改结束\n");
			 scanf("%d",&i);
       	   }
		}
}