//The train running control program source code.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "program.h"
#include "egg.h"
struct train Atrain,Btrain,Ctrain;                                  //Global variable declaration train structure
                                                                    //int alternate=1;
int command[4]={1,1,1,1};
int stop=1,flag=0,con; 
HEGG beijing;
HEGG Trainn[3];
DWORD WINAPI Function1Proc(LPVOID lpParameter);
//DWORD WINAPI Function2Proc(LPVOID lpParameter);
int main()
{
    extern struct train Atrain,Btrain,Ctrain;
     
    HANDLE hThread1;
    //HANDLE hThread2;
    EggStart(1200,718);
	Eggprogram(); 
    printf("*********************The Train Will Go,Are you ready**********************\n");
    init();
    hThread1=CreateThread(NULL,0,Function1Proc,NULL,0,NULL);
    //hThread2=CreateThread(NULL,0,Function2Proc,NULL,0,NULL);


    if (command[3]==0);
    {
	   WaitForSingleObject(hThread1,INFINITE);
       //WaitForSingleObject(hThread2,INFINITE);
    }
    printf("*********************THE TRIANS HAS STOPPED*********************\n");
    return 0;
}

DWORD WINAPI Function1Proc(LPVOID lpParameter)
{
	extern HEGG Trainn[3];
	int i;
	EVENT_TYPE ev;
	printf("哥们，你运行了没？");
    Trainn[0] = LayEgg();                                    //A车建蛋 
    SetPen(RED,20);
    MovePen(transferx(Atrain.X),transfemy(Atrain.Y));              
    DrawLine(10,0);
    
    Trainn[1] = LayEgg();                                   //B车建蛋 
    SetPen(RED,20);
    MovePen(transferx(Btrain.X),transfemy(Btrain.Y));
    DrawLine(10,0);
    
    Trainn[2] = LayEgg();                                   //C车建蛋 
    SetPen(RED,20);
    MovePen(transferx(Ctrain.X),transfemy(Ctrain.Y));
    DrawLine(10,0);
    
    StartTimer(1000); 
    while((ev = WaitForEvent())!= EXIT)
    {   
        switch(ev)
        {
        	case TIMER: 
			{
				Control();
				dongdan();
				break;
			}
			
			case KEYDOWN:
			{
				switch(GetStruckKey())
				{
					case VK_LBUTTON: 
					eggorder();break;
					default :break;
				}
				break;
		    }  
		}
        
        if (command[3]==0)
          break;
    }
    StopTimer(); 
    //EggStart(1200,718);
	//Eggprogram(); 
    //dongdan();
    WaitForExit();
} 
/*DWORD WINAPI Function2Proc(LPVOID lpParameter)
{
	
}*/
