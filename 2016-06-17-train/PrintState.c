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
     {fPtr=(FILE*)fopen("һ��С��.txt","w");
     ++M;}
     else
     fPtr=(FILE*)fopen("һ��С��.txt","a");

		fprintf(fPtr,"T=%d\n",T);
		printf("T=%d\n",T);
		++T;
		//�������A�𳵵�״̬��Ϣ ������A�����з���ͬ�𳵵�״̬Ҳ����ͬ ��A�����к;�ֹ״̬Ҳ��ͬ
      	if(command[0]!=0)        //A���������У��ٶȲ�Ϊ��ʱ
      	{
      		//1.A��˳ʱ�뷽�����У���վ̽����λ�þ����˻𳵵����з������ٶȲ�Ϊ��
      		if(Atrain.inpoint[0]==4&&Atrain.inpoint[1]==6)
      		{
                if(Atrain.X==0&&Atrain.Y>4&&Atrain.Y<=6)          //����
	          	{
                     fprintf(fPtr,"trainA:state=���С��ǹ������\t");
                     printf("trainA:state=���С��ǹ������\t");
                     fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
                     printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
           		}

           		if(Atrain.Y==6&&Atrain.X>0&&Atrain.X<=4)        //����
           		{
			         	fprintf(fPtr,"trainA:state=���С��ǹ������\t");
			         	printf("trainA:state=���С��ǹ������\t");
	                   	fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                   	printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          	}


	          	if(Atrain.Y==4&&Atrain.X>=0&&Atrain.X<4)         //������
	          	{
	          		if(Atrain.X==0||Atrain.X==3)
                    {
                   	    fprintf(fPtr,"trainA:state=���С��ǹ������\t");
                   	    printf("trainA:state=���С��ǹ������\t");
  		                fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
  		                printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
                    }
                    else
                    {
                        fprintf(fPtr,"trainA:state=���С��������\t");
                        printf("trainA:state=���С��������\t");
 		                fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
 		                printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     		        aca=1;
                    }

	          	}

	          	if(Atrain.X==4&&Atrain.Y>=4&&Atrain.Y<6)      //������
	          	{

			     		fprintf(fPtr,"trainA:state=���С��������\t");
			     		printf("trainA:state=���С��������\t");
	                    fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                    printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                    aba=1;
	          	}
      		}
     		//2.A����ʱ�뷽�����У��ٶȲ�Ϊ��

		     if(Atrain.inpoint[0]==4&&Atrain.inpoint[1]==4)
               {
       			if(Atrain.X==0&&Atrain.Y>=4&&Atrain.Y<6)       //������
	          	{
			          fprintf(fPtr,"trainA:state=���С��ǹ������\t");
			          printf("trainA:state=���С��ǹ������\t");
	                  fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                  printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
           		}


           		if(Atrain.Y==6&&Atrain.X>=0&&Atrain.X<4)     //������
           		{
				      fprintf(fPtr,"trainA:state=���С��ǹ������\t");
				      printf("trainA:state=���С��ǹ������\t");
	                  fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                  printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          	}
	          	if(Atrain.Y==4&&Atrain.X>0&&Atrain.X<=4)      //����
	          	{
	          		if(Atrain.X==1||Atrain.X==4)
	     		     {
				     	 fprintf(fPtr,"trainA:state=���С��ǹ������\t");
				     	 printf("trainA:state=���С��ǹ������\t");
	     	     	     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     	     	     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     		     }
	     		     else
	     		     {
     		     		 fprintf(fPtr,"trainA:state=���С��������\t");
     		     		 printf("trainA:state=���С��������\t");
	     	     	     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     	     	     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     	     	     aca=1;
     		     	}
	          	}
	          	if(Atrain.X==4&&Atrain.Y>4&&Atrain.Y<=6)       //����
	          	{
			     		fprintf(fPtr,"trainA:state=���С��������\t");
			     		printf("trainA:state=���С��������\t");
               	        fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
               	        printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
               	        aba=1;
	          	}
       		}
      	}
      	else                                //����ͣ���ٶ�Ϊ��
 	     {
 	     	//1.A��˳ʱ�뷽�����У���վ̽����λ�þ����˻𳵵����з������ٶ�Ϊ��

      		if(Atrain.inpoint[0]==4&&Atrain.inpoint[1]==6)
      		{
     	        if(Atrain.X==0&&Atrain.Y>4&&Atrain.Y<=6)
	          	{
                		fprintf(fPtr,"trainA:state=��ͣ���ǹ������\t");
                		printf("trainA:state=��ͣ���ǹ������\t");
	                	fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                	printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
           		}
           		if(Atrain.Y==6&&Atrain.X>0&&Atrain.X<=4)
           		{
			         fprintf(fPtr,"trainA:state=��ͣ���ǹ������\t");
			         printf("trainA:state=��ͣ���ǹ������\t");
           		     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
           		     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
			      }
	          	if(Atrain.Y==4&&Atrain.X>=0&&Atrain.X<4)
	          	{
	          		if(Atrain.X==0||Atrain.X==3)
	          		{
		          		fprintf(fPtr,"trainA:state=��ͣ���ǹ������\t");
		          		printf("trainA:state=��ͣ���ǹ������\t");
                        fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
                        printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
		          	}
		          	else
	     		     {
		     			fprintf(fPtr,"trainA:state=��ͣ���������\t");
		     			printf("trainA:state=��ͣ���������\t");
	     	     	    fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     	     	    printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	     	     	     aca=1;
	     		     }
	          	}
	          	if(Atrain.X==4&&Atrain.Y>=4&&Atrain.Y<6)
	          	{
	          		 fprintf(fPtr,"trainA:state=��ͣ���������\t");
	          		 printf("trainA:state=��ͣ���������\t");
	          		 fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          		 printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          		 aba=1;
	          	}
      		}
     		//2.A����ʱ�뷽�����У��ٶ�Ϊ��
		     if((Atrain.inpoint[0]==4)&&(Atrain.inpoint[1]==4))
               {
       			if(Atrain.X==0&&Atrain.Y>=4&&Atrain.Y<6)
	          	{
                		fprintf(fPtr,"trainA:state=��ͣ���ǹ������\t");
                		printf("trainA:state=��ͣ���ǹ������\t");
	                	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	                	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
           		}
           		if(Atrain.Y==6&&Atrain.X>=0&&Atrain.X<4)
           		{
           			fprintf(fPtr,"trainA:state=��ͣ���ǹ������\t");
           			printf("trainA:state=��ͣ���ǹ������\t");
	           		fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	           		printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          	}
	          	if(Atrain.Y==4&&Atrain.X>0&&Atrain.X<=4)
	          	{
	          		if(Atrain.X==2||Atrain.X==3)
	          		{
	    		         fprintf(fPtr,"trainA:state=��ͣ���������\t");
	    		         printf("trainA:state=��ͣ���������\t");
	           		     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	           		     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	           		     aca=1;
	          		}
	          		if(Atrain.X==1||Atrain.X==4)
	          		{
		          		fprintf(fPtr,"trainA:state=��ͣ���ȴ��������\t");
		          		printf("trainA:state=��ͣ���ȴ��������\t");
	           		     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	           		     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
		          	}
	          	}
	          	if(Atrain.X==4&&Atrain.Y>4&&Atrain.Y<=6)
	          	{
	          		 fprintf(fPtr,"trainA:state=��ͣ���������\t");
	          		 printf("trainA:state=��ͣ���������\t");
	          		 fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          		 printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Atrain.X,Atrain.Y);
	          		 aba=1;
	          	}
       		}
          }
          //Ȼ�����B�𳵵�״̬��Ϣ ������B�����з���ͬ�𳵵�״̬Ҳ����ͬ ��B�����к;�ֹ״̬Ҳ��ͬ
      	if(command[1]!=0)        //B���������У��ٶȲ�Ϊ��ʱ
      	{
      		//1.B��˳ʱ�뷽�����У���վ̽����λ�þ����˻𳵵����з������ٶȲ�Ϊ��
      	    if(Btrain.inpoint[0]==4&&Btrain.inpoint[1]==4)
      		{
                if(Btrain.X==4)
	          	{
	          		    if(Btrain.Y==6||Btrain.Y==5)
                		{
		          	        fprintf(fPtr,"trainB:state=���С��������\t");
		          	        printf("trainB:state=���С��������\t");
	                     	fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                     	printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                     	abb=1;
                		}
                		if(Btrain.Y==7||Btrain.Y==4)
                		{
                	        fprintf(fPtr,"trainB:state=���С��ǹ������\t");
                	        printf("trainB:state=���С��ǹ������\t");
	                     	fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                     	printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                         }
           		}
           		if(Btrain.Y==7&&Btrain.X>4&&Btrain.X<=6)
           		{
           			fprintf(fPtr,"trainB:state=���С��ǹ������\t");
           			printf("trainB:state=���С��ǹ������\t");
	           		fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	           		printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
	          	if(Btrain.Y==3&&Btrain.X>=4&&Btrain.X<6)
	          	{
	     		     fprintf(fPtr,"trainB:state=���С��ǹ������\t");
	     		     printf("trainB:state=���С��ǹ������\t");
	     		     fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	     		     printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
	          	if(Btrain.X==6&&Btrain.Y>=3&&Btrain.Y<7)
	          	{
	          		 fprintf(fPtr,"trainB:state=���С��ǹ������\t");
	          		 printf("trainB:state=���С��ǹ������\t");
	          		 fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          		 printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
      		}
      		//2.B����ʱ�뷽�����У��ٶȲ�Ϊ��
		     if(Btrain.inpoint[0]==4&&Btrain.inpoint[1]==6)
               {
         		if(Btrain.X==4)
	          	{
	          		if(Btrain.Y==5||Btrain.Y==4)
                		{
					        fprintf(fPtr,"trainB:state=���С��������\t");
					        printf("trainB:state=���С��������\t");
	                    	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	abb=1;
                		}
                		if(Btrain.Y==3||Btrain.Y==6)
                		{
		                	fprintf(fPtr,"trainB:state=���С��ǹ������\t");
		                	printf("trainB:state=���С��ǹ������\t");
	                    	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                		}
           		}
           		if(Btrain.Y==7&&Btrain.X>=4&&Btrain.X<6)
           		{
           			fprintf(fPtr,"trainB:state=���С��ǹ������\t");
           			printf("trainB:state=���С��ǹ������\t");
	           		fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	           		printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}


	          	if(Btrain.Y==3&&Btrain.X>4&&Btrain.X<=6)
	          	{
	     		     fprintf(fPtr,"trainB:state=���С��ǹ������\t");
	     		     printf("trainB:state=���С��ǹ������\t");
	     		     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	     		     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}

	          	if(Btrain.X==6&&Btrain.Y>3&&Btrain.Y<=7)
	          	{
	          		 fprintf(fPtr,"trainB:state=���С��ǹ������\t");
	          		 printf("trainB:state=���С��ǹ������\t");
	          		 fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          		 printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
       		}
      	}
      	else                                //����ͣ���ٶ�Ϊ��
 	     {
 	     	//1.B��˳ʱ�뷽�����У���վ̽����λ�þ����˻𳵵����з������ٶ�Ϊ��
      		if(Btrain.inpoint[0]==4&&Btrain.inpoint[1]==4)
      		{
                 if(Btrain.X==4)
	          	{
	          		    if(Btrain.Y==7)
                		{
					         fprintf(fPtr,"trainB:state=��ͣ���ǹ������\t");
					         printf("trainB:state=��ͣ���ǹ������\t");
	                	     fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                	     printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                		}
                		if(Btrain.Y==5||Btrain.Y==6)
                		{
		                	fprintf(fPtr,"trainB:state=��ͣ���������\t");
		                	printf("trainB:state=��ͣ���������\t");
                            fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                            printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                            abb=1;
		                }
		                if(Btrain.Y==4)
		                {
              				fprintf(fPtr,"trainB:state=��ͣ���ȴ��������\t");
              				printf("trainB:state=��ͣ���ȴ��������\t");
	                	     fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                	     printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                		}

           		}
           		if(Btrain.Y==7&&Btrain.X>4&&Btrain.X<=6)
           		{
				     fprintf(fPtr,"trainB:state=��ͣ���ǹ������\t");
				     printf("trainB:state=��ͣ���ǹ������\t");
	                	fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                	printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);

	          	}
	          	if(Btrain.Y==3&&Btrain.X>=4&&Btrain.X<6)
	          	{
	     		     fprintf(fPtr,"trainB:state=��ͣ���ǹ������\t");
	     		     printf("trainB:state=��ͣ���ǹ������\t");
	     		     fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	     		     printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}

	          	if(Btrain.X==6&&Btrain.Y>=3&&Btrain.Y<7)
	          	{
	          		 fprintf(fPtr,"trainB:state=��ͣ���ǹ������\t");
	          		 printf("trainB:state=��ͣ���ǹ������\t");
	          		 fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          		 printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
      		}
      		//2.B����ʱ�뷽�����У��ٶ�Ϊ��
		     if(Btrain.inpoint[0]==4&&Btrain.inpoint[1]==6)
               {
       			if(Btrain.X==4)
	          	{
	          	     if(Btrain.Y==3)
                		{
					     fprintf(fPtr,"trainB:state=��ͣ���ǹ������\t");
					     printf("trainB:state=��ͣ���ǹ������\t");
	                    	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                		}
                		if(Btrain.Y==5||Btrain.Y==4)
                		{
		                	fprintf(fPtr,"trainB:state=��ͣ���������\t");
		                	printf("trainB:state=��ͣ���������\t");
	                    	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	abb=1;
		                }
		                if(Btrain.Y==6)
		                {
                			fprintf(fPtr,"trainB:state=��ͣ���ȴ��������\t");
                			printf("trainB:state=��ͣ���ȴ��������\t");
	                    	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	                    	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
                		}
           		}
           		if(Btrain.Y==7&&Btrain.X>=4&&Btrain.X<6)
           		{
           			fprintf(fPtr,"trainB:state=��ͣ���ǹ������\t");
           			printf("trainB:state=��ͣ���ǹ������\t");
	           		fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	           		printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
	          	if(Btrain.Y==3&&Btrain.X>4&&Btrain.X<=6)
	          	{
	          		fprintf(fPtr,"trainB:state=��ͣ���ǹ������\t");
	          		printf("trainB:state=��ͣ���ǹ������\t");
	           		fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	           		printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}

	          	if(Btrain.X==6&&Btrain.Y>3&&Btrain.Y<=7)
	          	{
	          		 fprintf(fPtr,"trainB:state=��ͣ���ǹ������\t");
	          		 printf("trainB:state=��ͣ���ǹ������\t");
	          		 fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          		 printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Btrain.X,Btrain.Y);
	          	}
       		}

          }
		//�����C�𳵵�״̬��Ϣ ������C�����з���ͬ�𳵵�״̬Ҳ����ͬ ��C�����к;�ֹ״̬Ҳ��ͬ
      	if(command[2]!=0)        //C���������У��ٶȲ�Ϊ��ʱ
      	{
      		//1.C��˳ʱ�뷽�����У���վ̽����λ�þ����˻𳵵����з������ٶȲ�Ϊ��
      		if(Ctrain.inpoint[0]==1&&Ctrain.inpoint[1]==4)
      		{
     	          if(Ctrain.X==1&&Ctrain.Y>0&&Ctrain.Y<=4)
	          	{
                		fprintf(fPtr,"trainC:state=���С��ǹ������\t");
                		printf("trainC:state=���С��ǹ������\t");
	                	fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
           		}


           		if(Ctrain.Y==4&&Ctrain.X>1&&Ctrain.X<=3)
           		{
           			fprintf(fPtr,"trainC:state=���С��������\t");
           			printf("trainC:state=���С��������\t");
	           		fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		acc=1;
	          	}
	          	if(Ctrain.Y==0&&Ctrain.X>=1&&Ctrain.X<3)
	          	{
	     		     fprintf(fPtr,"trainC:state=���С��ǹ������\t");
	     		     printf("trainC:state=���С��ǹ������\t");
	     		     fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	     		     printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}

	          	if(Ctrain.X==3&&Ctrain.Y>=0&&Ctrain.Y<4)
	          	{
	          		 fprintf(fPtr,"trainC:state=���С��ǹ������\t");
	          		 printf("trainC:state=���С��ǹ������\t");
	          		 fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		 printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}
      		}

      		//2.C����ʱ�뷽�����У��ٶȲ�Ϊ��
		     if(Ctrain.inpoint[0]==3&&Ctrain.inpoint[1]==4)
               {
       			if(Ctrain.X==1&&Ctrain.Y>=0&&Ctrain.Y<4)
	          	{
                		fprintf(fPtr,"trainC:state=���С��ǹ������\t");
                		printf("trainC:state=���С��ǹ������\t");
	                	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
           		}


           		if(Ctrain.Y==4&&Ctrain.X>=1&&Ctrain.X<3)
           		{
           			fprintf(fPtr,"trainC:state=���С��������\t");
           			printf("trainC:state=���С��������\t");
	           		fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		acc=1;
	          	}


	          	if(Ctrain.Y==0&&Ctrain.X>1&&Ctrain.X<=3)
	          	{
	     		     fprintf(fPtr,"trainC:state=���С��ǹ������\t");
	     		     printf("trainC:state=���С��ǹ������\t");
	     		     fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	     		     printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}

	          	if(Ctrain.X==3&&Ctrain.Y>0&&Ctrain.Y<=4)
	          	{
	          		 fprintf(fPtr,"trainC:state=���С��ǹ������\t");
	          		 printf("trainC:state=���С��ǹ������\t");
	          		 fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		 printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}
       		}
      	}
      	else                                //����ͣ���ٶ�Ϊ��
 	     {
 	     	//1.C��˳ʱ�뷽�����У���վ̽����λ�þ����˻𳵵����з������ٶ�Ϊ��

      		if(Ctrain.inpoint[0]==1&&Ctrain.inpoint[1]==4)
      		{
     	         if(Ctrain.X==1&&Ctrain.Y>0&&Ctrain.Y<=4)
	          	{
	          		if(Ctrain.Y<4)
                		{
					          fprintf(fPtr,"trainC:state=��ͣ���ǹ������\t");
					          printf("trainC:state=��ͣ���ǹ������\t");
	                	      fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	      printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
                		}
                		if(Ctrain.Y==4)
                		{
		                	fprintf(fPtr,"trainC:state=��ͣ���ȴ��������\t");
		                	printf("trainC:state=��ͣ���ȴ��������\t");
	                	      fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	      printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
		                }
           		}


           		if(Ctrain.Y==4&&Ctrain.X>1&&Ctrain.X<=3)
           		{

					     fprintf(fPtr,"trainC:state=��ͣ���������\t");
					     printf("trainC:state=��ͣ���������\t");
	                	fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                		acc=1;

	          	}


	          	if(Ctrain.Y==0&&Ctrain.X>=1&&Ctrain.X<3)
	          	{
	     		     fprintf(fPtr,"trainC:state=��ͣ���ǹ������\t");
	     		     printf("trainC:state=��ͣ���ǹ������\t");
	     		     fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	     		     printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}

	          	if(Ctrain.X==3&&Ctrain.Y>=0&&Ctrain.Y<4)
	          	{
	          		 fprintf(fPtr,"trainC:state=��ͣ���ǹ������\t");
	          		 printf("trainC:state=��ͣ���ǹ������\t");
	          		 fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		 printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}


      		}
      		//2.C����ʱ�뷽�����У��ٶ�Ϊ��
		     if(Ctrain.inpoint[0]==3&&Ctrain.inpoint[1]==4)
               {
       			if(Ctrain.X==1&&Ctrain.Y>=0&&Ctrain.Y<4)
	          	{
                		fprintf(fPtr,"trainC:state=��ͣ���ǹ������\t");
                		printf("trainC:state=��ͣ���ǹ������\t");
	                	fprintf(fPtr,"RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	                	printf("RUNSOUTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
           		}


           		if(Ctrain.Y==4&&Ctrain.X>=1&&Ctrain.X<3)
           		{
           			fprintf(fPtr,"trainC:state=��ͣ���������\t");
           			printf("trainC:state=��ͣ���������\t");
	           		fprintf(fPtr,"RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		printf("RUNWEST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           		acc=1;
	          	}


	          	if(Ctrain.Y==0&&Ctrain.X>1&&Ctrain.X<=3)
	          	{
                          fprintf(fPtr,"trainC:state=��ͣ���ǹ������\t");
                          printf("trainC:state=��ͣ���ǹ������\t");
	           	      fprintf(fPtr,"RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	           	      printf("RUNEAST,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          	}

	          	if(Ctrain.X==3&&Ctrain.Y>0&&Ctrain.Y<=4)
	          	{
	          		if(Ctrain.Y==4)
	          		 {
					     fprintf(fPtr,"trainC:state=��ͣ���ȴ��������\t");
					     printf("trainC:state=��ͣ���ȴ��������\t");
	          		     fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		     printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		 }
	          		 if(Ctrain.Y<4)
	          		 {
 		          		fprintf(fPtr,"trainC:state=��ͣ���ǹ������\t");
 		          		printf("trainC:state=��ͣ���ǹ������\t");
	          		     fprintf(fPtr,"RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
	          		     printf("RUNNORTH,\tPOSX=%d,POSY=%d\n",Ctrain.X,Ctrain.Y);
 		          	}
	          	}


       		}

          }

          //����С�𳵵�״̬��Ϣ�Ѿ�ȫ�������ϣ�����������������������ռ�����
          //���ȿ���AB�������

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


          //���ڿ���AC���������ռ�����
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
          //�ر��ļ�
		fclose(fPtr);		
}