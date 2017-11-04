#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "program.h"
void PrintState()
{
	extern struct train Atrain,Btrain,Ctrain;
	static int T=1;
	int aba=0,abb=0,aca=0,acc=0;
	FILE *fPtr;
	static int M=0;
	extern int command[4];
	if(M==0)
     {fPtr=(FILE*)fopen("一起开小车.txt","w");
     ++M;}
     else
     fPtr=(FILE*)fopen("一起开小车.txt","a");

		fprintf(fPtr,"T=%d\n",T);
		printf("T=%d\n",T);
		++T;
		//首先输出A火车的状态信息 ，其中A火车运行方向不同火车的状态也不相同 ，A火车运行和静止状态也不同
      	if(command[0]!=0)        //A火车正在运行，速度不为零时
      	{
      		//1.A火车顺时针方向运行，入站探测点的位置决定了火车的运行方向，且速度不为零
      		if(Atrain.inpoint[0]==4&&Atrain.inpoint[1]==6)
      		{
                if(Atrain.X==0&&Atrain.Y>4&&Atrain.Y<=6)          //向北走
	          	{
                     fprintf(fPtr,"trainA:state=运行—非公共轨道\t");
                     printf("trainA:state=运行—非公共轨道\t");
                     fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
                     printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
           		}

           		if(Atrain.Y==6&&Atrain.X>0&&Atrain.X<=4)        //向东走
           		{
			         	fprintf(fPtr,"trainA:state=运行—非公共轨道\t");
			         	printf("trainA:state=运行—非公共轨道\t");
	                   	fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                   	printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          	}


	          	if(Atrain.Y==4&&Atrain.X>=0&&Atrain.X<4)         //向西走
	          	{
	          		if(Atrain.X==0||Atrain.X==3)
                    {
                   	    fprintf(fPtr,"trainA:state=运行—非公共轨道\t");
                   	    printf("trainA:state=运行—非公共轨道\t");
  		                fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
  		                printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
                    }
                    else
                    {
                        fprintf(fPtr,"trainA:state=运行—公共轨道\t");
                        printf("trainA:state=运行—公共轨道\t");
 		                fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
 		                printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     		        aca=1;
                    }

	          	}

	          	if(Atrain.X==4&&Atrain.Y>=4&&Atrain.Y<6)      //向南走
	          	{

			     		fprintf(fPtr,"trainA:state=运行—公共轨道\t");
			     		printf("trainA:state=运行—公共轨道\t");
	                    fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                    printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                    aba=1;
	          	}
      		}
     		//2.A火车逆时针方向运行，速度不为零

		     if(Atrain.inpoint[0]==4&&Atrain.inpoint[1]==4)
               {
       			if(Atrain.X==0&&Atrain.Y>=4&&Atrain.Y<6)       //向南走
	          	{
			          fprintf(fPtr,"trainA:state=运行—非公共轨道\t");
			          printf("trainA:state=运行—非公共轨道\t");
	                  fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                  printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
           		}


           		if(Atrain.Y==6&&Atrain.X>=0&&Atrain.X<4)     //向西走
           		{
				      fprintf(fPtr,"trainA:state=运行—非公共轨道\t");
				      printf("trainA:state=运行—非公共轨道\t");
	                  fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                  printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          	}
	          	if(Atrain.Y==4&&Atrain.X>0&&Atrain.X<=4)      //向东走
	          	{
	          		if(Atrain.X==1||Atrain.X==4)
	     		     {
				     	 fprintf(fPtr,"trainA:state=运行—非公共轨道\t");
				     	 printf("trainA:state=运行—非公共轨道\t");
	     	     	     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     	     	     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     		     }
	     		     else
	     		     {
     		     		 fprintf(fPtr,"trainA:state=运行—公共轨道\t");
     		     		 printf("trainA:state=运行—公共轨道\t");
	     	     	     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     	     	     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     	     	     aca=1;
     		     	}
	          	}
	          	if(Atrain.X==4&&Atrain.Y>4&&Atrain.Y<=6)       //向北走
	          	{
			     		fprintf(fPtr,"trainA:state=运行—公共轨道\t");
			     		printf("trainA:state=运行—公共轨道\t");
               	        fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
               	        printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
               	        aba=1;
	          	}
       		}
      	}
      	else                                //火车暂停，速度为零
 	     {
 	     	//1.A火车顺时针方向运行，入站探测点的位置决定了火车的运行方向，且速度为零

      		if(Atrain.inpoint[0]==4&&Atrain.inpoint[1]==6)
      		{
     	        if(Atrain.X==0&&Atrain.Y>4&&Atrain.Y<=6)
	          	{
                		fprintf(fPtr,"trainA:state=暂停—非公共轨道\t");
                		printf("trainA:state=暂停—非公共轨道\t");
	                	fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                	printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
           		}
           		if(Atrain.Y==6&&Atrain.X>0&&Atrain.X<=4)
           		{
			         fprintf(fPtr,"trainA:state=暂停—非公共轨道\t");
			         printf("trainA:state=暂停—非公共轨道\t");
           		     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
           		     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
			      }
	          	if(Atrain.Y==4&&Atrain.X>=0&&Atrain.X<4)
	          	{
	          		if(Atrain.X==0||Atrain.X==3)
	          		{
		          		fprintf(fPtr,"trainA:state=暂停—非公共轨道\t");
		          		printf("trainA:state=暂停—非公共轨道\t");
                        fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
                        printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
		          	}
		          	else
	     		     {
		     			fprintf(fPtr,"trainA:state=暂停—公共轨道\t");
		     			printf("trainA:state=暂停—公共轨道\t");
	     	     	    fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     	     	    printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     	     	     aca=1;
	     		     }
	          	}
	          	if(Atrain.X==4&&Atrain.Y>=4&&Atrain.Y<6)
	          	{
	          		 fprintf(fPtr,"trainA:state=暂停—公共轨道\t");
	          		 printf("trainA:state=暂停—公共轨道\t");
	          		 fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          		 printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          		 aba=1;
	          	}
      		}
     		//2.A火车逆时针方向运行，速度为零
		     if((Atrain.inpoint[0]==4)&&(Atrain.inpoint[1]==4))
               {
       			if(Atrain.X==0&&Atrain.Y>=4&&Atrain.Y<6)
	          	{
                		fprintf(fPtr,"trainA:state=暂停—非公共轨道\t");
                		printf("trainA:state=暂停—非公共轨道\t");
	                	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
           		}
           		if(Atrain.Y==6&&Atrain.X>=0&&Atrain.X<4)
           		{
           			fprintf(fPtr,"trainA:state=暂停—非公共轨道\t");
           			printf("trainA:state=暂停—非公共轨道\t");
	           		fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	           		printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          	}
	          	if(Atrain.Y==4&&Atrain.X>0&&Atrain.X<=4)
	          	{
	          		if(Atrain.X==2||Atrain.X==3)
	          		{
	    		         fprintf(fPtr,"trainA:state=暂停—公共轨道\t");
	    		         printf("trainA:state=暂停—公共轨道\t");
	           		     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	           		     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	           		     aca=1;
	          		}
	          		if(Atrain.X==1||Atrain.X==4)
	          		{
		          		fprintf(fPtr,"trainA:state=暂停—等待公共轨道\t");
		          		printf("trainA:state=暂停—等待公共轨道\t");
	           		     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	           		     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
		          	}
	          	}
	          	if(Atrain.X==4&&Atrain.Y>4&&Atrain.Y<=6)
	          	{
	          		 fprintf(fPtr,"trainA:state=暂停—公共轨道\t");
	          		 printf("trainA:state=暂停—公共轨道\t");
	          		 fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          		 printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          		 aba=1;
	          	}
       		}
          }
          //然后输出B火车的状态信息 ，其中B火车运行方向不同火车的状态也不相同 ，B火车运行和静止状态也不同
      	if(command[1]!=0)        //B火车正在运行，速度不为零时
      	{
      		//1.B火车顺时针方向运行，入站探测点的位置决定了火车的运行方向，且速度不为零
      	    if(Btrain.inpoint[0]==4&&Btrain.inpoint[1]==4)
      		{
                if(Btrain.X==4)
	          	{
	          		    if(Btrain.Y==6||Btrain.Y==5)
                		{
		          	        fprintf(fPtr,"trainB:state=运行—公共轨道\t");
		          	        printf("trainB:state=运行—公共轨道\t");
	                     	fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                     	printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                     	abb=1;
                		}
                		if(Btrain.Y==7||Btrain.Y==4)
                		{
                	        fprintf(fPtr,"trainB:state=运行—非公共轨道\t");
                	        printf("trainB:state=运行—非公共轨道\t");
	                     	fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                     	printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                         }
           		}
           		if(Btrain.Y==7&&Btrain.X>4&&Btrain.X<=6)
           		{
           			fprintf(fPtr,"trainB:state=运行—非公共轨道\t");
           			printf("trainB:state=运行—非公共轨道\t");
	           		fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	           		printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
	          	if(Btrain.Y==3&&Btrain.X>=4&&Btrain.X<6)
	          	{
	     		     fprintf(fPtr,"trainB:state=运行—非公共轨道\t");
	     		     printf("trainB:state=运行—非公共轨道\t");
	     		     fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	     		     printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
	          	if(Btrain.X==6&&Btrain.Y>=3&&Btrain.Y<7)
	          	{
	          		 fprintf(fPtr,"trainB:state=运行—非公共轨道\t");
	          		 printf("trainB:state=运行—非公共轨道\t");
	          		 fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          		 printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
      		}
      		//2.B火车逆时针方向运行，速度不为零
		     if(Btrain.inpoint[0]==4&&Btrain.inpoint[1]==6)
               {
         		if(Btrain.X==4)
	          	{
	          		if(Btrain.Y==5||Btrain.Y==4)
                		{
					        fprintf(fPtr,"trainB:state=运行—公共轨道\t");
					        printf("trainB:state=运行—公共轨道\t");
	                    	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	abb=1;
                		}
                		if(Btrain.Y==3||Btrain.Y==6)
                		{
		                	fprintf(fPtr,"trainB:state=运行—非公共轨道\t");
		                	printf("trainB:state=运行—非公共轨道\t");
	                    	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                		}
           		}
           		if(Btrain.Y==7&&Btrain.X>=4&&Btrain.X<6)
           		{
           			fprintf(fPtr,"trainB:state=运行—非公共轨道\t");
           			printf("trainB:state=运行—非公共轨道\t");
	           		fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	           		printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}


	          	if(Btrain.Y==3&&Btrain.X>4&&Btrain.X<=6)
	          	{
	     		     fprintf(fPtr,"trainB:state=运行—非公共轨道\t");
	     		     printf("trainB:state=运行—非公共轨道\t");
	     		     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	     		     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}

	          	if(Btrain.X==6&&Btrain.Y>3&&Btrain.Y<=7)
	          	{
	          		 fprintf(fPtr,"trainB:state=运行—非公共轨道\t");
	          		 printf("trainB:state=运行—非公共轨道\t");
	          		 fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          		 printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
       		}
      	}
      	else                                //火车暂停，速度为零
 	     {
 	     	//1.B火车顺时针方向运行，入站探测点的位置决定了火车的运行方向，且速度为零
      		if(Btrain.inpoint[0]==4&&Btrain.inpoint[1]==4)
      		{
                 if(Btrain.X==4)
	          	{
	          		    if(Btrain.Y==7)
                		{
					         fprintf(fPtr,"trainB:state=暂停—非公共轨道\t");
					         printf("trainB:state=暂停—非公共轨道\t");
	                	     fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                	     printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                		}
                		if(Btrain.Y==5||Btrain.Y==6)
                		{
		                	fprintf(fPtr,"trainB:state=暂停—公共轨道\t");
		                	printf("trainB:state=暂停—公共轨道\t");
                            fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                            printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                            abb=1;
		                }
		                if(Btrain.Y==4)
		                {
              				fprintf(fPtr,"trainB:state=暂停—等待公共轨道\t");
              				printf("trainB:state=暂停—等待公共轨道\t");
	                	     fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                	     printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                		}

           		}
           		if(Btrain.Y==7&&Btrain.X>4&&Btrain.X<=6)
           		{
				     fprintf(fPtr,"trainB:state=暂停—非公共轨道\t");
				     printf("trainB:state=暂停—非公共轨道\t");
	                	fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                	printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);

	          	}
	          	if(Btrain.Y==3&&Btrain.X>=4&&Btrain.X<6)
	          	{
	     		     fprintf(fPtr,"trainB:state=暂停—非公共轨道\t");
	     		     printf("trainB:state=暂停—非公共轨道\t");
	     		     fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	     		     printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}

	          	if(Btrain.X==6&&Btrain.Y>=3&&Btrain.Y<7)
	          	{
	          		 fprintf(fPtr,"trainB:state=暂停—非公共轨道\t");
	          		 printf("trainB:state=暂停—非公共轨道\t");
	          		 fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          		 printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
      		}
      		//2.B火车逆时针方向运行，速度为零
		     if(Btrain.inpoint[0]==4&&Btrain.inpoint[1]==6)
               {
       			if(Btrain.X==4)
	          	{
	          	     if(Btrain.Y==3)
                		{
					     fprintf(fPtr,"trainB:state=暂停—非公共轨道\t");
					     printf("trainB:state=暂停—非公共轨道\t");
	                    	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                		}
                		if(Btrain.Y==5||Btrain.Y==4)
                		{
		                	fprintf(fPtr,"trainB:state=暂停—公共轨道\t");
		                	printf("trainB:state=暂停—公共轨道\t");
	                    	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	abb=1;
		                }
		                if(Btrain.Y==6)
		                {
                			fprintf(fPtr,"trainB:state=暂停—等待公共轨道\t");
                			printf("trainB:state=暂停—等待公共轨道\t");
	                    	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                		}
           		}
           		if(Btrain.Y==7&&Btrain.X>=4&&Btrain.X<6)
           		{
           			fprintf(fPtr,"trainB:state=暂停—非公共轨道\t");
           			printf("trainB:state=暂停—非公共轨道\t");
	           		fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	           		printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
	          	if(Btrain.Y==3&&Btrain.X>4&&Btrain.X<=6)
	          	{
	          		fprintf(fPtr,"trainB:state=暂停—非公共轨道\t");
	          		printf("trainB:state=暂停—非公共轨道\t");
	           		fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	           		printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}

	          	if(Btrain.X==6&&Btrain.Y>3&&Btrain.Y<=7)
	          	{
	          		 fprintf(fPtr,"trainB:state=暂停—非公共轨道\t");
	          		 printf("trainB:state=暂停—非公共轨道\t");
	          		 fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          		 printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
       		}

          }
		//再输出C火车的状态信息 ，其中C火车运行方向不同火车的状态也不相同 ，C火车运行和静止状态也不同
      	if(command[2]!=0)        //C火车正在运行，速度不为零时
      	{
      		//1.C火车顺时针方向运行，入站探测点的位置决定了火车的运行方向，且速度不为零
      		if(Ctrain.inpoint[0]==1&&Ctrain.inpoint[1]==4)
      		{
     	          if(Ctrain.X==1&&Ctrain.Y>0&&Ctrain.Y<=4)
	          	{
                		fprintf(fPtr,"trainC:state=运行—非公共轨道\t");
                		printf("trainC:state=运行—非公共轨道\t");
	                	fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
           		}


           		if(Ctrain.Y==4&&Ctrain.X>1&&Ctrain.X<=3)
           		{
           			fprintf(fPtr,"trainC:state=运行—公共轨道\t");
           			printf("trainC:state=运行—公共轨道\t");
	           		fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		acc=1;
	          	}
	          	if(Ctrain.Y==0&&Ctrain.X>=1&&Ctrain.X<3)
	          	{
	     		     fprintf(fPtr,"trainC:state=运行—非公共轨道\t");
	     		     printf("trainC:state=运行—非公共轨道\t");
	     		     fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	     		     printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}

	          	if(Ctrain.X==3&&Ctrain.Y>=0&&Ctrain.Y<4)
	          	{
	          		 fprintf(fPtr,"trainC:state=运行—非公共轨道\t");
	          		 printf("trainC:state=运行—非公共轨道\t");
	          		 fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		 printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}
      		}

      		//2.C火车逆时针方向运行，速度不为零
		     if(Ctrain.inpoint[0]==3&&Ctrain.inpoint[1]==4)
               {
       			if(Ctrain.X==1&&Ctrain.Y>=0&&Ctrain.Y<4)
	          	{
                		fprintf(fPtr,"trainC:state=运行—非公共轨道\t");
                		printf("trainC:state=运行—非公共轨道\t");
	                	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
           		}


           		if(Ctrain.Y==4&&Ctrain.X>=1&&Ctrain.X<3)
           		{
           			fprintf(fPtr,"trainC:state=运行—公共轨道\t");
           			printf("trainC:state=运行—公共轨道\t");
	           		fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		acc=1;
	          	}


	          	if(Ctrain.Y==0&&Ctrain.X>1&&Ctrain.X<=3)
	          	{
	     		     fprintf(fPtr,"trainC:state=运行—非公共轨道\t");
	     		     printf("trainC:state=运行—非公共轨道\t");
	     		     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	     		     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}

	          	if(Ctrain.X==3&&Ctrain.Y>0&&Ctrain.Y<=4)
	          	{
	          		 fprintf(fPtr,"trainC:state=运行—非公共轨道\t");
	          		 printf("trainC:state=运行—非公共轨道\t");
	          		 fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		 printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}
       		}
      	}
      	else                                //火车暂停，速度为零
 	     {
 	     	//1.C火车顺时针方向运行，入站探测点的位置决定了火车的运行方向，且速度为零

      		if(Ctrain.inpoint[0]==1&&Ctrain.inpoint[1]==4)
      		{
     	         if(Ctrain.X==1&&Ctrain.Y>0&&Ctrain.Y<=4)
	          	{
	          		if(Ctrain.Y<4)
                		{
					          fprintf(fPtr,"trainC:state=暂停—非公共轨道\t");
					          printf("trainC:state=暂停—非公共轨道\t");
	                	      fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	      printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
                		}
                		if(Ctrain.Y==4)
                		{
		                	fprintf(fPtr,"trainC:state=暂停—等待公共轨道\t");
		                	printf("trainC:state=暂停—等待公共轨道\t");
	                	      fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	      printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
		                }
           		}


           		if(Ctrain.Y==4&&Ctrain.X>1&&Ctrain.X<=3)
           		{

					     fprintf(fPtr,"trainC:state=暂停—公共轨道\t");
					     printf("trainC:state=暂停—公共轨道\t");
	                	fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                		acc=1;

	          	}


	          	if(Ctrain.Y==0&&Ctrain.X>=1&&Ctrain.X<3)
	          	{
	     		     fprintf(fPtr,"trainC:state=暂停—非公共轨道\t");
	     		     printf("trainC:state=暂停—非公共轨道\t");
	     		     fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	     		     printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}

	          	if(Ctrain.X==3&&Ctrain.Y>=0&&Ctrain.Y<4)
	          	{
	          		 fprintf(fPtr,"trainC:state=暂停—非公共轨道\t");
	          		 printf("trainC:state=暂停—非公共轨道\t");
	          		 fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		 printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}


      		}
      		//2.C火车逆时针方向运行，速度为零
		     if(Ctrain.inpoint[0]==3&&Ctrain.inpoint[1]==4)
               {
       			if(Ctrain.X==1&&Ctrain.Y>=0&&Ctrain.Y<4)
	          	{
                		fprintf(fPtr,"trainC:state=暂停—非公共轨道\t");
                		printf("trainC:state=暂停—非公共轨道\t");
	                	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
           		}


           		if(Ctrain.Y==4&&Ctrain.X>=1&&Ctrain.X<3)
           		{
           			fprintf(fPtr,"trainC:state=暂停—公共轨道\t");
           			printf("trainC:state=暂停—公共轨道\t");
	           		fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		acc=1;
	          	}


	          	if(Ctrain.Y==0&&Ctrain.X>1&&Ctrain.X<=3)
	          	{
                          fprintf(fPtr,"trainC:state=暂停—非公共轨道\t");
                          printf("trainC:state=暂停—非公共轨道\t");
	           	      fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           	      printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}

	          	if(Ctrain.X==3&&Ctrain.Y>0&&Ctrain.Y<=4)
	          	{
	          		if(Ctrain.Y==4)
	          		 {
					     fprintf(fPtr,"trainC:state=暂停—等待公共轨道\t");
					     printf("trainC:state=暂停—等待公共轨道\t");
	          		     fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		     printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		 }
	          		 if(Ctrain.Y<4)
	          		 {
 		          		fprintf(fPtr,"trainC:state=暂停—非公共轨道\t");
 		          		printf("trainC:state=暂停—非公共轨道\t");
	          		     fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		     printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
 		          	}
	          	}


       		}

          }

          //三辆小火车的状态信息已经全部输出完毕，现在我们来输出公共轨道的占用情况
          //首先考虑AB公共轨道

		 if(abb==1||aba==1)
		 {
 			fprintf(fPtr,"railwayA-B:\tState=OCCUPIED\t");
 			printf("railwayA-B:\tState=OCCUPIED\t");
 			if(aba)
 			{
			     fprintf(fPtr,"train=trainA\n");
 	      		printf("train=trainA\n");
            }
 			if(abb)
 			{
			     fprintf(fPtr,"train=trainB\n");
                 printf("train=trainB\n");
            }
		 }
 		 else
 		 {
 		     fprintf(fPtr,"railwayA-B:\tState=IDLE\ttrain=/\n");
 	     	 printf("railwayA-B:\tState=IDLE\ttrain=/\n");
         }


          //现在考虑AC公共轨道的占用情况
		if(aca==1||acc==1)
		{
			fprintf(fPtr,"railwayA-C:\tState=OCCUPIED\t");
			printf("railwayA-C:\tState=OCCUPIED\t");
			if(aca)
			{
			     fprintf(fPtr,"train=trainA\n");
                 printf("train=trainA\n");
            }
			if(acc)
			{
                 fprintf(fPtr,"train=trainC\n");
		      	 printf("train=trainC\n");
            }
         }
	     else
	     {
		     fprintf(fPtr,"railwayA-C:\tState=IDLE\ttrain=/\n");
             printf("railwayA-C:\tState=IDLE\ttrain=/\n");
		 }
		 printf("\n");
         draw(Atrain.X,Atrain.Y,Btrain.X,Btrain.Y,Ctrain.X,Ctrain.Y);
          //关闭文件
		fclose(fPtr);		
}