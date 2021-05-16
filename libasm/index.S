        global  index_
        extern  strchr_

        section .text

index_:
        call    strchr_; See https://stackoverflow.com/a/4091879/2237433
        ret