data segment
    a1 dw 51,50,48,47,46,45,44,43,42,41
    dw 61,60,59,58,57,56,55,54,53,52
    dw 76,75,74,73,72,71,69,68,67,66
    dw 11,12,13,14,15,16,17,18,19,20
    dw 1,2,3,4,5,6,7,8,9,0
   ; cn equ $-a1 
    cn dw 50
data ends

code segment 
    assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    
    call disp
    mov cx,cn
    dec cx  
loop1: 
    ;dec cx
	mov di,cx
	mov bx,0
loop2:
	mov ax,a1[bx]
	cmp ax,a1[bx+2]
	jle continue
    xchg ax,a1[bx+2]
    
    mov a1[bx],ax
continue:
	add bx,2
	loop loop2 
	
	mov cx,di
	loop loop1
	 
	call disp
	mov ax,04ch
	int 21h 
;display function	
disp proc near
    push ax
    push bx
    push cx
    push dx 
    
    mov bx,0  
    mov si, 0
	mov cx,cn
sr: 
    ;dec cx
    ;mov dx,a1[bx] 
    mov ax,a1[bx]  
    
    mov bp,bx
    mov bl,10
    div bl
     
    mov bh,ah  
    mov bl,al
    mov dl,bl
    add dl,30h
    add si,1 
    ;add dx,20h
    mov ah,02 
    int 21h 
    mov dl,bh
    add dl,30h
    mov ah,02 
    int 21h 
    mov bx,bp
    mov  dl,20h        ;¼Ó»Ø³µ·û  
    int  21h 
    add bx,2  
    cmp si,9
    jle con
    mov si,0
    mov DL, 0dH
    int 21H 
    mov DL, 0ah
    int 21h        
con:    
    loop sr
    
     mov DL, 0dH
    int 21H 
    mov DL, 0ah
    int 21h    
    pop dx
    pop cx
    pop bx
    pop ax
    ret
    disp endp
code ends
    end start
