#include  "bconstant.h"
#define SchTabLen 20   
   #define SchTabWdh 3 
extern "C"  _declspec(dllexport)  void initSchTable(int ScheduleTable[SchTabLen][SchTabWdh])
{
	for(int i=0;i<SchTabLen;i++)
		{
			if(i%20 == 0)
				ScheduleTable[i][0] = 1;
			else
				ScheduleTable[i][0] = 0;
			
			if(i%1 == 0)
				ScheduleTable[i][1] = 1;
			else
				ScheduleTable[i][1] = 0;
			
			if(i%10 == 0)
				ScheduleTable[i][2] = 1;
			else
				ScheduleTable[i][2] = 0;
	}
    
      return;
}
