#include "bconstant.h"
extern  "C"  _declspec(dllexport) void  scanfor200(int  linestate200[LINEMAX], int linestate[LINEMAX],UpOnnode * head1,UpOnnode * end1)
{
	int up=0,down=0;
	for(int i = 0;i<LINEMAX;i++){
		struct UpOnnode * upwx = new struct UpOnnode;
		up = (!linestate200[i]) && linestate[i];
		down = (!linestate[i]) && linestate200[i];
		linestate200[i] = linestate[i];
		if(up || down){
			if(up)
				upwx->phonestate = ehandup;
			else
				upwx->phonestate = ehandon;
			upwx->linenum = i;
			upwx->next = 0;
			end1->next =upwx;
			end1 = upwx;
		}
	}
	return;	  
}
extern "C" _declspec(dllexport)  void   freenode(UpOnnode * node) 
{
	delete  node;
}


