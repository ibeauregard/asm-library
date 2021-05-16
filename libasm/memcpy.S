        global  memcpy_ ; Implements: https://man7.org/linux/man-pages/man3/memcpy.3.html

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