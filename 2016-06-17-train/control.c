#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "program.h"
void Control()//the cheif control function
{

       extern struct train Atrain,Btrain,Ctrain;
       int tra1,tra2,tra3;
       extern int command[4];
       clock_t time;
       judge();
       //�ж�����״��������-1��������ͬʱ�������� 
       if(command[0]==-1&&command[1]==-1)
		   choice_(Atrain.speed,Btrain.speed,&command[0],&command[1]);
       if(command[1]==-1&&command[2]==-1)
		   choice_(Btrain.speed,Ctrain.speed,&command[1],&command[2]);
       if(command[0]==-1&&command[2]==-1)
		   choice_(Atrain.speed,Ctrain.speed,&command[0],&command[2]);
       /*0Ϊ��ͣ��1Ϊ˳�У�2Ϊ����*/
       //�ж�˳��  	
       if(command[0]!=0)
       {
	      if((Atrain.inpoint[1]-Atrain.outpoint[1])>0)
             command[0]=1;
	      else
	         command[0]=2;
       }
       if(command[1]!=0)
       {
	      if((Btrain.inpoint[1]-Btrain.outpoint[1])<0)
             command[1]=1;
	      else
	         command[1]=2;
       }
       if(command[2]!=0)
       {
	      if((Ctrain.inpoint[0]-Ctrain.outpoint[0])<0)
             command[2]=1;
	      else
	         command[2]=2;
       }
       time=clock()/CLOCKS_PER_SEC;//�жϿ�ʼʱ���Ծ����Ƿ�ʼ��ʻ 
       if(time<Atrain.starttime)
          command[0]=0;
       if(time<Btrain.starttime)
          command[1]=0;
       if(time<Ctrain.starttime)
          command[2]=0;

	   tra1_move(command[0]);
       tra2_move(command[1]);
       tra3_move(command[2]);
       PrintState();

}

void choice_(int speed1,int speed2,int * command1,int * command2)
{
	static int alternate=1;
		   if(speed1==speed2)//�������
	       {
		       if(alternate==1)
		          {* command1=1;* command2=0;}
               else
                  {* command1=0;* command2=1;}
               alternate=abs(alternate-1);
	       }
	       else if(speed1>speed2)//�쳵����
                  {* command1=1;* command2=0;}
                else
                   {* command1=0;* command2=1;}
}

void tra1_move(int _command)//����aС����ʻ 
{
    extern struct train Atrain;
	int i;
    if(_command==1)
       {
       	  for(i=0;i<Atrain.speed;i++)
 	        {
        	   if(Atrain.Y==6&&Atrain.X!=4)	
        	      Atrain.X++;
     	       else if(Atrain.Y==4&&Atrain.X!=0)
     	          Atrain.X--;
			   else if(Atrain.X==0&&Atrain.Y!=6) 
			      Atrain.Y++;
               else if(Atrain.X==4&&Atrain.Y!=4)
                  Atrain.Y--;
 	        }
       }
       if(_command==2)
       {
       	  for(i=0;i<Atrain.speed;i++)
 	        {
        	   if(Atrain.Y==6&&Atrain.X!=0)	
        	      Atrain.X--;
     	       else if(Atrain.Y==4&&Atrain.X!=4)
     	          Atrain.X++;
			   else if(Atrain.X==0&&Atrain.Y!=4) 
			      Atrain.Y--;
               else if(Atrain.X==4&&Atrain.Y!=6)
                  Atrain.Y++;
 	        }
       }
}

void tra2_move(int _command)//����bС����ʻ 
{
	extern struct train Btrain;
    int i;
    if(_command==1)
       {
       	  for(i=0;i<Btrain.speed;i++)
 	        {
        	   if(Btrain.Y==7&&Btrain.X!=6)	
        	      Btrain.X++;
     	       else if(Btrain.Y==3&&Btrain.X!=4)
     	          Btrain.X--;
			   else if(Btrain.X==4&&Btrain.Y!=7) 
			      Btrain.Y++;
               else if(Btrain.X==6&&Btrain.Y!=3)
                  Btrain.Y--;
 	        }
       }
       if(_command==2)
       {
       	  for(i=0;i<Btrain.speed;i++)
 	        {
        	   if(Btrain.Y==7&&Btrain.X!=4)	
        	      Btrain.X--;
     	       else if(Btrain.Y==3&&Btrain.X!=6)
     	          Btrain.X++;
			   else if(Btrain.X==4&&Btrain.Y!=3) 
			      Btrain.Y--;
               else if(Btrain.X==6&&Btrain.Y!=7)
                  Btrain.Y++;
 	        }
       }
}
void tra3_move(int _command)//����cС����ʻ 
{
	extern struct train Ctrain;
     int i;
    if(_command==1)
       {
       	  for(i=0;i<Ctrain.speed;i++)
 	        {
        	   if(Ctrain.Y==4&&Ctrain.X!=3)	
        	      Ctrain.X++;
     	       else if(Ctrain.Y==0&&Ctrain.X!=1)
     	          Ctrain.X--;
			   else if(Ctrain.X==1&&Ctrain.Y!=4) 
			      Ctrain.Y++;
               else if(Ctrain.X==3&&Ctrain.Y!=0)
                  Ctrain.Y--;
 	        }
       }
       if(_command==2)
       {
       	  for(i=0;i<Ctrain.speed;i++)
 	        {
        	   if(Ctrain.Y==4&&Ctrain.X!=1)	
        	      Ctrain.X--;
     	       else if(Ctrain.Y==0&&Ctrain.X!=3)
     	          Ctrain.X++;
			   else if(Ctrain.X==1&&Ctrain.Y!=0) 
			      Ctrain.Y--;
               else if(Ctrain.X==3&&Ctrain.Y!=4)
                  Ctrain.Y++;
 	        }
       }
}
