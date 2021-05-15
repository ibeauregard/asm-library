        global  write_

        section .text

write_:
        mov     rax, 1
        syscall
        ret