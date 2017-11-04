#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "program.h"
void READ()
{
	static int Train_State_Order[3]={1,1,1};
    static int Program_state=1,speed1,speed2,speed3;
    extern int flag;
    extern int command[4];
    extern struct train Atrain,Btrain,Ctrain;
	char ch;
    
    


          scanf("%c",&ch);
          while(Program_state!=0)
          {
 	     	if(ch=='P')
 	     	{
	     	 	scanf("%c",&ch);
	     	 	if(ch=='A')
	     	 	{
				  Train_State_Order[0]=0;
				  speed1=Atrain.speed;
				  Atrain.speed=0;
				  getchar();
                }

	     	 	if(ch=='B')
	     	 	{
				  Train_State_Order[1]=0;
				  speed2=Btrain.speed;
				  Btrain.speed=0;
				  getchar(); 
                 }

	     	 	if(ch=='C')
	     	 	{
				  Train_State_Order[2]=0;
				  speed3=Ctrain.speed;
				  Ctrain.speed=0;
				   getchar();
                 }

	     	 	if(ch=='P')
	     	 	Program_state=0;	

     	     }

     	    else if(ch=='C')
     	     {
   	     		scanf("%c",&ch);
   	     		if(ch=='A')
   	     		{
				  Train_State_Order[0]=1;
				  Atrain.speed=speed1;
				   getchar();
                }

   	     		if(ch=='B')
   	     		{
				  Train_State_Order[0]=1;
                   Btrain.speed=speed2;
                    getchar();
                }

   	     		if(ch=='C')
   	     		{
				  Train_State_Order[0]=1;
				  Ctrain.speed=speed3;
				  getchar();
                }
     	     } 
     	     else
     	        printf(" ‰»Î÷∏¡Ó¥ÌŒÛ\n");
     	        
             command[3]=Program_state;
			 scanf("%c",&ch);
          }
}
