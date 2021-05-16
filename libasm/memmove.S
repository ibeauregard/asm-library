        global  memmove_ ; Implements: https://man7.org/linux/man-pages/man3/memmove.3.html
        extern  memcpy_

        section .text

memmove_:
        cmp     rsi, rdi
        jl      backwards_loop
        call    memcpy_
        ret

backwards_loop:
        dec     rdx
loop:
        cmp     rdx, -1
        je      return
        mov     cl, byte [rsi + rdx]
        mov     byte [rdi + rdx], cl
        dec     rdx
        jmp     loop

return:
        ret