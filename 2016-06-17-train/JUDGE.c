#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "program.h"
int judgedirection(int inpoint[2],int outpoint[2])//方向判断函数
{
    if(inpoint[0]==outpoint[0]&&inpoint[1]<outpoint[1])//A车的逆时针，B车的顺时针
        return 0;
    else if(inpoint[0]==outpoint[0]&&inpoint[1]>outpoint[1])//A车的顺时针，B车的逆时针
        return 1;
    else if(inpoint[0]>outpoint[0]&&inpoint[1]==outpoint[1])//A车的顺时针，C车的逆时针
        return 1;
    else if(inpoint[0]<outpoint[0]&&inpoint[1]==outpoint[1])//A车的逆时针，C车的顺时针
        return 0;
}

int judgestation(int x,int y,int stationinf[12][3],int stationnum)//判断函数，如果是站点，返回1，不是返回0，输入当前坐标，站点信息，站点数
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
int judgecomment(int x,int y)//判断火车是不是在公共轨道
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
    //先判断AB公共轨道
	//先是A车顺时针
  if(judgedirection(Atrain.inpoint,Atrain.outpoint))
  {
        if(judgestation(Atrain.X,Atrain.Y,Atrain.stationinf,Atrain.stationnum))  //A车在站台
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
     	else if(Atrain.X==4&&Atrain.Y==6)     //A到达探测点，先判断AB公共轨道
      	{
		     //看B车运行方向，如果是顺时针方向
      		if(!judgedirection(Btrain.inpoint,Btrain.outpoint))
	     	{
	     		if(judgecomment(Btrain.X,Btrain.Y)!=5&&judgecomment(Btrain.X,Btrain.Y)!=6)  //B车在非公共轨道上
	     		{
	      			Astate=1;
		     	}	   
				else     //B车在公共轨道上
	     		{
	      			Astate=0;
	     		}

		     	if(judgecomment(Btrain.X,Btrain.Y)==4)   //AB车同时接触到探测点
	          	{
	      			Astate=-1;
	      		}


	      	}


		  /*************************************************************************************/

	     	//B车是逆时针方向
      		if(judgedirection(Btrain.inpoint,Btrain.outpoint))
     		{
	      		if(judgecomment(Btrain.X,Btrain.Y)!=5&&judgecomment(Btrain.X,Btrain.Y)!=4)  //B车在非公共轨道上
	     		{
	     			Astate=1;
                }    
				 else     //B车在公共轨道上
	      		{
	     			Astate=0;
	     		}
                if(judgecomment(Btrain.X,Btrain.Y)==6)   //AB车同时接触到探测点
     			{
	      			Astate=-1;
                }

	     	}
        }
        else if(Atrain.X==3&&Atrain.Y==4)     //A到达探测点，先判断AC公共轨道
      	{
		     //看C车运行方向，如果是顺时针方向
      		if(!judgedirection(Ctrain.inpoint,Ctrain.outpoint))
	     	{
	     		if(judgecomment(Ctrain.X,Ctrain.Y)!=2&&judgecomment(Ctrain.X,Ctrain.Y)!=3)  //C车在非公共轨道上
	     		{
	    			Astate=1;
		     	}
	      		else     //C车在公共轨道上
	     		{
	      			Astate=0;
	     		}
		     	if(judgecomment(Ctrain.X,Ctrain.Y)==1)   //AC车同时接触到探测点
	          	{
	      			Astate=-1;
	      		}

	      	}

		  /*************************************************************************************/

	     	//C车是逆时针方向
      		if(judgedirection(Ctrain.inpoint,Ctrain.outpoint))
     		{
	      		if(judgecomment(Ctrain.X,Ctrain.Y)!=1&&judgecomment(Ctrain.X,Ctrain.Y)!=2)  //C车在非公共轨道上
	     		{
	     			Astate=1;
	     		}	     
				 else     //C车在公共轨道上
	      		{
	     			Astate=0;
	     		}
	     		if(judgecomment(Ctrain.X,Ctrain.Y)==3)   //AC车同时接触到探测点
     			{
	      			Astate=-1;
	     		}


	     	}

      	}
        else       //A车既没触发探测点也没有在站台
        Astate=1;
	}
    /********************************************************************************************/

	//然后如果A是逆时针方向

     if(!judgedirection(Atrain.inpoint,Atrain.outpoint))
	{
        if(judgestation(Atrain.X,Atrain.Y,Atrain.stationinf,Atrain.stationnum))  //A车在站台
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

	     else if(Atrain.X==4&&Atrain.Y==4)     //A到达探测点

      	{
	      	 //看B车运行方向，如果是顺时针方向
      		if(!judgedirection(Btrain.inpoint,Btrain.outpoint))
     		{
  	      		if(judgecomment(Btrain.X,Btrain.Y)!=5&&judgecomment(Btrain.X,Btrain.Y)!=6)  //B车在非公共轨道上
	      		{
      				Astate=1;
      			}
				else     //B车在公共轨道上
	     		{
	      			Astate=0;
	     		}
	      		if(judgecomment(Btrain.X,Btrain.Y)==4)   //AB车同时接触到探测点
      			{
	     			Astate=-1;
	      		}

            }

		/****************************************************************************************/

			 //B车是逆时针方向
      		if(judgedirection(Btrain.inpoint,Btrain.outpoint))
      		{
     			if(judgecomment(Btrain.X,Btrain.Y)!=5&&judgecomment(Btrain.X,Btrain.Y)!=4)  //B车在非公共轨道上
      			{
	     			Astate=1;
                }   
				else     //B车在公共轨道上
     			{
	     			Astate=0;
	     		}
      			if(judgecomment(Btrain.X,Btrain.Y)==6)   //AB车同时接触到探测点
     			{
      				Astate=-1;
      			}

            }

		}
		else if(Atrain.X==1&&Atrain.Y==4)     //A到达探测点
	    {
	        //看C车运行方向，如果是顺时针方向
      		if(!judgedirection(Ctrain.inpoint,Ctrain.outpoint))
     		{
  	      		if(judgecomment(Ctrain.X,Ctrain.Y)!=2&&judgecomment(Ctrain.X,Ctrain.Y)!=3)  //C车在非公共轨道上
	      		{

      				Astate=1;

      			}
	     		else     //C车在公共轨道上
	     		{
	      			Astate=0;
	     		}
	      		if(judgecomment(Ctrain.X,Ctrain.Y)==1)   //AC车同时接触到探测点
      			{
	     			Astate=-1;
	      		}
			 }

		/****************************************************************************************/

			 //C车是逆时针方向
      		if(judgedirection(Ctrain.inpoint,Ctrain.outpoint))
      		{
     			if(judgecomment(Ctrain.X,Ctrain.Y)!=1&&judgecomment(Ctrain.X,Ctrain.Y)!=2)  //C车在非公共轨道上
      			{
	     			Astate=1;
                }   
				else     //C车在公共轨道上
     			{
	     			Astate=0;
	     		}
      			if(judgecomment(Ctrain.X,Ctrain.Y)==3)   //AC车同时接触到探测点
     			{
      				Astate=-1;
      			}




      		}

		}
        else  //B车既没有触发探测点也不在站点
        Astate=1;
	}

/**************************************************************************************************/

    if(judgedirection(Btrain.inpoint,Btrain.outpoint)==0&&judgedirection(Atrain.inpoint,Atrain.outpoint)==1)//AB车顺时针走
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
    else if(judgedirection(Btrain.inpoint,Btrain.outpoint)==0/*b车顺时针*/&&judgedirection(Atrain.inpoint,Atrain.outpoint)==0)//B顺时针，A逆时针
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
    else if(judgedirection(Btrain.inpoint,Btrain.outpoint)==1&&judgedirection(Atrain.inpoint,Atrain.outpoint)==0)//A逆时针，B逆时针
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
    else if(judgedirection(Btrain.inpoint,Btrain.outpoint)==1&&judgedirection(Atrain.inpoint,Atrain.outpoint)==1)//B逆A顺
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



    if(judgedirection(Ctrain.inpoint,Ctrain.outpoint)==0&&judgedirection(Atrain.inpoint,Atrain.outpoint)==1)//AB车顺时针走
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
    else if(judgedirection(Ctrain.inpoint,Ctrain.outpoint)==0/*b车顺时针*/&&judgedirection(Atrain.inpoint,Atrain.outpoint)==0)//B顺时针，A逆时针
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
    else if(judgedirection(Ctrain.inpoint,Ctrain.outpoint)==1&&judgedirection(Atrain.inpoint,Atrain.outpoint)==0)//A逆时针，c逆时针
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
    else if(judgedirection(Ctrain.inpoint,Ctrain.outpoint)==1&&judgedirection(Atrain.inpoint,Atrain.outpoint)==1)//C逆A顺
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
