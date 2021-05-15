        global  read_

        section .text

read_:
        mov     rax, 0
        syscall
        ret