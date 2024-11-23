

section .text
bits 64
default rel
global imgCvtGrayIntToDouble

; RCX = no. of elements
; RDX = *intArr
; R8 = *doubleArr

imgCvtGrayIntToDouble:
    
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

