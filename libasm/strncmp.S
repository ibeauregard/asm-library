        global  strncmp_

        section .text

strncmp_:
        dec     rdi
        dec     rsi
        inc     rdx

loop:
        inc     rdi
        inc     rsi
        dec     rdx
        cmp     rdx, 0
        je      count_exhausted
        cmp     byte [rdi], 0
        je      done
        mov     cl, byte [rdi]
        cmp     cl, byte [rsi]
        je      loop

done:
        movzx   rax, byte [rdi]
        movzx   rcx, byte [rsi]
        sub     rax, rcx
        ret

count_exhausted:
        xor     rax, rax
        ret