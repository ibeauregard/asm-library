        global  strcmp_

        section .text

strcmp_:
        dec     rdi
        dec     rsi

loop:
        inc     rdi
        inc     rsi
        cmp     byte [rdi], 0
        je      done
        mov     dl, byte [rdi]
        cmp     dl, byte [rsi]
        je      loop

done:
        movzx   rax, byte [rdi]
        movzx   rdx, byte [rsi]
        sub     rax, rdx
        ret