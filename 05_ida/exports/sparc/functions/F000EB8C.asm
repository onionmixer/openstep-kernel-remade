F000EB8C: 9de3bf98                 save    %sp, -0x68, %sp
F000EB90: 40016538                 call    _kalloc
F000EB94: 90102020                 mov     0x20, %o0! __b
F000EB98: b0100008                 mov     %o0, %i0
F000EB9C: 92102000                 mov     0, %o1! __c
F000EBA0: 7fffddf7                 call    _memset
F000EBA4: 94102020                 mov     0x20, %o2 ! ' '
F000EBA8: c0260000                 clr     [%i0]
F000EBAC: 81c7e008                 ret
F000EBB0: 81e80000                 restore
