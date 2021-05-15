        global  memcpy_

        section .text

memcpy_:
        mov     rax, rdi

loop:
        cmp     rdx, 0
        je      return
        mov     cl, byte [rsi]
        mov     byte [rdi], cl
        inc     rdi
        inc     rsi
        dec     rdx
        jmp     loop

return:
        ret