; 已知一字符串string的内容为英文小写字母、数字、符号
;（如*、#、！等）组成，末尾是$符，试编写一个汇编程序
;，将string中的小写字母转换成大写字母。
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
data segment ;数据段strlen是长度
    str db 'abCDEFGHikjklmnopQR#!stuvwxyz',0dh,0ah,'$' 
    strlen dw $-str
ends

code segment      
    assume cs:code ds:data
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax   
    
    mov bx,offset str
log:mov dl,[bx]
    cmp dl,'$' 
    jz exit
    
    cmp dl,'a'
    jb show
    
    cmp dl,'z'
    ja show
    
    sub dl,20h;大小写转换
    
show: mov ah,2
    int 21h    ;显示
    
    inc bx
    jmp log
    
exit: mov ah,4ch
    int 21h
       
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h  

code ends

end start ; 
