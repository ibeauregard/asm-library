        global  index_ ; Implements: https://man7.org/linux/man-pages/man3/index.3.html
        extern  strchr_

        section .text

index_:
        call    strchr_; See https://stackoverflow.com/a/4091879/2237433
        ret