; ��֪һ�ַ���string������ΪӢ��Сд��ĸ�����֡�����
;����*��#�����ȣ���ɣ�ĩβ��$�����Ա�дһ��������
;����string�е�Сд��ĸת���ɴ�д��ĸ��
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
data segment ;���ݶ�strlen�ǳ���
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
    
    sub dl,20h;��Сдת��
    
show: mov ah,2
    int 21h    ;��ʾ
    
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
