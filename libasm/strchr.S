        global  strchr_ ; Implements: https://man7.org/linux/man-pages/man3/strchr.3.html

        section .text

strchr_:
        dec     rdi

loop:
        inc     rdi
        cmp     byte [rdi], sil
        je      found
        cmp     byte [rdi], 0
        jne     loop
        xor     rax, rax
        ret
        
found:
        mov     rax, rdi
        ret