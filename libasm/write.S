        global  write_ ; Implements: https://man7.org/linux/man-pages/man2/write.2.html

        section .text

write_:
        mov     rax, 1
        syscall
        ret