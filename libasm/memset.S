        global  memset_ ; Implements: https://man7.org/linux/man-pages/man3/memset.3.html

        section .text

memset_:
        mov     rax, rdi

loop:
        cmp     rdx, 0
        je      return
        mov     byte [rdi], sil
        inc     rdi
        dec     rdx
        jmp     loop

return:
        ret