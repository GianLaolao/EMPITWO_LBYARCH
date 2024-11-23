
section .bss
double resq 4

section .data
integers db 64,  89,  114, 84
d dq 0.0, 0.0, 0.0, 0.0
height db 2
width db 2 
divisor db 255

section .text
bits 64
default rel
global imgCvtGrayIntToDouble
; global main

; RCX = no. of elements
; RDX = *intArr
; R8 = *doubleArr

imgCvtGrayIntToDouble:
;main:
    
    XOR RBX, RBX
    MOV RAX, 255
    VPXOR XMM0, XMM0
    CVTSI2SD XMM0, RAX  
    
    convert:
        XOR RAX, RAX
        MOVZX RAX, byte [RDX + RBX]
        VPXOR XMM1, XMM1
        CVTSI2SD XMM1, RAX  
        DIVSD XMM1, XMM0
        MOVSD [R8 + RBX * 8], XMM1
        INC RBX
        LOOP convert

    ret

