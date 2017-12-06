data segment
    outport1 equ 02a0h
    outport2 equ 02a8h
data ends

code segment
	assume cs:code
start:
	mov dx,outport1
	out dx,al
	call delay
	mov dx,outport2
	out dx,al
	call delay
	mov ah,01h
	int 016h
	je start
	mov ah,04ch
	int 021h;
;delay program----------
delay proc near
	
	mov bx,200h
lm: mov cx,0
ln: loop ln
	dec bx
	jne lm	
	ret
delay endp
;------------------------
code ends
end start