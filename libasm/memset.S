        global  memset_

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