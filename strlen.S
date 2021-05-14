        global  strlen_

        section .text

strlen_:
        mov     rax, -1

loop:
        inc     rax
        cmp     byte [rdi + rax], 0
        jne     loop

done:
        ret