;**********************;
;*   数/模转换实验1   *;
;*     产生锯齿波     *;
;**********************;
io0832a        equ 290h
code segment
   assume cs:code
start: mov cl,0
       mov dx,io0832a
lll:   mov al,cl
    out dx,al
    add cl,10
    push dx
    mov ah,06h      ;判断是否有键按下
    mov dl,0ffh
    int 21h
    pop dx
    jz  lll       ;若无则转LLL
    mov ah,4ch    ;返回
    int 21h
code ends
   end start
