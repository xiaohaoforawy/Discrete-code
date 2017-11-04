#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "program.h"
int judgedirection(int inpoint[2],int outpoint[2])//�����жϺ���
{
    if(inpoint[0]==outpoint[0]&&inpoint[1]<outpoint[1])//A������ʱ�룬B����˳ʱ��
        return 0;
    else if(inpoint[0]==outpoint[0]&&inpoint[1]>outpoint[1])//A����˳ʱ�룬B������ʱ��
        return 1;
    else if(inpoint[0]>outpoint[0]&&inpoint[1]==outpoint[1])//A����˳ʱ�룬C������ʱ��
        return 1;
    else if(inpoint[0]<outpoint[0]&&inpoint[1]==outpoint[1])//A������ʱ�룬C����˳ʱ��
        return 0;
}

int judgestation(int x,int y,int stationinf[12][3],int stationnum)//�жϺ����������վ�㣬����1�����Ƿ���0�����뵱ǰ���꣬վ����Ϣ��վ����
{
    int e=0;
    int a=0;
    for(a;a<stationnum;a++)
    {
        if((x==stationinf[a][0])&&(y==stationinf[a][1]))
        {
		   return 1;
           e=1;
           break;
        }
    }
    if(e==0)
        return 0;
}
int judgecomment(int x,int y)//�жϻ��ǲ����ڹ������
{
    if(x==1&&y==4)
        return 1;
    else if(x==2&&y==4)
        return 2;
    else if(x==3&&y==4)
        return 3;
    else if(x==4&&y==4)
        return 4;
    else if(x==4&&y==5)
        return 5;
    else if(x==4&&y==6)
        return 6;
    else
        return -1;
}

void judge()//the biggest judge function
{
    extern struct train Atrain,Btrain,Ctrain;
    extern int command[4];
	static int Astoptime=0,Bstoptime=0,Cstoptime=0;
	int Astate,Bstate,Cstate;
	clock_t time_count;
    //���ж�AB�������
	//����A��˳ʱ��
  if(judgedirection(Atrain.inpoint,Atrain.outpoint))
  {
        if(judgestation(Atrain.X,Atrain.Y,Atrain.stationinf,Atrain.stationnum))  //A����վ̨
     	{
     		if(Astoptime==Atrain.stationinf[0][2])
      		{
      			Atrain.speed=1;
      			Astoptime=0;
     			Astate=1;
      		}
      		else
     		{
     			Atrain.speed=0;
     		    Astate=0;
     		    ++Astoptime;
            }
      	}
	     /***********************************************************************/
     	else if(Atrain.X==4&&Atrain.Y==6)     //A����̽��㣬���ж�AB�������
      	{
		     //��B�����з��������˳ʱ�뷽��
      		if(!judgedirection(Btrain.inpoint,Btrain.outpoint))
	     	{
	     		if(judgecomment(Btrain.X,Btrain.Y)!=5&&judgecomment(Btrain.X,Btrain.Y)!=6)  //B���ڷǹ��������
	     		{
	      			Astate=1;
		     	}	   
				else     //B���ڹ��������
	     		{
	      			Astate=0;
	     		}

		     	if(judgecomment(Btrain.X,Btrain.Y)==4)   //AB��ͬʱ�Ӵ���̽���
	          	{
	      			Astate=-1;
	      		}


	      	}


		  /*************************************************************************************/

	     	//B������ʱ�뷽��
      		if(judgedirection(Btrain.inpoint,Btrain.outpoint))
     		{
	      		if(judgecomment(Btrain.X,Btrain.Y)!=5&&judgecomment(Btrain.X,Btrain.Y)!=4)  //B���ڷǹ��������
	     		{
	     			Astate=1;
                }    
				 else     //B���ڹ��������
	      		{
	     			Astate=0;
	     		}
                if(judgecomment(Btrain.X,Btrain.Y)==6)   //AB��ͬʱ�Ӵ���̽���
     			{
	      			Astate=-1;
                }

	     	}
        }
        else if(Atrain.X==3&&Atrain.Y==4)     //A����̽��㣬���ж�AC�������
      	{
		     //��C�����з��������˳ʱ�뷽��
      		if(!judgedirection(Ctrain.inpoint,Ctrain.outpoint))
	     	{
	     		if(judgecomment(Ctrain.X,Ctrain.Y)!=2&&judgecomment(Ctrain.X,Ctrain.Y)!=3)  //C���ڷǹ��������
	     		{
	    			Astate=1;
		     	}
	      		else     //C���ڹ��������
	     		{
	      			Astate=0;
	     		}
		     	if(judgecomment(Ctrain.X,Ctrain.Y)==1)   //AC��ͬʱ�Ӵ���̽���
	          	{
	      			Astate=-1;
	      		}

	      	}

		  /*************************************************************************************/

	     	//C������ʱ�뷽��
      		if(judgedirection(Ctrain.inpoint,Ctrain.outpoint))
     		{
	      		if(judgecomment(Ctrain.X,Ctrain.Y)!=1&&judgecomment(Ctrain.X,Ctrain.Y)!=2)  //C���ڷǹ��������
	     		{
	     			Astate=1;
	     		}	     
				 else     //C���ڹ��������
	      		{
	     			Astate=0;
	     		}
	     		if(judgecomment(Ctrain.X,Ctrain.Y)==3)   //AC��ͬʱ�Ӵ���̽���
     			{
	      			Astate=-1;
	     		}


	     	}

      	}
        else       //A����û����̽���Ҳû����վ̨
        Astate=1;
	}
    /********************************************************************************************/

	//Ȼ�����A����ʱ�뷽��

     if(!judgedirection(Atrain.inpoint,Atrain.outpoint))
	{
        if(judgestation(Atrain.X,Atrain.Y,Atrain.stationinf,Atrain.stationnum))  //A����վ̨
      	{
     		if(Astoptime==Atrain.stationinf[0][2])
	      	{
	      		Atrain.speed=1;
	      		Astoptime=0;
	      		Astate=1;
	     	}
	     	else
	     	{
	     		Atrain.speed=0;
	     	    Astate=0;
                ++Astoptime;
	     	}
      	}

		/************************************************************************/

	     else if(Atrain.X==4&&Atrain.Y==4)     //A����̽���

      	{
	      	 //��B�����з��������˳ʱ�뷽��
      		if(!judgedirection(Btrain.inpoint,Btrain.outpoint))
     		{
  	      		if(judgecomment(Btrain.X,Btrain.Y)!=5&&judgecomment(Btrain.X,Btrain.Y)!=6)  //B���ڷǹ��������
	      		{
      				Astate=1;
      			}
				else     //B���ڹ��������
	     		{
	      			Astate=0;
	     		}
	      		if(judgecomment(Btrain.X,Btrain.Y)==4)   //AB��ͬʱ�Ӵ���̽���
      			{
	     			Astate=-1;
	      		}

            }

		/****************************************************************************************/

			 //B������ʱ�뷽��
      		if(judgedirection(Btrain.inpoint,Btrain.outpoint))
      		{
     			if(judgecomment(Btrain.X,Btrain.Y)!=5&&judgecomment(Btrain.X,Btrain.Y)!=4)  //B���ڷǹ��������
      			{
	     			Astate=1;
                }   
				else     //B���ڹ��������
     			{
	     			Astate=0;
	     		}
      			if(judgecomment(Btrain.X,Btrain.Y)==6)   //AB��ͬʱ�Ӵ���̽���
     			{
      				Astate=-1;
      			}

            }

		}
		else if(Atrain.X==1&&Atrain.Y==4)     //A����̽���
	    {
	        //��C�����з��������˳ʱ�뷽��
      		if(!judgedirection(Ctrain.inpoint,Ctrain.outpoint))
     		{
  	      		if(judgecomment(Ctrain.X,Ctrain.Y)!=2&&judgecomment(Ctrain.X,Ctrain.Y)!=3)  //C���ڷǹ��������
	      		{

      				Astate=1;

      			}
	     		else     //C���ڹ��������
	     		{
	      			Astate=0;
	     		}
	      		if(judgecomment(Ctrain.X,Ctrain.Y)==1)   //AC��ͬʱ�Ӵ���̽���
      			{
	     			Astate=-1;
	      		}
			 }

		/****************************************************************************************/

			 //C������ʱ�뷽��
      		if(judgedirection(Ctrain.inpoint,Ctrain.outpoint))
      		{
     			if(judgecomment(Ctrain.X,Ctrain.Y)!=1&&judgecomment(Ctrain.X,Ctrain.Y)!=2)  //C���ڷǹ��������
      			{
	     			Astate=1;
                }   
				else     //C���ڹ��������
     			{
	     			Astate=0;
	     		}
      			if(judgecomment(Ctrain.X,Ctrain.Y)==3)   //AC��ͬʱ�Ӵ���̽���
     			{
      				Astate=-1;
      			}




      		}

		}
        else  //B����û�д���̽���Ҳ����վ��
        Astate=1;
	}

/**************************************************************************************************/

    if(judgedirection(Btrain.inpoint,Btrain.outpoint)==0&&judgedirection(Atrain.inpoint,Atrain.outpoint)==1)//AB��˳ʱ����
    {
        if(judgecomment(Btrain.X,Btrain.Y)==4)
        {
            if(judgecomment(Atrain.X,Atrain.Y)==6)
                Bstate= -1;
            else if(judgecomment(Atrain.X,Atrain.Y)==5||judgecomment(Atrain.X,Atrain.Y)==4)
                 Bstate=0;
            else
                Bstate= 1;
        }
        else{
             if(judgestation(Btrain.X,Btrain.Y,Btrain.stationinf,Btrain.stationnum)==1)

           	{
     	      	if(Bstoptime==Btrain.stationinf[0][2])
      	      	{
      	      		Btrain.speed=1;
      		     	Bstoptime=0;
     		      	Bstate=1;
      	      	}
      	         	else
     	      	{Bstate=0;
                 Btrain.speed=0;
      	      	++Bstoptime;}

           	}
            else Bstate=1;
        }

    }
    else if(judgedirection(Btrain.inpoint,Btrain.outpoint)==0/*b��˳ʱ��*/&&judgedirection(Atrain.inpoint,Atrain.outpoint)==0)//B˳ʱ�룬A��ʱ��
    {
        if(judgecomment(Btrain.X,Btrain.Y)==4)
        {
            if(judgecomment(Atrain.X,Atrain.Y)==4)
                Bstate= -1;
            else if(judgecomment(Atrain.X,Atrain.Y)==5||judgecomment(Atrain.X,Atrain.Y)==6)
                Bstate=0;
            else
                Bstate= 1;
        }
        else{
             if(judgestation(Btrain.X,Btrain.Y,Btrain.stationinf ,Btrain.stationnum)==1)
              	{
     	      	if(Bstoptime==Btrain.stationinf[0][2])
      	      	{
      	      		Btrain.speed=1;
      		     	Bstoptime=0;
     		      	Bstate=1;
      	      	}
      	         	else
     	      	{Bstate=0;
                 Btrain.speed=0;
      	      	++Bstoptime;}

           	}
           	else Bstate=1;
        }
    }
    else if(judgedirection(Btrain.inpoint,Btrain.outpoint)==1&&judgedirection(Atrain.inpoint,Atrain.outpoint)==0)//A��ʱ�룬B��ʱ��
    {
        if(judgecomment(Btrain.X,Btrain.Y)==6)
        {
            if(judgecomment(Atrain.X,Atrain.Y)==4)
                Bstate=-1;
            else if(judgecomment(Atrain.X,Atrain.Y)==5||judgecomment(Atrain.X,Atrain.Y)==6)
                Bstate= 0;
            else
                Bstate= 1;
        }
        else{
             if(judgestation(Btrain.X,Btrain.Y,Btrain.stationinf,Btrain.stationnum)==1)
               {
     	      	if(Bstoptime==Btrain.stationinf[0][2])
      	      	{
      	      		Btrain.speed=1;
      		     	Bstoptime=0;
     		      	Bstate=1;
      	      	}
      	         	else
     	      	{Bstate=0;
                 Btrain.speed=0;
      	      	++Bstoptime;}

           	}
           	else Bstate=1;
        }
    }
    else if(judgedirection(Btrain.inpoint,Btrain.outpoint)==1&&judgedirection(Atrain.inpoint,Atrain.outpoint)==1)//B��A˳
    {
        if(judgecomment(Btrain.X,Btrain.Y)==6)
        {
            if(judgecomment(Atrain.X,Atrain.Y)==6)
                Bstate= -1;
            else if(judgecomment(Atrain.X,Atrain.Y)==5||judgecomment(Atrain.X,Atrain.Y)==4)
                Bstate=0;
            else
                Bstate= 1;
        }
        else{
             if(judgestation(Btrain.X,Btrain.Y,Btrain.stationinf,Btrain.stationnum)==1)
               {
     	      	if(Bstoptime==Btrain.stationinf[0][2])
      	      	{
      	      		Btrain.speed=1;
      		     	Bstoptime=0;
     		      	Bstate=1;
      	      	}
      	         	else
     	      	{Bstate=0;
                  Btrain.speed=0;
      	      	++Bstoptime;}

           	}
           	else Bstate=1;
        }
    }



    if(judgedirection(Ctrain.inpoint,Ctrain.outpoint)==0&&judgedirection(Atrain.inpoint,Atrain.outpoint)==1)//AB��˳ʱ����
    {
        if(judgecomment(Ctrain.X,Ctrain.Y)==1)
        {
            if(judgecomment(Atrain.X,Atrain.Y)==3)
                 Cstate=-1;
            else if(judgecomment(Atrain.X,Atrain.Y)==1||judgecomment(Atrain.X,Atrain.Y)==2)
               Cstate= 0;
            else
                Cstate=1;
        }
        else{
             if(judgestation(Ctrain.X,Ctrain.Y,Ctrain.stationinf,Ctrain.stationnum)==1)
               {
     	      	if(Cstoptime==Ctrain.stationinf[0][2])
      	      	{
      	      		Ctrain.speed=1;
      		     	Cstoptime=0;
     		      	Cstate=1;
      	      	}
      	         	else
     	      	{Cstate=0;
                 Ctrain.speed=0;
      	      	++Cstoptime;}

           	}
           	else Cstate=1;
        }
    }
    else if(judgedirection(Ctrain.inpoint,Ctrain.outpoint)==0/*b��˳ʱ��*/&&judgedirection(Atrain.inpoint,Atrain.outpoint)==0)//B˳ʱ�룬A��ʱ��
    {
        if(judgecomment(Ctrain.X,Ctrain.Y)==1)
        {
            if(judgecomment(Atrain.X,Atrain.Y)==1)
                Cstate=-1;
            else if(judgecomment(Atrain.X,Atrain.Y)==2||judgecomment(Atrain.X,Atrain.Y)==3)
                Cstate= 0;
            else
                Cstate= 1;
        }
        else{
             if(judgestation(Ctrain.X,Ctrain.Y,Ctrain.stationinf,Ctrain.stationnum)==1)
               {
     	      	if(Cstoptime==Ctrain.stationinf[0][2])
      	      	{
      	      		Ctrain.speed=1;
      		     	Cstoptime=0;
     		      	Cstate=1;
      	      	}
      	         	else
     	      	{Cstate=0;
                  Ctrain.speed=0;
      	      	++Cstoptime;}

           	}
           	else Cstate=1;
        }
    }
    else if(judgedirection(Ctrain.inpoint,Ctrain.outpoint)==1&&judgedirection(Atrain.inpoint,Atrain.outpoint)==0)//A��ʱ�룬c��ʱ��
    {
        if(judgecomment(Ctrain.X,Ctrain.Y)==3)
        {
            if(judgecomment(Atrain.X,Atrain.Y)==1)
                Cstate=-1;
            else if(judgecomment(Atrain.X,Atrain.Y)==2||judgecomment(Atrain.X,Atrain.Y)==3)
                Cstate=0;
            else
               Cstate=1;
        }
        else{
             if(judgestation(Ctrain.X,Ctrain.Y,Ctrain.stationinf,Ctrain.stationnum)==1)
               {
     	      	if(Cstoptime==Ctrain.stationinf[0][2])
      	      	{
      	      		Ctrain.speed=1;
      		     	Cstoptime=0;
     		      	Cstate=1;
      	      	}
      	         	else
     	      	{Cstate=0;
                 Ctrain.speed=0;
      	      	++Cstoptime;}

           	}
           	else Cstate=1;
        }
    }
    else if(judgedirection(Ctrain.inpoint,Ctrain.outpoint)==1&&judgedirection(Atrain.inpoint,Atrain.outpoint)==1)//C��A˳
    {
        if(judgecomment(Ctrain.X,Ctrain.Y)==3)
        {
            if(judgecomment(Atrain.X,Atrain.Y)==3)
              Cstate=-1;
            else if(judgecomment(Atrain.X,Atrain.Y)==2||judgecomment(Atrain.X,Atrain.Y)==1)
               Cstate= 0;
            else
              Cstate=1;
        }
        else{
             if(judgestation(Ctrain.X,Ctrain.Y,Ctrain.stationinf ,Ctrain.stationnum)==1)
             {
     	      	if(Cstoptime==Ctrain.stationinf[0][2])
      	      	{
      	      		Ctrain.speed=1;
      		     	Cstoptime=0;
     		      	Cstate=1;
      	      	}
      	         	else
     	      	{Cstate=0;
                 Ctrain.speed=0;
      	      	++Cstoptime;}

           	}
           	else Cstate=1;
        }
    }
      time_count=clock();
   	if((time_count/CLOCKS_PER_SEC)<Atrain.starttime)
	   Astate=0;
	if((time_count/CLOCKS_PER_SEC)<Btrain.starttime)
	   Bstate=0;
	if((time_count/CLOCKS_PER_SEC)<Ctrain.starttime)
	   Cstate=0;
     command[0]=Astate;
     command[1]=Bstate;
     command[2]=Cstate;
}
