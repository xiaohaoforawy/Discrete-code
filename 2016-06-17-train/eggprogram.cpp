#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include "egg.h"
#include "program.h"




void dongdan()
{
	int k=0;
	extern struct train Atrain,Btrain,Ctrain;
	extern HEGG Trainn[3];
	
    
   	while(WaitFor(100))                           
    {
   		if(Atrain.speed!=0)
   		{
   			SetActiveEgg(Trainn[0]);
   			if(Atrain.inpoint[1]==6)           //A��˳ʱ�� 
   			{
		          if(Atrain.X==0&&Atrain.Y>=4&&Atrain.Y<6)
		          {
				    OffsetEgg(0, 6*Atrain.speed);
		          }
		          if(Atrain.Y==6&&Atrain.X>=0&&Atrain.X<4)
		          {
				
		          	OffsetEgg(6*Atrain.speed, 0);
				  }    
		          if(Atrain.X==4&&Atrain.Y>4&&Atrain.Y<=6)
		          {
		    
		          	OffsetEgg(0, -6*Atrain.speed);
				  }
		          if(Atrain.Y==4&&Atrain.X>0&&Atrain.X<=4)
		          {
		
		          	OffsetEgg(-6*Atrain.speed, 0);
				  }
		    }
		    else                 //A����ʱ�� 
		    {
		    	if(Atrain.X==0&&Atrain.Y>4&&Atrain.Y<=6)
		        {
			
		    		OffsetEgg(0, -6*Atrain.speed);
				}
		    	if(Atrain.Y==4&&Atrain.X>=0&&Atrain.X<4)
		        {
	
		        	OffsetEgg(6*Atrain.speed, 0);
				}
		        if(Atrain.X==4&&Atrain.Y>=4&&Atrain.Y<6)
		        {
		        	
		        	OffsetEgg(0, 6*Atrain.speed);
				}
		        if(Atrain.Y==6&&Atrain.X>0&&Atrain.X<=4)
		        {
		        	OffsetEgg(-6*Atrain.speed, 0);
				}
			}
	    }
	    if(Btrain.speed!=0)
	    {
	    	SetActiveEgg(Trainn[1]);
	    	if(Btrain.inpoint[1]==4)       //B��˳ʱ�� 
	    	{
	    		if(Btrain.X==4&&Btrain.Y>=3&&Btrain.Y<7)
	    		OffsetEgg(0, 6*Btrain.speed);
	    		if(Btrain.Y==7&&Btrain.X>=4&&Btrain.X<6)
	    		OffsetEgg(6*Btrain.speed, 0);
	    		if(Btrain.X==6&&Btrain.Y>3&&Btrain.Y<=7)
	    		OffsetEgg(0, -6*Btrain.speed);
	    		if(Btrain.Y==3&&Btrain.X>4&&Btrain.X<=6)
	    		OffsetEgg(-6*Btrain.speed, 0);
			}
			else                            //B����ʱ�� 
			{
				if(Btrain.X==4&&Btrain.Y>3&&Btrain.Y<=7)
	    		OffsetEgg(0, -6*Btrain.speed);
	    		if(Btrain.Y==7&&Btrain.X>4&&Btrain.X<=6)
	    		OffsetEgg(-6*Btrain.speed, 0);
	    		if(Btrain.X==6&&Btrain.Y>=3&&Btrain.Y<7)
	    		OffsetEgg(0, 6*Btrain.speed);
	    		if(Btrain.Y==3&&Btrain.X>=4&&Btrain.X<6)
	    		OffsetEgg(6*Btrain.speed, 0);
			}
		}
		if(Ctrain.speed!=0)
		{
			SetActiveEgg(Trainn[2]);
			if(Ctrain.inpoint[0]==1)       //C��˳ʱ�� 
	    	{
	    		if(Ctrain.X==1&&Ctrain.Y>=0&&Ctrain.Y<4)
	    		OffsetEgg(0, 6*Ctrain.speed);
	    		if(Ctrain.Y==4&&Ctrain.X>=1&&Ctrain.X<3)
	    		OffsetEgg(6*Ctrain.speed, 0);
	    		if(Ctrain.X==3&&Ctrain.Y>0&&Ctrain.Y<=4)
	    		OffsetEgg(0, -6*Ctrain.speed);
	    		if(Ctrain.Y==0&&Ctrain.X>1&&Ctrain.X<=3)
	    		OffsetEgg(-6*Ctrain.speed, 0);
			}
			else                          //C����ʱ�� 
			{
				if(Ctrain.X==1&&Ctrain.Y>0&&Ctrain.Y<=4)
	    		OffsetEgg(0, -6*Ctrain.speed);
	    		if(Ctrain.Y==4&&Ctrain.X>1&&Ctrain.X<=3)
	    		OffsetEgg(-6*Ctrain.speed, 0);
	    		if(Ctrain.X==3&&Ctrain.Y>=0&&Ctrain.Y<4)
	    		OffsetEgg(0, 6*Ctrain.speed);
	    		if(Ctrain.Y==0&&Ctrain.X>=1&&Ctrain.X<3)
	    		OffsetEgg(6*Ctrain.speed, 0);
			}
		}
		++k;
		if(k==10)
		break;
    }
}



void Eggprogram(void)
{
	extern HEGG beijing;
    EggStart(1200,718);
    
    beijing=LayEgg();
    DrawBitmap("����ͼ.bmp");
    MovePen(197,532); 
    DrawBitmap("���.bmp");
    
    
    MovePen(840,528);
    DrawBitmap("�쳵����.bmp");
    
    MovePen(840,458);
    DrawBitmap("�������.bmp");
    
    MovePen(830,388);
    DrawBitmap("˳ʱ�����.bmp");
    MovePen(923,388);
    DrawBitmap("��ʱ�����.bmp");
    MovePen(877,388);
    DrawBitmap("С����ͣͼ��.bmp");
	MovePen(863,350);
	DrawBitmap("a���ַ�.bmp");
	
	
	MovePen(830,318);
    DrawBitmap("˳ʱ�����.bmp");
    MovePen(923,318);
    DrawBitmap("��ʱ�����.bmp");
    MovePen(877,318);
    DrawBitmap("С����ͣͼ��.bmp");
	MovePen(863,280);
	DrawBitmap("b���ַ�.bmp");
	
	
	MovePen(830,248);
    DrawBitmap("˳ʱ�����.bmp");
    MovePen(923,248);
    DrawBitmap("��ʱ�����.bmp");
    MovePen(877,248);
    DrawBitmap("С����ͣͼ��.bmp");
	MovePen(863,210);
	DrawBitmap("c���ַ�.bmp");
}
    
    
    

int transferx(int a)
{
	return 213+a*60;
}
int transfemy(int n)
{
	return 105+n*60;
}


void eggorder()
{
	EVENT_TYPE ev;
	extern struct train Atrain,Btrain,Ctrain;
	extern HEGG beijing;
	while ((ev=WaitForEvent()) != EXIT)    
	{
		SetActiveEgg(beijing);
		if(ev== KEYDOWN)
		{
			switch(GetStruckKey())	
			{
				case VK_LBUTTON:
					{
						
						if(GetMouseX()>=840&&GetMouseX()<=950&&GetMouseY()>=480&&GetMouseY()<=528)  //���п쳵���԰�ť
						{
							SetActiveEgg(beijing);
							MovePen(840,528);
							DrawBitmap("�쳵����1.bmp");
						} 
						if(GetMouseX()>=840&&GetMouseX()<=950&&GetMouseY()>=410&&GetMouseY()<=458)   //���н�����԰�ť
						{
							SetActiveEgg(beijing);
							MovePen(840,458);
                            DrawBitmap("�������1.bmp");
						} 
						
						
						//����A������ز��� 
						if(GetMouseX()>=830&&GetMouseX()<=866&&GetMouseY()>=352&&GetMouseY()<=388)    //����A��˳ʱ�밴ť 
						{
							Atrain.inpoint[1]=6;
						}
						if(GetMouseX()>=923&&GetMouseX()<=959&&GetMouseY()>=352&&GetMouseY()<=388)     //����A����ʱ�밴ť 
						{
							Atrain.inpoint[1]=4;
						}
						if(GetMouseX()>=877&&GetMouseX()<=917&&GetMouseY()>=352&&GetMouseY()<=388)    // ����A����ͣ/��ʻͼ�� 
						{
							if(Atrain.speed==0)
							{
								SetActiveEgg(beijing);
								Atrain.speed=1;
								MovePen(877,388);
								DrawBitmap("С����ͣͼ��.bmp");
							}
							if(Atrain.speed)
							{
								SetActiveEgg(beijing);
								Atrain.speed=0;
								MovePen(877,388);
								DrawBitmap("С����ʼͼ��.bmp");
							}
						}
						
						
						//����B������ز���
						if(GetMouseX()>=830&&GetMouseX()<=866&&GetMouseY()>=282&&GetMouseY()<=318)    //����B��˳ʱ�밴ť 
						{
							Btrain.inpoint[1]=6;
						}
						if(GetMouseX()>=923&&GetMouseX()<=959&&GetMouseY()>=282&&GetMouseY()<=318)     //����B����ʱ�밴ť 
						{
							Btrain.inpoint[1]=4;
						}
						if(GetMouseX()>=877&&GetMouseX()<=917&&GetMouseY()>=282&&GetMouseY()<=318)    // ����B����ͣ/��ʻͼ�� 
						{
							if(Btrain.speed==0)
							{
								SetActiveEgg(beijing);
								Btrain.speed=1;
								MovePen(877,318);
								DrawBitmap("С����ͣͼ��.bmp");
							}
							if(Btrain.speed)
							{
								SetActiveEgg(beijing);
								Btrain.speed=0;
								MovePen(877,318);
								DrawBitmap("С����ʼͼ��.bmp");
							}
						}
						
						
						//����C������ز���
						if(GetMouseX()>=830&&GetMouseX()<=866&&GetMouseY()>=212&&GetMouseY()<=248)    //����C��˳ʱ�밴ť 
						{
							Ctrain.inpoint[1]=6;
						}
						if(GetMouseX()>=923&&GetMouseX()<=959&&GetMouseY()>=212&&GetMouseY()<=248)     //����C����ʱ�밴ť 
						{
							Ctrain.inpoint[1]=4;
						}
						if(GetMouseX()>=877&&GetMouseX()<=917&&GetMouseY()>=212&&GetMouseY()<=248)    // ����C����ͣ/��ʻͼ�� 
						{
							if(Ctrain.speed==0)
							{
								SetActiveEgg(beijing);
								Ctrain.speed=1;
								MovePen(877,248);
								DrawBitmap("С����ͣͼ��.bmp");
							}
							if(Ctrain.speed)
							{
								SetActiveEgg(beijing);
								Ctrain.speed=0;
								MovePen(877,248);
								DrawBitmap("С����ʼͼ��.bmp");
							}
						}
						
						
						if(GetMouseX()>1060&&GetMouseX()<1170&&GetMouseY()>470&&GetMouseY()<570)
			            Atrain.speed=Btrain.speed=Ctrain.speed=1;
			            if(GetMouseX()>1060&&GetMouseX()<1170&&GetMouseY()>270&&GetMouseY()<370)
			            Atrain.speed=Btrain.speed=Ctrain.speed=0;
						
					}
					
					default :break;
			}
		}
	}
}
