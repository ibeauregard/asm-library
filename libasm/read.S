        global  read_ ; Implements: https://man7.org/linux/man-pages/man2/read.2.html

        section .text

read_:
        mov     rax, 0
        syscall
        ret