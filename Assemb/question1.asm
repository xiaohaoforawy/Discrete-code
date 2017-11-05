;******************************************************
;已知一任意长度字符串str，以00h结束，长度小于2000h，
;编写汇编程序实现在该字符串中搜索匹配子串substr（以00h结束，长度小于200)，
;若找到，则将found单元置为ffh，并将匹配位置（匹配位置以字符串str首地址为0参考点）
;存放在pos单元中；否则，将found单元置为00H。要求编写完整程序，并上机通过debug调试。
;提示：可利用串操作指令实现。
;****************************************************
data segment
    str_len   dw  200h
    str       db  200h dup(0)
    subs_len  dw  20
    substr    db  20 dup(0)
    found     db  00h
    temp      dw  ?
    pos       dw   ?  
    mas       db 'LOST$'  
   
data ends  ;定义数据段，初始化空间，初始化输出

stack segment stack
    dw 100 dup(0)
stack ends

code segment
    assume cs:code,ds:data ,ss:stack
start:
    mov ax,data
    mov ds,ax
    mov ax,stack
    mov ss,ax
    
    mov bx, offset str
    mov cx,str_len
    mov temp,cx
    call get_string      ;input string
    
    mov cx,subs_len
    mov temp,cx
    mov bx, offset substr
    call get_string       ;input substring
    
    call compa          ;bidui
    mov ah,4ch
    int 21h
;-------------------------------------------------
;	输入字符串子程序，
;	入口: (bX)字符串地址
;	出口: 无
;-------------------------------------------------
get_string proc near
    push ax
    push bx
    push cx
    
    mov cx,word ptr temp-1 ;初始化循环次数
loopin:
    mov ah, 1
    int 21h
    
    cmp al,'$'
    jz loopend
    
    mov [bx],al
    inc bx
    loop loopin
loopend:
    mov [bx] ,00h  ;在末尾加00h
    
    mov ah,02h
    mov dl,0dh
    int 21h
    mov dl,0ah
    int 21h
    
    pop cx
    pop bx
    pop ax
    ret
get_string endp
;-------------------------------------------------
;	比较子程序，
;	入口: (bX)要输出的数
;	出口: dx
;-------------------------------------------------
compa proc near
    push di 
    push si
    mov di,0
    mov si,0 
l0:
    cmp str[di],0
    jbe done
l1: 
    CMP substr[si],0
    jbe l3
    
    mov al,str[di]
    xor al,substr[si]
    cmp al,0
    ja l2
    
    add di,1
    add si,1
    jmp l0
    
l2: 
    sub di,si
    add di,1
    mov si,0
    jmp l0
    
l3:
    mov found,0ffh
    sub di,si
    mov pos,di
    
    jmp over
    
done:  
    lea dx,mas
    mov ah,09
    int 21h
    
over:
    pop di
    pop si
    ret
compa endp   
;-----------------------------------------------

code ends
    end start
    
